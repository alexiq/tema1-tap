#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>

using namespace std;

ifstream file("in.txt");

vector<pair<int, int> > v;
vector<pair<int, int> > matrix[100];

bool compare(const pair<int, int> &a, const pair<int, int> &b)
{
	return a.first < b.first;
}

int main()
{
	typedef pair<int, int> Pair;

	int n;
	file >> n;

	Pair aux;
	for (int i = 0; i < n; ++i)
	{
		file >> aux.first;
		file >> aux.second;

		v.push_back(aux);
	}

	sort(v.begin(), v.end(), compare);

	//for (int i = 0; i < n; ++i)
	//{
	//	cout << v[i].first << " " << v[i].second << endl;

	//}

	int nr = 0;

	//for (int i = 0; i < n; ++i)
	//{
	//	matrix[i].resize(n);
	//}

	aux = v[0];
	matrix[nr].push_back(aux);		// adaug primul interval pentru ca este sigur parte din solutie
	//aux = v[0];

	for (int i = 1; i < n; ++i)
	{
		for (int j = 0; j <= nr; ++j)
		{
			if (v[i].first >= matrix[j][matrix[j].size() - 1].second)
			{
				matrix[j].push_back(v[i]);
				break;
			}
			else
			{
				nr++;
				matrix[nr].push_back(v[i]);
				break;
			}
		}
	}

	cout << "Sunt necesare " << nr+1 << " sali." << endl;

	for (int i = 0; i <= nr; ++i)
	{
		for (int j = 0; j < matrix[i].size(); ++j)
		{
			cout << "(" << matrix[i][j].first << "," << matrix[i][j].second << ")" << " ";
		}

		cout << endl;
	}

	cout << endl;
	return 0;
}

