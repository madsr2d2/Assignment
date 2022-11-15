#include <iostream>
#include <cstdio>
#include <stdlib.h>

using namespace std;

#include "database.h"

int main(void)
{
	char scvFile[100] = "database";
	
	DataBase database;
	database.loadScvFile(scvFile);
	database.view();
	database.bubbleSort();
	database.view();

}