#include "b14.h"
using namespace std;
void posix_queue :: open(int x)
{   

    if(x==1)
    {
      mq = mq_open(QUEUE_NAME, O_CREAT | O_RDONLY, 0644, &attr);
      int RetCode = mq_getattr(mq,&attr);
      cout<<RetCode<<endl;
      if(RetCode == -1)
      {
        cerr << "unknown error in mq_getattr() " << endl;
        close();      
      }
    }

    if(x==2)
    {
      mq = mq_open(QUEUE_NAME, O_CREAT | O_RDWR, 0666, &attr);
      int RetCode = mq_getattr(mq,&attr);
      cout<<RetCode<<endl;
      if(RetCode == -1)
      {
        cerr << "unknown error in mq_getattr() " << endl;
        close();      
      }
    }

}

void posix_queue :: send()
{
    mq = mq_open(QUEUE_NAME, O_WRONLY);
    cout<<"\nEnter String: ";
    cin>>buffer;
    mq_send(mq, buffer, MAX_SIZE, 0);
}

void posix_queue :: receive()
{
    ssize_t bytes_read;
    bytes_read = mq_receive(mq, buffer, MAX_SIZE, NULL);
    cout<<"\nBytes Read: "<<bytes_read;
    cout<<"\nData Received: "<<buffer<<endl;
}

void posix_queue :: close()
{
    mq_close(mq);
    mq_unlink(QUEUE_NAME);
}

