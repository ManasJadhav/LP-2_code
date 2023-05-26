#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void insertByEdges(vector<vector<pair<int, int>>> &graph, int n)
{
    int e;
    cout << "Enter the number of edges: ";
    cin >> e;
    for (int i = 0; i < e; i++)
    {
        int a, b, wt;
        cout << "Enter the edge " << i + 1 << ": ";
        cin >> a >> b;
        cout << "Enter the edge Weight : ";
        cin >> wt;
        graph[a].push_back({b, wt});
        graph[b].push_back({a, wt});
    }
    // print adjacency list
    for (int i = 0; i < n; i++)
    {
        cout << i << "->";
        for (int j = 0; j < graph[i].size(); j++)
        {
            cout << "{" << graph[i][j].first << " , " << graph[i][j].second << "}";
        }
        cout << endl;
    }
}

void primsMST(vector<vector<pair<int, int>>> &graph, vector<int> &visited, vector<pair<int, int>> &MST, int start)
{
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    int sum = 0;
    pq.push({0, {start, -1}});
    while (!pq.empty())
    {

        int wt = pq.top().first;
        int node = pq.top().second.first;
        int parent = pq.top().second.second;
        pq.pop();

        if (visited[node] == 1)
            continue;
        visited[node] = 1;
        if (parent != -1)
        {
            MST.push_back({parent, node});
        }
        sum += wt;
        for (auto it : graph[node])
        {
            int currNode = it.first;
            int currWt = it.second;
            if (!visited[currNode])
            {
                pq.push({currWt, {currNode, node}});
            }
        }
    };
    cout << "The minimum sum of Wt's is: " << sum << "\n";
}
int main()
{
    int n;
    cout << "Enter the number of vertices: ";
    cin >> n;
    vector<vector<pair<int, int>>> graph(n);
    insertByEdges(graph, n);
    vector<int> visited(n, 0);
    vector<pair<int, int>> MST;
    int start = 0;
    cout << "Enter the start vertices : ";
    cin >> start;
    primsMST(graph, visited, MST, start);

    cout << "Edges in MST are : ";
    for (auto it : MST)
    {
        cout << "{" << it.first << " , " << it.second << "} ";
    }
    cout << "\n";
}