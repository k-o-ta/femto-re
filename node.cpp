//
// Created by koji on 1/9/22.
//

#include <iostream>
#include "node.h"
//#include "femto-re.h"

void Node::paint() {
  for (auto child:child_nodes) {
      child->paint();
  }
}

void Text::paint() {
    std::cout << data << std::endl;
//    BMP bmp;
//    bmp.generate("BBC");
}
