#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class Shifter {
    vector<string> sentence;

    public:

    Shifter(string input) 
    {
        istringstream istr(input);
        string word;
        while (istr>>word) {
            sentence.push_back(word);
        };
    };

    void getSchiftedSentence(int a) {
        for (int i=0; i<a;i++) {
            sentence.push_back(sentence.front());
            sentence.erase(sentence.begin());
        };
        for (auto word:sentence) {
            cout<<word<<endl;
        };
    };

    void getSchiftedSentenceReversed (int a) {
        for (int i=0; i<a;i++) {
            sentence.insert(sentence.begin(), sentence.back());
            sentence.pop_back();
        };
        for (auto word:sentence) {
            cout<<word<<endl;
        };
    };
};

int main() {

    string input, word;
    int reps;

    getline(cin,input);
    cin>>reps;

    Shifter sentence(input);

   // sentence.getSchiftedSentence(reps);

    sentence.getSchiftedSentenceReversed(reps);


    system ("pause");
    return 0;
}