/*
Course: Hardware oriented programming
Assignment nr.: 12
Student Name: Mads Richardt
Student id.: s224948
Date: 2022-12-02
*/

#include "musicBox.h"

#define BUZZER_PIN 2

StateMachine myMusicBox;

// Mester Jakob
const char jakob[] = "t10,f4,g4,a4,f4,f4,g4,a4,f4,a4,h-4,c>8,a4,h-4,c>8,"
                     "c>2,d>2,c>2,h-2,a4,f4,c>2,d>2,c>2,h-2,a4,f4,f4,c4,f8,f4,c4,f8,";

// Olsenbanden
const char olsen[] = "t8,d4,e-4,d2,e-4,f10,p8,d4,e-4,f2,g4,a-10,p8,g4,a-4,g4,"
                     "a-2,h-4,h-4,h-2,a4,g4,f4,f4,f-4,e-4,d4,f2,f4,g2,f4,e-16,p4,e-2,e-4,f2,e-4,"
                     "d16,p4,f2,f4,g2,f4,e-16,p4,e-2,e-4,f2,e-4,d32,c>4,c#>4,d>4,e>4,f>4,c>4,p8,"
                     "p4,c>2,c>4,c->2,h-4,a16,c>4,c#>4,d>4,e>4,f>4,c>4,p8,p4,c>2,c>4,d>2,e>4,f>16,"
                     "d4,e-4,d2,e-4,f10,p8,d4,e-4,f2,g4,a-10,p8,g4,a-4,g4,a-2,h-4,h-4,h-2,a4,g4,f4,"
                     "f4,f-4,e-4,d4,f2,f4,g2,f4,e-16,p4,e-2,e-4,f2,e-4,d16,p4,f2,f4,g2,f4,e-16,p4,"
                     "f2,f4,g2,a4,h-4,p4,h-<4,p4,";

// Marseillaisen
const char marseille[] = "t20,d1,d3,d1,g4,g4,a4,a4,d>6,h2,g2,p1,g1,h3,g1,"
                         "e4,c>8,a3,f#1,g8,p3,g1,g3,a1,h4,h4,h4,c>3,h1,h4,a4,p4,a3,h1,c>4,c>4,c>4,d>3,"
                         "c>1,h8,p4,d>3,d>1,d>4,h3,g1,d>4,h3,g1,d8,p3,d1,d3,f#1,a8,c>4,a3,f#1,"
                         "a4,g4,f8,e4,g3,g1,g4,f#3,g1,a8,p4,p2,a2,h-6,h-2,h-2,h-2,c>2,d>2,a12,h-2,a2,"
                         "g6,g2,g2,h-2,a2,g2,g4,f#2,p8,p1,d>1,d>11,d>1,h3,g1,a12,p3,d>1,d>11,d>1,h3,g1,"
                         "a10,p2,d4,g8,p4,a4,h8,p8,c>8,d>4,e>4,a10,p2,e>4,d>11,h1,c>3,a1,g12,p4,";
// Sound of silence
const char silence[] = "t30,p2,d1,d1,f1,f1,a1,a1,g8,p1,c1,c1,c1,e1,e1,g1,g1,"
                       "f8,p1,f1,f1,f1,a1,a1,c>1,c>1,d>4,c>4,p2,f1,f1,a1,a1,c>1,c>1,d>4,c>4,p2,f1,f1,"
                       "d>1,d>5,d>1,e>1,f>1,f>3,e>1,d>3,c>6,d>1,c>1,a8,p1,f1,f1,f1,c>6,p1,e1,f1,d7,";

void setup()
{
    pinMode(BUZZER_PIN, OUTPUT);
    myMusicBox.speaker = BUZZER_PIN;
}

void loop()
{
    myMusicBox.play(marseille);
    myMusicBox.play(silence);
    myMusicBox.play(olsen);
    myMusicBox.play(jakob);
}
