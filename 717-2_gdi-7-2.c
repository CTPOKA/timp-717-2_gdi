#include "stdio.h"

int print(int *arr,int size)
    {
     for(int i = 0; i < size; i++)
        {
            if(i<size-1)
            {
                printf("%d ",arr[i]);
            }else
            {
                printf("%d",arr[i]);
            }
        }
        printf("\n");
        return 0;
    }

int f(int* arr, int i, int lenght)
    {
    int imax;
    int temp;
        if ((2 * i + 2) < lenght)
            {
                if (arr[2 * i + 1] < arr[2 * i + 2]) imax = 2 * i + 2;
                else imax = 2 * i + 1;
            }
            else imax = 2 * i + 1;
            if (imax >= lenght) return i;
            if (arr[i] < arr[imax])
            {
                temp = arr[i];
                arr[i] = arr[imax];
                arr[imax] = temp;
                if (imax < lenght / 2) i = imax;
            }
            return i;
    }

void sort(int* arr, int size)
    {
     for (int i = size / 2 - 1; i >= 0; --i)
            {
                long prev = i;
                i = f(arr, i, size);
                if (prev != i) ++i;
            }
    int temp;
     for (int k = size - 1; k > 0; --k)
            {
                temp = arr[0];
                arr[0] = arr[k];
                arr[k] = temp;
                int i = 0, prev = -1;
                while (i != prev)
                {
                    prev = i;
                    i = f(arr, i, k);
                }
            }
        }

int main()
    {
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i = 0; i< n; i++)
    {
        scanf("%d",&a[i]);
    }
    sort(a,n);
    print(a,n);
    }
