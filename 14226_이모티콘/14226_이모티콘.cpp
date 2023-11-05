#include <iostream>
#include <queue>
#include <vector>
using namespace std;

typedef struct s_info
{
	int n;
	int c;
	int t;
} t_info;
int s;
vector<vector<int>> visited(3000, vector<int>(3000, 0));
vector<vector<int>> map(3000, vector<int>(3000, 0));

int bfs()
{
	queue<t_info> q;

	q.push({1, 0, 0});
	while (!q.empty())
	{
		t_info u = q.front();

		q.pop();
		if (u.n == s)
			return u.t;
		if (u.n + u.c < 3000 && !visited[u.n + u.c][u.c]) // paste
		{
			map[u.n + u.c][u.c] = u.t + 1;
			visited[u.n + u.c][u.c] = 1;
			q.push({u.n + u.c, u.c, u.t + 1});
		}
		if (!visited[u.n][u.n]) // duplicate
		{
			map[u.n][u.n] = u.t + 1;
			visited[u.n][u.n] = 1;
			q.push({u.n, u.n, u.t + 1});
		}
		if (u.n - 1 >= 0 && !visited[u.n - 1][u.c]) // subtract
		{
			map[u.n - 1][u.c] = u.t + 1;
			visited[u.n - 1][u.c] = 1;
			q.push({u.n - 1, u.c, u.t + 1});
		}
	}
	return -1;
}

int main()
{
	cin >> s;
	cout << bfs() << "\n";
}
