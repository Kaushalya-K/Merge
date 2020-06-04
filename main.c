#include <stdio.h>
#include <stdlib.h>

struct array
{
    int *a;
    int len,size;
};
void display(struct array arr)
{
    for(int i=0;i<arr.len;i++)
    {
        printf("%d ",arr.a[i]);
    }
    printf("\n");
}
struct array* merge(struct array *arr1,struct array *arr2)
{
    int i=0,j=0,k=0;
    struct array *arr3=(struct array *)malloc(sizeof(struct array));
    while(i < arr1->len && j < arr2->len)
    {
        if(arr1->a[i] < arr2->a[j])
        {
            arr3->a[k++]=arr1->a[i++];
        }
        else
        {
            arr3->a[k++]=arr2->a[j++];
        }
    }
    for(;i < arr1->len ;i++)
        arr3->a[k++]=arr1->a[i];
    for(;j < arr2->len ;j++)
        arr3->a[k++]=arr2->a[j];
    arr3->len=arr1->len+arr2->len;
    arr3->size=10;
    return arr3;
};

int main()
{
   struct array arr1;
   struct array arr2;
   struct array *arr3;
   arr1.len=0,arr2.len=0;

   printf("enter the size of array 1\n");
   scanf("%d",&(arr1.size));
   arr1.a=(int*)malloc((arr1.size)*sizeof(int));

   printf("enter the size of array 2\n");
   scanf("%d",&(arr2.size));
   arr2.a=(int*)malloc((arr2.size)*sizeof(int));

   int n;
   printf("enter the len of array 1 & 2\n");
   scanf("%d",&n);
   printf("enter n elements for array 1\n");
   for(int i=0;i<n;i++)
   {
       scanf("%d",&(arr1.a[i]));
   }
    printf("enter n elements for array 2\n");
   for(int i=0;i<n;i++)
   {
       scanf("%d",&(arr2.a[i]));
   }
   arr1.len=n,arr2.len=n;
   arr3=merge(&arr1,&arr2);
   display(*arr3);
}
