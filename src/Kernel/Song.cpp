#include "Song.h"

void playSong(uint_8 num)
{
    //Twinkle twinkle
    if(num == 1)
    {
        play_sound(294);
        Sleep(1000);
        nosound();

        play_sound(440);
        Sleep(1000);
        nosound();

        play_sound(494);
        Sleep(1000);
        nosound();

        play_sound(440);
        Sleep(500);
        nosound();

        Sleep(500);

        play_sound(392);
        Sleep(1000);
        nosound();

        play_sound(370);
        Sleep(1000);
        nosound();

        play_sound(330);
        Sleep(1000);
        nosound();

        play_sound(294);
        Sleep(500);
        nosound();
    }

    //SIMP
    if(num == 2)
    {
        play_sound(note_C);
        Sleep(600);
        nosound();
        play_sound(note_E);
        Sleep(400);
        nosound();
        play_sound(note_Fis);
        Sleep(400);
        nosound();
        play_sound(note_A);
        Sleep(200);
        nosound();
        play_sound(note_G);
        Sleep(600);
        nosound();
        play_sound(note_E);
        Sleep(400);
        nosound();
        play_sound(note_C);
        Sleep(400);
        nosound();
        play_sound(low_A);
        Sleep(200);
        nosound();
        play_sound(low_Fis);
        Sleep(200);
        nosound();
        play_sound(low_Fis);
        Sleep(200);
        nosound();
        play_sound(low_Fis);
        Sleep(200);
        nosound();
        play_sound(low_G);
        Sleep(400);
        nosound();
        Sleep(400);
        play_sound(note_Fis);
        Sleep(200);
        nosound();
        play_sound(note_Fis);
        Sleep(200);
        nosound();
        play_sound(note_Fis);
        Sleep(200);
        nosound();
        play_sound(note_G);
        Sleep(400);
        nosound();
        play_sound(note_Bb);
        Sleep(600);
        nosound();
        play_sound(high_C);
        Sleep(400);
        nosound();
        play_sound(note_C);
        Sleep(175);
        nosound();
        Sleep(25);
        play_sound(note_C);
        Sleep(175);
        nosound();
        Sleep(25);
        play_sound(note_C);
        Sleep(175);
        nosound();
        Sleep(25);
    }
}