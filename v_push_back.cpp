#include "header.h"

void		v_push_back(els **begin_list, float cost, int num)
{
    els *tmp;

    tmp = *begin_list;
    if (tmp == 0)
    {
        tmp = v_new(cost, num);
        *begin_list = tmp;
        return ;
    }
    while (tmp->next)
        tmp = tmp->next;
    tmp->next = v_new(cost, num);
}