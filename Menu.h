
#include "TextAndImages.h"
#include "MusicSound.h"

using namespace sf;
using namespace std;

// /////////////////////////////////////////////// Меню настроек ////////////////////////////////////////////////////

bool timer_menu(int x)
{
    static sf::Clock clock;
    if (clock.getElapsedTime().asSeconds() > x)
    {
        return true;
        clock.restart();
    }
    return false;
}

void settings(RenderWindow &window){
    Texture menuSettings1, menuSettings2, menuSettings3, menuSettings7, menuBackground_1, right_press, left_press;
    Texture menuSM;
    menuSM.loadFromFile("images/Text/Sound&Music_menu.png");
    menuSettings1.loadFromFile("images/Button/Scrin_1.png");
    menuSettings2.loadFromFile("images/Button/Scrin_2.png");
    menuSettings3.loadFromFile("images/Button/Scrin_3.png");
    menuSettings7.loadFromFile("images/Button/Back.png");
    Text_Settings(window);
    switch (scrn) {
        case 1: menuBackground_1.loadFromFile("images/Game_Settings_menu_mini.png"); break;
        case 2: break;
        case 3: menuBackground_1.loadFromFile("images/Game_Settings_menu.png");break;
    }

    left_press.loadFromFile("images/Button/LEVO_PRESS.png");
    right_press.loadFromFile("images/Button/PRAVO_PRESS.png");
    Sprite Menu_Set1(menuSettings1),Menu_Set2(menuSettings2), Menu_Set3(menuSettings3), Menu_Set7(menuSettings7), menuBg_1(menuBackground_1);
    Sprite Right_press(right_press), Left_press(left_press), MenuSoundMusic(menuSM);
    bool isSettings = 1;
    music_Sound();

    if(scrn == 1){
        MenuSoundMusic.setPosition(180, 100);
        Menu_Set1.setPosition(855, 205);
        Menu_Set2.setPosition(855, 335);
        Menu_Set3.setPosition(855, 465);
        Menu_Set7.setPosition(170, 550);
        Right_press.setPosition(300, 265);
        Left_press.setPosition(90, 265);
    }
    if(scrn == 2){ }
    if(scrn == 3){
        MenuSoundMusic.setPosition(180, 200);
        Menu_Set1.setPosition(1300, 350);
        Menu_Set2.setPosition(1300, 500);
        Menu_Set3.setPosition(1300, 680);
        Menu_Set7.setPosition(170, 800);
        Right_press.setPosition(300, 350);
        Left_press.setPosition(90, 350);
    }
    while(isSettings){
        ostringstream  IntVolume;
        Menu_Set1.setColor(Color::White);
        Menu_Set2.setColor(Color::White);
        Menu_Set3.setColor(Color::White);
        Menu_Set7.setColor(Color::White);
        Left_press.setColor(Color::White);
        Right_press.setColor(Color::White);

        SettingNum = 0;
        window.clear(Color(129, 181, 221));

        if(scrn == 1){
            if (IntRect(855, 205, 210, 70).contains(Mouse::getPosition(window))) { Menu_Set1.setColor(Color::Blue); SettingNum = 1; pressed_mouse.play();}
            if (IntRect(855,335, 210, 70).contains(Mouse::getPosition(window)) ) { Menu_Set2.setColor(Color::Blue); SettingNum = 2; pressed_mouse.play();}
            if (IntRect(855, 465, 240, 70).contains(Mouse::getPosition(window))) { Menu_Set3.setColor(Color::Blue); SettingNum = 3; pressed_mouse.play();}
            if (IntRect(170, 550, 240, 70).contains(Mouse::getPosition(window))) { Menu_Set7.setColor(Color::Blue); SettingNum = 4; pressed_mouse.play();}
            if(IntRect(300, 265, 240, 70).contains(Mouse::getPosition(window))) { Right_press.setColor(Color::Blue); SettingNum = 5; pressed_mouse.play();}
            if(IntRect(90, 265, 240, 70).contains(Mouse::getPosition(window))) { Left_press.setColor(Color::Blue); SettingNum = 6; pressed_mouse.play();}
        }
        if(scrn == 2){ }
        if(scrn == 3){
            if (IntRect(1300, 350, 210, 70).contains(Mouse::getPosition(window))) { Menu_Set1.setColor(Color::Blue); SettingNum = 1; pressed_mouse.play();}
            if (IntRect(1300,500, 210, 70).contains(Mouse::getPosition(window)) ) { Menu_Set2.setColor(Color::Blue); SettingNum = 2; pressed_mouse.play();}
            if (IntRect(1300, 680, 240, 70).contains(Mouse::getPosition(window))) { Menu_Set3.setColor(Color::Blue); SettingNum = 3; pressed_mouse.play();}
            if (IntRect(170, 800, 240, 70).contains(Mouse::getPosition(window))) { Menu_Set7.setColor(Color::Blue); SettingNum = 4; pressed_mouse.play();}
            if(IntRect(300, 350, 240, 70).contains(Mouse::getPosition(window))) { Right_press.setColor(Color::Blue); SettingNum = 5; pressed_mouse.play();}
            if(IntRect(90, 350, 240, 70).contains(Mouse::getPosition(window))) { Left_press.setColor(Color::Blue); SettingNum = 6; pressed_mouse.play();}
        }

        Event eve;
        while (window.pollEvent(eve)) {
            if(eve.type == Event::MouseButtonPressed){
                if(eve.key.code == Mouse::Left){
                    if(SettingNum == 4) isSettings = false;
                    if(SettingNum == 1){
                        window.setSize(Vector2u(1280, 720));
                        scrn = 1;
                        pressed_mouse.play();
                    }
                    if(SettingNum == 2){
                        window.setSize(Vector2u(1600, 900));
                        scrn = 2;
                        pressed_mouse.play();
                    }
                    if(SettingNum == 3){
                        window.setSize(Vector2u(1920, 1080));
                        scrn = 3;
                        pressed_mouse.play();
                    }

                  if(SettingNum == 5) { if(vol < 10){vol += 1;}}
                  if(SettingNum == 6 ) { if(vol > 1){vol -= 1;}}
                }
            }
            if (eve.type == Event::Closed) {window.close(); isSettings = false;}
        }
        string name = "Save/sound.txt";
        ofstream fin;
        fin.open(name);
        if(fin.is_open()){
            fin << vol;
        } else{ cout << "Error"<< endl; }
        fin.close();
        IntVolume << vol;
        TextVolume.text.setString(IntVolume.str());

        window.draw(menuBg_1);
        window.draw(Menu_Set1);
        window.draw(Menu_Set2);
        window.draw(Menu_Set3);
        window.draw(Menu_Set7);
        window.draw(Right_press);
        window.draw(Left_press);
        window.draw(MenuSoundMusic);
        window.draw(TextVolume.text);
        window.display();
    }
}

void Screensaver(RenderWindow &window){
    Texture Texture_Black_Fon, Texture_1, Texture_2, Texture_3;
    switch (scrn) {
        case 1: Texture_Black_Fon.loadFromFile("images/Black_Fon_mini.png");break;
        case 2: break;
        case 3: Texture_Black_Fon.loadFromFile("images/Black_Fon.png"); break;
    }
    Texture_1.loadFromFile("Scens/What_soul.png");
    Texture_2.loadFromFile("Scens/Does_Entitty.png");
    Texture_3.loadFromFile("Scens/What_Souls.png");
    Sprite BlackFon(Texture_Black_Fon); Sprite Text1(Texture_1); Sprite Text2(Texture_2); Sprite Text3(Texture_3);
    music_Sound();
    if(scrn == 1){
        Text1.setScale(0.5f, 0.5f);
        Text2.setScale(0.5f, 0.5f);
        Text3.setScale(0.5f, 0.5f);
        Text1.setPosition(100, 100);
        Text2.setPosition(100, 500);
        Text3.setPosition(280, 290);
    }
    if(scrn == 2){ }
    if(scrn == 3){
        Text1.setScale(0.8f, 0.8f);
        Text2.setScale(0.8f, 0.8f);
        Text3.setScale(0.8f, 0.8f);
        Text1.setPosition(140, 140);
        Text2.setPosition(140, 640);
        Text3.setPosition(350, 380);
    }

    bool isFon = 1;
    int FonNum = 0;

    while (isFon){

        window.clear();

        Event ev;
        while (window.pollEvent(ev)) {
            if (ev.type == sf::Event::Closed) { window.close();isFon = false; }
            if (Keyboard::isKeyPressed(Keyboard::Escape)) {window.close(); isFon = false;}
        }
        if(timer_menu(12) || Mouse::isButtonPressed(Mouse::Right)){ isFon = false;}
        window.draw(BlackFon);
        if(timer_menu(2)){ window.draw(Text1);}
        if(timer_menu(5)){window.draw(Text2);}
        if(timer_menu(9)){window.draw(Text3);}

        window.display();
    }
}
// ////////////////////////////////// Меню игры //////////////////////////////////////////////////////////////////
void menu(RenderWindow &window) { // Меню игры
    screen();
    Image image_Guts;
    Texture menuTexture1, menuTexture2, menuTexture3, aboutTexture, menuBackground, menuBackground_1;
    image_Guts.loadFromFile("images/Entity_sprite/Guts_Anim.png");
    menuTexture1.loadFromFile("images/Button/111.png");
    menuTexture2.loadFromFile("images/Button/222.png");
    menuTexture3.loadFromFile("images/Button/333.png");
    switch (scrn) {
        case 1:
            menuBackground.loadFromFile("images/Game_Fon_menu_min.png");
            break;
        case 2: break;
        case 3:
            menuBackground.loadFromFile("images/Game_Fon_menu.png");
            break;
    }
    Nps Guts(image_Guts, 1200, 400, 600, 600, "Guts");
    menuBackground_1.loadFromFile("images/Menu_setings.png");
    Sprite menu1(menuTexture1), menu2(menuTexture2), menu3(menuTexture3), about(aboutTexture), menuBg(menuBackground), menuBg_1(menuBackground_1);

    music_Sound();
    Music mus;//создаем объект музыки
    mus.openFromFile("Music/Menu.ogg");//загружаем файл
    mus.play();//воспроизводим музыку
    mus.setLoop(true);

    Clock clock;
    float time = clock.getElapsedTime().asMicroseconds();
    clock.restart();
    time = time / 500;

    bool isMenu = 1;
    int menuNum = 0;

    switch (scrn) {
        case 1:
            Guts.x = 850, Guts.y = 380;
            Guts.sprite.setScale(0.5f, 0.5f);
            menu1.setPosition(150, 385);
            menu3.setPosition(120, 485);
            menu2.setPosition(150, 580);break;
        case 2: break;
        case 3:
            Guts.x = 1200; Guts.y = 400;
            Guts.sprite.setScale(1.0f, 1.0f);
            menu1.setPosition(150, 685);
            menu3.setPosition(120, 785);
            menu2.setPosition(150, 880);break;
    }
    menuBg.setPosition(0, 0);
// ///////////////////////// Меню ///////////////////////////////////////////////////
    while (isMenu) {

        menu1.setColor(Color::White);
        menu2.setColor(Color::White);
        menu3.setColor(Color::White);
        menuNum = 0;
        window.clear(Color(129, 181, 221));
        switch (scrn) {
            case 1:
                if (IntRect(150, 385, 210, 70).contains(Mouse::getPosition(window))) {menu1.setColor(Color::Blue);menuNum = 1; pressed_mouse.play();}
                if (IntRect(120, 485, 240, 70).contains(Mouse::getPosition(window))) {menu3.setColor(Color::Blue);menuNum = 3; pressed_mouse.play();}
                if (IntRect(150, 580, 210, 70).contains(Mouse::getPosition(window))) {menu2.setColor(Color::Blue);menuNum = 2; pressed_mouse.play();} break;
            case 2: break;
            case 3:
                if (IntRect(150, 685, 210, 70).contains(Mouse::getPosition(window))) {menu1.setColor(Color::Blue);menuNum = 1; pressed_mouse.play();}
                if (IntRect(120, 785, 240, 70).contains(Mouse::getPosition(window))) {menu3.setColor(Color::Blue);menuNum = 3; pressed_mouse.play();}
                if (IntRect(150, 880, 210, 70).contains(Mouse::getPosition(window))) {menu2.setColor(Color::Blue);menuNum = 2; pressed_mouse.play();} break;
        }

        Event ev;
        while (window.pollEvent(ev)) {
            if(ev.type == Event::MouseButtonPressed){
                if(ev.key.code == Mouse::Left){
                    if (menuNum == 1) { mus.pause(); isMenu = false;  pressed_mouse.play(); }// Если нажали левую кнопеу мыши
                    if (menuNum == 2) { window.close();mus.pause();isMenu = false; pressed_mouse.play(); }
                    if (menuNum == 3) { settings(window); pressed_mouse.play(); }
                }
            }
            if (ev.type == sf::Event::Closed) { window.close();isMenu = false;mus.pause(); }
            if (Keyboard::isKeyPressed(Keyboard::Escape)) {window.close();mus.pause(); isMenu = false;}
        }
        Guts.update(time);

        window.draw(menuBg);
        window.draw(menu1);
        window.draw(menu2);
        window.draw(menu3);
        window.draw(Guts.sprite);
        window.display();
    }
}

bool timer_Screensaver_isMe(int x)
{
    static  sf::Clock clock;
    if (clock.getElapsedTime().asSeconds() > x)
    {
        return true;
        clock.restart();
    }
    return false;
}
void Screensaver_isMe(RenderWindow &window){

    bool isMe = 1;
    while(isMe){



        window.clear();

        if(Keyboard::isKeyPressed(Keyboard::Escape)){ isMe = false; }
        window.display();
    }
}

