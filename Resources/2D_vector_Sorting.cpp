#include <vector>
#include <algorithm>   // for std::sort
#include <functional>  // for std::greater
#include <iostream>
using namespace std;
int main()
{
    // Set up an example vector
    std::vector<std::vector<int>> v{{5, 9, 4, 12, 4},
        {7, 9, 3, 4, 7, 9},
        {6, 5, 11},
        {5, 8, 7, 3},
        {5, 9, 5, 1, 1}};

    // Perform the sort
    std::sort(v.begin(), v.end(), std::greater<std::vector<int>>());

    // Output the results
    for (const auto& i : v)
    {
        for (auto j : i)
            cout << j << " ";
        cout << "\n";
    }

    sort(v.begin(), v.end());
    cout<<"\n";
    // Output the results
    for (const auto& i : v)
    {
        for (auto j : i)
            cout << j << " ";
        cout << "\n";
    }


}
