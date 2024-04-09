#ifndef MEMORYREAD_H
#define MEMORYREAD_H

#include <memory>


#include "Operation.h"
#include "MemorySetOperation.h"

class MemoryReadoperation: public Operation{

    std::shared_ptr<MemorySetOperation> ms;

    public:
        MemoryReadoperation (std::shared_ptr<MemorySetOperation> ms) : ms(ms){};

        virtual void addOperand(int operand) override {};

        virtual int getResult() override {
            return ms->getResult();
        };
        
        virtual bool isCompleted() override {
            return true;
        };
        



};


#endif