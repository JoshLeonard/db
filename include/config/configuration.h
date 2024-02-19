#include <cstddef>
#include <memory>
#include <string>
#include <iostream>

#include "configurationNode.h"
#include "configurationNodeWithValue.h"

class Configuration {

public:

  template <typename ValueType>
  void insert(std::string key, ValueType value){
    if (root == NULL) {
      
    }
    
    for (char character : key) {
  
    } 
  }

  template<typename ValueType>
  ValueType get(std::string key);

private:
  
  std::string configurationName;
  std::shared_ptr<ConfigurationNode> root;

  template <typename ValueType>
  void insert(std::string key, size_t index, ValueType value) {

  }
};
