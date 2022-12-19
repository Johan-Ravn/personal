cmake_minimum_required(VERSION 3.1)
project(MiniProjects C)
set(CMAKE_C_STANDARD 11)

add_subdirectory(Projects/fizzbuzz)

add_subdirectory(Projects/hash_table)

add_subdirectory(Projects/Prime/prime_number)
add_subdirectory(Projects/Prime/prime_number_optimized)

add_subdirectory(Projects/sortingAlgorithms)

add_subdirectory(Projects/stickGame/MiniMax)
add_subdirectory(Projects/stickGame)

add_subdirectory(Projects/ticTacToe/MiniMax)
add_subdirectory(Projects/ticTacToe)

add_subdirectory(Projects/tree/binary_search)
add_subdirectory(Projects/tree/create_binary_tree)
