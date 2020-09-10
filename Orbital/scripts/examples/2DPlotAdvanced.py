import orbital
import math
import time

stop_execution = False

graphs = [[0,1,0,1],[0,2,1,2],[1,1,0,1],[2,1,0,1],[2,1,1,2]]
input_params = [
    "TIME [Plot Time (s)]"]

def init():
    orbital.init(graphs, input_params)
    orbital.set2DPlotProperty(1, 'title', 'Linear Step')
    orbital.set2DPlotProperty(1, 'line style', 'Step Left')
    orbital.set2DPlotProperty(1, 'scatter style', 'None')
    orbital.set2DPlotProperty(2, 'title', 'f(x) = sin(20*pi*erf(x))*exp(-erf(x)^2)')
    orbital.set2DPlotProperty(2, 'x label', 'x')
    orbital.set2DPlotProperty(2, 'y label', 'y')
    orbital.set2DPlotProperty(2, 'scatter style', 'None')
    orbital.set2DPlotProperty(2, 'color', 'Red')
    orbital.set2DPlotProperty(3, 'title', 'Error Function')
    orbital.set2DPlotProperty(3, 'scatter style', 'Cross Square')
    orbital.set2DPlotProperty(3, 'scatter size', '10')
    orbital.set2DPlotProperty(3, 'color', 'Dark Magenta')
    orbital.set2DPlotProperty(4, 'title', 'Sinusoidal Pulse')
    orbital.set2DPlotProperty(4, 'scatter style', 'None')
    orbital.set2DPlotProperty(5, 'title', 'Sinusoidal')
    orbital.set2DPlotProperty(5, 'scatter style', 'None')

def run(params):
    global stop_execution
    stop_execution = False
    start = -2500
    end = 2500
    time_delta = float(params["TIME"]) / (end - start)
    
    i = start
    while i <= end:
        orbital.msg(str(i))
        if stop_execution:
            break
        x = float(i) / 1000.0
        if i % 100 == 0:
            orbital.sendData(1, 2, x, fn1(x))
            orbital.sendData(3, 2, x, fn4(x))
        orbital.sendData(5, 2, x, fn2(x))
        orbital.sendData(4, 2, x, fn3(x))
        orbital.sendData(2, 2, x, fn5(x))
        time.sleep(time_delta)
        i += 1

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
