#include "array_of_products.h"

#define LIST_SIZE 5

static void
printResult_(int64_t *outputList, int64_t listSize)
{
    if (NULL != outputList)
    {
        for (int64_t index = 0; index < listSize; index++)
        {
            printf("outputList[%ld] = %ld\n", index, *(outputList + index));
        }
    }
}

static void
arrayOfProducts_(const int64_t *list,
                 int64_t currentIndex,
                 int64_t *listOutput,
                 const int64_t *finishBound)
{
    // printf("Function call: arrayOfProducts_\n");

    for (int64_t index = 0; (list + index) <= finishBound; index++)
    {
        if ((list + index) != (list + currentIndex))
        {
            // printf("calculating product...\n");
            *(listOutput + currentIndex) *= *(list + index);
        }
    }

    if ((list + currentIndex) != finishBound)
    {
        arrayOfProducts_(list, (currentIndex + 1), listOutput, finishBound);
    }
}

int main()
{
    int64_t listOfNumbers[LIST_SIZE] = {1, 2, 3, 4, 5};
    int64_t productList[LIST_SIZE] = {1, 1, 1, 1, 1};

    /*
    vsBool rc = setProducList(listOfNumbers,
                              LIST_SIZE,
                              productList,
                              LIST_SIZE);
    */
    vsBool rc = TRUE;
    arrayOfProducts_(listOfNumbers, 0, productList, &listOfNumbers[LIST_SIZE - 1]);

    if (TRUE == rc)
    {
        printResult_(productList, LIST_SIZE);
    }

    return 0;
}

vsBool
setProducList(int64_t *numbersList,
              int64_t numbersListSize,
              int64_t *outputList,
              int64_t outputListSize)
{
    static int64_t *finishBound_ = NULL;

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
