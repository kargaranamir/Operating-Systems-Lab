import socket

s = socket.socket()
host = socket.gethostname()
port = 8889

s.connect((host, port))

while True:
    try:
        msg = input()
        s.send(msg.encode())

        ans = s.recv(1024).decode()
        print(ans)
    except:
        s.close()
        break