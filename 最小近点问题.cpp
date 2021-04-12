#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int maxn=1e5+10;
struct Point{
	double x,y;
}p[maxn],p1[maxn];
bool cmpx(Point a,Point b){
	return a.x<b.x;
}
bool cmpy(Point a,Point b){
	return a.y<b.y;
}
double get_min(double a,double b){return a<b?a:b;}
double dist(Point a,Point b){
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
ld solve(ll l,ll r){
	if(l+1==r){
		return dist(p[l],p[r]);
	}
	if(l+2==r){
		return get_min(get_min(dist(p[l],p[l+1]),dist(p[l+1],p[r])),dist(p[l],p[r]));
	}
	ll mid=l+r>>1;
	double ans=get_min(solve(l,mid),solve(mid+1,r));
	int cnt=0;
	for(int i=l;i<=r;i++){
		if(p[i].x>=p[mid].x-ans&& p[i].x<=p[mid].x+ans){
			p1[++cnt]=p[i];
		}
	}
	sort(p1+1,p1+1+cnt,cmpy);
	for(int i=1;i<=cnt;i++){
		for(int j=i+1;j<=cnt;j++){
			if(p1[j].y-p1[i].y>ans)break;
			ans=get_min(ans,dist(p1[i],p1[j]));
		}
	}
	return ans;
}
void run(){
	int n;
	while(~scanf("%d",&n)&& n){
		for(int i=1;i<=n;i++){
			scanf("%lf%lf",&p[i].x,&p[i].y);
		}
		sort(p+1,p+1+n,cmpx);
		double min1=solve(1,n);
		printf("%.2lf\n",min1/2.0);
	}
	
	
}
int main(){
	run();
	return 0;
} 
