#ifndef VirtualBook_h
#define VirtualBook_h

#include <vector>
#include <iostream>

#include "VirtualPage.h" //to chek if it needs to be used



class VirtualBook {

std::vector<VirtualPage> bookPages;


public:
    VirtualBook() {};

void addPage(VirtualPage  page) {
    bookPages.push_back(page);
};

void printContent() const {
    if (!bookPages.empty()) {
        for (size_t idx=0;idx<bookPages.size();idx++) {
            bookPages[idx].printContent();
        };
    };
};

void removeLastPage() {
    if (!bookPages.empty()) {
    bookPages.pop_back();
    };
};

void removeAllPages() {
    if (!bookPages.empty()) {
    bookPages.clear();
    }
};





// book.addPage(page);  todo

//book.printContent();

//removeLastPage();

// book.removeAllPages();


};








#endif