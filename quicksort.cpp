#include<bits/stdc++.h>
using namespace std;
int partition(int arr[],int p,int r)
{
    int x=arr[r];
    int i=p-1;
    for(int j=p;j<=r-1;j++)
    {
       if(arr[j]<=x)
       {
        i=i+1;
       swap( arr[i],arr[j]);
       }
    }
    i=i+1;
    swap(arr[i],arr[r]);
    return i;
}
void quicksort(int arr[],int p,int r)
{
    int q;
    if(p<r)
    {
        q=partition(arr,p,r);
        quicksort(arr,p,q-1);
        quicksort(arr,q+1,r);
    }
}
int main()
{
    
    int n;
    cout<<"Enter the size of the array : "<<endl;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    quicksort(a,0,n-1);
    cout<<"The sorted array is : "<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    
 return 0;
}
