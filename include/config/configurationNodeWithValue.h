#pragma once

#include <string>
#include <utility>

#include "configurationNode.h"

template<typename ValueType>
class ConfigurationNodeWithValue : public ConfigurationNode {
  ValueType value;

public:
  
  ConfigurationNodeWithValue(ValueType value) noexcept{
    hasValue = true;
    this->value = value;
  }

  ConfigurationNodeWithValue(std::map<char, std::shared_ptr<ConfigurationNode>> &&children, ValueType value) : ConfigurationNode(std::move(children)), value{value} {
    
  }

  ValueType Get(std::string key);
  
  void insert(char key, ValueType value){
    auto it = children.find(key);
    if (it != children.end()){
      
    }else{

      auto newConfigurationNode = std::make_shared<ConfigurationNodeWithValue<ValueType>>(value);
      children.insert(std::pair<char, std::shared_ptr<ConfigurationNode>>(key, newConfigurationNode));
    }
  }
};
