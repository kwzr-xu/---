#include "cocos2d.h"
#include "MainScene.h"
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

    auto director = Director::getInstance();
    auto visibleSize = director->getVisibleSize();
    auto origin = director->getVisibleOrigin();

    auto background = Sprite::create("main.jpg");
    background->setAnchorPoint(Vec2(0, 0));
    background->setPosition(Point(0, 0));

    float x = visibleSize.width / background->getContentSize().width;
    float y = visibleSize.height / background->getContentSize().height;
    background->setScale(x, y);

    this->addChild(background, 1);

    // 三个按钮 “冒险模式”“设置”“关于”
    Sprite* newGameNormal = Sprite::create("Button/newGameButton.png", Rect(0, 0, singalWidth1, singalHeight1));
    Sprite* newGameSelected = Sprite::create("Button/newGameButton.png", Rect(0, singalHeight1, singalWidth1, singalHeight1));
    Sprite* newGameDisabled = Sprite::create("Button/newGameButton.png", Rect(0, singalHeight1 * 2, singalWidth1, singalHeight1));

    Sprite* gameSettingsNormal = Sprite::create("Button/otherButton.png", Rect(0, 0, singalWidth2, singalHeight2));
    Sprite* gameSettingsSelected = Sprite::create("Button/otherButton.png", Rect(0, singalHeight2, singalWidth2, singalHeight2));
    Sprite* gameSettingsDisabled = Sprite::create("Button/otherButton.png", Rect(0, singalHeight2 * 2, singalWidth2, singalHeight2));

    Sprite* aboutNormal = Sprite::create("Button/otherButton.png", Rect(singalWidth2, 0, singalWidth2, singalHeight2));
    Sprite* aboutSelected = Sprite::create("Button/otherButton.png", Rect(singalWidth2, singalHeight2, singalWidth2, singalHeight2));
    Sprite* aboutDesabled = Sprite::create("Button/otherButton.png", Rect(singalWidth2, singalHeight2 * 2, singalWidth2, singalHeight2));

    MenuItemSprite* newGame = MenuItemSprite::create(newGameNormal, newGameSelected, newGameDisabled,
        CC_CALLBACK_1(MainScene::onNewGame, this));

    MenuItemSprite* gameSetting = MenuItemSprite::create(gameSettingsNormal, gameSettingsSelected, gameSettingsDisabled,
        CC_CALLBACK_1(MainScene::onSettings, this));
    gameSetting->setTag(20);

    MenuItemSprite* about = MenuItemSprite::create(aboutNormal, aboutSelected, aboutDesabled,
        CC_CALLBACK_1(MainScene::onAbout, this));
    about->setTag(21);

    newGame->setPosition(Point(visibleSize.width / 2, 100));
    gameSetting->setPosition(Point(visibleSize.width / 4, visibleSize.height / 3));
    about->setPosition(Point(visibleSize.width / 4 * 3, visibleSize.height / 3));

    Menu* menu = Menu::create(newGame, gameSetting, about, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 2, 2);

    //**处之后加条件来开关音乐
    //if (**)
    //{
    int mainMusicAudio = AudioEngine::play2d("Music/BGM.mp3");
    AudioEngine::setVolume(mainMusicAudio, 1);

    //}

    return true;
}

void MainScene::onNewGame(Ref* pSender)
{
    AudioEngine::stopAll();
    Scene* scene = Scene::create();
    //scene->addChild(GameMenu::create());
    //GameMenu还没写，这里会直接进一个啥也没有的新场景
    Director::getInstance()->replaceScene(TransitionFade::create(1, scene));
}

void MainScene::onSettings(Ref* pSender)
{
    //还没写，按按钮不会进入设置界面
    //Scene* scene = SettingsLayer::scene();
    //Director::getInstance()->replaceScene(TransitionFade::create(1.2, scene));
}

void MainScene::onAbout(Ref* pSender)
{
    //还没写，按按钮不会进入设置界面
    //Scene* scene = AboutLayer::scene();
    //Director::getInstance()->replaceScene(TransitionFade::create(1.2, scene));
}




