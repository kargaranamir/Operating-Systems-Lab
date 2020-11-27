import os, random, signal, time
from signal import SIGUSR2

max_child = 5
r, w = os.pipe()
total = 20

def Child_sig_handler(signal, frame):
    global r, w
    random.seed(os.getpid())
    rand = random.randint(2, 5)

    os.write(w, bytes(str(rand), 'ascii'))
    os.kill(os.getppid(), SIGUSR2)

def Parent_sig_handler(signal, frame):
    global r, w, total
    val = os.read(r, 1).decode('ascii')
    total -= int(val)
    print('Recieved ' + val + ' from child.')


def sendVal():
    signal.signal(signal.SIGUSR1, Child_sig_handler)
    while True:
        signal.pause()

processes = []
signal.signal(signal.SIGUSR2, Parent_sig_handler)

for i in range(max_child):
    pid = os.fork()
    if pid == 0:
        sendVal()
    else:
        processes.append(pid)

index = 0
print('Total:', total)
while True:
    os.kill(processes[index], signal.SIGUSR1)
    index = ((index + 1) % max_child)
    time.sleep(0.25)
    if total <= 0:
        break
