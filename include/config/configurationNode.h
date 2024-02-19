#pragma once

#include <map>
#include <string>
#include <memory>

class ConfigurationNode {

protected: 
  std::map<char, std::shared_ptr<ConfigurationNode>> children; 
  bool hasValue;

public:
  ConfigurationNode() noexcept;
  void insert(char key);
}; 
