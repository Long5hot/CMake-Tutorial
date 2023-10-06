cmake_minimum_required(VERSION 3.15)

project(Tutorial VERSION 1.0)

configure_file(TutorialConfig.h.in TutorialConfig.h)

#set(CMAKE_CXX_STANDARD 14)
#set(CMAKE_CXX_STANDARD_REQUIRED True)

set(gcc_like_cxx "$<COMPILE_LANG_AND_ID:CXX,ARMClang,AppleClang,Clang,GNU,LCC>")
set(msvc_cxx "$<COMPILE_LANG_AND_ID:CXX,MSVC>")

add_subdirectory(MathFunctions)

add_executable(Tutorial DynamicsizeArray.cpp)

add_library(tutorial_compiler_flags INTERFACE)
target_compile_features(tutorial_compiler_flags INTERFACE cxx_std_11)


#target_compile_options(tutorial_compiler_flags INTERFACE
#  "$<${gcc_like_cxx}:-Wall;-Wextra;-Wshadow;-Wformat=2;-Wunused>"
#  "$<${msvc_cxx}:-W3>"
#)

#Lastly, we only want these warning flags to be used during builds. 
#Consumers of our installed project should not inherit our warning flags.
#To specify this, we wrap our flags in a generator expression using the BUILD_INTERFACE condition.
#The resulting full code looks like the following:

target_compile_options(tutorial_compiler_flags INTERFACE
  "$<${gcc_like_cxx}:$<BUILD_INTERFACE:-Wall;-Wextra;-Wshadow;-Wformat=2;-Wunused>>"
  "$<${msvc_cxx}:$<BUILD_INTERFACE:-W3>>"
)

target_link_libraries(Tutorial PUBLIC MathFunctions tutorial_compiler_flags)

target_include_directories(Tutorial PUBLIC
                           "${PROJECT_BINARY_DIR}"
#                           "${PROJECT_SOURCE_DIR}/MathFunctions"
                           )


install(TARGETS Tutorial DESTINATION bin)
install(FILES "${PROJECT_BINARY_DIR}/TutorialConfig.h"
  DESTINATION include
  )


















