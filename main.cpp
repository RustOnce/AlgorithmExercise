#include <iostream>
#include "string/Boyer-Moore.hpp"

//b5d8e73ed7934481ff898eca31310b1fe56feeb5 
//0b64cb4059809ab854d9e4383ca4c1dc
using namespace std;

int i = 0;
int main(void)
{
    string hay = "fafcebcdcabcdfabdfbsbcebcdcabcfdsdfa";
    string needle = "bcebcdcabc";
    int p = -1;
    p = SearchString(hay, needle);
    p = hay.find(needle);
    
    return 0;
}
