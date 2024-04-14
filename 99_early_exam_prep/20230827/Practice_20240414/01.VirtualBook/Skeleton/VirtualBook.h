#ifndef VirtualBook_h
#define VirtualBook_h

#include "VirtualPage.h"

#include <string>
#include <vector>

class VirtualBook {

    std::vector<VirtualPage> book;



public:

    VirtualBook();

    void addPage(VirtualPage page);

    void printContent() const;

    void removeLastPage();

    void removeAllPages();
};



#endif