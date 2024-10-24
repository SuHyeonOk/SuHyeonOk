#include <iostream>
#include <string>
using namespace std;

class Queue 
{
private:
    int* arr;
    int capacity;
    int front, rear;
    int size;

public:
    Queue(int n) 
    {
        capacity = n + 1;  // 배열 크기를 하나 더 크게 해서 원형 큐의 조건을 만족시킴
        arr = new int[capacity];
        front = 0;
        rear = 0;
        size = 0;
    }

    ~Queue() 
    {
        delete[] arr;
    }

    void push(int x) 
    {
        if ((rear + 1) % capacity == front) 
        {
            return; // 큐가 가득 찬 경우
        }
        arr[rear] = x;
        rear = (rear + 1) % capacity;
        size++;
    }

    int pop() 
    {
        if (true == empty()) 
        {
            return -1;
        }
        int result = arr[front];
        front = (front + 1) % capacity;
        size--;
        return result;
    }

    int getSize() 
    {
        return size;
    }

    bool empty() 
    {
        return front == rear;
    }

    int getFront() 
    {
        if (true == empty()) 
        {
            return -1;
        }
        return arr[front];
    }

    int getBack() 
    {
        if (true == empty()) 
        {
            return -1;
        }
        return arr[(rear - 1 + capacity) % capacity];
    }
};

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N = 0;
    cin >> N;

    Queue q(N);

    while (N--) 
    {
        string Command;
        cin >> Command;

        if (Command == "push")
        {
            int x;
            cin >> x;
            q.push(x);
        }
        else if (Command == "pop")
        {
            cout << q.pop() << '\n';
        }
        else if (Command == "size") 
        {
            cout << q.getSize() << '\n';
        }
        else if (Command == "empty")
        {
            cout << q.empty() << '\n';
        }
        else if (Command == "front") 
        {
            cout << q.getFront() << '\n';
        }
        else if (Command == "back") 
        {
            cout << q.getBack() << '\n';
        }
    }

    return 0;
}