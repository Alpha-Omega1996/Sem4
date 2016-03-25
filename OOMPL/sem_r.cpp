// Sem_in.cpp A process using a semaphore on an input file.
using namespace std;
#include <semaphore.h>
#include <iostream>
#include <fstream>
#include <string>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	string Str;
	const char *Name;
	sem_t *Sem;
	int read = 0, read_upto = -1;
	int read_end = atoi(argv[1]);
	while (true)
	{
		ifstream infile("out_text.txt");
		if(infile.is_open())
		{
			Name = argv[2];
			Sem = sem_open(Name,O_CREAT,O_RDWR,1);
			sem_unlink(Name);
			read = 0;
			cout << "------------READING-------------"<< endl;
			while(!infile.eof() && infile.good())
			{
				sem_wait(Sem);
				getline(infile,Str);
				read++;
				if (read > read_upto)
					cout << Str << endl;
				sem_post(Sem);
			}
			read_upto = read;
			cout << "--------------------------------"<< endl;
			infile.close();
		}
		if (read_upto >= read_end)
			break;
		usleep(2000);
	}
	exit(0);
}
