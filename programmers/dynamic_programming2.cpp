#include <string>
#include <vector>
#include <algorithm>

using namespace std;


int solution(vector<vector<int>> triangle) {
    int answer = 0;
    int height = triangle.size();
    vector<vector<int>> s(height, vector<int>(height, 0));
    
    s[0][0] = triangle[0][0];
	for (int i = 1; i < height; i++)
    {
        for (int j = 0; j < i+1; j++)
        {	
            if (j == 0)
                s[i][j] = s[i-1][j] + triangle[i][j];
            else if (j == i)
                s[i][j] = s[i-1][i-1] + triangle[i][j];
            else
                s[i][j] = max(s[i-1][j-1], s[i-1][j]) + triangle[i][j];
        }
    }
    
    sort(s[height - 1].begin(), s[height - 1].end());
    answer = s[height - 1][height - 1];
    return answer;
}