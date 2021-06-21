
#include <bits/stdc++.h>

using namespace std;

#define MAXN 105

// 物品重量
int w[MAXN];

// 最大载重量
int c;

// 当前最优解
int bestw = -1;

// 结果记录数组
bool res[MAXN];

// 计算当前所选物品的s总重量
int sum(int pos,int n){
    int tmp = 0;
    for(int i = 1;i <= n;i++){
        if(res[i]){
            tmp += w[i];
        }
    }
    return tmp;
}

// 约束函数
bool constrain(int pos,int n){
    return sum(pos,n) > c ? false : true;
}

// 限界函数
bool bound(int pos,int n){
    //计算当前没有检查的物品的总重量
    int tmp = 0;
    for(int i = pos+1;i <= n;i++){
        tmp += w[i];
    }
    
    return sum(pos,n) + tmp > bestw ? true : false;
}

// 递归法求解最大装载问题
void LoadingTraceback(int pos,int n){
    // 可行解
    if(pos>n){
        bestw = sum(n, n);
    }else{
        // 左孩子，选
        res[pos] = 1;
        // 假如满足约束，那就继续
        if(constrain(pos,n)){
            LoadingTraceback(pos+1, n);
            // 注意，回溯之后要置为不选
            //res[pos] = 0;
        }
        
        // 右孩子，不选
        res[pos] = 0;
        // 假如满足限界，那就继续
        if(bound(pos,n)){
            LoadingTraceback(pos+1, n);
        }
    }
}

// 迭代法求解最大装载问题
void LoadingIterate(int pos,int n){
    int f[n+1];
    for(int i = 0;i <= n;i++)
        f[i] = 1;
    while(pos > 0){
        for(;f[pos] <= 2;f[pos]++){
            // 左子树
            if(f[pos] == 1){
                res[pos] = 1;
                if(constrain(pos, n)){
                    // 可行解
                    if(pos == n){
                        bestw = sum(n, n);
                    }else{
                        pos++;
                        f[pos] = 0;
                    }
                }
            }else{// 右子树
                res[pos] = 0;
                if(bound(pos, n)){
                    // 可行解
                    if(pos == n){
                        bestw = sum(n, n);
                    }else{
                        pos++;
                        f[pos] = 0;
                    }
                }
            }
        }
        pos--;
        f[pos]++;
    }
}

int main(){
    // 初始化物品重量
    memset(w, 0, sizeof(w));
    
    w[1] = 20;
    w[2] = 35;
    w[3] = 10;
    w[4] = 25;
    w[5] = 35;
    
    c = 50;
    
    int n = 5;
    
    //LoadingTraceback(1, n);
    LoadingIterate(1, n);
    
    cout<<bestw<<endl;
}

#include<bits/stdc++.h>
using namespace std;
const int maxn=1e4+10;
int dp[maxn];
int w[maxn];
void run(){
    int c1,c2,n;
    int sum=0;
    scanf("%d%d",&c1,&c2);
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&w[i]);
        sum+=w[i];
    }
    for(int i=1;i<=n;i+++){
        for(int j=c1;j>=w[i];j--){
            dp[j]=max(dp[j],dp[j-w[j]]+w[j]);
        }
    }
    if(sum-dp[c1]>c2){
        cout<<"NO"<<endl;
    }
    else cout<<"YES"<<endl;
}
int main(){
    run();
    return 0;
}
