#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());
    string answer;
    for (int i = 0; i < completion.size(); i++) 
    {
        if (participant[i].compare(completion[i]) != 0)
        {
           	answer = participant[i];
            break;
        }
        if (i == completion.size() - 1)
            answer = participant[i+1];
    }
    return answer;
}
