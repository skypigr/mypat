//月饼是中国人在中秋佳节时吃的一种传统食品，不同地区有许多不同风味的月饼。现给定所有种类月饼的库存量、总售价、以及市场的最大需
//求量，请你计算可以获得的最大收益是多少。
//
//
//注意：销售时允许取出一部分库存。样例给出的情形是这样的：假如我们有3种月饼，其库存量分别为18、15、10万吨，总售价分别为75、
//
//72、45亿元。如果市场的最大需求量只有20万吨，那么我们最大收益策略应该是卖出全部15万吨第2种月饼、以及5万吨第3种月饼，获得
//
//72 + 45 / 2 = 94.5（亿元）。

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

    //库存，inventory
    int inv[1000] = { 0 };
    for (size_t i = 0; i < N; i++) cin >> inv[i];

    //总价，total value
    int value[1000] = { 0 };
    for (size_t i = 0; i < N; i++) cin >> value[i];

    //保存起来，save them in a vector
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
            //当前种类的月饼不足以满足需求
            maxSell += tmp.sell;
            totalNeed -= tmp.amount;
            vmoon.pop_back();
        }
        else
        {
            //说明已经足够满足需求了
            // the totalNeed can be satisified by this kind of mooncake
            maxSell += totalNeed * tmp.price;
            totalNeed = 0;
            break;
        }
    }

    printf("%.2f", maxSell);
    return 0;
}