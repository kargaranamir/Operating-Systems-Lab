import os
import multiprocessing
import signal
import time
import random

maxchild = 5

def printMessage():
    random.seed(os.getpid())
    r = random.randint(1, 5)
    time.sleep(r)

    print("message from child", os.getpid(), ", waited for ", r, "seconds.")
    os._exit(0)

processes = []

for i in range(maxchild):
    pid = os.fork()
    processes.append(pid)
    if pid == 0:
        printMessage()


while True:
     try:
        time.sleep(5)
        print()
        for i in range(maxchild):
            state = os.waitpid(processes[i], 0)
            if state != 0:
                pid = os.fork()
                processes[i] = pid
                if pid == 0:
                    printMessage()

     except:
        break