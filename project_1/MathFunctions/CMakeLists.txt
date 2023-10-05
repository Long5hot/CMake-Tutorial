

option(USE_MYMATH "Use tutorial provided math implementation" ON)

add_library(MathFunctions MathFunctions.cxx)

add_library(SqrtLibrary STATIC
              mysqrt.cxx
              )


if (USE_MYMATH)
  target_compile_definitions(MathFunctions PRIVATE "USE_MYMATH")
  target_link_libraries(MathFunctions PUBLIC SqrtLibrary)
endif()


