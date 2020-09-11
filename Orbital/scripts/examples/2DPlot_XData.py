import orbital
import math
import time

stop_execution = False

plots = [[0,1,0,1]]
input_params = [
    "RINGS [Ring Density]"]
n_rows = 400
n_cols = 1000
x_min = -5.0
x_max = 5.0
y_min = -10.0
y_max = 10.0

def init():
    orbital.init(plots, input_params)

def run(params):
    global stop_execution
    stop_execution = False

    rings = int(params['RINGS'])
    
    orbital.set2DPlotProperty(1, 'line style', 'Impulse')
    orbital.set2DPlotProperty(1, 'scatter style', 'None')
    orbital.set2DPlotProperty(1, 'color', 'Dark Yellow')
    f(rings)
    
    orbital.set2DPlotProperty(1, 'line style', 'None')
    orbital.set2DPlotProperty(1, 'scatter style', 'Peace')
    orbital.set2DPlotProperty(1, 'scatter size', '12')
    orbital.set2DPlotProperty(1, 'color', 'Dark Red')
    f(rings)

def stop():
    global stop_execution
    stop_execution = True

def f(rings):
    x_scale = (x_max - x_min)/n_cols
    y_scale = (y_max - y_min)/n_rows
    dt = 0.05
    for T in range(2):
        dT = dt*T
        for row in range(n_rows):
            x_arr = []
            y_arr = []
            y = row*y_scale + y_min
            for col in range(n_cols):
                if stop_execution:
                    return
                x = col*x_scale + x_min
                r = math.sqrt(x*x + y*y)
                r = rings*r + 0.01
                z = 4*x*(math.cos((r+2))/(r - math.sin((r+2)/r)))
                x_arr.append(x)
                y_arr.append(z)
            orbital.sendData(1, 0)
            orbital.sendXData(1, x_arr, y_arr, False)
            orbital.msg('Time: ' + str(round(dT*n_rows+dt*row, 1)))
            time.sleep(dt)
    
