
#ifndef WANDERING_SOUL_ISBOOK_H
#define WANDERING_SOUL_ISBOOK_H

#include "TextAndImages.h"

using namespace std;
using namespace sf;

int isPage = 1;

string text_book(int Click, int st){
    string  MasText = " ";
    if(Click == 1){
        if(st == 1){
            MasText = "\n1 NPC - Page, an unusual name"
                      "\nApparently, this is a local guide, \n he is somehow strangely dressed\n",
                    "\n \n",
                    "\n \n",
                    "\n \n",
                    "\n \n",
                    "\n \n",
                    "\n \n";
        }
        if(st == 2){
            MasText = "\n bbbbbbb"
                      "\n \n",
                    "\n \n",
                    "\n \n",
                    "\n \n",
                    "\n \n",
                    "\n \n",
                    "\n \n";
        }
    }
    if(Click == 2){
        if(st == 1){
            MasText = " ";
        }
        if(st == 2){

        }
    }
    if(Click == 3){
        if(st == 1){
            MasText = " ";
        }
        if(st == 2){

        }
    }
    if(Click == 4){
        if(st == 1){
            MasText = " ";
        }
        if(st == 2){

        }
    }
    if(Click == 5){
        if(st == 1){
            MasText = " ";
        }
        if(st == 2){

        }
    }
    if(Click == 6){
        if(st == 1){
            MasText = " ";
        }
        if(st == 2){

        }
    }
    if(Click == 7){
        if(st == 1){
            MasText = " ";
        }
        if(st == 2){

        }
    }
    if(Click == 8){
        if(st == 1){
            MasText = " ";
        }
        if(st == 2){

        }
    }
    if(Click == 9){
        if(st == 1){
            MasText = " ";
        }
        if(st == 2){

        }
    }
    if(Click == 10){
        if(st == 1){
            MasText = " ";
        }
        if(st == 2){

        }
    }
    return MasText;
}

void book(RenderWindow &window, Event &ev){
    window.setView(view);
    screen();

    text_isBookPage.text.setColor(Color::Black); text_isBookPage.text.setStyle(Text::Bold);
    text_isBook.text.setColor(Color::Blue); text_isBook.text.setStyle(Text::Bold);
    text_isBook2.text.setColor(Color::Blue); text_isBook2.text.setStyle(Text::Bold);
    switch (scrn) {
        case 1:
            text_isBook.text.setCharacterSize(20);
            text_isBook.text.setPosition(view.getCenter().x - 500, view.getCenter().y - 200);
            text_isBook2.text.setCharacterSize(20);
            text_isBook2.text.setPosition(view.getCenter().x + 500, view.getCenter().y - 200);
            Book_Sprite_mini.sprite.setPosition(view.getCenter().x - 580, view.getCenter().y - 400);
            break;
        case 2: break;
        case 3:
            text_isBook.text.setCharacterSize(25);
            text_isBook.text.setPosition(view.getCenter().x - 580, view.getCenter().y - 400);
            text_isBook2.text.setCharacterSize(25);
            text_isBook2.text.setPosition(view.getCenter().x + 380, view.getCenter().y - 400);

            Book_Sprite.sprite.setPosition(view.getCenter().x - 920, view.getCenter().y - 550);
            book_isPravo.sprite.setPosition(view.getCenter().x + 500, view.getCenter().y + 200);
            book_isLevo.sprite.setPosition(view.getCenter().x - 650, view.getCenter().y + 200);
            text_isBookPage.text.setPosition(view.getCenter().x - 3, view.getCenter().y + 200);
            break;
    }
    int isNum = 0;

    ostringstream PAGE;
    ostringstream Message, Message2;
    Book_Sprite_mini.sprite.setColor(Color::White);
    Book_Sprite.sprite.setColor(Color::White);
    book_isLevo.sprite.setColor(Color::White);
    book_isPravo.sprite.setColor(Color::White);
    switch (scrn){
        case 1: break;
        case 2: break;
        case 3:
            if(IntRect(1450, 750, 200, 100).contains(Mouse::getPosition(window))){ book_isPravo.sprite.setColor(Color::Blue); isNum = 1;}
            if(IntRect(300, 750, 200, 100).contains(Mouse::getPosition(window))){ book_isLevo.sprite.setColor(Color::Blue); isNum = 2;}
            break;
    }
    window.clear();

    if(ev.type == Event::MouseButtonPressed){
        if(ev.key.code == Mouse::Left){
            if(isNum == 1){ if(isPage < 10){ isPage++; } }
            if(isNum == 2){ if(isPage > 1){ isPage--; } }
        }
    }

    Message << text_book(isPage, 1);
    Message2 << text_book(isPage, 2);
    text_isBook.text.setString(Message.str());
    text_isBook2.text.setString(Message2.str());


    PAGE << isPage;
    text_isBookPage.text.setString(PAGE.str());
    cout << ""<< endl;


    if(scrn == 3){ window.draw(Book_Sprite.sprite);}
    if(scrn == 1){ window.draw(Book_Sprite_mini.sprite);}
    window.draw(book_isLevo.sprite);
    window.draw(book_isPravo.sprite);
    window.draw(text_isBookPage.text);
    window.draw(text_isBook.text);
    window.draw(text_isBook2.text);

    window.display();
}

#endif //WANDERING_SOUL_ISBOOK_H
