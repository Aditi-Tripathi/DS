#include <iostream>
using namespace std;

class cnode {
private:
    int data;
    cnode* next;

public:
    cnode() {
        next = NULL;
    }

    friend class CLL;
};

class CLL {
private:
    cnode* cursor;

public:
    CLL();
    ~CLL();
    bool empty() const;
    int front() const;
    int back() const;
    void advance();
    void add(const int);
    void remove();
    int search(int);
};

CLL::CLL() {
    cursor = NULL;
}

CLL::~CLL() {
    while (!empty()) {
        remove();
    }
}

bool CLL::empty() const {
    return cursor == NULL;
}

int CLL::front() const {
    return cursor->next->data;
}

int CLL::back() const {
    return cursor->data;
}

void CLL::advance() {
    cursor = cursor->next;
}

void CLL::add(const int x) {
    cnode* newCnode = new cnode();
    newCnode->data = x;
    if (cursor == NULL) {
        newCnode->next = newCnode;
        cursor = newCnode;
    } else {
        newCnode->next = cursor->next;
        cursor->next = newCnode;
        cursor = newCnode; // Move the cursor to the newly added node
    }
}

void CLL::remove() {
    if (cursor == NULL) {
        cout << "The list is empty!" << endl;
        return;
    }
    cnode* ptr = cursor->next;
    cout << "Deleted Node: " << ptr->data << endl;
    if (cursor->next == cursor) {
        delete ptr;
        cursor = NULL;
    } else {
        cursor->next = ptr->next;
        delete ptr;
    }
}

int CLL::search(int loc) {
    if (cursor == NULL) {
        cout << "The list is empty." << endl;
        return -1; // Element not found
    }
    
    cnode* ptr = cursor->next;
    int index = 0;

    // Traverse the list starting from the first node after cursor
    do {
        if (ptr->data == loc) {
            cout << "Element " << loc << " found at position " << index << endl;
            return index;
        }
        ptr = ptr->next;
        index++;
    } while (ptr != cursor->next); // Stop when we complete a full circle

    cout << "Element " << loc << " not found in the list." << endl;
    return -1; // Element not found
}

int main() {
    CLL cll;
    int choice;
    int num;
    int loc;

    while (true) {
        cout << "1. Add Node\n2. Remove Node\n3. Check if empty\n";
        cout << "4. Check front\n5. Check back\n6. Advance\n7. Search\n";
        cout << "8. Exit.\n";
        cout << "Enter your choice: "; cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter the Node to be added: ";
            cin >> num;
            cll.add(num);
            break;
        case 2:
            cll.remove();
            break;
        case 3:
            if (cll.empty()) {
                cout << "The list is empty.\n";
            } else {
                cout << "The list is not empty.\n";
            }
            break;
        case 4:
            if (!cll.empty()) {
                cout << "Front of the list: " << cll.front() << "\n";
            } else {
                cout << "The list is empty.\n";
            }
            break;
        case 5:
            if (!cll.empty()) {
                cout << "Back of the list: " << cll.back() << endl;
            } else {
                cout << "The list is empty.\n";
            }
            break;
        case 6:
            if (!cll.empty()) {
                cll.advance();
                cout << "Cursor advanced.\n";
            } else {
                cout << "The list is empty.\n";
            }
            break;
        case 7:
            cout << "Enter the Node to be searched: ";
            cin >> loc;
            cll.search(loc);
            break;
        case 8:
            return 0;
        }
    }

    return 0;
}