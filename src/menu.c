#include <stdio.h>
#include <string.h>
#include "../include/menu.h"
#include "../include/student.h"

static void clear_input()
{
	int c;
	while((c = getchar() != '\n' && c != EOF));
}

static void print_menu()
{
	printf("\n===== Student Registry =====\n");
	printf("1. Add Student\n");
	printf("2. Delete Student\n");
	printf("3. Search student by ID\n");
	printf("4. Search student by name\n");
	printf("5. List all students\n");
	printf("0. Exit\n");
	printf("Enter your choice: \n");
}

static int collect_student(Student* out)
{
	char name[NAME_LEN];
	char major[MAJOR_LEN];
	int age;
	float gpa;
	int year;

	printf("Enter Name: ");
	fgets(name, NAME_LEN, stdin);
	name[strcspn(name, "\n")] = '\0';

	printf("Enter Major: ");
	fgets(major, MAJOR_LEN, stdin);
	major[strcspn(major, "\n")] = '\0';

	printf("Enter Age: ");
	scanf("%d", &age);
	clear_input();

	printf("Enter GPA: ");
	scanf("%f", &gpa);
	clear_input();

	printf("Enter Year: ");
	scanf("%d", &year);
	clear_input();

	*out = student_create(name, major, gpa, year, age);
	
	return student_validate(out);
}

void menu_run(Registry* reg)
{
	int choice;

	do
	{
		print_menu();
		scanf("%d", &choice);
		clear_input();

		switch(choice)
		{
			case 1:
			{
				Student s;
				if(collect_student(&s))
				{
					if(registry_add(reg, s))
					{
						printf("Successfully added student with ID: %d\n", reg->students[reg->count - 1].id);
					}
					else
					{
						printf("Error. Could not add student.\n");
					}
				}
				else
				{
					printf("Invalid input. Student not added.\n");
				}
				break;
			}
			
			case 2:
			{
				int id;
				printf("Enter the ID of the student you would like to delete: ");
				scanf("%d", &id);
				clear_input();
				if(registry_delete_by_id(reg, id))
				{
					printf("Successfully deleted the student with the ID: %d\n", id);
				}
				else
				{
					printf("Error. No student with ID: %d\n", id);
				}
				break;
			}

			case 3:
			{
				int id;
				printf("Enter the ID of the student you would like to search for: ");
				scanf("%d", &id);
				clear_input();
				Student* s = registry_search_by_id(reg, id);
				if(s) student_print(s);
				else printf("Error. No student with ID: %d\n", id);
				break;
			}

			case 4:
			{
				char name[NAME_LEN];
				printf("Enter the name of the student you would like to search for: ");
				fgets(name, NAME_LEN, stdin);
				name[strcspn(name, "\n")] = '\0';
				Student* s = registry_search_by_name(reg, name);
				if(s) student_print(s);
				else printf("Error. No student with name: \"%s\".\n", name);
				break;
			}

			case 5:
			{
				registry_list(reg);
				break;
			}

			case 0:
			{
				printf("Saving and exiting...\n");
				break;
			}

			default:
			{
				printf("Invalid choice\n");
				break;
			}
		}
	}
	while(choice != 0);
}
