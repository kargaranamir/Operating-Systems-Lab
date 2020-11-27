import signal
import sys

cnt = 0

def signal_handler(signal, frame):
    global cnt
    cnt += 1
    if cnt == 6:
        sys.exit(0)
    print('Ctrl + C recived')


signal.signal(signal.SIGINT, signal_handler)
while True:
    pass
