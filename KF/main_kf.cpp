//
// Created by a8930 on 2022/12/8.
//

#include "kf.h"
#include <fstream>

std::ofstream out_txt_file;

// 定义过程噪声和测量噪声
const double processNoise = 0.1;
const double measurementNoise = 0.5;

// 创建二阶卡尔曼滤波器
KalmanFilter filter(processNoise, measurementNoise);

// 模拟真实值
std::vector<double> trueValues = {10, 10.5, 11, 11.5, 12,
                                  11.5, 11, 10.5, 13, 13.5,
                                  14, 14.5, 15, 16, 16.5};
// 模拟测量值
std::vector<double> measurements = {9.8, 10.2, 10.7, 11.1, 12.1,
                                    11.3, 11.2, 10.6, 13.1, 13.4,
                                    14.2, 14.6, 14.9, 16.2, 16.8};

int main() {

  out_txt_file.open("../Data/kf_data.txt", std::ios::out | std::ios::trunc);
  out_txt_file << std::fixed;

  // 模拟滤波过程
  for (int i = 0; i < measurements.size(); i++) {
    filter.predict();                           // 预测
    filter.update(measurements[i]);             // 更新

    // 获取当前状态估计
    double estimate = filter.getEstimate();

    // 输出当前状态估计和真实值
//    std::cout << "Estimate: " << estimate << ", True value: " << trueValues[i] << std::endl;
    out_txt_file << trueValues[i] << "," << estimate << "," << std::endl;
  }


  out_txt_file.close();
  return 0;
}
