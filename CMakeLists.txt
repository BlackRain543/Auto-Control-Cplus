cmake_minimum_required(VERSION 3.23)
project(Auto_Control_Cplus)

set(CMAKE_CXX_STANDARD 14)

include_directories(LPF)
include_directories(PID)

add_executable(LPF
        LPF/lowpass_filter.cpp
        LPF/lowpass_filter.h
        LPF/main_lpf.cpp
        )

add_executable(PID
        PID/pid.cpp
        PID/pid.h
        PID/main_pid.cpp
        )

add_executable(KF
        KF/main_kf.cpp
            KF/kf.cpp
            KF/kf.h
        )

add_executable(MPC
        MPC/mpc_demo.cpp
        )

add_executable(OLS
#        OLS/eigen_demo.cpp
        OLS/main_ols.cpp
        OLS/ols.cpp
        OLS/ols.h
        )