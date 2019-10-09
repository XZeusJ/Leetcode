#include <iostream>
#include <string>
#include <vector>
#include "11.container-with-most-water.cpp"

using namespace std;

int main() {
    // vector<string> msg {"Hello", "C++", "World", "from", "VS Code!"};

    // for (const string& word : msg)
    // {
    //     cout << word << " ";
    // }
    // cout << endl;

    vector<int> x = {1, 8, 6, 2, 5, 4, 8, 3, 7};

    cout << Solution().maxArea(x) << endl;
}