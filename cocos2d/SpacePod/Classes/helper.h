#ifndef __HELPER_H
#define __HELPER_H

#include "cocos2d.h"

template<class layer_t>
cocos2d::Scene *mkScene() {
    auto scene = cocos2d::Scene::create();
    auto layer = layer_t::create();
    scene->addChild(layer);
    return scene;
}

#endif
