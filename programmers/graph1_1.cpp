#include <string>
#include <vector>
#include <algorithm>

#define MAX_DISTANCE 32767

using namespace std;
int getNearest(int n, vector<int> &distance, vector<bool> &visited)
{
    int min_ = MAX_DISTANCE;
    int index = -1;
    for (int i = 1; i < n; i++)
    {
        if (visited[i] == false && distance[i] < min_)
        {
            min_ = distance[i];
            index = i;
        }
    }
    return index;
}

void daijkstra (int n, vector<vector<int>> &vertex, vector<int> &distance, vector<bool> &visited)
{
    for (int i = 0; i < n-1; i++)
    {
        int nearest = getNearest(n, distance, visited);
        if (nearest == -1)
            break;
        
        for (int j = 1; j < n; j++)
        {
            if (vertex[nearest][j] == 1)
                distance[j] = min(distance[j], distance[nearest] + 1);
        }
        visited[nearest] = true;
    }
}

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    vector<bool> visited(n, false);
         
    vector<vector<int>> vertex(n);
    for (int i = 0; i < n; i++)
        vertex[i].resize(n, 0);
    
    for (vector<int> e : edge)
    {
        vertex[e[0]-1][e[1]-1] = 1;
        vertex[e[1]-1][e[0]-1] = 1;
    }

    vector<int> distance(n, MAX_DISTANCE);
    distance[0] = 0;
    for (int i = 1; i < n; i++)
    {
    	if (vertex[0][i] == 1)
            distance[i] = 1;
    }

	daijkstra(n, vertex, distance, visited);
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