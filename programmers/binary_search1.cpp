#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> times) {
    long long answer;
    int m = times.size();
    sort(times.begin(), times.end());
    long long left = times[0];
    long long right = ((long long) (n / m + 1) * times[m - 1]);
    answer = right;
    long long mid = (left + right) / 2;
    while (left <= right)
    {
        mid = (left + right) / 2;
        long long capacity = 0;
        for (int i = 0; i < m; i++)
            capacity += mid / times[i];
        
        if (capacity < n)
        {
            left = mid + 1;
        }
        else if (capacity >= n)
        {            
            right = mid - 1;
        }
    }
    answer = left;
    return answer;
}
/*
First try, failed with test 6, 7, 8 (time over)

#include <string>
#include <vector>
#include <queue>
#include <algorithm>

struct Immigration {
    int index;
    long long left;
};

struct _greater {
    bool operator()(const Immigration &a, const Immigration &b)
    {
        return a.left > b.left;
    }
};

using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;
    int m = times.size();
    // sort(times.begin(), times.end());
	vector<int> done(m, 0);
    priority_queue<Immigration, vector<Immigration>, _greater> pq;
    for (int i = 0; i < m; i++)
    {
        Immigration im = {i, times[i]};
        pq.push(im);
    }
    
    for (int i = 0; i < n; i++)
    {
        Immigration t = pq.top();
        answer = t.left;
        pq.pop();
        done[t.index]++;
        t.left = (done[t.index] + 1) * times[t.index];
        pq.push(t);
    }
    
    return answer;
}
*/