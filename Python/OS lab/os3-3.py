from sys import argv

if argv[1] == "-vector":
    m, file = int(argv[2]), argv[3]

    f = open(file, "wb")
    l = []

    for i in range(4, 4 + m):
        num = int(argv[i])
        l.append(num)

    f.write(bytearray(l))
    f.close()

if argv[1] == "-readVecAll":
    count, file = int(argv[2]), argv[3]
    f = open(file, "rb")

    for i in range(count):
        print(int.from_bytes(f.read(1), byteorder='big'))

    f.close()


if argv[1] == "-readVec":
    j, file = int(argv[2]), argv[3]
    f = open(file, "rb")

    f.seek(j)
    print(int.from_bytes(f.read(1), byteorder='big'))

    f.close()