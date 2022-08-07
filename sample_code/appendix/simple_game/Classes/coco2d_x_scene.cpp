/****************************************************************************
 Copyright (c) 2017-2018 Xiamen Yaji Software Co., Ltd.
 
 http://www.cocos2d-x.org
 
 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ****************************************************************************/

#include "coco2d_x_scene.h"
#include <array>
#include <string>
#include <cmath>
#include "const_string.h"
#include "const_int.h"
#include "../game_logic/monster_class.h"
#include "../game_logic/configuration.h"
#include "../game_logic/game_logic_factory.h"

using namespace std;
USING_NS_CC;

bool coco2d_x_scene::is_key_pressed = false;
bool coco2d_x_scene::is_player_moving = false;
bool coco2d_x_scene::is_shooted = false;

map<riding_menu_id, string> coco2d_x_scene::riding_menu_map = { {riding_menu_id::riding_unselect, unselect},
                                                                {riding_menu_id::riding_obj_car,riding_object_car},
                                                                {riding_menu_id::riding_obj_motor_cycle, riding_object_motor_cycle},
                                                                {riding_menu_id::riding_obj_horse, riding_object_horse} };


Scene* coco2d_x_scene::createScene()
{
    return coco2d_x_scene::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

void coco2d_x_scene::onMouseMove(Event* event) {
  EventMouse* e = (EventMouse*)event;
}

void coco2d_x_scene::onMouseDown(Event* event) {
  EventMouse* e = (EventMouse*)event;
}

void coco2d_x_scene::onMouseUp(Event* event) {
  EventMouse* e = (EventMouse*)event;
  float bullet_duration = bullet_speed;

  if (is_shooted) {
    return;
  }
  is_shooted = true;

  string debug = to_string(e->getCursorX()) + " , " + to_string(e->getCursorY());
  OutputDebugStringA(debug.c_str());

  Vec2 target_position(e->getCursorX(), e->getCursorY());
  auto player = this->getChildByName(player_string);
  Vec2 player_position = player->getPosition();

  [&bullet_duration](Vec2 location_1, Vec2 location_2) {
    float length = sqrt(pow(location_1.x - location_2.x, 2) + pow(location_1.y - location_2.y, 2));
    bullet_duration = length / bullet_speed;
  }(target_position, player_position);

  auto bullet = Sprite::create(bullet_string + png_extention_string);
  bullet->setPosition(player_position);
  this->addChild(bullet, 0, bullet_string);

  auto move_by = MoveBy::create(bullet_duration, Vec2(target_position.x - player_position.x, target_position.y - player_position.y));
  this->schedule(CC_SCHEDULE_SELECTOR(coco2d_x_scene::bullet_timer), bullet_duration);
  bullet->runAction(move_by);
}

void coco2d_x_scene::bullet_timer(float f) {
  this->removeChildByName(bullet_string);
  is_shooted = false;
}

void coco2d_x_scene::onMouseScroll(Event* event) {
  EventMouse* e = (EventMouse*)event;
}

void coco2d_x_scene::onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event) {

  diff_x = 0;
  diff_y = 0;

  is_key_pressed = true;
  current_press_key = keyCode;
  switch (keyCode) {
  case EventKeyboard::KeyCode::KEY_UP_ARROW:
  case EventKeyboard::KeyCode::KEY_W:
    diff_y += configuration::get_move_speed();
    break;
  case EventKeyboard::KeyCode::KEY_DOWN_ARROW:
  case EventKeyboard::KeyCode::KEY_S:
    diff_y -= configuration::get_move_speed();
    break;
  case EventKeyboard::KeyCode::KEY_LEFT_ARROW:
  case EventKeyboard::KeyCode::KEY_A:
    diff_x -= configuration::get_move_speed();
    break;
  case EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
  case EventKeyboard::KeyCode::KEY_D:
    diff_x += configuration::get_move_speed();
    break;
  }

  this->schedule(CC_SCHEDULE_SELECTOR(coco2d_x_scene::move_timer), move_frequency);
}

void coco2d_x_scene::onKeyReleased(EventKeyboard::KeyCode keyCode, Event* event) {
  if (current_press_key == keyCode) {
    is_key_pressed = false;
  }
}

void coco2d_x_scene::move_timer(float f) {

  if (false == is_key_pressed) {
    this->unschedule(CC_SCHEDULE_SELECTOR(coco2d_x_scene::move_timer));
    return;
  }

  auto player = this->getChildByName(player_string);
  auto move_by = MoveBy::create(move_interval, Vec2(diff_x, diff_y));
  player->runAction(move_by);
}

void coco2d_x_scene::init_variables() {
  //riding_menu_map.insert({ riding_menu_id::riding_obj_car, &coco2d_x_scene::car_instance });
  //riding_menu_map.insert({ riding_menu_id::riding_obj_motor_cycle, &coco2d_x_scene::motor_cycle_instance });
  //riding_menu_map.insert({ riding_menu_id::riding_obj_horse, &coco2d_x_scene::horse_instance });
}

// on "init" you need to initialize your instance
bool coco2d_x_scene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Scene::init() )
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    //init_variables();

    init_menu(origin, visibleSize);

    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label

    auto label = Label::createWithTTF("Do It! CPP::Final Sample Source Code", "fonts/Marker Felt.ttf", 24);
    if (label != nullptr) {
        // position the label on the center of the screen
        label->setPosition(Vec2(origin.x + label->getContentSize().width / 2 + menu_margin,
                                origin.y + visibleSize.height - label->getContentSize().height));

        // add the label as a child to this layer
        this->addChild(label, 1, main_title_string);
    }

    init_object(origin, visibleSize);
    init_event_listener();

    return true;
}

void coco2d_x_scene::init_menu(cocos2d::Vec2 origin, cocos2d::Size visibleSize) {
  /////////////////////////////
  // 2. add a menu item with "X" image, which is clicked to quit the program
  //    you may modify it.

  // add a "close" icon to exit the progress. it's an autorelease object
  auto closeItem = MenuItemImage::create(
    "CloseNormal.png",
    "CloseSelected.png",
    CC_CALLBACK_1(coco2d_x_scene::menuCloseCallback, this));

  if (closeItem == nullptr ||
    closeItem->getContentSize().width <= 0 ||
    closeItem->getContentSize().height <= 0)
  {
    problemLoading("'CloseNormal.png' and 'CloseSelected.png'");
  }
  else
  {
    float x = origin.x + visibleSize.width - closeItem->getContentSize().width / 2;
    float y = origin.y + closeItem->getContentSize().height / 2;
    closeItem->setPosition(Vec2(x, y));
  }

  // create menu, it's an autorelease object
  auto menu = Menu::create(closeItem, NULL);
  menu->setPosition(Vec2::ZERO);
  this->addChild(menu, 1);

  int menu_count = 0;
  for (auto menu_item : riding_menu_map) {

    auto menu_button = MenuItemImage::create( menu_prefix + menu_item.second + png_extention_string,
                                              menu_prefix + menu_item.second + png_extention_string,
                                              CC_CALLBACK_1(coco2d_x_scene::menu_button_call_back, this));
    if (nullptr != menu_button) {
      menu_button->setPosition(Vec2(origin.x + visibleSize.width - menu_margin - menu_button->getContentSize().width/2 - menu_count * (menu_margin + menu_button->getContentSize().width),
                                    origin.y + visibleSize.height - 3* menu_margin));
      menu_button->setTag((int)menu_item.first);
      auto menu_object = Menu::create(menu_button, NULL);
      menu_object->setPosition(Vec2::ZERO);
      this->addChild(menu_object, 1);
      menu_count++;
    }
  }
}

void coco2d_x_scene::init_object(cocos2d::Vec2 origin, cocos2d::Size visibleSize) {
  game_logic_factory::create_terrain(this, origin, visibleSize);
  game_logic_factory::initialize_monster(this, visibleSize);
  game_logic_factory::create_player(this, origin, visibleSize, riding_menu_map);
}

void coco2d_x_scene::init_event_listener() {
  auto key_board_event_listener = EventListenerKeyboard::create();
  key_board_event_listener->onKeyPressed = CC_CALLBACK_2(coco2d_x_scene::onKeyPressed, this);
  key_board_event_listener->onKeyReleased = CC_CALLBACK_2(coco2d_x_scene::onKeyReleased, this);

  _eventDispatcher->addEventListenerWithSceneGraphPriority(key_board_event_listener, this);

  auto mouse_event_listener = EventListenerMouse::create();
  mouse_event_listener->onMouseMove = CC_CALLBACK_1(coco2d_x_scene::onMouseMove, this);
  mouse_event_listener->onMouseDown = CC_CALLBACK_1(coco2d_x_scene::onMouseDown, this);
  mouse_event_listener->onMouseUp = CC_CALLBACK_1(coco2d_x_scene::onMouseUp, this);
  mouse_event_listener->onMouseScroll = CC_CALLBACK_1(coco2d_x_scene::onMouseScroll, this);
  _eventDispatcher->addEventListenerWithSceneGraphPriority(mouse_event_listener, this);
}

void coco2d_x_scene::menu_button_call_back(cocos2d::Ref* pSender) {
  riding_menu_id tag = (riding_menu_id)((Node*)pSender)->getTag();
  auto player = this->getChildByName(player_string);

  riding_menu_id current_riding_object = configuration::get_current_ridigin_object();

  if (tag == current_riding_object) {
    return;
  }

  if (riding_menu_id::riding_unselect != current_riding_object) {
    auto riding_object = player->getChildByTag((int)current_riding_object);
    riding_object->setVisible(false);
  }

  if (riding_menu_id::riding_unselect != tag) {
    auto riding_object = player->getChildByTag((int)tag);
    riding_object->setVisible(true);
  }

  configuration::set_riding_object(tag);

  switch (tag) {
  case riding_menu_id::riding_obj_car:
    configuration::set_move_speed(move_step_car_offset);
    break;
  case riding_menu_id::riding_obj_horse:
    configuration::set_move_speed(move_step_horse_offset);
    break;
  case riding_menu_id::riding_obj_motor_cycle:
    configuration::set_move_speed(move_step_motor_cycle_offset);
    break;
  case riding_menu_id::riding_unselect:
    configuration::set_move_speed(move_step_offset);
    break;
  }
}

void coco2d_x_scene::menuCloseCallback(Ref* pSender)
{
    //Close the cocos2d-x game scene and quit the application
    Director::getInstance()->end();

    /*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() as given above,instead trigger a custom event created in RootViewController.mm as below*/

    //EventCustom customEndEvent("game_scene_close_event");
    //_eventDispatcher->dispatchEvent(&customEndEvent);
}

coco2d_x_scene::~coco2d_x_scene() {
  game_logic_factory::destroy_monster();
  game_logic_factory::destroy_terrain();
  game_logic_factory::destory_player();
}
