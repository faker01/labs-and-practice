﻿# CMakeList.txt: проект CMake для lab_4; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#
cmake_minimum_required (VERSION 3.8)

project ("lab_4")

# Добавьте источник в исполняемый файл этого проекта.
add_executable (lab_4 "lab_4.cpp" "lab_4.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET lab_4 PROPERTY CXX_STANDARD 20)
endif()

# TODO: Добавьте тесты и целевые объекты, если это необходимо.
