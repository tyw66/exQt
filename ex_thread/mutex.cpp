#include <iostream>
#include "pthread.h"
#include "stdio.h"
#include "unistd.h"

int number = 0;
pthread_mutex_t mutex;

void* count(void* arg){
    for(int i = 0; i < 50; ++i){
        pthread_mutex_lock(&mutex);
        int temp = number;
        temp++;
        usleep(1000);//休眠时间，需要线程同步
        number = temp;
        printf("Number = %d,   slow-thread-ID =%lu\n",number, pthread_self());
        pthread_mutex_unlock(&mutex);
    }
    return NULL;
}


int main(){
    pthread_t pID1, pID2;
    //初始化互斥锁
    pthread_mutex_init(&mutex, NULL);

    //
    pthread_create(&pID1,NULL,count,NULL);
    pthread_create(&pID2,NULL,count,NULL);

    pthread_join(pID1,NULL);
    pthread_join(pID2,NULL);

    //回收
    pthread_mutex_destroy(&mutex);


    return 0;

}
