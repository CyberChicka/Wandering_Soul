#ifndef WANDERING_SOUL_EVENTFUNCTION_H
#define WANDERING_SOUL_EVENTFUNCTION_H

void Inventory(Event event, bool &invent, Vector2<float> pos){
    if(event.type == Event::MouseButtonPressed){
        if(event.key.code == Mouse::Left && (open.sprite.getGlobalBounds().contains(pos.x, pos.y))){
            switch (invent) {
                case true:
                    open.sprite.setTextureRect(IntRect(48, 0, 48, 48));
                    invent = false; break;
                case false:invent = true; break;
            }
        }
    }
    if(event.type == Event::KeyPressed){
        if (event.key.code == Keyboard::I){
            switch (invent) {
                case true:
                    open.sprite.setTextureRect(IntRect(48, 0, 48, 48));
                    invent = false; break;
                case false:invent = true; break;
            }
        }
    }
}
void OpenBook(Event event, bool &isBook){
    if(event.type == Event::KeyPressed)
        if(event.key.code == sf::Keyboard::Tab){
            switch (isBook){
                case true: isBook = false; break;
                case false: isBook = true; break;
            }
        }
}
void modeBur(Event event, bool ModeBur, bool &isBurBreak){
    if(event.type == Event::KeyPressed)
        if(event.key.code == Keyboard::Space){
            if(ModeBur){
                switch (isBurBreak){
                    case true: isBurBreak = false; break;
                    case false: isBurBreak  = true; break;
                }
            }
        }
}

#endif //WANDERING_SOUL_EVENTFUNCTION_H
