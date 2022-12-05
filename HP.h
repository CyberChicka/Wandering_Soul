#ifndef ALONG_THE_WAY_HP_H
#define ALONG_THE_WAY_HP_H
#include "TextAndImages.h"
using namespace sf;

void Progres_bar(RenderWindow &window, int hp){
    screen();
    Text_Settings(window);
    if (hp >= 120) { HP.sprite.setTextureRect(IntRect(0, 0, 192, 64)); }
    if (hp == 100) { HP.sprite.setTextureRect(IntRect(198, 0, 192, 64)); }
    if (hp == 80) { HP.sprite.setTextureRect(IntRect(396, 0, 192, 64)); }
    if (hp == 60) { HP.sprite.setTextureRect(IntRect(0, 70, 192, 64)); }
    if (hp == 40) { HP.sprite.setTextureRect(IntRect(198, 70, 192, 64)); }
    if (hp == 20) { HP.sprite.setTextureRect(IntRect(396, 70, 192, 64)); }
    if (hp <= 0) { HP.sprite.setTextureRect(IntRect(0, 140, 192, 64)); }
    if(scrn == 1){

        Time_Bar.sprite.setScale(0.58f, 0.3f);
        Soul_Bar.sprite.setPosition(view.getCenter().x - 590, view.getCenter().y - 345);
        Soul_Bar.sprite.setScale(0.9f, 0.3f);
        text_gmTime.text.setPosition(view.getCenter().x - 570, view.getCenter().y - 260);
        Time_Bar.sprite.setPosition(view.getCenter().x - 570, view.getCenter().y - 260);
        text_souls.text.setPosition(view.getCenter().x - 570, view.getCenter().y - 335);
        HP.sprite.setPosition(view.getCenter().x - 570, view.getCenter().y - 300);
        Time_Bar.sprite.setPosition(view.getCenter().x - 590, view.getCenter().y - 238);
    }
    if(scrn == 2){ }
    if(scrn == 3){
        Time_Bar.sprite.setScale(0.6f, 0.4f);
        Time_Bar.sprite.setPosition(view.getCenter().x - 900, view.getCenter().y - 290);
        Soul_Bar.sprite.setScale(1.0f, 0.4f);
        Soul_Bar.sprite.setPosition(view.getCenter().x - 920, view.getCenter().y - 420);
        text_gmTime.text.setPosition(view.getCenter().x - 880, view.getCenter().y - 305);
        text_souls.text.setPosition(view.getCenter().x - 900, view.getCenter().y - 400);
        HP.sprite.setPosition(view.getCenter().x - 900, view.getCenter().y - 350);
    }
    window.draw(Soul_Bar.sprite);
    window.draw(Time_Bar.sprite);
    window.draw(HP.sprite);
    window.draw(text_souls.text); // рисуем этот текст
    window.draw(text_gmTime.text);
}

#endif //ALONG_THE_WAY_HP_H
