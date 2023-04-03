# server-graph.py

import socket
import matplotlib.pyplot as plt
import datetime

HOST = '127.0.0.1'  # Standard loopback interface address (localhost)
PORT = 65432  # Port to listen on (non-privileged ports are > 1023)

data = []

with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
    s.bind((HOST, PORT))
    s.listen()
    conn, addr = s.accept()
    with conn:
        print(f"Connected by {addr}")
        while True:
            received_data = conn.recv(1024)
            #print(f"Received {received_data!r}")
            data.append(str(received_data))
            #time.append(datetime.datetime.now())
            if not received_data:
                # Crear un gráfico con los datos y tiempos
                plt.plot(data)
                plt.title('Datos TCP recibidos')
                plt.show()
                break
            #conn.sendall(data)
    


