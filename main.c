#include "header.h"
void printGlobals();
/*
int main()
{
    while (1)
    {
        int fileNumber;
        printf("Choose which set of data to choose from (1-5): ");
        if (scanf_s("%d", &fileNumber) == 1 && fileNumber <= 5 && fileNumber >= 1)
        {
            // No error
        }
        else
        {
            printf("Must input number from 1-5\n\r");
            continue;
        }

        FILE* inputFile;
        switch (fileNumber)
        {
        case 1:

            if (fopen_s(&inputFile, "source1.txt", "r") != 0)
            {
                printf("File error\n\r");
            }
            break;
        case 2:
            if (fopen_s(&inputFile, "source2.txt", "r") != 0)
            {
                printf("File error\n\r");
            }
            break;
        case 3:
            if (fopen_s(&inputFile, "source3.txt", "r") != 0)
            {
                printf("File error\n\r");
            }
            break;
        case 4:
            if (fopen_s(&inputFile, "source4.txt", "r") != 0)
            {
                printf("File error\n\r");
            }
            break;
        case 5:
            if (fopen_s(&inputFile, "source5.txt", "r") != 0)
            {
                printf("File error\n\r");
            }
            break;
        default:
            printf("Must input number from 1-5\n\r");
            continue;
            break;
        }

        int value;
        for (int index = 0; index < DATA_LEN; index++)
        {
            fscanf_s(inputFile, "%d", &value);
            Globals.dataSet[index] = value;
        }
        fclose(inputFile);
        Globals.inversionCount = 0;
        int methodNumber;
        while (1)
        {
            printf("Choose the method to sort with (1 for quicksort, 2 for mergesort, 3 for heapsort): ");
            if (scanf_s("%d", &methodNumber) == 1 && methodNumber <= 3 && methodNumber >= 1)
            {
                break; // No error 
            }
            else
            {
                printf("Must input number from 1-3\n\r");
                continue;
            }
        }

        switch (methodNumber)
        {
        case 1:
            fallQuickSort(0, DATA_LEN - 1);
            break;
        case 2:
            //oldMergeSort(0, DATA_LEN - 1);
            break;
        case 3:
            //Globals.inversionCount = heapSort(Globals.dataSet, DATA_LEN);
            break;
        default:
            printf("Must input number from 1-3\n\r");
            continue;
        }

        printGlobals();

        FILE* outputFile;
        switch (fileNumber)
        {
        case 1:

            if (fopen_s(&outputFile, "source1(sorted).txt", "w") != 0)
            {
                printf("File error\n\r");
            }
            break;
        case 2:
            if (fopen_s(&outputFile, "source2(sorted).txt", "w") != 0)
            {
                printf("File error\n\r");
            }
            break;
        case 3:
            if (fopen_s(&outputFile, "source3(sorted).txt", "w") != 0)
            {
                printf("File error\n\r");
            }
            break;
        case 4:
            if (fopen_s(&outputFile, "source4(sorted).txt", "w") != 0)
            {
                printf("File error\n\r");
            }
            break;
        case 5:
            if (fopen_s(&outputFile, "source5(sorted).txt", "w") != 0)
            {
                printf("File error\n\r");
            }
            break;
        default:
            if (fopen_s(&outputFile, "source1(sorted).txt", "w") != 0)
            {
                printf("File error\n\r");
            }
            break;
        }

        for (int index = 0; index < DATA_LEN; index++)
        {
            fprintf(outputFile, "%d\n", Globals.dataSet[index]);
        }
        return 0;

    }

}
*/

int main()
{
    int dataSet[DATA_LEN] = {2, 1, 1};
    //int dataSet[DATA_LEN] = { 2, 3, 4, 5,6, 7, 8, 9, 10, 11, 12, 13, 14, 15, -1, 0, 1};
    int index;
    for (index = 0; index < DATA_LEN; index++)
    {
        Globals.dataSet[index] = dataSet[index];
    }
    Globals.inversionCount = 0;
    mergeSort(0, DATA_LEN - 1);
    for (index = 0; index < DATA_LEN; index++)
    {
        printf("%d ", Globals.dataSet[index]);
    }
    printf("\n\r%d\n\r", Globals.inversionCount);

}


void printGlobals()
{
    for (int index = 0; index < 20 && index < DATA_LEN; index++)
    {
        printf("%d ", Globals.dataSet[index]);
    }
    printf("\n\r...\n\r");
    if (DATA_LEN > 20)
    {
        for (int index = DATA_LEN - 20; index < DATA_LEN; index++)
        {
            printf("%d ", Globals.dataSet[index]);

        }
    }
    printf("\n\r");
    printf("Creating new sorted file.\n\r");
    printf("Inversion Count: %d\n\r", Globals.inversionCount);
}