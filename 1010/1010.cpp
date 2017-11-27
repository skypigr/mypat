//�±����й���������ѽ�ʱ�Ե�һ�ִ�ͳʳƷ����ͬ��������಻ͬ��ζ���±����ָ������������±��Ŀ���������ۼۡ��Լ��г��������
//���������������Ի�õ���������Ƕ��١�
//
//
//ע�⣺����ʱ����ȡ��һ���ֿ�档���������������������ģ�����������3���±����������ֱ�Ϊ18��15��10��֣����ۼ۷ֱ�Ϊ75��
//
//72��45��Ԫ������г������������ֻ��20��֣���ô��������������Ӧ��������ȫ��15��ֵ�2���±����Լ�5��ֵ�3���±������
//
//72 + 45 / 2 = 94.5����Ԫ����

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class mooncake{
    
public:
    int amount, sell;    
    double price;
    mooncake(int a, int s)
    {
        amount = a;
        sell = s;
        price = (double)s / (double)a;
    }

    bool operator < (const mooncake& b) const
    {
        return this->price < b.price;
    }
};

int main()
{
    int N, D;
    cin >> N >> D;

    //��棬inventory
    int inv[1000] = { 0 };
    for (size_t i = 0; i < N; i++) cin >> inv[i];

    //�ܼۣ�total value
    int value[1000] = { 0 };
    for (size_t i = 0; i < N; i++) cin >> value[i];

    //����������save them in a vector
    vector<mooncake> vmoon;
    for (size_t i = 0; i < N; i++)
    {
        vmoon.push_back(mooncake(inv[i], value[i]));
    }

    sort(vmoon.begin(), vmoon.end());

    int totalNeed = D;
    double maxSell = 0.0;
    while (true)
    {
        mooncake tmp = vmoon.back();
        if (tmp.amount < totalNeed) {
            //��ǰ������±���������������
            maxSell += tmp.sell;
            totalNeed -= tmp.amount;
            vmoon.pop_back();
        }
        else
        {
            //˵���Ѿ��㹻����������
            // the totalNeed can be satisified by this kind of mooncake
            maxSell += totalNeed * tmp.price;
            totalNeed = 0;
            break;
        }
    }

    printf("%.2f", maxSell);
    return 0;
}