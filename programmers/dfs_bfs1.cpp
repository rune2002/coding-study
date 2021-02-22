#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

struct Node {
    int sum;
    int depth;
};

int count = 0;
queue<Node> q;
void bfs(vector<int> numbers, int target) {
    while (!q.empty())
    {
        Node node_left = q.front();
        Node node_right = q.front();
        q.pop();
        node_left.sum -= numbers[node_left.depth];
        node_left.depth++;
        node_right.sum += numbers[node_right.depth];
        node_right.depth++;
        if (node_left.depth < numbers.size())
        {
            q.push(node_left);
            q.push(node_right);
        }
        else
        {
        	if (node_left.sum == target)
                count++;
            if (node_right.sum == target)
                count++;
        }
        bfs(numbers, target);
    }
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    Node node = {0, 0};
    q.push(node);
    bfs(numbers, target);
    answer = count; 
    return answer;
}