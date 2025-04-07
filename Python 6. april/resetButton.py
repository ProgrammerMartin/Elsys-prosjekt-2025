import numpy as np
from matplotlib.widgets import Button
from plottVariabler import gyro_vector, fig
from sensorData import adata, vdata, vdata_abs, sdata
from initializePlot import line1, line3, line4
_ = gyro_vector
_ = adata
_ = vdata
_ = vdata_abs
_ = sdata
_ = line1
_ = line3
_ = line4


def reset(event):
    print("reset() kalt")
    global adata, vdata, vdata_abs, sdata, cv, gyro_vector, line1, line3, line4

    adata.fill(0)
    vdata.fill(0)
    vdata_abs.fill(0)
    sdata.fill(0)
    cv = np.array([1, 1, 0])

    line1.set_ydata(adata)
    line3.set_ydata(vdata_abs)
    line4.set_data([], [])
    line4.set_3d_properties([])
    print(f"cv[0] = {cv[0]}")
    # gyro_vector.remove()  # Dette fungerer ikke her fsr
    # gyro_vector = ax2.quiver(0, 0, 0, cv[0], cv[1], cv[2], color="remove")


reset_ax = fig.add_axes([0.8, 0.01, 0.1, 0.05])
reset_button = Button(reset_ax, 'Reset')
reset_button.on_clicked(reset)
