from sys import argv
import os
v1, v2 = int(argv[1]), int(argv[2])
prefix = argv[3]
addr = argv[4] + '/'

for i in range(v1, v2 + 1):
    os.system("useradd " + prefix + "-" + str(i) + " -m")
    os.system("cp -r " + addr + " /home/" + prefix + "-" + str(i))
