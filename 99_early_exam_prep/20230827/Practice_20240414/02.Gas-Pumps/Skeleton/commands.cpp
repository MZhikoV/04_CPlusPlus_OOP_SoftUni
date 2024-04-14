#include "commands.h"





//class EndCommand : public Command {

        EndCommand::EndCommand(std::istream & istr) : Command(istr) {} ;

        virtual void EndCommand::process(void) override {
            istr<<"Hour "
        }; 

        virtual EndCommand::~EndCommand() override {};

//class InitCommand : public Command {
//    int initQ;

        InitCommand::InitCommand(std::istream & istr);

        virtual void InitCommand::process(void) override;

        virtual InitCommand::~InitCommand() override;

//class TwoParametersCommand : public Command {
//        int par1, par2;

        TwoParametersCommand::TwoParametersCommand(std::istream & istr) : Command(istr) {
            istr >> par1 >> par2;
        }

        int TwoParametersCommand::getPar1(void) const { return par1; }
        int TwoParametersCommand::getPar2(void) const { return par2; }

//class InCommand : public TwoParametersCommand {

        InCommand::InCommand(std::istream & istr);

        virtual void InCommand::process(void) override;

        virtual InCommand::~InCommand() override;

//class OutCommand : public TwoParametersCommand {

        OutCommand::OutCommand(std::istream & istr);

        virtual void OutCommand::process(void) override;

        virtual OutCommand::~OutCommand() override;


//class DemandCommand : public TwoParametersCommand {

        DemandCommand::DemandCommand(std::istream & istr);

        virtual void DemandCommand::process(void) override;

        virtual DemandCommand::~DemandCommand() override;