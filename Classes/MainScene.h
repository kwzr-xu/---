#pragma once
#ifndef __MW_CPP_SYSMENU_H__
#define __MW_CPP_SYSMENU_H__

#include "cocos2d.h"

class MainScene : public cocos2d::Layer
{
private:
public:

    virtual bool init();

    static cocos2d::Scene* scene();

    CREATE_FUNC(MainScene);
};


#endif/*__MW_CPP_SYSMENU_H__*/
