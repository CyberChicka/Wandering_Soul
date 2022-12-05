#ifndef ALONG_THE_WAY_NPS_H
#define ALONG_THE_WAY_NPS_H

#include "Entity.h"

class Nps: Entity{
public:
    Sprite sprite; Texture texture;
    float x, y;
    int health;
    bool life;
    Nps(Image &image, float X, float Y, int W, int H, String Name): Entity(image, X, Y, W, H, Name){
         x = X; y = Y; life = true; health = 1; name = Name;
         texture.loadFromImage(image);
         sprite.setTexture(texture);
         sprite.setTextureRect(IntRect(0, 0, w, h));
         health = 1;
    }
    FloatRect getRect(){ return FloatRect(x, y, w, h); }
    void Anim(){

        *time = clock.getElapsedTime().asMicroseconds();
        if (life) gameTime = gmTimeClock.getElapsedTime().asSeconds(); else { view.move(0.8, 0); }
        clock.restart();
        *time = *time / 800;

        if(name == "NPS1"){
            CurrentFrame += 0.008 * *time; if(CurrentFrame > 6) CurrentFrame -= 6;
            sprite.setTextureRect(IntRect(188 * int(CurrentFrame), 0, 155, 146));
        }
        if(name == "NPS2"){
            CurrentFrame += 0.004 * *time; if(CurrentFrame > 8) CurrentFrame -= 8;
            sprite.setTextureRect(IntRect(90 * int(CurrentFrame), 650, 88, 90));
        }
        if(name == "NPS3"){
            CurrentFrame += 0.006 * *time; if(CurrentFrame > 5) CurrentFrame -= 5;
            sprite.setTextureRect(IntRect(254 * int(CurrentFrame), 0, 225, 180));
        }
        if(name == "Guts"){
            CurrentFrame += 0.008 * *time; if(CurrentFrame > 10) CurrentFrame -= 10;
            sprite.setTextureRect(IntRect(0, 579 * int(CurrentFrame), 600, 578));
        }
    }
    void update(float time){
        Anim();
        sprite.setPosition(x, y);
        if(name == "NPS1"){
            sprite.setPosition(x, y);
            x += dx*time;
            if(health <= 0){ life = false; }
        }
        if(name == "NPS2"){
            sprite.setPosition(x, y);
            x += dx*time;
            if(health <= 0){ life = false;}
        }
    }
};
#endif //ALONG_THE_WAY_NPS_H
