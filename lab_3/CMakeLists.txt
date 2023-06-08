# CMakeList.txt: проект CMake для lab_3_; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#
cmake_minimum_required (VERSION 3.8)

project ("lab_3_")

# Добавьте источник в исполняемый файл этого проекта.
add_executable(lab_3_ "lab_3_.cpp" "lab_3_.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET lab_3_ PROPERTY CXX_STANDARD 20)
endif()

# TODO: Добавьте тесты и целевые объекты, если это необходимо.
