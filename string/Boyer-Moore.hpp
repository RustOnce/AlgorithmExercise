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
    
    vector<int> suffix_table(hay.size() - 1, -1);
    //length of max suffix from right to left.
    vector<size_t> max_suffix(needle.size(), 0);

    i = size2 - 1;
    int j = i + 1;
    while(--i >= 0)
    {
        int temp = max_suffix[j];
        if(needle[i] == needle[size2 - 1 - temp])
        {
            max_suffix[i] = temp + 1;
            if(suffix_table[temp + 1] == -1)
            {
                suffix_table[temp + 1] = i + temp;
            }
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
                j = size2 - temp;//size2 - 1 - (temp - 1);
            }
        }
    }
    
    int n = max_suffix[0];
    if(n != 0)
    {
        for(int i = n + 1;i < size2 - 1;++i)
        {
            if(suffix_table[i] == -1)
            {
                suffix_table[i] = n - 1;
            }
        }
    }



    return pos;
}