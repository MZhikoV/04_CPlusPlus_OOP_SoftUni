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

class Shifter {
    private:
    vector<string>words;

    public:
    Shifter(const string & input);

    string getShiftedSentence(int num);


};

    Shifter::Shifter (const string & input) {
        istringstream inp(input);
        string currWord;
        while (inp>>currWord) {
            words.push_back(currWord);
        }
    };

    string Shifter::getShiftedSentence(int num) {
        while (num--) {
            string buffer;
            buffer=words.back();
            words.erase(words.end());
            words.insert(words.begin(),buffer);
        }

        ostringstream outp;
        bool isFirst=true;
        for(string & curr:words) {
           outp<<curr<<endl;
        }
        return outp.str();
    }



int main() {

    string buffer;
    getline(cin,buffer);

    Shifter sht(buffer);


    int shifts;
    cin>>shifts;
    
    cout<<sht.getShiftedSentence(shifts)<<endl;
    
    system("pause");
    return 0;
}
