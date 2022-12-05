
#ifndef WANDERING_SOUL_MUSICSOUND_H
#define WANDERING_SOUL_MUSICSOUND_H

SoundBuffer buffer_dead, bufr, buf_molnii, buf_UseGun;
Sound sound_dead, soud, SoundUseGun;
Sound pressed_mouse, pressed_nps, sound_Bur, soundChanSaw, Perem_fire, udar_molnii;
SoundBuffer pressed_mouse1, pressed_nps1, sound_Bur1, soundChanSaw1, Perem_fire1;
Music music_lvl_1, Music_FightBoss, music_lvl_2;// music_lvl2_1;//создаем объект музыки
Music Music_LvL1Start;
//Music Music_FightBoss;

void volume(Music &music){
    string name = "Save/sound.txt";
    ifstream fin;
    fin.open(name);
    if(fin.is_open()){
        while (!fin.eof()){
            fin >> vol;
        }
    } else{ cout << "Error"<< endl; }
    fin.close();
    switch (vol) {
        case 1: music.setVolume(10); break;
        case 2: music.setVolume(20);break;
        case 3: music.setVolume(30);break;
        case 4: music.setVolume(40);break;
        case 5: music.setVolume(50);break;
        case 6: music.setVolume(60);break;
        case 7: music.setVolume(70); break;
        case 8: music.setVolume(80); break;
        case 9: music.setVolume(90); break;
        case 10: music.setVolume(100); break;
    }
}
void sound(Sound &sound){
    string name = "Save/sound.txt";
    ifstream fin;
    fin.open(name);
    if(fin.is_open()){
        while (!fin.eof()){
            fin >> vol;
        }
    } else{ cout << "Error"<< endl; }
    fin.close();
    switch (vol) {
        case 1: sound.setVolume(10); break;
        case 2: sound.setVolume(20);break;
        case 3: sound.setVolume(30);break;
        case 4: sound.setVolume(40);break;
        case 5: sound.setVolume(50);break;
        case 6: sound.setVolume(60);break;
        case 7: sound.setVolume(70); break;
        case 8: sound.setVolume(80); break;
        case 9: sound.setVolume(90); break;
        case 10: sound.setVolume(100); break;
    }
}

void music_Sound(){
    music_lvl_1.openFromFile("Music/LVL1.ogg");//загружаем файл
    music_lvl_1.setLoop(true);
    volume(music_lvl_1);

    Music_LvL1Start.openFromFile("Music/Lvl_1Vell.ogg");
    Music_LvL1Start.setLoop(true);
    volume(Music_LvL1Start);

    music_lvl_2.openFromFile("Music/LVL2.ogg");
    music_lvl_2.setLoop(true);
    volume(music_lvl_2);

    Music_FightBoss.openFromFile("Music/Boss_Music.ogg");
    Music_FightBoss.setLoop(true);
    volume(Music_FightBoss);

    buf_UseGun.loadFromFile("Music/UseGun.ogg"); SoundUseGun.setBuffer(buf_UseGun);
    sound(SoundUseGun);
    buf_molnii.loadFromFile("Music/udar-molnii.ogg"); udar_molnii.setBuffer(buf_molnii);
    sound(udar_molnii);
    Perem_fire1.loadFromFile("Music/Perem_fire.ogg"); Perem_fire.setBuffer(Perem_fire1);
    sound(Perem_fire);
    sound_Bur1.loadFromFile("Music/SoundBur.ogg"); sound_Bur.setBuffer(sound_Bur1);
    sound(sound_Bur);
    pressed_nps1.loadFromFile("Music/Dialog_nps1.ogg"); pressed_nps.setBuffer(pressed_nps1);
    sound(pressed_nps);
    pressed_mouse1.loadFromFile("Music/PressedMouse.ogg"); pressed_mouse.setBuffer(pressed_mouse1);
    sound(pressed_mouse);
    //pressed_mouse.setVolume(100);// настраивает громкость
    buffer_dead.loadFromFile("Music/game-over-3.ogg"); sound_dead.setBuffer(buffer_dead);
    sound(sound_dead);
    bufr.loadFromFile("Music/mech-sablya-vzmah.ogg"); soud.setBuffer(bufr);
    sound(soud);
    soundChanSaw1.loadFromFile("Music/benzopila-pilit.ogg"); soundChanSaw.setBuffer(soundChanSaw1);
    sound(soundChanSaw);
}

#endif //WANDERING_SOUL_MUSICSOUND_H
