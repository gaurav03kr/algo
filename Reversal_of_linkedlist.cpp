#include <bits/stdc++.h>
using namespace std;

/**
 * @brief Singly Linked List implementation with reversal function.
 *
 * @details
 * The reversal of a linked list can be done iteratively or recursively.
 * This implementation uses the **iterative approach** for clarity.
 *
 * Time Complexity:  O(n)
 * Space Complexity: O(1)
 */

struct Node {
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() : head(nullptr) {}

    // Insert node at the end
    void insert(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next)
            temp = temp->next;
        temp->next = newNode;
    }

    // Reverse the linked list iteratively
    void reverse() {
        Node* prev = nullptr;
        Node* curr = head;
        Node* next = nullptr;

        while (curr) {
            next = curr->next;   // Save next node
            curr->next = prev;   // Reverse the current node's link
            prev = curr;         // Move prev one step ahead
            curr = next;         // Move curr one step ahead
        }

        head = prev;  // New head after full reversal
    }

    // Display the linked list
    void display() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout <<endl;
    }
};

// ----------- DRIVER CODE -----------
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    LinkedList list;
    int n;
    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        list.insert(val);
    }

    cout << "\nOriginal Linked List: ";
    list.display();

    list.reverse();

    cout << "Reversed Linked List: ";
    list.display();

    return 0;
}

/*
---------------------------------------------------------------
SAMPLE INPUT
5
10 20 30 40 50

---------------------------------------------------------------
SAMPLE OUTPUT
Original Linked List: 10 20 30 40 50 
Reversed Linked List: 50 40 30 20 10 

---------------------------------------------------------------
EXPLANATION
Initial list: 10 → 20 → 30 → 40 → 50 → NULL
After reversal: 50 → 40 → 30 → 20 → 10 → NULL
---------------------------------------------------------------
*/
