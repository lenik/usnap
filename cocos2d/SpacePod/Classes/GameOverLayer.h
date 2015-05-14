#ifndef __GAME_OVER_LAYER_H__
#define __GAME_OVER_LAYER_H__

#include "cocos2d.h"

/**
 * The GameOverLayer Layer.
 */
class GameOverLayer : public cocos2d::Layer {
    
    int m_;

public:
    /* Declares $Name *$Name::create(). */
    CREATE_FUNC(GameOverLayer);

    virtual bool init();

protected:
    
private:
    
};

#endif
