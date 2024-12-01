cmake_minimum_required(VERSION 3.10)
project(MyExcel VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_COMPILER clang++)

# Wall - 일반적인 경고 활성화, #Wextra - 추가적인 경고 활성화
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")
set(CMAKE_CXX_FLAGS_DEBUG "-g -O0") # g: 디버깅 정보 포함, O0: Optimization level 0
set(CMAKE_CXX_FLAGS_RELEASE "-O3") # O3: Optimization level 3

file(GLOB_RECURSE PROJECT_FILES
    "src/*.cpp"
    "src/*.h"
    "src/*.hpp"
)

add_executable(${PROJECT_NAME} ${PROJECT_FILES})

# src 디렉토리를 include 경로에 추가
target_include_directories(${PROJECT_NAME}
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
)

