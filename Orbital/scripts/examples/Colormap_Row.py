import orbital
import math
import time

stop_execution = False

plots = [[0,1,0,1]]
input_params = [
    "RINGS [Ring Density]"]
n_rows = 100
n_cols = 100
x_min = -5.0
x_max = 5.0
y_min = -5.0
y_max = 5.0

def init():
    orbital.init(plots, input_params)
    orbital.setupColormap(1, x_min, x_max, y_min, y_max, n_rows, n_cols, -1, 1)
    orbital.setColormapProperty(1, 'title', 'Colormap Example')
    orbital.setColormapProperty(1, 'color min', 'Dark Magenta')
    orbital.setColormapProperty(1, 'color mid', 'Black')
    orbital.setColormapProperty(1, 'color max', 'Red')

def run(params):
    global stop_execution
    stop_execution = False

    rings = int(params['RINGS'])
    f(rings)

def stop():
    global stop_execution
    stop_execution = True

def f(rings):
    x_scale = (x_max - x_min)/n_cols
    y_scale = (y_max - y_min)/n_rows
    dt = 0.05

    for t in range(200):
        wt = -t*0.1
        for row in range(n_rows):
            y = row*y_scale + y_min
            z_vals = []
            for col in range(n_cols):
                if stop_execution:
                    return
                x = col*x_scale + x_min
                r = rings*math.sqrt(x*x + y*y) + 0.01
                z = 4*x*(math.cos(wt+r+2)/(r - math.sin(wt+r+2)/r))
                z_vals.append(z)
            orbital.sendCMDataRow(1, row, z_vals)
        time.sleep(dt)
