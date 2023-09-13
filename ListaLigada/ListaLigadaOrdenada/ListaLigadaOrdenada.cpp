#include <iostream>    
    #include <cstdio>    
    using namespace std;    
  
    // definicao de tipo    
    struct NO {    
            int valor;    
            NO* prox;    
    };    
  
    NO* primeiro = NULL;    
    NO* MeioDaLista = NULL; 
    int quantidade = 0; 
    int Soma = 0; 
    float Media;
  
    // headers    
    void menu();    
    void inicializar();    
    void exibirQuantidadeElementos();    
    void exibirElementos();    
    void inserirElemento();    
    void excluirElemento();    
    void buscarElemento();    
    NO* posicaoElemento(int numero);    
    //--------------------------    
  
  
    int main()    
    {    
            menu();    
    }    
  
    void menu()    
    {    
            int op = 0;    
            while (op != 7) {    
                    system("clear"); // somente no windows    
                    cout << "Menu Lista Ligada";    
                    cout << endl << endl;    
                    cout << "1 - Inicializar Lista \n";    
                    cout << "2 - Exibir quantidade de elementos \n";    
                    cout << "3 - Exibir elementos \n";    
                    cout << "4 - Buscar elemento \n";    
                    cout << "5 - Inserir elemento \n";    
                    cout << "6 - Excluir elemento \n";    
                    cout << "7 - Sair \n\n";    
  
                    cout << "Opcao: ";    
                    cin >> op;    
  
                    switch (op)    
                    {    
                    case 1: inicializar();    
                            break;    
                    case 2: exibirQuantidadeElementos();    
                            break;    
                    case 3: exibirElementos();    
                            break;    
                    case 4: buscarElemento();    
                            break;    
                    case 5: inserirElemento();    
                            break;    
                    case 6: excluirElemento();    
                            break;    
                    case 7:    
                            return;    
                    default:    
                            break;    
                    }    
                    getchar();    
            }    
    }    
  
  
    void inicializar()    
    {    
            // se a lista já possuir elementos    
    // libera a memoria ocupada    
            NO* aux = primeiro;    
            while (aux != NULL) {    
                    NO* paraExcluir = aux;    
                    aux = aux->prox;    
                    free(paraExcluir);    
            }    
  
            primeiro = NULL;    
            cout << "Lista inicializada \n";    
            cout << "\nPressione ENTER para continuar\n";    
            getchar();    
  
    }    
  
    void exibirQuantidadeElementos() {    
  
            int nElementos = 0;    
            NO* aux = primeiro;    
            while (aux != NULL) {    
                    nElementos++;    
                    aux = aux->prox;    
            }    
            cout << "Quantidade de elementos: " << nElementos << endl;    
  
    }    
  
    void exibirElementos()    
    {    
            if (primeiro == NULL) {    
                    cout << "Lista vazia \n";    
                    cout << "\nPressione ENTER para continuar\n";    
                    getchar();    
                    return;    
            }    
            else {    
                    cout << "Elementos: \n";    
                    NO* aux = primeiro;    
                    while (aux != NULL) {    
                            cout << aux->valor << endl;    
                            aux = aux->prox;    
                    }    
                    cout << "\nPressione ENTER para continuar\n";    
                    getchar();    
            }    
    }    
  
    void inserirElemento()    
    {    
        int ValNum;    
        cout << "Digite o elemento: ";    
        cin >> ValNum;    
        bool Inseriu=false;    
            // aloca memoria dinamicamente para o novo elemento    
        if(posicaoElemento(ValNum)==NULL){    
  
                NO* novo = (NO*)malloc(sizeof(NO));    
                bool PrimeiraVez=true;    
                /*if (novo == NULL)    
                {    
                        return;    
                }*/    
                novo->valor=ValNum;    
                novo->prox = NULL;    
                NO* ValorAtual=primeiro;    
                NO* Anterior; 
                if(primeiro==NULL){ 
                    primeiro=novo; 
                } 
                else{ 
                    while(ValorAtual!=NULL){ 
                        if(PrimeiraVez){ 
                            if(novo->valor>ValorAtual->valor){ 
                                novo->prox=ValorAtual; 
                                primeiro=novo; 
                                Inseriu=true; 
                            } 
                            else{ 
                                if(ValorAtual->prox==NULL){ 
                                    ValorAtual->prox=novo; 
                                    Inseriu=true; 
                                } 
                                Anterior=ValorAtual; 
                            } 
                            PrimeiraVez=false; 
                        } 
                        else{ 
                            if(novo->valor>ValorAtual->valor){ 
                                Anterior->prox=novo; 
                                novo->prox=ValorAtual; 
                                Inseriu=true; 
                            } 
                            else{ 
                                  if(ValorAtual->prox==NULL){ 
                                    ValorAtual->prox=novo; 
                                    Inseriu=true; 
                                } 
                            } 
                        } 
                        if(Inseriu){ 
                            break; 
                        } 
                        ValorAtual=ValorAtual->prox; 
                    } 
                } 
                cout <<"Valor inserido \n";  
                quantidade++;
                Soma = Soma + novo->valor; 
                Media = Soma/quantidade;
                if(quantidade>=3){
                    ValorAtual=primeiro;
                    while(ValorAtual!=NULL){
                        if(ValorAtual->valor>Media){
                            MeioDaLista=Anterior;
                            break;
                        }
                        else{
                            Anterior=ValorAtual;
                        }
                        ValorAtual=ValorAtual->prox;
                    }
                }
                cout << "\nPressione ENTER para continuar\n";    
                getchar();    
        }    
        else{    
            cout << "Esse valor ja esta na lista";    
            cout << "\nPressione ENTER para continuar\n";    
            getchar();    
        }    
  
    }    
  
    void excluirElemento(){
        int NumExc;
    }
    
    void Apagador(NO* ValorInicial,int NumExc){
        NO* ValorAtual = ValorInicial;
        NO* Anterior;
        bool PrimeiraVez= true;
        bool apagou = false;
        while(ValorAtual!=NULL){
            if(PrimeiraVez){
                if(ValorAtual->valor==NumExc){
                    primeiro=ValorAtual->prox;
                    cout<<"\nValor excluido\n";
                    free(ValorAtual);
                    apagou= true;
                }
                else{
                    if(ValorAtual->prox==NULL){
                        cout<<"\nValor nao encontrado\n";
                    }
                    Anterior=ValorAtual;
                }
                PrimeiraVez=false;
            }
            else{
                if(ValorAtual->valor==NumExc){
                    Anterior->prox=ValorAtual->prox;
                    cout<<"\nValor excluido\n";
                    free(ValorAtual);
                    apagou=true;
                }
                else{
                    Anterior=ValorAtual;
                    if(ValorAtual->prox==NULL){
                        cout<<"\nValor nao encontrado\n";
                    }
                }
            }
            if(apagou){
                break;
            }
            ValorAtual=ValorAtual->prox;
        }
        getchar();
    }
  
    void buscarElemento(){    
  
    }   
  
  
    NO* posicaoElemento(int numero)  {      
              NO* aux = primeiro;      
              while (aux != NULL) {      
                      if (aux->valor == numero)      
                      {      
                              break;      
                      }      
                      aux = aux->prox;      
              }      
              return aux;      
    }