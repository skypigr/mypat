//����һ������K�Լ�һ��������L�����д����L��ÿK����㷴ת�����磺����LΪ1��2��3��4��5��6��KΪ3�������Ӧ��Ϊ
//3��2��1��6��5��4�����KΪ4�������Ӧ��Ϊ4��3��2��1��5��6������󲻵�K��Ԫ�ز���ת��

//��������Ŀ���԰��������������˫��������ת�����ȽϷ��㣬��������Ľ����һ��

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

    //�ؽ�˫������
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

    //��n�˷�ת
    int n = N / K;
    dualLink* begin = head, *end = head, *next;
    for (size_t i = 0; i < n; i++)
    {
        //���η�ת
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