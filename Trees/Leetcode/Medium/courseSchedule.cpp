//Leetcode medium 207
//Eventually we have to find a cycle in the graph, so we build the graph first and then perform recursive dfs on every node. A cycle exists if we meet the same node on any path we traverse in the graph
#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<vector<int>> graph(numCourses);
        vector<bool> visited(graph.size(), false);
        vector<bool> path(numCourses);
        for (auto adj : prerequisites)
        {
            graph[adj[0]].push_back(adj[1]);
        }
        for (int i = 0; i < numCourses; i++)
        {
            if (!dfs(visited, graph, path, i))
            {
                return false;
            }
        }
        return true;
    }
    bool dfs(vector<bool> &visited, vector<vector<int>> &graph, vector<bool> &path, int node)
    {
        if (visited[node])
        {
            return true;
        }
        if (path[node])
        {
            return false;
        }
        path[node] = true;
        for (auto x : graph[node])
        {
            if (!dfs(visited, graph, path, x))
            {
                return false;
            }
        }
        path[node] = false;
        visited[node] = true;
        return true;
    }
};