#ifndef LPF_H
#define LPF_H

#include <time.h>

class LowPassFilter {
public:
    LowPassFilter() = default;

    explicit LowPassFilter(float _timeConstant)
            : timeConstant(_timeConstant), outputLast(0.0f) {
      timeStamp = clock();
    }


    float operator()(float _input);
    float timeConstant;


protected:
    clock_t timeStamp = 0;
    float outputLast;

};

#endif