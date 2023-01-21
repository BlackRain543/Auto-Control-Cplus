//
// Created by a8930 on 2022/12/9.
//

#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

// 状态向量的维度
const int state_dim = 6;
// 控制向量的维度
const int control_dim = 2;
// 时间步长
const double dt = 0.1;
// 预测的时间步数
const int N = 10;

// 状态向量
double x[state_dim];
// 控制向量
double u[control_dim];

// 约束条件
vector<double> lower_bounds = {-1.0, -2.0};
vector<double> upper_bounds = {1.0, 5.0};

// 系统动力学方程
void dynamics(double* x, double* u, double* x_next) {
  x_next[0] = x[0] + dt * x[3];
  x_next[1] = x[1] + dt * x[4];
  x_next[2] = x[2] + dt * x[5];
  x_next[3] = x[3] + dt * u[0];
  x_next[4] = x[4] + dt * u[1];
  x_next[5] = x[5];
}

// 目标函数
double objective(double* x, double* u) {
  double cost = 0;
  // 计算控制代价
  for (int i = 0; i < control_dim; i++) {
    cost += u[i] * u[i];
  }
  // 计算状态代价
  for (int i = 0; i < state_dim; i++) {
    cost += x[i] * x[i];
  }
  return cost;
}

// MPC 控制循环
void mpc_control(double* x_init) {
  // 初始化状态向量
  for (int i = 0; i < state_dim; i++) {
    x[i] = x_init[i];
  }

  // 迭代优化控制
  for (int i = 0; i < N; i++) {
    // 优化目标函数，求得最优控制解
    // 这里假设已经求得了最优控制解，并将其存储在变量 u 中
    // 根据当前状态和控制解，计算下一个状态
    double x_next[state_dim];
    dynamics(x, u, x_next);

    // 更新状态向量
    for (int j = 0; j < state_dim; j++) {
      x[j] = x_next[j];
    }

    // 检查约束条件，并调整控制解以满足约束条件
    for (int j = 0; j < control_dim; j++) {
      if (u[j] < lower_bounds[j]) {
        u[j] = lower_bounds[j];
      } else if (u[j] > upper_bounds[j]) {
        u[j] = upper_bounds[j];
      }
    }
  }
}

int main() {
  // 初始状态向量
  double x_init[state_dim] = {1.0, 3.0, 0.5, 7.0, 5.0, 50.0};

  // 运行 MPC 控制循环
  mpc_control(x_init);

  // 输出最终状态向量
  for (int i = 0; i < state_dim; i++) {
    cout << x[i] << " ";
  }
  cout << endl;

  return 0;
}
