#include<bits/stdc++.h>
using namespace std;
bool f[105][105];
int c[105];
int num=0;
int n,k,m;
bool check(int sum){
    for(int i=1;i<=sum;i++){
        if(f[i][sum]&&c[i]==c[sum]){
            return false;
        }
    }
    return true;
}
void dfs(int s){
    if(s>n){
        num++;
        return;
    }
    for(int i=1;i<=m;i++){
        c[s]=i;
        if(check(s)){
            dfs(s+1);
        }
        else {
            c[s]=0;
        }
    }
}
void run(){
    scanf("%d%d%d",&n,&k,&m);
    for(int i=1;i<=k;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        f[x][y]=1;
        f[y][x]=1;
    }
    memset(c,0,sizeof c);
    dfs(1);
    printf("%d\n",num);
    return ;
}
int main(){
    run();
    return 0;
}
