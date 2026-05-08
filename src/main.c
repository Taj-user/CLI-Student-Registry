#include <stdio.h>
#include "../include/student.h"
#include "../include/registry.h"
#include "../include/fileio.h"


// TODO: Test all Registry functions. Do student.c

int main()
{
	// Create Registry struct variable 
	Registry reg;
	
	// Initialize and Load Registry
	registry_init(&reg);	
	fileio_load(&reg);

	// Create Students
	

	// Add student to registry
	

	// List Registry
	registry_list(&reg);

	// Free and Save Registry
	// fileio_save(&reg);
	registry_free(&reg);	

	return 0;
}
