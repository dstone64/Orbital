import orbital

stop_execution = False

graphs = [[0,1,0,1]]
input_params = [
    "PARAM1 [Param 1]",
    "PARAM2 [Param 2]",
    "PARAM3"]

def init():
    orbital.sendInit(graphs, input_params)

def run(params):
    global stop_execution
    stop_execution = False

def stop():
    global stop_execution
    stop_execution = True
