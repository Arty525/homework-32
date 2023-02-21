# CMakeList.txt: проект CMake для EX1; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#
cmake_minimum_required (VERSION 3.8)

project ("EX2")

set(CMAKE_CXX_STANDARD 14)

set(JSON_BuildTests OFF CACHE INTERNAL "")

add_subdirectory(nlohmann_json)
# Добавьте источник в исполняемый файл этого проекта.
add_executable (EX2 "EX2.cpp" )

target_link_libraries(EX2 PRIVATE nlohmann_json::nlohmann_json)

# TODO: Добавьте тесты и целевые объекты, если это необходимо.
