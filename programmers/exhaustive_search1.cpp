#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
    int size = answers.size();
    vector<int> score(3, 0);
    int pattern_one[5] = {1, 2, 3, 4, 5};
    int pattern_two[8] = {2, 1, 2, 3, 2, 4, 2, 5};
    int pattern_three[10] = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
    
    for (int i = 0; i < size; i++)
    {
    	if (answers[i] == pattern_one[(i % 5)])
            score[0]++;
        
        if (answers[i] == pattern_two[(i % 8)])
            score[1]++;
        
        if (answers[i] == pattern_three[(i % 10)])
            score[2]++;
    }

	vector<int> sorted = score;
    sort(sorted.begin(), sorted.end());
    
    vector<int> rtn;
    for (int i = 0; i < 3; i++)
    {
        if (score[i] == sorted[2])
            rtn.push_back(i+1);
    }
    
    return rtn;
}