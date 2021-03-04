#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int borrow = 0;
    int lost_size = lost.size();
    vector<int>::iterator it;
    sort(reserve.begin(), reserve.end());
    sort(lost.begin(), lost.end());
    for (int i = 0; i < reserve.size(); i++)
    {
        it = find(lost.begin(), lost.end(), reserve[i]); 
        if (it != lost.end())
        {
            lost.erase(it);
            borrow++;
            continue;
        }
        
        it = find(lost.begin(), lost.end(), reserve[i] - 1);
        if (it != lost.end())
        {
            lost.erase(it);
            borrow++;
            continue;
        }
        
        it = find(lost.begin(), lost.end(), reserve[i] + 1);
        if (it != lost.end())
        {
            if (i < (reserve.size() - 1) && reserve[i+1] == *it)
                continue;
            
            lost.erase(it);
            borrow++;
            continue;
        }
	}
    int answer = n - lost_size + borrow;
    return answer;
}