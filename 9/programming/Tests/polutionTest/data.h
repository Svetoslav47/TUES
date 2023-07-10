#ifndef DATA_H
#define DATA_H

typedef struct
{
    int year;
    int month;
    int day;
} Date;

typedef struct
{
    Date date;
    int pollution;
} Sample;

#endif