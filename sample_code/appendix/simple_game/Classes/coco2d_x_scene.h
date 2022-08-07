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

#ifndef __COCO2D_X_SCENE_H__
#define __COCO2D_X_SCENE_H__

#include "cocos2d.h"
#include <string>
#include <map>
#include "const_int.h"
#include "../game_logic/riding_object.h"

using namespace std;
USING_NS_CC;

class coco2d_x_scene : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();
    
    virtual bool init();
    virtual ~coco2d_x_scene();
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    void menu_button_call_back(cocos2d::Ref* pSender);

    virtual void onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event);
    virtual void onKeyReleased(EventKeyboard::KeyCode keyCode, Event* event);
    virtual void onMouseMove(Event* event);
    virtual void onMouseDown(Event* event);
    virtual void onMouseUp(Event* event);
    virtual void onMouseScroll(Event* event);
    
    // implement the "static create()" method manually
    CREATE_FUNC(coco2d_x_scene);

private:
  int diff_x;
  int diff_y;
  static bool is_shooted;
  static bool is_key_pressed;
  static bool is_player_moving;
  static map<riding_menu_id, string> riding_menu_map;
  EventKeyboard::KeyCode current_press_key;

  void init_menu(cocos2d::Vec2 origin, cocos2d::Size visibleSize);
  void move_timer(float f);
  void bullet_timer(float f);
  void init_object(cocos2d::Vec2 origin, cocos2d::Size visibleSize);
  void init_event_listener();
  void init_variables();
};

#endif // __COCO2D_X_SCENE_H__
