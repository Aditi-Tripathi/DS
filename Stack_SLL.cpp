// Stack Using SLL
#include <iostream>
using namespace std;

class Node {
    public: 
        int data;
        Node* next;
        Node() { next = NULL; }
        Node(int value) { data = value; next = NULL; }
};

class SLL {
    Node* head;
    
    public:
        SLL() { head = NULL; }

        bool isEmpty() {
            return head == NULL;
        }

        void push(int value) {
            Node* newNode = new Node(value);
            newNode->next = head;
            head = newNode;
            cout << "Pushed: " << value << "\n";
        }

        void pop() {
            if (isEmpty()) {
                cout << "Stack is empty. Cannot pop.\n";
                return;
            }
            Node* temp = head;
            cout << "Popped: " << head->data << "\n";
            head = head->next;
            delete temp;
        }

        void display() {
            if (isEmpty()) {
                cout << "Stack is empty.\n";
                return;
            }
            cout << "Stack elements: ";
            Node* current = head;
            while (current != NULL) {
                cout << current->data << " ";
                current = current->next;
            }
            cout << "\n";
        }
};

int main() {
    SLL stack;
    int choice, value;

    do {
        cout << "\nStack Menu:\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Display\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter a value to push: ";
                cin >> value;
                stack.push(value);
                break;
            case 2:
                stack.pop();
                break;
            case 3:
                stack.display();
                break;
            case 0:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 0);

    return 0;
}