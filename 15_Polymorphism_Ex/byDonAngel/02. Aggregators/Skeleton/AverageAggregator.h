#ifndef AVGAGGR_H
#define AVGAGGR_H

#include "Aggregator.h"




class AverageAggregator:public StreamAggregator {

    int sum;


    public:
        AverageAggregator(std::istringstream & istr): StreamAggregator(istr), sum(0) {aggregationResult=0;};

        virtual void aggregate(int next) override {
            StreamAggregator::aggregate(next);
		    sum+=next;

            aggregationResult=sum/getNumAggregated();
	    };

};



#endif