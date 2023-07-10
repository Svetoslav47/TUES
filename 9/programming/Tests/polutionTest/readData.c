#include <stdio.h>
#include <stdlib.h>
#include "data.h"

void readFromFile(Sample **measurements, char *fileName, int *sizeToReturn)
{
    FILE *file = fopen(fileName, "rb");
    if (file == NULL)
    {
        printf("Error opening file");
        exit(1);
    }
    int size = 0;
    fread(&size, sizeof(int), 1, file);
    *measurements = (Sample *)malloc(size * sizeof(Sample));
    fread(*measurements, sizeof(Sample), size, file);
    *sizeToReturn = size;
    fclose(file);
}

int main()
{
    int size = 0;
    Sample **measurements = (Sample **)malloc(sizeof(Sample *));
    readFromFile(measurements, "measurements.bin", &size);
    for (int i = 0; i < size; i++)
    {
        printf("Day: %d, Month: %d, Year: %d, Pollution: %d\n", (*measurements)[i].date.day, (*measurements)[i].date.month, (*measurements)[i].date.year, (*measurements)[i].pollution);
    }
}