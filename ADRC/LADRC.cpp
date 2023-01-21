//
// Created by a8930 on 2023/1/21.
//

#include "LADRC.h"
#include<iostream>
#include<vector>

using namespace std;
/*
程序功能：
1、LADRC控制器的实现
2、RungeKutta计算微分方程组，封装为RungeKutta头文件和类
3、LESO和System微分方程组作为子函数
4、Controller作为子函数

*/

//构造函数初始化

LADRC::LADRC(float Wo, float Wc, float b, float y, float h, float ref)
        : _b(b), _ref(ref), _z(ODE_NUM + 1, 0), _x(ODE_NUM + 1, 1), _Wc(Wc), _Wo(Wo), _t1(0), _h(h), _u(0), _y(y) {
  int i;
  //生成LESO系数
  for (i = 0; i < ODE_NUM + 1; i++) {
    beta_Wo[i] = powj(_Wo, i + 1) * comb(ODE_NUM + 1, i + 1);

  }
  //生成LESO系数
  for (i = 0; i < ODE_NUM + 1; i++) {
    beta_Wo[i] = powj(_Wc, i + 1) * comb(ODE_NUM + 1, i + 1);
  }
  //控制律系数
  for (i = 0; i < ODE_NUM; i++) {
    beta_Wc[i] = powj(_Wc, ODE_NUM - i) * comb(ODE_NUM, ODE_NUM - i);
  }
  for (i = 0; i < ODE_NUM; i++)
    cout << "beta_Wc[" << i << "]=" << beta_Wc[i] << endl;
  for (i = 0; i < ODE_NUM + 1; i++)
    cout << "beta_Wo[" << i << "]=" << beta_Wo[i] << endl;
  Controller();// 构造函数调用控制器计算

}

//控制量输出
float LADRC::Output() {
  return _u;
}

//控制器计算函数
//vector<float> fx(float t, float x[]);
void LADRC::Controller() {
  int i;
  calc();
  _u = _z[ODE_NUM] + beta_Wc[0] * (_z[0] - _ref);;//取z3
  for (i = 1; i < ODE_NUM; i++) {
    _u = _u + beta_Wc[i] * _z[i];
  }
  _u = -_u / _b;


}

float LADRC::powj(float Wo, int n) {
  int i;
  float z = 1;
  if (n == 0)
    return 1;
  else {
    for (i = n; i >= 1; i--) {
      z = z * Wo;
    }
  }
  return z;

}

//组合数计算公式
float LADRC::comb(int n, int m) {
  if (n < 0 || n < 0)
    return 0;
  else
    return jiecheng(n) / jiecheng(m) / jiecheng(n - m);

}

//计算阶乘子函数
float LADRC::jiecheng(int n) {
  if (n < 0)
    return 0;
  else if (n == 0 || n == 1)
    return 1.0;
  else
    return n * jiecheng(n - 1);
}

//LESO微分方程组定义
vector<float> LADRC::LESO(float t, vector<float> x)
//void LADRC::LESO()
{
  int i;
  float e;
  vector<float> dx(ODE_NUM + 1, 0);//
  e = _y - _x[0];
  for (i = 0; i < ODE_NUM - 1; i++) {
    dx[i] = beta_Wo[i] * e + x[i + 1];
  }
  dx[ODE_NUM - 1] = beta_Wo[ODE_NUM - 1] * e + _b * _u;
  dx[ODE_NUM] = beta_Wo[ODE_NUM] * e;
  return dx;

}

//迭代计算函数
void LADRC::calc() {
  int j;
  //vector<float> s(ODE_NUM+1,0);
  Lx();
  vector<float> _s(ODE_NUM + 1, 0);
  for (j = 0; j < ODE_NUM + 1; j++)
    _x[j] = _x[j] + _s[j];//更新当前ODE计算的值
  _t = _t + _h;// 更新时间节点
  _z = _x;//返回当前节点解算的LESO

}

//RungeKutta计算所需项
//vector<float>  LADRC::Lx(float _t, vector<float> _x)
void LADRC::Lx() {
  int j;
  vector<float> x1(ODE_NUM + 1, 0), x2(ODE_NUM + 1, 0), x3(ODE_NUM + 1, 0);
  vector<float> y1(ODE_NUM + 1, 0), y2(ODE_NUM + 1, 0), y3(ODE_NUM + 1, 0), y4(ODE_NUM + 1, 0);// 使用vector数据类型，子函数可返回数组
  //N = ODE_NUM + 1;
  vector<float> _s(ODE_NUM + 1, 0);//
  y1 = LESO(_t, _x);


  for (j = 0; j < ODE_NUM + 1; j++)
    x1[j] = _x[j] + _h / 2 * y1[j];
  y2 = LESO(_t + _h / 2, x1);
  for (j = 0; j < ODE_NUM + 1; j++)
    x2[j] = _x[j] + _h / 2 * y2[j];
  y3 = LESO(_t + _h / 2, x2);
  for (j = 0; j < ODE_NUM + 1; j++)
    x3[j] = _x[j] + _h * y3[j];
  y4 = LESO(_t + _h, x3);
  for (j = 0; j < ODE_NUM + 1; j++)
    _s[j] = _s[j] + y1[j];
  for (j = 0; j < ODE_NUM + 1; j++)
    _s[j] = _s[j] + 2 * y2[j];
  for (j = 0; j < ODE_NUM + 1; j++)
    _s[j] = _s[j] + 2 * y3[j];
  for (j = 0; j < ODE_NUM + 1; j++)
    _s[j] = _s[j] + y4[j];
  for (j = 0; j < ODE_NUM + 1; j++)
    _s[j] = _s[j] * _h / 6;

}