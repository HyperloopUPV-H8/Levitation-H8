# echo-server.py

import socket

HOST = '192.168.7.1'  # Standard loopback interface address (localhost)
PORT = 8015  # Port to listen on (non-privileged ports are > 1023)

with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
    s.bind((HOST, PORT))
    s.listen()
    conn, addr = s.accept()
    with conn:
        print(f"Connected by {addr}")
        while True:
            data = conn.recv(1024)
            print(f"Received {data!r}")
            if not data:
                break
            conn.sendall(data)
