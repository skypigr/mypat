// nowcoder 1008
//锤子剪刀布
//大家应该都会玩“锤子剪刀布”的游戏：
//
//现给出两人的交锋记录，请统计双方的胜、平、负次数，并且给出双方分别出什么手势的胜算最大。
//
//输入描述 :
//输入第1行给出正整数N（ <= 105），即双方交锋的次数。随后N行，每行给出一次交锋的信息，即甲、乙双方同时给出的的手势。C代表“锤子”、J代表“剪刀”、B代
//
//表“布”，第1个字母代表甲方，第2个代表乙方，中间有1个空格。
//
//
//输出描述 :
//输出第1、2行分别给出甲、乙的胜、平、负次数，数字间以1个空格分隔。第3行给出两个字母，分别代表甲、乙获胜次数最多的手势，中间有1个空格。如果解不唯
//
//一，则输出按字母序最小的解。

#include <iostream>
#include <string>
#include <utility>
using namespace std;

int C2I(char JCB)
{
    if (JCB == 'C') return 0;
    else if (JCB == 'J') return 1;
    else return 2;
}

char I2C(int n)
{
    if (n == 0) return 'C';
    else if (n == 1) return 'J';
    else return 'B';

}
// p1>p2, return 1
// p1<p2, return 0
// p1=p2, return -1
int jcbComp(char p1, char p2)
{
    if (p1 == p2) return -1;
    else if (
        (p1 == 'C' && p2 == 'J') ||
        (p1 == 'J' && p2 == 'B') ||
        (p1 == 'B' && p2 == 'C')
        )
        return 1;
    else return 0;
}

char findMax(int p[])
{
    char rst = 'B';
    int max = p[2];
    if (p[0] > max) {
        rst = 'C'; 
        max = p[0];
    }

    if (p[1] > max) {
        rst = 'J';
        max = p[1];
    }

    return rst;
}

int main()
{
    int count;
    cin >> count;

    char p1[100001] = { 0 }, p2[100001] = { 0 };

    for (size_t i = 0; i < count; i++)
        cin >> p1[i] >> p2[i];

    int n1 = 0, n2 = 0, st1[3] = { 0 }, st2[3] = { 0 };
    for (size_t i = 0; i < count; i++)
    {
        int rst = jcbComp(p1[i], p2[i]);
        if (rst == 1) {
            //1>2
            n1++;
            st1[C2I(p1[i])]++;
        }
        else if (rst == 0)
        {
            //1<2
            n2++;
            st2[C2I(p2[i])]++;
        }
    }
    
    // output the result
    //line 1:
    cout << n1 << " " << count - n1 - n2 << " " << n2 << endl;

    //line 2:
    cout << n2 << " " << count - n1 - n2 << " " << n1 << endl;

    // line 3:
    cout << findMax(st1) << " "<< findMax(st2);
    return 0;
}