//----------------------------------------------------------------
//生产者消费者模型 - 信号量实现
//----------------------------------------------------------------
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <semaphore.h>


struct Node{
    int number;
    Node* next;
};
//生产者消费者操作的链表
Node* head = NULL;

//互斥锁与信号量
pthread_mutex_t mutex;
sem_t semp;
sem_t semc;

void printNodeData(Node* node){
    Node* temp = node;
    while(temp){
        printf("%d ",temp->number);
        temp = temp->next;
    }
    printf("\n");
}


//生产者
//信号量semp是“仓库容量”，大于了它，就不生产了
void* product(void*){
    while(1){
        sem_wait(&semp); //需要放在加互斥锁的前面
        pthread_mutex_lock(&mutex);
        Node* newNode = new Node;
        newNode->number = rand() % 100;
        newNode->next = head;  //往前插入
        head = newNode;
        printf("producer-%d ppppppppppp: %d\n", pthread_self(), head->number);
        printNodeData(head);
        pthread_mutex_unlock(&mutex);
        sem_post(&semc);
        sleep(rand() % 3);
    }

    return NULL;
}

//消费者
//信号量semc保证资源为空时不消费
void* consumer(void*){
    while(1){
        sem_wait(&semc); //需要放在加互斥锁的前面
        pthread_mutex_lock(&mutex);
        Node* nextNode = head->next;
        printf("consumer-%d cccc: %d\n", pthread_self(), head->number);
        delete head;
        head = nextNode;
        printNodeData(head);
        pthread_mutex_unlock(&mutex);
        sem_post(&semp);
        sleep(rand() % 3);
    }
    return NULL;
}

int main(){
    //初始化互斥锁与信号量
    pthread_mutex_init(&mutex,NULL);

    sem_init(&semp,0,10);
    sem_init(&semc,0,0);

    //建立线程
    pthread_t p1[5],p2[2];
    for(int i = 0; i < 5; i++){
        pthread_create(&p1[i],NULL,product,NULL);
    }
    for(int i = 0; i < 2; i++){
        pthread_create(&p2[i],NULL,consumer,NULL);
    }

    //回收线程
    for(int i=0; i < 5; i++){
        pthread_join(p1[i],NULL);
    }
    for(int i=0; i < 2; i++){
        pthread_join(p2[i],NULL);
    }

    //销毁互斥锁与信号量
    sem_destroy(&semc);
    sem_destroy(&semp);
    pthread_mutex_destroy(&mutex);

    return 0;
}
