cmake_minimum_required(VERSION 3.20)

set(CMAKE_PREFIX_PATH "C:/Qt/6.4.1/mingw_64")

set(PRODUCT_NAME_EN "AT Framework system software")
set(PRODUCT_NAME_RU "Системное программное обеспечение AT Framework")
set(PRODUCT_VERSION_MAJOR 0)
set(PRODUCT_VERSION_MINOR 0)
set(PRODUCT_VERSION_PATCH 1)

project(AtfGui VERSION ${PRODUCT_VERSION_MAJOR}.${PRODUCT_VERSION_MINOR}.${PRODUCT_VERSION_PATCH})

add_subdirectory(Application/Core)
