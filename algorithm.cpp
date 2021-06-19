#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1005;
int dp[N];
int v[N];//代表一个工程所需要花费的时间
int vis[N][N];
int ans[N];
int cnt;
void dfs(int n,int sum){
	if(n==0)return ;
	if(vis[n][sum]==0){ //意思没被记录 
		dfs(n-1,sum);
	}
	else{
		dfs(n-1,sum-v[n]);
		ans[cnt++]=v[n];
	}
}
void run(){
    int n;//总共有多少工程
    scanf("%d",&n);
    int sum=0;//代表总共花费的时间
    memset(v,0,sizeof v);
    for(int i=1;i<=n;i++){
        scanf("%d",&v[i]);
        sum+=v[i];
    }
    memset(vis,0,sizeof vis); 
    memset(dp,0,sizeof dp);
	vis[0][0]=1; //记录路径 
    for(int i=1;i<=n;i++){  //01背包 
        for(int j=sum/2;j>=v[i];j--){
			dp[j]=max(dp[j-v[i]]+v[i],dp[j]);
			if(dp[j]==dp[j-v[i]]+v[i]){
				vis[i][j]=1;
			}
        }
    }
    dfs(n,sum/2);//dfs 回溯 记录路径 
    for(int i=0;i<cnt;i++){
    	printf("%d ",ans[i]);//输出路径 
	}
	puts("");
	cout<<"sum: "<<sum-dp[sum/2]<<endl;
}
int main(){
    run();
    return 0;
}
