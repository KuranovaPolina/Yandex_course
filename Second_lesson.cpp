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

void sequence_type() {
    enum type { CONSTANT, 
        ASCENDING, 
        DESCENDING,
        WEAKLY_ASCENDING, 
        WEAKLY_DESCENDING, 
        RANDOM
    };

    bool is_constant = false,
        is_ascending = false,
        is_weakly_ascending = false,
        is_descending = false,
        is_weakly_descending = false;

    int last_ai, ai;
    cin >> ai;

    if (ai != -2000000000) {
        last_ai = ai;
        cin >> ai;

        if (ai != -2000000000) {
            type type_now = DESCENDING;
            if (last_ai == ai) {
                type_now = CONSTANT;
                is_constant = true;
            }
            else if (last_ai < ai) {
                type_now = ASCENDING;
                is_ascending = true;
            }
            else is_descending = true;

            last_ai = ai;
            cin >> ai;

            while (ai != -2000000000) {
                if (type_now != RANDOM) {
                    if (last_ai < ai) {
                        if (!is_constant && !is_descending && !is_weakly_descending && !is_weakly_ascending) {
                            type_now = ASCENDING;
                            is_ascending = true;
                        }
                        else if (is_constant && !is_descending && !is_weakly_descending) {
                            type_now = WEAKLY_ASCENDING;
                            is_weakly_ascending = true;
                        }
                        else if (is_descending || is_weakly_descending) type_now = RANDOM;
                    }

                    else if (last_ai > ai) {
                        if (!is_constant && !is_ascending && !is_weakly_ascending && !is_weakly_descending) {
                            type_now = DESCENDING;
                            is_descending = true;
                        }
                        else if (is_constant && !is_ascending && !is_weakly_ascending) {
                            type_now = WEAKLY_DESCENDING;
                            is_weakly_descending = true;
                        }
                        else if (is_ascending || is_weakly_ascending) type_now = RANDOM;
                    }

                    else if (last_ai == ai) {
                        if (type_now == ASCENDING){
                            type_now = WEAKLY_ASCENDING;
                            is_weakly_ascending = true;
                        }
                        else if (type_now == DESCENDING){
                            type_now = WEAKLY_DESCENDING;
                            is_weakly_descending = true;
                        }
                    }
                }

                last_ai = ai;
                cin >> ai;
                
            }

            switch (type_now)
            {
            case CONSTANT:
                cout << "CONSTANT";
                break;
            case ASCENDING:
                cout << "ASCENDING";
                break;
            case DESCENDING:
                cout << "DESCENDING";
                break;
            case WEAKLY_ASCENDING:
                cout << "WEAKLY ASCENDING";
                break;
            case WEAKLY_DESCENDING:
                cout << "WEAKLY DESCENDING";
                break;
            case RANDOM:
                cout << "RANDOM";
                break;
            default:
                break;
            }
        }            
        else cout << "CONSTANT";
    }
    else cout << "RANDOM";
    
};