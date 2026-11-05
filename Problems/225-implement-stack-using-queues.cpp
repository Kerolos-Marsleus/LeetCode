#include <queue>
#include <utility>

class MyStack {
    private:
        std::queue<int> q1;
        std::queue<int> q2;
        int top_elem = 0;
public:
    void push(int x) {
        q1.push(x);
        top_elem = x;
    }
    
    int pop() {
        while(q1.size() > 1){
            q2.push(q1.front());
            top_elem = q1.front();
            q1.pop();
            
        }
        int val = q1.front();
        q1.pop();
        std::swap(q1,q2);
        return val;
    }
    
    int top() const {
        return top_elem;
    }
    
    bool empty() const {
        return q1.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */