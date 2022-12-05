#ifndef WANDERING_SOUL_BOSS_H
#define WANDERING_SOUL_BOSS_H

#include "Entity.h"

using namespace std;
using namespace sf;

class BossEnemy: public Entity{
public:
    bool isLvL3, isBoss, isWelcome;
    bool isClk;
    float x, y;
    int w, h;
    BossEnemy(Image &image, float X, float Y,int W,int H,String Name):Entity(image,X,Y,W,H,Name){
        isLvL3 = false; isBoss = false; isClk = false;
        isWelcome = false;
        w = W; h = H; x = X; y = Y;
        if(name == "Ghost_normal"){ health = 1200; }
        sprite.setOrigin(w/2, h/2);
        sprite.setTextureRect(IntRect(0, 0, w, h));
    }
    FloatRect getRect(){ return FloatRect(x, y, w, h); }
    void Anim(){
        *time = clock.getElapsedTime().asMicroseconds();
        if (life) gameTime = gmTimeClock.getElapsedTime().asSeconds(); else { view.move(0.8, 0); }
        clock.restart();
        *time = *time / 800;
        if(name == "Ghost_normal"){
            if(life){
                if(isBoss){
                    CurrentFrame += 0.005 * *time; if (CurrentFrame > 7) CurrentFrame -= 7;
                    sprite.setTextureRect(IntRect(330 * int(CurrentFrame)+320, 0, -320, 400));
                } else{
                    CurrentFrame += 0.005 * *time; if (CurrentFrame > 7) CurrentFrame -= 7;
                    sprite.setTextureRect(IntRect(330 * int(CurrentFrame)+320, 0, -320, 400));
                }
            } else{
                sprite.setTextureRect(IntRect(320, 0, -320, 400));
            }
        }
    }
    void checkCollisionWithMap(float Dx, float Dy){
        for (int i = y / 48; i < (y + h) / 48; i++)//проходимся по элементам карты
            for (int j = x / 48; j < (x + w) / 48; j++)
            {
                if (TileLVL2[i][j] == '0' || TileLVL2[i][j] == '1')//если элемент наш тайлик земли, то
                {
                    if (Dy>0){ y = i * 48 - h;  dy = -0.5;  }//по Y вниз=>идем в пол(стоим на месте) или падаем. В этот момент надо вытолкнуть персонажа и поставить его на землю, при этом говорим что мы на земле тем самым снова можем прыгать
                    if (Dy<0){ y = i * 48 + 48; dy = 0.5; }//столкновение с верхними краями карты(может и не пригодиться)
                    if (Dx>0){ x = j * 48 - w; dx = -0.5;  sprite.scale(-1, 1); }//с правым краем карты
                    if (Dx<0){ x = j * 48 + 48; dx = 0.5;  sprite.scale(-1, 1); }// с левым краем карты
                }
            }
    }
    void update(float time){
        Anim();
        speed = 0;
        sprite.setPosition(x, y);
        if(name == "Ghost_normal"){
            speed = 0;
            checkCollisionWithMap(dx, 0);
            if(life)x += dx*time;
        }
        if(health > 0){ life = true;}
        else{ life = false;}
    }

};

#endif //WANDERING_SOUL_BOSS_H
