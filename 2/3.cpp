#include <iostream>
#include <vector>
#include <string>
using namespace std;

int LongCommonString(const string& lhs, const string& rhs) 
{
    auto llen = lhs.size();
    auto rlen = rhs.size();
    //check if empty
    if (llen == 0 || rlen == 0) 
        return 0;
    vector<vector<int>> record(llen,vector<int>(rlen,0));

    int startl = -1;
    int startr = -1;
    int res = 0; 
    int com = 0;
    //begin compare
    for (int j = 0; j < rlen; j++)
    {
        com++;
        record[0][j] = lhs[0] == rhs[j] ? 1 : 0;
    }
 
    for (int i = 1; i < llen; i++)
    {
        com++;
        record[i][0] = lhs[i] == rhs[0] ? 1 : 0;
        for (int j = 1; j < rlen; j++)
        {
            com++;
            if (lhs[i] == rhs[j])
                record[i][j] = record[i-1][j-1] + 1;
        }
    }
    for (int i = 0; i < llen; i++)
    {
        for (int j = 0; j < rlen; j++)
        {
            if (res < record[i][j])
            {
                res = record[i][j];
                startl = i - res + 1;
                startr = j - res + 1;
            }
        }
    }
    return res;
}

int main()
{
    string lhs,rhs;
    cin >> lhs >> rhs;
    cout << LongCommonString(lhs,rhs) << endl;
    return 0;
}