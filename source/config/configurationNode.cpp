#include "config/configurationNode.h"
#include <memory>

ConfigurationNode::ConfigurationNode() noexcept{
  hasValue = false; 
}

ConfigurationNode::ConfigurationNode(std::map<char, std::shared_ptr<ConfigurationNode>>&& children) : children(children) {
  hasValue = false;
}
  
