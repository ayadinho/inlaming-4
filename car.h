#ifndef CAR_H_
#define CAR_H_

/*Inkluderingsdirektiv*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/********************************************************************************
* car_print: Detta �r en funktion som skriver ut inneh�llet f�r varje bil.
********************************************************************************/
void car_print(struct car* c, FILE* ostream);

/********************************************************************************
* car_change_color: Detta �r funktion som byter f�rgen p� bilen.
********************************************************************************/
void car_change_color(struct car* c, char* new_color);

/********************************************************************************
* car_init: Detta �r en funktion som intierar varje bil.
********************************************************************************/
void car_init(struct car* c, char* brand, char* model, char* color, unsigned int year_of_launch, enum car_transmission transmission);

/********************************************************************************
* car_clear: Detta �r en funktion som nollst�ller �nskad bil
********************************************************************************/
void car_clear(struct car* c);

/********************************************************************************
* car_new: Detta �r en funktion som l�gger till en ny bil p� heapen.
		  Retunerar en pekare till den nya bilen.
********************************************************************************/
struct car* car_new(char* brand, char* model, char* color, unsigned int year_of_launch, enum car_transmission transmission);

/********************************************************************************
* car_delete: Detta �r en funktion som tar bort �nskad bil.
********************************************************************************/
void car_delete(struct car** c);

/********************************************************************************
* car_change_transmission: Detta �r en funktion som byter v�xel�dan p� bilen.
********************************************************************************/
void car_change_transmission(struct car* c);

/********************************************************************************
* file_read: Detta �r en funktion som l�ser av en textfil som skriver ut det i terminalen
********************************************************************************/
void file_read(const char* filepath);

/********************************************************************************
* enum car_transmission: Enumration av v�xell�dan
********************************************************************************/
enum car_transmission {
	AUTOMATIC,
	MANUAL
};

/********************************************************************************
* struct car: Strukt som inneh�ller bilens olika attribut.
********************************************************************************/
struct car
{
	const char* brand;
	const char* model;
	const char* color;
	unsigned int year_of_launch;
	enum car_transmission transmission;

	void (*change_color)(struct car*, char* new_colour);
	void (*change_transmission)(struct car*);
	void (*print)(struct car*, FILE* ostream);
};



#endif // !CAR_H_

