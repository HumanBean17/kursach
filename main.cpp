#include "header.h"

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
	void 		ft_connect(int cur_num, int dest_num, float cost)
	{
		els *tmp;

		tmp = ft_find(cur_num);
		ft_list_push_back(&tmp, dest_num, cost);
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
		while (i < 7)
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
	~graph 		() {};
};

class 			func_graph
{
public:
	func_graph 	() {};
	void 		ft_do_dfs(graph &my_graph, int x)
	{
		els *u;
		vector<bool> visited(my_graph.node.size(), false);
		int flag;
		int sum;

		sum = 0;
		for (int i = 0; i < visited.size(); i++)
		{
			u = &my_graph.node.at(i);
			flag = 0;
			cout << "v" << u->v << " -> ";
			dfs(u, my_graph, &visited, &sum);
			cout << "NULL" << endl;
			cout << "========" << endl;
		}
	}
	int 		dfs(els *u, graph &my_graph, vector<bool> *visited, int *sum)
	{
		els *tmp;

		visited->at(u->v - 1) = true;
		cout << "v" << u->v << " -> ";
		while (u->next)
		{
			u = u->next;
			//cout << "u = " << u->v << endl;
			//cout << u->v << " next " << endl;
			/*if (!(ft_int_vector_find(*visited, u->v)))
			{
				tmp = ft_els_vector_find(my_graph, u->v);
				dfs(tmp, my_graph, visited);
				cout << "==========" << endl;
				//cout << "tmp = " << tmp->v << endl;
			}*/
			tmp = ft_els_vector_find(my_graph, u->v);
			dfs(tmp, my_graph, visited, sum);
		}
		//cout << "v" << u->v << endl;
		cout << "NULL" << endl;
		return (0);
	}
	els 		*ft_els_vector_find(graph &my_graph, int num)
	{
		for (int i = 0; i < my_graph.node.size(); i++)
			if (my_graph.node.at(i).v == num)
				return (&my_graph.node.at(i));
		return (nullptr);
	}
	bool		ft_int_vector_find(vector<bool> s, int to_find)
	{
		for (int i = 0; i <= s.size(); i++)
		{
			if (i == to_find && i == true)
				return (true);
		}
		return (false);
	}
	~func_graph () {};
};

int     main()
{
	string 		filename;
	string		tmp;
	ifstream	file;
	vector<int>	ar;
	graph 		*a;
	func_graph 	b;
	char 		**str;
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
	{
		str = ft_strsplit(tmp, ' ');
		a->ft_connect(ft_atoi(str[0]), ft_atoi(str[1]), ft_atoi(str[2]));
	}
	a->ft_check();
	//cout << "Введите длину пути:" << endl;
	//cin >> x;
	b.ft_do_dfs(*a, 1);
    return (0);
}