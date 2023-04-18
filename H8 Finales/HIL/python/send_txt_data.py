import socket
import struct
import time

HOST = 'localhost'  # Standard loopback interface address (localhost)
PORT = 1024  # Port to listen on (non-privileged ports are > 1023)

f = open("u_send.txt","r")

with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
    s.bind((HOST, PORT))
    s.listen()
    conn, addr = s.accept()
    with conn:
        print(f"Connected by {addr}")
        for line in f: #Reads a line at 2 kHz
            a = f.readline()
            #data = struct.pack('!d', a)
            conn.sendall(bytes(a, encoding='utf-8'))
            time.sleep(0.0005)

f.close()
