#include <iostream>
using namespace std;

class dnode {
private:
    int elem;
    dnode* prev;
    dnode* next;
public:
    dnode() : prev(NULL), next(NULL) {}  // Initialize prev and next to NULL
    friend class DLL;
};

class DLL {
private:
    dnode* head;
    dnode* tail;
protected:
    void add(dnode* node, int num);
    void remove(dnode* node);
public:
    int size = 0;
    DLL();
    ~DLL();
    bool empty();
    int front() const;
    int back() const;
    void addfront(int);
    void addback(int);
    void add_at_loc(int, int);
    void removefront();
    void removeback();
    void display();
};

DLL::DLL() {
    head = new dnode();  // dummy head node
    tail = new dnode();  // dummy tail node
    head->next = tail;
    tail->prev = head;
}

DLL::~DLL() {
    while (!empty()) {
        removefront();
    }
    delete head;
    delete tail;
}

bool DLL::empty() {
    return head->next == tail;
}

int DLL::front() const {
    return head->next->elem;
}

int DLL::back() const {
    return tail->prev->elem;
}

void DLL::addfront(int num) {
    dnode* newNode = new dnode();
    newNode->elem = num;
    newNode->next = head->next;
    newNode->prev = head;
    head->next->prev = newNode;
    head->next = newNode;
    size++;
}

void DLL::addback(int num) {
    dnode* newNode = new dnode();
    newNode->elem = num;
    newNode->prev = tail->prev;
    newNode->next = tail;
    tail->prev->next = newNode;
    tail->prev = newNode;
    size++;
}

void DLL::removefront() {
    if (empty()) {
        cout << "List is empty" << endl;
    } else {
        dnode* t = head->next;
        head->next = t->next;
        t->next->prev = head;
        delete t;
        size--;
    }
}

void DLL::removeback() {
    if (empty()) {
        cout << "List is empty" << endl;
    } else {
        dnode* t = tail->prev;
        tail->prev = t->prev;
        t->prev->next = tail;
        delete t;
        size--;
    }
}

void DLL::add_at_loc(int loc, int num) {
    if (loc < 0 || loc > size) {
        cout << "Invalid location" << endl;
    } else {
        dnode* newNode = new dnode();
        newNode->elem = num;
        dnode* ptr = head;
        for (int i = 0; i < loc; i++) {
            ptr = ptr->next;
        }
        newNode->next = ptr->next;
        newNode->prev = ptr;
        ptr->next->prev = newNode;
        ptr->next = newNode;
        size++;
    }
}

void DLL::display() {
    dnode* ptr = head->next;
    if (size != 0) {
        while (ptr != tail) {
            cout << ptr->elem;
            if (ptr->next != tail) {
                cout << "<->";
            }
            ptr = ptr->next;
        }
        cout << endl;
    } else {
        cout << "List is empty." << endl;
    }
}

int main() {
    DLL dll;
    int choice, num, loc;

    while (true) {
        cout << endl << "Menu:" << endl;
        cout << "1. Add to front" << endl;
        cout << "2. Add to back" << endl;
        cout << "3. Add at location" << endl;
        cout << "4. Remove from front" << endl;
        cout << "5. Remove from back" << endl;
        cout << "6. Display list" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter a number to add to front: ";
                cin >> num;
                dll.addfront(num);
                break;
            case 2:
                cout << "Enter a number to add to back: ";
                cin >> num;
                dll.addback(num);
                break;
            case 3:
                cout << "Enter a location to add: ";
                cin >> loc;
                cout << "Enter a number to add: ";
                cin >> num;
                dll.add_at_loc(loc, num);
                break;
            case 4:
                dll.removefront();
                break;
            case 5:
                dll.removeback();
                break;
            case 6:
                dll.display();
                break;
            case 7:
                return 0;
            default:
                cout << "Invalid choice. Try again!" << endl;
        }
    }

    return 0;
}
