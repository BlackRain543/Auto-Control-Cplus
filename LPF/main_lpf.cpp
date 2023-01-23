//
// Created by dellg15 on 23-1-17.
//
#include "lpf.h"
#include <iostream>
#include <fstream>
#include <vector>

LowPassFilter LPF{0.8f};

using namespace std;

// 定义/打开输出的txt文件
ofstream out_txt_file;

void random_data_read(string path, vector<double> &data);

int main() {

  vector<double> Test_data = {
          1.1, 2.3, 3.3, 2.5, 7.4,
          5.6, 5.0, 4.2, 8.3, 6.5,
          10.2, 12.3, 14.5, 13.2, 10.3,
          8.2, 7.1, 4.2, 4.3, 2.0
  };

//  string read_path = "../Data/random_data.txt";
//  random_data_read(read_path,Test_data);

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

void random_data_read(string path, vector<double> &data) {
  ifstream f(path);

  string line;
  vector<double> Data;

  while (getline(f, line)) {
    line.back() = 0;
    data.push_back(stod(line));
  }
}