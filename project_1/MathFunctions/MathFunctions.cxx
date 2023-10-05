
#include <cmath>

#ifdef USE_MYMATH
#  include "mysqrt.h"
#endif

namespace mathfunctions {
  

double sqrt(double num) {

#ifdef USE_MYMATH
  return mysqrt(num);
#else
  return std::sqrt(num);
#endif//
  //This is not square root, Jsut doing something..
}

}
