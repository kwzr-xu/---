#include "cocos2d.h"
#include "MainScene.h"
#include "audio/include/AudioEngine.h"

using namespace cocos2d;

// ������Ϸ����������
Scene* MainScene::scene()
{
    Scene* scene = Scene::create();
    MainScene* layer = MainScene::create();

    scene->addChild(layer);

    return scene;
}

// ��ʼ����������
bool MainScene::init()
{
    if (!Layer::init())
    {
        return false;
    }

    auto director = Director::getInstance();
    auto visibleSize = director->getVisibleSize();
    auto origin = director->getVisibleOrigin();

    // ���������ñ���ͼ��
    auto background = Sprite::create("main.jpg");
    background->setAnchorPoint(Vec2(0, 0));
    background->setPosition(Point(0, 0));

    // ������Ļ�ߴ��������ͼ���С��
    float x = visibleSize.width / background->getContentSize().width;
    float y = visibleSize.height / background->getContentSize().height;
    background->setScale(x, y);

    this->addChild(background, 1);

    // ������Ϸ�İ�ť - ��ð��ģʽ���������á��������ڡ���
    // ������ѡ�С�����״̬�İ�ťͼ��
    Sprite* newGameNormal = Sprite::create("Button/newGameButton.png", Rect(0, 0, singalWidth1, singalHeight1));
    Sprite* newGameSelected = Sprite::create("Button/newGameButton.png", Rect(0, singalHeight1, singalWidth1, singalHeight1));
    Sprite* newGameDisabled = Sprite::create("Button/newGameButton.png", Rect(0, singalHeight1 * 2, singalWidth1, singalHeight1));

    Sprite* gameSettingsNormal = Sprite::create("Button/otherButton.png", Rect(0, 0, singalWidth2, singalHeight2));
    Sprite* gameSettingsSelected = Sprite::create("Button/otherButton.png", Rect(0, singalHeight2, singalWidth2, singalHeight2));
    Sprite* gameSettingsDisabled = Sprite::create("Button/otherButton.png", Rect(0, singalHeight2 * 2, singalWidth2, singalHeight2));

    Sprite* aboutNormal = Sprite::create("Button/otherButton.png", Rect(singalWidth2, 0, singalWidth2, singalHeight2));
    Sprite* aboutSelected = Sprite::create("Button/otherButton.png", Rect(singalWidth2, singalHeight2, singalWidth2, singalHeight2));
    Sprite* aboutDesabled = Sprite::create("Button/otherButton.png", Rect(singalWidth2, singalHeight2 * 2, singalWidth2, singalHeight2));

    // Ϊÿ����ť���ûص�������
    MenuItemSprite* newGame = MenuItemSprite::create(newGameNormal, newGameSelected, newGameDisabled,
        CC_CALLBACK_1(MainScene::onNewGame, this));

    MenuItemSprite* gameSetting = MenuItemSprite::create(gameSettingsNormal, gameSettingsSelected, gameSettingsDisabled,
        CC_CALLBACK_1(MainScene::onSettings, this));
    gameSetting->setTag(20);

    MenuItemSprite* about = MenuItemSprite::create(aboutNormal, aboutSelected, aboutDesabled,
        CC_CALLBACK_1(MainScene::onAbout, this));
    about->setTag(21);

    // ���ð�ťλ�á�
    newGame->setPosition(Point(visibleSize.width / 2, 100));
    gameSetting->setPosition(Point(visibleSize.width / 4, visibleSize.height / 3));
    about->setPosition(Point(visibleSize.width / 4 * 3, visibleSize.height / 3));

    // ����ť��ӵ��˵�����ӵ�������
    Menu* menu = Menu::create(newGame, gameSetting, about, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 2, 2);

    // ��ӱ������֣����������ɿ��ء�
    // if (���ֿ�������)
    // {
    int mainMusicAudio = AudioEngine::play2d("Music/BGM.mp3");
    AudioEngine::setVolume(mainMusicAudio, 1);
    // }

    return true;
}

void MainScene::onNewGame(Ref* pSender)
{
    AudioEngine::stopAll();
    Scene* scene = Scene::create();
    //scene->addChild(GameMenu::create());
    //GameMenu��ûд�������ֱ�ӽ�һ��ɶҲû�е��³���
    Director::getInstance()->replaceScene(TransitionFade::create(1, scene));
}

void MainScene::onSettings(Ref* pSender)
{
    //��ûд������ť����������ý���
    //Scene* scene = SettingsLayer::scene();
    //Director::getInstance()->replaceScene(TransitionFade::create(1.2, scene));
}

void MainScene::onAbout(Ref* pSender)
{
    //��ûд������ť����������ý���
    //Scene* scene = AboutLayer::scene();
    //Director::getInstance()->replaceScene(TransitionFade::create(1.2, scene));
}




