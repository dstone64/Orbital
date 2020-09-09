import orbital
import math
import time

stop_execution = False

graphs = [[0,1,0,1],[0,2,1,2],[1,1,0,1],[2,1,0,1],[2,1,1,2]]
input_params = [
    "TIME [Plot Time (s)]"]

def init():
    orbital.sendInit(graphs, input_params)
    orbital.set2DPlotProperty(1, 'scatter style', 'None')

def run(params):
    global stop_execution
    stop_execution = False
    start = -2.5
    end = 2.5
    interval = 0.001
    time_delta = float(params["TIME"]) / ((end - start)/interval)
    
    x = start
    while x <= end:
        if stop_execution:
            break
        orbital.sendData(1, 2, x, fn1(x))
        orbital.sendData(3, 2, x, fn2(x))
        orbital.sendData(4, 2, x, fn3(x))
        orbital.sendData(5, 2, x, fn4(x))
        orbital.sendData(2, 2, x, fn5(x))
        time.sleep(time_delta)
        x += interval

def stop():
    global stop_execution
    stop_execution = True

def fn1(x):
    return 20*math.pi*x

def fn2(x):
    return math.sin(fn1(x))

def fn3(x):
    return fn2(x)*math.exp(-x**2)

def fn4(x):
    return math.erf(x)

def fn5(x):
    return fn3(fn4(x))
