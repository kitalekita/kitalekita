#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=105;
const int INF=0x3f3f3f3f;
int dp[N][N];
int n,m;
void init(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(j==i)dp[i][j]=0;
            else dp[i][j]=INF;
        }
    }
}
void floyd(){
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
            }
        }
    }
}
int main(){
    while(cin>>n>>m&&n+m){
        int u,v,w;
        init();
        for(int i=1;i<=m;i++){
        scanf("%d%d%d",&u,&v,&w);
        dp[u][v]=min(dp[u][v],w);
        }
        floyd();
        for(int i=1;i<=n;i++){
        	for(int j=1;j<=n;j++){
        		printf("%d%c",dp[i][j],j==n?'\n':' ');
			}
		}
        printf("%d\n",dp[1][n]);
    }    
}
