#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Function to perform depth-first search
void dfs(vector<vector<int>> &graph, vector<bool> &visited, int node)
{
    // Mark the current node as visited
    visited[node] = true;
    cout << node << " ";

    // Recursively visit all adjacent unvisited nodes
    for (int neighbor : graph[node])
    {
        if (!visited[neighbor])
        {
            dfs(graph, visited, neighbor);
        }
    }
}

void bfsRecursive(vector<vector<int>> &graph, vector<bool> &visited, queue<int> &q)
{
    if (q.empty())
    {
        return;
    }

    int node = q.front();
    q.pop();
    cout << node << " ";
    for (auto it : graph[node])
    {
        if (!visited[it])
        {
            visited[it] = 1;
            q.push(it);
        }
    }

    bfsRecursive(graph, visited, q);
}

void insertbyedges(vector<vector<int>> &graph, int n)
{
    int e;
    cout << "Enter the number of edges: ";
    cin >> e;
    for (int i = 0; i < e; i++)
    {
        int a, b;
        cout << "Enter the edge " << i << ": ";
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    // print adjacency list
    for (int i = 0; i < n; i++)
    {
        cout << i << "->";
        for (int j = 0; j < graph[i].size(); j++)
        {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int numVertices;
    cout << "Enter the number of vertices: ";
    cin >> numVertices;
    vector<vector<int>> graph(numVertices);

    insertbyedges(graph, numVertices);

    int startNode;
    cout << "Enter the starting node: ";
    cin >> startNode;

    // Perform DFS
    cout << "DFS traversal: ";
    vector<bool> visitedDFS(numVertices, false);
    dfs(graph, visitedDFS, startNode);
    cout << endl;

    // Perform BFS
    cout << "BFS traversal: ";
    vector<bool> visitedBFS(numVertices, false);
    queue<int> q;
    q.push(startNode);
    visitedBFS[startNode] = true;
    bfsRecursive(graph, visitedBFS, q);
    cout << endl;
}