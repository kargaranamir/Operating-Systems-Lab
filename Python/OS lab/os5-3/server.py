import os

os.mkfifo('clientToServer')
os.mkfifo('serverToClient')

while True:
    readfifo = open('clientToServer', 'r')
    data = [int(x) for x in readfifo.read().split()]
    readfifo.close()

    if len(data) == 0:
        continue

    print('New Client')
    sum = str(data[0] + data[1])
    writefifo = open('serverToClient', 'w')
    writefifo.write(sum)
    writefifo.close()
