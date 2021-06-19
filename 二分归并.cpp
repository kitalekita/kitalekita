#include<bits/stdc++.h>
using namespace std;
int A[10005];
void Merge(int A[], int l, int mid, int r)
{
	int *L, *R,x,y;
	x=mid-l+1,y=r-mid;
	L = (int*)malloc(sizeof(int)*x);
	R = (int*)malloc(sizeof(int)*y);
	int i ,j;
	for (i=0; i <x; i++)
		L[i] = A[i + l];
	for (j=0; j < y; j++)
		R[j] = A[j + mid + 1];
	i = j = 0;
	int k = l;
	while (i <x && j <y)
	{
		if (L[i] <= R[j])
			A[k++] = L[i++];
		else
			A[k++] = R[j++];
	}
	while (i < x)
		A[k++] = L[i++];
	while (j <y)
		A[k++] = R[j++];
	free(L);
	free(R);
}

int MergeSort(int A[],int l,int r)	// 递归分组函数
{
	if (l < r)
	{
		int mid = (l + r) / 2;
		MergeSort(A,l, mid);
		MergeSort(A,mid + 1, r);
		Merge(A,l, mid, r);// 调用Merge函数，合并两组数据
	}
}

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
    	scanf("%d",&A[i]);
	}
    MergeSort(A,0,n-1);
    for(int i=0;i<n;i++)
    {
        printf("%d ",A[i]);
    }
    puts("");
    return 0;
}

