#include "lpf.h"


float LowPassFilter::operator()(float _input) {
  auto time = clock();
  float dt = (float) ((time - timeStamp) * 1e-3);

  if (dt < 0.0f) dt = 1e-3f;
  else if (dt > 0.3f) {
    outputLast = _input;
    timeStamp = time;
    return _input;
  }
  float alpha = timeConstant;
//  float alpha   = timeConstant / (timeConstant + dt);
  float output = alpha * outputLast + (1.0f - alpha) * _input;
  outputLast = output;
  timeStamp = time;

  return output;
}
