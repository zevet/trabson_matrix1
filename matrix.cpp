#include "matrix.h"
#include<iostream>

void Matrix::define_size(int lines, int columns) {

    _l = lines;
    _c = columns;

    _mtx = new int*[columns];

    for (int i = 0; i < lines; i++)
        _mtx[i] = new int[lines];

}

Matrix Matrix::transpose(Matrix &B)
{
    Matrix inverso;
    inverso.define_size(_c, _l);
    for(int i = 0; i < _c; i++)
        for(int j = 0; j < _l; j++)
            inverso.set(j,i,_mtx[i][j]);
    return inverso;
}
Matrix Matrix::operator+(Matrix B){
    if(equalDimension(B)){
        Matrix C;
        C.define_size(_l, _c);
        for(int i = 0; i < _l; i++)
            for(int j = 0; j < _c; j++)
                C.set(i, j, _mtx[i][j] + B.getElement(i, j));
            return C;
    }
    else
        throw  std::string("\nNao eh possivel fazer a soma.\n");
}
Matrix Matrix::operator-(Matrix B){
    if(equalDimension(B)){
        Matrix C;
        C.define_size(_l,_c);
        for(int i = 0; i < _l; i++)
            for(int j = 0; j < _c;j++)
                C.set(i, j, _mtx[i][j] - B.getElement(i, j));
        return C;
    }
    else
        throw  std::string("\nNao eh possivel fazer a subtracao.\n");
}
//Matrix Matrix::operator *(Matrix &B){
//    if(columnsA_Equal_LinesB(B)){
//        Matrix C;
//        C.define_size(_l,B.getColumn());
//        for(int i = 0; i < _l; i++)
//            for(int j = 0; i < B.getColumn();j++)
//                C.set(i,j, C.getElement(i,j) + _mtx[i][j] * B.getElement(i,j));
//        return C;
//         }
//    else
//        throw std::string("\nNao eh possivel fazer a multiplicacao.\n");

//}

bool Matrix::equalDimension(Matrix B){
    return _l == B.getLine() && _c == B.getColumn();
}
bool Matrix::columnsA_Equal_LinesB(Matrix &B){
    return _c == B.getLine();
}
bool Matrix::upperTriangular(){

    if(square()==true)
        for(int i=0; i < _l; i++)
            for(int j=0; j < i; j++)
                if(_mtx[i][j] != 0)
                    return false;
                return true;

}