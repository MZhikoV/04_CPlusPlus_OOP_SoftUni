
#include "VirtualBook.h"




// class VirtualBook {

//     std::vector<VirtualPage*> book;
// public:

    VirtualBook::VirtualBook()=default;

    void VirtualBook::addPage(VirtualPage page) {
        book.push_back(page);
    };

    void VirtualBook::printContent() const {

        for (auto &currPage:book) {
            currPage.printContent();
        };
    };

    void VirtualBook::removeLastPage() {
        if (!book.empty())
        book.pop_back();
    };

    void VirtualBook::removeAllPages() {
        if (!book.empty())
        book.clear();
    };


