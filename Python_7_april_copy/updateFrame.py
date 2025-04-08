from plottVariabler import gyro_vector
from initializePlot import line1, line3, line4
from fetchData import fetchData
from sensorData import adata, vdata_abs, sdata
from updateGyroAndAccel import updateGyroAndAccel


def updateFrame(frame):

    # Oppdaterer grensene på y-aksene i 2D-plottene hver gang
    # ax1.set_ylim(0, max(adata) + 0.5)
    # ax3.set_ylim(0, max(vdata_abs) + 0.5)

    # Henter akselerometer og gyroskopdata via nettverket
    accelx, accely, accelz, gyrox, gyroy, gyroz = fetchData()

    print(f"{accelx}, {accely}, {accelz}")
    # Oppdaterer python-listene som inneholder akselerasjon, fart,
    # posisjon og retning
    updateGyroAndAccel(accelx, accely, accelz, gyrox, gyroy, gyroz)

    # Oppdaterer linjeobjektene med den nye dataen
    line1.set_ydata(adata)
    line3.set_ydata(vdata_abs)
    line4.set_data(sdata[:, 0], sdata[:, 1])
    line4.set_3d_properties(sdata[:, 2])

    # Returnerer linjeobjektene og retningsvektoren til
    # ani (FuncAnimation-objektet), som bruker dette til å oppdatere plottet
    return line1, line3, line4, gyro_vector
