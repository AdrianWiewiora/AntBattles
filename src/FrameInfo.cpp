//
// Created by AdiAs on 04.12.2022.
//

#include "FrameInfo.h"

sf::Vector2f FrameInfo::setViewFrame() {
    sf::Vector2f sizeView;
    if(zoomViewDel == -8){
        sizeView.x = 3840;
        sizeView.y = 2160;
        return sizeView;
    }
    if(zoomViewAdd == 8){
        sizeView.x = 960;
        sizeView.y = 540;
        return sizeView;
    }
    return sizeView;
}
