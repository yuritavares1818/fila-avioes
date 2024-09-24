#include <iostream>
#include "./queue.h"

using std::cout;
using std::endl;

Queue::Queue() {
    this->First = nullptr;
    this->First = nullptr;
};

Queue::~Queue() {
    while (!this->IsEmpty()) {
        Plane* item = this->Dequeue();
        delete item;
    }
}

int Queue::GetSize() {
    return this->Size;
}

void Queue::PrintPlane(Plane* plane) {
    cout << "Id: " << plane->id << " - Nome: " << plane->name << endl;
}

void Queue::PrintFirst() {
    this->PrintPlane(this->First->item);
}

void Queue::List() {
    if (this->First == nullptr) {
        cout << "Sem registros na fila!" << endl;
    }

    Node* first = this->First;

    while (first != nullptr) {
        this->PrintPlane(first->item);
        first = first->next;
    }
    
    cout << endl;
}

void Queue::Enqueue(Plane* plane) {
    Node* node = new Node();
    node->item = plane;
    node->next = nullptr;

    this->Size++;

    if (this->First == nullptr) {
        this->First = node;
        this->Last = node;
        return;
    }

    this->Last->next = node;
    this->Last = node;
}

Plane* Queue::Dequeue() {
    if (this->First == nullptr) return nullptr;

    Node* node = this->First;
    this->First = this->First->next;

    Plane* item = node->item;
    delete node;

    this->Size--;

    return item;
}

bool Queue::IsEmpty() {
    return this->First == nullptr;
}
