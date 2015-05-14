#ifndef __MAIN_MENU_LAYER_H__
#define __MAIN_MENU_LAYER_H__

#include "cocos2d.h"

/**
 * The MainMenuLayer Layer.
 */
class MainMenuLayer : public cocos2d::Layer {
    
    int m_;

public:
    /* Declares $Name *$Name::create(). */
    CREATE_FUNC(MainMenuLayer);

    virtual bool init();

protected:
    
private:
    
};

#endif
