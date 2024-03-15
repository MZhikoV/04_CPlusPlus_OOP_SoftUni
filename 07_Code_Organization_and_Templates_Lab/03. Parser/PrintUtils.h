#ifndef PRINTUNITS_H
#define PRINTUNITS_H

using namespace std;

template <typename T> void printVector (vector<T> & vectorT) {
    typename vector<T>::iterator it1;

    for (it1=vectorT.begin(); it1!=vectorT.end();it1++) {
        cout<<*it1<<' ';
    }
    cout<<endl;
}






#endif //!PRINTUNITS_H