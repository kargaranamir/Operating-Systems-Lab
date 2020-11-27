import os, sys, time, random, signal

max_child = 5

def sendVal(r, w):
    random.seed(os.getpid())
    while True:
        time.sleep(1)
        os.close(r)
        p = os.fdopen(w, 'w')

        rand = random.randint(0, 10)
        p.write(str(rand))
        p.close()



pipes = []
processes = []

for i in range(max_child):
    r, w = os.pipe()
    pipes.append((r, w))
    pid = os.fork()
    if pid == 0:
        sendVal(r, w)
    else:
        processes.append(pid)

total = 0
while total < 20:
    for p in pipes:
        r, w = p[0], p[1]
        os.close(w)

        f = os.fdopen(r)
        val = int(f.read())

        total += val
        print(total)

for pid in processes:
    os.kill(pid, signal.SIGKILL)