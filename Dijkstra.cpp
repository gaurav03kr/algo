// link to question: https://codeforces.com/problemset/problem/20/C



#include <bits/stdc++.h>
using namespace std;

#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define sz(x) (int)(x).size()

#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, n) for (int i = (n) - 1; i >= 0; --i)
#define per1(i, a, b) for (int i = (b); i >= (a); --i)

typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<vector<ll>> vvll;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
using namespace std;

vector<vector<pair<int, int>>> graph;
vector<pair<ll, int>> visited;
ll check = LLONG_MAX;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m;
    cin >> n >> m;
    graph.resize(n + 1);
    rep(i, m)
    {
        int temp1, temp2, temp3;
        cin >> temp1 >> temp2 >> temp3;
        graph[temp2].push_back({temp1, temp3});
        graph[temp1].push_back({temp2, temp3});
    }
    visited.resize(n + 1, {check, -1});
    visited[1].first = 0;
    visited[1].second = 0;
    priority_queue<pair<ll, int>> pri;
    pri.push({0, 1});
    while (!pri.empty())
    {
        ll temp = pri.top().second;
        pri.pop();
        for (auto i : graph[temp])
        {
            if (visited[temp].first + i.second < visited[i.first].first)
            {
                visited[i.first].first = visited[temp].first + i.second;
                visited[i.first].second = temp;
                pri.push({-visited[i.first].first, i.first});
            }
        }
    }
    if (visited[n].second == -1)
    {
        cout << -1;
    }
    else
    {
        vi hi;
        int node = n;
        while (visited[node].second != -1)
        {
            hi.push_back(node);
            node = visited[node].second;
        }
        per(i, hi.size())
        {
            cout << hi[i] << ' ';
        }
    }
}
