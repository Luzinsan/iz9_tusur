#include "structs.h"

int FindWorker(DEPARTMENT*, size_t, int);
void putNameToF2(FILE*, DEPARTMENT*);
char getAnswer(char, char);
int FillF3(DEPARTMENT*, size_t, int);
DEPARTMENT* OpenF1(DEPARTMENT*, size_t*);
int OpenF2(DEPARTMENT*, size_t);

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    DEPARTMENT *Worker = NULL;
    int month;
    while(1){
    printf("\n\tВведите месяц (в виде числа), за который будет выведена ведомость оплаты работников: ");
    while(!scanf("%d", &month))
    {
        printf("\n\tОшибка! Попробуйте ещё раз.\n\t\t\t");
        fflush(stdin);
    }
    if(month > 12 || month < 1) { printf("\n\tТакого месяца не существует! Попробуйте ещё раз."); continue;}
    else break;
    }

    size_t number = 1;
    if(Worker = OpenF1(Worker, &number))         printf("\n\tФайл F1 успешно обработан.");
    else{  printf("\n\tФайла F1 не существует"); exit(1);}
    if(OpenF2(Worker, number))                   FillF3(Worker, number, month);
    else{  printf("\n\tФайла F2 не существует"); exit(2);}
    return 0;
}

int FindWorker(DEPARTMENT *Worker, size_t number, int id)
{
    for(int i = 0; i < number; i++)
    {
        //printf("\n\t%s | %s",Dialer->d_pages[letter].p_recording[i].r_subname, subname);
        if(Worker[i].w_id == id)
            return i+1;
    }
    return 0;
}

void putNameToF2(FILE *F2, DEPARTMENT *Worker)
{
    char c;
    char* string = NULL;
    int numberString = 0, indexWord = 0;
    while(c = fgetc(F2)) if(c!=' ') break;
    do
    {
        indexWord++;
        if(c == ' ')
        {
            string[indexWord-1] = '\0';
            indexWord = 0;
            numberString++;
            switch(numberString-1)
            {
            case 0:
                Worker->w_full_name.f_subname = (char*)realloc(Worker->w_full_name.f_subname, strlen(string)*sizeof(char));
                strcpy(Worker->w_full_name.f_subname, string);
                continue;
            case 1:
                Worker->w_full_name.f_name = (char*)realloc(Worker->w_full_name.f_name, strlen(string)*sizeof(char));
                strcpy(Worker->w_full_name.f_name, string);
                continue;
            case 2:
                Worker->w_full_name.f_patronymic = (char*)realloc(Worker->w_full_name.f_patronymic, strlen(string)*sizeof(char));
                strcpy(Worker->w_full_name.f_patronymic , string);

                while(c = fgetc(F2)) if(c!=' ') break;
            }
            break;
        }
        else
        {
            string = (char*)realloc(string, indexWord*sizeof(char));
            string[indexWord-1] = c;
        }

    }while(fscanf(F2, "%c", &c) == 1);

    free(string);
    //return Worker;
}

char getAnswer(char a, char b)
{
    char choice;
    do{
        printf("\n\t  - ");
        choice = _getch();
        printf("%c", choice);
        if(choice < a || choice > b)
            printf("\n\tНеверно введено значение. Попробуйте ещё раз.");
    }while(choice < a || choice > b);
    return choice;
}

int FillF3(DEPARTMENT *Worker, size_t number, int month)
{
    FILE *F3 = fopen("F3.txt", "a+");
    fprintf(F3, "\n\t___________________________________________________________________________________________________"
                "\n\t|  id  |                       ФИО                       |   DATA   | Зарплата за указанный месяц |"
                "\n\t|______|_________________________________________________|__________|_____________________________|");
    for(int i = 0; i < number; i++)
        if(Worker[i].w_data.d_month == month)
            fprintf(F3, "\n\t|%6d| %-15s %-15s %-15s |%02d.%02d.%02d|%29d|"
                "\n\t|______|_________________________________________________|__________|_____________________________|\n",
                        Worker[i].w_id, Worker[i].w_full_name.f_subname,
                                         Worker[i].w_full_name.f_name,
                                         Worker[i].w_full_name.f_patronymic,
                                         Worker[i].w_data.d_day,
                                         Worker[i].w_data.d_month,
                                         Worker[i].w_data.d_year,
                        Worker[i].w_hours_worker * Worker[i].w_hourly_wage);

    fclose(F3);
}
