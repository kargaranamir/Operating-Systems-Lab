import os, random


writefifo = open('clientToServer', 'w')
r1, r2 = random.randint(1, 10), random.randint(1, 10)
print(r1, r2)
writefifo.write(str(r1) + ' ' + str(r2))
writefifo.close()

while True:
    readfifo = open('serverToClient', 'r')
    data = readfifo.read()
    readfifo.close()

    if len(data):
        print(data)
        break