#include <stdio.h>
#include "../include/student.h"
#include "../include/registry.h"


// TODO: Test all Registry functions. Do student.c

int main()
{
	// Create Registry struct variable 
	Registry reg;
	
	// Initialize Registry
	registry_init(&reg);	
	printf("Count: %d\n", reg.count);
	printf("Capacity: %d\n", reg.capacity);

	// Create Students
	Student s1 = student_create("Taj Robinson", "Computer Science", 3.9, 1, 19);
	Student s2 = student_create("Bread Breadington", "Actuarial Science", 4.3, 2, 18);

	// Add students to registry
	registry_add(&reg, s1);
	registry_add(&reg, s2);

	printf("%p\n", registry_search_by_id(&reg, 2));
	printf("%p\n", registry_search_by_name(&reg, "Taj Robinson"));

	//  

	// List Registry
	registry_list(&reg);

	// Free Registry
	registry_free(&reg);

	return 0;
}
