#include <iostream>
#include <sstream>
#include <vector>
#include <string>

class Sentence {
    std::vector<std::string> sentence;

    public:

    Sentence(std::string inp) {
        std::istringstream istr(inp);
        std::string tmp;
        while (istr>>tmp) {
            sentence.push_back(tmp);
        };
    };

    void shiftSentence(int reps) {
        while (reps>0) {
            std::string word=sentence.back();
            sentence.pop_back();
            std::vector<std::string>::iterator it1=sentence.begin();
            sentence.insert(it1,word);
            reps--;
        };
    };

    void getShiftedSentence() {
        for (auto currW:sentence) {
            std::cout<<currW<<std::endl;
        };
    };


};

int main() {
    std::string inpStr;
    std::getline(std::cin, inpStr);
    std::cin.ignore();
    int shifts;
    std::cin>>shifts;

    Sentence first(inpStr);
    first.shiftSentence(shifts);
    first.getShiftedSentence();

    system("pause");
    return 0;
}