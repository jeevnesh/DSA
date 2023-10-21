class MyCircularQueue {
    int* arr;
    int qFront;
    int qRear;
    int n;
public:
    MyCircularQueue(int k) {
        n = k;
        arr = new int[n];
        qFront = qRear = -1;
    }
    
    bool enQueue(int value) {
        //check if queue is full
        if(isFull())
        {
            return false;
        }
        // insert into first place
        if(qFront == -1 && qRear == -1)
        {
            qFront = qRear = 0;
        }
        else if(qRear == n-1 && qFront != 0)    // insert into last place
        {
            qRear = 0;
        }
        else  //insert at any position
        {
            qRear++;
        }
        arr[qRear] = value;
        return true;
    }
    
    bool deQueue() {
        //check if queue if empty
        if(isEmpty())
        {
            return false;
        }
        else if(qFront == qRear)  // if queue is empty
        {
            qFront = qRear = -1;
        }
        else if(qFront == n-1)  // remove from last position
        {
            arr[qFront] = -1;
            qFront = 0;
        }
        else  // remove from any position
        {
            arr[qFront] = -1;
            qFront++;
        }
        return true;
    }
    
    int Front() {
        if(isEmpty())
        {
            return -1;
        }
        return arr[qFront];
    }
    
    int Rear() {
        if(isEmpty())
        {
            return -1;
        }
        return arr[qRear];
    }
    
    bool isEmpty() {
        if(qFront == -1 && qRear == -1)
        {
            return true;
        }
        return false;
    }
    
    bool isFull() {
        if((qFront == 0 && qRear == n-1) || (qRear == (qFront-1)%n))
        {
            return true;
        }
        return false;
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