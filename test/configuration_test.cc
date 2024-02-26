#include <gtest/gtest.h>

#include "config/configuration.h"

TEST(ConfigurationTest, CanInsertAndRetrieveOneValue) {
  Configuration configuration{};

  configuration.insert<std::string>("test", "test string");
  auto value = configuration.get<std::string>("test");

  ASSERT_EQ(value, "test string");
}

TEST(ConfigurationTest, CanInsertAndRetrieveTwoDifferentValues) {
  Configuration configuration{};
  
  configuration.insert("test", "test string");
  configuration.insert("batman", "found batman");

  auto test = configuration.get<std::string>("test");
  
  ASSERT_EQ(test, "test string");

  auto batman = configuration.get<std::string>("batman");

  ASSERT_EQ(batman, "batman");
}
