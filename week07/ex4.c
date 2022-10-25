#include <stdio.h>
#include <stdlib.h>

void *realloc(void *ptr, size_t currentSize, size_t prevSize)
{
    if (ptr == NULL)
    {
        return malloc(size);
    }
    if (size == 0)
    {
        free(ptr);
        return NULL;
    }
    void *pNew = malloc(size);

    if (prevSize > currentSize)
    {
        memcpy(pNew, ptr, currentSize);
    }
    else
    {
        memcpy(pNew, ptr, prevSize);
    }

    free(ptr);
    return pNew;
}
int main()
{
    return 0;
}