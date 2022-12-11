/*
Course: Hardware oriented programming
Assignment nr.: 12
Student Name: Mads Richardt
Student id.: s224948
Date: 2022-12-02
*/

#if !defined(MUSIC_BOX_H)
#define MUSIC_BOX_H

#include <Arduino.h>
#include <AceCommon.h>

// table of frequencies
const unsigned int freq[36] = {
    // c d e f g a h
    131, 139, 147, 156, 165, 175, 185, 196, 208, 220, 233, 247, // low octave
    262, 277, 294, 311, 330, 349, 370, 392, 415, 440, 466, 494, // default octave
    523, 554, 587, 622, 659, 698, 740, 784, 831, 880, 932, 988  // high octave
};

// Name states for state machine
enum States {
    Start, // start or after comma
    T1,    // after 't': interpret timebase
    T2,    // after T1 and at least one digit: calculate tempo
    T3,    // after T2 and comma: save tempo
    N1,    // after note a-h or #-<>: Interpret note
    N2,    // after N1 and at least one digit: Calculate duration
    N3,    // after N2 and comma: Play note
    P1,    // after 'p'. Interpret pause
    P2,    // after P1 and at least one digit: Calculate duration
    P3,    // after P2 and comma: Play pause
    Stop,  // finished
    Error  // syntax error
};

// The class StateMachine defines a state machine for interpreting a music string
class StateMachine {
    private:
        States state;    // state in syntax parsing
        int timebase;    // time unit
        int pitch;       // note to play
        int duration;    // duration of note or pause
        const char *p;   // position in tune string
        char c;          // current character in tune string

        // Start 
        void SStart();
        // Interpret tempo
        void ST1();
        // Calculate tempo
        void ST2();
        // Save tempo
        void ST3();
        // Interpret pause
        void SP1();
        // Calculate length of pause
        void SP2();
        // Play pause
        void SP3();
        // Interpret note
        void SN1();
        // Calculate length of note
        void SN2();
        // Play note
        void SN3();
        // Exit program on error
        void SError();
        // Close program
        void SStop();

    public:
        int speaker = 2; // Pin connected to buzzer on arduino
        // Play the tune
        int play(const char *tune);
};

#endif // MUSIC_BOX_H