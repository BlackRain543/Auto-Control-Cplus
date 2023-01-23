//
// Created by dellg15 on 23-1-17.
//
#include <iostream>
#include <Eigen/Dense>

using Eigen::MatrixXd;
using namespace ::std;

int main()
{
    MatrixXd m(3,3);

    m <<    1,2,3,
            2.5,3.5,3,
            4,5,6;

    std::cout << m << std::endl;
    cout << "Mat1转置矩阵：\n"   << m.transpose()    << endl;
    cout << "Mat1伴随矩阵：\n"   << m.adjoint()      << endl;
    cout << "Mat1逆矩阵：\n"    << m.inverse()      << endl;
    cout << "Mat1行列式：\n"    << m.determinant()  << endl;

    Eigen::SelfAdjointEigenSolver<MatrixXd> eigen(m);

    if (eigen.info() != Eigen::Success) abort();
        cout << "特征值：\n" << eigen.eigenvalues() << endl;
        cout << "特征向量：\n" << eigen.eigenvectors() << endl;

}
