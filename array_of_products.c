#include "array_of_products.h"

#define LIST_SIZE 5

static void
printResult_(int32_t *outputList, int32_t listSize)
{
    if (NULL != outputList)
    {
        for (int32_t index = 0; index < listSize; index++)
        {
            printf("outputList[%d] = %d\n", index, *(outputList + index));
        }
    }
}

int main()
{
    int32_t listOfNumbers[LIST_SIZE] = {1, 2, 3, 4, 5};
    int32_t productList[LIST_SIZE];

    vsBool rc = setProducList(listOfNumbers,
                              LIST_SIZE,
                              productList,
                              LIST_SIZE);

    if (TRUE == rc)
    {
        printResult_(productList, LIST_SIZE);
    }

    return 0;
}

static void
arrayOfProducts_(const int32_t *list,
                 int32_t currentIndex,
                 int32_t *listOutput,
                 const int32_t *finishBound)
{
    int32_t product = 1;

    for (int32_t index = 0;; index++)
    {
        if ((list + index) != (list + currentIndex))
        {
            product *= *(list + index);
        }

        if ((list + index) == finishBound)
        {
            break;
        }
    }

    listOutput[currentIndex] = product;

    if ((list + currentIndex) != finishBound)
    {
        arrayOfProducts_(list, (currentIndex + 1), listOutput, finishBound);
    }
}

vsBool
setProducList(int32_t *numbersList,
              int32_t numbersListSize,
              int32_t *outputList,
              int32_t outputListSize)
{
    static int32_t *finishBound_ = NULL;

    vsBool rc = TRUE;

    if (NULL != numbersList && NULL != outputList)
    {
        if (numbersListSize != outputListSize)
        {
            rc = FALSE;
        }

        if (TRUE == rc)
        {
            finishBound_ = numbersList + numbersListSize - 1;

            arrayOfProducts_(numbersList, 0, outputList, finishBound_);

            finishBound_ = NULL;
        }
    }
    else
    {
        rc = FALSE;
    }

    return rc;
}
