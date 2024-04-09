#ifndef INIT_H
#define INIT_H

#include <memory>
#include <string>
#include "CommandInterface.h"

class AdvancedCommandInterface : public CommandInterface {

    class CutTransform : public TextTransform {

            std::string contents;

        public:
            virtual void invokeOn(std::string& text, int startIndex, int endIndex) override {
                this->contents=text.substr(startIndex, endIndex-startIndex);
                text.erase(startIndex,endIndex-startIndex);
            };

            std::string getContents(void) const {return contents;};
    };

        std::shared_ptr<CutTransform> cutTransform;
        

    class PasteTransform : public TextTransform {

           std::shared_ptr<CutTransform> ct;

        public:

            PasteTransform(std::shared_ptr<CutTransform> ct) : ct(ct) {};

            virtual void invokeOn(std::string& text, int startIndex, int endIndex) override {
                
                std::string::iterator itBegin=text.begin()+startIndex;
                std::string::iterator itEnd=text.begin()+endIndex;

                text.replace(itBegin,itEnd,ct->getContents());
            };
    };



    public:
        AdvancedCommandInterface(std::string & str) : CommandInterface(str) {};

    virtual std::vector<Command> initCommands() override {

        std::vector<Command> commands(CommandInterface::initCommands());

        cutTransform=std::make_shared<CutTransform>();

        commands.push_back(Command("cut", cutTransform));

        commands.push_back(Command("paste", std::make_shared<PasteTransform>(cutTransform)));

        return commands;
    }
};


std::shared_ptr<CommandInterface> buildCommandInterface(std::string &text){
    auto ci = std::make_shared<AdvancedCommandInterface>(text);
    ci->init();

    return ci;
}



#endif