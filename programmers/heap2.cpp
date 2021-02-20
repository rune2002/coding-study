#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

bool less_1(const vector<int> work1, const vector<int> work2)
{
    return work1[0] < work2[0];
}

struct greater_2
{
    bool operator()(const vector<int> work1, const vector<int> work2)
    {
        return work1[1] > work2[1];
    }
};

priority_queue<vector<int>, vector<vector<int>>, greater_2> pq;
int solution(vector<vector<int>> jobs) {
    sort(jobs.begin(), jobs.end(), less_1);
    int now = 0;
    int answer = 0;
    int index = 0;
    bool done = false;

    while (!done)
    {
        while (index < jobs.size() && jobs[index][0] <= now)
        { 
            pq.push(jobs[index]);
            index++;
        }
        
        if (pq.empty())
        {
            now++;
        }
        else 
        {
            vector<int> work = pq.top();
            pq.pop();
            now += work[1];
            answer += (now - work[0]);
        }
        if (index == jobs.size() && pq.empty())
            done = true;
    }
    return answer / jobs.size();
}