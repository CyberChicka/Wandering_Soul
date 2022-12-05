#ifndef TEST_SFML_TEXTANDIMAGES_H
#define TEST_SFML_TEXTANDIMAGES_H

using namespace sf;
using namespace std;

Image image228, image887, easyEnemyImage, NPS1Image, NPS2Image, NPS3Image, Boss_Ghost, Image_Fire;
Image image_purple_fire, image_Anim_BOSS_TEXT, AttacaImage;
Image Water_image, Portal_image, Radius_image;
Image ChanSawImage, Bbullet, ImageGunSan;

int SettingNum = 0;
float Width;
float Height;
int scrn = 0; char pi, pa;
int vol = 5;
bool isAttackEnemy = false;
string txt = "Text/MaredivRegular.ttf";

class Images_s{
public:
    String File; Image image; Texture texture; Sprite sprite;
    Images_s(String F){
        File = F; image.loadFromFile("images/" + File);
        texture.loadFromImage(image); sprite.setTexture(texture);
    }
};
class Text_{
public:
    Font font;
    Text text;
    int size;
    Text_(String F, int S){
        size = S; font.loadFromFile(F);
        text.setFont(font); text.setCharacterSize(size);
    }
};
//

Images_s Time_Bar("Time_Bar.png");
Images_s Soul_Bar("Time_Bar.png");
Images_s Sprite_Mouse("Sprite-Mouse.png");
Images_s mech("Sprite-new_SWORD_2_broken.png");
Images_s inventoreOpen("inventor.png");
Images_s HP("HP1.png");
Images_s open("inventor_2.png");
Images_s toro_1("Sprite-Toro_1.png");
Images_s restart("Button/444.png");
Images_s kolodec("Sprite-kolodec1.png");
Images_s Bur("Sprite-bur01.png");
Images_s Bur2("Sprite-bur02.png");
Images_s Bur_("Sprite-bur01.png");
Images_s ChanInvent("ChanInvent.png");
Images_s gunInvent("Object/Gun_Sanberst.png");
Images_s Flower_txt("Flower_Filed.png");
Images_s Ghost_txt("Ghost_Valley.png");
// lvl st
Images_s Trava_pool("Map_set/tekstura-trvi_pool.png");
Images_s Trava_pool1("Map_set/tekstura-trvi_pool.png");
Images_s Trava_pool2("Map_set/tekstura-trvi_pool.png");
Images_s Trava_pool3("Map_set/tekstura-trvi_pool.png");
Images_s Trava_pool4("Map_set/tekstura-trvi_pool.png");
Images_s Trava_pool5("Map_set/tekstura-trvi_pool.png");
Images_s Trava_pool6("Map_set/tekstura-trvi_pool.png");
Images_s Trava_pool7("Map_set/tekstura-trvi_pool.png");
Images_s Trava_pool8("Map_set/tekstura-trvi_pool.png");
Images_s Trava_pool9("Map_set/tekstura-trvi_pool.png");
Images_s Trava_pool10("Map_set/tekstura-trvi_pool.png");
Images_s Trava_pool11("Map_set/tekstura-trvi_pool.png");
Images_s Trava_pool12("Map_set/tekstura-trvi_pool.png");
Images_s Trava_pool13("Map_set/tekstura-trvi_pool.png");
Images_s Trava_pool14("Map_set/tekstura-trvi_pool.png");
Images_s Trava_pool15("Map_set/tekstura-trvi_pool.png");
Images_s Trava_pool16("Map_set/tekstura-trvi_pool.png");
Images_s Trava_pool17("Map_set/tekstura-trvi_pool.png");
Images_s Trava_pool18("Map_set/tekstura-trvi_pool.png");

Images_s Trava_pool19("Map_set/tekstura-trvi_pool.png");
Images_s Trava_pool20("Map_set/tekstura-trvi_pool.png");
Images_s Trava_pool21("Map_set/tekstura-trvi_pool.png");
Images_s Trava_pool22("Map_set/tekstura-trvi_pool.png");

Images_s Trava2("Map_set/Sprite-Trava.png");
Images_s Kyst_big("Map_set/Sprite-Kyst-big.png");
Images_s Kyst_big2("Map_set/Sprite-Kyst-big2.png");
Images_s Kyst_big2_2("Map_set/Sprite-Kyst-big2.png");
Images_s Kyst_mini("Map_set/Sprite-Kyst-mini.png");
Images_s Stone("Map_set/Sprite-Stone.png");
Images_s Stone_Fors("Map_set/Sprite-stone_fors.png");
Images_s Stone_Mini("Map_set/Sprite-Stone_mini.png");
Images_s Trava("Map_set/Sprite-Trava.png");
Images_s Trava_Pes_Big("Map_set/Sprite-Trava_pes_big.png");
Images_s Education("Education_text.png");
// lvl1
Images_s Derevo_Ghost("Object/Sprite-Drevo_priz.png");
Images_s Derevo_Ghost1("Object/Sprite-Drevo_priz.png");
Images_s Derevo_Ghost2("Object/Sprite-Drevo_priz.png");
Images_s Derevo_Ghost3("Object/Sprite-Drevo_priz.png");
Images_s Derevo_Ghost4("Object/Sprite-Drevo_priz.png");
Images_s Derevo_Ghost5("Object/Sprite-Drevo_priz.png");
Images_s Derevo_Ghost6("Object/Sprite-Drevo_priz.png");
Images_s Derevo_Ghost7("Object/Sprite-Drevo_priz.png");
//
Images_s Book_Sprite("Object/Sprite-isBook.png");
Images_s Book_Sprite_mini("Object/Sprite-isBook_mini.png");
Images_s book_isPravo("Button/PRAVO_PRESS_isBook.png");
Images_s book_isLevo("Button/LEVO_PRESS_isBook.png");

bool timer(int x)
{
    static sf::Clock clc;
    if (clc.getElapsedTime().asSeconds() < x){return true; clc.restart(); }
    return false;
}
bool timer_1(int x)
{
    static sf::Clock clc;
    if (clc.getElapsedTime().asSeconds() < x){return true; clc.restart(); }
    return false;
}
void Load_image(){
    ImageGunSan.loadFromFile("images/Object/Gun_Sanberst.png");
    Bbullet.loadFromFile("images/Object/bullet.png");
    ChanSawImage.loadFromFile("images/Object/CHAN-SAW.png");
    Radius_image.loadFromFile("images/Object/Radius.png");
    Portal_image.loadFromFile("images/Object/Portal.png");
    Water_image.loadFromFile("images/Map_set/Water_anim.png");
    AttacaImage.loadFromFile("images/Atack/AttacaBoss.png");
    image228.loadFromFile("images/Entity_sprite/Hero_atack_8.png");
    image887.loadFromFile("images/Entity_sprite/Player_new++.png");
    easyEnemyImage.loadFromFile("images/Entity_sprite/enum.png");
    NPS1Image.loadFromFile("images/Entity_sprite/Nps_2_newSprite.png");
    NPS2Image.loadFromFile("images/Entity_sprite/Nps_3_F.png");
    NPS3Image.loadFromFile("images/Entity_sprite/Nps_alf.png");
    Boss_Ghost.loadFromFile("images/Entity_sprite/Ghost_normal1.png");
    Image_Fire.loadFromFile("images/Fire_Sprite.png");
    image_purple_fire.loadFromFile("images/Object/Fire_boss.png");
    image_Anim_BOSS_TEXT.loadFromFile("images/Text/Boss_text_Anim.png");
}
void screen(){
    string name = "Save/save.txt";
    ifstream fin;
    fin.open(name);
    if(fin.is_open() ){
        while (!fin.eof()){ fin >> scrn;}
    } else{ cout << "Error"<< endl; }
    fin.close();

    if(scrn == 1){ Width = 1280; Height = 720; }
    if(scrn == 2){ Width = 1600; Height = 900; }
    if(scrn == 3){ Width = 1920; Height = 1080; }
}

Text_ nps_txt1(txt, 25);
Text_ nps_txt2(txt, 25);
Text_ nps_txt3(txt, 25);
Text_ text_souls(txt, 25);
Text_ text_gmTime(txt, 25);
Text_ text_toro(txt, 25);

Text_ control(txt, 20);
Text_ text_dead(txt, 150);
Text_ text_isBook(txt, 20);
Text_ text_isBook2(txt, 20);
Text_ text_isBookPage(txt, 30);
Text_ textBossOfHazeMassage(txt, 25);
Text_ TextVolume(txt, 25);

void Location_of_Objects_lvlST(RenderWindow &window, bool islvlST){
    Trava2.sprite.setScale(0.9f, 0.9f);
    Kyst_big.sprite.setScale(0.9f, 0.9f);
    Kyst_mini.sprite.setScale(0.9f, 0.9f);
    Stone.sprite.setScale(0.9f, 0.9f);
    Kyst_big2.sprite.setScale(0.9f, 0.9f);
    Kyst_big2_2.sprite.setScale(0.9f, 0.9f);
    Stone_Mini.sprite.setScale(0.9f, 0.9f);
    Stone_Fors.sprite.setScale(0.9f, 0.9f);
    Trava_Pes_Big.sprite.setScale(0.9f, 0.9f);
    Trava.sprite.setScale(0.9f, 0.9f);
    Trava_pool.sprite.setScale(1.0f, 1.0f);
    Trava_pool1.sprite.setScale(1.0f, 1.0f);
    Trava_pool2.sprite.setScale(1.0f, 1.0f);
    Trava_pool3.sprite.setScale(1.0f, 1.0f);
    Trava_pool4.sprite.setScale(1.0f, 1.0f);
    Trava_pool5.sprite.setScale(1.0f, 1.0f);
    Trava_pool6.sprite.setScale(1.0f, 1.0f);
    Trava_pool7.sprite.setScale(1.0f, 1.0f);
    //Trava_pool8.sprite.setScale(1.0f, 1.0f);
    Trava_pool9.sprite.setScale(1.0f, 1.0f);
    Trava_pool10.sprite.setScale(1.0f, 1.0f);
    Trava_pool11.sprite.setScale(1.0f, 1.0f);
    Trava_pool12.sprite.setScale(1.0f, 1.0f);
    Trava_pool13.sprite.setScale(1.0f, 1.0f);
    Trava_pool14.sprite.setScale(1.0f, 1.0f);
    Trava_pool15.sprite.setScale(1.0f, 1.0f);
    Trava_pool16.sprite.setScale(1.0f, 1.0f);
    Trava_pool17.sprite.setScale(1.0f, 1.0f);
    Trava_pool18.sprite.setScale(1.0f, 1.0f);
    Trava_pool19.sprite.setScale(1.0f, 1.0f);
    Trava_pool20.sprite.setScale(1.0f, 1.0f);
    Trava_pool21.sprite.setScale(1.0f, 1.0f);
    Trava_pool22.sprite.setScale(1.0f, 1.0f);

    Trava_pool.sprite.setPosition(500, 500);
    Trava_pool1.sprite.setPosition(800, 500);
    Trava_pool2.sprite.setPosition(500, 800);
    Trava_pool3.sprite.setPosition(800, 800);
    Trava_pool4.sprite.setPosition(200, 650);
    Trava_pool5.sprite.setPosition(500, 200);
    Trava_pool6.sprite.setPosition(800, 200);

    Trava_pool7.sprite.setPosition(1100, 200);
    //Trava_pool8.sprite.setPosition(1100, 500);
    Trava_pool9.sprite.setPosition(1100, 800);
    Trava_pool10.sprite.setPosition(1100, 1100);

    Trava_pool11.sprite.setPosition(1400, 200);
    Trava_pool12.sprite.setPosition(1400, 500);
    Trava_pool13.sprite.setPosition(1400, 800);
    Trava_pool14.sprite.setPosition(1400, 1100);

    Trava_pool15.sprite.setPosition(1700, 200);
    Trava_pool16.sprite.setPosition(1700, 500);
    Trava_pool17.sprite.setPosition(1700, 800);
    Trava_pool18.sprite.setPosition(1700, 1100);

    Trava_pool19.sprite.setPosition(2000, 200);
    Trava_pool20.sprite.setPosition(2300, 200);
    Trava_pool21.sprite.setPosition(2650, 1000);
    Trava_pool22.sprite.setPosition(2350, 1000);


    Trava2.sprite.setPosition(1100, 500);
    Kyst_big.sprite.setPosition(2400, 500);
    Kyst_mini.sprite.setPosition(2900, 900);
    Stone.sprite.setPosition(2800, 600);
    Kyst_big2.sprite.setPosition(2850, 1000);
    Kyst_big2_2.sprite.setPosition(900, 1000);
    Stone_Mini.sprite.setPosition(2850, 800);
    Stone_Fors.sprite.setPosition(2000, 500);
    Trava_Pes_Big.sprite.setPosition(2300,700);
    Trava.sprite.setPosition(2000, 920);

    if(islvlST){
        window.draw(Trava_pool.sprite);
        window.draw(Trava_pool1.sprite);
        window.draw(Trava_pool2.sprite);
        window.draw(Trava_pool3.sprite);
        window.draw(Trava_pool4.sprite);
        window.draw(Trava_pool5.sprite);
        window.draw(Trava_pool6.sprite);
        window.draw(Trava_pool7.sprite);
        window.draw(Trava_pool9.sprite);
        window.draw(Trava_pool10.sprite);
        window.draw(Trava_pool11.sprite);
        window.draw(Trava_pool12.sprite);
        window.draw(Trava_pool13.sprite);
        window.draw(Trava_pool14.sprite);
        window.draw(Trava_pool15.sprite);
        window.draw(Trava_pool16.sprite);
        window.draw(Trava_pool17.sprite);
        window.draw(Trava_pool18.sprite);
        window.draw(Trava_pool19.sprite);
        window.draw(Trava_pool20.sprite);
        window.draw(Trava_pool21.sprite);
        window.draw(Trava_pool22.sprite);
        window.draw(Kyst_big.sprite);
        window.draw(Kyst_big2.sprite);
        window.draw(Kyst_big2_2.sprite);
        window.draw(Kyst_mini.sprite);
        window.draw(Stone.sprite);
        window.draw(Stone_Fors.sprite);
        window.draw(Stone_Mini.sprite);
        window.draw(Trava.sprite);
        window.draw(Trava_Pes_Big.sprite);
        window.draw(Trava2.sprite);
    }
}
void Location_of_Objects_LVL1(RenderWindow &window, bool isLVL1){
    Derevo_Ghost.sprite.setPosition(275,525);
    Derevo_Ghost1.sprite.setPosition(2820,140);
    Derevo_Ghost2.sprite.setPosition(3348,46);
    Derevo_Ghost3.sprite.setPosition(4260,335);
    Derevo_Ghost4.sprite.setPosition(4115,1290);
    Derevo_Ghost5.sprite.setPosition(3205,1145);
    Derevo_Ghost6.sprite.setPosition(1910,1100);
    Derevo_Ghost7.sprite.setPosition(805,1435);

    if(isLVL1){
        window.draw(Derevo_Ghost.sprite);
        window.draw(Derevo_Ghost1.sprite);
        window.draw(Derevo_Ghost2.sprite);
        window.draw(Derevo_Ghost3.sprite);
        window.draw(Derevo_Ghost4.sprite);
        window.draw(Derevo_Ghost5.sprite);
        window.draw(Derevo_Ghost6.sprite);
        window.draw(Derevo_Ghost7.sprite);
    }
}
void Location_of_Objects_LVL2(RenderWindow &window, bool isLVL2){ }
void Location_ofObjects_LVL3(RenderWindow &window, bool isMap3){ }

void Text_Settings(RenderWindow &window){
    TextVolume.text.setColor(Color(0, 161, 102));
    textBossOfHazeMassage.text.setColor(Color(67, 157, 170));
    textBossOfHazeMassage.text.setStyle(Text::Bold);
    nps_txt1.text.setColor(Color::Black);
    nps_txt2.text.setColor(Color::Black);
    nps_txt3.text.setColor(Color::Black);
    text_souls.text.setStyle(Text::Bold);
    text_souls.text.setColor(Color(0, 161, 102));
    text_gmTime.text.setStyle(Text::Bold);
    text_gmTime.text.setColor(Color(0, 180, 180));
    text_toro.text.setStyle(Text::Bold);
    text_toro.text.setColor(Color::Black);
    control.text.setStyle(Text::Bold);
    control.text.setColor(Color(205, 118, 84));
    text_dead.text.setStyle(Text::Bold);
    text_dead.text.setColor(Color(220, 20, 60));
}

void Set_Screen(RenderWindow &window){
    ChanInvent.sprite.setPosition(view.getCenter().x - 450, view.getCenter().y - 45);
    gunInvent.sprite.setPosition(view.getCenter().x -493, view.getCenter().y - 45);
    Bur_.sprite.setPosition(view.getCenter().x - 454, view.getCenter().y - 95);
    toro_1.sprite.setScale(2.0f, 2.0f);
    mech.sprite.setScale(0.97f, 0.97f);
    restart.sprite.setColor(Color::White);
    restart.sprite.setPosition(view.getCenter().x - 200, view.getCenter().y - -150);
    open.sprite.setScale(1.5f, 1.5f);
    text_dead.text.setPosition(view.getCenter().x - 350, view.getCenter().y - 200);
    inventoreOpen.sprite.setPosition(view.getCenter().x - 500, view.getCenter().y - 100);
    textBossOfHazeMassage.text.setPosition(view.getCenter().x - 100, view.getCenter().y - 100);
    Ghost_txt.sprite.setPosition(view.getCenter().x - 200, view.getCenter().y - 250);
    control.text.setPosition(view.getCenter().x - 150, view.getCenter().y - 30);
    mech.sprite.setPosition(view.getCenter().x - 512, view.getCenter().y - 144);
    Flower_txt.sprite.setPosition(view.getCenter().x - 200, view.getCenter().y - 250);
    gunInvent.sprite.setScale(0.24f, 0.24f);
    switch (scrn) {
        case 1:
            open.sprite.setPosition(view.getCenter().x - 450, view.getCenter().y + 250);
            TextVolume.text.setPosition(280, 290);
            Bur.sprite.setScale(0.4f, 0.4f);
            Bur2.sprite.setScale(0.4f, 0.4f);
            Bur_.sprite.setScale(0.5f, 0.5f);
            ChanInvent.sprite.setScale(0.5f, 0.5f);
            Education.sprite.setScale(0.9f, 0.9f);
            Education.sprite.setPosition(view.getCenter().x - 580, view.getCenter().y - 210);
            toro_1.sprite.setPosition(view.getCenter().x + 300, view.getCenter().y - 335);
            text_toro.text.setPosition(view.getCenter().x + 300, view.getCenter().y - 335);
            break;
        case 2: break;
        case 3:
            open.sprite.setPosition(view.getCenter().x - 450, view.getCenter().y + 380);
            TextVolume.text.setPosition(285, 380);
            Bur.sprite.setScale(0.4f, 0.4f);
            Bur2.sprite.setScale(0.4f, 0.4f);
            Bur_.sprite.setScale(0.5f, 0.5f);
            ChanInvent.sprite.setScale(0.3f, 0.4f);
            toro_1.sprite.setPosition(view.getCenter().x + 450, view.getCenter().y - 350);
            text_toro.text.setPosition(view.getCenter().x + 450, view.getCenter().y - 380);
            Education.sprite.setPosition(view.getCenter().x - 900, view.getCenter().y - 500);
            break;
    }
}

void Arrangement(int break_fire, Sprite &sprite){
    switch(break_fire){
        case 1: sprite.setPosition(228, 1488); break;
        case 2: sprite.setPosition(2200, 600);break;
        case 3: sprite.setPosition(3000, 1200);break;
        case 4: sprite.setPosition(2100, 1200);break;
        case 5: sprite.setPosition(1500, 300);break;
        case 6: sprite.setPosition(500, 1000);break;
        case 7: sprite.setPosition(1000, 1000);break;
        case 8: sprite.setPosition(2040, 678);break;
        case 9: sprite.setPosition(4305, 247);break;
    }
}
void IsLVL(bool &isLvLST, bool &isLvL1, bool &isLvL2, bool &isLvL3){
    if(isLvLST){ isLvL1 = false; isLvL3 = false; isLvL2 = false;}
    if(isLvL1){ isLvLST = false; isLvL3 = false; isLvL2 = false;}
    if(isLvL2){ isLvLST = false;isLvL1 = false; isLvL3 = false;}
    if(isLvL3){ isLvLST = false; isLvL1 = false; isLvL2 = false; }
}
#endif //TEST_SFML_TEXTANDIMAGES_H
