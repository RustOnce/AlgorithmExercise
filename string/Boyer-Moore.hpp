#include <string>
#include <map>
#include <unordered_map>
#include <algorithm>

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
    
    vector<int> substr_table(needle.size() - 1, size2);
    substr_table[0] = 1;

    //length of max suffix from right to left.
    vector<size_t> max_suffix(needle.size(), 0);

    int j = i = size2 - 1;
    --i;
    while(i >= 0)
    {
        int temp = max_suffix[j];
        if(needle[i] == needle[size2 - 1 - temp])
        {
            max_suffix[i] = temp + 1;
            if(substr_table[temp + 1] == size2)
            {
                substr_table[temp + 1] = size2 - 1 - i - temp;
            }
            j = i;
            --i;
        }
        else
        {
            if(temp == 0)
            {
                max_suffix[i] = 0;
                j = i;
                --i;
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
        int stride = size2 - n;
        for(int i = n + 1;i < size2 - 1;++i)
        {
            if(substr_table[i] == size2)
            {
                substr_table[i] = stride;
            }
        }
    }

    i = size2 - 1;
    j = 0;
    while(i <= size1 - 1)
    {
        while(j < size2)
        {
            if(hay[i - j] == needle[size2 - 1 - j])
            {
                ++j;
                continue;
            }
            else
            {
                int stride1 = 1;
                int stride2 = 1;
                char c = hay[i - j];
                int p = GetCharPos(c);
                if(p < size2 - 1 -j)
                {
                    stride1 = size2 - 1 - j - p;
                }

                stride2 = substr_table[j];
                i += std::max(stride1, stride2);
                j = 0;
                            
                break;
            }
        }
        if(j == size2)
        {
            pos = i - size2 + 1;
            break;
        }
    }

    return pos;
}