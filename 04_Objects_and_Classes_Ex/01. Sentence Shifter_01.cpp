#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <list>

using namespace std;

class SentenceShift {
    typedef list<string> listS;

    listS sentence;

    public:
    SentenceShift(const string & istr);

    void shift() {
        sentence.push_front(sentence.back());
        sentence.pop_back();
    }

    void shift (int & num) {
        while (num--) {
            shift();
        }
    }

    string getString() {
        ostringstream ostr;

        for (auto elem:sentence) {
            ostr<<elem<<endl;
        };
        return ostr.str();
    }

};

SentenceShift::SentenceShift (const string & istr) {
    istringstream inp(istr);
    string word;
    while (inp>>word) {
        sentence.push_back(word);
    }

}


int main() {

    string input;
    getline(cin,input);

    SentenceShift ss(input);

    int num;
    cin>>num;

    ss.shift(num);

    cout<<ss.getString();
    
    
    system("pause");
    return 0;
}
