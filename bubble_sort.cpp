#include<iostream>
using namespace std;

int main(){
int n,i,j;
cout<<"Enter The NUmber OF N"<<endl;
cin>>n;
 int arr[n];
 cout<<"Enter The Element of The Array\n"<<endl;
 for(i=0;i<n;i++){
    cout<<" "<<i+1<<"."<<"element is :"<<endl;
    cin>>arr[i];
 }
 cout<<"The ARRAY IS :"<<endl;
 for(i=0;i<n;i++){
 cout<<'\t'<<arr[i];
 }
 //taking Bubble SOrt For Sorting 
for(i=0;i<n-1;i++){
    for(j=0;j<n-i-1;j++){
        if(arr[j]>arr[j+1]){
            swap(arr[j],arr[j+1]);
        }
    }
}
//after Sort Using Bbble Sort
cout<<endl<<"After Using bubblr Sort"<<endl;
 for(i=0;i<n;i++){
 cout<<'\t'<<arr[i];
 }
    return 0;
}
