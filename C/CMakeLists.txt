cmake_minimum_required(VERSION 3.25)

project(GradeTwoLearn)

enable_testing()

add_executable(helloworld helloworld.c)

add_executable(complex_number complex_number.c)
add_test(NAME test_complex_number COMMAND ./complex_number)

add_executable(stack stack.c)
add_test(NAME test_stack COMMAND ./stack)

add_executable(queue queue.c)
add_test(NAME test_queue COMMAND ./queue)

add_executable(stack_list stack_list.c)
add_test(NAME test_stack_list COMMAND ./stack_list)

add_executable(queue_list queue_list.c)
add_test(NAME test_queue_list COMMAND ./queue_list)