import os
import random
import time

max_child = 5
processes = []

def wait():
    random.seed(os.getpid())
    os.execl('./a.out', './a.out', str(random.randint(2, 5)))

while True:
    pid = os.fork()
    if pid == 0:
        wait()

    else:
        t1 = time.time()
        os.waitpid(pid, 0)
        t2 = time.time()
        print(t2 - t1, 'seconds')




