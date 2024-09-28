class MyCircularQueue {
public:
    vector<int>que;
    int size,maxSize,front,rear;
    MyCircularQueue(int k) {
        vector<int>temp(k,0);
        que=temp;
        size=0,maxSize=k,front=0,rear=-1;
    }
    
    bool enQueue(int value) {
        if(isFull()) return false;
        rear=(rear+1+maxSize)%maxSize;
        que[rear]=value;
        size++;
        return true;
    }
    
    bool deQueue() {
        if(isEmpty()) return false;
        front=(front+1+maxSize)%maxSize;
        size--;
        return true;
    }
    
    int Front() {
        if(isEmpty()) return -1;
        return que[front];
    }
    
    int Rear() {
        if(isEmpty()) return -1;
        return que[rear];
    }
    
    bool isEmpty() {
        return size==0;
    }
    
    bool isFull() {
        return size==maxSize;
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