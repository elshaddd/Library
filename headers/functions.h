#pragma once

#include "libs_and_strucs.h"

void ReadingData(char *file_name, struct book **lib, int *lib_am);

void write_file(struct book **lib, const int *lib_am, char *filename);

void default_data(struct book **lib);

