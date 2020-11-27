import threading, time

THREADS = 10

# lo = threading.Lock()
lock = 0
inc = 1

def work(t):
    global lock, inc, lo
    while True:
        # lo.acquire()
        # try:
        time.sleep(1/100000.0)
        if t == lock:
            print('thread_id = ' + str(t))

            if t == 0:
                inc = 1
            elif t == THREADS - 1:
                inc = -1

            lock += inc

        # finally:
        #     lo.release()


threads = []
for ind in range(THREADS):
    th = threading.Thread(target=work, args=(ind,))
    th.start()


for th in threads:
    th.join()