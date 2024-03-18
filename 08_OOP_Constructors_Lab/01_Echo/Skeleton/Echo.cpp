#include "Echo.h"

bool echoOn=true;


void echo (const std::string & outp) {
   if(echoOn) {
    std::cout<<outp<<std::endl;
   };

       //std::cout<<outp<<std::endl;

};