//
// Created by dellg15 on 23-1-17.
//
#include "lpf.h"
#include <iostream>
#include <fstream>
#include <vector>

#define random_int(a, b)    (rand()%(b-a)+a)
#define random_X(x)         rand()%(x)
#define random_float(a, b)   a + b* rand() /double (RAND_MAX + 1)

LowPassFilter LPF{0.2f};

using namespace std;

// 定义/打开输出的txt文件
ofstream out_txt_file;


int main() {
  srand(20);

  vector<float> Test_data = {
          1.1, 2.3, 3.3, 2.5, 7.4,
          5.6, 5.0, 4.2, 8.3, 6.5,
          10.2, 12.3, 14.5, 13.2, 10.3,
          8.2, 7.1, 4.2, 4.3, 2.0
  };

  float output = 0;
  int i;

  out_txt_file.open("../Data/lpf_data.txt", ios::out | ios::trunc);
  out_txt_file << std::fixed;

  for (i = 0; i < Test_data.size(); i++) {

    output = LPF(Test_data[i]);

    out_txt_file << Test_data[i] << "," << output << "," << std::endl;

  }

  out_txt_file.close();

  return 0;
}