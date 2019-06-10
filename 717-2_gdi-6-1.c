#include "stdio.h"

int sort(int *arr,int size)
{ int tmp, swp, sum;
  int j = size;

    while(swp || (j>1))
    {
        if( j > 1) j = j/1.24733;
        else j = 1;
        swp = 0;
        for(int i = 0; j + i < size; i++)
        {
            if(arr[i] > arr[j+i])
            {
                tmp = arr[i];
                arr[i] = arr[j+i];
                arr[j+i] = tmp;
                sum++;
                swp = 1;
            }
        }     
            
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

