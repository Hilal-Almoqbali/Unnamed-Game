cmake_minimum_required(VERSION 3.26)
add_subdirectory(glad)
add_subdirectory(glfw)
add_subdirectory(tinygltf)
add_subdirectory(imgui)
set(INCLUDE
    ./glfw/include/
    ./glad/include/
    ./
)