#include "config/configurationNode.h"
#include <memory>


ConfigurationNode::ConfigurationNode() noexcept{
  hasValue = false; 
}

ConfigurationNode::ConfigurationNode(std::map<char, std::shared_ptr<ConfigurationNode>>&& children) : children(children) {

}
  
void ConfigurationNode::insert(char key){
  auto it = children.find(key);
  if(it != children.end()){

  }else{
    // Will move to smart pointers soon, just doing this for speed and testing
    auto newNode = std::make_unique<ConfigurationNode>();
    children.insert(std::pair<char, std::shared_ptr<ConfigurationNode>>(key, std::move(newNode)));
  }
}
