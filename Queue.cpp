// Queue
#include <iostream>
using namespace std;

#define MAX_SIZE 100

class Queue {
    int front, rear, arr[MAX_SIZE];

public:
    Queue() : front(-1), rear(-1) {}

    bool isEmpty() {
        return (front == -1 && rear == -1);
    }

    bool isFull() {
        return (rear == MAX_SIZE - 1);
    }

    void enqueue(int value) 
    {
        if (isFull()) 
        {
            cout << "Queue is full. Cannot enqueue " << value << ".\n";
            return;
        }
        if (isEmpty()) 
        {
            front = rear = 0;
        } 
        else 
        {
            rear++;
        }
        arr[rear] = value;
        cout << "Enqueued: " << value << "\n";
    }

    void dequeue() {
        if (isEmpty()) 
        {
            cout << "Queue is empty. Cannot dequeue.\n";
            return;
        }
        cout << "Dequeued: " << arr[front] << "\n";
        if (front == rear) 
        { 
            front = rear = -1;
        } 
        else 
        {
            front++;
        }
    }

    void display() 
    {
        if (isEmpty()) 
        {
            cout << "Queue is empty.\n";
            return;
        }
        cout << "Queue elements: ";
        for (int i = front; i <= rear; i++) 
        {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
};

int main() 
{
    Queue q;
    int choice, value;

    do {
        cout << "\nQueue Menu:\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Display Queue\n";
        cout << "4. Check if Queue is Empty\n";
        cout << "5. Check if Queue is Full\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) 
        {
            case 1:
                cout << "Enter a value to enqueue: ";
                cin >> value;
                q.enqueue(value);
                break;
            case 2:
                q.dequeue();
                break;
            case 3:
                q.display();
                break;
            case 4:
                cout << (q.isEmpty() ? "Queue is empty.\n" : "Queue is not empty.\n");
                break;
            case 5:
                cout << (q.isFull() ? "Queue is full.\n" : "Queue is not full.\n");
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