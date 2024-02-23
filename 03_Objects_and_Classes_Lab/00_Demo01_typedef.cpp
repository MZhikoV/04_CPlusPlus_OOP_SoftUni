#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;

typedef string TenStrings[10];

void printArray(TenStrings strings) {
    for (int i=0; i<10;i++) {
        cout<<strings[i]<<' ';
    }
    cout<<endl;
}


int main() {
    typedef unsigned long long ull;
    ull number=42;

    TenStrings words={"the", "quick","brown","fox","jumps","over","the","lazy","dog","!"};

    printArray(words);

    cout<<endl;

    typedef map<string,vector<int>> StudentScores;

    StudentScores judjeAss;
    judjeAss["name1"]={100,100,100};
    judjeAss["name2"]={100,5,78};
    judjeAss["name3"]={0,0,100};

    for (StudentScores::iterator it=judjeAss.begin();it!=judjeAss.end();it++){
        cout<<it->first<<' ';
        for (int el:it->second) {
            cout<<el<<' ';
        }
        cout<<endl;
    }

    
    system("pause");
    return 0;
}
