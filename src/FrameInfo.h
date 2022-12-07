//
// Created by AdiAs on 04.12.2022.
//

#ifndef ZALICZENIE2_FRAMEINFO_H
#define ZALICZENIE2_FRAMEINFO_H


#include "SFML/Graphics.hpp"

class FrameInfo {
public:
    double delta,mouseWheelDelta;
    int zoomViewAdd = 0;
    int zoomViewDel = 0;
    sf::Vector2f setViewFrame();
};


#endif //ZALICZENIE2_FRAMEINFO_H
