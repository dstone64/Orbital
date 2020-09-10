import orbital
import math

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
    x_scale = (x_max - x_min)/n_cols
    y_scale = (y_max - y_min)/n_rows
    
    for i in range(n_rows*n_cols):
        if stop_execution:
            break
        row = int(i / n_cols)
        col = int(i % n_cols)
        x = col*x_scale + x_min
        y = row*y_scale + y_min
        r = math.sqrt(x*x + y*y)
        if r > 14.25:
            z = 0
        else:
            r = rings*r + 0.01
            z = 4*x*(math.cos(r+2)/(r - math.sin(r+2)/r))
        orbital.sendCMData(1, col, row, z)

def stop():
    global stop_execution
    stop_execution = True
