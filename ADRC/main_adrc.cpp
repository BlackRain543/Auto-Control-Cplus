//
// Created by a8930 on 2023/1/21.
//
/*
 * ADRC(Adaptive Dynamic Programming and Robust Control)算法是一种智能控制算法，
 * 其结合了自适应控制和鲁棒控制的优点。
 * ADRC算法通过自适应地调整控制参数来实现对系统的控制，并通过鲁棒控制来应对系统的不确定性。
 * ADRC算法包括两个主要部分：自适应控制器和鲁棒控制器。
 * 自适应控制器负责在线地估计系统的参数，并使用这些参数来更新控制器的参数。
 * 鲁棒控制器负责在系统参数变化时保持系统稳定。
 */
#include<iostream>
#include"LADRC.h"

using namespace std;

int main() {
  float u = 0;
  //LADRC(float Wo, float Wc, float b, float y, float h, float ref);
  LADRC ladrc(10, 10, 1, 0.8, 0.02, 1);
  u = ladrc.Output();
  cout << "u=" << u << endl;

  return 0;


}