#include <iostream>

#include "config/configuration.h"

int main(){
  std::cout << "hello world" << std::endl;
  Configuration configuration{};
  std::cout << "configuration created" << std::endl;
  return 0;
}
