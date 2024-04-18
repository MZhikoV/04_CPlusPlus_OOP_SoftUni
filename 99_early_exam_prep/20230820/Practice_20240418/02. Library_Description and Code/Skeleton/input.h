#ifndef input_hh
#define input_hh

#include <iostream>
#include <map>
#include <string>


template <class T> void read(std::map<size_t, T> & input,std::istream & ist) {


    std::string buffer;
    while (ist>>buffer && buffer!="end") {
        size_t id=stoi(buffer);
        ist.ignore();

        T t(id,ist);

        input[id]=t;

    };   

    
};


//books[bookID], cout
template <class T> void print(T & outputB,std::ostream & ost) {
    

    ost<<"book "<<outputB.getId()<<" \""<<outputB.getTitle()<<"\" by \""<<outputB.getAuthor()<<"\" is ";
    
    if (outputB.getBorrower()=="") {
        ost<<"\"available\"";
    }
    else {
        ost<<"\"borrowed by "<<outputB.getBorrower()<<"\"";
    };
    ost<<std::endl;
};





template <class T> void borrow(T & outputB, const string & reader) {
    outputB.setBorrowed(reader);
   print<T>(outputB,cout);
};


template <class T> void borrow(T & outputB) {
    outputB.setBorrowed("");
   print<T>(outputB,cout);
};




template <typename T> void print(T && input,std::ostream & ost) {

        ost<<"-----"<<std::endl;
        ost<<"total books: "<<(*input).size()<<std::endl;
       
    for (auto & curr: *input ) {
        
        //ost<<curr.second.getId();
        print(curr.second,ost);
    };

}

//template <class T> void read(std::map<size_t, T> & input,std::istream & ist) {



//print<map<size_t, Book> *>(&books, cout);


//read<Book>(Book, cin);




/*
borrow<Book>(books[bookID], borrower);
*/



/*
book 2 "Journey to the Center of the Earth" by "Jules Verne" is "available"
*/





/*
1
Daniel Defoe
Robinson Crusoe

*/




/*
 typedef map<size_t, Book> Books;
    Books books;

    read<Book>(books, cin);
*/



#endif