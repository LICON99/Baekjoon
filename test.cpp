#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<int> a;
	vector<pair<int, int>> test;
	a.push_back(1);
	a.push_back(2);
	a.push_back(3);
	a.push_back(4);
	for (int i = 0; i < 4; i++)
		printf("i : %d, val : %d\n", i, a[i]);
	a.assign(4, 0);
	a[0]=2;
	for (int i = 0; i < 4; i++)
		printf("i : %d, val : %d\n", i, a[i]);
	// a.resize(10);
	// a.push_back(4);
	// for (int i : a)
	// 	printf("%d, ", i);
	// printf("back : %d, size : %d\n", a.back(), a.size());
	// a.clear();
	// a.push_back(4);
	// for (int i = 0; i < 11; i++)
	// 	printf("%d, ", a[i]);
	// printf("back : %d, size : %d\n", a.front(), a.size());
}