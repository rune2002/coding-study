#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

priority_queue<int, vector<int>, greater<int>> s;
int solution(vector<int> scoville, int K) {
    for (int i : scoville)
        s.push(i);
    
    int answer = 0;
    while (s.top() < K && s.size() > 1) {
        int t1 = s.top();
        s.pop();
        int t2 = s.top();
        s.pop();
        s.push(t1 + t2 * 2);
    	answer++;
    }
    
    return s.top() >= K ? answer : -1;
}