#include<bits/stdc++.h>
using namespace std;
int partition(vector<int>&a,int l,int r){
    int p=a[r],i=l-1;
    for(int j=l;j<r;j++){
        if(a[j]<p){
            i++;
            swap(a[i],a[j]);
        }
    }
    swap(a[i+1],a[r]);
    return i+1;
}
void quickSort(vector<int>&a,int l,int r){
    if(l>=r)return;
    int p=partition(a,l,r);
    quickSort(a,l,p-1);
    quickSort(a,p+1,r);
}
int main(){
    int n;
    cin>>n;
    vector<int>a(n);
    for(int&i:a)
    cin>>i;
    quickSort(a,0,n-1);
    for(int i:a)
    cout<<i<<" ";
}