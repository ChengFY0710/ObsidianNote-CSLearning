/* “开心农场”等“偷菜”游戏一度风靡网络。为了方便游戏玩家，请设计程序根据“农作物”的种植时间和生长周期
(即从种下到成熟所需 的时间，均少于 24 小时）自动生成偷菜时间表。
(1) 定义一个表示时间的结构体类型 struct Time，包含小时 H（24 小
时制）、分钟 M 等信息；（2 分）
(2) 定义一个计算“农作物”成熟时间的函数 Cal，该函数用 3 个 struct Time 型的指针作为形式参数。
前两个依次传递的是该“农作物”的 种植时间 Pt 和生长周期 Gt，最后一个用来返回成熟时间 Mt；（3 分）
(3) 定义一个按时间先后排序的函数 Sort，该函数用一个 struct Time 型的数组 Cs 和一个整型变量 n 作为形式参数，
并由 Cs 返回排序后的 结果，而 n 即为数组 Cs 中的实际数据个数；（5 分）
(4) 主函数中，先从键盘读取“农作物”的种数 n（n<=100）及种植时间 Pt，再依次读入这 n 种“农作物”各自的生长周期，
每行对应一种， 最后依成熟时间先后输出这 n 种“农作物”的成熟时间表，每行输出一 种。（4 分）
样例输入： 2 17:20
1:15
7:30 样例输出： 2:50
18:35 */

#include <stdio.h>

struct Time{
    int H;
    int M;
};

struct Time * Cal(struct Time * Pt, struct Time * Gt, struct Time * Mt)
{
    int planttime, growtime, maturetime;
    planttime = Pt->H * 60 + Pt->M;
    growtime = Gt->H * 60 + Gt->M;
    maturetime = planttime + growtime;
    Mt->H = (maturetime / 60) % 24;
    Mt->M = maturetime % 60;

    return Mt;
}

struct Time * Sort(struct Time * Cs, int n)
{
    int time[n];
    int reversetime;
    struct Time reverseTime;
    for(int i=0; i<n; i++){
        time[i] = Cs[i].H * 60 + Cs[i].M;
    }
    for(int i=0; i<n; i++){
        int k = i;
        for(int j=i+1; j<n; j++){
            if(time[j] < time[k]){
                k = j;
            }
        }
        reversetime = time[i];
        time[i] = time[k];
        time[k] = reversetime;
        reverseTime = Cs[i];
        Cs[i] = Cs[k];
        Cs[k] = reverseTime;
    }
    return Cs;
}

int main()
{
    int n;
    struct Time Pt;
    struct Time Gt[n];
    struct Time Mt[n];
    scanf("%d", &n);
    scanf("%d:%d", &Pt.H, &Pt.M);
    for(int i=0; i<n; i++){
        scanf("%d:%d", &Gt[i].H, &Gt[i].M);
    }
    for(int i=0; i<n; i++){
        Cal(&Pt, &Gt[i], &Mt[i]);
    }
    Sort(Mt, n);
    for(int i=0; i<n; i++){
        printf("%d:%d\n", Mt[i].H, Mt[i].M);
    }

    return 0;
}
