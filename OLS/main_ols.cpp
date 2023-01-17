//
// Created by dellg15 on 23-1-17.
//
#include <Eigen/Core>
#include <Eigen/Dense>
#include <Eigen/Geometry>
#include <Eigen/Eigenvalues>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

int main(){

    // txt点数据文件路径
    const string fileName = "../points.txt";

    // 读取文件
    ifstream f(fileName);

    // 设置是几次拟合
    const int N = 2;

    // 创建两个vector
    vector<float> x, y;

    if (!f) {
        cout << "数据文件打开失败" << endl;
        exit(EXIT_FAILURE);
    }

    float tempx, tempy;

    while (f >> tempx >> tempy) {
        x.push_back(tempx);
        y.push_back(tempy);
    }

    if (x.size() != y.size()) {
        cout << "数据文件内容有误" << endl;
        exit(EXIT_FAILURE);
    }

    // 创建A矩阵
    Eigen::MatrixXd A(x.size(), N + 1);

    for (unsigned int i = 0; i < x.size(); ++i) {  // 遍历所有点

        for (int n = N, dex = 0; n >= 1; --n, ++dex) {  // 遍历N到1阶
            A(i, dex) = pow(x[i], n);
        }

        A(i, N) = 1;  //
    }

    // 创建B矩阵
    Eigen::MatrixXd B(y.size(), 1);

    for (unsigned int i = 0; i < y.size(); ++i) {
        B(i, 0) = y[i];
    }

    // 创建矩阵W
    Eigen::MatrixXd W;
    W = (A.transpose() * A).inverse() * A.transpose() * B;

    // 打印W结果
    cout << W << endl;
}
