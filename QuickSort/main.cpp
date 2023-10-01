#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int c = 0;
int sort(int a[], int n){
    c++;
    if(n==0)return 0;
    if(n==2){
        if(a[0]>a[1]) swap(a[0],a[1]);
        return 0;
    }
    int p = a[0];
    int i = 1; int j = n-1;
    while(i<j){
        while(a[i]<p) i++;
        while(a[j]>p) j--;
        if(i<j) swap(a[i],a[j]);
    }
    swap(a[0],a[j]);
    sort(a,j);sort(a+j+1,n-j-1);
    return 0;
}

int main(){
    // 1 3 2 4 7 9 12 45 5 6
    int a[10] = {4,5,2,1,7,9,12,45,3,6};
    sort(a,10);
    for(int i = 0; i<10; i++){
        cout<<a[i]<<" ";
    }
    cout<<"\n"<<c<<endl;
    return 0;
}

