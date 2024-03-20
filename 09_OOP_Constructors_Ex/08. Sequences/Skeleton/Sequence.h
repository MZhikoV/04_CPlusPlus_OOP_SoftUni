#ifndef SEQUENCE_H
#define SEQUENCE_H

#include <vector>
#include <climits>

/*Sequence<T, Generator> sequence;*/

template <typename T, typename Generator> class Sequence {

    typedef std::vector<T> Data;
    Data data;
    Generator gen;

    public:

        class Iterator {
            Data & data;
            unsigned long idx;

            public:
                Iterator(Data & theData, size_t idx) : data(theData), idx(idx) {};

                static Iterator getEnd(Data & theData) {return Iterator(theData, ULONG_MAX);};
                static Iterator getBegin(Data & theData) {return Iterator(theData,0);};

                bool operator==(const Iterator & other) {

                    bool areContainersTheSame=(&data)==(&other.data);
                    bool areBothEnd= (isAtEnd() && other.isAtEnd());
                    bool areIndexesTheSame=(idx==other.idx);

                    return areContainersTheSame && (areBothEnd || areIndexesTheSame);
                };

                bool operator != (const Iterator & other) {
                    return !(*this==other);
                }

                Iterator & operator++() {
                    idx++;
                    return *this;
                }

                T & operator *() {
                    return data[idx];
                }

            private:
                bool isAtEnd() const {
                    return idx>=data.size();
                };

        };

        Sequence() {};

        void generateNext(int numberToGenerate) {
            while (numberToGenerate--){
                data.push_back(gen());
            };
        };


        //begin()->Iterator
        Iterator begin() {return Iterator::getBegin(data);};
        //end()->Iterator
        Iterator end() {return Iterator::getEnd(data);};

};



#endif