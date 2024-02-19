#include <string>
#include <utility>

#include "configurationNode.h"

template<typename ValueType>
class ConfigurationNodeWithValue : ConfigurationNode {
  ValueType value;

public:
  
  ConfigurationNodeWithValue() noexcept{
    hasValue = true;
  }

  ValueType Get(std::string key);
  
  void insert(char key, ValueType value){
    auto it = children.find(key);
    if (it != children.end()){
      
    }else{
      ConfigurationNodeWithValue<ValueType> newConfigurationNode{};
      newConfigurationNode.value = value;
      children.insert(std::pair<char, ConfigurationNode>(key, newConfigurationNode));
    }
  }
};
