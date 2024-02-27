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

using namespace std;

class Sentence {
    private:
        typedef deque<string> QQ;
        QQ wordsOrder;

    public:

        Sentence () {};
        void setWords(string &inp) {
            wordsOrder.push_back(inp);
        }

        string getShiftedSentence(int &num);
};


string Sentence::getShiftedSentence(int &num) {
            while (num>0) {
                string temp;
                temp=wordsOrder.back();
                wordsOrder.pop_back();
                wordsOrder.push_front(temp);
                num--;
            }

            ostringstream outp;

          while (!wordsOrder.empty()) {
            outp<<wordsOrder.front()<<endl;
            wordsOrder.pop_front();
          }
          return outp.str();
        };



int main() {

    string input;
    getline(cin,input);
    istringstream inp(input);

    int num;
    cin>>num;

    Sentence words;

    string word;
    while (inp>>word) {
        words.setWords(word);
    }

    cout<<words.getShiftedSentence(num);
    
    
    system("pause");
    return 0;
}
