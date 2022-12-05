#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <ctime>
#include <vector>
#include <list>
#include <iostream>
#include <fstream>
#include "view.h" // подключили код с камерой
#include "Map.h" //подключили код с картой
#include "Object_Class .h"
#include "Enemy.h"
#include "Player.h"
#include "Boss.h"
#include "Nps.h"
#include "HP.h"
#include "mission.h"
#include "Menu.h"
#include "isBook.h"
#include "Particle.h"
#include "LifeBar.h"
#include "Radius.h"
#include "Smart_Pointer.h"
#include "Bullet.h"
#include " EventFunction.h"
#include "TextAndImages.h"
#include "MusicSound.h"

using namespace sf;
using namespace std;

bool startGame(){
    screen();
    Load_image();
    music_Sound();
    RenderWindow window(VideoMode(Width, Height), "\"Wandering Soul - Betas\"", Style::Fullscreen);
    view.reset(FloatRect(0, 0, Width, Height));
    Text_Settings(window); Set_Screen(window);
    menu(window);
    Screensaver(window);
    window.setFramerateLimit(250);

    music_lvl_1.play();
    sf::CircleShape shape(350.f);

    vector<string>enem;
    enem.push_back("EasyEnemy");
    enem.push_back("EasyEnemy_");

    list<Bullet*>::iterator itBul;
    list<Bullet*>bul;
    list<Enemy*>::iterator itEn;//итератор чтобы проходить по эл-там списка
    list<Enemy*>en; //создаю список, сюда буду кидать объекты.например врагов.
    en.push_back(new Enemy(easyEnemyImage, 500, 1200, 85, 86, enem[1]));
    en.push_back(new Enemy(easyEnemyImage, 550, 1120, 85, 86, enem[0]));
    en.push_back(new Enemy(easyEnemyImage, 500, 1600, 85, 86, enem[1]));
    en.push_back(new Enemy(easyEnemyImage, 2000, 1200, 85, 86, enem[0]));
    en.push_back(new Enemy(easyEnemyImage, 3100, 500, 85, 86, enem[1]));
    en.push_back(new Enemy(easyEnemyImage, 3000, 500, 85, 86, enem[0]));
    en.push_back(new Enemy(easyEnemyImage, 3100, 1200, 85, 86, enem[1]));
    en.push_back(new Enemy(easyEnemyImage, 3100, 1200, 85, 86, enem[0]));
    en.push_back(new Enemy(easyEnemyImage, 3100, 1600, 85, 86, enem[1]));


    Radius Radius_At(Radius_image, 0,0, 150, 150, "Radius");
    object Fire(Image_Fire, 700, 230, 40, 40, "Bonfire");
    object Attack(AttacaImage, 700, 230, 600, 1095, "AttacBoss");
    object GHOST_HAZE(image_Anim_BOSS_TEXT, 200, 200, 570, 150, "Anim_Text_BOSS");
    object Purple_Fire(image_purple_fire, 700, 400, 120, 300, "Purple_Fire");
    object Water(Water_image, 608, 1150, 400, 200, "Water");
    object Portal(Portal_image, 600, 200, 142,200, "Portal1");
    object CHAN_SAW(ChanSawImage, 0, 0, 140, 210, "Benzo");
    object Gun_Sanberst(ImageGunSan, 0, 0, 182, 90, "Gun");
    Player p(image887, 2485, 762, 60.0, 86.0, "Player_new");
    Nps nps1(NPS1Image, 1821, 328, 140 , 140, "NPS1");
    Nps nps2(NPS2Image, 1200, 620, 70, 80, "NPS2");
    Nps nps3(NPS3Image, 2125, 1064, 230, 180, "NPS3");
    BossEnemy Ghost_Normal(Boss_Ghost, 1550, 500, 100.0, 100.0, "Ghost_normal");

    LifeBar lifeBarBoss;
    ParticleSystem particles(100);
    Purple_Fire.sprite.setScale(0.8f, 0.8f);
    nps1.sprite.setScale(1.0f, 1.0f);
    nps2.sprite.setScale(1.2f, 1.2f);
    Radius_At.sprite.setScale(1.4f, 1.4f);
    CHAN_SAW.sprite.setScale(0.8f, 0.8f);


    Clock clock; Clock gameTimeClock; Clock cl;
    Time elapsed;
    int gameTime = 0,num = 0;
    bool invent = true, npsTrueAndFalse = true;
    bool isBook = true;
    int break_Fire = 0;
    int xMap3 = 4212, yMap3 = 300;
    float dX = 0; float dY = 0;
    int randomNumber = 0;
    int moveTimer = 0, moveTimeAt = 0, TimerTxt = 0, TimerEnemy = 0;
    int BulTimer = 0;
    int createObjectForMapTimer = 0; // таймер рандома
    int ClickNps[3];
    int tempX = 0; int tempY = 0; int distance = 0; bool isMove = false;
    bool isLifeBoss = true;
    bool isBurBreak = true;
    while (window.isOpen()){
        IsLVL(p.isLVLStarting, p.isLVL1, p.isSoul, p.map_to_lvl3);
        SmartPointer<float>time = new float;
        *time = clock.getElapsedTime().asMicroseconds();
        if (p.life) gameTime = gameTimeClock.getElapsedTime().asSeconds(); else { view.move(0.8, 0); }

        elapsed = cl.restart();
        clock.restart();
        *time = *time / 500;
        ostringstream tiss, gameTimeString,plaerSoulsString; // объевляем переменую;
        ostringstream Message_Nps;
        Event event;
        BulTimer += *time;
        Vector2<float> mouse;
        Vector2i localPostion = Mouse::getPosition(window);
        Vector2f  pos = window.mapPixelToCoords(localPostion);
        dX = pos.x - p.x; dY = pos.y - p.y;
        float rotation = (atan2(dY, dX)) * 180 / 3.14159265;

        while (window.pollEvent(event)) {
            Inventory(event, invent, pos); // Open inventory
            OpenBook(event, isBook); // Opne Book
            modeBur(event, p.ModeBur, isBurBreak);
            for(itEn = en.begin(); itEn != en.end(); itEn++){
                for(itBul = bul.begin(); itBul != bul.end(); itBul++){
                    (*itEn)->Taking_Damage((*itBul)->sprite, p.isLVL1);
                }
            }

            if(!Ghost_Normal.life){
                Music_FightBoss.stop();
                music_lvl_2.stop();
                Ghost_Normal.dx = 0;
            }
            if(Portal.getRect().intersects(p.getRect())){
                if(p.map_to_lvl3 && Ghost_Normal.isWelcome){
                    p.isLVLStarting = true; p.isSoul = false; p.map_to_lvl3 = false; p.isLVL1 = false;
                    Music_LvL1Start.stop(); music_lvl_1.play();
                }
            }
            if(p.isSoul){
                if((kolodec.sprite.getGlobalBounds().contains(p.x, p.y))){
                    p.map_to_lvl3 = true; p.isSoul = false; p.isLVL1 = false;
                }
            }
            if(p.life){
                if(break_Fire >= 5){
                    if(Attack.sprite.getGlobalBounds().contains(p.x, p.y)){
                        if(moveTimeAt > 3000){ p.health -= 20; moveTimeAt = 0; }
                    }
                }
                if(!p.isLVLStarting && !p.map_to_lvl3){
                    if(!p.isSoul){
                        for(itEn = en.begin(); itEn != en.end(); itEn++){ (*itEn)->Attack(p.getRect(), p.isLVL1); }
                        if(isAttackEnemy){ p.health -= 20; }
                    }
                }
                for(int i = pos.y/48; i < (pos.y + 1)/48; i++)
                    for(int j = pos.x/48; j < (pos.x + 1)/48; j++){
                        if(event.type == Event::MouseButtonPressed)
                            if(event.key.code == Mouse::Right && p.isBur){
                                if(isBurBreak){ if(TileLVL[i][j] == '1' || TileLVL[i][j] == '0'){ TileLVL[i][j] = ' '; p.StonesCollected++; }}
                                else if(!isBurBreak && p.StonesCollected > 0){ if(TileLVL[i][j] == ' '){ TileLVL[i][j] = '1'; p.StonesCollected--; }}
                            }
                    }
            }

            if(event.type == sf::Event::Closed || event.key.code == sf::Keyboard::Escape)window.close();

            if(event.type == sf::Event::MouseButtonPressed) {
                if(p.life){
                    if (event.key.code == Mouse::Left)
                    {
                        if(p.isGun && p.modeSwordAndChanSaw == 2)
                            if(BulTimer > 4000){
                                bul.push_back(new Bullet(Bbullet, Gun_Sanberst.x, Gun_Sanberst.y, 16, 16, "Bullet", p.state));
                                isMove = true;
                                tempX = pos.x; tempY = pos.y;
                                SoundUseGun.play();
                                BulTimer = 0;
                            }
                        //
                        if(break_Fire >= 10){
                            for(itBul = bul.begin(); itBul != bul.end(); itBul++){
                                if((*itBul)->getRect().intersects(Ghost_Normal.getRect()) && p.isGun){
                                    Ghost_Normal.health -= 20;
                                    (*itBul)->life = false;
                                }
                            }
                            if(Radius_At.sprite.getGlobalBounds().intersects(Ghost_Normal.getRect())){
                                if(p.isChanSaw || p.sword_pt)Ghost_Normal.health -= 20;
                            }
                        }
                        //
                        if(p.isChanSaw || p.isGun || p.sword_pt)
                            for(itEn = en.begin(); itEn != en.end(); itEn++){
                                (*itEn)->Taking_Damage(Radius_At.sprite,p.isLVL1);
                            }
                    }
                    if(Ghost_Normal.isBoss && p.isBur){
                        if(event.key.code == Mouse::Right){
                            if(Purple_Fire.sprite.getGlobalBounds().contains(pos.x, pos.y)){
                                Purple_Fire.health -= 20;
                                if(Purple_Fire.health <= 0 && break_Fire <= 10){
                                    break_Fire += 1; Purple_Fire.health = 120;
                                }
                                if(break_Fire == 5){ Ghost_Normal.dx = 0.5; }
                            }
                        }
                    }
                    if(event.key.code == Mouse::Left && Fire.sprite.getGlobalBounds().contains(pos.x, pos.y)){
                        if(Ghost_Normal.life && p.isLVL1 || p.isLVLStarting){
                            p.x = 600; p.y = 400;
                            p.isLVLStarting = false; p.isSoul = false;
                            Perem_fire.play();
                        }
                    }
                    if(Ghost_Normal.sprite.getGlobalBounds().contains(pos.x, pos.y) && p.map_to_lvl3){
                        Ghost_Normal.isBoss = true;
                        if(!Ghost_Normal.isClk && !p.isSoul){ Music_FightBoss.play(); }
                        Ghost_Normal.isClk = true;
                    }
                }
            }
            if (event.type == Event::KeyPressed){
                if(event.key.code == Keyboard::F){
                    if(Radius_At.sprite.getGlobalBounds().intersects(nps1.getRect())){
                        switch (npsTrueAndFalse){
                            case true:
                                nps_txt1.text.setPosition(nps1.x + 100, nps1.y - 55);
                                npsTrueAndFalse = false; ClickNps[0]++;
                                nps_txt2.text.setString(" "); nps_txt3.text.setString(" ");
                                if(p.isLVLStarting && !p.isLVL1 && !p.map_to_lvl3 && !p.isSoul){
                                    Message_Nps << getNpsMessage(ClickNps[0], 1, "Nps1");
                                    nps_txt1.text.setString(Message_Nps.str());
                                    if(ClickNps[0] >= 6){ ClickNps[0] = 0;} pressed_nps.play();
                                }
                                if(p.isLVL1 && !p.map_to_lvl3 && !p.isSoul && !p.isLVLStarting){
                                    Message_Nps << getNpsMessage(ClickNps[0], 2, "Nps1");
                                    nps_txt1.text.setString((Message_Nps.str()));
                                    if(ClickNps[0] >= 6){ ClickNps[0] = 0;} pressed_nps.play();
                                }
                                if(p.isSoul && !p.map_to_lvl3){
                                    Message_Nps << getNpsMessage(ClickNps[0], 3 , "Nps1");
                                    nps_txt1.text.setString(Message_Nps.str());
                                    if(ClickNps[0] >= 7){ClickNps[0] = 0;} pressed_nps.play();
                                } break;
                                case false: nps_txt1.text.setString(" "); npsTrueAndFalse = true; break;
                        }
                    }
                    if(Radius_At.sprite.getGlobalBounds().intersects(nps2.getRect())){
                        if(!p.map_to_lvl3 && !p.isSoul){
                            switch (npsTrueAndFalse){
                                case true:
                                    nps_txt2.text.setPosition(nps2.x + 50, nps2.y);
                                    npsTrueAndFalse = false; ClickNps[1]++;
                                    nps_txt1.text.setString(" "); nps_txt3.text.setString(" ");
                                    if(p.isLVL1){
                                        Message_Nps << getNpsMessage(ClickNps[1], 1, "Nps2");
                                        nps_txt2.text.setString(Message_Nps.str());
                                        if(ClickNps[1] >= 3){ ClickNps[1] = 0;} pressed_nps.play();
                                    }
                                    if(p.isLVLStarting){
                                        Message_Nps << getNpsMessage(ClickNps[1], 2, "Nps2");
                                        nps_txt2.text.setString(Message_Nps.str());
                                        if(ClickNps[1] >= 3){ ClickNps[1] = 0;} pressed_nps.play();
                                    } break;
                                    case false: nps_txt2.text.setString(" "); npsTrueAndFalse = true; break;}
                        }
                    }
                    if(Radius_At.sprite.getGlobalBounds().intersects(nps3.getRect())){
                        if(Ghost_Normal.isWelcome){
                            switch (npsTrueAndFalse){
                                case true:
                                    nps_txt3.text.setPosition(nps3.x - 100, nps3.y - 60);
                                    npsTrueAndFalse = false; ClickNps[2]++;
                                    nps_txt2.text.setString(" "); nps_txt1.text.setString(" ");
                                    if(p.isLVLStarting){
                                        Message_Nps << getNpsMessage(ClickNps[2], 1, "Nps3");
                                        nps_txt3.text.setString(Message_Nps.str());
                                        if(ClickNps[2] >= 3){ ClickNps[2] = 0;} pressed_nps.play();
                                    } break;
                                    case false: nps_txt3.text.setString(" "); npsTrueAndFalse = true; break;
                            }
                        }
                    }
                }
            }
        }

        moveTimeAt += *time;
        Sprite_Mouse.sprite.setPosition(pos.x - 5, pos.y - 2);
        if(!p.stop){ // частитцы при ходьбе
            mouse.x = p.x + 23; mouse.y = p.y + 86;
            particles.setEmitter(mouse); particles.update(elapsed);
        }
        if(!Ghost_Normal.life){ Ghost_Normal.isWelcome = true; }

        if(p.isLVL1){ // Движение врагов
             for(itEn = en.begin(); itEn != en.end(); itEn++){
                 (*itEn)->control();
                 (*itEn)->update(*time, p.x, p.y,shape, p.isLVL1);
             }
        }
        if (p.life) {
            p.control();
            sound_dead.play();
            if(p.sword_pt && p.modeSwordAndChanSaw == 0)
                if (Mouse::isButtonPressed(Mouse::Left))
                    soud.play();
            if(p.isBur)
                if(Mouse::isButtonPressed(Mouse::Right))
                    sound_Bur.play();
            if(p.isChanSaw && p.modeSwordAndChanSaw == 1)
                if(Mouse::isButtonPressed(Mouse::Left))
                    soundChanSaw.play();
        }
        if(!Ghost_Normal.life){ isLifeBoss = false;}

        nps1.update(*time); nps2.update(*time); nps3.update(*time);
        Fire.update(*time); Purple_Fire.update(*time);
        p.update(*time); Attack.update(*time);
        Water.update(*time); Portal.update(*time); Radius_At.update();
        Ghost_Normal.update(*time); lifeBarBoss.update(Ghost_Normal.health);
        CHAN_SAW.update(*time); Gun_Sanberst.update(*time);
        window.setView(view); // оживляем камеру в окне sfm

        if(p.isLVL1){ window.clear(Color(65 ,41, 0)); }
        if(p.isSoul){ window.clear(Color(0, 157, 63)); }
        if(p.isLVLStarting){ window.clear(Color(0, 139, 160)); }
        if(p.map_to_lvl3){ Ghost_Normal.isLvL3 = true; window.clear(Color(10,10,10)); }
        kolodec.sprite.setPosition(1000, 1200);

        if(p.isLVLStarting && !p.isSoul && !p.isLVL1){
            nps3.x = 2050; nps3.y = 1000;
            nps1.x = 2100; nps1.y = 550;
            Music_LvL1Start.stop();
            lvl_starting(window, p.isLVLStarting);
            window.draw(Water.sprite);
        }
        if(p.isLVL1){
            lvl_drawing_1(window, p.isLVL1);
            for (itEn = en.begin(); itEn != en.end(); itEn++) {
                if ((*itEn)->life) { window.draw((*itEn)->sprite); }
            }
        }
        else{
            if(!p.isLVLStarting&&!p.isSoul){ Music_LvL1Start.play(); music_lvl_1.stop(); }
        }
        if(!p.isLVLStarting && !p.map_to_lvl3){
            p.isLVL1 = true;
            switch (p.isSoul){
                case true:
                    p.isLVL1 = false;
                    nps1.x = 2930; nps1.y = 500;
                    music_lvl_1.stop();
                    Music_LvL1Start.stop();
                    lvl_drawing_2(window, p.isSoul);
                    window.draw(kolodec.sprite); break;
                case false: music_lvl_2.play(); break;
            }
        }

        if(p.map_to_lvl3){
            GHOST_HAZE.update(*time);
            if(scrn == 1) GHOST_HAZE.sprite.setPosition(view.getCenter().x-250, view.getCenter().y-350);
            if(scrn == 3) GHOST_HAZE.sprite.setPosition(view.getCenter().x - 250, view.getCenter().y - 400);
            if(!Ghost_Normal.isBoss)textBossOfHazeMassage.text.setString("Click on the boss\n to start the fight");
            else{
                if(TimerTxt < 3000){
                    textBossOfHazeMassage.text.setString("Break purple lights");
                    TimerTxt += *time;
                }
                randomNumber = rand();
                if(Ghost_Normal.life){
                    if(Ghost_Normal.sprite.getGlobalBounds().contains(p.x, p.y)){ p.health -= 20; }
                    if(break_Fire >= 5){
                        moveTimer += *time;
                        if (moveTimer>3000){
                            yMap3 =(randomNumber % 500) + 50; xMap3 = (randomNumber % 4212) + 1;
                            udar_molnii.play(); moveTimer = 0;
                        }
                    } if(break_Fire < 5){
                        createObjectForMapTimer += *time;//наращиваем таймер
                        if (createObjectForMapTimer>3000){
                            randomMapGenerate(break_Fire);//генерация случ камней
                            createObjectForMapTimer = 0;//обнуляем таймер
                        }
                    }
                }
            }
            Attack.sprite.setPosition(xMap3, yMap3);
            lvl_drawing_3(window, p.map_to_lvl3); //Music_FightBoss.play();
        }
//                           Позиция возле игрока
        Gun_Sanberst.sprite.setScale(0.3f, 0.3f);
        Gun_Sanberst.x = p.x + 15; Gun_Sanberst.y = p.y + 50;
        Gun_Sanberst.sprite.setRotation(rotation);

        for(itBul = bul.begin(); itBul != bul.end(); itBul++){ (*itBul)->dist(tempX, tempY,p.x, p.y, *time, isMove); }
        Radius_At.sprite.setPosition(p.x + 26, p.y + 32);
        Bur.sprite.setPosition(p.x, p.y + 40);
        Bur2.sprite.setPosition(p.x, p.y + 40);
        shape.setPosition(p.x - 290, p.y - 290);
        CHAN_SAW.x = p.x; CHAN_SAW.y = p.y; CHAN_SAW.direction = p.state;
        if(CHAN_SAW.direction == 0 || CHAN_SAW.direction == 3) CHAN_SAW.x = p.x - 120;

//                         Текста и картинки
        Set_Screen(window);
        gameTimeString << gameTime;
        plaerSoulsString << p.plaerSoul; // занесли в неё число очков, то есть формулируем строку


        text_gmTime.text.setString("\nTime: " + gameTimeString.str());
        text_souls.text.setString("Soul collected: " + plaerSoulsString.str()); // задаём строку тексту
        text_dead.text.setString("You Dead");
        control.text.setString("Control \nW - Forward \nS - Back \nA - Left \nD - Right \nEscape - close \nTab - Mission & bestiary\nE - Inventory\nMouse_Left - Damage\nMouse_Right - Bur");
        text_toro.text.setString("Toro Speed");
        restart.sprite.setColor(Color::White); num = 0;

// ///////////////////////////////////////////////////////////////////
        Arrangement(break_Fire, Purple_Fire.sprite);

        if (invent) {
            open.sprite.setTextureRect(IntRect(0, 0, 48, 48));
            window.draw(open.sprite);
        }
        else {
            window.draw(inventoreOpen.sprite); window.draw(open.sprite);
            if(Mouse::isButtonPressed(Mouse::Left)){
                if(ChanInvent.sprite.getGlobalBounds().contains(pos.x, pos.y))p.modeSwordAndChanSaw = 1;
                if(mech.sprite.getGlobalBounds().contains(pos.x, pos.y))p.modeSwordAndChanSaw = 0;
                if(gunInvent.sprite.getGlobalBounds().contains(pos.x, pos.y))p.modeSwordAndChanSaw = 2;
            }
            if(p.sword_pt)window.draw(mech.sprite);
            if(p.isChanSaw) window.draw(ChanInvent.sprite);
            if(p.isBur)window.draw(Bur_.sprite);
            if(p.isGun)window.draw(gunInvent.sprite);
        }
        if(!npsTrueAndFalse){
            if(!p.map_to_lvl3) window.draw(nps_txt1.text);
            if(p.isLVLStarting || p.isLVL1) window.draw(nps_txt2.text);
            window.draw(nps_txt3.text);
        }
        if (gameTime < 12) window.draw(control.text);
        if(p.isSoul)
            if(timer(10))
                window.draw(Flower_txt.sprite);
        if(p.toroSpeed){
            window.draw(toro_1.sprite);
            if(timer_1(10)) window.draw(text_toro.text);
        }
        if (!p.life) {
            isAttackEnemy = false;
            Music_FightBoss.stop();
            if(restart.sprite.getGlobalBounds().contains(pos.x, pos.y)){num = 1; restart.sprite.setColor(Color::Blue);}
            if (Mouse::isButtonPressed(Mouse::Left)) { if(num == 1)return true; }
            music_lvl_1.stop(); music_lvl_2.stop();
            window.draw(restart.sprite); window.draw(text_dead.text);
        }
        if(nps1.life){ if(!p.map_to_lvl3)window.draw(nps1.sprite); }

        if(nps2.life){ if(!p.isSoul && !p.map_to_lvl3)window.draw(nps2.sprite); }
        if(!p.stop)window.draw(particles);

        if(p.map_to_lvl3){
            music_lvl_2.stop();
            if(Purple_Fire.life)window.draw(Purple_Fire.sprite);
            if(!Ghost_Normal.isBoss) window.draw(GHOST_HAZE.sprite);
            window.draw(textBossOfHazeMassage.text);
        }
        if(p.isLVLStarting){if(Ghost_Normal.isWelcome)window.draw(nps3.sprite);}
        if(p.isLVL1 || p.isLVLStarting)
            if(Ghost_Normal.life)
                window.draw(Fire.sprite);
        window.draw(Education.sprite);
        window.draw(p.sprite);
        Progres_bar(window, p.health);
        if(p.isGun && p.modeSwordAndChanSaw == 2){ if(p.life)window.draw(Gun_Sanberst.sprite); }
        if(p.isChanSaw && p.modeSwordAndChanSaw == 1){
            if(p.life)
                if(Mouse::isButtonPressed(Mouse::Left))
                    window.draw(CHAN_SAW.sprite);
        }
        if(p.isLVL1)Location_of_Objects_LVL1(window, p.isLVL1);
        if(p.map_to_lvl3){
            if(Ghost_Normal.isWelcome){ window.draw(Portal.sprite); }
            window.draw(Ghost_Normal.sprite);
            if(Ghost_Normal.isBoss){
                lifeBarBoss.draw(window, scrn);
                if(break_Fire >= 5 && Ghost_Normal.life){ window.draw(Attack.sprite); }
            }
        }
        if(p.life && p.isBur){
            if(Mouse::isButtonPressed(Mouse::Right)){
                if(isBurBreak) window.draw(Bur.sprite);
                if(!isBurBreak) window.draw(Bur2.sprite);
            }
        }
        if(!isBook) book(window, event);
        for(itBul = bul.begin(); itBul != bul.end(); itBul++){
            if(p.isGun && p.modeSwordAndChanSaw == 2){
                (*itBul)->update(*time);
                if((*itBul)->life)
                    window.draw((*itBul)->sprite);
            }
        }
        window.draw(Sprite_Mouse.sprite);
        window.display();
    }
    return false;
}

void gameRunnig() { if (startGame()){gameRunnig();} }
int main() {
    gameRunnig();
    return 0;
}
