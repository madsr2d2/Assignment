/*
Course: Hardware oriented programming
Assignment nr.: 12
Student Name: Mads Richardt
Student id.: s224948
Date: 2022-12-02
*/

#include "musicBox.h"

// function to play a tune
int StateMachine::play(const char *tune)
{
    p = tune; // pointer to tune string timebase = 20; // default time base
    timebase = 20;
    state = Start; // start in state Start
    c = *p;        // read first character
    p++;           // advance pointer for reading next character
    // run state machine
    while (state != Stop)
    {
        switch (state)
        {
        case Start:
            SStart();
            break; // Read next item SStart(); break;
        case T1:
            ST1();
            break; // interpret timebase ST1(); break;
        case T2:
            ST2();
            break; // state T2: calculate timebase ST2(); break;
        case T3:
            ST3();
            break; // state T3: save timebase ST3(); break;
        case P1:
            SP1();
            break; // state P1: interpret pause SP1(); break;
        case P2:
            SP2();
            break; // state P2: calculate length of pause SP2(); break;
        case P3:
            SP3();
            break; // state P3: play pause SP3(); break;
        case N1:
            SN1();
            break; // state N1: interpret note SN1(); break;
        case N2:
            SN2();
            break; // state N2: calculate length of note SN2(); break;
        case N3:
            SN3();
            break; // state N3: play note SN3(); break;
        case Error:
            SError();
            return 1; // state error SError();
        case Stop:
            return 0;
        default:
            return 0;
            break;
        } // end switch (state)
    }     // end while
}
// Functions for each state:
void StateMachine::SStart()
{ // start state
    switch (c)
    {
    case 't': // interpret timebase
        state = T1;
        break;
    case 'p': // pause
        state = P1;
        break;
    case 'a': // note a - h
    case 'b':
    case 'c':
    case 'd':
    case 'e':
    case 'f':
    case 'g':
    case 'h':
        state = N1;
        break;
    case ',':  // ignore comma break;
    case '\0': // end of string
        state = Stop;
        break;
    default: // anything else should give an error state = Error;
        state = Error;
        break;
    }
}

void StateMachine::ST1()
{
    c = *p;
    timebase = (int)c - 48;
    p++;
    c = *p;
    if (c == ',')
    {
        state = T3;
    }
    else
    {
        state = T2;
    }
}

void StateMachine::ST2()
{

    timebase = timebase * 10 + (int)c - 48;
    p++;
    c = *p;
    if (c == ',')
    {
        state = T3;
    }
}

void StateMachine::ST3()
{
    p++;
    c = *p;
    state = Start;
}

void StateMachine::SN1()
{
    size_t index;

    switch (c)
    {
    case 'c':
        pitch = freq[12];
        break;
    case 'd':
        pitch = freq[14];
        break;
    case 'e':
        pitch = freq[16];
        break;
    case 'f':
        pitch = freq[17];
        break;
    case 'g':
        pitch = freq[19];
        break;
    case 'a':
        pitch = freq[21];
        break;
    case 'h':
        pitch = freq[23];
        break;
    case '-':
        index = ace_common::binarySearch(freq, 36, (const unsigned int)pitch);
        pitch = freq[index - 1];
        break;
    case '#':
        index = ace_common::binarySearch(freq, 36, (const unsigned int)pitch);
        pitch = freq[index + 1];
        break;
    case '<':
        index = ace_common::binarySearch(freq, 36, (const unsigned int)pitch);
        pitch = freq[index - 12];
        break;
    case '>':
        index = ace_common::binarySearch(freq, 36, (const unsigned int)pitch);
        pitch = freq[index + 12];
        break;
    default:
        break;
    }
    p++;
    c = *p;
    if (isDigit(c))
    {
        duration = 0;
        state = N2;
    }
}

void StateMachine::SN2()
{
    if (duration == 0)
    {
        duration = (int)c - 48;
    }
    else
    {
        duration = duration * 10 + (int)c - 48;
    }
    p++;
    c = *p;
    if (c == ',')
    {
        state = N3;
    }
}

void StateMachine::SN3()
{
    tone(speaker, pitch);
    delay(duration * 7 * timebase);
    noTone(speaker);
    delay(duration * 1 * timebase);

    p++;
    c = *p;
    state = Start;
}

void StateMachine::SP1()
{
    duration = 0;
    state = P2;
    p++;
    c = *p;
    state = P2;
}

void StateMachine::SP2()
{
    if (duration == 0)
    {
        duration = (int)c - 48;
    }
    else
    {
        duration = duration * 10 + (int)c - 48;
    }
    p++;
    c = *p;
    if (!isDigit(c))
    {
        state = P3;
    }
}

void StateMachine::SP3()
{
    delay(duration * 8 * timebase);
    p++;
    c = *p;
    state = Start;
}

void StateMachine::SError()
{
    exit(1);
}
