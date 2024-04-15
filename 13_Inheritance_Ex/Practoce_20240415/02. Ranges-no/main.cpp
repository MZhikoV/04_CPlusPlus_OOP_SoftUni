#include <iostream>
#include <vector>
#include <string>
#include <sstream>

#include "Node.h"


using namespace std;

class Nodes  {
    
    vector<Node> nodes;

    public:
    void setNodeV(Node n) {
        nodes.push_back(n);
    };

    bool inRange (int & value) {
        for (auto & curr:nodes) {
            if ((curr.getFrom())<=value && curr.getTo()) {
                return true;
            };
        };
        return false;
    };

    ~Nodes () {};

};



int main() {



string buff;
while (getline(cin,buff) && buff!=".") {
    stringstream istr(buff);
    int a,b;
    istr>>a>>b;
    Node nd(a,b);

    Nodes nds;
    nds.setNodeV(nd);
};

while (getline(cin,buff) && buff!=".") {
    stringstream istr(buff);
    int c;
    istr>>c;

    Nodes nds;
    cout<<(nds.inRange(c) ? "in":"out")<<endl;
};



    system("pause");
    return 0;
}