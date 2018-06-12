cmake_minimum_required(VERSION 3.9)

include("cmake/HunterGate.cmake")
HunterGate(
    URL "https://github.com/ruslo/hunter/archive/v0.22.12.tar.gz"
    SHA1 "34d985ce72c67441644664a2e3f7ab0822613768"
    LOCAL # cmake/Hunter/config.cmake
)

project(dlib_openblas VERSION 1.0.0)  

hunter_add_package(dlib)
find_package(dlib CONFIG REQUIRED)

hunter_add_package(gauze)
find_package(gauze CONFIG REQUIRED)

add_executable(dlib_openblas_hang main.cpp)
target_link_libraries(dlib_openblas_hang PUBLIC dlib::dlib)

enable_testing()

gauze_add_test(
  NAME DlibOpenBlasHang
  COMMAND dlib_openblas_hang
)
