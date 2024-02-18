#include "config/configurationNode.h"


ConfigurationNode::ConfigurationNode() noexcept{
  hasValue = false; 
}
  
void ConfigurationNode::insert(char key){
  auto it = children.find(key);
  if(it != children.end()){

  }else{
    // Will move to smart pointers soon, just doing this for speed and testing
    ConfigurationNode newNode{};
    
    children.insert(std::pair<char, ConfigurationNode>(key, newNode));
  }
}
