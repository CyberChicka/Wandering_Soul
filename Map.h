#ifndef TEST_SFML_MAP_H
#define TEST_SFML_MAP_H
using namespace sf;
using namespace std;
#include "TextAndImages.h"

//                                 Основной LVL
Images_s map_starting("Map_set/Sprite-map.png");
Images_s s_map("Map_Texture/Map_Texrure_1_Dark.png");
Images_s o_map("Map_Texture/Map_Texrure_22.png");
Images_s t_map("Map_Texture/Map_Texrure_3+.png");
const int HEIGHT_LVL_STARTING = 50;//размер карты высота
const int WIDTH_LVL_STARTING = 90;//размер карты ширина

string LVLStarting[HEIGHT_LVL_STARTING]{
            "..............00000000........000000000000........................................",
            ".......0000000        00000000            0000000000000000........................",
            "......0                                                   0000000000000000000.....",
            "......0                                                                      0....",
            ".......0                                                                      0...",
            ".......0                                                                       0..",
            ".......0                                                                        0.",
            ".......0                                                                        0.",
            ".......0                                                                       0..",
            ".......0                                                                       0..",
            "......0                                                                       0...",
            ".....0                                                                       0....",
            "....0                                                                        0....",
            "...0                                                                          0...",
            "..0                                                                           0...",
            ".0                                                                            0...",
            ".0                                                                             0..",
            ".0                                                                             0..",
            "..0                                                                           0...",
            "...0                                                                         0....",
            "...0                                                                        0.....",
            "...0                                                                       0......",
            "....0                                                                     0.......",
            ".....0      QjjjjjjjjW                                                    0.......",
            ".....0      l        L                                                    0.......",
            ".....0      l        L                                                    0.......",
            "....0       l        L                                                    0........",
            "....0       l        L                                                   0........",
            "...0        EJJJJJJJJR                                                   0.......",
            "000000000000000000000000000000000000000                                  0.......",
            "0                                      000000000000                  000000000   ",
            "0                                                  0000000000000000000      0   ",
            "0                                                                            0   ",
            "0                                                                            0   ",
            "0                                                                            0   ",
            "0                                                                            0   ",
            "0                                                                            0   ",
            "0                                                                            0   ",
            "0                                                                            0   ",
            "0                                                                            0   ",
            "0                                                                            0   ",
            "0                                                                            0   ",
            "0                                                                            0   ",
            "0                                                                            0   ",
            "0                                                                            0   ",
            "0                                                                            0   ",
            "0                                                                            0   ",
            "0                                                                            0   ",
            "0                                                                            0   ",
            "000000000000000000000000000000000000000000000000000000000000000000000000000000   ",
};
void lvl_starting(RenderWindow &window, bool isLVLStarting){
    if(isLVLStarting){
        for (int i = 0; i < HEIGHT_LVL_STARTING; i++)
            for (int j = 0; j < WIDTH_LVL_STARTING; j++){
                // Локация старта
                if (LVLStarting[i][j] == ' ')map_starting.sprite.setTextureRect(IntRect(0, 0, 48, 48));  //если встретили символ пробел, то рисуем 1й квадратик
                if (LVLStarting[i][j] == '0')map_starting.sprite.setTextureRect(IntRect(50, 0, 48, 48)); //если встретили символ 0, то рисуем 3й квадратик
                if(LVLStarting[i][j] == '.')map_starting.sprite.setTextureRect(IntRect(520, 0, 48, 48));
                if(LVLStarting[i][j] == 'j')map_starting.sprite.setTextureRect(IntRect(100, 0, 48, 48));
                if(LVLStarting[i][j] == 'J')map_starting.sprite.setTextureRect(IntRect(150, 0, 48, 48));
                if(LVLStarting[i][j] == 'l')map_starting.sprite.setTextureRect(IntRect(204, 0, 48, 48));
                if(LVLStarting[i][j] == 'L')map_starting.sprite.setTextureRect(IntRect(250, 0, 48, 48));
                if(LVLStarting[i][j] == 'Q')map_starting.sprite.setTextureRect(IntRect(300, 0, 48, 48));
                if(LVLStarting[i][j] == 'W')map_starting.sprite.setTextureRect(IntRect(350, 0, 48, 48));
                if(LVLStarting[i][j] == 'E')map_starting.sprite.setTextureRect(IntRect(400, 0, 48, 48));
                if(LVLStarting[i][j] == 'R')map_starting.sprite.setTextureRect(IntRect(450, 0, 48, 48));


                map_starting.sprite.setPosition(j * 48, i * 48); //по сути раскидывает квадратики, превращая в карту, то есть задает каждому из них позицию, если убрать, то вся карта нарисуется в одном квадрате 32*32 и мы увидим один квадрат
                window.draw(map_starting.sprite); //рисуем квадратики на экран
            }
        Location_of_Objects_lvlST(window, isLVLStarting);
    }
}
//                                     lvl 1
const int HEIGHT_LVL = 45;//размер карты высота
const int WIDTH_LVL = 100;//размер карты ширина

string TileLVL[HEIGHT_LVL] = {
        "                                                  11111111111111111111111111111111111111111111111111",
        "111100000000000000011                            110000000000000000000000000000000000000000000000001",
        "1110               00001                         11                                                1",
        "110                    0000000000000000000000000011               s        f         s             1",
        "10                                               11                                    0           1",
        "1                              f                 11        R            D             0 0          1",
        "1                                                11                                    0           1",
        "1                              f                 11          D                 f                  f1",
        "1                f                               11                                                1",
        "1                                 1              11                                                1",
        "1                                010             11                         R                      1",
        "1                        f        0              11             Q                          D       1",
        "1      R                   B                     11                    f            f              1",
        "1                                        s       11          f                                     1",
        "1                                                11                                                1",
        "1       D                                        00                                   s            1",
        "1     f                      oooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo1",
        "1                            oooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo1",
        "1                  R                             11                       ooo                      1",
        "1                                                00               s       ooo                      1",
        "1111111111111111111111111111111111111111111111111  1111111111111111111111111111111111111111111111111",
        "1000000000000000000000000000000000000000000000000 i0000000000000000000000000000000000000000000000001",
        "1 s     f                                        11                       ooo                      1",
        "1                                                11    f                  ooo                 f    1",
        "1     f                  f                       11                       ooo                      1",
        "1          R                         R    f      11                f      ooo                      1",
        "1           f                                    11       R               ooo           f          1",
        "1                               f         D      11             f         ooo                      1",
        "1  R                  0                          11                  D    ooo                      1",
        "1              f     0R0                         11   f                   ooo     f            R   1",
        "1                   oo0oooooooooooooooooooooooooo11oooooooooooooooooooooooooo                      1",
        "1    f              ooooooooooooooooooooooooooooo11oooooooooooooooooooooooooo s         D          1",
        "1         R                                      11                       ooo                      1",
        "1         f                         f            11                       ooo                      1",
        "1                  D               R             11            f          ooo           f     111111",
        "1            R             s                     11   R                   ooo            11111100000",
        "1              f                          R      11                 0     ooo      R  111100000     ",
        "1s                                               11        D       1s1    ooo      1110000          ",
        "11111111111111111111111111111111111111111111111111111111111111111111111111111111111111              ",
        "00000000000000000000000000000000000000000000000000000000000000000000000000000000000000              ",
        "                                                                                                    ",
        "                                                                                                    ",
        "                                                                                                    ",
        "                                                                                                    ",
        "                                                                                                    "

};

void lvl_drawing_1(RenderWindow &window, bool isLvl1){
    if(isLvl1){
        for (int i = 0; i < HEIGHT_LVL; i++)
            for (int j = 0; j < WIDTH_LVL; j++){
                // Локация старта
                if (TileLVL[i][j] == ' ')s_map.sprite.setTextureRect(IntRect(4, 1, 48, 48));  //если встретили символ пробел, то рисуем 1й квадратик
                if(TileLVL[i][j] == 'D')s_map.sprite.setTextureRect(IntRect(4, 1, 48, 48));
                if (TileLVL[i][j] == 's')s_map.sprite.setTextureRect(IntRect(47, 0, 48, 48)); //если встретили символ s, то рисуем 2й квадратик
                if (TileLVL[i][j] == '0')s_map.sprite.setTextureRect(IntRect(96, 0, 48, 48)); //если встретили символ 0, то рисуем 3й квадратик
                if (TileLVL[i][j] == 'f') s_map.sprite.setTextureRect(IntRect(148, 0, 48, 48)); // объект отвечающий за урон
                if (TileLVL[i][j] == 'h')s_map.sprite.setTextureRect(IntRect(193, 0, 48, 48)); // объект отвечающий за выстоновление жизни
                if (TileLVL[i][j] == '1')s_map.sprite.setTextureRect(IntRect(242, 0, 48, 48));
                if (TileLVL[i][j] == 'i')s_map.sprite.setTextureRect(IntRect(293, 0, 48, 48));
                if (TileLVL[i][j] == 'o')s_map.sprite.setTextureRect(IntRect(822, 0, 48, 48));
                if (TileLVL[i][j] == 'B')s_map.sprite.setTextureRect(IntRect(342,0,48,48));
                if (TileLVL[i][j] == 'R')s_map.sprite.setTextureRect(IntRect(394, 0, 48, 48));
                if (TileLVL[i][j] == 'Q')s_map.sprite.setTextureRect(IntRect(446, 0, 48, 48));

                s_map.sprite.setPosition(j * 48, i * 48); //по сути раскидывает квадратики, превращая в карту, то есть задает каждому из них позицию, если убрать, то вся карта нарисуется в одном квадрате 32*32 и мы увидим один квадрат
                window.draw(s_map.sprite); //рисуем квадратики на экран
            }
    }
    //Location_of_Objects_LVL1(window, isLvl1);
}
//                                            LVL 2
const int HEIGHT_LVL2 = 41;//размер карты высота
const int WIDTH_LVL2 = 110;//размер карты ширина

String TileLVL1[HEIGHT_LVL2] = {
        "3M5555555555555555555555555755555555555555555555555555555555555555555555555555555555555555555555555555555n333",
        "2mM55555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555nN222",
        "22m33333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333N2222",
        "222v444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444222222",
        "22vV...................................................................................................52",
        "2vV5...................................................................................................52",
        "2V55...................................................................................................52",
        "255.....................55555.....5555.................................................................52",
        "255................555555............55555s.s..........................................................52",
        "255......................................sssss..................Z......................................52",
        "255.......................................sss..................767.....................................52",
        "255...........................Z............s..................Z6z6Z....................................52",
        "255....................................................A.......767.....................................52",
        "255.............................................................Z......................................52",
        "255.7....55555555555555655555555...................555555555555........................................52",
        "255.55..5555555665555555...............................................................................52",
        "255.7...5855555566677555588555555555.........................................555.......................52",
        "255.7.....55555577777755555555555........................................5555555555....................52",
        "255.55..5555555555555555...............................................55555333333555..................52",
        "255.......................................555...........................5553v444445....................52",
        "255......................................................................33vV55555.....................52",
        "255......................................................................2vV55555......................52",
        "255....................................................................................................52",
        "255................5555.....6..........................................................................52",
        "255.......................777..........................................................................52",
        "255.......................7......................7.....................................................52",
        "255......................667...................77777...................................................52",
        "255...........................................7...77...................................................52",
        "255................................................7...................................................52",
        "255....................................................................................................52",
        "255....................................................................................................52",
        "255....................................................................................................52",
        "255....................................................................................................52",
        "2M55...................................................................................................52",
        "2mM55..................................................................................................52",
        "22mM555................................................................................................52",
        "222m33333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333332",
        "22222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222",
        "22222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222",
        "222v44444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444V2",
        "55555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555",
};
void lvl_drawing_2(RenderWindow &window, bool isLVL2){
    if(isLVL2){
        for(int i = 0; i < HEIGHT_LVL2; i++)
            for(int j = 0; j < WIDTH_LVL2; j++){
                if (TileLVL1[i][j] == '2')o_map.sprite.setTextureRect(IntRect(0, 0, 48, 48));
                if (TileLVL1[i][j] == '3')o_map.sprite.setTextureRect(IntRect(51.8, 0, 48, 48));
                if (TileLVL1[i][j] == '4')o_map.sprite.setTextureRect(IntRect(101.8, 0, 48, 48));
                if (TileLVL1[i][j] == '5')o_map.sprite.setTextureRect(IntRect(150, 0, 48, 48));
                if (TileLVL1[i][j] == '6')o_map.sprite.setTextureRect(IntRect(200, 0, 48, 48));
                if (TileLVL1[i][j] == '.')o_map.sprite.setTextureRect(IntRect(248, 0, 48, 48));
                if (TileLVL1[i][j] == '7')o_map.sprite.setTextureRect(IntRect(300, 0, 48, 48));

                if(TileLVL1[i][j] == 'm')o_map.sprite.setTextureRect(IntRect(394, 0, 48, 48));
                if(TileLVL1[i][j] == 'M')o_map.sprite.setTextureRect(IntRect(442, 0, 48, 48));
                if(TileLVL1[i][j] == 'n')o_map.sprite.setTextureRect(IntRect(486, 0, 48, 48));
                if(TileLVL1[i][j] == 'N')o_map.sprite.setTextureRect(IntRect(534, 0, 48, 48));
                if(TileLVL1[i][j] == 'b')o_map.sprite.setTextureRect(IntRect(586, 0, 48, 48));
                if(TileLVL1[i][j] == 'B')o_map.sprite.setTextureRect(IntRect(634, 0, 48, 48));
                if(TileLVL1[i][j] == 'v')o_map.sprite.setTextureRect(IntRect(682, 0, 48, 48));
                if(TileLVL1[i][j] == 'V')o_map.sprite.setTextureRect(IntRect(726, 0, 48, 48));
                if(TileLVL1[i][j] == 'Z')o_map.sprite.setTextureRect(IntRect(778, 0, 48, 48));
                if(TileLVL1[i][j] == 'z')o_map.sprite.setTextureRect(IntRect(824, 0, 48, 48));
                if(TileLVL1[i][j] == 's')o_map.sprite.setTextureRect(IntRect(870, 0, 48, 48));
                if(TileLVL1[i][j] == 'A')o_map.sprite.setTextureRect(IntRect(920, 0, 48, 48));

                o_map.sprite.setPosition(j * 48, i * 48);
                window.draw(o_map.sprite);
            }
    }
    Location_of_Objects_LVL2(window, isLVL2);
}
//                                       LVL 3
const int HEIGHT_LVL3 = 40;//размер карты высота
const int WIDTH_LVL3 = 90;//размер карты ширина

String TileLVL2[HEIGHT_LVL3] = {
        "000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000",
        "1........................................................................................1",
        "1                                                                                        1",
        "1                                                                                        1",
        "1                                                                                        1",
        "1                                                                                        1",
        "1                                                                                        1",
        "1                                                                                        1",
        "1                                                                                        1",
        "1                                                                                        1",
        "1                                                                                        1",
        "1                                                                                        1",
        "1                                                                                        1",
        "1                                                                                        1",
        "1                                                                                        1",
        "1                                                                                        1",
        "1                                                                                        1",
        "1                                                                                        1",
        "1                                                                                        1",
        "1                                                                                        1",
        "1                                                                                        1",
        "1                                                                                        1",
        "1                                                                                        1",
        "1                                                                                        1",
        "1                                                                                        1",
        "1                                                                                        1",
        "1                                                                          G             1",
        "1                                                                                        1",
        "1                                                                                        1",
        "1                                                                                        1",
        "1                                                                                        1",
        "1                                                                                        1",
        "1                                                                                        1",
        "1                                                                                        1",
        "1                                                                                        1",
        "1                                                                                        1",
        "1                                                                                        1",
        "1                                                                                        1",
        "000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000",
        "..........................................................................................",
};
void lvl_drawing_3(RenderWindow &window, bool isLVL3){
    if(isLVL3){
        for (int i = 0; i < HEIGHT_LVL3; i++)
            for (int j = 0; j < WIDTH_LVL3; j++) {
                if (TileLVL2[i][j] == '0')t_map.sprite.setTextureRect(IntRect(0, 0, 48, 48));
                if (TileLVL2[i][j] == '1')t_map.sprite.setTextureRect(IntRect(51, 0, 48, 48));
                if (TileLVL2[i][j] == ' ')t_map.sprite.setTextureRect(IntRect(98, 0, 48, 48));
                if (TileLVL2[i][j] == '.')t_map.sprite.setTextureRect(IntRect(144, 0, 48, 48));
                if (TileLVL2[i][j] == 'I')t_map.sprite.setTextureRect(IntRect(338, 0, 48, 48));
                if (TileLVL2[i][j] == 'G')t_map.sprite.setTextureRect(IntRect(386, 0, 48, 48));

                t_map.sprite.setPosition(j * 48, i * 48);
                window.draw(t_map.sprite);
            }
    }
    Location_ofObjects_LVL3(window, isLVL3);
}
void randomMapGenerate(int &isFigh){

    int randomElementX = 0;//случайный элемент по горизонтали
    int randomElementY = 0;//случ эл-т по вертикали
    int countStone = 2;//количество камней

    while (countStone>0){
        randomElementX = 1 + rand() % (WIDTH_LVL3 - 1);//рандомное по иксу от 1 до ширина карты-1, чтобы не получать числа бордюра карты
        randomElementY = 1 + rand() % (HEIGHT_LVL3 - 1);//по игреку так же

        if (TileLVL2[randomElementY][randomElementX] == ' ')   {//если встретили символ пробел,
            if(isFigh < 5){TileLVL2[randomElementY][randomElementX] = 'I';} //то ставим туда камень.
            //std::cout << "coordinate of Stone X:" << randomElementX << "\n" << "coordinate of Stone Y:" << randomElementY << "\n\n";
            countStone--;
        }
    }
}
#endif //TEST_SFML_LVL_PROJECT_H