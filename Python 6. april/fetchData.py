import socket
from nettverksVariabler import host, port


def fetchData():
    client_socket = socket.socket()

    try:
        client_socket.connect((host, port))
        raw_data = client_socket.recv(2048).decode("utf-8").strip()
        data = raw_data.split(",")

        if len(data) >= 6:
            accel_x, accel_y, accel_z = map(float, data[:3])
            gyro_x, gyro_y, gyro_z = map(float, data[3:])

            return accel_x, accel_y, accel_z, gyro_x, gyro_y, gyro_z
        else:
            raise Exception("Ugyldig dataformat")

    except Exception as e:
        print(f"Feil: {e}")
        return None, None, None, None, None, None
