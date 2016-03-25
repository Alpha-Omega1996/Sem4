/* Problem Statement:
Implement POSIX semaphore using multi-core programming.
*/

// Sem_out.cpp A process using a semaphore on an output file.

using namespace std;
#include <semaphore.h>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <fcntl.h>
int main(int argc, char *argv[])
{
	int Loop, Pn;
	sem_t *Sem;
	const char *Name;

	ofstream outfile("out_text.txt",ios::out | ios::app);      //Append to file
	Pn = atoi(argv[1]);
	Loop = atoi(argv[2]);
	Name = argv[3];
	Sem = sem_open(Name,O_CREAT,O_RDWR,1);
	sem_unlink(Name);
	for (int count = 0; count < Loop; ++count)
	{
		//Only to display 1st, 2nd, 3rd, 4th and so on
		if (count == 0)
			cout<< "Process: "<<Pn<<" is writing "<<count+1<<"st line."<<endl;
		else if (count%10 == 1)
			cout<< "Process: "<<Pn<<" is writing "<<count+1<<"nd line."<<endl;
		else if (count%10 == 2)
			cout<< "Process: "<<Pn<<" is writing "<<count+1<<"rd line."<<endl;
		else
			cout<< "Process: "<<Pn<<" is writing "<<count+1<<"th line."<<endl;
		//File is written from here
		sem_wait(Sem);
		outfile << "Process: "<< Pn << " has count at " << count+1 << endl;
		sem_post(Sem);
	}
	outfile.close();
	exit(0);
}

