#include "printing.h"

void tablica(struct book **lib, const int *lib_am) {
    //шапка
    wprintf(L"---------------------------------------------------------------------\n");
    wprintf(L"|% 2s", "№");
    wprintf(L"|% -20s", "Автор");
    wprintf(L"|%-20s", "Название книги");
    wprintf(L"|% 10s", "Цена,руб.");
    wprintf(L"|% 11s|\n", "Количество");
    wprintf(L"---------------------------------------------------------------------\n");
    //вывод самой таблицы
    for (int i = 0; i < *lib_am; i++) {
        wprintf(L"|% 2d", i + 1);
        wprintf(L"|% 20s", lib[i]->author);
        wprintf(L"|%20s", lib[i]->name);
        wprintf(L"|% 10d", lib[i]->cost);
        wprintf(L"|% 11d|\n", lib[i]->kolvo);
    }
    printf("---------------------------------------------------------------------\n");

}

void Menu() {
    //меню
    wprintf(L"%-17s\n", "Выберете действие:");
    wprintf(L"%-17s\n", "1-Открыть файл ");
    wprintf(L"%-17s\n", "2-Работа с данными ");
    wprintf(L"%-17s\n", "3-Записать файл ");
    wprintf(L"%-17s\n", "4-Записать в новый файл ");
    wprintf(L"%-17s\n", "5-Просмотр данных ");
    wprintf(L"%-17s\n", "6-Выход из программы ");
}

void podmenu() {
    wprintf(L"% 17s\n", "Выберете действие:");
    wprintf(L"% 10s", "1-Редактировать ");
    wprintf(L"% 10s", "2-Добавить ");
    wprintf(L"%10s", "3-Удалить ");
    wprintf(L"% 10s", "4-Сортировка ");
    wprintf(L"% 7s", "5-Поиск ");
    wprintf(L"% 7s", "6-Просмотр данных ");
    wprintf(L"% 7s\n", "7-Выход");

}


void red_podmenu() {
    wprintf(L"% 17s\n", "Выберете действие:");
    wprintf(L"% 10s", "1-Изменение автора ");
    wprintf(L"% 10s", "2-Изменение книги ");
    wprintf(L"%10s", "3-Изменение цены ");
    wprintf(L"% 10s", "4-Изменение количества ");
    wprintf(L"% 7s\n", "5-Выход");
}