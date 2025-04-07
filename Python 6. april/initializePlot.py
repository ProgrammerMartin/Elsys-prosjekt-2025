from plottVariabler import ax1, ax3, ax4
from sensorData import adata, vdata_abs, time

(line1,) = ax1.plot(time, adata, "r-", label="Akselerasjon")
(line3,) = ax3.plot(time, vdata_abs, "g-", label="Fart")
(line4,) = ax4.plot([], [], [], "b-", label="Strekning")
