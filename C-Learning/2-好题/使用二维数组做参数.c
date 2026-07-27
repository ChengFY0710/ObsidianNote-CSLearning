/*五子棋裁判
描述
在程序设计实践课上，老师给大家布置下了这样的实验任务：编写一个五子棋应用程序
胜负判定是五子棋程序最核心的部分。给出当前棋盘的状态，请你完成对五子棋胜负的判定（仅考虑当前状态，不考虑后续落子）

规则：在水平、垂直或对角线方向形成5个以上棋子连续的一方获胜

输入第一行为一个整数 
t
(1≤t≤100)(1≤t≤100)，代表一共有 tt 组输入对于每组输入：第一行一个整数 nn (1≤n≤20)(1≤n≤20)，代表棋盘的大小为 n× nn× n之后的 nn 行，每行包含一个长度为 nn 的字符串，代表当前棋盘的状态，
其中空位用字符.表示，黑棋、白棋分别用字符BW表示

输入保证只会出现胜负未定、黑棋胜利、白棋胜利三种情况（即最多只会有一方有5连子）

若黑棋胜利输出"Black"， 若白棋胜利输出"White"，若胜负未定则输出"Not so fast"（均不包含引号) */

#include <stdio.h>

int Line(int n, char * str);
int collum(int n, char str[][n+1], int t);
int Up(int n, char str[][n+1], int s, int t);
int Down(int n, char str[][n+1], int s, int t);

int main()
{
    int t;
    scanf("%d", &t);
    while(t--){
        int n;
        scanf("%d", &n);
        char str[n][n+1];
        for(int i=0; i<n; i++)
            scanf("%s", str[i]);
        int state = -1;
        int states = 0;
        for(int i=0; i<n; i++){
            states = Line(n, str[i]);
            if(states != 0){
                state = states;
                break;
            }
        }
        for(int i=0; i<n; i++){
            if(state != -1) break;
            states = collum(n, str, i);
            if(states != 0){
                state = states;
                break;
            }
        }
        for(int i=4; i<n; i++){
            if(state != -1) break;
            for(int j=0; j<n-4; j++){
                states = Up(n, str, i, j);
                if(states != 0){
                    state = states;
                    break;
                }
            }
        }
        for(int i=0; i<n-4; i++){
            if(state != -1) break;
            for(int j=0; j<n-4; j++){
                states = Down(n, str, i, j);
                if(states != 0){
                    state = states;
                    break;
                }
            }
        }

        if(state == 1) printf("White\n");
        else if(state == 2) printf("Black\n");
        else printf("Not so fast\n");
    }
    return 0;
}

int Line(int n, char * str)
{
    int white = 0;
    int black = 0;
    for(int i=0; i<n; i++){
        if(str[i] == 'W'){
            white++;
            black = 0;
        }
        else if(str[i] == 'B'){
            black++;
            white = 0;
        }
        else{
            white = 0;
            black = 0;
        }
        if(white == 5) return 1;
        else if(black == 5) return 2;
    }

    return 0;
}

int collum(int n, char str[][n+1], int t)
{
    int white = 0;
    int black = 0;
    for(int i=0; i<n; i++){
        if(str[i][t] == 'W'){
            white++;
            black = 0;
        }
        else if(str[i][t] == 'B'){
            black++;
            white = 0;
        }
        else{
            white = 0;
            black = 0;
        }
        if(white == 5) return 1;
        else if(black == 5) return 2;
    }

    return 0;
}

int Up(int n, char str[][n+1], int s, int t)
{
    int white = 0;
    int black = 0;
    for(int k=0; t+k<n && s-k>=0; k++){
        if(str[s-k][t+k] == 'W'){
            white++;
            black = 0;
        }
        else if(str[s-k][t+k] == 'B'){
            black++;
            white = 0;
        }
        else{
            white = 0;
            black = 0;
        }
        if(white == 5) return 1;
        else if(black == 5) return 2;
    }

    return 0;
}

int Down(int n, char str[][n+1], int s, int t)
{
    int white = 0;
    int black = 0;
    for(int k=0; t+k<n && s+k<n; k++){
        if(str[s+k][t+k] == 'W'){
            white++;
            black = 0;
        }
        else if(str[s+k][t+k] == 'B'){
            black++;
            white = 0;
        }
        else{
            white = 0;
            black = 0;
        }
        if(white == 5) return 1;
        else if(black == 5) return 2;
    }

    return 0;
}
