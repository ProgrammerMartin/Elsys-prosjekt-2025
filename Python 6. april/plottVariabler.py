import matplotlib.pyplot as plt
from sensorData import cv

# Oppretter en figur
fig = plt.figure(figsize=(10, 8))

# Oppretter subplots til figuren individuelt
ax1 = fig.add_subplot(2, 2, 1)  # 2D-plot øverst til venstre
ax3 = fig.add_subplot(2, 2, 2)  # 2D-plot øverst til høyre
ax4 = fig.add_subplot(2, 2, 3, projection='3d')  # 3D-plot nederst til venstre
ax2 = fig.add_subplot(2, 2, 4, projection='3d')  # 3D-plot nederst til høyre

# Initialize 3D gyro vector plot
gyro_vector = ax2.quiver(0, 0, 0, cv[0], cv[1], cv[2], color="red")
