#ifndef HEADER_H
# define HEADER_H

# include <iostream>
# include <fstream>

class add_elem;

struct      els
{
    int     v;
    float   len;
    els     *next;
};

struct      orgraf
{
    int     v_first;
    els     *first;
};

els		    *v_new(float cost, int num);
void		v_push_back(els **begin_list, float cost, int num);

#endif HEADER_H
