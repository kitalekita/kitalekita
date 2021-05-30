#include<bits/stdc++.h>
using namespace std;
#define debug(i) printf("# %d\n",i)
int read(){
    int a;scanf("%d",&a);return a;
}

char x[1000009];
int main(){
    int t;while(scanf("%d",&t)!=EOF)
    while(t--){
        int n;scanf("%d%s",&n,x);
        int co[30];
        memset(co,0,sizeof(co));
        int len=strlen(x);
        for(int i=0;i<len;i++){
            co[x[i]-'a']++;
        }
        priority_queue<int,vector<int>,greater<int> >Q;
        for(int i=0;i<30;i++){
            if(co[i])Q.push(co[i]);
        }
        if(Q.size()==1){
            if(Q.top()<=n)printf("yes\n");
            else printf("no\n");
            continue;
        }
        int ans=0;
        while(Q.size()>1){
            int sum=0;
            sum+=Q.top();Q.pop();
            sum+=Q.top();Q.pop();
            ans+=sum;Q.push(sum);
        }
        if(ans<=n)printf("yes\n");
        else printf("no\n");
    }
}


