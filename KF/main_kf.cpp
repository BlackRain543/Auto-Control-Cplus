//
// Created by a8930 on 2022/12/8.
//

#include "kf.h"

int main()
{
  // 定义过程噪声和测量噪声
  const double processNoise = 0.1;
  const double measurementNoise = 0.5;

  // 创建二阶卡尔曼滤波器
  KalmanFilter filter(processNoise, measurementNoise);

  // 模拟真实值
  std::vector<double> trueValues = { 10, 10.5, 11, 11.5, 12 };

  // 模拟测量值
  std::vector<double> measurements = { 9.8, 10.2, 10.7, 11.1, 12.1 };

  // 模拟滤波过程
  for (int i = 0; i < measurements.size(); i++)
  {
    // 预测
    filter.predict();

    // 更新
    filter.update(measurements[i]);

    // 获取当前状态估计
    double estimate = filter.getEstimate();

    // 输出当前状态估计和真实值
    std::cout << "Estimate: " << estimate << ", True value: " << trueValues[i] << std::endl;
  }

  return 0;
}
