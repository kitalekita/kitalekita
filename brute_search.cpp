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
	int m;scanf("%d",&m);
	for(int i=1;i<=n;i++){
		if(m==a[i]){
			printf("%d\n",i);
			return 0;
		}
		
	}
	puts("Not Search");
} 
