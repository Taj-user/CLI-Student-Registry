#include <stdio.h>
#include <stdlib.h>
#include "../include/fileio.h"

int fileio_save(const Registry* reg)
{
	FILE* f = fopen(DATA_FILE, "wb");
	if(f == NULL) return 0;

	fwrite(&reg->count, sizeof(int), 1, f);
	fwrite(reg->students, sizeof(Student), reg->count, f);

	fclose(f);
	return 1; 
}

int fileio_load(Registry* reg)
{
	FILE* f = fopen(DATA_FILE, "rb");
	if(f == NULL) return 0;

	int count = 0;
	fread(&count, sizeof(int), 1, f);

	if(count > 0)
	{
		if(count > reg->capacity)
		{
			Student* temp = realloc(reg->students, sizeof(Student) * count);
			if(temp == NULL)
			{
				fclose(f);
				return 0;
			}
			reg->students = temp;
			reg->capacity = count;
		}

		int read = fread(reg->students, sizeof(Student), count, f);
		if(read != count)
		{
			fclose(f);
			return 0;
		}
		reg->count = count;
	}

	fclose(f);
	return 1;
}
