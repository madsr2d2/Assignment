#include "musicBox.h"
#include <iostream>
using namespace std;

const char pippi[] = "t20,c2,f1,f1,a2,f2,g4,h-1,a1,g1,f1,e2,g1,e1,c2,e2,f4,a4,"
					 "c2,f2,a2,f2,g4,h-1,a1,g1,f1,e2,g1,e1,c2,e2,f6,p2,c2,f2,a2,f2,g4,h-1,a1,g1,f1,"
					 "e2,g1,e1,c2,e2,f4,a4,c2,f2,a2,f2,g4,h-1,a1,g1,f1,e2,g1,e1,c2,e2,f6,p2,a2,a1,"
					 "a1,a2,a2,h-3,h-3,h-1,a1,g2,g1,g1,g2,g1,f1,e2,f2,g2,p2,a2,a1,a1,a2,a2,h-4,h-2,"
					 "h-1,a1,g2,g2,f2,e2,f8,";

int main()
{
	MusicBox myMusicBox;
	
	myMusicBox.play(pippi);

	return 0;
}