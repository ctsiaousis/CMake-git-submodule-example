cmake_minimum_required(VERSION 3.5)

project(MASproject LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

make_directory(eigen/build_dir)
add_subdirectory(eigen)

set(EIGEN3_INCLUDE_DIR "${CMAKE_CURRENT_LIST_DIR}/eigen/Eigen")
include_directories(${EIGEN3_INCLUDE_DIR})

set(SRCDIR "${CMAKE_CURRENT_SOURCE_DIR}/src/")
set(DATADIR "${CMAKE_CURRENT_SOURCE_DIR}/data/")


# add all the source codes to the SOURCES variable
set(SOURCES
    ${SRCDIR}Definitions.h              ${SRCDIR}CSVParser.h
    ${SRCDIR}Utils/Metrics.h            ${SRCDIR}Utils/LinearAlgebra.h
    ${SRCDIR}ProjectClasses/Entry.h     ${SRCDIR}ProjectClasses/Entry.cpp
    ${SRCDIR}ProjectClasses/UserEntry.h ${SRCDIR}ProjectClasses/UserEntry.cpp
    ${SRCDIR}ProjectClasses/ItemEntry.h ${SRCDIR}ProjectClasses/ItemEntry.cpp
    ${SRCDIR}main.cpp
    )

# add users filename to the USR_FILE_PATH variable
add_definitions(-DUSR_FILE_PATH="${DATADIR}users.csv")

# add users filename to the USR_FILE_PATH variable
add_definitions(-DITM_FILE_PATH="${DATADIR}items.csv")


add_executable(MASproject ${SOURCES})
target_link_libraries (MASproject Eigen3::Eigen)

