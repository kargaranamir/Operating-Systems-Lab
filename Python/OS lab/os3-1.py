from sys import argv
import os

com = argv[1]

if com == '-c':
    per = argv[2]
    path = argv[3]

    f = open(path, 'w+')
    f.close()

    os.chmod(path, int(per, 8))


elif com == '-w':
    path = argv[2]

    str = ''
    while True:
        try:
            str += input() + '\n'
        except:
            break

    f = open(path, 'w')
    f.write(str)
    f.close()
    os.chmod(path, 0o755)

elif com == '-r':
    path = argv[2]

    f = open(path, 'r')
    for line in f:
        print(line, end='')
    f.close()