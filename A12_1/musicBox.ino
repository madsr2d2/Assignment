#include <Arduino.h>
#include <AceCommon.h>

// table of frequencies
const unsigned int freq[36] = {
    // c d e f g a h
    131, 139, 147, 156, 165, 175, 185, 196, 208, 220, 233, 247, // low octave
    262, 277, 294, 311, 330, 349, 370, 392, 415, 440, 466, 494, // default octave
    523, 554, 587, 622, 659, 698, 740, 784, 831, 880, 932, 988  // high octave
};

void setup() {
}

void loop() {
    
}
