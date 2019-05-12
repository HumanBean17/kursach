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
		ft_list_push_back(&tmp, stoi(str[1]), stoi(str[2]));
	}
	els			*ft_find(int cur_num)
	{
		for (int i = node.size() - 1; i > 0; i--)
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
		vector<bool> visited(my_graph.node.size(), false);
		float sum;

		sum = 0;
		for (int i = 0; i < my_graph.node.size(); i++)
		{
			g = 0;
			u = &my_graph.node.at(i);
			vector<int>	 way(my_graph.node.size());
			way.at(g) = u->v;
			dfs(u, my_graph, &visited, &way, &sum, x);
			way.clear();
		}
	}
	int 		dfs(els *u, graph &my_graph, vector<bool> *visited, vector<int> *way, float *sum, int x)
	{
		els *tmp;
		els *const_u;

		way->at(g) = u->v;
		while (u->next)
		{
			u = u->next;
			*sum += u->len;
			if (*sum == x)
				ft_print_way(my_graph, way, *sum);
			g++;
			tmp = ft_els_vector_find(my_graph, u->v);
			dfs(tmp, my_graph, visited, way, sum, x);
		}
		/*if (*sum != 0)
			ft_print_way(my_graph, way, *sum);*/
		way->at(g) = 0;
		g--;
		*sum = 0;
		return (0);
	}
	void		ft_print_way(graph &my_graph, vector<int> *way, float sum)
	{
		for (int j = 0; j < way->size(); j++)
		{
			if (way->at(j) != 0)
				cout << way->at(j) << " -> ";
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
	bool		ft_bool_vector_find(vector<bool> s, int to_find)
	{
		for (int i = 0; i <= s.size(); i++)
		{
			if (i == to_find && i == true)
				return (true);
		}
		return (false);
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
	void    	ft_lstdelone(els **alst, els *to_del)
	{
		els    *tmp;
		els    *cp;

		tmp = *alst;
		if (!tmp || !to_del)
			return ;
		if (tmp == to_del)
		{
			*alst = tmp->next;
			cout << tmp->v << endl;
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
		my_graph.node.erase(my_graph.node.begin() + num - 1);
		for (int i = 0; i < my_graph.node.size() - 1; i++)
		{
			tmp = &my_graph.node.at(i);
			cur = tmp;
			while (tmp)
			{
				if (tmp->v == num)
					ft_lstdelone(&cur, tmp);
				tmp = tmp->next;
			}
		}
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
			func.ft_lstdelone(&head, tmp);
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
			func.ft_lstdelone(&head, tmp);
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

	//cout << "Введите путь к файлу:" << endl;
	//cin >> filename;
	file.open("/Users/lcrawn/Documents/GitHub/kursach/graph1.tgf");
	if (!file.is_open())
	{
		cout << "Ошибка при открытии файла" << endl;
		return (1);
	}
	while (getline(file, tmp) && tmp[0] != '#')
		ar.push_back((int) tmp[0] - 48);
	a = new graph(ar);
	while (getline(file, tmp))
		a->ft_connect(tmp);
	a->ft_check();
	cout << "Введите длину пути:" << endl;
	cin >> x;
	b.ft_do_dfs(*a, x);
	//b.ft_add_v(*a, b);
	//b.ft_change_direction(*a, b, 4, 5);
	//b.ft_del_vertex(*a);
	//a->ft_check();
    return (0);
}