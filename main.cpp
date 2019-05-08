#include "header.h"

els 			*ft_node_find(int v_num, vector<els> node);

class 			graph
{
	friend els *ft_node_find(int v_num, vector<els> node);
private:
	orgraf 			*or_tmp;
	els	   			*v_tmp;
	vector<els> 	node;
public:
	graph (vector<int> num)
	{
		int j = -1;

		for (int i = num.size(); i > 0; i--)
		{
			j++;
			if (j == 0)
				ft_create_head(num.at(j), &or_tmp);
			v_tmp = ft_create_node(num.at(j), 0);
			node.push_back(*v_tmp);
		}
	};
	els		*ft_create_node(int v_num, float cost)
	{
		els *tmp;

		tmp = new els;
		tmp->v = v_num;
		tmp->len = cost;
		tmp->next = nullptr;
		return (tmp);
	}
	void	ft_list_push_back(els **begin, int v_num, float cost)
	{
		els *tmp;

		tmp = *begin;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = ft_create_node(v_num, cost);
		//cout << (*begin)->v << "  " << ((*begin)->next)->v << endl;
	}
	void 	ft_connect(int cur_num, int dest_num, float cost)
	{
		els *tmp;

		for (int i = node.size() - 1; i > 0; i--)
			if (node.at(i).v == cur_num)
			{
				tmp = &node.at(i);
				ft_list_push_back(&tmp, dest_num, cost);
			}
	}
	int		*ft_create_head(int v_num, orgraf **head)
	{
		*head = new orgraf;

		(*head)->v_first = v_num;
		(*head)->first = nullptr;
		return (nullptr);
	}
	void 	ft_check(void)
	{
		int i;
		els *tmp;

		i = 0;
		while (i < 7)
		{
			tmp = &node.at(i);
			//cout <<  tmp->v << "  " << (tmp->next)->v << endl;
			while (tmp)
			{
				cout << "vertex = " << tmp->v << " cost = " << tmp->len << endl;
				tmp = tmp->next;
			}
			i++;
		}
	}
	~graph () {};
};

int     main()
{
	setlocale(LC_ALL, "ru");
	string 			filename;
	string			tmp;
	ifstream		file;
	vector<int>		ar;
	char 			**str;
	graph 			*a;

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
    return (0);
}