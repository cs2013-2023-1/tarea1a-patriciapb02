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
    filas= std::move(m.filas);
        columnas= std::move( m.columnas);
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
    Matriz2D m1(m.columnas,m.filas);
        for(auto i=0;i<m1.filas;i++){
            for(auto j=0;j<m1.columnas;j++){
                m1.ptr[i][j]=m.ptr[j][i];
            }
        }

       return m1;
}

std::ostream& operator<<(std::ostream& os, const Matriz2D& m){
    // Sobrecarga del operador <<
    for(size_t i=0;i<m.filas; i++){
            for(size_t j=0;j<m.columnas; j++){
                os << m.ptr[i][j] << " ";
            }os<<std::endl;
        }
        return os;
}

Matriz2D operator+(const Matriz2D& m1, const Matriz2D& m2){
    // Sobrecarga del operador +
    auto m3=m1;
        if(m1.filas == m2.filas and m1.columnas == m2.columnas){
            for(size_t i=0;i<m1.filas; i++){
                for(size_t j=0;j<m1.columnas; j++){
                    m3.ptr[i][j]+=m2.ptr[i][j];
                }
            }}
        return m3;
}

Matriz2D operator-(const Matriz2D& m1, const Matriz2D& m2){
    // Sobrecarga del operador -
    auto m3=m1;
        if(m1.filas == m2.filas and m1.columnas == m2.columnas){
            for(size_t i=0;i<m1.filas; i++){
                for(size_t j=0;j<m1.columnas; j++){
                    m3.ptr[i][j]-=m2.ptr[i][j];
                }
            }}
        return m3;
}

Matriz2D operator*(const Matriz2D& m1, const Matriz2D& m2){
    // Sobrecarga del operador *
    Matriz2D m3(m1.filas, m2.columnas);
        for(size_t i=0;i<m3.filas; i++){
            for(size_t j=0;j<m3.columnas; j++){
                float suma{};
                for(size_t k=0;k<m1.columnas; k++){
                    suma+= m1.ptr[i][k] * m2.ptr[k][j];
                }
                m3.ptr[i][j]=suma;
            }
        }
        return m3;
}

Matriz2D operator+(const Matriz2D& m, float n){
    // Sobrecarga del operador +
    auto m2=m;
        for(size_t i=0;i<m2.filas; i++){
            for(size_t j=0;j<m.columnas; j++){
                m2.ptr[i][j]+=n;
            }
        }
        return m2;
}

Matriz2D operator-(const Matriz2D& m, float n){
    // Sobrecarga del operador -
    auto m2=m;
        for(size_t i=0;i<m2.filas; i++){
            for(size_t j=0;j<m.columnas; j++){
                m2.ptr[i][j]-=n;
            }
        }
        return m2;
}

Matriz2D operator*(const Matriz2D& m, float n){
    // Sobrecarga del operador *
    auto m2=m;
        for(size_t i=0;i<m2.filas; i++){
            for(size_t j=0;j<m.columnas; j++){
                m2.ptr[i][j]*=n;
            }
        }
        return m2;
}

Matriz2D operator/(const Matriz2D& m, float n){
    // Sobrecarga del operador /
    auto m2=m;
        for(size_t i=0;i<m2.filas; i++){
            for(size_t j=0;j<m.columnas; j++){
                m2.ptr[i][j]/=n;
            }
        }
        return m2;
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
