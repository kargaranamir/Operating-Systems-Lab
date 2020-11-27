import socket

MAX_CLIENT = 5

class client():
    def __init__(self, socket, address):
        self.sock = socket
        self.addr = address
        self.run()

    def run(self):
        while(1):
            msg = c.recv(1024).decode()
            a, b = [int(x) for x in msg.split()]
            self.sock.send((str(a + b)).encode())

s = socket.socket()
host = socket.gethostname()
port = 8889
s.bind((host, port))

s.listen(5)
clients = 0
while clients < MAX_CLIENT:
    clientSocket, addr = s.accept()
    print('Got connection from', addr)
    # client(c, addr)
    msg = clientSocket.recv(1024).decode()
    a, b = [int(x) for x in msg.split()]
    clientSocket.send((str(a + b)).encode())
