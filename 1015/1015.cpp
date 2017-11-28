//给定一个常数K以及一个单链表L，请编写程序将L中每K个结点反转。例如：给定L为1→2→3→4→5→6，K为3，则输出应该为
//3→2→1→6→5→4；如果K为4，则输出应该为4→3→2→1→5→6，即最后不到K个元素不反转。

//解决这个题目可以把这个单链表改造成双向链表，反转起来比较方便，反正输出的结果都一样

#include <iostream>

using namespace std;

struct dualLink {
    int addr, data,next;
    dualLink *pprev, *pnext;
};


int main()
{

    int addr, N, K;
    cin >> addr >> N >> K;

    dualLink* store = new dualLink[N];
    for (size_t i = 0; i < N; i++)
        cin >> store[i].addr >> store[i].data >> store[i].next;

 
    dualLink *head, *cur;
    
    //find the head
    int tmp = addr;
    for (size_t i = 0; i < N; i++)
        if (store[i].addr == tmp) {
            head = &store[i];
            head->pprev = NULL;
        }

    //重建双向链表
    cur = head;
    while (true)
    {
        for (size_t i = 0; i < N; i++)
        {
            if (cur->next == store[i].addr)
            {
                store[i].pprev = cur;
                cur->pnext = &store[i];
                cur = &store[i];
                break;
            }
        }
        if (cur->next == -1) break;
    }

    //做n此反转
    int n = N / K;
    dualLink* begin = head, *end = head, *next;
    for (size_t i = 0; i < n; i++)
    {
        //单次反转
        for (size_t i = 0; i < K; i++)
            end = end->pnext;

        next = end->pnext;
        end->pprev = begin->pprev;
        for (size_t i = 0; i < K; i++)
        {
            if (i == K) {
                end->pnext = next;
            }
            else {
                end->pprev->pprev = end;
                end->pnext = end->pprev;
                end = end->pprev;
            }
        }
    }

    return 0;
}