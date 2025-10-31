#include <bits/stdc++.h>
#define in tlong long
using namespace std ;
int main() {
    int n1, n2;
    
    cout << "Enter size of first array: ";
    cin >> n1;
    
    vector<int> v1(n1);
    cout << "Enter " << n1 << " elements for first array: ";
    for(int i = 0; i < n1; i++) {
        cin >> v1[i];
    }
    
    cout << "\nEnter size of second array: ";
    cin >> n2;
    
    vector<int> v2(n2);
    cout << "Enter " << n2 << " elements for second array: ";
    for(int i = 0; i < n2; i++) {
        cin >> v2[i];
    }
    
    cout << "\nFirst array: ";
    for(int x : v1) cout << x << " ";
    cout << "\n";
    
    cout << "Second array: ";
    for(int x : v2) cout << x << " ";
    cout << "\n\n";
    
    bool result = lexicographical_compare(v1.begin(), v1.end(), v2.begin(), v2.end());
    
    if(result) {
        cout << "First array is lexicographically less than second array\n";
    } else {
        cout << "First array is NOT lexicographically less than second array\n";
    }
    return 0;
}

/*
**Example run 1:**

Enter size of first array: 4
Enter 4 elements for first array: 1 2 3 4

Enter size of second array: 4
Enter 4 elements for second array: 1 2 4 5

First array: 1 2 3 4 
Second array: 1 2 4 5 

First array is lexicographically less than second array


**Example run 2:**

Enter size of first array: 3
Enter 3 elements for first array: 5 6 7

Enter size of second array: 3
Enter 3 elements for second array: 1 2 3

First array: 5 6 7 
Second array: 1 2 3 

First array is NOT lexicographically less than second array
*/