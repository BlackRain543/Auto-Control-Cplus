cmake_minimum_required(VERSION 3.21)
project(Auto_Control_Cplus)
set(CMAKE_CXX_STANDARD 11)


include_directories(F:\\Eigen\\v3.4.0)
include_directories(F:\\matplotlib-cpp-master)

#find_package(PythonLibs 3.9)
#target_include_directories(Auto_Control_Cplus PRIVATE ${PYTHON_INCLUDE_DIRS})
#target_link_libraries(Auto_Control_Cplus ${PYTHON_LIBRARIES})

#include_directories(E:/Anaconda3/envs/basic/include)
#include_directories(E:/Anaconda3/envs/basic/Lib/site-packages/numpy/core/include)
#link_libraries(E:/Anaconda3/envs/basic/libs/python39.lib)

#include_directories(E:/Python3.9.11/include)
#include_directories(E:/Python3.9.11/Lib/site-packages/numpy/core/include)
#link_libraries(E:/Python3.9.11/libs/python39.lib)

include_directories(E:/Anaconda3/envs/python39/include)
include_directories(E:/Anaconda3/envs/python39/Lib/site-packages/numpy/core/include)
#link_libraries(E:/Anaconda3/envs/python39/libs/python39.lib)
#link_libraries(E:/Anaconda3/envs/python39/python39.dll)
#link_libraries(E:/Anaconda3/envs/python39/libs)


#add_executable(Auto_Control_Cplus eigen_demo.cpp)

add_executable(LPF
        LPF/lpf.cpp
        LPF/lpf.h
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
        SMC/smc.cpp SMC/smc.h)

add_executable(LQR
        LQR/main_lqr.cpp
        )

add_executable(ADRC
        ADRC/main_adrc.cpp
        ADRC/LADRC.cpp
        ADRC/LADRC.h)

add_executable(Time
        time_demo.cpp)









