#include <string>
#include <vector>
#include <queue>
using namespace std;

queue<int> bridge;
int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    int sum = 0;
    int i = 0;
    while (i < truck_weights.size())
    {
        if (bridge.size() == bridge_length)
        {
            sum -= bridge.front();
            bridge.pop();
        }        
        
        if (sum + truck_weights[i] <= weight)
        {
            sum += truck_weights[i];
            bridge.push(truck_weights[i]);
            i++;
        } 
        else
        {
            bridge.push(0);
        }
        
   		answer++;     
    }

	answer += bridge_length;    
    return answer;
}
