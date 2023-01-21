//
// Created by dellg15 on 23-1-17.
//
#include "pid.h"
#include <iostream>
#include <fstream>

PidController PID{0.3, 5, 0, 0, 300};

// 定义/打开输出的txt文件
std::ofstream out_txt_file;


int main() {

  float target = 50.0f;
  float output = 0.0f;

  int i = 0;
  int n = 5000;

  out_txt_file.open("../Data/pid_data.txt", std::ios::out | std::ios::trunc);
  out_txt_file << std::fixed;

  while (true) {
    if (i >= n)
      break;
    output = PID(target - output);

    i++;
//    std::cout<<output<<",";
    out_txt_file << target << "," << output << "," << std::endl;

  }
  out_txt_file.close();

  return 0;
}