#include<iostream>
using namespace std;
#define N 7
//pΪ��������p[0],p[1]�����һ������p[1],p[2]����ڶ�������lengthΪp�ĳ���
//�����������������length=7��mΪ�洢���Ž���Ķ�ά����sΪ�洢ѡ�����Ž��·�ߵ�
//��ά����
void MatrixChainOrder(int *p,int (*m)[N],int (*s)[N],int length)
{
    int n=length-1;
    int l,i,j,k,q=0;
    //m[i][i]ֻ��һ������������˴���Ϊ0����m[i][i]=0;
    for(i=1;i<length;i++)
    {
        m[i][i]=0;
    }
    //l��ʾ�������ĳ���
    // l=2ʱ������ m[i,i+1],i=1,2,...,n-1 (����l=2��������С����)
    for(l=2;l<=n;l++)
    {
        for(i=1;i<=n-l+1;i++)
        {
            j=i+l-1; //��iΪ��ʼλ�ã�jΪ����Ϊl������ĩλ��
            m[i][j]=0x7fffffff;
            //k��i��j-1,��kΪλ�û���
            for(k=i;k<=j-1;k++)
            {
                q=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
                if(q<m[i][j])
                {
                    m[i][j]=q;
                    s[i][j]=k;
                }
            }
        }
    }
    cout << m[1][N-1] << endl;
}
void PrintAnswer(int(*s)[N],int i,int j)
{
    if(i==j)
    {
        cout<<"A"<<i;
    }
    else
    {
        cout<<"(";
        PrintAnswer(s,i,s[i][j]);
        PrintAnswer(s,s[i][j]+1,j);
        cout<<")";
    }
}
int main()
{
    int p[N]={20,35,15,5,10,20,25};
    int m[N][N],s[N][N];
    MatrixChainOrder(p,m,s,N);
    PrintAnswer(s,1,N-1);
    return 0;
}
