
#include <bits/stdc++.h>

using namespace std;

#define MAXN 105

// ��Ʒ����
int w[MAXN];

// ���������
int c;

// ��ǰ���Ž�
int bestw = -1;

// �����¼����
bool res[MAXN];

// ���㵱ǰ��ѡ��Ʒ��s������
int sum(int pos,int n){
    int tmp = 0;
    for(int i = 1;i <= n;i++){
        if(res[i]){
            tmp += w[i];
        }
    }
    return tmp;
}

// Լ������
bool constrain(int pos,int n){
    return sum(pos,n) > c ? false : true;
}

// �޽纯��
bool bound(int pos,int n){
    //���㵱ǰû�м�����Ʒ��������
    int tmp = 0;
    for(int i = pos+1;i <= n;i++){
        tmp += w[i];
    }
    
    return sum(pos,n) + tmp > bestw ? true : false;
}

// �ݹ鷨������װ������
void LoadingTraceback(int pos,int n){
    // ���н�
    if(pos>n){
        bestw = sum(n, n);
    }else{
        // ���ӣ�ѡ
        res[pos] = 1;
        // ��������Լ�����Ǿͼ���
        if(constrain(pos,n)){
            LoadingTraceback(pos+1, n);
            // ע�⣬����֮��Ҫ��Ϊ��ѡ
            //res[pos] = 0;
        }
        
        // �Һ��ӣ���ѡ
        res[pos] = 0;
        // ���������޽磬�Ǿͼ���
        if(bound(pos,n)){
            LoadingTraceback(pos+1, n);
        }
    }
}

// ������������װ������
void LoadingIterate(int pos,int n){
    int f[n+1];
    for(int i = 0;i <= n;i++)
        f[i] = 1;
    while(pos > 0){
        for(;f[pos] <= 2;f[pos]++){
            // ������
            if(f[pos] == 1){
                res[pos] = 1;
                if(constrain(pos, n)){
                    // ���н�
                    if(pos == n){
                        bestw = sum(n, n);
                    }else{
                        pos++;
                        f[pos] = 0;
                    }
                }
            }else{// ������
                res[pos] = 0;
                if(bound(pos, n)){
                    // ���н�
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
    // ��ʼ����Ʒ����
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

