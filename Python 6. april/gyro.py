import numpy as np


def rotate_vector(initial_vector, delta_theta_x, delta_theta_y, delta_theta_z,
                  t):
    theta_x = np.radians(delta_theta_x*t)
    theta_y = np.radians(delta_theta_y*t)
    theta_z = np.radians(delta_theta_z*t)

    Rx = np.array([
        [1, 0, 0],
        [0, np.cos(theta_x), -np.sin(theta_x)],
        [0, np.sin(theta_x), np.cos(theta_x)]
    ])

    Ry = np.array([
        [np.cos(theta_y), 0, np.sin(theta_y)],
        [0, 1, 0],
        [-np.sin(theta_y), 0, np.cos(theta_y)]
    ])

    Rz = np.array([
        [np.cos(theta_z), -np.sin(theta_z), 0],
        [np.sin(theta_z), np.cos(theta_z), 0],
        [0, 0, 1]
    ])

    R = Rz @ Ry @ Rx

    rotated_vector = list(R @ initial_vector)

    return rotated_vector
