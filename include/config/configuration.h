#include <cstddef>
#include <memory>
#include <string>
#include <iostream>

#include "configurationNode.h"
#include "configurationNodeWithValue.h"

class Configuration {

public:
  
  Configuration() noexcept;

  template <typename ValueType>
  void insert(std::string key, ValueType value){
    auto node = root;
    
    for (int index = 0; index < key.length(); index++){
      auto it = node->children.find(key[index]);
      bool isValueNode = index == key.length() - 1 ? true : false;
      if (it == node->children.end()){
        std::shared_ptr<ConfigurationNode> newNode;
        if (isValueNode) {
          newNode = std::make_shared<ConfigurationNodeWithValue<ValueType>>(value);
        } else {
          newNode = std::make_shared<ConfigurationNode>(); 
        } 
        node->children.insert(std::pair(key[index], newNode));
        node = newNode;
      } else {
        if (isValueNode) {
          auto newNode = std::make_shared<ConfigurationNodeWithValue<ValueType>>(std::move(node->children), value);
          node->children[key[index]] = newNode;
        }
        node = it->second;
      }
    }
  }

  template<typename ValueType>
  ValueType get(std::string key) {    
    auto node = root;
    for (size_t index = 0; index < key.length(); index++) {
      bool isValueNode = index == key.length() - 1 ? true : false;
      auto it = node->children.find(key[index]);
      if (it == node->children.end()) {
        return ValueType();
      } 
      else {
        if (isValueNode) {
          if (it->second->hasValue) {
            auto configurationNodeWithValue = std::dynamic_pointer_cast<ConfigurationNodeWithValue<ValueType>>(it->second);
            if (configurationNodeWithValue == nullptr) {
              return ValueType();
            }
            return configurationNodeWithValue->get();
          }else {
            return ValueType();
          }
        }
        else {
          node = it->second;
        }
      }
    }
    return ValueType();
  }

private:
  
  std::string configurationName;
  std::shared_ptr<ConfigurationNode> root;
};
