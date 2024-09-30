class CustomStack {
public:
    int size,top=0;
    vector<int>arr;
    CustomStack(int maxSize) {
        size=maxSize;
        vector<int>temp(size);
        arr=temp;
    }
    void push(int x) {
        if(top<0)
            top=0;
        if(top<size)
            arr[top++]=x;
    }
    int pop() {
        top--;
        if(top<0)
            return -1;
        return arr[top];
    }
    void increment(int k, int val) {
        int tempTop=max(0,min(top,k));
        while(tempTop--)
            arr[tempTop]+=val;
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */