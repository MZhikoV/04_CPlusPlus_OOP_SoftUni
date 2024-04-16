#ifndef SumAggregator_hhh
#define SumAggregator_hhh

#include<vector>

class SumAggregator: public StreamAggregator {

std::vector<int> numbers;

public:
    SumAggregator(std::istream& istr) : StreamAggregator(istr) {aggregationResult=0;};

    virtual void aggregate(int next) override {
		StreamAggregator::aggregate(next);
        aggregationResult+=next;
	};
};


#endif