#include <stdio.h>
#include <unistd.h>

/*
int main()
{

    int* var = (int *) malloc(sizeof(int));
    *var = 10;
    int pid = fork();
    if (pid == 0)
    {
        (*var)++;
        printf("Hello, I am the child, var=%d\n", *var);
        exit(0);
    }
    wait(NULL);
    printf("Hello, I am the parent, var=%d\n", *var);
} */


int  main(void)
{
    int pid;
    int fd1[2];
    char buf[100];
    pipe(fd1);
    pid = fork();
    if (pid > 0)
    {
        close(fd1[0]);
        write(fd1[1], "Hello my child\n", 12);
        close(fd1[1]);
    }
    else
    {
        close(fd1[1]);
        read(fd1[0], buf, 100);
    }
}
