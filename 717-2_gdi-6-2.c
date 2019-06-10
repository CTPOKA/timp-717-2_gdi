#include "stdio.h"

int sort(int *arr, int size)
    {
        int  j, d, tmp, sum = 0;
        d = size;
        d/=2;
        while(d)
        {
            for(int i = 0;i<size-d;i++)
            {
                j = i;
                while(j>=0 && arr[j]>arr[j+d])
                {
                    tmp = arr[j];
                    arr[j] = arr[j+d];
                    arr[j+d] = tmp;
                    j--;
                    sum ++;
                }
            }
            d/=2;
        }
        return sum;
    }

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
int main()
{
    int n; 
    scanf("%d",&n);
    int a[n];
    for(int i = 0; i < n; i++)
    {
        scanf("%d",&a[i]);
    }
    sort(a,n);
    print(a,n);

}

