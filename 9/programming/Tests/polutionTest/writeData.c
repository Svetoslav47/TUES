#include <stdio.h>
#include <stdlib.h>
#include "data.h"

#define numberOfSamples 20

void writeToFile(Sample *measurements, int size, char *fileName)
{
    FILE *file = fopen(fileName, "wb");
    if (file == NULL)
    {
        printf("Error opening file!\n");
        exit(1);
    }
    fwrite(&size, sizeof(int), 1, file);

    for (int i = 0; i < size; i++)
    {
        fwrite(&measurements[i], sizeof(Sample), 1, file);
    }
    fclose(file);
}

Sample generateSample(int index)
{
    Sample sample;
    sample.date.day = 10 + index;
    sample.date.month = 6;
    sample.date.year = 2023;
    sample.pollution = 50 + index * 10;
    return sample;
}

int main()
{
    Sample measurements[numberOfSamples];

    for (int i = 0; i < numberOfSamples; i++)
    {
        measurements[i] = generateSample(i);
    }

    writeToFile(measurements, numberOfSamples, "measurements.bin");
}
