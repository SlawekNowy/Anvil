cmake_minimum_required(VERSION 2.8)
project (OcclusionQuery)



if (NOT ANVIL_LINK_EXAMPLES)
	add_subdirectory   (../.. "${CMAKE_CURRENT_BINARY_DIR}/anvil")
endif()

target_include_directories(Anvil PUBLIC "${CMAKE_CURRENT_BINARY_DIR}/anvil/include")

include_directories(${Anvil_SOURCE_DIR}/include
                   ${OcclusionQuery_SOURCE_DIR}/include) 
                   
# Create the OcclusionQuery project.
add_executable (OcclusionQuery include/app.h
                               src/app.cpp)

# Add linking dependencies for the example projects
add_dependencies(OcclusionQuery Anvil)

target_compile_features(OcclusionQuery PRIVATE cxx_std_20)

if (WIN32)
    target_link_libraries(OcclusionQuery Anvil)
else()
    target_link_libraries(OcclusionQuery Anvil dl)
endif()