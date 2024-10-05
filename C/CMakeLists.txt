cmake_minimum_required(VERSION 3.25)

project(GradeTwoLearn)

enable_testing()

add_executable(helloworld helloworld.c)

add_executable(complex_number complex_number.c)
add_test(NAME test_complex_number COMMAND ./complex_number)