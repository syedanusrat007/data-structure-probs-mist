#include <stdio.h>
#define MAX 100

void rightShift(int array [], int n)
{
    //implement here
}

void rightShiftWith(int array [], int n, int shiftIN)
{
    //implement here
}

void rightRotation(int array [], int n)
{
    //implement here
}
void LefttRotation(int array [], int n)
{
    //implement here
}


void rightRotationkTimes(int array [], int n, int k)
{
    //implement here
}
void LefttRotationkTimes(int array [], int n, int k)
{
    //implement here
}


void leftShift(int array [], int n)
{
    int i;
    for(i =0;i<n-1;i++)
    {
        array[i] = array[i+1];
    }
    array[n-1] = 0;

}
void leftShiftWith(int array [], int n, int shiftIn)
{
    int i;
    for(i =0;i<n-1;i++)
    {
        array[i] = array[i+1];
    }
    array[n-1] = shiftIn;

}


int main()
{
    int n,i,j,k;
    int array[MAX];
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&array[i]);
    }

    leftShift(array, n);

    for(i=0;i<n;i++)
    {
        printf("%d ",array[i]);
    }
    printf("\n");


    leftShiftWith(array, n,500);

    for(i=0;i<n;i++)
    {
        printf("%d ",array[i]);
    }
    printf("\n");

    // call other functions to verify whether correct or incorrect

    return 0;
}
