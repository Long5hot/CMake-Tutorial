

option(USE_MYMATH "Use tutorial provided math implementation" ON)

add_library(MathFunctions MathFunctions.cxx)

add_library(SqrtLibrary STATIC
              mysqrt.cxx
              )


if (USE_MYMATH)
  target_compile_definitions(MathFunctions PRIVATE "USE_MYMATH")
  target_link_libraries(SqrtLibrary PUBLIC tutorial_compiler_flags)
  target_link_libraries(MathFunctions PUBLIC SqrtLibrary)
endif()

target_include_directories(MathFunctions
                           INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
                           )


