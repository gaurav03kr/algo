#include <bits/stdc++.h>
using namespace std;

/**
 * @brief Implementation of a Circular Singly Linked List in C++
 *
 * @details
 * In a Circular Linked List, the last node points back to the head,
 * forming a circle. This structure allows continuous traversal.
 *
 * Operations:
 *  - Insert at end
 *  - Insert at beginning
 *  - Delete a node
 *  - Display the list
 *
 * Time Complexity:
 *  - Insertion: O(n) (can be made O(1) if we maintain a tail pointer)
 *  - Deletion:  O(n)
 *  - Traversal: O(n)
 */

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class CircularLinkedList {
private:
    Node* head;

public:
    CircularLinkedList() : head(nullptr) {}

    // Insert a node at the end
    void insertAtEnd(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
            head->next = head;  // Points to itself
            return;
        }

        Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
    }

    // Insert a node at the beginning
    void insertAtBeginning(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
            head->next = head;
            return;
        }

        Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }

        temp->next = newNode;
        newNode->next = head;
        head = newNode;
    }

    // Delete a node with given value
    void deleteNode(int val) {
        if (!head) {
            cout << "List is empty.\n";
            return;
        }

        Node* curr = head;
        Node* prev = nullptr;

        // Case 1: Deleting head node
        if (head->data == val) {
            Node* temp = head;
            while (temp->next != head)
                temp = temp->next;

            // If only one node in list
            if (head == head->next) {
                delete head;
                head = nullptr;
                return;
            }

            temp->next = head->next;
            head = head->next;
            delete curr;
            return;
        }

        // Case 2: Deleting non-head node
        do {
            prev = curr;
            curr = curr->next;
            if (curr->data == val) {
                prev->next = curr->next;
                delete curr;
                return;
            }
        } while (curr != head);

        cout << "Value " << val << " not found in list.\n";
    }

    // Display the list
    void display() {
        if (!head) {
            cout << "List is empty.\n";
            return;
        }

        Node* temp = head;
        cout << "Circular Linked List: ";
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << "\n";
    }

    // Destructor to free memory
    ~CircularLinkedList() {
        if (!head) return;

        Node* curr = head->next;
        while (curr != head) {
            Node* temp = curr;
            curr = curr->next;
            delete temp;
        }
        delete head;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    CircularLinkedList clist;
    int n;
    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        clist.insertAtEnd(val);
    }

    cout << "\nInitial ";
    clist.display();

    int addFront;
    cout << "Enter element to insert at beginning: ";
    cin >> addFront;
    clist.insertAtBeginning(addFront);
    clist.display();

    int delVal;
    cout << "Enter value to delete: ";
    cin >> delVal;
    clist.deleteNode(delVal);
    clist.display();

    return 0;
}

/*
---------------------------------------------------------------
SAMPLE INPUT
5
10 20 30 40 50
5
30

---------------------------------------------------------------
SAMPLE OUTPUT
Initial Circular Linked List: 10 20 30 40 50 
Circular Linked List: 5 10 20 30 40 50 
Circular Linked List: 5 10 20 40 50 

---------------------------------------------------------------
EXPLANATION
Input elements form: 10 → 20 → 30 → 40 → 50 → (back to 10)
After inserting 5 at beginning: 5 → 10 → 20 → 30 → 40 → 50 → (back to 5)
After deleting 30: 5 → 10 → 20 → 40 → 50 → (back to 5)
---------------------------------------------------------------
*/
