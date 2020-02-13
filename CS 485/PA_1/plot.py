import matplotlib.pyplot as plt
import numpy as np

sigma1 = np.loadtxt("sigma1.txt")
sigma5 = np.loadtxt("sigma5.txt")
sigma11 = np.loadtxt("sigma11.txt")

fig, axs = plt.subplots(1, 3, tight_layout=True)

axs[0].invert_yaxis()
axs[0].hist(sigma1)
axs[1].hist(sigma5)
axs[2].hist(sigma11)

plt.show()

