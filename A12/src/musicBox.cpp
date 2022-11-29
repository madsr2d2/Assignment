#include "musicBox.h"

//  function  to  play  a  tune
void MusicBox::play(const char *tune)
{
    p = tune;      //  pointer  to  tune  string timebase  =  20; //  default  time  base
    state = Start; //  start  in  state  Start
    c = *p;        //  read  first  character
    p++;           //  advance  pointer  for  reading  next  character

    //  run  state  machine
    while (state != Stop)
    {
        switch (state)
        {
        case Start: //  Read  next  item SStart();  break;

        case T1: //  interpret  timebase ST1(); break;

        case T2: //  state  T2:  calculate  timebase ST2(); break;

        case T3: //  state  T3:  save  timebase ST3(); break;

        case P1: //  state  P1:  interpret  pause SP1();  break;

        case P2: //  state  P2:  calculate  length  of  pause SP2(); break;

        case P3: //  state  P3:  play  pause SP3(); break;

        case N1: //  state  N1:  interpret  note SN1(); break;

        case N2: //  state  N2:  calculate  length  of  note SN2(); break;

        case N3: //  state  N3:  play  note SN3(); break;

        case Error: //  state  error SError();
        default:
            break;

        } //  end  switch  (state)
    }     //  end  while
}

void MusicBox::SStart()
{ //  start state
    switch (c)
    {
    case 't': //  interpret  timebase
        state = T1;
        break;
    case 'p': //  pause
        state = P1;
        break;
    case 'a': //  note  a  -  h
    case 'b':
    case 'c':
    case 'd':
    case 'e':
    case 'f':
    case 'g':
    case 'h':
        state = N1;
        break;
    case ',': //  ignore  comma break;
    case 0:   //  end  of  string
        state = Stop;
        break;
    default: //  anything  else  should  give  an  error state  =  Error;
        break;
    }
}