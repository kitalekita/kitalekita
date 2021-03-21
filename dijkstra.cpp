#include<cstdio>
#include<cstring>
#include<iostream>
#include<queue>
#include<stack>
#include<algorithm>
#include<vector>
#include<cmath>
#include<map>
#include<string>
#include<set>
#define Case int t;scanf("%d",&t);while(t--)
#define pi acos(-1)
#define eps 1e-8
using namespace std;
typedef long long ll;
const int N = 1e6 + 10;
const int M = 1e5 + 10;
const int inf = 0x3f3f3f3f;
const ll mod = 1e9+7;
struct edge{
	int from,to,w;
	edge(int a,int b,int c){from=a;to=b;w=c;}
};
vector<edge>e[M];
struct node{
	int id,dist;
	node(int u,int v){id=u,dist=v;}
	bool operator<(const node &a)const{
		return dist>a.dist;
	}
};
int n,m;
int dis[M];
bool done[M];
void dijkstra(){
	int s=1;
	for(int i=1;i<=n;i++){
		dis[i]=inf;
		done[i]=0;
	}
	dis[s]=0;
	priority_queue<node>q;
	q.push(node(s,dis[s]));
	while(!q.empty()){
		node u=q.top();
		q.pop();
		if(done[u.id])continue;
		done[u.id]=1;
		for(int i=0;i<e[u.id].size();i++){
			edge y=e[u.id][i];
			if(done[y.to])continue;
			if(dis[y.to]>y.w+u.dist){
				dis[y.to]=y.w+u.dist;
				q.push(node(y.to,dis[y.to]));
			}
		}
	}
	printf("%d\n",dis[n]);
}
void run() {
	while(~scanf("%d%d",&n,&m)&&n&&m){
		for(int i=1;i<=n;i++)e[i].clear();
		for(int i=1;i<=m;i++){
			int u,v,w;
			scanf("%d%d%d",&u,&v,&w);
			e[u].push_back(edge(u,v,w));
		}
		dijkstra();
	}
}
int main() {
//	Case
		run();
	return 0;
}

