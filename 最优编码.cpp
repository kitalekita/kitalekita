#include<bits/stdc++.h>
using namespace std;


typedef struct{
    unsigned int weight;
    unsigned int parent,lchild,rchild; 
    char character; 
}HTNode,*HuffmanTree; 

typedef char **HuffmanCode;

void Select(HuffmanTree HT, int n, int &s1, int &s2){
    if(n<2) return;
   int w1=-1,w2=-1;
    for(int i=1;i<=n;i++){
        if(HT[i].parent==0){
            if(w1==-1||HT[i].weight<=w1){
                w1=HT[i].weight;
                s1=i;
            }
        }
    }
    for(int i=1;i<=n;i++){
        if(HT[i].parent==0&&i!=s1){
            if(w2==-1||HT[i].weight<=w2&&HT[i].weight>=w1){
                w2=HT[i].weight;
                s2=i;
            }
        }
    }
}
void HuffmanCoding(HuffmanTree &HT, HuffmanCode &HC, int *w, char *&character, int n){
    if(n<=1) return;
    int m=2*n-1;
    HT=(HuffmanTree)malloc((m+1)*sizeof(HTNode));
    HuffmanTree p;
    int i;
    for(p=HT+1,i=1;i<=n;++i,++p,++w,++character){
        *p={*w,0,0,0,*character}; 
    }
    for(;i<=m;++i,++p)
        *p={0,0,0,0,'\0'}; 
    for(i=n+1;i<=m;++i){
        int s1,s2;
        Select(HT,i-1,s1,s2);
        HT[s1].parent=i;HT[s2].parent=i;
        HT[i].lchild=s1;HT[i].rchild=s2;
        HT[i].weight=HT[s1].weight+HT[s2].weight;
    }
    HC=(HuffmanCode)malloc((n+1)*sizeof(char *)); 
    char *cd=(char *)malloc(n*sizeof(char)); 
    cd[n-1]='\0';
    for(i=1;i<=n;i++){ 
        int start=n-1; 
        int c,f;
        for(c=i,f=HT[i].parent;f!=0;c=f,f=HT[f].parent){ 
            if(HT[f].lchild==c) cd[--start]='0';
            else cd[--start]='1';
        }
        HC[i]=(char *)malloc((n-start)*sizeof(char)); 
        strcpy(HC[i],&cd[start]);
    }
    free(cd);
}

int main(){
    cout<<"课件上的例子……"<<endl;
    char *character = "ETAOINSRHLDCU";
    int freq[] = {125,93,80,76,72,71,65,61,55,41,40,31,27};
    int n = 13;
    cout<<"13个字符及它们的频率分别是："<<endl;
    for(int i=0;i<13;i++)
        cout<<character[i]<<": "<<freq[i]<<endl;
    HuffmanTree HT;
    HuffmanCode HC;
    HuffmanCoding(HT,HC,freq,character,n);
    cout<<endl<<"Huffman编码："<<endl;
    for(int i=1;i<=n;i++){
        cout<<HT[i].character<<": "<<HC[i]<<endl;
    }
    return 0;
}

