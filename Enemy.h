#ifndef TEST_SFML_ENEMY_H
#define TEST_SFML_ENEMY_H

#include "Entity.h"

using namespace sf;
using namespace std;
// //////////////////////////////////////////////////// Класс врага ////////////////////////////////////////////////////////////
class Enemy :public Entity{
public:
    float distance = 0;
    bool RigLft, isDist;
    Enemy(Image &image, float X, float Y,int W,int H,String Name):Entity(image,X,Y,W,H,Name){
        if (name == "EasyEnemy"){ health = 100; dy = 0.5; }
        if (name == "EasyEnemy_"){ health = 100; dx = 0.5; }
        isDist = false;
        sprite.setOrigin(w/2, h/2);
        sprite.setTextureRect(IntRect(0,0,w,h));
    }
    FloatRect getRect(){ return FloatRect(x, y, w, h); }
    void Attack(FloatRect p_getRect, bool lvl1){
        if(lvl1)
            if(life)
                if(getRect().intersects(p_getRect)){ isAttackEnemy = true; }
    }
    void Taking_Damage(Sprite sp, bool lvl1){
        if(lvl1)
            if(life)
                if(sp.getGlobalBounds().intersects(getRect())){
                    health -= 20;
                    sprite.setColor(Color::Red);
                    speed = 20;
                }
    }
    void control(){
        *time = clock.getElapsedTime().asMicroseconds();
        clock.restart();
        *time = *time / 800;
        if(dx <= -0.1){ RigLft = true; }
        if(dx >= 0.1) { RigLft = false; }
        if(name == "EasyEnemy" || name == "EasyEnemy_"){
            if(RigLft){
                CurrentFrame += 0.005 * *time; if (CurrentFrame > 3) CurrentFrame -= 3;
                sprite.setTextureRect(IntRect(104 * int(CurrentFrame), 187, 96, 90));
            }
            else if(!RigLft){
                CurrentFrame += 0.005 * *time; if (CurrentFrame > 3) CurrentFrame -= 3;
                sprite.setTextureRect(IntRect(104 * int(CurrentFrame), 90, 96, 90));
            }
            else {
                CurrentFrame += 0.005 * *time; if (CurrentFrame > 3) CurrentFrame -= 3;
                sprite.setTextureRect(IntRect(104 * int(CurrentFrame), 90, 96, 90));
            }
        }
    }
    void checkCollisionWithMap(float Dx, float Dy)//ф ция проверки столкновений с картой
    {
        for (int i = y / 48; i < (y + h) / 48; i++)//проходимся по элементам карты
            for (int j = x / 48; j < (x + w) / 48; j++)
            {
                if (TileLVL[i][j] == '0' || TileLVL[i][j] == '1')
                {
                    if (Dy>0){ y = y - 1; dy = -0.1;  sprite.setScale(-1, 1);}//по Y вниз=>идем в пол(стоим на месте) или падаем. В этот момент надо вытолкнуть персонажа и поставить его на землю, при этом говорим что мы на земле тем самым снова можем прыгать
                    if (Dy<0){ y = y + 1; dy = 0.1; sprite.setScale(-1, 1);}//столкновение с верхними краями карты(может и не пригодиться)
                    if (Dx>0){ x = x - 1; dx = -0.1;  sprite.setScale(-1, 1);}//с правым краем карты
                    if (Dx<0){ x = x + 1; dx = 0.1; sprite.setScale(-1, 1);}// с левым краем карты
                }
                if(y < 1){  y = y + 0.5;}
                if(x < 1){  x = x + 0.5;}
                if(y > 1864){ y = y - 0.5;}
                if(x > 4760){ x = x - 0.5;}
            }
    }
    void going(float eX, float eY, CircleShape shape){
        distance = ((x - eX) * (x - eX) + (y - eY)*(y - eY));
        if(shape.getGlobalBounds().intersects(getRect())){ isDist = true; }
        if(isDist && life){
            if(name == "EasyEnemy" || name == "EasyEnemy_"){
                if(distance > 2){
                    dx += 0.03* *time * (eX - x) / distance;
                    dy += 0.03* *time * (eY - y) / distance;
                }
            }
        }
    }
    void update(float time, float eX, float eY, CircleShape shape, bool isLvl1)
    {
        going(eX, eY, shape);
        if(health <= 0){ life = false; }
        sprite.setPosition(x + w / 2, y + h / 2);

        if (name == "EasyEnemy"){//для персонажа с таким именем логика будет тако
            checkCollisionWithMap(0, dy); checkCollisionWithMap(dx, 0);
            if(isDist){ x += dx*time; }
            y += dy*time;
        }
        if(name == "EasyEnemy_"){
            checkCollisionWithMap(dx, 0); checkCollisionWithMap(0, dy);
            if(isDist){ y += dy*time; }
            x += dx*time;
        }
    }
};

#endif //TEST_SFML_ENEMY_H
