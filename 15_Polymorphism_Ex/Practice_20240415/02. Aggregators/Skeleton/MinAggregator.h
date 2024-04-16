#ifndef MinAggregator_hhh
#define MinAggregator_hhh

#include "Aggregator.h"
#include <climits>

class MinAggregator: public StreamAggregator {
    int min;

public:
    MinAggregator(std::istringstream & istr) : StreamAggregator(istr), min(INT_MAX) {aggregationResult=0;};

    virtual void aggregate(int next) {
		StreamAggregator::aggregate(next);
        if (min>next) {
            min=next;
            aggregationResult=min;
        };
	};
};


#endif