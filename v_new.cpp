#include "header.h"

els		*v_new(float cost, int num)
{
    els *tmp;

    tmp = new els;
    tmp->len = cost;
    tmp->v = num;
    tmp->next = NULL;
    return (tmp);
}