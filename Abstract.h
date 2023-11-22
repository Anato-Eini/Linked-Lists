#include "Node.h"
class List{
public:
    virtual void addLast(int) = 0;
    virtual void addFirst(int) = 0;
    virtual void print() = 0;
    virtual void removeNode(int) = 0;
    virtual void flip() = 0;
    virtual int getSize() = 0;
};