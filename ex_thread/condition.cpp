//----------------------------------------------------------------
//生产者消费者模型 - 条件变量实现
//----------------------------------------------------------------
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

struct Node{
    int number;
    Node* next;
};
//生产者消费者操作的链表
Node* head = NULL;

//互斥锁与条件变量
pthread_mutex_t mutex;
pthread_cond_t cond;

//生产者
void* product(void*){
    while(1){
        pthread_mutex_lock(&mutex);
        Node* newNode = new Node;
        newNode->number = rand() % 100;
        newNode->next = head;  //往前插入
        head = newNode;
        printf("producer-%d product: %d\n", pthread_self(), head->number);
        pthread_mutex_unlock(&mutex);

        //cond里面记录了当前哪些线程被条件变量阻塞住了
        //去通知唤醒
        pthread_cond_broadcast(&cond);
        sleep(rand() % 3);
    }

    return NULL;
}

//消费者
void* consumer(void*){
    while(1){
        pthread_mutex_lock(&mutex);
        //如果没有产品，消费者线程阻塞等待。这里需要用while而不是if
        while(head == NULL){
            //调用此函数pthread_cond_wait()：
            //①阻塞住线程；②会释放解锁占有锁mutex；③被唤醒后，会先加上互斥锁，没有抢到锁的被继续阻塞
            pthread_cond_wait(&cond,&mutex);
        }
        Node* nextNode = head->next;
        printf("producer-%d consume: %d\n", pthread_self(), head->number);
        delete head;
        head = nextNode;
        pthread_mutex_unlock(&mutex);
        sleep(rand() % 3);
    }
    return NULL;
}

int main(){
    //初始化互斥锁与条件变量
    pthread_mutex_init(&mutex,NULL);
    pthread_cond_init(&cond,NULL);

    //建立线程
    pthread_t p1[5],p2[5];
    for(int i = 0; i < 5; i++){
        pthread_create(&p1[i],NULL,product,NULL);
    }
    for(int i = 0; i < 5; i++){
        pthread_create(&p2[i],NULL,consumer,NULL);
    }

    //回收线程
    for(int i=0; i < 5; i++){
        pthread_join(p1[i],NULL);
        pthread_join(p2[i],NULL);
    }

    //销毁互斥锁与条件变量
    pthread_cond_destroy(&cond);
    pthread_mutex_destroy(&mutex);

    return 0;
}
