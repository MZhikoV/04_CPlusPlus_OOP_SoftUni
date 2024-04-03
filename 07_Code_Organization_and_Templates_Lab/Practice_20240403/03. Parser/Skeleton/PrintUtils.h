#ifndef PRINTU_H
#define PRINTU_H

#include <vector>
#include <iostream>

using namespace std;

template <typename T> void printVector(vector<T> & forPrint) {
    for ( T & curr:forPrint) {
        cout<<curr<<' ';
    };
    cout<<endl;
};


#endif