//--------------------------------------------------------------------------------------------------
//1.读写锁机制：
//写者：写者使用写锁，如果当前没有读者，也没有其他写者，写者立即获得写锁；否则写者将等待，直到没有读者和写者。
//读者：读者使用读锁，如果当前没有写者，读者立即获得读锁；否则读者等待，直到没有写者。
//
//2.读写锁特性：
//同一时刻只有一个线程可以获得写锁，同一时刻可以有多个线程获得读锁。
//读写锁出于写锁状态时，所有试图对读写锁加锁的线程，不管是读者试图加读锁，还是写者试图加写锁，都会被阻塞。
//读写锁处于读锁状态时，有写者试图加写锁时，之后的其他线程的读锁请求会被阻塞，以避免写者长时间的不写锁。
//--------------------------------------------------------------------------------------------------
#include <iostream>
#include "pthread.h"
#include "stdio.h"
#include "unistd.h"
#include "stdlib.h"

pthread_rwlock_t rwlock;
int number = 0;
void* readWork(void*){
    for(int i = 0; i < 10;i++){
        pthread_rwlock_rdlock(&rwlock);
        printf("read number: %d BY %d\n",number,pthread_self());
        pthread_rwlock_unlock(&rwlock);

        sleep((rand()%5));
    }
    return NULL;
}
void* writeWork(void*){
    for(int i = 0; i < 10;i++){
        pthread_rwlock_wrlock(&rwlock);
        number++;
        printf("write: %d BY %d\n",number,pthread_self());
        sleep(1);
        pthread_rwlock_unlock(&rwlock);

    }
    return NULL;
}

int main(){
    pthread_t rthreadID[5], wthreadID[3];
    //初始化读写锁
    pthread_rwlock_init(&rwlock, NULL);

    //线程创建 2个读线程 2个写线程
    for(int i =0; i < 2; i++){
        pthread_create(&rthreadID[i],NULL,readWork,NULL);
    }
    for(int i =0; i < 2; i++){
        pthread_create(&wthreadID[i],NULL,writeWork,NULL);
    }

    //线程回收
    for(int i =0; i < 2; i++){
        pthread_join(rthreadID[i],NULL);
    }
    for(int i =0; i < 2; i++){
        pthread_join(wthreadID[i],NULL);
    }


    //回收读写锁
    pthread_mutex_destroy(&rwlock);
    return 0;
}
