#include "HelloWorldScene.h"
#include "Keyboard.h"

USING_NS_CC;

Scene* HelloWorld::createScene() {
    // 'scene' is an autorelease object
    auto scene = Scene::create();

    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance

bool HelloWorld::init() {
    //////////////////////////////
    // 1. super init first

    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    auto closeItem = MenuItemImage::create(
            "CloseNormal.png",
            "CloseSelected.png",
            CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));

    closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width / 2,
            origin.y + closeItem->getContentSize().height / 2));

    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);

    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label

    auto label = LabelTTF::create("2048", "Arial", 50);

    // position the label on the center of the screen
    label->setPosition(Vec2(origin.x + visibleSize.width / 2,
            origin.y + visibleSize.height - label->getContentSize().height));

    // add the label as a child to this layer
    this->addChild(label, 1);

    // add "HelloWorld" splash screen"
    auto sprite = Sprite::create("2048.png");
    sprite->setScale(0.7);

    // position the sprite on the center of the screen
    sprite->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));

    // add the sprite as a child to this layer
    this->addChild(sprite, 2);

    // add background layer
    auto layer = LayerColor::create(Color4B(120, 190, 190, 255));

    // add the bg layer to this
    this->addChild(layer, -1);

    // 设置每格的方块
    auto numSprite = Sprite::create("num_rect.png");
    numSprite->setScale(0.7);
    numSprite->setPosition(Vec2(visibleSize.width / 2 - numSprite->getContentSize().width,
            visibleSize.height / 2 + numSprite->getContentSize().height + 20));
    this->addChild(numSprite, 1);

    // 设置方块中的数字
    auto num = LabelTTF::create("2", "Arial", 80);
    num->setPosition(Vec2(origin.x + numSprite->getContentSize().width / 2,
            origin.y + numSprite->getContentSize().height / 2));
    numSprite->addChild(num, 3);

    // 移动方块
    auto moveR = MoveBy::create(1, Point(100, 0));
    numSprite->runAction(moveR);

    // 加入键盘事件
    auto listener1 = EventListenerKeyboard::create();
    listener1->onKeyPressed = [](EventKeyboard::KeyCode keycode, cocos2d::Event * event) {
        if (keycode == EventKeyboard::KeyCode::KEY_KP_RIGHT) {
            auto target = static_cast<Sprite*>(event->getCurrentTarget());
            auto moveR = MoveBy::create(1, Point(100, 0));
            target->runAction(moveR);
            return true;
        }
        return false;
    };


    return true;
}

void HelloWorld::menuCloseCallback(Ref* pSender) {
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
    MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.", "Alert");
    return;
#endif

    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
