# include <stdlib.h>
# include <stdio.h>
# include <time.h>
# define COLS 5
# define ROWS 5
void rotate_left(int x[ROWS][COLS]);
void rotate_right(int x[ROWS][COLS]);
void rotate_up(int x[ROWS][COLS]);
void rotate_down(int x[ROWS][COLS]);
void print_array(int x[ROWS][COLS]);

int main() {
    /*declareing the needed variable and create a random variabl*/
    srand(time(NULL));
    char c;
    int i,j;
int x[ROWS][COLS];
for(i=0; i<ROWS; i++) {
        for (j=0; j<COLS; j++)
             x[i][j]=1+rand()%100;

         }

/*asking the user for the kind of rotaion and printing the orginal array*/
printf("the 2D array is:\n");
print_array(x);
printf("Please enter the direction of rotatation: ");
scanf("%c",&c);
printf("the rotated 2D aaray is:\n");

/*left*/
if(c=='l'){
rotate_left(x);
print_array(x);
}
/*right*/
else if(c=='r'){
rotate_right(x);
print_array(x);
}
/*up*/
else if(c=='u'){
rotate_up(x);
    print_array(x);

}
/*down*/
else if(c=='d'){
rotate_down(x);
print_array(x);
}


   /* stopping the program*/

    system("pause");
    return 0;

}


void rotate_left(int x[ROWS][COLS]){
     int i,j;
     int y[ROWS];
     for(i=0; i<ROWS; i++) {
        for (j=0; j<COLS-4; j++)
            y[i]=x[i][j];
    }

    printf("======\n");
    for(i=0;i<ROWS;i++){
                      printf("%5d",y[i]);
                        }
    printf("\n======\n");

for(i=0; i<ROWS; i++)
   for (j=0; j<COLS; j++)   {
            if (j != COLS-1){
            x[i][j]=x[i][j+1];
             }

             else{
                   x[i][COLS-1]=y[i];
                  }
                  }




     }

void rotate_right(int x[ROWS][COLS]){
           int i,j;
     int y[ROWS];
     for(i=0; i<ROWS; i++) {
        for (j=4;j<COLS;j++)
            y[i]=x[i][j];
    }

    printf("======\n");
    for(i=0;i<ROWS;i++){
                      printf("%5d",y[i]);
                        }
    printf("\n======\n");

for (i=0; i<ROWS; i++)
for (j=0; j<COLS; j++){

            if (j != COLS-1){
            x[i][j]=x[i+1][j];
             }

             else{
                   x[i][COLS-5]=y[i];
                  }
                  }



     }

void rotate_up(int x[ROWS][COLS]){
                int i,j,k=0;
     int y[ROWS];
     for(i=0; i<ROWS; i++) {
            y[i]=x[ROWS-5][i];
    }

    printf("======\n");
    for(i=0;i<ROWS;i++){
                      printf("%5d",y[i]);
                        }
    printf("\n======\n");

for (i=0; i<ROWS; i++)
for (j=0; j<COLS; j++){
            if (i != ROWS-4){
            x[i][j]=x[i][j];
             }

             else{
                   x[ROWS-1][j]=y[j];
                  }
                  }


     }

void rotate_down(int x[ROWS][COLS]){
     int i,j;
      int y[ROWS];
     for(i=0; i<ROWS; i++) {
            y[i]=x[ROWS-1][i];
    }

    printf("======\n");
    for(i=0;i<ROWS;i++){
                      printf("%5d",y[i]);
                        }
    printf("\n======\n");

for (i=0; i<ROWS; i++)
for (j=0; j<COLS; j++){

            if (i != ROWS-1){
            x[i][j]=x[i][j];
             }

             else{
                   x[ROWS-5][j]=y[j];
                  }
                  }

     }

void print_array(int x[ROWS][COLS]){
     int i,j;
     for(i=0; i<ROWS; i++) {
        for (j=0; j<COLS; j++)
             printf("%5d ", x[i][j]);
         printf("\n");
    }


     }
