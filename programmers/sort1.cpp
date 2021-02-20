#include <string>
#include <vector>

using namespace std;
void sort(vector<int> &array)
{
    for (int i = 0; i < array.size(); i++) 
    {
        for (int j = i-1; j >= 0; j--) 
        {
            if (array[j + 1] < array[j])
            {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
            else
                break;
        }
    }
}

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    for (vector<int> command : commands)
    {
        int start = command[0];
        int end = command[1];
        int k = command[2];
        
        vector<int> sub_array(end - start + 1);
        vector<int>::iterator s = array.begin() + start - 1;
        vector<int>::iterator e = array.begin() + end;
        copy(s, e, sub_array.begin());
        sort(sub_array);
        answer.push_back(sub_array[k - 1]);
    }
    return answer;
}