#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>

#define MAX_DISTANCE 32767

using namespace std;

queue<int> q;
void BFS (int n, int current, vector<vector<int>> &vertex, vector<int> &distance, vector<int> &visited)
{
    queue<int> q_next;
    while (!q.empty())
    {
        int nearest = q.front();
        q.pop();

        for (int j = 1; j < n; j++)
        {
            if (vertex[nearest][j] == 1 && visited[j] == 0)
            {
                distance[j] = current + 1;;
                q_next.push(j);
                visited[j] = 1;
            }
        }
    }

    if (q_next.empty())
        return;

    q = q_next;
    BFS(n, current + 1, vertex, distance, visited);

}

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    vector<int> visited(n, 0);

    vector<vector<int>> vertex(n, vector<int>(n, 0));
    for (vector<int> e : edge)
    {
        vertex[e[0]-1][e[1]-1] = 1;
        vertex[e[1]-1][e[0]-1] = 1;
    }

    vector<int> distance(n, MAX_DISTANCE);
    q.push(0);
    distance[0] = 0;
    BFS(n, 0, vertex, distance, visited);
    sort(distance.begin() + 1, distance.end());
    int max_distance = distance[n-1];

    int index = n - 1;

    while(distance[index] == max_distance)
    {
        index--;
    }

    answer = n - index - 1;
    return answer;
}