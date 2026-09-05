#include<bits/stdc++.h>
using namespace std;
void bucketSort(vector<int>&a){
    int n=a.size();
    int mn=*min_element(a.begin(),a.end());
    int mx=*max_element(a.begin(),a.end());
    int k=mx-mn+1;
    vector<int>b(k);
    for(int x:a)b[x-mn]++;
    int p=0;
    for(int i=0;i<k;i++)
        while(b[i]--)a[p++]=i+mn;
}
int main(){
    int n;
    cin>>n;
    vector<int>a(n);
    for(int&i:a)
    cin>>i;
    bucketSort(a);
    for(int i:a)
    cout<<i<<" ";
}