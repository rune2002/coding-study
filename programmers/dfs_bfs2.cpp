#include <string>
#include <vector>
#include <stack>

using namespace std;

stack<int> s;
void DFS(int n, vector<vector<int>> computers, vector<bool> &visited)
{
    while(!s.empty())
    {
        int node = s.top();
        s.pop();
        visited[node] = true;
        for (int i = 0; i < n; i++)
        {
            if (computers[node][i] == 1 && visited[i] == false)
            {
                s.push(i);
            }
        }  
        DFS(n, computers, visited);
    }
}

int solution(int n, vector<vector<int>> computers) {
    vector<bool> visited(n, false);
    int answer = 0;
    for (int i = 0; i < n; i++)
    {
        if (visited[i] == false)
        {
            s.push(i);
            DFS(n, computers, visited);
            answer++;
        }
    }
    return answer;
}