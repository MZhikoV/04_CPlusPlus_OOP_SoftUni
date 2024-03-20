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

class Letters {
    private:
        typedef set<string> WordS;
        WordS words;

        void cleanWord(string & word);




    public:

        Letters (const string & theLine);

        string getWordsContaining(char c);


};

    Letters::Letters (const string & theLine) {
        string currWord;
        istringstream istr(theLine);

        while (istr>>currWord) {
            cleanWord(currWord);
            words.insert(currWord);
        }
    };

    void Letters::cleanWord(string & word) {
        for (string::iterator it1=word.begin(); it1!=word.end();) {
            if(isalpha(*it1)) {
                it1++;
            }
            else {
                it1=word.erase(it1);
            }
        }
    };

    string Letters::getWordsContaining(char ch) {
        ostringstream result;
        bool isEmpty=true;
            for (WordS::iterator it2=words.begin(); it2!=words.end(); it2++) {
                string currentW=*it2;
                    for (size_t c=0; c<currentW.size();c++) {
                        if (tolower(currentW[c])==tolower(ch)) {
                             result<<currentW<<' ';
                            isEmpty=false;
                            break;
                        }
                    };
            };
        if (isEmpty) {
            result<<"---";
        }

        return result.str();
    }



int main() {
    

    string input;
    getline(cin,input);
    Letters l(input);

     char inpC;
     while (cin>>inpC && inpC!='.') {
        cout<<l.getWordsContaining(inpC)<<endl;   
     }



    // istringstream inp(input);

    // vector<char> inclC;
    // char inpC;
    // while (cin>>inpC && inpC!='.') {
    //     inclC.push_back(inpC);
    // }

    // vector<set<string>> words;
    // int idx=0;

    // for (vector<char>::iterator it1=inclC.begin(); it1!=inclC.end(); it1++) {
    //     string currWord;
    //     while (inp>>currWord) {
    //         for(size_t c=0; c<currWord.size(); c++) {
    //             if (tolower(currWord[c])==tolower(*it1)) {
    //                 words.
    //             }
    //         }
    //     }
    //     if (it1!=inclC.end()) {
    //         idx++;
    //     }
    // }
    




    system("pause");
    return 0;
}
