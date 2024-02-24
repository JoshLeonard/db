#include "config/configuration.h"
#include <iostream>


Configuration::Configuration() noexcept{
  this->root = std::make_shared<ConfigurationNode>();
}
