//
// Created by a8930 on 2023/1/21.
//
/*
 * PLL (Phase-Locked Loop) 锁相环算法是一种用于调整和维护频率同步的电子电路技术。
 * 它通过比较输入信号的相位和参考信号的相位来控制锁相环的输出频率。
 * 这样可以使输出信号的频率与参考信号的频率保持同步。
 * PLL算法在很多领域都有应用，如通信系统、音频和视频处理、时钟同步和控制系统等。
 */

#include <iostream>
#include <cmath>
#include <complex>

#define PI 3.14159265358979323846

const double ref_freq = 1000.0;   // 参考频率
const double lock_band = 1.0;     // 锁定偏差
const double kp = 1.0;            // PI控制器的比例系数
const double ki = 0.1;            // PI控制器的积分系数

double input_signal;    // 输入信号
double ref_signal;      // 参考信号
double phase_error;     // 相位差
double control_output;  // 控制输出
double output_freq;     // 输出频率
double integral_error;  // 积分误差

int main() {
  while (true) {
    // 计算相位差
    phase_error = std::arg(input_signal) - std::arg(ref_signal);

    while (phase_error > PI) phase_error -= 2 * PI;
    while (phase_error < -PI) phase_error += 2 * PI;

    // 计算积分误差
    integral_error += phase_error;

    // 计算控制输出
    control_output = kp * phase_error + ki * integral_error;

    // 调整输出频率
    output_freq = ref_freq + control_output;

    // 锁定判断
    if (std::abs(phase_error) < lock_band) {
      std::cout << "PLL Locked!" << std::endl;
      break;
    }
  }
  return 0;
}