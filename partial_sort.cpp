#include <bits/stdc++.h>
#define int long long
using namespace std;

int main() {
    int n, k;
    
    cout << "Enter number of elements: ";
    cin >> n;
    
    vector<int> v(n);
    
    cout << "Enter " << n << " elements: ";
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }
    
    cout << "How many elements to sort? ";
    cin >> k;
    
    cout << "\nOriginal: ";
    for(int x : v) cout << x << " ";
    cout << "\n";
    
    partial_sort(v.begin(), v.begin() + k, v.end());
    
    cout << "After partial_sort (first " << k << " elements): ";
    for(int x : v) cout << x << " ";
    cout << "\n";
    return 0;
}

/*
**Example run:**

Enter number of elements: 8
Enter 8 elements: 9 3 7 1 5 8 2 6
How many elements to sort? 4

Original: 9 3 7 1 5 8 2 6 
After partial_sort (first 4 elements): 1 2 3 5 9 8 7 6
*/