#include "cmp.h"
#include "functions.h"
#include "printing.h"

int main() {
    setlocale(LC_CTYPE, "");
    Menu();
    int opt_menu;
    int opt_podmenu;
    int red_opt_podmenu;
    struct book **lib = (struct book **) malloc(10000 * sizeof(struct book *));
    int lib_am = 3;
    default_data(lib);
    char file_name[256];
    char res_file[256];
    while (1) {
        wprintf(L">> ");
        cin >> opt_menu;
        switch (opt_menu) {
            case 1: {
                getchar();
                wprintf(L"\nВведите название файла:\n");
                scanf("%s", file_name);
                lib_am = 0;
                ReadingData(file_name, lib, &lib_am);
                break;
            }
            case 2: {
                getchar();
                tablica(lib, &lib_am);
                podmenu();
                int ex = 1;
                while (ex) {
                    wprintf(L">> ");
                    cin >> opt_podmenu;
                    switch (opt_podmenu) {
                        case 1: {
                            getchar();
                            wprintf(L"Для редактирования введите номер книги: ");
                            int num;
                            cin >> num;
                            wprintf(L"Что именно вы хотите изменить?\n");
                            red_podmenu();
                            int red_ex = 1;
                            while (red_ex) {
                                wprintf(L">> ");
                                cin >> red_opt_podmenu;
                                int for_digit;
                                switch (red_opt_podmenu) {
                                    case 1: {
                                        getchar();
                                        char* str1 =(char*) malloc(40);
                                        wprintf(L"Введите новое имя автора: ");
                                        fgets(str1,40,stdin);
                                        str1[strlen(str1)-1] = '\0';
                                        lib[num - 1]->author = (str1);
                                        red_podmenu();
                                        break;
                                    }
                                    case 2: {
                                        getchar();
                                        char* str2 =(char*) malloc(80);
                                        wprintf(L"Введите новое название книги: ");
                                        fgets(str2,40,stdin);
                                        str2[strlen(str2)-1] = '\0';
                                        lib[num - 1]->name = (str2);
                                        red_podmenu();
                                        break;
                                    }
                                    case 3: {
                                        getchar();
                                        wprintf(L"Введите новую цену книги: ");
                                        cin >> for_digit;
                                        lib[num - 1]->cost = for_digit;
                                        red_podmenu();
                                        break;
                                    }
                                    case 4: {
                                        getchar();
                                        wprintf(L"Введите количество: ");
                                        cin >> for_digit;
                                        lib[num - 1]->kolvo = for_digit;
                                        red_podmenu();
                                        break;
                                    }
                                    case 5: {
                                        getchar();
                                        podmenu();
                                        red_ex = 0;
                                        break;
                                    }
                                    default: {
                                        getchar();
                                        wprintf(L"Ошибка. Некорректная команда. Попробуйте ещё раз:\n");
                                    }
                                }
                            }
                            break;
                        }
                        case 2: {
                            getchar();
                            char* str1 =(char*) malloc(40);
                            char* str2 =(char*) malloc(80);
                            int for_digit;
                            lib = (struct book **) realloc(lib, (lib_am + 1) * sizeof(struct book *));
                            struct book *temp = (struct book *) malloc(sizeof(struct book));

                            wprintf(L"Автор: ");
                            fgets(str1,40,stdin);
                            str1[strlen(str1)-1] = '\0';
                            temp->author = (str1);

                            wprintf(L"Название книги: ");
                            fgets(str2,80,stdin);
                            str2[strlen(str2)-1] = '\0';
                            temp->name = (str2);

                            wprintf(L"Цена: ");
                            cin >> for_digit;
                            temp->cost = for_digit;

                            wprintf(L"Количество: ");
                            cin >> for_digit;
                            temp->kolvo = for_digit;

                            lib[lib_am] = temp;
                            lib_am++;

                            podmenu();
                            break;
                        }
                        case 3: {
                            getchar();
                            wprintf(L"Для удаления книги введите её номер: ");
                            int num;
                            cin >> num;
                            memmove(lib[num - 1], lib[num], (lib_am - num) * sizeof(struct book));
                            lib_am--;
                            podmenu();
                            break;
                        }
                        case 4: {
                            getchar();
                            wprintf(L"1-Возрастание\n");
                            wprintf(L"2-Убывание\n");
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
                                                qsort(lib, lib_am, sizeof(struct book *), kolvo_vozr);
                                                tablica(lib, &lib_am);
                                                break;
                                            }
                                            case 2: {
                                                getchar();
                                                qsort(lib, lib_am, sizeof(struct book *), cost_vozr);
                                                tablica(lib, &lib_am);
                                                break;
                                            }
                                            case 3: {
                                                qsort(lib, lib_am, sizeof(struct book *), av_vozr);
                                                tablica(lib, &lib_am);
                                                break;
                                            }
                                            case 4: {
                                                getchar();
                                                qsort(lib, lib_am, sizeof(struct book *), name_vozr);
                                                tablica(lib, &lib_am);
                                                break;
                                            }
                                            case 0: {
                                                getchar();
                                                ex2 = 0;
                                                podmenu();
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
                                                qsort(lib, lib_am, sizeof(struct book *), kolvo_ymen);
                                                tablica(lib, &lib_am);;
                                                break;
                                            }
                                            case 2: {
                                                getchar();
                                                qsort(lib, lib_am, sizeof(struct book *), cost_ymen);
                                                tablica(lib, &lib_am);
                                                break;
                                            }
                                            case 3: {
                                                getchar();
                                                qsort(lib, lib_am, sizeof(struct book *), av_ymen);
                                                tablica(lib, &lib_am);
                                                break;
                                            }
                                            case 4: {
                                                getchar();
                                                qsort(lib, lib_am, sizeof(struct book *), name_ymen);
                                                tablica(lib, &lib_am);
                                                break;
                                            }
                                            case 0: {
                                                getchar();
                                                ex2 = 0;
                                                podmenu();
                                                break;
                                            }
                                        }
                                        break;
                                    }
                                }
                            }
                            break;
                        }
                        case 5: {
                            getchar();
                            char *name_to_search = (char *) malloc(100 * sizeof(char));
                            wprintf(L"Введите название книги: ");
                            fgets(name_to_search,40,stdin);
                            name_to_search[strlen(name_to_search)-1] = '\0';

                            int f = 0;
                            for (int i = 0; i < lib_am; i++) {
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
                                    wprintf(L"|% 11d|\n", lib[i]->kolvo);
                                    wprintf(L"---------------------------------------------------------------------\n");
                                    f++;
                                    break;
                                }
                            }
                            if (!f) {
                                wprintf(L"В магазине отсутствуют книги с таким названием\n");
                            }
                            podmenu();
                            break;
                        }
                        case 6: {
                            getchar();
                            tablica(lib, &lib_am);
                            podmenu();
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
                break;
            }
            case 3: {
                getchar();
                write_file(lib, &lib_am, file_name);
                break;
            }
            case 4: {
                getchar();
                scanf("%s", res_file);
                write_file(lib, &lib_am, res_file);
                break;
            }
            case 5: {
                getchar();
                tablica(lib, &lib_am);
                wprintf(L"Выберете действие:\n");
                break;
            }
            case 6: {
                getchar();
                wprintf(L"Выход из программы...\n");
                exit(0);
            }
            default: {
                getchar();
                wprintf(L"Ошибка. Некорректная команда. Попробуйте ещё раз:\n");
                break;
            }
        }
    }
}