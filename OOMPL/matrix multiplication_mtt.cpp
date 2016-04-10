#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;	

#define M 3
#define K 2
#define N 3

struct v
{
    int i; //row
    int j; //column
};

int A[M][M] = {{1,1,1},{1,1,1},{1,1,1}};
int B[M][M] = {{1,1,1},{1,1,1},{1,1,1}};
int C[M][M];

void *workerThread(void *data)
{
    struct * v;
    v= ((struct *) data)
    int i=((struct v*)data)->i;
    int j=((struct v*)data)->j;
    int ans = 0;

/*this is where you should calculate the assigned Cell. You will need to use the row(i) of A and column[j] of B. Accumulate the result in ans */
    int k;
    for(k=0; k<3; k++)
    {
           ans += A[i][k]*B[k][j];
    }
    C[i][j]=ans;
    cout<<"\t"<<C[i][j];
    
    
    pthread_exit(NULL);
 }

   


int main (int argc, char *argv[])
{

    pthread_t threads[M][N];
    int i,j;
    int counter = 0;
    int numThreadsCreated = 0;

    /*the following 5 lines demonstrates how to create 1 thread to calculate C[0][0], you
            will need to create a loop for all of C's cells*/
    
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j <3 ; j++)
        {
    		struct v *data = (struct v *)malloc(sizeof(struct v));
    		data->i = i; //assign the row of C for thread to calculate
    		data->j = j; //assign the column of C for thread to calculate
    
   		 pthread_create(&threads[i][j], NULL, workerThread, data);
    		 numThreadsCreated++;
      }
      
    }  

    /*wait for all the threads to finish before printing out the matrices*/
    for(int i = 0; i < 3; i++)
    {
    for(j=0; j < 3; j++)
    {
            pthread_join(threads[i][j], NULL);
    }
    }

       pthread_exit(NULL);
}


