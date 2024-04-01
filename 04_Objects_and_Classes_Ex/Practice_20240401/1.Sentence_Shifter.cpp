#include <iostream>
#include <deque>
#include <sstream>
#include <string>

using namespace std;

int main() {

class Shifter{
    private:
    deque<string> words;

    public:
    Shifter(string inp) {
        istringstream istr(inp);
        string curr;
        while (istr>>curr) {
            words.push_back(curr);
        };
    };


    string getShiftedSentence(int shifts) {
        while (shifts--) {
            string temp=words.back();
            words.pop_back();
            words.push_front(temp);
            temp.clear();
        };

        ostringstream ostr;
        for (string word:words) {
            ostr<<word<<endl;
        };
        return ostr.str();
    };
};
    string input;
    getline(cin, input);
    Shifter a (input);

    int num;
    cin>>num;
    cout<<a.getShiftedSentence(num);

    system("pause");
    return 0;
}