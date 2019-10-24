#include <iostream>
#include <string>
#include <vector>
// #include "290.word-pattern.cpp"

using namespace std;

int main() {
    // vector<string> msg {"Hello", "C++", "World", "from", "VS Code!"};

    // for (const string& word : msg)
    // {
    //     cout << word << " ";
    // }
    // cout << endl;

    vector<int> x = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    string s      = "abba";
    string t      = "dog cat cat fish";

    // cout << Solution().wordPattern(s, t) << endl;

    int j = 0;
    for (int i = 0; i < s.size(); i++) {
        string word = "";
        while (j < t.size()) {
            if (t[j] != ' ')
                word = word + t[j++];
            else {
                j++;
                break;
            }
        }
        cout << word << endl;
    }
}