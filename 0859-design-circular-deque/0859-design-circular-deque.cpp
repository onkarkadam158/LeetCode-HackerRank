class MyCircularDeque {
public:
    vector<int>dq;
    int K,front,last,count;
    MyCircularDeque(int k) {
        vector<int>res(k,0);
        dq=res;   
        count=0;
        front=0,last=k-1,K=k;
    }
    
    bool insertFront(int value) {
        if(isFull()) return false;
        front=(front-1+K)%K;
        dq[front]=value;
        count++;
        return true;
    }
    
    bool insertLast(int value) {
        if(isFull()) return false;
        last=(last+1+K)%K;
        dq[last]=value;
        count++;
        return true;
    }
    
    bool deleteFront() {
        if(isEmpty()) return false;
        front=(front+1+K)%K;
        count--;
        return true;
    }
    
    bool deleteLast() {
        if(isEmpty()) return false;
        last=(last-1+K)%K;
        count--;
        return true;
    }
    
    int getFront() {
        if(!isEmpty()) return dq[front];
        return -1;
    }
    
    int getRear() {
        if(!isEmpty()) return dq[last];
        return -1;
    }
    
    bool isEmpty() {
        return count==0;
    }
    
    bool isFull() {
        return count==K;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */