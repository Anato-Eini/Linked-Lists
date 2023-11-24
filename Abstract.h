#include "Node.h"
class SinglyList{
public:
    virtual void addLast(int) = 0;
    virtual void addFirst(int) = 0;
    virtual void print() = 0;
    virtual void removeNode(int) = 0;
    virtual void flip() = 0;
};

class DoublyList{
public:
    virtual void addLast(int) = 0;
    virtual void addFirst(int) = 0;
    virtual void print() = 0;
    virtual int nthNodeFromLast(int) = 0;//this solves the problem of https://citu.codechum.com/student/study-area/5591
};