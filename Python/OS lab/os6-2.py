import os, sys, time, random, signal

max_child = 5
total = 0

def sigHandler(signal, frame):
    # print("Signal recieved")
    global total
    total += 1
    print(total)

def sendSignal(pid):
    random.seed(os.getpid())
    while True:
        r = random.randint(1, 5)
        time.sleep(r)
        os.kill(pid, signal.SIGUSR1)



processes = []
ppid = os.getpid()
for i in range(max_child):
    pid = os.fork()
    if pid == 0:
        sendSignal(ppid)
    else:
        processes.append(pid)

signal.signal(signal.SIGUSR1, sigHandler)
while total < 20:
    pass

for pid in processes:
    os.kill(pid, signal.SIGKILL)