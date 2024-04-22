#include <string>
#include <iostream>

#include "Processor.h"

using namespace std;

int main(void) {

    Processor proc;

    string str;
    while(getline(cin, str)) {

        if (str[0] == 'e' && str.length() == 3)
            break;

        if (proc.processInput(str)) {
            cout << proc.execute() << endl;
        }
    }

    system("pause");

    return 0;
}





/*
cut sleeveR 5 8
cut sleeveL 6 8
cut base 12 15
sew light-jacket 7 sleeve base sleeveR
iron light-jacket 5
pack
cut I1 3 5
cut I2 4 7
sew J1 2 I1 I2
iron J1 2
cut I3 5 8
sew J2 3 J1 I3
cut I3 2 2
pack
end


*/