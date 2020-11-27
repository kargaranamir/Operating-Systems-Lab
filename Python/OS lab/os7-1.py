import threading

SIZE = 5
THREADS = 3

lock = threading.Lock()
product = 0

a = [1, 2, 3, 4, 5]
b = [10, 20, 30, 40, 50]

def cal_product(ind):
    global lock, product, a, b
    sum = 0

    while ind < SIZE:
        sum += a[ind] * b[ind]
        ind += THREADS

    lock.acquire()
    try:
        product += sum
    finally:
        lock.release()


threads = []
for ind in range(THREADS):
    th = threading.Thread(target=cal_product, args=(ind,))
    th.start()

for th in threads:
    th.join()

print(product)
