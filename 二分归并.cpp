#include <cstdio>
#include <cstdlib>
using namespace std;
void Merge(int A[], int p, int q, int r)
{
	int *L, *R,x,y;
	x=q-p+1,y=r-q;
	L = (int*)malloc(sizeof(int)*x);
	R = (int*)malloc(sizeof(int)*y);
	int i ,j;
	for (i=0; i <x; i++)
		L[i] = A[i + p];
	for (j=0; j < y; j++)
		R[j] = A[j + q + 1];
	i = j = 0;
	int k = p;
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

int MergeSort(int A[],int p,int r)	// 递归分组函数
{
	if (p < r)
	{
		int q = (p + r) / 2;
		MergeSort(A,p, q);
		MergeSort(A,q + 1, r);
		Merge(A,p, q, r);// 调用Merge函数，合并两组数据
	}
}

int main()
{
    int A[10]={3,4,2,6,5,7,8,1,9,10};
    MergeSort(A,0,9);
    for(int i=0;i<10;i++)
    {
        printf("%d\n",A[i]);
    }
    return 0;
}

