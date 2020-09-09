import orbital
import time
import math

stop_execution = False

input_params = [
    "TIME [Plot Time (s)]"]

def init():
    orbital.sendInit(1, input_params)

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
        orbital.sendData(1, 2, x, fn(x))
        time.sleep(time_delta)
        x += interval

def stop():
    global stop_execution
    stop_execution = True

def fn(x):
    return math.sin(20*math.pi*x)*math.exp(-x**2)
