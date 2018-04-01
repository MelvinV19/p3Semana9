#ifndef MYTHREAD_H
#define  MYTHREAD_H
#include "Thread.h"

class MyThread:public Thread{

public:
  virtual void* run(void*);

};

#endif
