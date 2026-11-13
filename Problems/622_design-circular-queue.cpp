#include <vector>

class MyCircularQueue {
private:
        std::vector<int> vec;
        int head;
        int tail;
        int count ;
        int capacity;
public:
    MyCircularQueue(int k) : vec(k),head{0}, tail{0}, count{0},capacity{k}  
    {}
    
    bool enQueue(int value) {
        if(count == capacity){return false;}
        else{
            vec[tail] = value;
            tail = (tail + 1) % capacity;
            ++count;
            return true;
        }
    }
    
    bool deQueue() {
        if(count == 0){return false;}
        else{
            head = (head+1) % capacity;
            --count;
            return true;
        }
    }
    
    int Front() {
        if(count == 0){
            return -1;
        }
        return vec[head];
    }
    
    int Rear() {
        if(count == 0){
            return -1;
        }
        return vec[(tail-1 + capacity) % capacity];
    }
    
    bool isEmpty() {
        return (count == 0);
    }
    
    bool isFull() {
        return (count == capacity);
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */