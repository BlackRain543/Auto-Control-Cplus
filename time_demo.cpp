//
// Created by a8930 on 2023/1/21.
//
#include <time.h>
#include <iostream>
#include <cmath>
#include <windows.h>

int main() {
  float a;
  clock_t start, end;
  start = clock();

  Sleep(999);

  end = clock();
  std::cout << "time = " << double(end - start) << "s" << std::endl;  //输出时间（单位：ｓ）
}
