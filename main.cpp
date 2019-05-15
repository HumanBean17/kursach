#include "header.h"

int g;

class 			graph
{
private:
	orgraf 		*or_tmp;
	els	   		*v_tmp;
	vector<els> node;
public:
	graph 		(vector<int> num)
	{
		int j = -1;

		for (int i = 0; i < num.size(); i++)
		{
			j++;
			v_tmp = ft_create_node(num.at(j), 0);
			node.push_back(*v_tmp);
			if (j == 0)
				ft_create_head(num.at(j), &or_tmp, &v_tmp);
		}
	};
	els			*ft_create_node(int v_num, float cost)
	{
		els *tmp;

		tmp = new els;
		tmp->v = v_num;
		tmp->len = cost;
		tmp->next = nullptr;
		return (tmp);
	}
	int			*ft_create_head(int v_num, orgraf **head, els **tmp)
	{
		*head = new orgraf;

		(*head)->v_first = v_num;
		(*head)->first = *tmp;
		return (nullptr);
	}
	void		ft_list_push_back(els **begin, int v_num, float cost)
	{
		els *tmp;

		tmp = *begin;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = ft_create_node(v_num, cost);
	}
	void 		ft_connect(string s)
	{
		els *tmp;
		char **str;

		str = ft_strsplit(s, ' ');
		tmp = ft_find(stoi(str[0]));
		if (str[2] != nullptr)
		    ft_list_push_back(&tmp, stoi(str[1]), stoi(str[2]));
	}
	els			*ft_find(int cur_num)
	{
		for (int i = 0; i < node.size(); i++)
			if (node.at(i).v == cur_num)
				return (&node.at(i));
		return (nullptr);
	}
	void 		ft_check(void)
	{
		int i;
		els *tmp;

		i = 0;
		cout << "Вершина графа: v" << (or_tmp->first)->v << endl;
		while (i < node.size())
		{
			tmp = &node.at(i);
			while (tmp)
			{
				cout << "v" << tmp->v << " cost = " << tmp->len;
				tmp = tmp->next;
				if (tmp)
					cout << " -> ";
				else
					cout << " -> NULL";
			}
			cout << endl;
			i++;
		}
		cout << endl;
	}
	friend 		func_graph;
	friend 		void operator > (graph &my_graph, func_graph &func);
	friend 		void operator < (graph &my_graph, func_graph &func);
	~graph 		() {};
};

class 			func_graph
{
private:
	int x;
	int y;
	int add;
public:
	func_graph 	() {};
	void 		ft_do_dfs(graph &my_graph, int x)
	{
		els *u;
		float sum;

		sum = 0;
		for (int i = 0; i < my_graph.node.size(); i++)
		{
			g = 0;
			u = &my_graph.node.at(i);
			vector<int>	 way(my_graph.node.size());
            vector<bool> visited(my_graph.node.size() + 1, false);
			way.at(g) = u->v;
			my_graph.v_tmp = u;
			dfs(u, my_graph, &visited, &way, &sum, x);
			way.clear();
			visited.clear();
		}
	}
	int 		dfs(els *u, graph &my_graph, vector<bool> *visited, vector<int> *way, float *sum, int x)
	{
		els *tmp;
		els *const_u;

		way->at(g) = u->v;
		visited->at(u->v) = true;
		while (u->next)
		{
			u = u->next;
			*sum += u->len;
            g++;
			if (*sum == x)
			{
                way->at(g) = u->v;
                ft_print_way(my_graph, way, *sum);
            }
			tmp = ft_els_vector_find(my_graph, u->v);
			if (!ft_bool_vector_find(visited, u->v))
			    dfs(tmp, my_graph, visited, way, sum, x);
            way->at(g) = 0;
		}
		way->at(g) = 0;
		g--;
		*sum = 0;
		return (0);
	}
	void		ft_print_way(graph &my_graph, vector<int> *way, float sum)
	{
	    int k;

		for (int j = 0; j < way->size(); j++)
		{
			if (way->at(j) != 0)
				cout << way->at(j) << " -> ";
			k = j;
		}
		cout << "NULL || len = " << sum << endl;
	}
	els 		*ft_els_vector_find(graph &my_graph, int num)
	{
		for (int i = 0; i < my_graph.node.size(); i++)
			if (my_graph.node.at(i).v == num)
				return (&my_graph.node.at(i));
		return (nullptr);
	}
	int		ft_bool_vector_find(vector<bool> *s, int to_find)
	{
		for (int i = 1; i < s->size(); i++)
			if (i == to_find && s->at(i) == true)
				return (1);
		return (0);
	}
	void 		ft_add_v(graph &my_graph, func_graph &func)
	{
		char z;

		y = 1;
		add = 1;
		my_graph.node.push_back(*my_graph.ft_create_node(my_graph.node.size() + 1, 0));
		cout << "Должна ли вершина быть изолированной? 1/0" << endl;
		cin >> x;
		if (x == 0)
		{
			x = my_graph.node.size();
			while (true)
			{
				cout << "Введите вершину, с которыми должна быть смежна новая вершина. Для окончания ввода, введите '-1'" << endl;
				cin >> y;
				if (y < 0)
					break;
				ft_change_direction(my_graph, func, x, y);
			}
			add = 0;
		}
	}
	void 		ft_change_weight(graph &my_graph)
	{
		els *tmp;
		int l;
		int m;
		int n;

		cout << "Номера вершин, между которыми необходимо изменить вес ребра" << endl;
		cin >> m;
		cin >> n;
		cout << "Введите новый вес ребра:" << endl;
		cin >> l;
		tmp = ft_els_vector_find(my_graph, m);
		if (!ft_list_find(tmp, n))
		{
			while (tmp)
			{
				if (tmp->v == n)
				{
					tmp->len = l;
					return ;
				}
				tmp = tmp->next;
			}
		}
		else
		{
			tmp = ft_els_vector_find(my_graph, n);
			while (tmp)
			{
				if (tmp->v == m)
				{
					tmp->len = l;
					return;
				}
				tmp = tmp->next;
			}
		}
	}
	void 		ft_change_direction(graph &my_graph, func_graph &func, int f_x, int f_y)
	{
		char f_z;

		func.x = f_x;
		func.y = f_y;
		printf("Введите направление ребра. Формат :\n> (из v%d можно попасть в v%d)\n< (из v%d можно попасть в v%d)\n", f_x, f_y, f_y, f_x);
		cin >> f_z;
		if (f_z == '>')
			my_graph > func;
		else
			my_graph < func;
	}
	void    	ft_lstdelone(els **alst, els *to_del, graph &my_graph)
	{
	    els    *cur;
		els    *tmp;
		els    *cp;

		for (int i = 0; i < my_graph.node.size();i++)
        {
		    if (my_graph.node.at(i).v)
		    {
                cur = &my_graph.node.at(i);
                break;
            }
        }
		tmp = *alst;
		if (!tmp || !to_del)
			return ;
		if (tmp == to_del)
		{
		    free(my_graph.or_tmp);
			*alst = tmp->next;
			my_graph.ft_create_head(cur->v, &my_graph.or_tmp, &cur);
			free(tmp);
			return ;
		}
		while(tmp->next != to_del)
			tmp = tmp->next;
		cp = tmp->next;
		if (tmp->next != nullptr && (tmp->next)->next == nullptr)
		{
			tmp->next = nullptr;
			free(cp);
		}
		else
		{
			tmp->next = (tmp->next)->next;
			free(cp);
		}
	}
	bool		ft_list_find(els *begin_list, int num)
	{
		els *tmp;

		tmp = begin_list;
		if (tmp)
		{
			while ((tmp->next) && num != tmp->v)
				tmp = tmp->next;
			if (tmp->v == num)
				return (false);
		}
		return (true);
	}
	void 		ft_del_vertex(graph &my_graph)
	{
		els *tmp;
		els *cur;
		int num;

		cout << "Введите номер вершины, которую вы хотите удалить" << endl;
		cin >> num;
		for (int i = 0; i < my_graph.node.size(); i++)
		{
			tmp = &my_graph.node.at(i);
			cur = tmp;
			while (tmp)
			{
				if (tmp->v == num)
                    ft_lstdelone(&cur, tmp, my_graph);
				tmp = tmp->next;
			}
		}
        my_graph.node.erase(my_graph.node.begin() + num - 1);
	}
	orgraf      *FIRST(graph &my_graph)
    {
	    return (my_graph.or_tmp);
    }
	friend 		void operator < (graph &my_graph, func_graph &func);
	friend 		void operator > (graph &my_graph, func_graph &func);
	~func_graph () {};
};

void operator < (graph &my_graph, func_graph &func)
{
	els *tmp;
	els *head;

	if (func.add == 1)
	{
		tmp = func.ft_els_vector_find(my_graph, func.y);
		my_graph.ft_list_push_back(&tmp, func.x, 0);
		return ;
	}
	tmp = func.ft_els_vector_find(my_graph, func.y);
	if (!func.ft_list_find(tmp, func.x))
		return ;
	my_graph.ft_list_push_back(&tmp, func.x, 0);
	tmp = &my_graph.node.at(func.x - 1);
	head = &my_graph.node.at(func.x - 1);
	while (tmp)
	{
		if (tmp->v == func.y)
		{
			func.ft_lstdelone(&head, tmp, my_graph);
			break ;
		}
		tmp = tmp->next;
	}
}

void operator > (graph &my_graph, func_graph &func)
{
	els *tmp;
	els *head;

	if (func.add == 1)
	{
		tmp = func.ft_els_vector_find(my_graph, func.x);
		my_graph.ft_list_push_back(&tmp, func.y, 0);
		return ;
	}
	tmp = func.ft_els_vector_find(my_graph, func.x);
	if (!func.ft_list_find(tmp, func.y))
		return ;
	my_graph.ft_list_push_back(&tmp, func.y, 0);
	tmp = &my_graph.node.at(func.y - 1);
	head = &my_graph.node.at(func.y - 1);
	while (tmp)
	{
		if (tmp->v == func.x)
		{
			func.ft_lstdelone(&head, tmp, my_graph);
			break ;
		}
		tmp = tmp->next;
	}
}

int     main()
{
	string 		filename;
	string		tmp;
	ifstream	file;
	vector<int>	ar;
	graph 		*a;
	func_graph 	b;
	int 		x;
	setlocale(LC_ALL, "ru");

	cout << "Введите путь к файлу:" << endl;
	cin >> filename;
	file.open(filename);
	if (!file.is_open())
	{
		cout << "Ошибка при открытии файла" << endl;
		return (1);
	}
	while (getline(file, tmp) && tmp[0] != '#')
		ar.push_back(stoi(tmp));
	a = new graph(ar);
	while (getline(file, tmp))
        a->ft_connect(tmp);
	a->ft_check();
	//cout << "Введите длину пути:" << endl;
	//cin >> x;
	//b.ft_do_dfs(*a, x);
	//b.ft_add_v(*a, b);
	//b.ft_change_direction(*a, b, 15, 9);
    b.ft_del_vertex(*a);
    //b.ft_change_weight(*a);
    //b.FIRST(*a);
    a->ft_check();
    return (0);
}