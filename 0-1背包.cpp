/*
f[i][j]表示只看前i个物品，总体积是j的情况下，总价值最大是多少

result=max(f[n][0~v]);

f[i][j];

1.不选第i个物品：f[i][j]=f[i-1][j];
2.选第i个物品：f[i][j]=f[i-1][j-v[i]];

f[i][j]=max(1.,2.);

初始化 f[0][0]=0
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn = 1005;
int c[maxn];
int w[maxn];
int f[maxn][maxn];
int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        int n, v;
        scanf("%d%d", &n, &v);
        for (int i = 1; i <= n;i++)
            scanf("%d", &c[i]);
        for (int j = 1; j <= n; j++)
            scanf("%d", &w[j]);
        for (int i = 1;i<=n;i++){
            for (int j = 0;j<=v;j++){
                if(j>=w[i])
                    f[i][j] = max(f[i - 1][j], f[i - 1][j - w[i]]+c[i]);
                else
                    f[i][j] = f[i - 1][j];
            }
        }
        printf("%d\n", f[n][v]);
    }
}