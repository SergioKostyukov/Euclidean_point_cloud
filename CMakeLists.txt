cmake_minimum_required(VERSION 3.21)
project(ModuleWorks_test_task)

set(CMAKE_CXX_STANDARD 14)

add_executable(ModuleWorks_test_task main.cpp CreateSkin.cpp CreateSkin.h Point3D.h DiscreteFunction.h PointWriter.h IdxRangeException.cpp IdxRangeException.h Exception.cpp Exception.h PointCloud.h MovingFunction.cpp MovingFunction.h)
