CMAKE_MINIMUM_REQUIRED (VERSION 2.6)
set(CMAKE_C_COMPILER_INIT g++)
set(CMAKE_CXX_COMPILER_INIT g++)
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall -g")
set(CMAKE_BUILD_TYPE Debug)
set(BASE_SOURCE_DIR ${CMAKE_CURRENT_BINARY_DIR}/src)
set(SCANNER_FILES ${BASE_SOURCE_DIR}/scanner)
set(PARSER_FILES ${BASE_SOURCE_DIR}/parser)
PROJECT(compiladorEtapa4)
FIND_PACKAGE(FLEX REQUIRED)
FIND_PACKAGE(BISON REQUIRED)
FLEX_TARGET(scanner ${SCANNER_FILES}/scanner.l ${SCANNER_FILES}/scanner.cpp)
BISON_TARGET(parser ${PARSER_FILES}/parser.y ${PARSER_FILES}/parser.cpp)
INCLUDE_DIRECTORIES(${CMAKE_CURRENT_BINARY_DIR})
INCLUDE_DIRECTORIES(${compiladorEtapa4_SOURCE_DIR})
INCLUDE_DIRECTORIES(${BASE_SOURCE_DIR})
INCLUDE_DIRECTORIES(${SCANNER_FILES})
INCLUDE_DIRECTORIES(${PARSER_FILES})
ADD_EXECUTABLE(main
${BASE_SOURCE_DIR}/main.cpp
${FLEX_scanner_OUTPUTS}
${BISON_parser_OUTPUTS}
${BASE_SOURCE_DIR}/symbol.cpp
${BASE_SOURCE_DIR}/tree/node.cpp
${BASE_SOURCE_DIR}/tree/programnode.cpp
${BASE_SOURCE_DIR}/tree/vardeclarationnode.cpp
${BASE_SOURCE_DIR}/tree/vectordeclarationnode.cpp
${BASE_SOURCE_DIR}/tree/headernode.cpp
${BASE_SOURCE_DIR}/tree/functiondefinitionnode.cpp
${BASE_SOURCE_DIR}/tree/assignmentnode.cpp
${BASE_SOURCE_DIR}/tree/inputnode.cpp
${BASE_SOURCE_DIR}/tree/outputnode.cpp
${BASE_SOURCE_DIR}/tree/returnnode.cpp
${BASE_SOURCE_DIR}/tree/functioncallnode.cpp
${BASE_SOURCE_DIR}/tree/ifnode.cpp
${BASE_SOURCE_DIR}/tree/whilenode.cpp
${BASE_SOURCE_DIR}/tree/blocknode.cpp
${BASE_SOURCE_DIR}/tree/expressionnode.cpp
${BASE_SOURCE_DIR}/tree/identifiernode.cpp
${BASE_SOURCE_DIR}/tree/literalnode.cpp
${BASE_SOURCE_DIR}/tree/operationnode.cpp)
TARGET_LINK_LIBRARIES(main ${FLEX_LIBRARIES})
