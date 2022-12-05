#ifndef WANDERING_SOUL_OBJECT_CLASS_H
#define WANDERING_SOUL_OBJECT_CLASS_H

#include "Entity.h"

class object: Entity{
public:
    float x, y;
    Sprite sprite;
    bool life;
    int direction;
    int health, w, h;
    object(Image &image, float X, float Y, int W, int H, String Name): Entity(image, X, Y, W, H, Name){
        sprite.setTextureRect(IntRect(0, 0, w, h));
        if(name == "Bonfire"){  health = 10000;}
        if(name == "Purple_Fire"){ health = 120; }
        life = true;
        x = X; y = Y; w = W; h = H;life = true; name = Name;
        texture.loadFromImage(image);
        sprite.setTexture(texture);
        sprite.setTextureRect(IntRect(0, 0, w, h));
    }
    FloatRect getRect(){ return FloatRect(x, y, w, h); }
    void Anim(float time){
//        *time = clock.getElapsedTime().asMicroseconds();
//        clock.restart();
//        *time = *time / 600;
        if(name == "Bonfire"){
            CurrentFrame += 0.005 * time; if (CurrentFrame > 8) CurrentFrame -= 8;
            sprite.setTextureRect(IntRect(67 * int(CurrentFrame), 0, 70, 120));
        }
        if(name == "Purple_Fire"){
            CurrentFrame += 0.006 * time; if (CurrentFrame > 7) CurrentFrame -= 7;
            sprite.setTextureRect(IntRect(154 * int(CurrentFrame), 0, 145, 300));
        }
        if(name == "Anim_Text_BOSS"){ // анимация текста BOSS
            CurrentFrame += 0.005 * time; if (CurrentFrame > 10) CurrentFrame -= 10;
            sprite.setTextureRect(IntRect(600 * int(CurrentFrame), 0, 570, 150));
        }
        if(name == "Water"){
            CurrentFrame += 0.0015 * time; if (CurrentFrame > 2) CurrentFrame -= 2;
            sprite.setTextureRect((IntRect(412 * int(CurrentFrame), 0, 400, 200)));
        }
        if(name == "AttacBoss"){
            CurrentFrame += 0.008 * time; if (CurrentFrame > 7) CurrentFrame -= 7;
            sprite.setTextureRect((IntRect(850 * int(CurrentFrame), 0, 650, 1095)));
        }
        if(name == "Portal1"){
            CurrentFrame += 0.008 * time; if (CurrentFrame > 7) CurrentFrame -= 7;
            sprite.setTextureRect((IntRect(143 * int(CurrentFrame), 0, 140, 200)));
        }
        if(name == "Benzo"){
            switch (direction) {
                case 1:
                    CurrentFrame += 0.0095 * time; if (CurrentFrame > 5) CurrentFrame -= 5;
                    sprite.setTextureRect((IntRect(210 * int(CurrentFrame), 0, 210, 140)));
                    break;
                case 0:
                    CurrentFrame += 0.0095 * time; if (CurrentFrame > 5) CurrentFrame -= 5;
                    sprite.setTextureRect((IntRect(210 * int(CurrentFrame)+210, 0, -210, 140)));
                    break;
                case 2:
                    CurrentFrame += 0.0095 * time; if (CurrentFrame > 5) CurrentFrame -= 5;
                    sprite.setTextureRect((IntRect(210 * int(CurrentFrame), 0, 210, 140)));
                    break;
                case 3:
                    CurrentFrame += 0.0095 * time; if (CurrentFrame > 5) CurrentFrame -= 5;
                    sprite.setTextureRect((IntRect(210 * int(CurrentFrame)+210, 0, -210, 140)));
                    break;
            }
        }
        if(name == "Gun"){
            sprite.setOrigin(w/2, h/2);
            CurrentFrame += 0.008 * time; if (CurrentFrame > 1) CurrentFrame -= 1;
            sprite.setTextureRect((IntRect(182 * int(CurrentFrame)+182, 0, -182, 90)));
        }
    }

    void update(float time){
        Anim(time);
        sprite.setPosition(x, y);
        if(health <= 0){ life = false; }
        else{ life = true;}
    }

};
#endif //WANDERING_SOUL_OBJECT_CLASS_H
