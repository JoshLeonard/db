#pramga once

#include "configurationNode.h"
#include "configurationNodeWithValue.h"

class configurationNodeFactory {

public:

  std::shared_ptr<ConfigurationNode> createNode() {
    return std::make_shared<ConfigurationNode>();
  }

  std::shared_ptr<ConfigurationNode> createNode(std::map<char, std::shared_ptr<ConfigurationNode>> children) {
    return std::make_shared<ConfigurationNode>(children);
  }

  template <typename ValueType>
  std::shared_ptr<ConfigurationNode> createNode(ValueType value) {
    return std::make_shared<ConfigurationNodeWithValue<ValueType>>(value);
  }

  template <typename ValueType>
  std::shared_ptr<ConfigurationNode> createNode(std::map<char, std::shared_ptr<ConfigurationNode>> children, ValueType value) {
    return std::make_shared<ConfigurationNodeWithValue<ValueType>>(value);
  }
};
