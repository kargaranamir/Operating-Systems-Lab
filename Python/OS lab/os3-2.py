from sys import argv

com = argv[1]

if com == '-make':
    path = argv[2]
    name = argv[3]
    format = argv[4]
    a = argv[5]
    b = argv[6]

    for i in range(int(a), int(b) + 1):
        f = open(path+name + str(i) + '.' + format, 'w+')
        f.close()