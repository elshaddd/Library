#include "functions.h"
#include "cmp.h"
#include "printing.h"

void read_file(char *file_name, struct book **lib, int *lib_am) {
    FILE *file = fopen(file_name, "r+");
    if (!file) {
        printf("Не удалось открыть файл: Нет такого файла или каталога\n");
        return;
    }
    char **lines = nullptr; // - массив строк
    int num_lines = 0; // - "i" счетчик
    char line[1024];

    while (fgets(line, 1024, file)) {
        printf("%s\n", line);
        auto *temp = (struct book *) malloc(sizeof(struct book));
        char *copy = (char *) malloc(strlen(line) + 1);
        strcpy(copy, line);
        lines = (char **) realloc(lines, (num_lines + 1) * sizeof(char *));
        lines[num_lines++] = copy; // запихать в массив строк строку copy
        char *istr = strtok(lines[num_lines - 1], ";");
        int count = 0;
        while ((istr != nullptr) && (count < 4)) {
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
                temp->amount = atoi(istr);
            }
            count++;
            istr = strtok(nullptr, ";");
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
        fwprintf(file, L"%s; %s; %d; %d\n", lib[i]->author, lib[i]->name, lib[i]->cost, lib[i]->amount);
    }
    fclose(file);
}


void default_data(struct book **lib) {
    struct book def[] = {{"Пушкин",    "Пиковая дама", 200,  30},
                         {"Лермонтов", "Маскарад",     150,  20},
                         {"Толстой",   "Война и мир",  1000, 12}};
    for (int i = 0; i < 3; i++) {
        auto *temp = (struct book *) malloc(sizeof(struct book));
        temp->author = def[i].author;
        temp->name = def[i].name;
        temp->cost = def[i].cost;
        temp->amount = def[i].amount;
        lib[i] = temp;
    }
}


void search(struct book **lib, const int *lib_am) {
    char *name_to_search = (char *) malloc(100 * sizeof(char));
    wprintf(L"Введите название книги: ");
    fgets(name_to_search, 40, stdin);
    name_to_search[strlen(name_to_search) - 1] = '\0';

    int f = 0;
    for (int i = 0; i < (*lib_am); i++) {
        if (strcmp((name_to_search), (lib[i]->name)) == 0) {
            wprintf(L"---------------------------------------------------------------------\n");
            wprintf(L"|% 2s", "№");
            wprintf(L"|% -20s", "Автор");
            wprintf(L"|%-20s", "Название книги");
            wprintf(L"|% 10s", "Цена,руб.");
            wprintf(L"|% 11s|\n", "Количество");
            wprintf(L"---------------------------------------------------------------------\n");
            //вывод самой таблицы
            wprintf(L"|% 2d", i + 1);
            wprintf(L"|% 20s", lib[i]->author);
            wprintf(L"|%20s", lib[i]->name);
            wprintf(L"|% 10d", lib[i]->cost);
            wprintf(L"|% 11d|\n", lib[i]->amount);
            wprintf(L"---------------------------------------------------------------------\n");
            f++;
            break;
        }
    }
    if (!f) {
        wprintf(L"В магазине отсутствуют книги с таким названием\n");
    }
}


void sorting(struct book **lib, const int *lib_am) {
    int x;
    cin >> x;
    int ex2 = 1;
    while (ex2) {
        switch (x) {
            case 1: {
                wprintf(L"Введите критерий для сортировки 1 - количество, 2 - цена, 3 - название, 4 - автор, 0 - выход:\n");
                int y;
                cin >> y;
                switch (y) {
                    case 1: {
                        getchar();
                        qsort(lib, *lib_am, sizeof(struct book *), amount_ascending);
                        tablica(lib, lib_am);
                        break;
                    }
                    case 2: {
                        getchar();
                        qsort(lib, *lib_am, sizeof(struct book *), cost_ascending);
                        tablica(lib, lib_am);
                        break;
                    }
                    case 3: {
                        qsort(lib, *lib_am, sizeof(struct book *), author_ascending);
                        tablica(lib, lib_am);
                        break;
                    }
                    case 4: {
                        getchar();
                        qsort(lib, *lib_am, sizeof(struct book *), name_ascending);
                        tablica(lib, lib_am);
                        break;
                    }
                    case 0: {
                        getchar();
                        ex2 = 0;
                        data_handling_menu();
                        break;
                    }
                }
                break;
            }

            case 2: {
                getchar();
                wprintf(L"Введите критерий для сортировки 1 - количество, 2 - цена, 3 - название, 4 - автор, 0 - выход:\n");
                int z;
                cin >> z;
                switch (z) {
                    case 1: {
                        getchar();
                        qsort(lib, *lib_am, sizeof(struct book *), amount_descending);
                        tablica(lib, lib_am);;
                        break;
                    }
                    case 2: {
                        getchar();
                        qsort(*lib, *lib_am, sizeof(struct book *), cost_descending);
                        tablica(lib, lib_am);
                        break;
                    }
                    case 3: {
                        getchar();
                        qsort(lib, *lib_am, sizeof(struct book *), author_descending);
                        tablica(lib, lib_am);
                        break;
                    }
                    case 4: {
                        getchar();
                        qsort(lib, *lib_am, sizeof(struct book *), name_descending);
                        tablica(lib, lib_am);
                        break;
                    }
                    case 0: {
                        getchar();
                        ex2 = 0;
                        data_handling_menu();
                        break;
                    }
                }
                break;
            }
        }
    }
}


void add_new(struct book **lib, int *lib_am) {
    char *str1 = (char *) malloc(40);
    char *str2 = (char *) malloc(80);
    int for_digit;
    lib = (struct book **) realloc(lib, (*lib_am + 1) * sizeof(struct book *));
    auto *temp = (struct book *) malloc(sizeof(struct book));

    wprintf(L"Автор: ");
    fgets(str1, 40, stdin);
    str1[strlen(str1) - 1] = '\0';
    temp->author = (str1);

    wprintf(L"Название книги: ");
    fgets(str2, 80, stdin);
    str2[strlen(str2) - 1] = '\0';
    temp->name = (str2);

    wprintf(L"Цена: ");
    cin >> for_digit;
    temp->cost = for_digit;

    wprintf(L"Количество: ");
    cin >> for_digit;
    temp->amount = for_digit;

    lib[*lib_am] = temp;
    (*lib_am)++;
}


void data_handling(struct book **lib, int *lib_am) {
    int opt_dh_menu;
    int ex = 1;
    while (ex) {
        wprintf(L">> ");
        cin >> opt_dh_menu;
        switch (opt_dh_menu) {
            case 1: {
                getchar();
                edit(lib);
                break;
            }
            case 2: {
                getchar();
                add_new(lib, lib_am);
                data_handling_menu();
                break;
            }
            case 3: {
                getchar();
                wprintf(L"Для удаления книги введите её номер: ");
                int num;
                cin >> num;
                memmove(lib[num - 1], lib[num], (*lib_am - num) * sizeof(struct book));
                (*lib_am)--;
                data_handling_menu();
                break;
            }
            case 4: {
                getchar();
                wprintf(L"1-Возрастание\n");
                wprintf(L"2-Убывание\n");
                sorting(lib, lib_am);
                break;
            }
            case 5: {
                getchar();
                search(lib, lib_am);
                data_handling_menu();
                break;
            }
            case 6: {
                getchar();
                tablica(lib, lib_am);
                data_handling_menu();
                break;
            }
            case 7: {
                getchar();
                Menu();
                ex = 0;
                break;
            }
            default: {
                getchar();
                wprintf(L"Ошибка. Некорректная команда. Попробуйте ещё раз:\n");
            }
        }
    }
}


void edit(struct book **lib) {
    int opt_edit_menu;
    wprintf(L"Для редактирования введите номер книги: ");
    int num;
    cin >> num;
    wprintf(L"Что именно вы хотите изменить?\n");
    edit_menu();
    int red_ex = 1;
    while (red_ex) {
        wprintf(L">> ");
        cin >> opt_edit_menu;
        int for_digit;
        switch (opt_edit_menu) {
            case 1: {
                getchar();
                char *str1 = (char *) malloc(40);
                wprintf(L"Введите новое имя автора: ");
                fgets(str1, 40, stdin);
                str1[strlen(str1) - 1] = '\0';
                lib[num - 1]->author = (str1);
                edit_menu();
                break;
            }
            case 2: {
                getchar();
                char *str2 = (char *) malloc(80);
                wprintf(L"Введите новое название книги: ");
                fgets(str2, 40, stdin);
                str2[strlen(str2) - 1] = '\0';
                lib[num - 1]->name = (str2);
                edit_menu();
                break;
            }
            case 3: {
                getchar();
                wprintf(L"Введите новую цену книги: ");
                cin >> for_digit;
                lib[num - 1]->cost = for_digit;
                edit_menu();
                break;
            }
            case 4: {
                getchar();
                wprintf(L"Введите количество: ");
                cin >> for_digit;
                lib[num - 1]->amount = for_digit;
                edit_menu();
                break;
            }
            case 5: {
                getchar();
                data_handling_menu();
                red_ex = 0;
                break;
            }
            default: {
                getchar();
                wprintf(L"Ошибка. Некорректная команда. Попробуйте ещё раз:\n");
            }
        }
    }
}