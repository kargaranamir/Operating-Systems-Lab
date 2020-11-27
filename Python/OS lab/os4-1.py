import os
import multiprocessing
import signal
import time

while True:
    try:
        p = multiprocessing.Process()
        p.start()

        print(p.pid)
        p.terminate()


        time.sleep(2)
    except:
        break