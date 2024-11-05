cmake_minimum_required(VERSION 2.8)
project (PushConstants)


if (NOT ANVIL_LINK_EXAMPLES)
	add_subdirectory   (../.. "${CMAKE_CURRENT_BINARY_DIR}/anvil")
endif()

target_include_directories(Anvil PUBLIC "${CMAKE_CURRENT_BINARY_DIR}/anvil/include")

include_directories(${Anvil_SOURCE_DIR}/include
                    ${PushConstants_SOURCE_DIR}/include)

# Include the Vulkan header.
if (WIN32)
    include_directories($ENV{VK_SDK_PATH}/Include
                        $ENV{VULKAN_SDK}/Include)
    
    if("${CMAKE_SIZEOF_VOID_P}" EQUAL "8")
            link_directories   ($ENV{VK_SDK_PATH}/Bin
                                $ENV{VK_SDK_PATH}/Lib
                                $ENV{VULKAN_SDK}/Bin
                                $ENV{VULKAN_SDK}/Lib)
    else()
            link_directories   ($ENV{VK_SDK_PATH}/Bin32
                                $ENV{VK_SDK_PATH}/Lib32
                                $ENV{VULKAN_SDK}/Bin32
                                $ENV{VULKAN_SDK}/Lib32)
    endif()
else()
    include_directories($ENV{VK_SDK_PATH}/x86_64/include
                        $ENV{VULKAN_SDK}/include
                        $ENV{VULKAN_SDK}/x86_64/include)
    link_directories   ($ENV{VK_SDK_PATH}/x86_64/lib
                        $ENV{VULKAN_SDK}/lib
                        $ENV{VULKAN_SDK}/x86_64/lib)
endif()

# Create the PushConstants project.
add_executable (PushConstants include/app.h
                              src/app.cpp)

# Add linking dependencies for the example projects
add_dependencies(PushConstants Anvil)

target_compile_features(PushConstants PRIVATE cxx_std_20)
if (WIN32)
    target_link_libraries(PushConstants Anvil)
else()
    target_link_libraries(PushConstants Anvil dl)
endif()