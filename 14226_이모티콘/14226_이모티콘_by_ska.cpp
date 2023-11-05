#include <iostream>
#include <queue>
#include <set>

struct queue_ele{
    int num;
    int clipboard;
    int operation;
};

using namespace std;

int main(void){
    queue<queue_ele> q;
    set<pair<int, int>> visited;

    int s; cin >> s;
    q.push({1, 1, 1});
    while (!q.empty()){
        auto t = q.front(); q.pop();
        if (visited.find({t.num, t.clipboard}) != visited.end())
            continue;
        visited.insert({t.num, t.clipboard});
        if (s == t.num) {
            cout << t.operation << endl;
            break;
        }
        if (t.clipboard != t.num)
            q.push({t.num, t.num, t.operation + 1});
        q.push({t.num + t.clipboard, t.clipboard, t.operation + 1});
        if (t.num - 1 > 0)
            q.push({t.num - 1, t.clipboard, t.operation + 1});
    }
}