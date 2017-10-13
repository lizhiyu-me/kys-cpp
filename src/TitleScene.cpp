#include "TitleScene.h"
#include "Menu.h"
#include "MainScene.h"
#include "BattleScene.h"
#include "Event.h"
#include "SubScene.h"
#include "Button.h"
#include "Audio.h"
#include "TeamMenu.h"
#include "UIShop.h"
#include "Script.h"
#include "UISave.h"

TitleScene::TitleScene()
{
    full_window_ = 1;
    menu_ = new Menu();
    menu_->setTexture(TextureManager::getInstance()->loadTexture("title", 17));
    menu_->setPosition(400, 250);
    auto b = new Button("title", 3, 23, 23);
    menu_->addChild(b, 20, 0);
    b = new Button("title", 4, 24, 24);
    menu_->addChild(b, 20, 50);
    b = new Button("title", 6, 26, 26);
    menu_->addChild(b, 20, 100);
    menu_load_ = new UISave();
    menu_load_->setPosition(500, 300);
}

TitleScene::~TitleScene()
{
    delete menu_;
    delete menu_load_;
}

void TitleScene::draw()
{
    int count = count_ / 20;
    TextureManager::getInstance()->renderTexture("title", 0, 0, 0);
    TextureManager::getInstance()->renderTexture("title", 12, 70, 100);
    TextureManager::getInstance()->renderTexture("title", 10, 70, 100);
    TextureManager::getInstance()->renderTexture("title", 10, 670, 100);

    int alpha = count_ % 256;
    TextureManager::getInstance()->renderTexture("title", 13, 50, 300, { 255, 255, 255, 255 }, alpha);
    TextureManager::getInstance()->renderTexture("head", count % 115, 50, 300, { 255, 255, 255, 255 }, alpha);
    count_++;
}

void TitleScene::dealEvent(BP_Event& e)
{
    int r = menu_->run();
    if (r == 0)
    {
        Save::getInstance()->load(0);
        MainScene::getIntance()->setManPosition(Save::getInstance()->MainMapX, Save::getInstance()->MainMapY);
        MainScene::getIntance()->forceEnterSubScene(70, 19, 20);
        MainScene::getIntance()->setTowards(1);
        MainScene::getIntance()->run();
    }
    if (r == 1)
    {
        int save = menu_load_->run();
        MainScene::getIntance()->run();
    }
    if (r == 2)
    {
        setExit(true);
    }
}

void TitleScene::onEntrance()
{
}

