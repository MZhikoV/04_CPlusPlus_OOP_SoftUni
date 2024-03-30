

#include <iostream>
#include <vector>

#include "Matrix.h"

class Matrix
{
    public:
        Matrix() = default;
        ~Matrix() = default;

        Matrix & Matrix::operator=(const std::vector<std::vector<int>> & data);
        Matrix & Matrix::operator+=(const Matrix & other);
        Matrix & Matrix::operator-=(const Matrix & other);
        Matrix & Matrix::operator*=(const Matrix & other);
        Matrix & Matrix::operator/=(const Matrix & other);

        friend std::ostream & Matrix::operator<<(std::ostream & os,
                                         const Matrix & matrix);

    private:
        std::vector<std::vector<int>> _data;
};

#endif /* MATRIX_H_ */
