#include "MainScene.h"
#include "Resource.h"
#include "audio/include/AudioEngine.h"

using namespace cocos2d;

Scene* MainScene::scene()
{
    Scene* scene = Scene::create();
    MainScene* layer = MainScene::create();

    scene->addChild(layer);

    return scene;
}

bool MainScene::init()
{

    if (!Layer::init())
    {
        return false;
    }


    Sprite* sp = Sprite::create("mainscreen.png", Rect(2, 1, 959, 640));

    sp->setAnchorPoint(Vec2::ANCHOR_BOTTOM_LEFT);
    this->addChild(sp, 0, 1);


    //添加logo
    auto logo = Sprite::create("mainscreen.png", Rect(511, 653, 919, 970));
    logo->setAnchorPoint(Vec2(0, 1));//锚点设置为左上角
    logo->setPosition(Point(271, 227));
    this->addChild(logo, 10, 10);

    //添加其他配件，拆分开便于后期做动态（可能）
    auto carrot= Sprite::create("mainscreen.png", Rect(8, 641, 224, 830));
    logo->setAnchorPoint(Vec2(0, 1));//锚点设置为左上角
    logo->setPosition(Point(374, 179));
    this->addChild(logo, 10, 9);

    system("pause");
    /*
    //不写配置了，手动
    int singalHeight = 36;
    int singalWidth = 123;
    //添加 三个按钮
    Sprite* newGameNormal = Sprite::create(s_menu_png, Rect(0, 0, singalWidth, singalHeight));//在png中直接截取某矩形区域部分
    Sprite* newGameSelected = Sprite::create(s_menu_png, Rect(0, singalHeight, singalWidth, singalHeight));
    Sprite* newGameDisabled = Sprite::create(s_menu_png, Rect(0, singalHeight * 2, singalWidth, singalHeight));
    //一个按钮的三种形态

    Sprite* gameSettingsNormal = Sprite::create(s_menu_png, Rect(singalWidth, 0, singalWidth, singalHeight));
    Sprite* gameSettingsSelected = Sprite::create(s_menu_png, Rect(singalWidth, singalHeight, singalWidth, singalHeight));
    Sprite* gameSettingsDisabled = Sprite::create(s_menu_png, Rect(singalWidth, singalHeight * 2, singalWidth, singalHeight));

    Sprite* aboutNormal = Sprite::create(s_menu_png, Rect(singalWidth * 2, 0, singalWidth, singalHeight));
    Sprite* aboutSelected = Sprite::create(s_menu_png, Rect(singalWidth * 2, singalHeight, singalWidth, singalHeight));
    Sprite* aboutDesabled = Sprite::create(s_menu_png, Rect(singalWidth * 2, singalHeight * 2, singalWidth, singalHeight));

    auto flare = Sprite::create(s_flare_jpg);
    this->addChild(flare, 15, 10);
    flare->setVisible(false);

    MenuItemSprite* newGame = MenuItemSprite::create(newGameNormal, newGameSelected, newGameDisabled,
        CC_CALLBACK_1(MainScene::flareEffect, this));

    MenuItemSprite* gameSetting = MenuItemSprite::create(gameSettingsNormal, gameSettingsSelected, gameSettingsDisabled,
        CC_CALLBACK_1(MainScene::onSettings, this));
    //“设置”按钮tag为20
    gameSetting->setTag(20);

    MenuItemSprite* about = MenuItemSprite::create(aboutNormal, aboutSelected, aboutDesabled,
        CC_CALLBACK_1(MainScene::onAbout, this));//StartMenu::menuCallback
    //“关于”按钮tag为21
    about->setTag(21);

    newGame->setScale(MW_SCALE);
    gameSetting->setScale(MW_SCALE);
    about->setScale(MW_SCALE);


    // 最后一个参数要是NULL
    Menu* menu = Menu::create(newGame, gameSetting, about, NULL);
    menu->alignItemsVerticallyWithPadding(15);//菜单项的对齐方法
    this->addChild(menu, 1, 2);
    menu->setPosition(Point(winSize.width / 2, winSize.height / 2 - 140));


    auto label = Label::createWithSystemFont("Power by Cocos2dx4.0 Ithe", "Arial", 21);
    label->setColor(Color3B(31, 45, 150));
    this->addChild(label, 1);
    label->setPosition(winSize.width / 2, 80);

    //添加update回调函数
    this->schedule(CC_SCHEDULE_SELECTOR(MainScene::update), 0.1);

    // 添加ships
   // Texture2D *textCache = Director::getInstance()->getTextureCache()->addImage(s_ship03);
    _ship = Sprite::createWithSpriteFrameName("ship03.png");
    this->addChild(_ship, 0, 4);
    //设置飞船位置 移动
    Point position = Point(CCRANDOM_0_1() * winSize.width, 0);
    _ship->setPosition(position);
    _ship->runAction(MoveBy::create(2, Point(CCRANDOM_0_1() * winSize.width, position.y + winSize.height + 100)));


    if (GlobalResManager::getInstance()->getSoundFlag())
    {

        int mainMusicAudio = AudioEngine::play2d(s_mainMainMusic);
        AudioEngine::setVolume(mainMusicAudio, 0.7);

    }
    */
    return true;
}
/*
void MainScene::onNewGame()
{
    AudioEngine::stopAll();
    Scene* scene = Scene::create();
    scene->addChild(GameLayer::create());

    Director::getInstance()->replaceScene(TransitionFade::create(1.2, scene));
    //使用 Director::replaceScene 方法切换当前场景为新创建的场景。
    //这里还使用了 TransitionFade::create 来添加一个淡入淡出的过渡效果，持续时间为1.2秒
}

void MainScene::onSettings(Ref* pSender)
{
    onButtonEffect();

    //转到"SettingsLayer"的界面
    Scene* scene = SettingsLayer::scene();
    Director::getInstance()->replaceScene(TransitionFade::create(1.2, scene));

}

void MainScene::onAbout(Ref* pSender)
{
    onButtonEffect();


    Scene* scene = AboutLayer::scene();
    Director::getInstance()->replaceScene(TransitionFade::create(1.2, scene));
}

void MainScene::update(float dt)
{
    if (_ship->getPosition().y > 750)
    {
        Point pos = Point(CCRANDOM_0_1() * winSize.width, 10);
        _ship->setPosition(pos);
        _ship->runAction(MoveBy::create(floor(5 * CCRANDOM_0_1()), Point(CCRANDOM_0_1() * winSize.width, pos.y + winSize.height)));

    }
}


void MainScene::onButtonEffect()
{
    if (GlobalResManager::getInstance()->getSoundFlag()) {
        //好像这个ID也没用，后面也不用了
        auto effect_audio = AudioEngine::play2d(s_buttonEffect);//按下按钮会响应声音
    }

}

void MainScene::flareEffect(Ref* pSender)//光晕效果后触发onNewGame函数
{
    onButtonEffect();
    int n = 0;

    Effect* flareEffect = Effect::create();
    CallFunc* callback = CallFunc::create(CC_CALLBACK_0(MainScene::onNewGame, this));

    flareEffect->flareEffect(s_flare_jpg, this, callback);


}
*/



