#ifndef AverageAggregator_hhh
#define AverageAggregator_hhh


#include "Aggregator.h"


class AverageAggregator: public StreamAggregator {
int sum;

public:
    AverageAggregator(std::istringstream & istr) : StreamAggregator(istr), sum(0) {aggregationResult=0;};

    virtual void aggregate(int next) {
		StreamAggregator::aggregate(next);
        
        sum+=next;

        aggregationResult=sum/getNumAggregated();
	};
};



#endif