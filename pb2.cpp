#include<iostream>
#include<fstream>
#include<vector>
#include<set>

using namespace std;

#define MAXLENGTH 100

int viz[MAXLENGTH], tata[MAXLENGTH];

vector<int> adancime;
vector<vector<int> > tree;
set<int> rez;

ifstream file("in.txt");

int DFS_helper(int v)
{
	viz[v] = 1;

	for (int i = 0; i < tree[v].size(); ++i)
	{
		if (viz[tree[v][i]] == 0)
		{
			tata[tree[v][i]] = v;
			DFS_helper(tree[v][i]);
		}
	}

	adancime.push_back(v);

	return 0;
}

int DFS(int n)
{
	for (int i = 1; i <= n; ++i)
	{
		if (viz[i] == 0)
		{
			DFS_helper(i);
		}
	}

	return 0;
}

int main()
{
	int n, x, y;
	file >> n;

	tree.resize(n + 1);

	while (file >> x >> y)
	{
		tree[x].push_back(y);
		tree[y].push_back(x);
	}

	DFS(n);

	// Construiesc solutia:

	for (int i = 0; i < adancime.size(); ++i)
	{
		if (viz[adancime[i]] == 1)
		{
			rez.insert(adancime[i]);
			viz[tata[adancime[i]]] = 0;
		}
	}

	cout << rez.size() << endl;

	set<int>::iterator i;
	for (i = rez.begin(); i != rez.end(); ++i)
	{
		cout << (*i) << " ";
	}

	cout << endl;

	return 0;
}
