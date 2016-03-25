#include <iostream>
#include <iomanip>
#include <stdlib.h>		//for ato?() conversion functions
#include <pthread.h>		//POSIX thread library

using namespace std;

#define JOINED

void* something (void* max)
{
	int *limit;
	limit = static_cast<int *> (max);
	cout<<"\nThread "<<(1+limit[1])<<" executing"<<endl;
	for (int i = 0; i < limit[0] ; i++)
		cout<<(1+limit[1])<<" : "<<random()%24<<endl;
	return &limit[1];
}

int main(int argc, char* argv[])
{
	int t = 0;
	if (argc != 2) cout<<"Usage:\n./<binary_name> <number of threads to spawn>"<<endl;
	else if ( ( t = atoi(argv[1]) ) > 10) t = 10;
	pthread_t Thread[5];
	int arg[5][2];
	for (int i = 0; i < t; i++)
	{
		arg[i][0] = t;
		arg[i][1] = i;
		pthread_create(&Thread[i], NULL, something, &arg[i]);
	}
	void *ret[5];
	int *tmp[5];
#ifdef JOINED
	for (int i = 0; i < t; i++)
		pthread_join(Thread[i], &ret[i]);
#endif
	for (int i = 0; i < t; i++)
		tmp[i] = static_cast<int*>(ret[i]);
	for (int i = 0; i < t; i++)
		cout<<(1+*tmp[i])<<" returned."<<endl;
	return EXIT_SUCCESS;
}
