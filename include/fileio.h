#ifndef FILEIO_H

#define FILEIO_H

#include "registry.h"

#define DATA_FILE "data/student.dat"

int fileio_save(const Registry* reg);
int fileio_load(Registry* reg);

#endif
