#include "helper.h"
#include "MainMenuLayer.h"
#include "GameLayer.h"
#include "GameOverLayer.h"

USING_NS_CC;

bool MainMenuLayer::init() {
    if (!Layer::init())
        return false;
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    auto menuTitle = MenuItemImage::create
        ("MainMenuLayer/Game_Title.png",
         "MainMenuLayer/Game_Title.png");
    
    auto playItem = MenuItemImage::create
        ("MainMenuLayer/Play_Button.png",
         "MainMenuLayer/Play_Button(Click).png",
         [&](Ref *sender) {
            //auto dst = mkScene<GameOverLayer>();
            auto dst = TransitionFade::create(1.0, GameLayer::createScene());
            Director::getInstance()->replaceScene(dst);
        });

    auto menu = Menu::create(menuTitle, playItem, NULL);
    menu->alignItemsVerticallyWithPadding(visibleSize.height / 4);
    this->addChild(menu);

    auto bgSprite = Sprite::create("MainMenuLayer/Background.png");
    bgSprite->setPosition(Point((visibleSize.width / 2) + origin.x,
                                (visibleSize.height / 2) + origin.y));
    
    return true;
}
