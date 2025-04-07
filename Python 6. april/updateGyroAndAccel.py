import gyro as g
from sensorData import adata, vdata, vdata_abs, sdata, cv
from fellesVariabler import file, gyroc
from plottVariabler import ax2, gyro_vector
from configVariabler import t
import numpy as np

_ = adata  # Dette gjør at lintern forstår at adata faktisk brukes
_ = vdata
_ = vdata_abs
_ = sdata
_ = cv
_ = gyro_vector


def updateGyroAndAccel(accelx, accely, accelz, gyrox, gyroy, gyroz):

    # Skriver "global" for å endre de globale variablene
    global cv, gyro_vector, adata, vdata, vdata_abs, sdata

    if gyrox is not None:
        gyrox = gyrox * gyroc
        gyroy = gyroy * gyroc
        gyroz = gyroz * gyroc
        cv = g.rotate_vector(cv, gyrox, gyroy, gyroz, t)
        gyro_vector.remove()  # Remove previous gyro vector plot
        gyro_vector = ax2.quiver(0, 0, 0, cv[0], cv[1], cv[2], color="red")

    if accelx is not None:
        # Calculate the length of the acceleration vector
        accel = np.sqrt(accelx**2 + accely**2 + accelz**2)
        # Update acceleration for plotting
        adata[:-1], adata[-1] = adata[1:], accel

        # Update velocity (x, y, z)
        vdata[:-1], vdata[-1] = vdata[1:], (
            vdata[-1][0] + accelx * t,  # Update for x
            vdata[-1][1] + accely * t,  # Update for y
            vdata[-1][2] + accelz * t   # Update for z
        )

        # Update speed for absolute velocity plot
        total_speed = np.sqrt(
            vdata[-1][0]**2 +
            vdata[-1][1]**2 +
            vdata[-1][2]**2)
        vdata_abs[:-1], vdata_abs[-1] = vdata_abs[1:], total_speed

        # Update position (x, y, z)
        sdata[:-1], sdata[-1] = sdata[1:], (
            sdata[-1][0] + vdata[-1][0] * t,  # Update for x
            sdata[-1][1] + vdata[-1][1] * t,  # Update for y
            sdata[-1][2] + vdata[-1][2] * t   # Update for z
        )

    # Skriver data til filen "data.csv"
    data = f"{accel},{cv[0]},{cv[1]},{cv[2]}\n"
    file.write(data)
