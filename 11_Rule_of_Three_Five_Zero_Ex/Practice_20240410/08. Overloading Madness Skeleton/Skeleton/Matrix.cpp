#include "Matrix.h"

#include <sstream>
#include <string>

// class Matrix
// {
//     public:
        //Matrix::Matrix() = default;
        //Matrix::~Matrix() = default;

        Matrix & Matrix::operator=(const std::vector<std::vector<int>> & data) {

            this->_data=data;
            return *this;
        };

        Matrix & Matrix::operator+=(const Matrix & other) {

            for (size_t r=0; r<other._data.size(); r++) {
                for (size_t c=0; c<other._data.size(); c++) {
                    this->_data[r][c]+=other._data[r][c];
                };
            };
            return *this;
        };

        Matrix & Matrix::operator-=(const Matrix & other) {

            for (size_t r=0; r<other._data.size(); r++) {
                for (size_t c=0; c<other._data.size(); c++) {
                    this->_data[r][c]-=other._data[r][c];
                };
            };
            return *this;
        };

        Matrix & Matrix::operator*=(const Matrix & other) {

            for (size_t r=0; r<other._data.size(); r++) {
                for (size_t c=0; c<other._data.size(); c++) {
                    this->_data[r][c]*=other._data[r][c];
                };
            };
            return *this;
        };

        Matrix & Matrix::operator/=(const Matrix & other){

            for (size_t r=0; r<other._data.size(); r++) {
                for (size_t c=0; c<other._data.size(); c++) {
                    if (other._data[r][c]!=0) {
                    this->_data[r][c]/=other._data[r][c];
                    }
                    else {
                        this->_data[r][c]=0;
                    };
                };
            };
            return *this;
        };

        //friend 
        std::ostream & operator<<(std::ostream & os, const Matrix & matrix) {
            std::ostringstream ostr;
            for (size_t r=0; r<matrix._data.size(); r++) {
                bool isFirst=true;
                for (size_t c=0; c<matrix._data.size(); c++) {
                    if (isFirst) {
                        isFirst=false;
                    }
                    else {
                        ostr<<' ';
                    }
                    ostr<<matrix._data[r][c];
                };
                ostr<<std::endl;
            };
            return os<<ostr.str();
        };
    // private:
    //     std::vector<std::vector<int>> _data;