#ifndef MEMORYOP_H
#define MEMORYOP_H

#include <stack>


#include "Operation.h"

class MemorySetOperation: public Operation {

    std::stack<int> memory;

    public:
        virtual void addOperand(int operand) override {
            memory.push(operand); 
        };

        virtual int getResult() override {

            int memoryTop=memory.top();
            memory.pop();
            return memoryTop;
        };

        virtual bool isCompleted() override {

            return false;
        };


};



#endif