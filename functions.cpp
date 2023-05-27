#include "functions.h"

void ReadingData(char *file_name, struct book **lib, int *lib_am) {

    FILE *file = fopen(file_name, "r+");
    if (!file) {
        printf("Не удалось открыть файл: Нет такого файла или каталога\n");
        return;
    }
    char **lines = nullptr; // - массив строк
    int num_lines = 0; // - "i" счетчик
    char line[1024];

    while (fgets(line, 1024, file)) {
        printf("%s\n",line);
        struct book *temp = (struct book *) malloc(sizeof(struct book));
        char *copy = (char *) malloc(strlen(line) + 1);
        strcpy(copy, line);
        lines = (char **) realloc(lines, (num_lines + 1) * sizeof(char *));
        lines[num_lines++] = copy; // запихать в массив строк строку copy
        char *istr = strtok(lines[num_lines - 1], ";");
        int count = 0;
        while ((istr != NULL) && (count < 4)) {
            if (count == 0) {
                temp->author = istr;
            }
            if (count == 1) {
                temp->name = istr;
            }
            if (count == 2) {
                temp->cost = atoi(istr);
            }
            if (count == 3) {
                temp->kolvo = atoi(istr);
            }
            count++;
            istr = strtok(NULL, ";");
        }
        lib = (struct book **) realloc(lib, ((*lib_am) + 1) * sizeof(struct book *));
        lib[*lib_am] = temp;
        (*lib_am)++;
    }
    fclose(file);
}

void write_file(struct book **lib, const int *lib_am, char *filename) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        wprintf(L"Не удалось открыть файл: Нет такого файла или каталога\n");
        return;
    }
    fseek(file, 0, SEEK_SET);
    for (int i = 0; i < (*lib_am); i++) {
        fwprintf(file, L"%s; %s; %d; %d\n", lib[i]->author, lib[i]->name, lib[i]->cost, lib[i]->kolvo);
    }
    fclose(file);
}

void default_data(struct book **lib) {
    struct book def[] = {{ "Пушкин",     "Пиковая дама", 200,  30},
                         { "Лермонтов",  "Маскарад",     150,  20},
                         { "Толстой",    "Война и мир",  1000, 12}};
    for(int i =0; i<3;i++){
        struct book *temp = (struct book *) malloc(sizeof(struct book));
        temp->author = def[i].author;
        temp->name = def[i].name;
        temp->cost = def[i].cost;
        temp->kolvo = def[i].kolvo;
        lib[i] = temp;
    }
}