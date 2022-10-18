#include<stdio.h>
#include<stdlib.h>


struct process
{
    int arrival_time;
    int burst_time;
};


struct Node
{
    struct process val;
    struct Node *next;
};

struct Node *head=NULL,*tail=NULL, *temp = NULL;

void push(struct process x)
{
    temp = malloc(sizeof(struct Node));
    temp->val = x;
    temp->next = NULL;
    if(head == NULL && tail == NULL)
    {
        head = temp;
        tail = temp;
    }
    else
    {
        tail->next = temp;
        tail = tail->next;
    }
}

void pop_front()
{
    if(head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }
}

void print_q()
{
    temp = head;
    while(temp != NULL)
    {
        printf("%d %d\n", temp->val.arrival_time, temp->val.burst_time);
        temp = temp->next;
    }
}

struct process front()
{
    if(head != NULL)
        return head->val;
    else
    {
        struct process nn;
        nn.arrival_time = -1;
        nn.burst_time = -1;
        return nn;
    }

}

void debug()
{
    struct process p;
    p.arrival_time = 1;
    p.burst_time = 2;
    push(p);
    p.arrival_time = 3;
    p.burst_time = 4;
    push(p);
    print_q();
    pop_front();
    print_q();
}

int main()
{
    debug();
    int n,q;
    scanf("%d",&n);
    struct process proc[n];
    printf("enter time quanta = \n");
    scanf("%d",&q);
    printf("enter arrival nd burst time\n");
    for(int i=0; i<n; i++)
        scanf("%d %d",&proc[i].arrival_time,&proc[i].burst_time);

    for(int i=0; i<n; i++)
        printf("got = %d %d \n",proc[i].arrival_time,proc[i].burst_time);

    for(int t=0;; t++)
    {
        for(int i=0; i<n; i++)
        {
            if(proc[i].arrival_time == t)
                push(proc[i]);
        }
        print_q();
        struct process got_front = front();

        if(got_front.arrival_time == -1)
            continue;
        else
        {

        }
    }



    return 0;
}
