class MyCircularDeque {
    int* arr;
    int qFront;
    int qRear;
    int n;
public:
    MyCircularDeque(int k) {
        n = k;
        arr = new int[n];
        qFront = qRear = -1;
    }
    
    bool insertFront(int value) {
        if(isFull())
        {
            return false;
        }
        else if(qFront == -1 && qRear == -1) //insert in empty queue
        {
            qFront = qRear = 0;
        }
        else if(qFront == 0 && qRear != n-1) //insert at first position
        {
            qFront = n-1;
        }
        else  //insert at any location
        {
            qFront--;
        }
        arr[qFront] = value;
        return true;
    }
    
    bool insertLast(int value) {
        if(isFull())
        {
            return false;
        }
        else if(qFront == -1 && qRear == -1) //insert in empty queue
        {
            qFront = qRear = 0;
        }
        else if(qFront != 0 && qRear == n-1) //insert at last position
        {
            qRear = 0;
        }
        else //insert at any location
        {
            qRear++;
        }
        arr[qRear] = value;
        return true;
    }
    
    bool deleteFront() {
        if(isEmpty())
        {
            return false;
        }
        else if(qFront == qRear) //queue contain only one element
        {
            arr[qFront] = -1;
            qFront = qRear = -1;
        }
        else if(qFront == n-1) //pop from last position
        {
            arr[qFront] = -1;
            qFront = 0;
        }
        else //pop from any location
        {
            arr[qFront] = -1;
            qFront++;
        }
        return true;
    }
    
    bool deleteLast() {
        if(isEmpty())
        {
            return false;
        }
        else if(qFront == qRear) //queue contain only one element
        {
            arr[qFront] = -1;
            qFront = qRear = -1;
        }
        else if(qRear == 0) //pop from first position
        {
            arr[qRear] = -1;
            qRear = n-1;
        }
        else //pop from any location
        {
            arr[qRear] = -1;
            qRear--;
        }
        return true;
    }
    
    int getFront() {
        if(isEmpty())
        {
            return -1;
        }
        return arr[qFront];
    }
    
    int getRear() {
        if(isEmpty())
        {
            return -1;
        }
        return arr[qRear];
    }
    
    bool isEmpty() {
        if(qFront == -1 && qRear == -1)
        {
            //queue is empty
            return true;
        }
        return false;
    }
    
    bool isFull() {
        if((qFront == 0 && qRear == n-1) || qRear == (qFront-1)%n)
        {
            //queue is full
            return true;
        }
        return false;
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