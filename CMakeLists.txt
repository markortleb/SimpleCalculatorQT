cmake_minimum_required(VERSION 3.0.2)
project("SimpleCalculator")

find_package(Qt5Widgets)


set(SCLib_sCWinSrc ${PROJECT_SOURCE_DIR}/src/SimpleCalculator.cpp)
set(SCLib_sCWinHdr ${PROJECT_SOURCE_DIR}/include/SimpleCalculator.h)
set(SCLib_sCUitlHdr ${PROJECT_SOURCE_DIR}/include/utility.h)
set(SCLib_sCUtilSrc ${PROJECT_SOURCE_DIR}/src/utility.cpp)
set(SCBin_mainSrc ${PROJECT_SOURCE_DIR}/src/main.cpp)

qt5_wrap_cpp(SCLib_sCWinHdr_moc ${SCLib_sCWinHdr})
qt5_wrap_cpp(SCLib_sCUtilHdr_moc ${SCLib_sCUtilHdr})

include_directories(${PROJECT_SOURCE_DIR})
include_directories(${PROJECT_BINARY_DIR})
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

add_library(SCLib SHARED
	${SCLib_sCWinSrc}
	${SCLib_sCWinHdr_moc}
	${SCLib_sCUtilSrc}
	${SCLib_sCUtilHdr_moc}
)

target_link_libraries(SCLib Qt5::Widgets)

add_executable("SimpleCalculator" ${SCBin_mainSrc})
target_link_libraries("SimpleCalculator" SCLib)

