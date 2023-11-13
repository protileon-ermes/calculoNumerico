#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;

double funcao(double x){
    x = pow(x,2)+x-6;
    return x;
}

int main(){
    double x0=1.5, x1=1.7, x2, prec=0.003, it=100, e, k=1;

    ofstream outputfile("secanteErmnindo.txt");
    if(outputfile.is_open()){
        if(fabs(funcao(x0))<prec){
            e = x0;
        }
        if(fabs(funcao(x1))<prec || fabs(x1-x0)<prec){
            e=x1;
        } else {
        while(fabs(funcao(x1))>prec && fabs(x1-x0)>prec){
            x2=x1- (funcao(x1)*(x1-x0))/(funcao(x1)-funcao(x0));
            if(fabs(funcao(x2))<prec || fabs(x1-x0)<prec || k > it){
                e = x2;
                break;
                }
            x0=x1;
            x1=x2;
            k=k+1;
        }
        outputfile << "maior coeficiente: " << e << endl;
        outputfile << "numero de interacoes: " << k << endl;
        }
    } else {
        cerr  << "erro no arquivo" << endl;
    }
    return 0;
}