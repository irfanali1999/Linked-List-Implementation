C++ Code (Linked List Implementation for Sparse Matrix)
#include <iostream>
using namespace std;
// Node structure for linked list representation
struct Node {
    int row, col, value;
    Node* next;
};
// Function to create a new node
Node* createNode(int row, int col, int value) {
    Node* newNode = new Node;
    newNode->row = row;
    newNode->col = col;
    newNode->value = value;
    newNode->next = nullptr;
    return newNode;
}
// Function to insert a node at the end of the list
void insertNode(Node*& head, int row, int col, int value) {
    Node* newNode = createNode(row, col, value);
    if (head == nullptr) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}
// Function to display the sparse matrix in linked list form
void displayList(Node* head) {
    cout << "\nSparse Matrix Representation using Linked List (Row, Col, Value):\n";
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->row << " " << temp->col << " " << temp->value << endl;
        temp = temp->next;
    }
}
int main() {
    int m, n;
    cout << "Enter number of rows: ";
    cin >> m;
    cout << "Enter number of columns: ";
    cin >> n;
    int matrix[m][n];
    cout << "Enter the matrix elements (" << m * n << " values):\n";
    // Input matrix
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }
    Node* head = nullptr;
    // Insert non-zero elements into linked list
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] != 0) {
                insertNode(head, i, j, matrix[i][j]);
            }
        }
    }
    // Display linked list representation
    displayList(head);
    return 0;
}
