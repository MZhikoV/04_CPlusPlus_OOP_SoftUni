#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <sstream>

#include "Defines.h"

using namespace std;

class Command {

    static map<size_t,MemoryType> memory;

    char action;
    MemoryType type;
    size_t index;

    static MemoryType getAt(size_t index) {
        auto it=memory.find(index);
        if (it==memory.end()) {
            return MemoryType::UNKNOWN;
        };
        return it->second;
    };


    static void allocate(size_t index, MemoryType type) {
        memory[index]=type;
    };

    static void free(size_t index) {
        memory.erase(index);
    }

    public:
        Command(const string & command) {
            string buffer;
            istringstream istr(command);
            istr>>buffer;
            action=buffer[0];

            istr>>buffer;
            type=(buffer=="Single" ? MemoryType::SINGLE : MemoryType::MULTIPLE);

            istr>>index;
        };

        ErrorCode execute() {

            MemoryType current=getAt(index);

            if (action=='A') {
                //allocate
                if (current != MemoryType::UNKNOWN) {
                    return ErrorCode::MEMORY_LEAK;
                };

                allocate(index,type);
            }
            else {
                //dellocate
                if (current==MemoryType::UNKNOWN) {
                    return ErrorCode::DOUBLE_FREE;
                };

                if (current!=type) {
                    return ErrorCode::ALLOCATE_DEALLOCATE_MISMATCH;
                };

                free(index);
            };

            return ErrorCode::EXECUTE_SUCCESS;
        };
};

//static
map<size_t,MemoryType> Command::memory;

ErrorCode executeCommand(const std::string & command,std::vector<MemoryNode> & memory) {
    
    Command c(command);

    return c.execute();
};

void printResult(const ErrorCode errorCode, const std::string & command) {

    ostringstream ostr;

    ostr<<command<<" - ";

    switch(errorCode) {
        case ErrorCode::EXECUTE_SUCCESS:
            ostr<<"success";
            break;
        case ErrorCode::DOUBLE_FREE:
            ostr<<"system crash prevented, will skip this deallocation";
            break;
        case ErrorCode::ALLOCATE_DEALLOCATE_MISMATCH:
            ostr<<"Warning allocate/deallocate mismatch, will skip this deallocation";
            break;
        case ErrorCode::MEMORY_LEAK:
            ostr<<"memory leak prevented, will not make allocation";
            break;
    };

    cout<<ostr.str()<<endl;
};