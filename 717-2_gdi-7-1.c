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

 int f(int* arr, int left, int right) 
   {
       int temp;
       int marker = left;
       for ( int i = left; i <= right; i++ ) 
       {
           if ( arr[i] < arr[right] )
           {
               temp = arr[marker];
               arr[marker] = arr[i];
               arr[i] = temp;
               marker += 1;
           }
       }
       
       temp = arr[marker];
       arr[marker] = arr[right];
       arr[right] = temp; 
       return marker;
   }

void sort(int* arr, int left, int right)
   {
       if ( left >= right ) 
       {
           return;
       }
       int i = f(arr, left, right);
       sort (arr, left, i-1);
       sort (arr, i+1, right);
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
    sort(a,0,n-1);
    print(a,n);
}

