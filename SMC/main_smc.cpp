//#include "smc.h"
//
//int main() {
//  SMCController controller(50, 0.1, 0.01, 0.001);
//  double current_value = 40;
//  double control = controller.computeControl(current_value);
//
//  std::cout << "control: " << control << std::endl;
//  return 0;
//}

/*
 * 滑模控制又称为变结构控制，其控制策略在系统状态接触或穿过滑膜面时会发生变化，具有系统结构随时间变化的开关特性。
 * 滑模控制对于扰动具有良好的鲁棒性。
 * 在滑模面上，系统是降阶的，因为一部分状态变量与其他状态变量受限于滑膜面方程s=0。
 * 因此，一个合理设计的滑模面及相应的控制输入能够很好地使被控系统达到稳定状态。
 * 进一步说，如果我们设计的控制器能够使得s的导数（Filippov意义下）等于零，那么当系统的状态达到滑模面时，系统将沿着滑模面趋近于稳态原点。
 */
#include "smc.h"
#include <fstream>

std::ofstream out_txt_file;

double point = 100.0f;
SMCController controller(point, 0.6, 0.01, 0.001);

int main() {
  double current_value = 40;
  double control;

  out_txt_file.open("../Data/smc_data.txt", std::ios::out | std::ios::trunc);
  out_txt_file << std::fixed;


  for (int i = 0; i < 500; i++) {
    control = controller.computeControl(current_value);
    current_value += control;

    out_txt_file << point << "," << current_value << "," << std::endl;
  }

  out_txt_file.close();

  return 0;
}