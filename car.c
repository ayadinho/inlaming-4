#include "car.h"

void car_init(struct car* c, char* brand, char* model, char* color, unsigned int year_of_launch, enum car_transmission transmission)
{
	c->brand = brand;
	c->model = model;
	c->color = color;
	c->year_of_launch = year_of_launch;
	c->transmission = transmission;

	c->change_color = car_change_color;
	c->change_transmission = car_change_transmission;
	c->print = car_print;
}

void car_clear(struct car* c)
{
	c->brand = 0;
	c->model = 0;
	c->color = 0;
	c->year_of_launch = 0;
	c->transmission = AUTOMATIC;
}

/********************************************************************************
*car_new: H�r allokeras vi minnet f�r den nya bilen objekt i heapen. Sedan 
 initiserar vi bil objektet genom att anv�nda car_init funktionen. 
********************************************************************************/
struct car* car_new(char* brand, char* model, char* color, unsigned int year_of_launch, enum car_transmission transmission)
{
	struct car* c = malloc(sizeof(struct car));

	if (!c) return 0;

	car_init(c, brand, model, color, year_of_launch, transmission);

	return c;
}

/********************************************************************************
* car_delete: H�r koller vi ifall bil objektet �r NULL, sedan t�mmer vi minnet 
 som �r i bil objektet. Sedan s�tter vi bil objektet till NULL.
********************************************************************************/
void car_delete(struct car** c)
{
	
	if (*c == NULL)
	{
		return;
	}

	free(*c);

	*c = NULL;
	return;
}

void car_print(struct car* c, FILE* ostream)
{
	if (!ostream) ostream = stdout;

	fprintf(ostream, "--------------------------------------------------------------------------------\n");
	fprintf(ostream, "Brand: %s\n", c->brand);
	fprintf(ostream, "Model: %s\n", c->model);
	fprintf(ostream, "Color: %s\n", c->color);
	fprintf(ostream, "Year of Launch: %u\n", c->year_of_launch);
	if (c->transmission == 1) {

		fprintf(ostream, "Transmission: MANUAL\n");
	}

	else if (c->transmission == 0) {

		fprintf(ostream, "Transmission: AUTOMATIC\n");
	}
	fprintf(ostream, "--------------------------------------------------------------------------------\n\n");
}

/********************************************************************************
* car_change_color: H�r l�gger vi bilens objekt f�rg till en ny f�rg
********************************************************************************/
static void car_change_color(struct car* c, char* new_color)
{
	
	c->color = new_color;
}

/********************************************************************************
* car_change_transmission:H�r kollar vi om bilens objekt transmission och �ndrar
 den till motsatatta v�rde. 
********************************************************************************/
static void car_change_transmission(struct car* c)
{
	
	if (c->transmission == AUTOMATIC) {
		c->transmission = MANUAL;
	}
	else {
		c->transmission = AUTOMATIC;
	}
}

void file_read(const char* filepath)
{
	FILE* f = fopen(filepath, "r");
	if (!f) return;
	char s[100] = { '\0' };

	while (fgets(s, sizeof(s), f))
	{
		printf("%s", s);
	}

	fclose(f);
	return;
}
