#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <deque>
#include <list>

using namespace std;

class Sentence {
    list<string> wordsOrder;

    public:

        Sentence (const string &inp);

        void shift(void) {
            wordsOrder.push_front(wordsOrder.back());
            wordsOrder.pop_back();
        }

        void shift(int &count) {
            while (count>0 && count--) {
                shift();
            }
        }

        string getShiftedSentence();
};

Sentence::Sentence (const string &inp) {
    istringstream input(inp);
    string word;
    while (input>>word) {
        wordsOrder.push_back(word);
    }
};


string Sentence::getShiftedSentence() {
            
            ostringstream outp;

          for (auto el:wordsOrder) {
            outp<<el<<endl;
          }
          return outp.str();
        };



int main() {

    string input;
    getline(cin,input);
   
   // istringstream inp(input);

    Sentence words(input);

    int num;
    cin>>num;

    words.shift(num);

    cout<<words.getShiftedSentence();
    
    
    system("pause");
    return 0;
}
