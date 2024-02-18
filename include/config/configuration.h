#include <string>

#include "configurationNode.h"

class Configuration {

  std::string configurationName;
  ConfigurationNode root;

public:
  void addKey();
};
