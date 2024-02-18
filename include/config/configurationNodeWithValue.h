#include <string>

#include "configurationNode.h"

template<typename ValueType>
class ConfigurationNodeWithValue : ConfigurationNode {
  ValueType value;

  public:
  
  ValueType Get(std::string key);
};
