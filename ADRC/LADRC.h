#include<iostream>
#include<iomanip>
#include<vector>

#define ODE_NUM 2

using namespace std;

/*
程序功能：
1、LADRC类的功能
2、提供的接口包含：
   参考输入信号ref、系统输出返回值y、控制量输出u


By Chenglin Li
_2020.11.30_

*/
class LADRC
//class LADRC
{
private:
    float _h;// 步长
    float _t1; //初始和末尾时刻
    //LESO和控制器参数
    float _ref;
    float _y;
    float _u;
    float _Wo;//LESO带宽
    float _Wc;//控制带宽
    float _b;//控制输入系数
    float beta_Wo[ODE_NUM + 1];//LESO系数
    float beta_Wc[ODE_NUM];//控制器系数
    vector<float> _z; //表示LESO返回值
    vector<float> _x;////表示RK计算的当前节点值
    float _t;

    vector<float> _s();
    //vector<float> _dx;
    //vector<float> _y1;
    //vector<float> _y2;
    //vector<float> _y3;
    //vector<float> _y4;

public:
    //构造函数
    //LADRC(float, float , float , float , float,float );
    LADRC(float Wo, float Wc, float b, float y, float h, float ref);

    void Controller();

    float Output();

    vector<float> LESO(float, vector<float>);

    //void LESO();
    //LADRC计算中使用到的相关函数
    float jiecheng(int n);

    float comb(int n, int m);

    float powj(float Wo, int n);

    void calc();

    //vector<float>Lx(float , vector<float>  );
    void Lx();
};