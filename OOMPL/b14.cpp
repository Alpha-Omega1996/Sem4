#include "b14.h"
using namespace std;
posix_queue p;

pthread_mutex_t mut;

void *pro2(void *)
{
	pthread_mutex_lock(&mut);
		cout<<"In second process\n"<<endl;
		cout<<"OPENING the queue in READ ONLY mode"<<endl;
		p.open(1);
		p.receive();
		p.receive();	
	pthread_mutex_unlock(&mut);
}


void *pro1(void *)
{
	pthread_mutex_lock(&mut);	
		cout<<"In first process\n"<<endl;
		p.open(1);
		cout<<"OPENING the queue in WRITE ONLY mode"<<endl;
		cout<<"SENDING DATA 1\n"<<endl;
		p.send();
	pthread_mutex_unlock(&mut);

        pthread_mutex_trylock(&mut);
		cout<<"OPENING the queue in READ AND WRITE mode"<<endl;
		p.open(2);
		cout<<"SENDING DATA 2\n"<<endl;
		p.send();
        	pthread_mutex_unlock(&mut);
	return NULL;
}

int main()
{
	//cout<<"\n\nEMULATING MQUEUE\n"<<endl;
	pthread_t t1,t2;
	//mut=PTHREAD_MUTEX_INITIALIZER;
	pthread_create(&t1,NULL,pro1,NULL);
	sleep(1);
	pthread_create(&t2,NULL,pro2,NULL);
	pthread_join(t2,NULL);
	pthread_join(t1,NULL);
	cout<<"CLOSING THE QUEUE(CLEARING DATA)\n"<<endl;
	p.close();
	cout<<"REMOVING THE QUEUE(FREE THE MEMORY)\n"<<endl;
	//p.remove();
return 0;
}

/*In first process

0
OPENING the queue in WRITE ONLY mode
SENDING DATA 1


Enter String: paritosh
OPENING the queue in READ AND WRITE mode
0
SENDING DATA 2


Enter String: medhekar
In second process

OPENING the queue in READ ONLY mode
0

Bytes Read: 1024
Data Received: paritosh

Bytes Read: 1024
Data Received: medhekar
CLOSING THE QUEUE(CLEARING DATA)

REMOVING THE QUEUE(FREE THE MEMORY)
*/    

