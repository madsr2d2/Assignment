/*
Course: Hardware oriented programming (62557)
Assignment: 8
Student Name: Mads Richardt
Student ID: s224849
Date: 25-10-2022
*/

#include <stdio.h>
#include <time.h>
#define MAX_NAME_LENGTH 100

// Data type definitions
typedef struct {
	float BMI;
	int MaxPulse;
	float TargetPulseInterval[2];
} Sunhedsdata;

typedef struct {
	char Name[MAX_NAME_LENGTH];
	char Surname[MAX_NAME_LENGTH];
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
void calcBMI(Sunhedsprofil *sp);
void printSp(Sunhedsprofil *sp);

int main() 
{
	puts("*********************");
	puts("Homework Assignment 8");
	puts("*********************");
	puts("");

	Sunhedsprofil sp = getPersonalInfo();
	calcAge(&sp);
	calcHartData(&sp);
	calcBMI(&sp);
	printSp(&sp);
}

// Function definitions.
Sunhedsprofil getPersonalInfo(void) {
	Sunhedsprofil sp;
	
	// Get First Name.
	printf("Enter first name: ");
	scanf("%s",sp.Name);

	// Get Surname.
	printf("Enter surname: ");
	scanf("%s", sp.Surname);

	// Get birth date.
	printf("Enter date of birth (format: day-month-year): ");
	scanf("%2d%*c%2d%*c%4d", &sp.BirthDate[0], &sp.BirthDate[1], &sp.BirthDate[2]);

	// Maybe do a check on the date format here... 

	// Get height.
	printf("Enter height in meters: ");
	scanf("%f", &sp.Height);

	// Get weight.
	printf("Enter weight in kg: ");
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

void calcHartData(Sunhedsprofil *sp) {
	sp->sd.MaxPulse = 220 - sp->Age;
	sp->sd.TargetPulseInterval[0] = sp->sd.MaxPulse*0.5;
	sp->sd.TargetPulseInterval[1] = sp->sd.MaxPulse * 0.85;
}

void calcBMI(Sunhedsprofil *sp) {
	sp->sd.BMI = sp->Weight/(sp->Height*sp->Height);
}

void printSp(Sunhedsprofil *sp) {
	puts("");
	puts("*************");
	puts("Sunhedsprofil");
	puts("*************");
	printf("%s %s\n", sp->Name, sp->Surname);
	printf("%.2f m\n", sp->Height);
	printf("%.0f kg\n", sp->Weight);
	printf("BMI: %.1f kg/m^2\n", sp->sd.BMI);
	printf("Maks. puls: %d\n", sp->sd.MaxPulse);
	printf("Pulsinterval: %.1f-%.1f\n", sp->sd.TargetPulseInterval[0], sp->sd.TargetPulseInterval[1]);
	puts("*************");
}