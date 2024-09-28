class MyCircularDeque {
    vector<int>q;
    int front,back,len,cap;
public:
    MyCircularDeque(int k) {
        q=vector<int>(k,-1);
        front=0;
        back=0;
        len=0;      // Keeps track of the current number of elements
        cap=k;
    }
    
    bool insertFront(int value) {
        if(isFull())
            return false;
        if(front==0)
            front=cap-1;
        else
            front--;
        q[front]=value;
        len++;
        return true;
    }
    
    bool insertLast(int value) {
       if(isFull())
         return false;
        q[back]=value;
        if(back==cap-1)
            back=0;
        else    
            back++;
        len++;
        return true;
    }
    
    bool deleteFront() {
        if(isEmpty())
            return false;
        q[front]=-1;
        if(front==cap-1)
            front=0;
        else
            front++;
        len--;
        return true;
    }
    
    bool deleteLast() {
        if(isEmpty())
            return false;
        if(back==0)
            back=cap-1;
        else
            back--;
        q[back]=-1;
        len--;
        return true;
    }
    
    int getFront() {
        if(isEmpty())
            return -1;
        return q[front];
    }
    
    int getRear() {
        if(isEmpty())
            return -1;
        if(back==0)
            return q[cap-1];     // Wrap around to the last valid element
        else
            return q[back-1];
    }
    
    bool isEmpty() {
        return len==0;
    }
    
    bool isFull() {
        return len==cap;
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