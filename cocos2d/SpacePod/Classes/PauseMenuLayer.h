#ifndef __PAUSE_MENU_LAYER_H__
#define __PAUSE_MENU_LAYER_H__

#include "cocos2d.h"

/**
 * The PauseMenuLayer Layer.
 */
class PauseMenuLayer : public cocos2d::Layer {
    
    int m_;

public:
    /* Declares $Name *$Name::create(). */
    CREATE_FUNC(PauseMenuLayer);

    virtual bool init();

protected:
    
private:
    
};

#endif
