#include "header.h"


// This function recursively sorts a virtual array, a subset of the global array based on the bounds.
// It uses the quick sort method.
void quickSort(int lowerBound, int upperBound)
{
    if (lowerBound < upperBound)
    {
        Bound equalsBound = partition(lowerBound, upperBound);

        quickSort(lowerBound, equalsBound.lowerBound - 1);
        quickSort(equalsBound.upperBound + 1, upperBound);
    }
}

// This function does operations on a virtual array, a subset of the global array based on the bounds.
// It moves the values lower than the pivot to the left part of the virtual array, moves the values
// greater than the pivot to the right part of the virtual array, and returns the index of the first value greater than the pivot
Bound partition(int lowerBound, int upperBound)
{
    int pivot = Globals.dataSet[lowerBound];

    Bound equalsBound;

    int lesserSize = 0;
    int equalSize = 0;
    int greaterSize = 0;
    int belongingMatrix[3][3] =
    { // inner is where it belongs, outer is where it is located
        { 0, 0, 0},
        { 0, 0, 0},
        { 0, 0, 0}
    };


    // Count each type
    int globalIndex;
    for (globalIndex = lowerBound; globalIndex <= upperBound; globalIndex++)
    {
        if (Globals.dataSet[globalIndex] < pivot)
        {
            lesserSize++;
        }
        else if (Globals.dataSet[globalIndex] == pivot)
        {
            equalSize++;
        }
        else if (Globals.dataSet[globalIndex] > pivot)
        {
            greaterSize++;
        }
    }
    int equalStart = lowerBound + lesserSize;
    int greaterStart = equalStart + equalSize;
    equalsBound.lowerBound = equalStart;
    equalsBound.upperBound = greaterStart - 1;

    // See what belongs where
    for (globalIndex = lowerBound; globalIndex < equalStart; globalIndex++)
    {
        if (Globals.dataSet[globalIndex] < pivot)
        {
            belongingMatrix[0][0]++;
        }
        else if (Globals.dataSet[globalIndex] == pivot)
        {
            belongingMatrix[0][1]++;
        }
        else if (Globals.dataSet[globalIndex] > pivot)
        {
            belongingMatrix[0][2]++;
        }
    }

    for (; globalIndex < greaterStart; globalIndex++)
    {
        if (Globals.dataSet[globalIndex] < pivot)
        {
            belongingMatrix[1][0]++;
        }
        else if (Globals.dataSet[globalIndex] == pivot)
        {
            belongingMatrix[1][1]++;
        }
        else if (Globals.dataSet[globalIndex] > pivot)
        {
            belongingMatrix[1][2]++;
        }
    }

    for (; globalIndex <= upperBound; globalIndex++)
    {
        if (Globals.dataSet[globalIndex] < pivot)
        {
            belongingMatrix[2][0]++;
        }
        else if (Globals.dataSet[globalIndex] == pivot)
        {
            belongingMatrix[2][1]++;
        }
        else if (Globals.dataSet[globalIndex] > pivot)
        {
            belongingMatrix[2][2]++;
        }
    }

    int testNum = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            testNum += belongingMatrix[i][j];
        }
    }
    if (testNum != upperBound - lowerBound + 1)
    {
        printf("Something went wrong.\n\rtestNum: %d\n\rBound: %d\n\r", testNum, upperBound - lowerBound + 1);
    }

    int diffNum;
    do
    {

        if (belongingMatrix[0][1] > 0 && belongingMatrix[1][0] > 0)
        {
            int lesserIndex = lowerBound; // lesserRegion
            int equalIndex = equalStart; // equalRegion
            while (lesserIndex < equalStart && equalIndex < greaterStart)
            {
                if (Globals.dataSet[lesserIndex] == pivot)
                {
                    if (Globals.dataSet[equalIndex] < pivot)
                    {
                        int equalCopy = Globals.dataSet[equalIndex];
                        Globals.dataSet[equalIndex] = Globals.dataSet[lesserIndex];
                        Globals.dataSet[lesserIndex] = equalCopy;
                        Globals.inversionCount++;
                        lesserIndex++;
                        equalIndex++;
                        belongingMatrix[0][0]++;
                        belongingMatrix[1][1]++;
                        belongingMatrix[0][1]--;
                        belongingMatrix[1][0]--;
                    }
                    else
                    {
                        equalIndex++;
                    }
                }
                else
                {
                    lesserIndex++;
                }

            }
        }
        else if (belongingMatrix[0][2] > 0 && belongingMatrix[2][0] > 0)
        {
            int lesserIndex = lowerBound;
            int greaterIndex = greaterStart;
            while (lesserIndex < equalStart && greaterIndex <= upperBound)
            {
                if (Globals.dataSet[lesserIndex] > pivot)
                {
                    if (Globals.dataSet[greaterIndex] < pivot)
                    {
                        int greaterCopy = Globals.dataSet[greaterIndex];
                        Globals.dataSet[greaterIndex] = Globals.dataSet[lesserIndex];
                        Globals.dataSet[lesserIndex] = greaterCopy;
                        Globals.inversionCount++;
                        lesserIndex++;
                        greaterIndex++;
                        belongingMatrix[0][0]++;
                        belongingMatrix[2][2]++;
                        belongingMatrix[0][2]--;
                        belongingMatrix[2][0]--;
                    }
                    else
                    {
                        greaterIndex++;
                    }
                }
                else
                {
                    lesserIndex++;
                }
            }
        }
        else if (belongingMatrix[1][2] > 0 && belongingMatrix[2][1] > 0)
        {
            int equalIndex = equalStart;
            int greaterIndex = greaterStart;
            while (equalIndex < greaterStart && greaterIndex <= upperBound)
            {
                if (Globals.dataSet[equalIndex] > pivot)
                {
                    if (Globals.dataSet[greaterIndex] == pivot)
                    {
                        int equalCopy = Globals.dataSet[equalIndex];
                        Globals.dataSet[equalIndex] = Globals.dataSet[greaterIndex];
                        Globals.dataSet[greaterIndex] = equalCopy;
                        Globals.inversionCount++;
                        equalIndex++;
                        greaterIndex++;
                        belongingMatrix[1][2]--;
                        belongingMatrix[2][1]--;
                        belongingMatrix[1][1]++;
                        belongingMatrix[2][2]++;
                    }
                    else
                    {
                        greaterIndex++;
                    }
                }
                else
                {
                    equalIndex++;
                }
            }
        }
        else
        {
            int lesserIndex = lowerBound;
            int equalIndex = equalStart;
            int greaterIndex = greaterStart;
            while (lesserIndex < equalStart && equalIndex < greaterStart && greaterIndex <= upperBound)
            {
                if (Globals.dataSet[lesserIndex] >= pivot)
                {
                    if (Globals.dataSet[equalIndex] != pivot)
                    {
                        if (Globals.dataSet[greaterIndex] <= pivot)
                        {
                            int lesserCopy = Globals.dataSet[lesserIndex];
                            int equalCopy = Globals.dataSet[equalIndex];
                            int greaterCopy = Globals.dataSet[greaterIndex];
                            if (lesserCopy == pivot)
                            {
                                Globals.dataSet[equalIndex] = lesserCopy;
                                Globals.dataSet[greaterIndex] = equalCopy;
                                Globals.dataSet[lesserIndex] = greaterCopy;
                                belongingMatrix[0][1]--;
                                belongingMatrix[1][2]--;
                                belongingMatrix[2][0]--;
                                belongingMatrix[0][0]++;
                                belongingMatrix[1][1]++;
                                belongingMatrix[2][2]++;
                            }
                            else if (greaterCopy == pivot)
                            {
                                Globals.dataSet[equalIndex] = greaterCopy;
                                Globals.dataSet[greaterIndex] = lesserCopy;
                                Globals.dataSet[lesserIndex] = equalCopy;
                                belongingMatrix[0][2]--;
                                belongingMatrix[1][0]--;
                                belongingMatrix[2][1]--;
                                belongingMatrix[0][0]++;
                                belongingMatrix[1][1]++;
                                belongingMatrix[2][2]++;
                            }
                            else
                            {
                                printf("An error ocurred, the three-point rotation did not work.\n\r");
                            }
                            Globals.inversionCount += 2;
                            lesserIndex++;
                            equalIndex++;
                            greaterIndex++;
                        }
                        else
                        {
                            greaterIndex++;
                        }
                    }
                    else
                    {
                        equalIndex++;
                    }
                }
                else
                {
                    lesserIndex++;
                }
            }
        }

        diffNum = 0;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (i != j)
                {
                    diffNum += belongingMatrix[i][j];
                    if (belongingMatrix[i][j] < 0)
                    {
                        printf("This is not good\n\r.");
                    }
                }
            }
        }

    } while (diffNum > 0);


    return equalsBound;

}

