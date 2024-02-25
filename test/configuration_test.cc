#include <gtest/gtest.h>

#include "config/configuration.h"

TEST(ConfigurationTest, CanInsert){
  Configuration configuration{};

  configuration.insert<std::string>("test", "test string");
  auto value = configuration.get<std::string>("test");

  ASSERT_EQ(value, "test string");
}

