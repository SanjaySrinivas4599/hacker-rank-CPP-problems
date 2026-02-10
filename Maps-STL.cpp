#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <map>
#include <algorithm>
using namespace std;


int main() {
    map<string, int> marks;
    int count; cin >> count;
    
    for (int x = 0, query; x < count; x++)
    {
        map<string, int>::iterator pointer;
        string name;
        int mark = 0;
        
        cin >> query >> name;
        
        switch (query)
        {
            case 1: 
            {
                cin >> mark;
                if ((pointer = marks.find(name)) == marks.end())
                {
                    marks.insert(make_pair(name, mark));
                } else 
                {
                    marks[name] += mark;
                }
                break; 
            }
            case 2:
            {
                if ((pointer = marks.find(name)) == marks.end()) break;
                marks.erase(pointer->first);
                
                break;
            }
            case 3:
            {
                if ((pointer = marks.find(name)) == marks.end()) cout << 0 << endl;
                else cout << pointer->second << endl;
                break;    
            }
        }
    }
    
    return 0;
}
