#ifndef VIEW_H
#define VIEW_H
using namespace sf;
using namespace std;
View view; //объявляем SFML объект вид, который и является камерой
View getPlayerCoordinateForView(float x, float y){ // функция для считывания движения игрока
    float tempX = x; float tempY = y;
    view.setCenter(tempX, tempY); // Следим за игроком передавая его координаты
    return view;
}
#endif