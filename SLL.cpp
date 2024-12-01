#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node() { next = NULL; }
};

class SLL {
    Node* head;
public:
    SLL() { head = NULL; }
    void insertAtBeg(int);
    void insertAtEnd(int);
    void insertAtLoc(int, int);
    void deleteAtBeg();
    void deleteAtEnd();
    void deleteAtLoc(int);
    int searchElement(int); // Modified to return the position
    void concatenateSLL(SLL &list);
    void display() {
        Node* ptr = head;
        while (ptr != NULL) {
            cout << ptr->data << " -> ";
            ptr = ptr->next;
        }
        cout << "NULL" << endl;
    }
};

void SLL::insertAtBeg(int num) {
    Node* newNode = new Node();
    newNode->data = num;
    newNode->next = head;
    head = newNode;
}

void SLL::insertAtEnd(int num) {
    Node* newNode = new Node();
    newNode->data = num;
    
    if (head == NULL) {
        head = newNode;
    } else {
        Node* ptr = head;
        while (ptr->next != NULL) {
            ptr = ptr->next;
        }
        ptr->next = newNode;
    }
}

void SLL::insertAtLoc(int num, int loc) {
    if (loc < 1) {
        cout << "Invalid location." << endl;
        return;
    }
    Node* newNode = new Node();
    newNode->data = num;
    if (loc == 1) {
        insertAtBeg(num);
        return;
    }
    Node* ptr = head;
    for (int i = 1; i < loc - 1; i++) {
        if (ptr == NULL) {
            cout << "Location is out of bounds." << endl;
            return;
        }
        ptr = ptr->next;
    }
    newNode->next = ptr->next;
    ptr->next = newNode;
}

void SLL::deleteAtBeg() {
    if (head == NULL) {
        cout << "SLL is empty." << endl;
        return;
    }
    Node* ptr = head;
    cout << "Node to be deleted: " << ptr->data << endl;
    head = head->next;
    delete ptr;
}

void SLL::deleteAtEnd() {
    if (head == NULL) {
        cout << "SLL is empty." << endl;
        return;
    } else if (head->next == NULL) {
        cout << "Deleted node: " << head->data << endl;
        delete head;
        head = NULL;
    } else {
        Node* ptr1 = head;
        Node* ptr2;
        while (ptr1->next != NULL) {
            ptr2 = ptr1;
            ptr1 = ptr1->next;
        }
        cout << "Deleted node: " << ptr1->data << endl;
        ptr2->next = NULL;
        delete(ptr1);
    }
}

void SLL::deleteAtLoc(int loc) {
    if (head == NULL) {
        cout << "SLL is empty." << endl;
        return;
    }
    if (loc < 1) {
        cout << "Invalid location." << endl;
        return;
    }
    Node* ptr1 = head;
    Node* ptr2 = NULL;
    if (loc == 1) {
        deleteAtBeg();
        return;
    }
    for (int i = 1; i < loc; i++) {
        if (ptr1 == NULL) {
            cout << "Location is out of bounds." << endl;
            return;
        }
        ptr2 = ptr1;
        ptr1 = ptr1->next;
    }
    ptr2->next = ptr1->next;
    cout << "Deleted Node: " << ptr1->data << endl;
    delete(ptr1);
}

int SLL::searchElement(int value) {
    Node* temp = head;
    int position = 1;  // Position starts at 1 for the first node
    while (temp != NULL) {
        if (temp->data == value) {
            cout << "Element found at position: " << position << endl;
            return position;  // Return the position of the element
        }
        temp = temp->next;
        position++;
    }
    cout << "Element not found in the linked list." << endl;
    return -1;  // Return -1 if element is not found
}

void SLL::concatenateSLL(SLL& list) {
    if (head == NULL) {
        head = list.head;
        return;
    }
    Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = list.head;
    list.head = NULL;
}

int main() {
    SLL sll;
    int choice, num, loc;

    while (true) {
        cout << "\nSingly Linked List Menu:" << endl;
        cout << "1. Insert at beginning" << endl;
        cout << "2. Insert at end" << endl;
        cout << "3. Insert at location" << endl;
        cout << "4. Delete from beginning" << endl;
        cout << "5. Delete from end" << endl;
        cout << "6. Delete from location" << endl;
        cout << "7. Search an element" << endl;
        cout << "8. Concatenate another list" << endl;
        cout << "9. Display list" << endl;
        cout << "10. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the number to insert at the beginning: ";
                cin >> num;
                sll.insertAtBeg(num);
                break;
            case 2:
                cout << "Enter the number to insert at the end: ";
                cin >> num;
                sll.insertAtEnd(num);
                break;
            case 3:
                cout << "Enter the number to insert: ";
                cin >> num;
                cout << "Enter the location to insert: ";
                cin >> loc;
                sll.insertAtLoc(num, loc);
                break;
            case 4:
                sll.deleteAtBeg();
                break;
            case 5:
                sll.deleteAtEnd();
                break;
            case 6:
                cout << "Enter the location to delete: ";
                cin >> loc;
                sll.deleteAtLoc(loc);
                break;
            case 7:
                cout << "Enter the element you want to search: ";
                cin >> num;
                sll.searchElement(num);
                break;
            case 8:
                {
                    SLL list2;
                    cout << "Enter size of list2: ";
                    int t;
                    cin >> t;
                    while (t--) {
                        cout << "Enter the number to insert: ";
                        cin >> num;
                        list2.insertAtEnd(num);
                    }
                    sll.concatenateSLL(list2);
                }
                break;
            case 9:
                cout << "Linked List: ";
                sll.display();
                break;
            case 10:
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}


