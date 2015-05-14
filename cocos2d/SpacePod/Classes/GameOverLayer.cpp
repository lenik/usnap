#include "GameLayer.h"
#include "GameOverLayer.h"
#include "MainMenuLayer.h"
#include "helper.h"

USING_NS_CC;

bool GameOverLayer::init() {
    if (!Layer::init())
        return false;
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    auto menuTitle = MenuItemImage::create
        ("GameOverLayer/Game_Over.png",
         "GameOverLayer/Game_Over.png");

    auto retryItem = MenuItemImage::create
        ("GameOverLayer/Retry_Button.png",
         "GameOverLayer/Retry_Button(Click).png",
         [&](Ref *sender) {
            Director::getInstance()->replaceScene(GameLayer::createScene());
        });

    auto mainMenuItem = MenuItemImage::create
        ("GameOverLayer/Menu_Button.png",
         "GameOverLayer/Menu_Button(Click).png",
         [&](Ref *sender) {
            Director::getInstance()->replaceScene(mkScene<MainMenuLayer>());
        });


    auto menu = Menu::create(menuTitle, retryItem, mainMenuItem, NULL);
    menu->alignItemsVerticallyWithPadding(visibleSize.height / 4);
    this->addChild(menu);

    auto bgSprite = Sprite::create("GameOverLayer/Game_Over_Screen_Background.png");
    bgSprite->setPosition(Point((visibleSize.width / 2) + origin.x,
                                (visibleSize.height / 2) + origin.y));
    this->addChild(bgSprite, -1);
    return true;
}
