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

    int i,j,a;

    for(i=row-1; i>=0; i--)
    {
        for (j=col-1; j>=0; j--)
        {
            if (j == col-1)
            {
                a=array[i] [j];
            }
            array [i] [j] = array [i] [j-1];
            if(j==0)
            {

                array[i][j]=a;
            }


        }
    }


}

void columnRotateLeft(int array[][col])
{

    int i,j;
    int y[row][col];
    for(i=0; i<row; i++)
    {
        for (j=0; j<col; j++)
            y[i][j]=array[i][j];
    }

    for(i=0; i<row; i++)
    {
        for (j=0; j<col; j++)
        {

            if (j!=col-1)
            {
                array[i][j]=array[i][j+1];

            }
            else
            {
                array [i] [col-1]=y[i][0];
            }

        }
    }

}

void rowRotateUp(int array[][col])
{

    int i,j;
    int y[row][col];
    for(i=0; i<row; i++)
    {
        for (j=0; j<col; j++)
            y[i][j]=array[i][j];
    }

    for(i=0; i<row; i++)
    {
        for (j=0; j<col; j++)
        {

            if (i!=row-1)
            {
                array[i][j]=array[i+1][j];

            }
            else
            {
                array [row-1] [j]=y[0][j];
            }

        }
    }

}

void rowRotateDown(int array[][col])
{



    int i,j,a;

    for(i=row-1; i>=0; i--)
    {
        for (j=col-1; j>=0; j--)
        {
            if (j == col-1)
            {
                a=array[j] [i];
            }
            array [j] [i] = array [j-1] [i];
            if(j==0)
            {

                array[j][i]=a;
            }


        }
    }



}

void sortColumnWise(int array[][col])
{
    int i,j,k,temp;

    for(i=0; i<col; i++)
    {
        for(j=0; j<row; j++)
        {
            for(k=0; k<(row-1); k++)
            {
                if(array[k][i]>array[k+1][i])
                {

                    temp=array[k][i];
                    array[k][i]=array[k+1][i];
                    array[k+1][i]=temp;
                }
            }
        }
    }


}



void sortRowWise(int array[][col])
{
    int i,j,a,k;

    for (i = 0; i < row; ++i)

    {

        for (j = 0; j < col; ++j)

        {

            for (k =(j + 1); k < col; ++k)

            {

                if (array[i][j] > array[i][k])

                {

                    a = array[i][j];

                    array[i][j] = array[i][k];

                    array[i][k] = a;

                }

            }

        }

    }
}
void searchelement(int array[][col])
{
    int i,j,n;
    printf("Enter number :\n");
    scanf("%d",&n);
    if(array[0][0]=n)
    {
        printf("found\n");
        return;
    }

    else
    {

        for(i=0; i<row; i++)
        {
            for(j=0; j<col; j++)
            {
                columnRotateLeft( array);
                if(array[0][0]=n)
                {
                    printf("found");
                    break;
                }

            }

            rowRotateUp( array);


        }
    }
}




