#pragma once
#ifndef __MW_CPP_SYSMENU_H__
#define __MW_CPP_SYSMENU_H__

#include "cocos2d.h"

class MainScene : public cocos2d::Layer
{
private:
    float singalHeight1 = 88;
    float singalWidth1 = 300;
    float singalHeight2 = 63;
    float singalWidth2 = 83;
public:

    virtual bool init();

    static cocos2d::Scene* scene();

    void onNewGame(Ref* pSender);
    void onAbout(Ref* pSender);
    void onSettings(Ref* pSender);

    CREATE_FUNC(MainScene);
};


#endif
