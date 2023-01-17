//
// Created by R9000K on 2022/12/20.
//

#ifndef KF_H
#define KF_H

#include <iostream>
#include <vector>
#include <algorithm>

class KalmanFilter
{
public:
    // 构造函数
    KalmanFilter(double processNoise, double measurementNoise)
            : processNoise(processNoise), measurementNoise(measurementNoise)
    {
      // 初始化状态估计为0
      x = 0;
      // 初始化状态估计误差协方差为1
      p = 1;
    }

    // 预测
    void predict()
    {
      // 状态预测
      x = x;
      // 状态误差协方差预测
      p = p + processNoise;
    }

    // 更新
    void update(double measurement)
    {
      // 更新卡尔曼增益
      k = p / (p + measurementNoise);
      // 更新状态估计
      x = x + k * (measurement - x);
      // 更新状态误差协方差
      p = (1 - k) * p;
    }

    // 获取当前状态估计
    double getEstimate() const
    {
      return x;
    }

private:
    // 状态估计
    double x;
    // 状态误差协方差
    double p;
    // 卡尔曼增益
    double k;
    // 过程噪声
    double processNoise;
    // 测量噪声
    double measurementNoise;
};


#endif //AUTO_CONTROL_CPLUS_KF_H
