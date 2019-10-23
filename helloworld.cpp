#include <iostream>
#include <string>
#include <vector>
#include "205.isomorphic-strings.cpp"

using namespace std;

int main() {
    // vector<string> msg {"Hello", "C++", "World", "from", "VS Code!"};

    // for (const string& word : msg)
    // {
    //     cout << word << " ";
    // }
    // cout << endl;

    vector<int> x = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    string s = "ab";
    string t = "aa";

    cout << Solution().isIsomorphic(s, t) << endl;
}