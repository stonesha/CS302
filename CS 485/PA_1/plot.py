import matplotlib.pyplot as plt
import numpy as np

sigma1 = np.loadtxt("sigma-1.txt")
sigma5 = np.loadtxt("sigma-5.txt")
sigma11 = np.loadtxt("sigma-11.txt")

#plt.plot(sigma1, np.linspace(0, 0.5, num=128))
plt.plot(np.linspace(0, 0.5, num=128), sigma1)
plt.show()

