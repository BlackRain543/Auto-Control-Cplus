#ifndef LPF_H
#define LPF_H

class LowPassFilter
{
public:
    LowPassFilter() = default;

    explicit LowPassFilter(float _timeConstant)
        : timeConstant(_timeConstant), outputLast(0.0f)
    {
        timeStamp = micros();
    }


    float operator()(float _input);
    float timeConstant;


protected:
    unsigned long timeStamp;
    float outputLast;
};

#endif