#include "header.h"

class add_elem
{
private:
    els *tmp;
public:
    void		v_push_back(els **begin_list, float cost, int num)
    {
        tmp = *begin_list;
        if (tmp == NULL)
        {
            tmp = v_new(cost, num);
            *begin_list = tmp;
            return ;
        }
        while (tmp->next)
            tmp = tmp->next;
        tmp->next = v_new(cost, num);
    }
	els		*v_new(float cost, int num)
	{
		tmp = new els;
		tmp->len = cost;
		tmp->v = num;
		tmp->next = NULL;
		return (tmp);
	}
};