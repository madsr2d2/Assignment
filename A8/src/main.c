#include <stdio.h>
#include <time.h>
#include <stdlib.h>
//#include <string.h>

#define NAME_LENGTH 100

typedef struct {
	float BMI;
	float MaxPulse;
	float TargetPulseInterval[2];
} Sunhedsdata;

typedef struct
{
	char Name[NAME_LENGTH];
	char Surname[NAME_LENGTH];
	int BirthDate[3];
	float Height;
	float Weight;
	int Age;
	Sunhedsdata sd;
} Sunhedsprofil;

// Function declarations 
Sunhedsprofil getPersonalInfo(void);
void calcAge(Sunhedsprofil *sp);
void calcHartData(Sunhedsprofil *sp);

int main() 
{
	printf("Hello World!\n");

	

	//strcpy((&sp)->Name, "Mads");

	Sunhedsprofil sp = getPersonalInfo();

	calcAge(&sp);

	printf("%d",sp.Age);


	

	//struct tm tm;
	//time_t t = time(NULL);
	//struct tm *tm = localtime(&t);
	//printf("%d", tm->tm_mon);
	//return (0);
}

Sunhedsprofil getPersonalInfo(void) {
	Sunhedsprofil sp;
	
	// Get First Name.
	printf("Enter first name: ");
	scanf("%s",sp.Name);

	// Get Surname.
	printf("\nEnter surname: ");
	scanf("%s", sp.Surname);

	// Get birth date.
	printf("\nEnter date of birth (format: day-month-year): ");
	scanf("%2d%*c%2d%*c%4d", &sp.BirthDate[0], &sp.BirthDate[1], &sp.BirthDate[2]);

	// Maybe do a check on the date format here... 

	// Get height.
	printf("\nEnter height in meters: ");
	scanf("%f", &sp.Height);

	// Get weight.
	printf("\nEnter weight in kg: ");
	scanf("%f", &sp.Weight);

	return sp;
}

void calcAge(Sunhedsprofil *sp) {
	// Get tm struct
	time_t t = time(NULL);
	struct tm *tm = localtime(&t);
	// Calculate and assign age to sp.Age
	sp->Age = tm->tm_year+(1900-sp->BirthDate[2]);
}
