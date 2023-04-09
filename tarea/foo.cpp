#include "foo.h"

Matriz2D::Matriz2D(){
    // Constructor por defecto
    filas=3;
    columnas=3;
    ptr=new float*[filas];
    for(size_t i=0; i < filas; i++){
            ptr[i]=new float [columnas];
            for(size_t j=0; j < columnas; j++){
                ptr[i][j]= float(rand() % 10001) / 10000;
            }}
}

Matriz2D::Matriz2D(int n){
    // Constructor con un parametro
    filas= columnas=n;
        ptr=new float*[filas];
        for(size_t i=0; i < filas; i++){
            ptr[i]=new float [columnas];
            for(size_t j=0; j < columnas; j++){
                ptr[i][j]= float(rand() % 10001) / 10000;
            }}
}

Matriz2D::Matriz2D(int n, int m){
    // Constructor con dos parametros
    filas=n;
        columnas=m;
        ptr=new float*[filas];
        for(size_t i=0; i < filas; i++){
            ptr[i]=new float [columnas];
            for(size_t j=0; j < columnas; j++){
                ptr[i][j]= float(rand() % 10001) / 10000;
            }}
}

Matriz2D::Matriz2D(const Matriz2D& m){
    // Constructor de copia
    filas= m.filas;
        columnas= m.columnas;
        ptr=new float *[filas];
        for(size_t i=0; i < filas; i++){
            ptr[i]=new float [columnas];
            for(size_t j=0; j < columnas; j++){
                ptr[i][j]=m.ptr[i][j];
            }
        }
}

Matriz2D::Matriz2D(Matriz2D&& m){
    // Constructor de movimiento
    filas= move(m.filas);
        columnas= move( m.columnas);
        ptr=new float *[filas];
        for(size_t i=0; i < filas; i++){
            ptr[i]=new float [columnas];
            for(size_t j=0; j < columnas; j++){
                ptr[i][j]=m.ptr[i][j];
            }
        }
}

Matriz2D t(Matriz2D& m){
    // Transpuesta de una matriz
}

std::ostream& operator<<(std::ostream& os, const Matriz2D& m){
    // Sobrecarga del operador <<
}

Matriz2D operator+(const Matriz2D& m1, const Matriz2D& m2){
    // Sobrecarga del operador +
}

Matriz2D operator-(const Matriz2D& m1, const Matriz2D& m2){
    // Sobrecarga del operador -
}

Matriz2D operator*(const Matriz2D& m1, const Matriz2D& m2){
    // Sobrecarga del operador *
}

Matriz2D operator+(const Matriz2D& m, float n){
    // Sobrecarga del operador +
}

Matriz2D operator-(const Matriz2D& m, float n){
    // Sobrecarga del operador -
}

Matriz2D operator*(const Matriz2D& m, float n){
    // Sobrecarga del operador *
}

Matriz2D operator/(const Matriz2D& m, float n){
    // Sobrecarga del operador /
}

float Matriz2D::get(int i, int j){
    return ptr[i][j];
}

int Matriz2D::getFilas(){
    return filas;
}

int Matriz2D::getColumnas(){
    return columnas;
}
