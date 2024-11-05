cmake_minimum_required(VERSION 2.8)
project (OutOfOrderRasterization)



if (NOT ANVIL_LINK_EXAMPLES)
	add_subdirectory   (../.. "${CMAKE_CURRENT_BINARY_DIR}/anvil")
endif()

target_include_directories(Anvil PUBLIC "${CMAKE_CURRENT_BINARY_DIR}/anvil/include")

include_directories(${Anvil_SOURCE_DIR}/include
                    ${OutOfOrderRasterization_SOURCE_DIR}/include)

# Create the OutOfOrderRasterization project.
add_executable (OutOfOrderRasterization include/app.h
                                        include/teapot_data.h
                                        src/app.cpp
                                        src/teapot_data.cpp)

# Add linking dependencies for the example projects
add_dependencies(OutOfOrderRasterization Anvil)

target_compile_features(OutOfOrderRasterization PRIVATE cxx_std_20)

if (WIN32)
    target_link_libraries(OutOfOrderRasterization Anvil)
else()
    target_link_libraries(OutOfOrderRasterization Anvil dl)
endif()