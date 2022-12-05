#ifndef WANDERING_SOULPLAYER_H
#define WANDERING_SOULPLAYER_H

#include "Entity.h"

using namespace sf;
using namespace std;

// ///////////////////////////////////////////////////// class Player //////////////////////////////////////////////////////
class Player: Entity {
public:
    float x,y;
    int plaerSoul, health; // новая переменая отвечающая за жизнь
    bool life, toroSpeed,sword_pt, isSoul, isLVL1, isLVLStarting, isGameMode;
    bool ModeBur, isBur, isChanSaw, isGun;
    int StonesCollected;
    int modeSwordAndChanSaw = 0;
    int inventory;
    bool map_to_lvl3, stop = true;
    Sprite sprite;
    enum { left, right, up, down, stop_, stay} state; //добавляем тип перечисления - состояние объекта
    Player(Image &image, float X, float Y, int W, int H, String Name): Entity(image, X, Y, W, H, Name){
        toroSpeed = false; sword_pt = false; isLVL1 = false; isLVLStarting = true;
        map_to_lvl3 = false; isChanSaw = false; modeSwordAndChanSaw = 0;
        isSoul = false; isGameMode = false; isBur = false; name = Name; ModeBur = false;
        isGun = false;
        plaerSoul = 0; health = 120; life = true;
        state = stay; x = X; y = Y;
        inventory = 4; StonesCollected = 0;
        sprite.setScale(0.4f, 0.4f);
        sprite.setTexture(texture);
        sprite.setTextureRect(IntRect(0, 0, w, h));
        sprite.setOrigin(w/2,h/2);

        *time = clock.getElapsedTime().asMicroseconds();
        if (life) gameTime = gmTimeClock.getElapsedTime().asSeconds(); else { view.move(0.8, 0); }
        clock.restart();
        *time = *time / 700;
    }
    FloatRect getRect(){ return FloatRect(x, y, w, h);  }
    void anim(){
        if(life){
            if(name == "Player_new"){
                if(sword_pt && modeSwordAndChanSaw == 0){
                    if(Mouse::isButtonPressed(sf::Mouse::Left)){
                        if(state == right){
                            CurrentFrame += 0.008 * *time; if(CurrentFrame > 10) CurrentFrame -= 10;
                            sprite.setTextureRect(IntRect(250 * int(CurrentFrame), 755, 240, 244));
                        }
                        else if(state == left){
                            CurrentFrame += 0.008 * *time; if(CurrentFrame > 10) CurrentFrame -= 10;
                            sprite.setTextureRect(IntRect(247 * int(CurrentFrame), 1020, 222, 244));
                        } else{
                            CurrentFrame += 0.008 * *time; if(CurrentFrame > 10) CurrentFrame -= 10;
                            sprite.setTextureRect(IntRect(250 * int(CurrentFrame), 755, 240, 244));
                        }
                        mous = false; stop = false;
                    }
                }
                if(mous){
                    if(!stop){
                        if(state == left){
                            CurrentFrame += 0.005 * *time; if (CurrentFrame > 10) CurrentFrame -= 10;
                            sprite.setTextureRect(IntRect(246 * int(CurrentFrame)+165, 256, -168, 262));
                        }
                        if(state == right){
                            CurrentFrame += 0.005 * *time; if (CurrentFrame > 10) CurrentFrame -= 10;
                            sprite.setTextureRect(IntRect(246 * int(CurrentFrame), 256, 168, 262));
                        }
                        if(state == up){
                            CurrentFrame += 0.005 * *time; if (CurrentFrame > 10) CurrentFrame -= 10;
                            sprite.setTextureRect(IntRect(246 * int(CurrentFrame), 256, 168, 262));
                        }
                        if(state == down){
                            CurrentFrame += 0.005 * *time; if (CurrentFrame > 10) CurrentFrame -= 10;
                            sprite.setTextureRect(IntRect(246 * int(CurrentFrame)+165, 256, -168, 262));
                        }
                    }
                }
                if(stop){
                    if(state == left){
                        CurrentFrame += 0.005 * *time; if (CurrentFrame > 10) CurrentFrame -= 10;
                        sprite.setTextureRect(IntRect(246 * int(CurrentFrame)+165, 0, -168, 264));
                    }
                    else if(state == right){
                        CurrentFrame += 0.005 * *time; if (CurrentFrame > 10) CurrentFrame -= 10;
                        sprite.setTextureRect(IntRect(246 * int(CurrentFrame), 0, 168, 264));
                    }
                    else if(state != right && state != left){
                        CurrentFrame += 0.005 * *time; if (CurrentFrame > 10) CurrentFrame -= 10;
                        sprite.setTextureRect(IntRect(246 * int(CurrentFrame)+165, 0, -168, 264));
                    }
                }
            }
        } else { sprite.setTextureRect(IntRect(0, 524, 168, 240)); }
    }
    void control() {
        if (life) {
            stop = true; mous = true;
            if(mous) {
                if (Keyboard::isKeyPressed(Keyboard::Left) || Keyboard::isKeyPressed(Keyboard::A)) {
                    state = left;speed = 0.12; stop = false;
                    if(toroSpeed){ speed = 0.16;}
                }
                if (Keyboard::isKeyPressed(Keyboard::Right) || Keyboard::isKeyPressed(Keyboard::D)) {
                    state = right;speed = 0.12; stop = false;
                    if(toroSpeed){ speed = 0.16;}
                }
                if (Keyboard::isKeyPressed(Keyboard::Up)  || Keyboard::isKeyPressed(Keyboard::W)) {
                    state = up; speed = 0.12; stop = false;
                    if(toroSpeed){ speed = 0.16;}
                }
                if (Keyboard::isKeyPressed(Keyboard::Down) || Keyboard::isKeyPressed(Keyboard::S)) {
                    state = down; speed = 0.12; stop = false;
                    if(toroSpeed){ speed = 0.16;}
                }
            }
            anim();
        }
    }

    void update(float time) {
        control();//функция управления персонажем
        switch (state)//тут делаются различные действия в зависимости от состояния
        {
            case right: dx = speed; dy = 0;break;//состояние идти вправо
            case left: dx = -speed; dy = 0;break;//состояние идти влево
            case down: dy = speed; dx = 0;break; //состояние идти вниз
            case up:dy = -speed;dx = 0;break; //состояние идти вверх
            case stop_: break;
            case stay: break; // Состояние чего-то
        }
        speed = 0;
        x += dx * time; y += dy * time;
        sprite.setPosition(x,y);
        checkCollisionWithMap(); // вызываем функцию, отвечающую за взаимодействие с картой ф
        if(isGameMode){  life = true; speed = 0.2; isBur = true; sword_pt = true; toroSpeed = true;}
        else{ if (health <= 0){life = false;} }
        getPlayerCoordinateForView(x,y);
    }
    void checkCollisionWithMap() { // функция взаимодейстивия с картой
        for (int i = y/48; i < (y+h)/48; i++)//проходимся по тайликам, контактирующим с игроком, то есть по всем квадратикам размера 32*32, которые мы окрашивали в 9 уроке. про условия читайте ниже.
            for (int j = x/48; j<(x+w) / 48; j++)//икс делим на 32, тем самым получаем левый квадратик, с которым персонаж соприкасается. (он ведь больше размера 32*32, поэтому может одновременно стоять на нескольких квадратах). А j<(x + w) / 32 - условие ограничения координат по иксу. то есть координата самого правого квадрата, который соприкасается с персонажем. таким образом идем в цикле слева направо по иксу, проходя по от левого квадрата (соприкасающегося с героем), до правого квадрата (соприкасающегося с героем)
            {
                if(!isGameMode){
                    if(isLVLStarting){
                        if (LVLStarting[i][j] == '0') {
                            if (dy > 0) { y = i * 48 - h; }// если мы шли вниз,
                            if (dy < 0) {y = i * 48 + 48;}//аналогично с ходьбой вверх. dy<0, значит мы идем вверх (вспоминаем координаты паинта)}
                            if (dx > 0) {x = j * 48 - w;}//если идем вправо, то координата Х равна стена (символ 0) минус ширина персонажа}
                            if (dx < 0) { x = j * 48 + 48; }//аналогично идем влево}
                        }
                    }

                        if(isLVL1){
                            if (TileLVL[i][j] == '0'|| TileLVL[i][j] == '1'|| TileLVL[i][j] == 'D') {
                                if (dy > 0) { y = i * 48 - h; }// если мы шли вниз,
                                if (dy < 0) {y = i * 48 + 48;}//аналогично с ходьбой вверх. dy<0, значит мы идем вверх (вспоминаем координаты паинта)}
                                if (dx > 0) {x = j * 48 - w;}//если идем вправо, то координата Х равна стена (символ 0) минус ширина персонажа}
                                if (dx < 0) { x = j * 48 + 48; }//аналогично идем влево}
                            }
                            if(TileLVL[i][j] == 'i'){ if(inventory > 0){ sword_pt = true; inventory--; TileLVL[i][j] = ' ';} }
                            if(TileLVL[i][j] == 'B'){ if(inventory > 0){ isBur = true; inventory--; TileLVL[i][j] = ' ';} }
                            if(TileLVL[i][j] == 'Q'){ ModeBur = true; TileLVL[i][j] = ' '; }
                            if (TileLVL[i][j] == 's') { //если символ равен 's' (камень)
                                plaerSoul++; TileLVL[i][j] = ' ';
                                if(plaerSoul >= 10){x = 1500; y = 530; isSoul = true;}
                            }
                            if (TileLVL[i][j] == 'f') { health -= 20; TileLVL[i][j] = ' '; }
                            if (health < 120) { if (TileLVL[i][j] == 'h') { health += 20; TileLVL[i][j] = ' '; } }
                        }

                    if(!isLVLStarting || !isSoul){
                        if(y < 1){  y = y + 1;}
                        if(x < 1){  x = x + 1;}
                        if(y > 1864){ y = y - 1;}
                        if(x > 4760){ x = x - 1;}
                    }

                    if (isSoul && !map_to_lvl3 && !isLVLStarting){
                        if ((TileLVL1[i][j] == '3') || (TileLVL1[i][j] == '2')) {
                            if (dy > 0) { y = i * 48 - h; }// если мы шли вниз,
                            if (dy < 0) {y = i * 48 + 48;}//аналогично с ходьбой вверх. dy<0, значит мы идем вверх (вспоминаем координаты паинта)}
                            if (dx > 0) {x = j * 48 - w;}//если идем вправо, то координата Х равна стена (символ 0) минус ширина персонажа}
                            if (dx < 0) { x = j * 48 + 48; }//аналогично идем влево}
                        }
                        if(TileLVL1[i][j] == 'z'){ toroSpeed = true; TileLVL1[i][j] = '5'; }
                        if(TileLVL1[i][j] == 'A'){ if(inventory > 0){ isChanSaw = true; inventory--; TileLVL1[i][j] = '.';}}
                        if(health < 120){ if(TileLVL1[i][j] == 's'){ health += 20; TileLVL1[i][j] = '.'; }}
                    }
                    if(map_to_lvl3){
                        if(TileLVL2[i][j] == 'I'){ health -= 20; TileLVL2[i][j] = ' ';}
                        if(TileLVL2[i][j] == 'G'){if(inventory > 0){ isGun = true;  inventory--; TileLVL2[i][j] = ' ';}}
                        if (TileLVL2[i][j] == '0' || TileLVL2[i][j] == '1') {
                            if (dy > 0) { y = i * 48 - h; }// если мы шли вниз,
                            if (dy < 0) {y = i * 48 + 48;}//аналогично с ходьбой вверх. dy<0, значит мы идем вверх (вспоминаем координаты паинта)}
                            if (dx > 0) {x = j * 48 - w;}//если идем вправо, то координата Х равна стена (символ 0) минус ширина персонажа}
                            if (dx < 0) { x = j * 48 + 48; }//аналогично идем влево}
                        }
                    }
                }
            }
    }
};
#endif