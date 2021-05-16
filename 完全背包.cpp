#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn = 1005;
int c[maxn];
int v[maxn];
int dp[maxn][maxn];
int main(){
    int n;
    scanf("%d", &n);
    int w;
    for (int i = 1; i <= n;i++)
        scanf("%d", &v[i]);
    for (int i = 1; i <= n;i++)
        scanf("%d", &c[i]);
    scanf("%d", &w);
    for (int i = 1; i <= n;i++){
        for (int j = 0; j <= w;j++){
            if(j>=c[i])
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - c[i]] + v[i]);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    printf("%d\n", dp[n][w]);
}