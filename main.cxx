#include "neurons.h" //diretriz para inclusão nosso arquivo de classe

int main(){//main função principal
    double entradas[2] = {0.3, 2.0};// aqui são inicializados as listas com os dados
    double pesos[2]={0.2, 0.4};
    double bias = -1.5;
    NeuronBase*ptr = new NeuronioReLU(entradas, pesos, bias);
    //criamos um ponteiro alocado dinamicamente para obter as informações
    ptr->predict();//função predict para printar o OUTPUT
    delete ptr;//liberação de memoria para calcular outro valor
    ptr = nullptr;//desvinculando memoria do ponteiro
    double entradas2[2] = {0.3, 2.0}; //segundo valor de teste
    double pesos2[2]={0.2, 0.4};
    double bias2 = -0.5;
    ptr = new NeuronioReLU(entradas2, pesos2, bias2); //ponteiro realocado
    ptr->predict();//nova predição
    delete ptr;
    ptr=nullptr;
    
    return 0;
}

