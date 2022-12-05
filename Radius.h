#ifndef WANDERING_SOUL_RADIUS_H
#define WANDERING_SOUL_RADIUS_H

class Radius{
public:
    float x, y;
    int w, h;
    Texture texture;
    Sprite sprite;
    Radius(Image &image, float X, float Y, int W, int H, String name){
        x = X; y = Y; w = W; h = H;
        sprite.setOrigin(w/2, h/2);
        texture.loadFromImage(image);
        sprite.setTexture(texture);
        sprite.setTextureRect(IntRect(0,0,w,h));
    }
    FloatRect getRect(){ return FloatRect(x,y,w,h);}
    void update(){
        sprite.setPosition(x,y);
    }
};


#endif //WANDERING_SOUL_RADIUS_H
