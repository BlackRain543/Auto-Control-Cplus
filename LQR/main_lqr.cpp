//
// Created by a8930 on 2023/1/21.
//
/*
 * LQR(Linear Quadratic Regulator)是线性二次型正则器的缩写。
 * LQR是一种线性控制理论，用于解决线性系统的最优控制问题。
 * 其通过最小化系统的期望状态误差和控制动作的期望值来实现最优控制。
 * LQR算法通过解决一组特定的线性代数方程来解决最优控制问题。
 * 这些方程包括系统的状态方程和控制方程，以及系统的状态和控制的权重矩阵。
 */

#include <iostream>
#include <Eigen/Core>
#include <Eigen/Dense>

using namespace Eigen;

int main() {
  //系统状态矩阵
  MatrixXd A(2, 2);
  A << 1, 1, 0, 1;
  MatrixXd B(2, 1);
  B << 0, 1;

  //系统误差权重矩阵
  MatrixXd Q(2, 2);
  Q << 1, 0, 0, 1;
  MatrixXd R(1, 1);
  R << 1;

  //LQR解
  MatrixXd K = -((R + B.transpose() * Q * B).inverse() * B.transpose() * Q * A).transpose();
  std::cout << "Gain matrix K: \n" << K << std::endl;

  return 0;
}




