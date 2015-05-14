#include "GameLayer.h"
#include "MainMenuLayer.h"
#include "PauseMenuLayer.h"
#include "helper.h"

USING_NS_CC;

bool PauseMenuLayer::init() {
    if (!Layer::init())
        return false;
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    auto resumeItem = MenuItemImage::create
        ("PauseMenuLayer/Resume_Button.png",
         "PauseMenuLayer/Resume_Button(Click).png",
         [&](Ref *sender) {
            Director::getInstance()->popScene();
        });

    auto retryItem = MenuItemImage::create
        ("PauseMenuLayer/Retry_Button.png",
         "PauseMenuLayer/Retry_Button(Click).png",
         [&](Ref *sender) {
            auto dst = TransitionFlipX::create(3, GameLayer::createScene());
            Director::getInstance()->replaceScene(dst);
        });

    auto mainMenuItem = MenuItemImage::create
        ("PauseMenuLayer/Menu_Button.png",
         "PauseMenuLayer/Menu_Button(Click).png",
         [&](Ref *sender) {
            auto dst = TransitionPageTurn::create(3, mkScene<MainMenuLayer>(), false);
            Director::getInstance()->replaceScene(dst);
        });

    auto menu = Menu::create(resumeItem, retryItem, mainMenuItem, NULL);

    menu->alignItemsVerticallyWithPadding(visibleSize.height / 4);
    this->addChild(menu);

    auto bgSprite = Sprite::create("PauseMenuLayer/Pause_Background.png");
    bgSprite->setPosition(Point((visibleSize.width / 2) + origin.x,
                                (visibleSize.height / 2) + origin.y));
    this->addChild(bgSprite, -1);
    
    return true;
}
