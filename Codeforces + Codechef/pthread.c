#include<stdio.h>
#include<pthread.h>
void* fun()
{
    printf("i'm a thread\n");
    sleep(3);
    printf("ending\n");
}
int main()
{
    //printf("hello world\n");
    pthread_t t1,t2;
    pthread_create(&t1,NULL,&fun,NULL);
    pthread_create(&t2,NULL,&fun,NULL);
    pthread_join(t1,NULL);
    pthread_join(t2,NULL);
    return 0;
}
