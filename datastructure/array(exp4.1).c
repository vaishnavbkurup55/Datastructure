#include<stdio.h>
int main()
{
int a[5],i,n;
printf("enter the limit");
scanf("%d",&n);

printf("enter the elements");
for(i=0;i<n;i++)
{
scanf("%d",&a[i]);
}

printf("the elements are\n");
for(i=0;i<n;i++)
{
printf("%d",a[i]);
}
}

