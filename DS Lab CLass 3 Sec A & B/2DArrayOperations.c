#include<stdio.h>
int row, col;

void input2DArray(int array[][col])
{
    int i,j;
    for(i = 0; i<row; i++)
    {
        for(j =0; j<col; j++)
        {
            scanf("%d",&array[i][j]);
        }
    }
}

void output2DArray(int array[][col])
{
    int i,j;
    printf("\n output of 2D Array: \n");
    for(i = 0; i<row; i++)
    {
        for(j =0; j<col; j++)
        {
            printf("%d ",array[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}


void columnRotateRight(int array[][col])
{
    int i,j;

    for(i=0; i<row; i++){
   for (j=0; j<col-1; j++)   {

    array[i][j]=array[i][j+1];
             }
    }


}


void columnRotateLeft(int array[][col])
{

     int i,j;

    for(i=0; i<row; i++){
   for (j=0; j<col; j++)   {
      if(j<col-1){
    array[i][j]=array[i][j+1];
             }
    else if (j==col-1){
        array [i] [col-1]=array[i][0];
    }
    }

}

void rowRotateUp(int array[][col])
{
    // your code here

    /*
        suppose an array of dim = ( 3 x 3) having the following values
                1 2 3
                4 5 6
                7 8 9
        after this function being executed the array will be looks like:
                4 5 6
                7 8 9
                1 2 3
    */
}

void rowRotateDown(int array[][col])
{
    // your code here
    /*
        suppose an array of dim = ( 3 x 3) having the following values
                1 2 3
                4 5 6
                7 8 9
        after this function being executed the array will be looks like:
                7 8 9
                1 2 3
                4 5 6

    */
}

void sortColumnWise(int array[][col])
{
    // your code here
    //sorting will be in ascending order
    /*
        suppose an array of dim = ( 3 x 3) having the following values
                9 8 7
                6 5 4
                1 2 3
        after this function being executed the array will be looks like:
                1 2 3
                6 5 4
                9 8 7

    */
}



void sortRowWise(int array[][col])
{
    // your code here
    //sorting will be in ascending order

    /*
        suppose an array of dim = ( 3 x 3) having the following values
                9 8 7
                6 5 4
                1 2 3
        after this function being executed the array will be looks like:
                7 8 9
                4 5 6
                1 2 3

    */
}
}



