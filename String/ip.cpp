#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int stringToInt(string& s)
{
    int res = 0; 
    for(int i = 0; i < s.size(); ++i)
    {
        res = res*10 + s[i] - '0';
    }
    if(s[0] == '0' && s.size() > 1)return INT_MAX;
    return res;
}
void getR(vector<string>& res, string& s, string& temp, int index, int turn)
{
    if(index == s.size())
    {
        if(turn == 4)
        {
            cout<<temp<<endl;
            res.push_back(temp);
        }
        return;
    }
    for(int i = 1; i <= 3; ++i)
    {
        string T = temp;
        if(turn != 0)
          temp += ".";  
        string addString;
        if(index + i <= s.size())
            addString = s.substr(index, i);
        else
            return;
        temp += addString;
        int val = stringToInt(addString);
        if(val > 255 || val < 0)return;
        if(index + i <= s.size())
         getR(res, s, temp, index + i, turn + 1);
        else 
         getR(res, s, temp, s.size(), turn + 1);
        temp = T;
    }
}
int main()
{
    string str = "2552551111";
    vector<string> res;
    if(str.size() > 12 || str.size() < 4)return -1;
    string temp="";
    getR(res, str, temp, 0, 0);
    return 0;
}
