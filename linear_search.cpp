#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n,target;cin>>n>>target;
    bool found=false;
    int arr[n];
    for(int i=0;i<n;i++) {
        cin>>arr[i];
        if(arr[i]==target){
            cout<<"Found at position"<< i+1;
            found=true;
            break;
        }
    }
    if(!found) cout<<"Not found in the whole array";
    
}
int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}