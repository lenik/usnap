#ifndef __GAME_LAYER_H__
#define __GAME_LAYER_H__

#include "cocos2d.h"

/**
 * The GameLayer Layer.
 */
class GameLayer : public cocos2d::Layer {
    
    int m_;

 public:
    /* Declares $Name *$Name::create(). */
    CREATE_FUNC(GameLayer);

    static cocos2d::Scene *createScene();
    
    virtual bool init();

    inline void setPhysicsWorld(cocos2d::PhysicsWorld *world) {
        mWorld = world;
        mWorld->setGravity(cocos2d::Vect(0, 0));
    }

 protected:
    void update(float dt);
    void spawnAsteroid(float dt);

    bool onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *event);
    void onTouchMoved(cocos2d::Touch *touch, cocos2d::Event *event);
    void onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *event);
    void onTouchCancelled(cocos2d::Touch *touch, cocos2d::Event *event);
    bool onContactBegin(cocos2d::PhysicsContact& contact);
    
 private:
    cocos2d::Sprite *bgSprites[2];
    cocos2d::Sprite *playerSprite;
    std::vector<cocos2d::Sprite *> asteroids;

    bool isTouching;
    float touchPosition;

    cocos2d::PhysicsWorld *mWorld;
};

#endif
