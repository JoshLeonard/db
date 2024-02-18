#include <map>
#include <string>

class ConfigurationNode {

protected: 
  std::map<char, ConfigurationNode> children; 
  bool hasValue;

public:
  ConfigurationNode() noexcept;
  void insert(char key);
}; 
