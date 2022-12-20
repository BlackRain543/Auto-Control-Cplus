cmake_minimum_required(VERSION 3.24)
project(Auto_Control_Cplus)

set(CMAKE_CXX_STANDARD 14)

include_directories(LPF)
include_directories(PID)

add_executable(LPF
        LPF/lowpass_filter.cpp
        LPF/lowpass_filter.h
        )

add_executable(PID
        PID/pid.cpp
        PID/pid.h
        )

add_executable(KF
        KF/demo.cpp
        KF/kf.cpp
        KF/kf.h
        )