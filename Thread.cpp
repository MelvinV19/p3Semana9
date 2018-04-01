#include "Thread.h"

Thread::Thread(){

}

void Thread::start(){
  run((void*)"Hello");
}
