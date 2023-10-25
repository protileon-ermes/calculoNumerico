#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;

//float funcao(float x){
//    x = exp(-pow(x, 2)) - cos(x);
//    return x;
//}
float funcao(float x){
    x = pow(x,3)-9*x+3;
    return x;
}

//float fi(float x){
//    x = cos(x) - exp(-pow(x, 2)) + x;
//    return x;
//}
float fi(float x){
    x = pow(x,3)/9.0 + 1.0/3.0;
    return x;
}

int main(){
    float x0=0.5, x1, precisao=0.0005, it=100, E;
    int k;
    ofstream outputfile("milErmindo.txt");
    if(outputfile.is_open()){
        if(fabs(funcao(x0)) < precisao){
            E = x0;
            cout << "x: " << E << endl;
        } else {
            k = 1;
            while(k < it){
                x1 = fi(x0);
                if(fabs(funcao(x1))<precisao || fabs(x1-x0) < precisao || k>it){
                    E=x1;
                    cout << "x" << k << ": " << E << endl;
                    break;
                } else {
                    x0=x1;
                    cout << "x" << k << ": " << x0 << endl;
                    k=k+1;
                }
            }
        }
        cout << "numero de interações: " << k << endl;
    } else {
        cerr  << "erro no arquivo" << endl;
    }
    return 0;
}