#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int sum = 0; 
    vector<pair<int, bool>> container(n, {0, false});

    for (int i = 1; i < container.size(); i+= 2)
    {
        if ((i != 0 && i != container.size() - 1))
        {
            container[i].second = true;

            for (int j = i - 1; j >= 0; --j)
            {
                if (container[j].second == true)
                    break;
                container[i].first += abs(i - j);
            }
            for (int j = i + 1; j <= container.size() - 1; ++j)
            {
                if (container[j].second == true)
                    break;
                container[i].first += abs(i - j);
            }
        }
    }

    for (auto [num, check] : container)
    {
        sum += num;
    }
    cout << sum << endl;
}