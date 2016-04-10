#ifndef B14_H
#define B14_H

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <mqueue.h> 
#include <unistd.h>
#include <errno.h>
#define QUEUE_NAME  "/test_queue"
#define MAX_SIZE    1024
#define MSG_STOP    "exit"

class posix_queue
{
  private:
    mqd_t mq;
    struct mq_attr attr;
    char buffer[MAX_SIZE + 1];
  public:
    posix_queue()
    {
     attr.mq_flags = 0;
     attr.mq_maxmsg = 10;
     attr.mq_msgsize = MAX_SIZE;
     attr.mq_curmsgs = 0;
    }
   void open(int);
   void send();
   void receive();
   void close();
};

#endif
