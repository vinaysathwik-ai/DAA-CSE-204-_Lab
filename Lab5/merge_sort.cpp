#include<bits/stdc++.h>
using namespace std;
void merge(vector<int>&a,int l,int m,int r){
    vector<int>x;
    int i=l,j=m+1;
    while(i<=m&&j<=r){
        if(a[i]<=a[j])x.push_back(a[i++]);
        else x.push_back(a[j++]);
    }
    while(i<=m)x.push_back(a[i++]);
    while(j<=r)x.push_back(a[j++]);
    for(int k=0;k<x.size();k++)a[l+k]=x[k];
}
void mergeSort(vector<int>&a,int l,int r){
    if(l>=r)return;
    int m=l+(r-l)/2;
    mergeSort(a,l,m);
    mergeSort(a,m+1,r);
    merge(a,l,m,r);
}
int main(){
    int n;
    cout<<"Enter no of elements"<<endl;
    cin>>n;
    vector<int>a(n);
    cout<<"Enter the elements of the array:"<<endl;
    for(int&i:a)
    cin>>i;
    mergeSort(a,0,n-1);
    cout<<"Merge Sort:"<<endl;
    for(int i:a)
    cout<<i<<" ";
}