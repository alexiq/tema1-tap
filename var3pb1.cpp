#include<iostream>
#include<fstream>
#include<vector>
#include<ctime>


using namespace std;

ifstream file("in.txt");

int startGame(int n, vector<int> v)
{
	int s, d, sum1, sum2;
	vector<char> P1;
	vector<char> P2;

	s = 0;
	d = n - 1;
	sum1 = 0;
	sum2 = 0;

	while (s < d)
	{
		if (v[s] == v[d])	// daca optiunile sunt egale, o aleg pe cea care lasa pentru oponent o optiune mai mica
		{
			if (v[s + 1] > v[d - 1])
			{
				sum1 += v[d];
				P1.push_back('D');
				d--;
			}
			else
			{
				sum1 += v[s];
				P1.push_back('S');
				s++;
			}
		}
		else
			if (v[s] < v[d])
			{
				if (v[d - 1] > v[d] && v[d - 1] > v[s] && v[d - 1] > v[s + 1] && v[s + 1] < v[d])
				{
					sum1 += v[s];
					P1.push_back('S');
					s++;
				}
				else
				{
					sum1 += v[d];
					P1.push_back('D');
					d--;
				}
			}
			else
			{
				if (v[s + 1] > v[s] && v[s + 1] > v[d] && v[s + 1] > v[d - 1] && v[s] > v[d - 1])
				{
					sum1 += v[d];
					P1.push_back('D');
					d--;
				}
				else
				{
					sum1 += v[s];
					P1.push_back('S');
					s++;
				}
			}

		int pc;
		// pc = variabila random dupa care alege calculatorul;

		pc = rand() % 2;
		if (pc)
		{
			sum2 += v[d];
			P2.push_back('D');
			d--;
		}
		else
		{
			sum2 += v[s];
			P2.push_back('S');
			s++;
		}
	}

	// Incheiere joc:

	if (sum1 >= sum2)
	{
		cout << "Jucatorul 1 a castigat!" << endl;
	}
	else
	{
		cout << "Jucatorul 2 a castigat!" << endl;
	}
	cout << endl;

	cout << "Primul jucator a adunat suma " << sum1 << endl;
	cout << "Mutarile primului jucator au fost: ";
	for (int i = 0; i < P1.size(); ++i)
	{
		cout << P1[i] << " ";
	}
	cout << endl << endl;

	cout << "Al doilea jucator a adunat suma " << sum2 << endl;
	cout << "Mutarile celui de-al doilea jucator au fost: ";
	for (int i = 0; i < P2.size(); ++i)
	{
		cout << P2[i] << " ";
	}
	cout << endl;

	return 0;
}

int main()
{
	srand(time(NULL));

	int n, x;
	vector<int> v;

	file >> n;	
	for (int i = 0; i < n; ++i)
	{
		file >> x;
		v.push_back(x);
	}

	startGame(n, v);

	return 0;
}