cmake_minimum_required(VERSION 3.21)
project(Auto_Control_Cplus)

include_directories(F:\\Eigen\\v3.4.0)
set(CMAKE_CXX_STANDARD 14)

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
        MPC/main_mpc.cpp
        )

add_executable(OLS
        OLS/main_ols.cpp
        OLS/ols.cpp
        OLS/ols.h
        )

add_executable(PLL
        PLL/main_pll.cpp
        )

add_executable(SMC
        SMC/main_smc.cpp
        )

add_executable(LQR
        LQR/main_lqr.cpp
        )

add_executable(ADRC
        ADRC/main_adrc.cpp
        ADRC/LADRC.cpp
        ADRC/LADRC.h)