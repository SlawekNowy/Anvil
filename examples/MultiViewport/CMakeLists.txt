cmake_minimum_required(VERSION 2.8)
project (MultiViewport)


if (NOT ANVIL_LINK_EXAMPLES)
	add_subdirectory   (../.. "${CMAKE_CURRENT_BINARY_DIR}/anvil")	
endif()

target_include_directories(Anvil PUBLIC "${CMAKE_CURRENT_BINARY_DIR}/anvil/include")

include_directories(${Anvil_SOURCE_DIR}/include
                    ${MultiViewport_SOURCE_DIR}/include)

# Create the MultiViewport project.
add_executable (MultiViewport include/app.h
                              src/app.cpp)

# Add linking dependencies for the example projects
add_dependencies(MultiViewport Anvil)

target_compile_features(MultiViewport PRIVATE cxx_std_20)
if (WIN32)
    target_link_libraries(MultiViewport Anvil)
else()
    target_link_libraries(MultiViewport Anvil dl)
endif()