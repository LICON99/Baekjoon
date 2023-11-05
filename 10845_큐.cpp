#include <iostream>
#include <queue>
#include <string>
using namespace std;

int n;
queue<int> q;
void conv(string cmd)
{
	int n;
	if (cmd == "push")
	{
		cin >> n;
		q.push(n);
	}
	if (cmd == "front")
	{
		if (!q.empty())
			cout << q.front() << "\n";
		else
			cout << -1 << "\n";
	}
	if (cmd == "back")
	{
		if (q.empty())
			cout << -1 << "\n";
		else
			cout << q.back() << "\n";
	}
	if (cmd == "size")
		cout << q.size() << "\n";
	if (cmd == "empty")
		cout << q.empty() << "\n";
	if (cmd == "pop")
	{
		if (q.empty())
			cout << -1 << "\n";
		else
		{
			cout << q.front() << "\n";
			q.pop();
		}
	}
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);

	cin >> n;
	string cmd;
	for (int i = 0; i < n; i++)
	{
		cin >> cmd;
		// cout << stoi(cmd.substr(5));
		conv(cmd);
	}
	return 0;
}