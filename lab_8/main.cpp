#include <iostream>


using namespace std;


template <typename STK>
class Stack
{
private:
    STK* stack;
    int size = 0;
    int i = 0;
public:
    Stack(int s)
    {
        if (s < 1)
        {
            throw bad_alloc();
        }
        size = s;
        STK* stack = new STK[size];

    }
    ~Stack()
    {
        delete[] stack;
    }
    int get_size()
    {
        return size;
    }
    bool is_empty()
    {
        if (i == 0)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    STK push(const STK& elem)
    {
        if (size == i)
        {
            throw overflow_error("Stack is full");
        }
        return stack[i++] = elem;
    }
    STK top()
    {
        if (is_empty())
        {
            throw logic_error("Stack is empty");
        }
        return stack[i-1];
    }
    STK pop()
    {
        if (is_empty())
        {
            throw out_of_range("Stack is empty");
        }
        return stack[--i];
    }
};


int main(int argc, char** argv) {
    /*try
    {
        Stack<int> steck= -1;
    }
    catch (const bad_alloc& e)
    {
        cerr << e.what() << endl;
    }*/
    Stack<int> steck = 5;
    cout << steck.push(1) << endl;
    cout << steck.push(2) << endl;
    cout << steck.push(3) << endl;
    cout << steck.push(4) << endl;
    cout << steck.push(5) << endl;
    try
    {
        cout << steck.push(6) << endl;
    }
    catch (const overflow_error& e)
    {
        cerr << e.what() << endl;
    }
    cout << steck.top() << endl;
    cout << steck.pop() << endl;
    cout << steck.pop() << endl;
    cout << steck.pop() << endl;
    cout << steck.pop() << endl;
    cout << steck.pop() << endl;
    try
    {
        cout << steck.pop() << endl;
    }
    catch (const out_of_range& e)
    {
        cerr << e.what() << endl;
    }
    try
    {
        cout << steck.top() << endl;
    }
    catch (const logic_error& e)
    {
        cerr << e.what() << endl;
    }

    return 0;
}