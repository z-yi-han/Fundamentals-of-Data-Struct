#include"Cricular Queue.h"
MyCircularQueue* myCircularQueueCreate(int k)
{
        MyCircularQueue* obj = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
        obj->k = k + 1;  // 容量多 1 个
        obj->a = (int*)malloc(sizeof(int) * obj->k);
        obj->head = 0;
        obj->tail = 0;
        return obj;
}
bool myCircularQueueEnQueue(MyCircularQueue* obj, int value)
{
    if (myCircularQueueIsFull(obj))
    {
        return false;
    }
    obj->a[obj->tail] = value;
    obj->tail++;
    obj->tail %= (obj->k + 1);
    return true;
}
bool myCircularQueueDeQueue(MyCircularQueue* obj)
{
    if (myCircularQueueIsEmpty(obj))
    {
        return false;
    }
    obj->head++;
    obj->head %= obj->k + 1;
    return true;
}
int myCircularQueueFront(MyCircularQueue* obj)
{
    if (myCircularQueueIsEmpty(obj)) {
        return -1;  // 队列是空的
    }
    return obj->a[obj->head];  // 返回队头元素
}
int myCircularQueueRear(MyCircularQueue* obj)
{
    if (myCircularQueueIsEmpty(obj)) {
        return -1;  // 队列是空的
    }
    return obj->a[(obj->tail-1+obj->k)%obj->k];
}
bool myCircularQueueIsEmpty(MyCircularQueue* obj)
{
    return obj->head == obj->tail;
}
bool myCircularQueueIsFull(MyCircularQueue* obj)
{
    return (obj->tail + 1) % obj->k == obj->head;
}
void myCircularQueueFree(MyCircularQueue* obj)
{
    free(obj->a);
    free(obj);
}