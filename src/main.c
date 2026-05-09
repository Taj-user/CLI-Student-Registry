#include <stdio.h>
#include "../include/student.h"
#include "../include/registry.h"
#include "../include/fileio.h"
#include "../include/menu.h"


int main()
{
	// Create Registry struct variable
	Registry reg;
	
	// Initialize Registry
	registry_init(&reg);

	//Load Registry
	fileio_load(&reg);

	// Menu
	menu_run(&reg);	

	// Save Registry
	fileio_save(&reg);

	// Free Registry
	registry_free(&reg);

	return 0;
}
