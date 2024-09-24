#ifndef NODE_H
#define NODE_H

#include "plane.h"

struct t_node {
    Plane* item;
    t_node* next;
};

typedef struct t_node Node;

#endif
