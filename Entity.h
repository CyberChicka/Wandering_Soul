#ifndef TEST_SFML_ENTITY_H
#define TEST_SFML_ENTITY_H

using namespace sf;
using namespace std;
// ///////////////////////////////////// Класс Организация ////////////////////////////////////////////////////

class Entity {
public:
    float dx, dy, x, y, speed = 0, moveTimer;//добавили переменную таймер для будущих целей
    int w, h, health;
    bool life = true;
    Texture texture; Sprite sprite;
    Clock clock; Clock gmTimeClock; int gameTime = 0;
    bool mous = true;
    float *time = new float; float CurrentFrame;
    String name;
    Entity(Image &image, float X, float Y, int W, int H, String Name){
        x = X;y = Y;w = W;h = H; name = Name; moveTimer = 0;
        speed = 0; health = 120; dx = 0; dy = 0;
        life = true;
        texture.loadFromImage(image);
        sprite.setTexture(texture);
        sprite.setOrigin(w/2,h/2);
        sprite.setTextureRect(IntRect(0, 0, w, h));
    }
    //virtual void update(float time) = 0;
};

#endif //TEST_SFML_ENTITY_H
