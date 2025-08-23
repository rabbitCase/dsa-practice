#include <iostream>
#include <stack>
using namespace std;
class MyQueue {
public:
    stack<int> enq;
    stack<int> deq;

    MyQueue() {
        
    }
    
    void push(int x) {
        enq.push(x);
    }
    
    int pop() {
        peek();
        int top = deq.top();
        deq.pop();
        return top;
    }
    
    int peek() {
        if(deq.empty()){
            while(!enq.empty()){
                deq.push(enq.top());
                enq.pop();
            }
        }
        return deq.top();
    }
    
    bool empty() {
        return (enq.empty() && deq.empty());
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */