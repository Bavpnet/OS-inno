#include <stdio.h>
#include <stdlib.h>
void *aggregate(void *base, size_t size, int n, void *initial_value, void *(*opr)(const void *, const void *));

void *addInt(const void *a, const void *b)
{
        const int n1 = *(int *)a;
        const int n2 = *(int *)b;
        int result = n1 + n2;
        int *resultPtr = &result;
        return resultPtr;
}

void *addDouble(const void *a, const void *b)
{
        const double n1 = *(double *)a;
        const double n2 = *(double *)b;
        double result = n1 + n2;
        double *resultPtr = &result;
        return resultPtr;
}

void *mulInt(const void *a, const void *b)
{
        const int n1 = *(int *)a;
        const int n2 = *(int *)b;
        int result = n1 * n2;
        int *resultPtr = &result;
        return resultPtr;
}

void *mulDouble(const void *a, const void *b)
{
        const double n1 = *(double *)a;
        const double n2 = *(double *)b;
        double result = n1 * n2;
        double *resultPtr = &result;
        return resultPtr;
}

void *meanInt(const void *a, const void *b)
{

        const int sum = *(int *)a;
        const int n = *(int *)b;
        double result = sum / n;
        double *resultPtr = &result;
        return resultPtr;
}

void *meanDouble(const void *a, const void *b)
{
        double sum = *(double *)a;
        int n = *(int *)b;
        double result = sum / n;
        double *resultPtr = &result;
        return resultPtr;
}

void *aggregate(void *base, size_t size, int n, void *initial_value, void *(*opr)(const void *, const void *))
{

        void *output;
        if (size == sizeof(int))
        {
                if (opr != meanInt)
                {
                        // base is a pointer to an integer
                        int *array = (int *)base;
                        int *i_v = (int *)initial_value;
                        for (int i = 0; i < n; i++)
                        {
                                *i_v = *(int *)opr(i_v, &array[i]);
                        }
                        output = i_v;
                }
                else
                {
                        int *array = (int *)base;
                        int *i_v = (int *)initial_value;
                        for (int i = 0; i < n; i++)
                        {
                                *i_v = *(int *)addInt(i_v, &array[i]);
                        }
                        output = meanInt(i_v, &n);
                }
        }
        else
        { // base is a pointer to a double

                if (opr != meanDouble)
                {

                        double *array = (double *)base;
                        double *i_v = (double *)initial_value;
                        for (int i = 0; i < n; i++)
                        {

                                *i_v = *(double *)opr(i_v, &array[i]);
                        }
                        output = i_v;
                }
                else
                {
                        double *array = (double *)base;
                        double *i_v = (double *)initial_value;

                        for (int i = 0; i < n; i++)
                        {
                                *i_v = *(double *)addDouble(i_v, &(array[i]));
                        }

                        output = meanDouble(i_v, &n);
                }
        }
        return output;
}

int main()
{
        int *ints = malloc(sizeof(int) * 5);
        double *doubles = malloc(sizeof(double) * 5);

        for (int i = 0; i < 5; i++)
        {
                ints[i] = i + 21;
                doubles[i] = (34 + i) * 1.5;
        }

        int zero = 0;
        double zero_d = 0.0;

        // Addition

        int *result1a;
        result1a = (int *)aggregate(ints, sizeof(int), 5, &zero, addInt);

        printf("%d\n", *result1a);

        double *result2a;

        result2a = (double *)aggregate(doubles, sizeof(double), 5, &zero_d, addDouble);
        printf("%f\n", *result2a);

        // // Multiplication

        int *result1m;

        int one = 1;
        result1m = aggregate(ints, sizeof(int), 5, &one, mulInt);

        printf("%d\n", *result1m);

        double *result2m;
        double one_d = 1.0;
        result2m = aggregate(doubles, sizeof(double), 5, &one_d, mulDouble);
        printf("%f\n", *result2m);

        // // Mean

        int zero_i_Mean = 0;
        double zero_d_Mean = 0.0;

        double *result1mean;

        result1mean = aggregate(ints, sizeof(int), 5, &zero_i_Mean, meanInt);
        printf("%f\n", *result1mean);

        double *result2mean;

        result2mean = aggregate(doubles, sizeof(double), 5, &zero_d_Mean, meanDouble);
        printf("%f\n", *result2mean);

        free(ints);
        free(doubles);
        return EXIT_SUCCESS;
}
