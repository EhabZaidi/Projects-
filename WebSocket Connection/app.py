from flask import Flask, render_template, request
from flask_socketio import SocketIO, join_room
import websockets
from websocket import create_connection
import simplejson as json
import asyncio
import threading
import time
from gevent import pywsgi
from geventwebsocket.handler import WebSocketHandler
from collections import defaultdict

clientcount = defaultdict(int)
clientsubscription = {}


app = Flask(__name__)
socketio = SocketIO(app, async_mode="gevent")

subscribe_eurusd = {
        'eventName': 'subscribe',
        'authorization': 'a9783ea9150de52212a3cc765bf6cac81f35c45e',
        'eventData': {
            'thresholdLevel': 5,
            'tickers':['eurusd']
        }
    }
subscribe_usdjpy = {
        'eventName': 'subscribe',
        'authorization': 'a9783ea9150de52212a3cc765bf6cac81f35c45e',
        'eventData': {
            'thresholdLevel': 5,
            'tickers':['usdjpy']
        }
    }
subscribe_btcusd = {
        'eventName': 'subscribe',
        'authorization': 'a9783ea9150de52212a3cc765bf6cac81f35c45e',
        'eventData': {
            'thresholdLevel': 5,
            'tickers':['btcusd']
        }
    }


async def connect_stream(subscriber):
    url = "wss://api.tiingo.com/fx"
    async with websockets.connect(url) as ws:
        await ws.send(json.dumps(subscriber))
        while True:
            try:
                json_message = await ws.recv()
                message = json.loads(json_message)
                symbol = message.get('data')[1]
                bid_price = message.get('data')[4]
                ask_price = message.get('data')[7]

                data = {
                    "symbol" : symbol,
                    "bid": bid_price,
                    "ask": ask_price,
                }
                print("EMMITTING TO ROOM", data)
                socketio.emit("quote_update", data)

                if clientcount[symbol]  == 0:
                    break
            except:
                continue

def thread(subscriber):
    def runner():
        loop = asyncio.new_event_loop()
        asyncio.set_event_loop(loop)
        loop.run_until_complete(connect_stream(subscriber))
    threading.Thread(target=runner, daemon = True).start()

@socketio.on("subscribe")
def subscribe(data):
    try:
        symbol = data.get("symbol")
        if symbol:
            join_room(symbol)
            clientcount[symbol] +=1
            clientsubscription[request.sid] = symbol
            print(f"Client subscribed to {symbol}")
    except:
        print(f"Could not subscribe to {symbol}")

@socketio.on("disconnect")
def disconnect():
    sid = request.sid
    symbol = clientsubscription.get(sid)
    if symbol and clientcount[symbol]>0:
        clientcount[symbol] -=1
    clientsubscription.pop(sid, None)
    print(f"Disconnected")

@app.route('/')
def home():
    print("CONNECTED TO SOCKET")
    return render_template("index.html")

@app.route('/eurusd', methods = ['POST'])
def eurusd():
    try:
        return render_template("choice_eurusd.html", symbol = "eurusd")
    except:
        return render_template("error.html")

@app.route('/eurusd/current', methods = ['POST'])
def eurusd_current():
    threading.Thread(target = lambda: thread(subscribe_eurusd), daemon=True).start() 
    return render_template("current.html", symbol = "eurusd")
    
@app.route('/eurusd/continuous', methods = ['GET', 'POST'])
def eurusd_continuous():
    threading.Thread(target = lambda: thread(subscribe_eurusd), daemon=True).start() 
    return render_template("continuous.html", symbol = "eurusd")
    

@app.route('/usdjpy', methods = ['POST'])
def usdjpy():
    try:
        return render_template("choice_usdjpy.html", symbol = "usdjpy")
    except:
        return render_template("error.html")


@app.route('/usdjpy/current', methods = ['POST'])
def usdjpy_current():
    threading.Thread(target = lambda: thread(subscribe_usdjpy), daemon=True).start() 
    return render_template("current.html", symbol = "usdjpy")
    

@app.route('/usdjpy/continuous', methods = ['GET', 'POST'])
def usdjpy_continuous():
    threading.Thread(target = lambda: thread(subscribe_usdjpy), daemon=True).start()
    return render_template("continuous.html", symbol = "usdjpy")
    
@app.route('/btcusd', methods = ['POST'])
def btcusd():
    try:
        return render_template("choice_btcusd.html", symbol = "btcusd")
    except:
        return render_template("error.html")

@app.route('/btcusd/current', methods = ['POST'])
def btcusd_current():
    threading.Thread(target = lambda: thread(subscribe_btcusd), daemon=True).start() 
    return render_template("current.html", symbol = "btcusd")

@app.route('/btcusd/continuous', methods = ['GET', 'POST'])
def btcusd_continuous():
    threading.Thread(target = lambda: thread(subscribe_btcusd), daemon=True).start() 
    return render_template("continuous.html", symbol = "btcusd")

if __name__=="__main__":
    print("http://127.0.0.1:5000/")
    server = pywsgi.WSGIServer(("127.0.0.1", 5000), app, handler_class=WebSocketHandler, backlog=1024)
    server.serve_forever()