#ifndef input_h
#define input_h

#include <string>
#include <map>
#include <iostream>
#include <sstream>

using namespace std;


template <typename T> void read( map<size_t, T> & books, istream & istr) {
       string input;
       while (istr>>input && input!="end") {
       size_t currID=stoi(input);
       istr.ignore();

       T currBook (currID,istr);

       books[currID]=currBook;
       };
};



// template <typename T> void print( const T& booke, ostream & ostr) {

// const T * book=&booke;

// ostr<<"book "<<book->getId()<<" \""<<book->getTitle()<<"\" by "<<book->getAuthor()<<" is ";
// if (book->getBorrower()=="") {
//     ostr<<"\"available\"";
// }
// else {
//     ostr<<"\"borrowed by "<<book->getBorrower()<<"\"";
// }
//     ostr<<endl;
// };

template <typename T> void borrow(  T & book, const string & borrower) {

    book.setBorrowed(borrower);
    print (book,cout);

};

template <typename T> void borrow(  T & book) {
    book.setBorrowed("");
    print (book,cout);

//todo

};

template <typename T> void print(const T& books, ostream & ostr) {
 
    ostr << "-----" << std::endl;
    ostr << "total books: " << books.size() << std::endl;
    for (size_t idx=0; idx<books.size();idx++) {
        ostr << "book " << books[idx].getId() << " \"" << books[idx].getTitle() << "\" by \"" << books[idx].getAuthor() << "\" is ";
        if (books[idx].getBorrower().empty()) {
            ostr << "\"available\"";
        } else {
            ostr << "\"borrowed by " << books[idx].getBorrower() << "\"";
        }
        ostr << std::endl;
    };

};



#endif