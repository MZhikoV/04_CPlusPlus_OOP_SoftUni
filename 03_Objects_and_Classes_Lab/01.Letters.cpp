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

class Letters
{

private:
    typedef set<string> Words;
    Words words;

    void cleanWord(string &word);

public:
    Letters(const string & theLine);

    string getWordsContaining(char c);

};

Letters::Letters(const string & theLine){
    string currWord;
    istringstream istr(theLine);

    while (istr>>currWord) {
        cleanWord(currWord);    //cleans the word from non-alpha symbols
        words.insert(currWord); //inserts the current word in the set
    }
}

char asciitoUpper(char c) {
    if (c>='a') {
        c-=('a'-'A');
    }
    return c;
}

string Letters::getWordsContaining(char c) {
    ostringstream ostr;

    c=asciitoUpper(c);

    for (const string &s:words) {
        string transformed=s;
        transform(transformed.begin(), transformed.end(), transformed.begin(), asciitoUpper);

        if (transformed.find(c)!=string::npos) {
            ostr<<s<<" ";
        }
    }

    return ostr.str();
}

void Letters::cleanWord(string & word) {
    for (string::iterator itCur=word.begin();itCur!=word.end();) {
        if (isalpha(*itCur)) {
            itCur++;
        }
        else {
            itCur=word.erase(itCur);
        }
    }
}

int main()
{
    string buffer;
    getline(cin,buffer);

    Letters l(buffer);

    char currCh;
    while (cin>>currCh && currCh!='.') {
        string containedWords=l.getWordsContaining(currCh);

        if (containedWords.size()==0){
            containedWords="---";
        }

        cout<<containedWords<<endl;
    }


    system("pause");
    return 0;
}
