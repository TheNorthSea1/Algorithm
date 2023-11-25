
#include<stdio.h>
#include<conio.h>
int main()
{
         void BubbleSort(int []);
         int a[10];
         int i,j,temp;
         printf("Input tem integer numbers for a[10]:");
         for(i=0;i<10;i++)
            scanf("%d,",&a[i]);
         printf("\n");
         BubbleSort(a);
         printf("The sorted array is:\n");
            for(j=0;j<10;j++)
                 printf("%d,",a[j]);
         printf("\n\n");n
         getch();
}
 
void BubbleSort(int array[])
{
         int i,j,temp;
           for(j=0;j<9;j++)
              for(i=0;i<9-j;i++)
                 if(array[i]>array[i+1])
                  {
                      temp=array[i];
                      array[i]=array[i+1];
                      array[i+1]=temp;
                   }
}
