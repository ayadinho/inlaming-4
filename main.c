#include "car.h"
/********************************************************************************
main: Detta program skapar en strukt f?r en bil. H?r initierar vi strukten och
arrayen d?refter initerar ineh?llet i varje bil. Sedan ?ppnar upp en textfil.
Efter det skriver vi ?ver inneh?llet i arrayen till textfilen.Slutligen l?ser av
textfilen och skriver ut det i terminalen
********************************************************************************/
int main(void)
{
	
	struct car car1, car2, car3;
	struct car* cars[] = { &car1, &car2, &car3 };

	
	car_init(&car1, "Volvo", "V70", "Black", 1995, MANUAL);
	car_init(&car2, "BMW", "Z3", "Blue", 2001, AUTOMATIC);
	car_init(&car3, "Skoda", "Octavia RS", "White", 2003, MANUAL);

	
	FILE* ostream = fopen("cars.txt", "a");

	
	for (int i = 0; i < sizeof(cars) / sizeof(cars[0]); i++)
	{
		car_print(cars[i], ostream);

	}

	
	car3.change_color(&car3, "Green");
	car3.change_transmission(&car3);
	car3.print(&car3, ostream);
	fclose(ostream);

	
	file_read("cars.txt");

	return 0;
}