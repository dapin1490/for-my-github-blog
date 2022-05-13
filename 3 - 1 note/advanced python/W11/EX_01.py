import numpy as np
import matplotlib.pyplot as plt

def f(t):  # e^-t x cos(2pi x t)
    return np.exp(-t) * np.cos(2 * np.pi * t)

def g(t):  # sin(pi x t)
    return np.sin(np.pi * t)

def h(t):  # exp(-t)
    return np.exp(-t)

def k(t):  # -exp(-t)
    return -np.exp(-t)

t = np.arange(0.0, 5.0, 0.01)  # 0.00, 0.01, 0.02, ... 4.99

plt.plot(t, f(t), t, g(t), 'r-', t, h(t), 'cyan', t, k(t), 'magenta')
# y = f(t) (지정 형식 없음, 디폹트), y = g(t) (빨간 실선)
plt.xlabel("x-axis")
plt.ylabel("y-axis")
plt.title("Drawing graph")
plt.grid()

plt.show()
