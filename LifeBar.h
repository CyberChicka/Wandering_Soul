#ifndef WANDERING_SOUL_LIFEBAR_H
#define WANDERING_SOUL_LIFEBAR_H

using namespace sf;

class LifeBar
{
public:
    Image image; Texture t; Sprite s;
    int max;
    RectangleShape bar;
    LifeBar()
    {
        image.loadFromFile("images/lifeBarBoss.png");
        image.createMaskFromColor(Color(50, 96, 166));
        t.loadFromImage(image);
        s.setTexture(t);
        bar.setFillColor(Color(0, 0, 0));//черный прямоугольник накладывается сверху и появляется эффект отсутствия здоровья
        max = 1200;
    }
    void update(int &k)// k-текущее здоровье
    {
        if (k>0)
            if (k<max)
                bar.setSize(Vector2f((max - k) * 320 / max, 26));//если не отрицательно и при этом меньше максимума, то устанавливаем новое значение (новый размер) для черного прямоугольника
    }

    void draw(RenderWindow &window, int scrn)
    {
        if(scrn == 1){
            s.setPosition(view.getCenter().x-180, view.getCenter().y+290);//позиция на экране
            bar.setPosition(view.getCenter().x-128, view.getCenter().y+322);
        }
        if(scrn == 2){}
        if(scrn == 3){
            s.setPosition(view.getCenter().x-180,view.getCenter().y+300);//позиция на экране
            bar.setPosition(view.getCenter().x-128,view.getCenter().y+332);
        }
        window.draw(s);//сначала рисуем полоску здоровья
        window.draw(bar);//поверх неё уже черный прямоугольник, он как бы покрывает её
    }

};

#endif //WANDERING_SOUL_LIFEBAR_H
