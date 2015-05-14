#include <stdlib.h>

#include "GameLayer.h"
#include "GameOverLayer.h"
#include "PauseMenuLayer.h"
#include "helper.h"

USING_NS_CC;

Scene *GameLayer::createScene() {
    auto scene = Scene::createWithPhysics();
    auto layer = GameLayer::create();
    layer->setPhysicsWorld(scene->getPhysicsWorld());
    scene->addChild(layer);
    return scene;
}

bool GameLayer::init() {
    if (!Layer::init())
        return false;
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    auto pauseItem = MenuItemImage::create
        ("GameLayer/Pause_Button.png",
         "GameLayer/Pause_Button(Click).png",
         [&](Ref *sender) {
            Director::getInstance()->pushScene(mkScene<PauseMenuLayer>());
        });

    auto c = pauseItem->getContentSize();
    pauseItem->setPosition(Point(c.width * 3/4 + origin.x,
                                 visibleSize.height - c.height * 3/4 + origin.y));

    auto menu = Menu::create(pauseItem, NULL);
    menu->setPosition(Point::ZERO);
    this->addChild(menu);
    
    for (int i = 0; i < 2; i++) {
        bgSprites[i] = Sprite::create("GameLayer/Game_Screen_Background.png");
        bgSprites[i]->setPosition(Point((visibleSize.width / 2) + origin.x,
                                        (visibleSize.height / 2) - i * visibleSize.height + origin.y));
        this->addChild(bgSprites[i], -2);
    }

    playerSprite = Sprite::create("GameLayer/Space_Pod.png");
    auto body = PhysicsBody::createCircle(playerSprite->getContentSize().width / 2);
    body->setContactTestBitmask(true);
    body->setDynamic(true);
    playerSprite->setPhysicsBody(body);
    playerSprite->setPosition(Point(visibleSize.width / 2,
                                    pauseItem->getPosition().y - (pauseItem->getContentSize().height / 2) - (playerSprite->getContentSize().height / 2)));
    this->addChild(playerSprite, -1);

    this->scheduleUpdate();
    this->schedule(schedule_selector(GameLayer::spawnAsteroid), 1.0);
    
    auto listener = EventListenerTouchOneByOne::create();
    listener->setSwallowTouches(true);
    listener->onTouchBegan = CC_CALLBACK_2(GameLayer::onTouchBegan, this);
    listener->onTouchMoved = CC_CALLBACK_2(GameLayer::onTouchMoved, this);
    listener->onTouchEnded = CC_CALLBACK_2(GameLayer::onTouchEnded, this);
    listener->onTouchCancelled = CC_CALLBACK_2(GameLayer::onTouchCancelled, this);

    this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);
    isTouching = false;
    touchPosition = 0;

    auto contactListener = EventListenerPhysicsContact::create();
    contactListener->onContactBegin = [&](PhysicsContact& contact) {
        Director::getInstance()->replaceScene(mkScene<GameOverLayer>());
        return true;
    };
    this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(contactListener, this);
    
    return true;
}

void GameLayer::update(float dt) {

    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    for (int i = 0; i < 2; i++) {
        auto pos = bgSprites[i]->getPosition();
        if (pos.y == visibleSize.height + (visibleSize.height / 2) - 1) {
            bgSprites[i]->setPosition(Point((visibleSize.width / 2) + origin.x,
                                            (-1 * visibleSize.height) + (visibleSize.height / 2)));
        }
    }

    for (int i = 0; i < 2; i++) {
        auto pos = bgSprites[i]->getPosition();
        bgSprites[i]->setPosition(Point(pos.x, pos.y + (0.75 * visibleSize.height * dt)));
    }

    for (int i = 0; i < asteroids.size(); i++) {
        auto a = asteroids[i];
        auto pos = a->getPosition();
        a->setPosition(Point(pos.x, pos.y + (0.75 * visibleSize.height * dt)));
        pos = a->getPosition();
        if (pos.y > visibleSize.height * 2) {
            this->removeChild(a);
            asteroids.erase(asteroids.begin() + i);
        }
    }

    if (isTouching) {
        auto pos = playerSprite->getPosition();
        auto c = playerSprite->getContentSize();
        if (touchPosition < visibleSize.width / 2) {
            playerSprite->setPositionX(pos.x - (0.5 * visibleSize.width * dt));
            pos = playerSprite->getPosition();
            if (pos.x <= c.width / 2) {
                playerSprite->setPositionX(c.width / 2);
            }
        } else {
            playerSprite->setPositionX(pos.x + (0.5 * visibleSize.width * dt));
            pos = playerSprite->getPosition();
            if (pos.x >= visibleSize.width - c.width / 2) {
                playerSprite->setPositionX(visibleSize.width - c.width / 2);
            }
        }
    }
}

void GameLayer::spawnAsteroid(float dt) {

    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    int index = (::random() % 3) + 1;
    __String* str = __String::createWithFormat("GameLayer/Asteroid_%i.png",
                                               index);
    Sprite *tmp = Sprite::create(str->getCString());

    auto c = tmp->getContentSize();
    int xpos = (::random() % (int) (visibleSize.width - (c.width / 2))) + (c.width / 2);
    tmp->setPosition(Point(xpos + origin.x, -c.height + origin.y));
    asteroids.push_back(tmp);

    auto body = PhysicsBody::createCircle(c.height / 2);
    body->setContactTestBitmask(true);
    body->setDynamic(true);
    tmp->setPhysicsBody(body);
    
    this->addChild(tmp, -1);
}

bool GameLayer::onTouchBegan(Touch *touch, Event *event) {
    isTouching = true;
    touchPosition = touch->getLocation().x;
    return true;
}

void GameLayer::onTouchMoved(Touch *touch, Event *event) {
}

void GameLayer::onTouchEnded(Touch *touch, Event *event) {
    isTouching = false;
}

void GameLayer::onTouchCancelled(Touch *touch, Event *event) {
    onTouchEnded(touch, event);
}
