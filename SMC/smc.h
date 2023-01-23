//
// Created by a8930 on 2023/1/22.
//

#ifndef AUTO_CONTROL_CPLUS_SMC_H
#define AUTO_CONTROL_CPLUS_SMC_H


#include <iostream>

class SMCController {
public:
    SMCController(double setpoint, double kp, double ki, double kd)
            : setpoint_(setpoint), kp_(kp), ki_(ki), kd_(kd), error_sum_(0), last_error_(0) {}

    double computeControl(double current_value) {
      double error = setpoint_ - current_value;
      error_sum_ += error;
      double d_error = error - last_error_;
      last_error_ = error;
      double control = kp_ * error + ki_ * error_sum_ + kd_ * d_error;

      return control;
    }

private:
    double setpoint_;     //设定值
    double kp_;           //比例系数
    double ki_;           //积分系数
    double kd_;           //微分系数
    double error_sum_;    //误差累加器
    double last_error_;   //上一次误差
};


#endif //AUTO_CONTROL_CPLUS_SMC_H
