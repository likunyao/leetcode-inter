/*
 * @lc app=leetcode.cn id=811 lang=cpp
 *
 * [811] 子域名访问计数
 */

// @lc code=start
#include <vector>
#include <string>
#include <map>
#include <sstream>
using namespace std;

class Solution
{
public:
    vector<string> subdomainVisits(vector<string> &cpdomains)
    {
        map<string, int> vitimes;
        for (auto cpdomain : cpdomains)
        {
            stringstream out(cpdomain);
            int times;
            string domain;
            out >> times >> domain;
            int len = domain.size(), pos = -1;
            vitimes[domain] += times;
            while ((pos = domain.find(".", pos + 1)) != string::npos)
            {
                string dom = domain.substr(pos + 1);
                vitimes[dom] += times;
            }
        }
        vector<string> res;
        for (auto item : vitimes)
            res.push_back(to_string(item.second) + " " + item.first);
        return res;
    }
};
// @lc code=end
