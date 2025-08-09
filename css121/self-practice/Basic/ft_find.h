#include <algorithm>
#include <vector>
#include <iostream>

using std::vector;
using std::cout;

void ft_find()
{
    vector<int> v = {9, -1, 3, 7, 5, 2, 1, 4};

    int x = 5;
    if(find(v.begin(), v.end(), x) != v.end())
    {
        cout << "found" << std::endl;
    }
    else
    {
        cout << "not found" << std::endl;
    }
}