#include <string>
#include <vector>
#include <cmath>
#include <unordered_set>

#define MAX_NUMBER 32000

using namespace std;
unordered_set<int> s[9];

int solution(int N, int number) {
    int answer = -1;
    
    int n = 0;
    for (int i = 0; i < 5; i++)
    {
        n += pow(10, i) * N;
        s[i+1].insert(n);
    }
    
    for (int i = 1; i < 9; i++)
    {
        s[i].insert(pow(N, i));
    }
    
    for (int i = 1; i < 9; i++)
    {
        for (int j = 1; j < 9 - i; j++)
        {
            for (int x : s[i])
            {
                for (int y : s[j])
                {
                    s[i+j].insert(x + y);
                    s[i+j].insert(x * y);
                    if (x != y)
                        s[i+j].insert(abs(x - y));
                    if (y != 0 && x >= y)
                        s[i+j].insert(x / y);
                    else if (x != 0 && y >= x)
                        s[i+j].insert(y / x);
                }
            }
        }
    }
    
    for (int i = 1; i < 9; i++)
    {
        if(s[i].find(number) != s[i].end())
        {
    		answer = i;
            break;
        }
    }
    
    return answer;
}