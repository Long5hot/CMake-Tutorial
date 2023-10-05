#include<iostream>
#include<sstream>
#include<algorithm>

#include "TutorialConfig.h"
#include "MathFunctions.h"

struct student {
  std::string name;
  int standard;
};

std::ostream& operator<<(std::ostream& os, const student& s)
{
    return (os << "[Name: " << s.name << ", Standard: " << s.standard <<"]");
}

template <typename T>
class dynamic_array {
  T* data;
  size_t n;

public:
  dynamic_array(int n) {
    this->n = n;
    data = new T[n];
  }

  dynamic_array(const dynamic_array<T> & other){
    n = other.n;
    data = new T[n];

    for(int i = 0; i < n; i++) {
      data[i] = other[i];
    }
  }

  T& operator[](int Index){
    return data[Index];
  }

  const T& operator[](int Index) const {
    return data[Index];
  }

  T at(int Index){
    if(Index < n)
      return data[Index];
    throw "Index Out of range";
  }

  int size() const{
    return n;
  }

  ~dynamic_array(){
    if(data){
      delete[] data;
    }
  }

  T* begin() {
    return data;
  }

  const T* begin() const{
    return data;
  }

  T* end() {
    return data + n;
  }
  
  const T* end() const{
    return data + n;
  }

  std::string to_string(const std::string& sep=",") {
    if(n==0)
      return "";
    std::ostringstream os;
    os << data[0];

    for(int i = 1; i < n; ++i)
      os << sep << data[i];
    return os.str();
  }
};


int main(int argc, char **argv) {

  if (argc < 4) {
    // report version
    std::cout << argv[0] << " Version " << Tutorial_VERSION_MAJOR << "."
              << Tutorial_VERSION_MINOR << std::endl;
    std::cout << "Usage: " << argv[0] << " number" << std::endl;
    return 1;
  }

  const double outputValue = mathfunctions::sqrt(10.0);

  std::cout << outputValue << std::endl;

  int nstudents;
  std::cout << "Enter the number of students : " ;
  std::cin >> nstudents;
  
  dynamic_array<student> class_1(nstudents);
  int standard = 0;
  for(int i = 0; i < nstudents; ++i) {
    std::cout << "Enter the Name and standard " << i + 1 << " ";
    std::cin >> class_1[i].name >> class_1[i].standard ;
  }
  
  for(const student & s : class_1){
    std::cout << s;
    std::cout << std::endl;
  }
}
