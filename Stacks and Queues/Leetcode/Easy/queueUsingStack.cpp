//Leetcode Easy 232
//We need two stack, one for enqueue, one for dequeue. When pushing, we just push to stack1. When we need to dequeue, we need the bottom element in stack1, so we start popping stack1 and store them in stack2 so the order is reversed. Finally we pop from stack2 for dequeue. Ensure stack2 is empty before reversing stack1 otherwise new elements will be added to stack2 which would be popped first instead of the already remaining elements in stack2 (which should have been popped first)
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