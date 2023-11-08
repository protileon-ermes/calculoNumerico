#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;

//double funcao(double x){
//    x=pow(x,3)-9*x+3;
//    return x;
//}

//double funcaoDerivavada(double x){
//    x=pow(3*x, 2)-9;
//    return x;
//}

double funcao(double x){
    x=exp(-pow(x,2))-cos(x);
    return x;
}

double funcaoDerivavada(double x){
    x=sin(x)-2*exp(-pow(x,2));
    return x;
}

int main(){
    double x0=1.5, x1, fx, fxlinha, prec=0.01, it=100, raiz;
    int k;

    ofstream outputfile("newton.txt");
    if(outputfile.is_open()){
        fx = funcao(x0);
        if(fabs(fx)>prec){
            k=1;
            fxlinha = funcaoDerivavada(x0);
            x1=x0-(fx/fxlinha);
            fx=funcao(x1);
            while(fabs(fx)>prec && fabs(x1-x0)>prec && k <= it){
                k=k+1;
                x0=x1;
                fxlinha=funcaoDerivavada(x0);
                x1=x0-(fx/fxlinha);
                fx=funcao(x1);
            }
            raiz = x1;
        } else {
            raiz = x0;
        }
        cout << "raiz: " << raiz << endl;
        cout << "num de it: " << k << endl;
        } else {
        cerr  << "erro no arquivo" << endl;
    }
    return 0;
}
