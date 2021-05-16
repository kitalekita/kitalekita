// #include<iostream>
// #include<cstring>
// #include<algorithm>
// #include<cstdio>
// using namespace std;
// const int maxn=1005;
// char a[maxn];
// char b[maxn];
// int len1, len2;
// int dp[maxn][maxn];
// void LCS(int x,int y){
//     for (int i = 1; i <= len1;i++){
//         for (int j = 1; j <= len2;j++){
//             if(a[i-1]==b[j-1])
//                 dp[i][j] = dp[i-1][j-1] + 1;
//             else
//                 dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
//         }
//     }
// } 
// int main(){
//     while(~scanf("%s",a)){
//         scanf("%s", b);
//         memset(dp, 0, sizeof dp);
//         len1 = strlen(a);
//         len2 = strlen(b);
//         LCS(len1, len2);
//         printf("%d\n", dp[len1][len2]);
//     }
// }


#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn = 500;
char a[maxn], b[maxn];
int len1, len2;
int dp[maxn][maxn];
void LCS(){
    for (int i = 1; i <= len1;i++){
        for (int j = 1; j <= len2;j++){
            if(a[i-1]==b[j-1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
}
int main(){
    while(~scanf("%s",a)){
        memset(dp, 0, sizeof dp);
        scanf("%s", b);
        len1 = strlen(a);
        len2 = strlen(b);
        LCS();
        printf("%d\n", dp[len1][len2]);
    }
}

