#ifndef SUMAGR_H
#define SUMAGR_H

#include "Aggregator.h"

class SumAggregator:public StreamAggregator {


    public:
        SumAggregator(std::istringstream & istr): StreamAggregator(istr) {aggregationResult=0;};

        virtual void aggregate(int next) override {
      //      StreamAggregator::aggregate(next);
		    aggregationResult+=next;
	    };
};




#endif