#ifndef TypedStream_h
#define TypedStream_h

#include <vector>
#include <sstream>

template <typename T> class TypedStream {


protected:
    std::istringstream stream;

public:
    TypedStream(const std::string & input): stream(input) {};


    virtual TypedStream <T> & operator>>( T & i)=0;
        //  {
        // 	this->stream >> i;
        // 	return *this;
        // };

    std::vector<T> readToEnd() {
        T curr;
        std::vector<T> result;
        while (true) {
            *this>>curr;
            if ((bool)stream==false) {
                break;
            };
            result.push_back(curr);
        };
        return result;
    };

    // std::string readToEnd() {
    //     std::ostringstream ostr;
    //     std::string buff;
    //     while (stream>>buff) {

    //     }
    // }




};


#endif