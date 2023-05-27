#include "cmp.h"
#include "functions.h"
#include "printing.h"

int main() {
    setlocale(LC_CTYPE, "");
    Menu();
    int opt_menu;
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
                read_file(file_name, lib, &lib_am);
                break;
            }
            case 2: {
                getchar();
                tablica(lib, &lib_am);
                data_handling_menu();
                data_handling(lib, &lib_am);
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