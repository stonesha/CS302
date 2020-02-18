import matplotlib.pyplot as plt
import numpy as np

sigma1 = np.loadtxt("sigma1.txt")
sigma5 = np.loadtxt("sigma5.txt")
sigma11 = np.loadtxt("sigma11.txt")
x_axis = np.linspace(0.0, 255.0, num=128)

plt.plot(x_axis, sigma1)
plt.plot(x_axis, sigma5)
plt.plot(x_axis, sigma11)
plt.legend(['sigma=1', 'sigma=5', 'sigma=11'], loc='upper left')
plt.xlabel("x")
plt.xlabel("G(x)")

plt.show()

