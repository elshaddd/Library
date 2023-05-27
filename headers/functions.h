#pragma once

#include "libs_and_strucs.h"

void read_file(char *file_name, struct book **lib, int *lib_am);

void write_file(struct book **lib, const int *lib_am, char *filename);

void default_data(struct book **lib);

void search(struct book **lib, const int *lib_am);

void sorting(struct book **lib, const int *lib_am);

void add_new(struct book **lib, int *lib_am);

void data_handling(struct book **lib, int *lib_am);

void edit(struct book **lib);