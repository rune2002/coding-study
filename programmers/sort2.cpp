#include <string>
#include <vector>
#include <algorithm>

using namespace std;
bool _greater(const int a, const int b)
{
    string _a = to_string(a);
    string _b = to_string(b);
    
    return (_a + _b).compare(_b + _a) > 0 ? true : false;
}

string solution(vector<int> numbers) {
    sort(numbers.begin(), numbers.end(), _greater);
    if (numbers[0] == 0)
        return "0";
        
    string answer;
    for (int i = 0; i < numbers.size(); i++)
        answer += to_string(numbers[i]);
    
    return answer;
}