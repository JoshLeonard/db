#pragma once

#include <map>
#include <string>
#include <memory>

class ConfigurationNode {

protected: 
  bool hasValue;

  friend class Configuration;

public:
  ConfigurationNode() noexcept;
  ConfigurationNode(std::map<char, std::shared_ptr<ConfigurationNode>>&& children);
  virtual ~ConfigurationNode() {}
  void insert(char key);
  std::map<char, std::shared_ptr<ConfigurationNode>> children; 
  
}; 
