cmake_minimum_required(VERSION 3.0.0)
project(kcp_test VERSION 0.1.0)

add_compile_options(-std=c++17)

include(CTest)
enable_testing()

add_executable(kcptest main.cpp)
add_library(kcpwrapper kcp_api_wrapper.cpp kcp.cpp)
include_directories(C:/Python27/include)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

set(PYTHON_27 C:/Python27/libs/python27.lib)

find_package(kcp CONFIG REQUIRED)

target_link_libraries(kcpwrapper PRIVATE kcp::kcp ${PYTHON_27})
target_link_libraries(kcptest ${PYTHON_27})
