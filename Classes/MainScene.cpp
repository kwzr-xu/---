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


    //���logo
    auto logo = Sprite::create("mainscreen.png", Rect(511, 653, 919, 970));
    logo->setAnchorPoint(Vec2(0, 1));//ê������Ϊ���Ͻ�
    logo->setPosition(Point(271, 227));
    this->addChild(logo, 10, 10);

    //��������������ֿ����ں�������̬�����ܣ�
    auto carrot= Sprite::create("mainscreen.png", Rect(8, 641, 224, 830));
    logo->setAnchorPoint(Vec2(0, 1));//ê������Ϊ���Ͻ�
    logo->setPosition(Point(374, 179));
    this->addChild(logo, 10, 9);

    system("pause");
    /*
    //��д�����ˣ��ֶ�
    int singalHeight = 36;
    int singalWidth = 123;
    //��� ������ť
    Sprite* newGameNormal = Sprite::create(s_menu_png, Rect(0, 0, singalWidth, singalHeight));//��png��ֱ�ӽ�ȡĳ�������򲿷�
    Sprite* newGameSelected = Sprite::create(s_menu_png, Rect(0, singalHeight, singalWidth, singalHeight));
    Sprite* newGameDisabled = Sprite::create(s_menu_png, Rect(0, singalHeight * 2, singalWidth, singalHeight));
    //һ����ť��������̬

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
    //�����á���ťtagΪ20
    gameSetting->setTag(20);

    MenuItemSprite* about = MenuItemSprite::create(aboutNormal, aboutSelected, aboutDesabled,
        CC_CALLBACK_1(MainScene::onAbout, this));//StartMenu::menuCallback
    //�����ڡ���ťtagΪ21
    about->setTag(21);

    newGame->setScale(MW_SCALE);
    gameSetting->setScale(MW_SCALE);
    about->setScale(MW_SCALE);


    // ���һ������Ҫ��NULL
    Menu* menu = Menu::create(newGame, gameSetting, about, NULL);
    menu->alignItemsVerticallyWithPadding(15);//�˵���Ķ��뷽��
    this->addChild(menu, 1, 2);
    menu->setPosition(Point(winSize.width / 2, winSize.height / 2 - 140));


    auto label = Label::createWithSystemFont("Power by Cocos2dx4.0 Ithe", "Arial", 21);
    label->setColor(Color3B(31, 45, 150));
    this->addChild(label, 1);
    label->setPosition(winSize.width / 2, 80);

    //���update�ص�����
    this->schedule(CC_SCHEDULE_SELECTOR(MainScene::update), 0.1);

    // ���ships
   // Texture2D *textCache = Director::getInstance()->getTextureCache()->addImage(s_ship03);
    _ship = Sprite::createWithSpriteFrameName("ship03.png");
    this->addChild(_ship, 0, 4);
    //���÷ɴ�λ�� �ƶ�
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
    //ʹ�� Director::replaceScene �����л���ǰ����Ϊ�´����ĳ�����
    //���ﻹʹ���� TransitionFade::create �����һ�����뵭���Ĺ���Ч��������ʱ��Ϊ1.2��
}

void MainScene::onSettings(Ref* pSender)
{
    onButtonEffect();

    //ת��"SettingsLayer"�Ľ���
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
        //�������IDҲû�ã�����Ҳ������
        auto effect_audio = AudioEngine::play2d(s_buttonEffect);//���°�ť����Ӧ����
    }

}

void MainScene::flareEffect(Ref* pSender)//����Ч���󴥷�onNewGame����
{
    onButtonEffect();
    int n = 0;

    Effect* flareEffect = Effect::create();
    CallFunc* callback = CallFunc::create(CC_CALLBACK_0(MainScene::onNewGame, this));

    flareEffect->flareEffect(s_flare_jpg, this, callback);


}
*/



