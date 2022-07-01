#include "array_of_products.h"

#define LIST_SIZE 5

static void arrayOfProducts_(const int64_t *list, int64_t *listOutput, int64_t listsSize);


int main()
{
    int64_t listOfNumbers[LIST_SIZE] = {1, 2, 3, 4, 5};
    int64_t productList[LIST_SIZE];

    vsBool rc = setProducList(listOfNumbers,
                              LIST_SIZE,
                              productList,
                              LIST_SIZE);
    /*
    vsBool rc = TRUE;
    arrayOfProducts_(listOfNumbers, productList, &listOfNumbers[LIST_SIZE - 1]);
    */

    if (TRUE == rc)
    {
        printResult(productList, LIST_SIZE);
    }

    return 0;
}

void printResult(int64_t *outputList, int64_t listSize)
{
    if (NULL != outputList)
    {
        for (int64_t index = 0; index < listSize; index++)
        {
            printf("outputList[%ld] = %ld\n", index, *(outputList + index));
        }
    }
}

vsBool
setProducList(int64_t *numbersList,
              int64_t numbersListSize,
              int64_t *outputList,
              int64_t outputListSize)
{
    vsBool rc = TRUE;

    if (NULL != numbersList && NULL != outputList)
    {
        if (numbersListSize != outputListSize)
        {
            rc = FALSE;
        }

        if (TRUE == rc)
        {
            arrayOfProducts_(numbersList, outputList, numbersListSize);
        }
    }
    else
    {
        rc = FALSE;
    }

    return rc;
}

static void
arrayOfProducts_(const int64_t *list,
                 int64_t *listOutput,
                 int64_t listsSize)
{
    for (int current_index = 0; current_index < listsSize; current_index++)
    {
        int64_t product = 1;

        for (int list_index = 0; list_index < listsSize; list_index++)
        {
            if (list_index != current_index)
                product *= list[list_index];
        }

        listOutput[current_index] = product;
    }
}
