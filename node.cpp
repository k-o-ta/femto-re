//
// Created by koji on 1/9/22.
//

#include <iostream>
#include "node.h"
//#include "femto-re.h"

void Node::paint() {
  for (auto child:child_nodes) {
      switch(child->kind) {
          case ND_TEXT:
              std::dynamic_pointer_cast<Text>(child)->paint();
              break;
          default:
              child->paint();
              break;
      }
  }
}

void Text::paint() {
    std::cout << data << std::endl;
//    BMP bmp;
//    bmp.generate("BBC");
}

void CharacterData::paint() {
    std::cout << data << std::endl;
//    BMP bmp;
//    bmp.generate("BBC");
}

//void Hoo::print() {
//    std::cout << "print Hoo" << std::endl;
//}
