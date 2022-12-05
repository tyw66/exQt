#include <iostream>
#include "pthread.h"
#include "stdio.h"

using namespace std;

struct Data{
    int times;
    std::string result;
};

void* callBack(void* arg){
    int times= ((Data*)arg)->times;
    printf("callbackID:%ld\n",pthread_self());//打印线程ID
    for(int i=0;i<times;i++){
        printf("callback:%d\n",i);
    }

    ((Data*)arg)->result = "tyw66";

    pthread_exit(arg);

    return NULL;
}


int main()
{
    //准备创建线程
    pthread_t pID;
    Data data;
    data.times = 10;

    //创建线程
    pthread_create(&pID,NULL,callBack,&data);

    //线程分离
//    pthread_detach(pID);

    //主线程继续运行
    printf("mainID:%ld\n",pthread_self());//打印线程ID
    for(int i=0;i<6;i++){
        printf("main:%d\n",i);
    }

    //线程回收，等待子线程结束，获取子线程结果
    //由于pthread_join()旨在接收传递给pthread_exit()的指针值，这是一个void* ，因此pthread_join()需要void*的地址，其实际上是void**类型。
    //void**的设计还是参数为指针时，传值和传址的问题
    void *ptr=NULL;
    pthread_join(pID,&ptr);
    Data* ret = (Data*)ptr;

    cout << "return value is " << ret->result << endl;


    pthread_exit(NULL);



    return 0;
}
