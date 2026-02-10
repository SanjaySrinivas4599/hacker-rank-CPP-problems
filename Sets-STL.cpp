#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;



    
    int main() {
    set<int> values;
    int queries, qType, qVal;
    cin >> queries; 
    while(queries) {
        cin >> qType >> qVal;
        switch (qType) {
            case 1:
                values.insert(qVal);
                break;
            case 2:
                values.erase(qVal);
                break;
            case 3:
                if(values.find(qVal) != values.end())
                    cout << "Yes\n";
                else
                    cout << "No\n";
                break;
        }
        queries--;
    }
    return 0;
}



