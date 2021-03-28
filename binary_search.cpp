#include<bits/stdc++.h>
using namespace std;
const int maxn=1e4+10;
int a[maxn];
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+1+n);
	int l=1,r=n;
	int m;
	scanf("%d",&m);
	while(l<=r){
		int mid=l+r>>1;
		if(a[mid]<m){
			l=mid+1;
		}
		else r=mid-1;
	}
	if(a[l]!=m){
		puts("Not Search");
	}
	else {
		printf("%d\n",l);
	}
} 
