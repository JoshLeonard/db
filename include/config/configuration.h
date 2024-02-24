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
        } else {
          node = it->second;
        } 
      }
    }
  }

  template<typename ValueType>
  ValueType get(std::string key);

private:
  
  std::string configurationName;
  std::shared_ptr<ConfigurationNode> root;

  template <typename ValueType>
  void insert(std::string key, size_t key_index, ValueType value) {
    if (key.length() == key_index) {
      // doesnt exist and need to add
    }
    bool isDestination = key_index == key.length() - 1 ? true : false; 
    
    auto it = root->children.find(key[key_index]);
    if (it != root->children.end()) {

    }else{
      if (isDestination) {
        auto newNode = std::make_shared<ConfigurationNodeWithValue<ValueType>>(value);
        root->children.insert(std::pair(key[key_index], newNode));
      }else {

      }
    }

  }
};
