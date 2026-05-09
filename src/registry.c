#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "../include/registry.h"

#define INITIAL_CAPACITY 8

static int registry_next_id(Registry* reg)
{
	int max = 0;
	for(int i = 0; i < reg->count; i++)
	{
		if(reg->students[i].id > max) max = reg->students[i].id;
	}
	return max + 1;
}

void registry_init(Registry* reg)
{
	reg->students = malloc(sizeof(Student) * INITIAL_CAPACITY);
	reg->count = 0;
	reg->capacity = INITIAL_CAPACITY;
}

int registry_add(Registry* reg, Student s)
{
	if(reg->count == reg->capacity)
	{
		int new_capacity = reg->capacity * 2;
		Student* temp = realloc(reg->students, sizeof(Student) * new_capacity);
		if(temp == NULL) return 0;
		reg->students = temp;
		reg->capacity = new_capacity;
	}

	s.id = registry_next_id(reg);
	reg->students[reg->count] = s;
	reg->count++;

	return 1;
}

int registry_delete_by_id(Registry* reg, int id)
{
	int index = -1;
	for(int i = 0; i < reg->count; i++)
	{
		if(reg->students[i].id == id)
		{
			index = i;
			break;
		}
	}

	if(index == -1) return 0;

	for(int i = index; i < reg->count - 1; i++)
	{
		reg->students[i] = reg->students[i + 1];
	}

	reg->count--;

	return 0;
}

Student* registry_search_by_id(Registry* reg, int id)
{
	for(int i = 0; i < reg->count; i++)
	{
		if(reg->students[i].id == id) return &reg->students[i];
	}

	return NULL;
}

Student* registry_search_by_name(Registry* reg, const char* name)
{
	for(int i = 0; i < reg->count; i++)
	{
		if(_stricmp(reg->students[i].name, name)) return &reg->students[i];
	}

	return NULL;
}

void registry_list(Registry* reg)
{
	if(reg->count == 0)
	{
		printf("No students registered\n");
		return;
	}

	printf("%-5s %-30s %-40s %-10s %s\n", "ID", "Name", "Major", "GPA", "Year");
	printf("-------------------------------------------------------------------------------------------------------------\n");

	for(int i = 0; i < reg->count; i++)
	{
		Student* s = &reg->students[i];
		printf("%-5d %-30s %-40s %-10.2f %d\n", s->id, s->name, s->major, s->gpa, s->yearLvl);
	}
}

void registry_free(Registry* reg)
{
	free(reg->students);
	reg->students = NULL;
	reg->count = 0;
	reg->capacity = 0;
}
