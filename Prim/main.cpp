#include <bits/stdc++.h>
#include <cstdio>

using namespace std;

class TRI {
public:
    int a,b,w; // a와 b를 연결, weight a쪽에서 넣음
};

class PQ{
public:
    int n;
    TRI Arr[1000];
    PQ();
    TRI Delete();
    void Insert(TRI x);
    int isEmpty();
};
PQ::PQ(){
    n = 0;

}
int PQ::isEmpty(){
    return n == 0;
}

void PQ::Insert(TRI x)
{
    int i,tmp;
    Arr[n+1] = x;
    i = n+1;
    n = n+1;
    while(i>1 && Arr[i].w < Arr[i/2].w){
        swap(Arr[i], Arr[i/2]);
        i = i/2;
    }
}

TRI PQ::Delete()
{
    TRI ret = Arr[1];
    int i,j;
    if(n==1) {n=0; return ret;}
    Arr[1] = Arr[n];
    i = 1; n = n-1;
    while(1){
        if(i*2 > n){
            break;
        }
        else if(i*2+1 > n){ // Left Child Only
            if(Arr[i*2].w < Arr[i].w){
                    swap(Arr[i*2], Arr[i]);
                    i = i*2;
            }
            else{
                break;
            }
        }else { // Left and Right Child exists
            if(Arr[i].w > Arr[i*2].w && Arr[i].w >Arr[i*2+1].w){
                if(Arr[i*2].w <Arr[i*2+1].w)
                    j = i*2;
                else
                    j = i*2+1;
                swap(Arr[i],Arr[j]);
                i=j;
            }
            else if(Arr[i].w > Arr[i*2].w && Arr[i].w <= Arr[i*2+1].w){
                j = i*2;
                swap(Arr[i],Arr[j]);
                i=j;
            }
            else if(Arr[i].w <= Arr[i*2].w && Arr[i].w > Arr[i*2+1].w){
                j = i*2+1;
                swap(Arr[i],Arr[j]);
                i=j;
            }
            else{
                break;
            }
        }
    }
    return ret;
}

PQ Q;
int n,m;
vector<pair<int,int>> Edges[1000];
int M[1000];
int main(){
    int c,i,a,b,w;
    TRI x, y;
    scanf("%d %d", &n,&m);
    for(i = 0; i<m; i++){
        scanf("%d %d %d", &a, &b,&w);
        Edges[a].push_back(make_pair(b,w));
        Edges[b].push_back(make_pair(a,w));
    }
    c = 1; M[c] = 1;
    for(i = 0; i<Edges[c].size(); i++){
        x.a = c; x.b = Edges[c][i].first;
        x.w = Edges[c][i].second;
        Q.Insert(x);
    }
    while(Q.isEmpty()==0){
        y = Q.Delete();
        if(M[y.a] == 1 &&M[y.b]==1){
            continue;
        }
        else {
           printf("Edge from Node %d to Node %d of Weight %d Selected.\n", y.a, y.b, y.w);
           c = y.b; M[c] = 1;
           for(i = 0; i<Edges[c].size(); i++){
                x.a = c; x.b = Edges[c][i].first; x.w = Edges[c][i].second;
                Q.Insert(x);
            }

        }
    }
    return 0;
}
/*
3 7
1 2 1
2 3 4
1 3 2
1 2 7
4 5 2
4 5 1
4 5 3

3 3
1 2 1
2 3 4
1 3 2

5 10
1 2 10
2 3 1
1 5 6
1 4 5
2 4 4
2 4 3
4 5 2
3 4 9
3 5 4
5 3 6






*/
