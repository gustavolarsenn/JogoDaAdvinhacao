#include <iostream>
#include <ctime>
#include <cstdlib>
#include <locale.h>

using namespace std;

int main(void){

    cout << "*************************************" << endl;
    cout << "* Bem-vindos ao jogo da advinhacao! *" << endl;
    cout << "*************************************" << endl;

    cout << "Escolha a dificuldade: " << endl;
    cout << "Facil (F), Medio (M) ou Dificil (D)" << endl;

    char dificuldade;
    cin >> dificuldade;

    int numeroTentativas;
    
    if(dificuldade == 'F'){
        numeroTentativas = 15;
    } else if(dificuldade == 'M'){
        numeroTentativas = 10;
    } else {
        numeroTentativas = 5;
    }

    srand(time(NULL));
    const int NUMERO_SECRETO = rand() % 100;
    bool naoAcertou = true;

    int tentativas; 

    double pontos = 1000;


   for(tentativas = 1; tentativas <= numeroTentativas; tentativas++){
        
        int chute;
        cout << "Tentiva: " << tentativas << endl;
        cout << "Qual o seu chute? ";

        cin >> chute;

        double pontosPerdidos = abs(chute - NUMERO_SECRETO)/2.0;
        pontos = pontos - pontosPerdidos;

        system("cls");

        cout << "O valor do seu chute e " << chute << endl;

        bool acertou = chute == NUMERO_SECRETO;
        bool menor = chute < NUMERO_SECRETO;

        if(acertou){
            cout << "Parabens, voce acertou o numero secreto!" << endl << endl;
            naoAcertou = false;
            break;
        } else if(menor){
            cout << "O chute foi menor do que o numero secreto!" << endl << endl;
        } else {
            cout << "O chute foi maior do que o numero secreto!" << endl << endl;
        }

   }
    
    cout << "Fim do jogo!" << endl;
    if(naoAcertou){
        cout << "Voce perdeu! Tente novamente!" << endl;
        cout << "O numero secreto era: " << NUMERO_SECRETO << endl;
    } else {
        cout << "Voce acertou o numero secreto em " << tentativas << " tentativas!" << endl;
        cout.precision(2);
        cout << fixed;
        cout << "Sua pontuacao foi de " << pontos << " pontos!" << endl;
    }
}