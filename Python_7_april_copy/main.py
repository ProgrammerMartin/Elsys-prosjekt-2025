import matplotlib.pyplot as plt
from matplotlib.animation import FuncAnimation
from fellesVariabler import file
from plottVariabler import ax1, ax2, ax3, ax4, fig
from configVariabler import t
from sensorData import time, adata, vdata_abs
from configureAxes import configureAxes
from resetButton import reset
from updateFrame import updateFrame
reset


def main():
    configureAxes(ax1, ax2, ax3, ax4, time, adata, vdata_abs)

    ani = FuncAnimation(fig, updateFrame, interval=t * 1000, blit=False,
                        cache_frame_data=False)
    _ = ani  # Bare for å ikke få advarsel om at "ani blir ikke brukt"

    plt.show()

    file.close()


if __name__ == "__main__":
    main()
