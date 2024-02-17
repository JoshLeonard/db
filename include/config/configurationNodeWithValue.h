#include "configurationNode.h"

template<typename ValueType>
class ConfigurationNodeWithValue : ConfigurationNode {
  ValueType value;
};
