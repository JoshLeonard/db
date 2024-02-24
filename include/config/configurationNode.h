#pragma once

#include <map>
#include <string>
#include <memory>

class ConfigurationNode {

protected: 
  std::map<char, std::shared_ptr<ConfigurationNode>> children; 
  bool hasValue;

  friend class Configuration;

public:
  ConfigurationNode() noexcept;
  ConfigurationNode(std::map<char, std::shared_ptr<ConfigurationNode>>&& children);
  void insert(char key);
}; 
