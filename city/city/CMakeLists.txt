project(city_builder)
cmake_minimum_required(VERSION 3.1.0)

find_package(Qt5 COMPONENTS Widgets REQUIRED)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED on)
set(CMAKE_CXX_EXTENSIONS off)
if(CMAKE_CXX_COMPILER_ID MATCHES "GNU")
    add_compile_options(-Wall -Wpedantic)
endif()

find_package(BISON)
find_package(FLEX)


include_directories(parser expressions villeconst ${CMAKE_CURRENT_BINARY_DIR})
file(GLOB EXPRESSION_HEADERS
    expressions/*.hh
    villeconst/*.hh
     )
 file(GLOB EXPRESSION_SOURCE
     expressions/*.cc
     villeconst/*.cc
     )

add_library(libexpressions
    ${EXPRESSION_HEADERS}
    ${EXPRESSION_SOURCE}
    )
add_library(GUI
	IG/main.cc
	IG/villeGUI.cc
)
target_link_libraries(GUI Qt5::Widgets)

BISON_TARGET(parser parser/parser.yy ${CMAKE_CURRENT_BINARY_DIR}/parser.cpp VERBOSE ${CMAKE_CURRENT_BINARY_DIR}/automate.txt)
FLEX_TARGET(scanner parser/scanner.ll  ${CMAKE_CURRENT_BINARY_DIR}/scanner.cpp)
ADD_FLEX_BISON_DEPENDENCY(scanner parser)
add_executable(${PROJECT_NAME}
    parser/main.cc
    parser/driver.hh
    parser/driver.cc
    parser/scanner.hh
    parser/scanner.ll
    parser/parser.yy
    ${BISON_parser_OUTPUTS}
    ${FLEX_scanner_OUTPUTS}
)
target_link_libraries(${PROJECT_NAME} libexpressions GUI)
