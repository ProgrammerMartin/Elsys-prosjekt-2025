def configureAxes(ax1, ax2, ax3, ax4, time, adata, vdata_abs):
    # Set axes limits
    for ax in [ax1, ax3, ax4]:
        ax.set_xlim(time[0], time[-1])

    ax2.set_xlim([-1, 1])
    ax2.set_ylim([-1, 1])
    ax2.set_zlim([-1, 1])
    ax1.set_ylim(0, max(adata) + 0.5)
    ax3.set_ylim(0, max(vdata_abs) + 0.5)
    ax4.set_xlim([-2, 2])
    ax4.set_ylim([-2, 2])
    ax4.set_zlim([-2, 2])

    ax1.set_ylabel("Akselerasjon (m/s²)")
    ax3.set_ylabel("Fart (m/s)")
    ax1.set_xlabel("Tid (s)")
    ax3.set_xlabel("Tid (s)")