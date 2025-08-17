cmake_minimum_required(VERSION 3.20)

set(PRODUCT_NAME_EN "RXI system software")
set(PRODUCT_NAME_RU "Системное программное обеспечение RXI")
set(PRODUCT_VERSION_MAJOR 0)
set(PRODUCT_VERSION_MINOR 0)
set(PRODUCT_VERSION_PATCH 1)

project(AtfGui VERSION ${PRODUCT_VERSION_MAJOR}.${PRODUCT_VERSION_MINOR}.${PRODUCT_VERSION_PATCH})

add_subdirectory(Application/Core)
