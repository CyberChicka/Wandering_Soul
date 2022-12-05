#ifndef WANDERING_SOUL_BULLET_H
#define WANDERING_SOUL_BULLET_H

#include "Entity.h"

class Bullet :public Entity{//класс пули
public:
    int direction;//направление пули
    float distance = 0;
    Bullet(Image &image,float X, float Y, int W, int H, String Name, int dir):Entity(image,X,Y,W,H,Name){//всё так же, только взяли в конце состояние игрока (int dir)
        x = X;
        y = Y;
        direction = dir;
        speed = 0.8;
        w = h = 16;
        life = true;
        //выше инициализация в конструкторе
    }
    FloatRect getRect(){ return FloatRect(x, y, w, h); }
    void dist(float tempX, float tempY, float pX, float pY, float time, bool &isMove){
        if(life)
            if(isMove){
                distance = sqrt((tempX - pX)*(tempX - pX) + (tempY - pY)*(tempY - pY));
                if(distance > 2){
                    x += 2.1 * time*(tempX - pX) / distance;
                    y += 2.1 * time*(tempY - pY) / distance;
                } else{ isMove = false;}
            }
    }
    void update(float time)
    {
        x += dx*time;//само движение пули по х
        y += dy*time;//по у

        if(x > 5000){ x = 0; life = false; }
        if(y > 5000){ y = 0; life = false; }
        if(x <= 5){ x = 0; life = false;}
        if(y <= 5){y = 0; life = false;}

        for (int i = y/48; i < (y+h)/48; i++)
            for (int j = x/48; j<(x+w) / 48; j++)
            {
                if (LVLStarting[i][j] == '0' ) {
//                    if (dy > 0) { life = false;}
//                    if (dy < 0) {life = false;}
//                    if (dx > 0) {life = false;}
//                    if (dx < 0) { life = false;}
                }
            }

        sprite.setPosition(x+w/2, y+h/2);//задается позицию пуле
    }
};

#endif //WANDERING_SOUL_BULLET_H
