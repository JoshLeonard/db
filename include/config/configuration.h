#include <string>
#include <iostream>

#include "configurationNode.h"
#include "configurationNodeWithValue.h"

class Configuration {

public:

  template <typename ValueType>
  void insert(std::string key, ValueType value){
    if (root == null) {
      
    }
    
    for (char character : key) {
      
    } 
  }

  template<typename ValueType>
  ValueType get(std::string key);

private:
  
  std::string configurationName;
  ConfigurationNode root;
};
