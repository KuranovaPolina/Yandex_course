#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

void is_grow(void) {
    string s;

    getline(cin, s);

    stringstream iss(s);

    int number;
    vector<int> myNumbers;
    while (iss >> number)
        myNumbers.push_back(number);

    int last = myNumbers[0], now;
    bool is_grow = true;

    for (int i = 1; i < myNumbers.size(); i++)
    {
        now = myNumbers[i];
        if (now <= last) {
            is_grow = false;
            break;
        }
        last = now;
    }

    if (is_grow) cout << "YES";
    else cout << "NO";

}