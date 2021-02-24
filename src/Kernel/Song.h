#pragma once
#include <stdint.h>
#include "PIT.h"
#include "Timer.h"

#define note_C 262
#define note_Cis 277
#define note_D 294
#define note_Dis 311
#define note_E 330
#define note_F 350
#define note_Fis 370
#define note_G 392
#define note_Gis 415
#define note_A 440
#define note_Bb 466
#define note_B 494

#define low_C 131
#define low_Cis 139
#define low_D 147
#define low_Dis 156
#define low_E 165
#define low_F 175
#define low_Fis 185
#define low_G 196
#define low_Gis 208
#define low_A 220
#define low_Bb 233
#define low_B 247

#define high_C 523
#define high_Cis 554
#define high_D 587
#define high_Dis 622
#define high_E 659
#define high_F 698
#define high_Fis 740
#define high_G 784
#define high_Gis 831
#define high_A 880
#define high_Bb 932
#define high_B 988

void playSong(uint_8 num);