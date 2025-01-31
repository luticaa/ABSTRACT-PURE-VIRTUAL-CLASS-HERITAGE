#include<iostream>//Diretriz pre-processamento fluxo entrada
#include<algorithm> //inclusão bibliotecapara função max
using namespace std; //namespace escrita codigo
#ifndef NEURONS_H //proteção para definição unica da classe
#define NEURONS_H

class NeuronBase{//declaração classe Base
    public:
        NeuronBase(){};//construtor padrão classe Base
        virtual void predict()=0;//função virtual pura classificando a classe como abstrata
        virtual ~NeuronBase(){};//destrutor virtual para a classe poderia ser puro tb se quisessemos
};
//NeuronBase::~NeuronBase(){} interessante isso aqui pois se é pura a declaração vai pra fora


class NeuronioReLU: public NeuronBase{//classe derivada
    public://membros públicos
        virtual void predict()override;//reescrevendo a assinatura inicial da pura;
        double*getInputs();//função retorna entradas
        double *getBiases();//função retorna os biases
        void setInputs(double entradas[]);//seta as entradas
        void setBiases(double biases[]);//seta os biases
        NeuronioReLU(double inputsNew [], double biasesNew[], double bia );
        //assinatura contrutor paramentado da classe derivada
        ~NeuronioReLU(){};//destrutor classe derivada, aqui temos a garantia por 
        //termos declarado o destrutor da base como virtual que este carinha vai 
        //realizar a destruição corretamente. Aqui fico na duvida se ele acaba virando 
        //virtual tb automaticamente ou se é só uma mensagem mas ok.
    private:
        double inputs[2];//membros de dados privados com os valores
        double biases[2];
        double bias;
};

void NeuronioReLU::predict(){//função predict herdada da classe Base abstrata
   double saida = max(0.0, (inputs[0] * biases[0] + inputs[1] *biases[1]) + bias);
   cout<<"A saida calculada foi: "<<saida<<endl;//exatamente como no PDF
}
NeuronioReLU::NeuronioReLU(double inputsNew [], double biasesNew[], double bia ){
    for (int i = 0; i< 2;i++){//aqui a inicialização do construtor paramentado da
    //classe derivada
        inputs[i] = inputsNew[i];
        biases[i] = biasesNew[i];
    }
    bias = bia;
}

double* NeuronioReLU::getInputs(){//função obtém entradas
    return inputs;
}
double* NeuronioReLU::getBiases(){//função obtem biases;0
    return biases;
}
void NeuronioReLU::setInputs(double entradas[]){//função para setar entradas
    for (int i = 0; i<2;i++){
                inputs[i] = entradas[i];
                }
}
void NeuronioReLU::setBiases(double newBiases[]){//função para setar os biases
    for (int i = 0; i<2;i++){
                biases[i] = newBiases[i];
                }
}

#endif //final da proteção de arquivo duplicado