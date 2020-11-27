import threading
from math import ceil

a = [1, 5, 6, 2, -1]

size = len(a)
stride = int(ceil(size / 2))

def cal_min(ind):
    global stride, a
    if (ind + stride) < size:
        a[ind] = min(a[ind], a[ind + stride])

while True:
    threads = []
    for i in range(stride):
        th = threading.Thread(target=cal_min, args=(i,))
        th.start()

    for th in threads:
        th.join()

    if stride == 1:
        break
    stride = int(ceil(stride / 2))

print(a[0])