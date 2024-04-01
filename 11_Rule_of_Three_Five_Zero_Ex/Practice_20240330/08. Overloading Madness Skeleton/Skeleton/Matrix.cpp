#include <iostream>
#include <vector>

#include "Matrix.h"


        Matrix & Matrix::operator=(const std::vector<std::vector<int>> & data) {
            
            // Matrix a;
            // size_t rows=data.size();
            // size_t cols=data[0].size();
            // this->_data.resize(rows);

            // for (size_t r=0; r<rows; r++) {
            //     this->_data[r].resize(cols);
            //     for (size_t c=0;c<cols;c++) {
            //         this->_data[r][c]=data[r][c];
            //     };
            // };

            this->_data=data;

            return *this;
        };


        Matrix & Matrix::operator+=(const Matrix & other) {
            size_t rows=other._data.size();
            size_t cols=other._data[0].size();

            for (size_t r=0; r<rows; r++) {
                for (size_t c=0;c<cols;c++) {
                    this->_data[r][c]+=other._data[r][c];
                };
            };
            return *this;
        };


        Matrix & Matrix::operator-=(const Matrix & other){
            size_t rows=other._data.size();
            size_t cols=other._data[0].size();

            for (size_t r=0; r<rows; r++) {
                for (size_t c=0;c<cols;c++) {
                    this->_data[r][c]-=other._data[r][c];
                };
            };
            return *this;
        };


        Matrix & Matrix::operator*=(const Matrix & other){
            size_t rows=other._data.size();
            size_t cols=other._data[0].size();

            for (size_t r=0; r<rows; r++) {
                for (size_t c=0;c<cols;c++) {
                    this->_data[r][c]*=other._data[r][c];
                };
            };
            return *this;
        };


        Matrix & Matrix::operator/=(const Matrix & other){
            size_t rows=other._data.size();
            size_t cols=other._data[0].size();

            for (size_t r=0; r<rows; r++) {
                for (size_t c=0;c<cols;c++) {
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
            size_t rows=matrix._data.size();
            size_t cols=matrix._data[0].size();

            for (size_t r=0; r<rows; r++) {
                for (size_t c=0;c<cols;c++) {
                    os<<matrix._data[r][c]<<' ';
                };
                os<<std::endl;
            };
            return os;  
        };


