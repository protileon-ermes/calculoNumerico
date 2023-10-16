#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;

double funcao(double x){
    int r;
    r=pow(x, 3)-10;
    return r;
}


int main(){
    double a=2, b=3, raiz;
    double prec=0.1, x, finicio, meio, fmeio;
    int n;
    int k=0;
    ofstream outputfile("bisscecçãoErmindo.txt");
    if(outputfile.is_open()){
        if(fabs(b-a)<prec){
            x = a;
        }
        else{
            while(fabs(b-a)>prec && k<n){
                k++;
                finicio = funcao(a);
                meio = (a+b)/2;
                fmeio = funcao(meio);
                outputfile << "interação: " << k << ":\t a =" << "\t b= " << b << "\t meio= " << meio << "\t k = " << k <<endl;
                if (finicio*fmeio<0){
                    b = meio;
                    raiz = b;
                }
                else{
                    a = meio;
                    raiz = a;
                }
            }
        }
    cout << "raiz: " << raiz << endl;
    cout << "num de int: " << k;
    }else{
        cerr << "erro no arquivo" << endl;
    }
    return 0;
}
