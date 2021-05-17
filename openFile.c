#include "structs.h"
void putNameToF2(FILE*, DEPARTMENT*);
int FindWorker(DEPARTMENT*, size_t, int);

DEPARTMENT* OpenF1(DEPARTMENT *Worker, size_t *number)
{
    FILE *F1;
    char name[] = "F1.txt";

    if((F1 = fopen(name, "r")) == NULL)
    {
        printf("\n\tФайла F1 не существует");
        return NULL;
    }


    int id, hours_worker, data_year, data_month, data_day;

    fscanf(F1,       "\t| id|   Дата   |hrs|\n"
                     "\t|___|__________|___|\n");

    for(; fscanf(F1, "\t|%3d|%d.%d.%d|%3d|\n", &id, &data_day, &data_month, &data_year, &hours_worker) == 5;
        (*number)++)
    {
        Worker = (DEPARTMENT*)realloc(Worker, *number*sizeof(DEPARTMENT));
        Worker[*number-1].w_id = id;
        Worker[*number-1].w_data.d_day   = data_day;
        Worker[*number-1].w_data.d_month = data_month;
        Worker[*number-1].w_data.d_year  = data_year;
        Worker[*number-1].w_hours_worker = hours_worker;
        printf("\n\tWorker[%d]: id - %d\n\tdata: %02d.%02d.%4d\n\tnumber of hours worked - %d",
                *number, Worker[*number-1].w_id, Worker[*number-1].w_data.d_day,
                                                 Worker[*number-1].w_data.d_month,
                                                 Worker[*number-1].w_data.d_year,
                         Worker[*number-1].w_hours_worker);

    }
    (*number)--;
    fclose(F1);
    return Worker;
}

int OpenF2(DEPARTMENT *Worker, size_t number)
{
    FILE *F2;
    char name_file[] = "F2.txt";


    if((F2 = fopen(name_file, "r")) == NULL)
        return 0;

    fscanf(F2,                               "\t| id|     Фамилия Имя Отчество      |hrs|\n"
                                             "\t|___|_______________________________|___|\n");
    int id = 0;
    for(int j = 0; fscanf(F2, "\t|%3d|", &id) == 1; )
    {

        if(j = FindWorker(Worker, number, id))
        {
            j--;
            putNameToF2(F2, &Worker[j]);
            fscanf(F2, "%3d|", &Worker[j].w_hourly_wage);
            printf("\n\t|%3d|%s %s %s|%3d", Worker[j].w_id, Worker[j].w_full_name.f_subname, Worker[j].w_full_name.f_name, Worker[j].w_full_name.f_patronymic, Worker[j].w_hours_worker);
        }
        else
        {
            printf("\n\tid %d в таблице файла F1.txt не найден.", id);
            char c;
            while(c = fgetc(F2)) if(c=='\n') break;

        }
    }

    fclose(F2);
    return 1;
}
