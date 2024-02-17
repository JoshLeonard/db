#include <map>
#include <string>

class ConfigurationNode {
  std::map<std::string, ConfigurationNode> children; 
  bool hasValue;
}; 
