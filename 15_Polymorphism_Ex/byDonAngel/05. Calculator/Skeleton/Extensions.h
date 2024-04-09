#ifndef EXTENSIONS_H
#define EXTENSIONS_H

#include "CalculationEngine.h"
#include "AdvancedInterpreter.h"
#include <memory>

std::shared_ptr<InputInterpreter> buildInterpreter(CalculationEngine & engine) {

    return std::make_shared<AdvancedInterpreter>(engine);
};

#endif