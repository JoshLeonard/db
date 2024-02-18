#include <gtest/gtest.h>

#include "config/configuration.h"

TEST(configurationTest, CanInstantiate){
  Configuration configuration{};

  configuration.insert("test", 1);
  
}
