//
// Created by a8930 on 2023/1/23.
//
#include <iostream>
#include <vector>
#include <fstream>

#define randint(a, b)    (rand()%(b-a)+a)
#define random_X(x)       rand()%(x)
#define randfloat(a, b)   a + b* rand() /double (RAND_MAX + 1)

using namespace std;

void random_data_generate(string path, double min, double max, int length) {
  ofstream out_txt_file;

  out_txt_file.open(path, std::ios::out | std::ios::trunc);
  out_txt_file << std::fixed;

  for (int i = 0; i < length; i++) {
    out_txt_file << randfloat(min, max) << "," << std::endl;
  }
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

int main() {
  srand(20);

  vector<double> Data;
  string path = "../Data/random_data.txt";

  random_data_read(path, Data);

  for (int i = 0; i < Data.size(); i++) {
    cout << Data.at(i) << endl;
  }

  return 0;
}
