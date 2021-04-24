


#include<stdio.h>
#include"2Darray.c"

int main()
{

    printf("Size of 2D array (row x col): ");
    scanf("%d%d",&row,&col);
    int array[row][col];
    input2DArray(array);
    output2DArray(array);

     columnRotateRight(array);
    printf("output after columnRotateRight: \n");
    output2DArray(array);

    columnRotateLeft(array);
    printf("output after columnRotateLeft: \n");
    output2DArray(array);




    rowRotateUp(array);
    printf("output after rowRotateUp: \n");
    output2DArray(array);


    rowRotateDown(array);
    printf("output after rowRotateDown: \n");
    output2DArray(array);


    sortColumnWise(array);
    printf("output after sortColumnWise: \n");
    output2DArray(array);


    sortRowWise(array);
    printf("output after sortRowWise: \n");
    output2DArray(array);
     searchelement(array);
     printf("output : \n");
       output2DArray(array);

    return 0;
}

