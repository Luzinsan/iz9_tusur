#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

/**
В текстовом файле F1 записана таблица, содержащая информацию о работе наёмных работников
(номер работника, дата, количество отработанных часов).
В файле F2 записана информация о почасовой оплате работников
(номер работника, Ф.И.О.,оплата работы за час).
Сформировать файл F3 и записать в него ведомость оплаты работников за указанный месяц.
*/

typedef struct
{
    char* f_subname;
    char* f_name;
    char* f_patronymic;
}FIO;

typedef struct
{
    int d_year;
    int d_month;
    int d_day;
}DATA;

typedef struct
{
    int w_id;
    DATA w_data;
    int w_hours_worker;
    FIO w_full_name;
    int w_hourly_wage;
}DEPARTMENT;
