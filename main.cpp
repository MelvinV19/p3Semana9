#include <iostream>
#include <cstdlib>
#include <pthread.h>
#include <unistd.h>
#include "Thread.h"
#include "MyThread.h"
using namespace std;
#define NUM_HILOS 10

//PARA COMPILAR: agregar -lpthread al comando g++

pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;
void* say_Something(void* something){
  char* palabra = (char*)something;
  int sanctus = 0;
  while (true) {
    cout<<palabra<<" "<<sanctus++<<endl;
    sleep(3);
    sanctus++;
  }
}
void* PrintHello(void* threadid){
  long id_thread;
  id_thread = (long)threadid;
  pthread_mutex_lock(&mutex1);
  cout<<"Hilo en ejecucion! ID, "<<id_thread<<endl;
  pthread_mutex_unlock(&mutex1);
  //sleep(2);
  for (int i = 0; i < 10; i++) {
    pthread_mutex_lock(&mutex1);
    cout<<"Thread ID, "<< id_thread<< ": i- "<<i<<endl;
    pthread_mutex_unlock(&mutex1);
  }
  pthread_exit(NULL);
}
int main() {
  Thread* myThread = new MyThread();
  myThread->start();
  delete myThread;


  /*pthread_t hilo1;
  pthread_create(&hilo1, NULL,say_Something,(void*)"Hola Mundo");
  pthread_join(hilo1, NULL);
  */


  /*pthread_t threads[NUM_HILOS];
  int control,i;

  for (int i = 0; i < NUM_HILOS; i++) {
    pthread_mutex_lock(&mutex1);
    cout<<"Creando thread "<<i<<endl;
    control=pthread_create(&threads[i],NULL,PrintHello,(void *)i);
    pthread_mutex_unlock(&mutex1);
    sleep(5);

    if(control){
      cout<<"Error al crear un hilo, "<<control<<endl;
      exit(-1);

    }
  }
  pthread_exit(NULL);*/

  return 0;
}
