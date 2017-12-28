#include <string>
#include <map>
#include <unordered_map>

using namespace std;

int SearchString(const string& hay, const string& needle)
{
    int pos = -1;

    if(needle.empty())
        return 0;
    if(hay.empty())
        return pos;

    int size1 = hay.size();
    int size2 = needle.size();

    unordered_map<char, size_t> char_map;
    int i = 0;
    //Contruct char table for needle.For one char in needle, only its rightmost position will be preserved.
    for(auto& c : needle)
    {
        char_map[c] = i;
        ++i;
    }
    auto GetCharPos = [&](char c)
    {
        int p = -1;
        auto it = char_map.find(c);
        if(it != char_map.end())
        {    
            p = it->second;
        }

        return p;
    };
    unordered_map<size_t, size_t> suffix_table;
    vector<size_t> max_suffix(needle.size(), 0);
    int j = i = size2 - 1;
    while(--i >= 0)
    {
        int temp = max_suffix[j];
        if(needle[i] == needle[size2 - 1 - temp])
        {
            max_suffix[i] = max_suffix[j] + 1;
            j = i;
        }
        else
        {
            if(temp == 0)
            {
                max_suffix[i] = 0;
                j = i;
            }
            else
            {
                j = temp - 1;
            }
        }
    }
    j = size2 - 2;
    i = j;
    int n = 1;
    while(n < size2)
    {
        
    }


    return pos;
}