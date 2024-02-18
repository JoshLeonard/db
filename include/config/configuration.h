#include <string>
#include <iostream>

#include "configurationNode.h"

class Configuration {

  std::string configurationName;
  ConfigurationNode root;

public:

  template <typename ValueType>
  void insert(std::string key, ValueType value){
    std::cout << "calling add key" << std::endl;  
  }

  template<typename ValueType>
  ValueType get(std::string key);
};
