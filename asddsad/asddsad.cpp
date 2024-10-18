#include <iostream>
#include <random>

using namespace std;

int main()
{
	setlocale(LC_ALL, "");
	int n = 10;
	int size2 = 0;
	cout << "Введите кол-во вершин";
	cin >> n;
	int** G = new int* [n];
	int* deg = new int [n];
	for (int i = 0; i < n; i++) {
		deg[i] = 0;
	}
	for (int i = 0; i < n; i++)
	{
		G[i] = new int[n];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = i; j < n; j++)
		{
			G[i][j] = rand() % 2;
			G[j][i] = G[i][j];
			if (i == j) G[i][j] = 0;
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << G[i][j] << " ";
		}
		cout << endl;
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			//size = size + G[i][j];
			if (G[i][j] == 1)
			{
				size2++;
			}
		}
	}
	size2 = size2 / 2;

	cout << "Размер графа " << size2;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			
			if (G[i][j] != 0)
			{
				deg[i]++;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		cout << "Степень вершины " << i << " = " << deg[i] << endl;
	}

	for (int i = 0; i < n; i++) {
		if (deg[i] == 0) cout << "Вершина " << i << " изолированная" << endl;
		if (deg[i] == 1) cout << "Вершина " << i << " концевая" << endl;
		if (deg[i] == n - 1) cout << "Вершина " << i << " доминирующая" << endl;
	}

	delete(G);
}