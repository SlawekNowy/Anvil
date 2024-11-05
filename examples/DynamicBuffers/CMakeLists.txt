cmake_minimum_required(VERSION 2.8)
project (DynamicBuffers)


if (NOT ANVIL_LINK_EXAMPLES)
	add_subdirectory   (../.. "${CMAKE_CURRENT_BINARY_DIR}/anvil")
endif()

target_include_directories(Anvil PUBLIC "${CMAKE_CURRENT_BINARY_DIR}/anvil/include")

include_directories(${Anvil_SOURCE_DIR}/include
                   ${DynamicBuffers_SOURCE_DIR}/include)

# Create the DynamicBuffers project.
add_executable (DynamicBuffers include/app.h
                               src/app.cpp)

# Add linking dependencies for the example projects
add_dependencies     (DynamicBuffers Anvil)
target_compile_features(DynamicBuffers PRIVATE cxx_std_20)
if (WIN32)
    target_link_libraries(DynamicBuffers Anvil)
else()
    target_link_libraries(DynamicBuffers Anvil dl)
endif()