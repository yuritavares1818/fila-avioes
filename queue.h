#ifndef QUEUE_H
#define QUEUE_H

#include <string>
#include "./node.h"

using std::string;

class Queue {
    private:
        Node *First;
        Node *Last;
        int Size;
        void PrintPlane(Plane* plane);

    public:
        Queue();
        ~Queue();
        int GetSize();
        void PrintFirst();
        void List();
        void Enqueue(Plane* plane);
        Plane* Dequeue();
        bool IsEmpty();
};

#endif
