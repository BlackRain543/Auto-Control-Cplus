import numpy as np
import matplotlib.pyplot as plt


# 设置点数
num = 100

# 设置噪声系数
rate = 0

# 生成数据
x = np.linspace(-10, 10, num)
y = []
a = 2.2
b = 1.4
c = -1.3

for i in x:
    noise = np.random.random()
    temp = i + noise * rate
    y.append(a * pow(temp, 2) + b * temp + c)

# 绘制曲线
plt.plot(x, y)
plt.show()

# 写入文件
with open("../points.txt", 'w') as f:
    for i in range(num):
        f.write(str(x[i]))
        f.write("\t")
        f.write(str(y[i]))
        f.write("\n")