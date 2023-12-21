/********************************************************
 *      �rvore B em disco                               *
 *                                                      *
 * Autores:   Kaio L�zaro Silva de Ara�jo               *
 *                                                      *
 *                                                      *
 ********************************************************/
#include <iostream>
#include "tree.h"
#include "charSerial.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "Portuguese");

    // Arrays de caracteres para inser��o e remo��o
    charSerial inserting[] = {'u', '<', 'd', 'e', 'i', '{', '!', 'X', '.', '4', 'r', 'J', '#', 'B', '7', 'x', ',', '?', '9', ';', 'Q', '8', 'I', 'P', 'C'};
    charSerial removing[] = {'4', 'r', '#', ',', 'i', '<', 'e', '8', '9', 'C', '!', 'P'};

    // Cria��o da �rvore B
    tree<charSerial, 3> tree("Data","char", 1);
    node<charSerial, 3> n;
    int option;
    char k;
    bool quit = false;

    do {
        // Menu principal
        cout << "\n==========================================================";
        cout << "\n*             �rvore B em disco                          *";
        cout << "\n*                                                        *";
        cout << "\n*  Autores:  Kaio L�zaro Silva de Ara�jo                 *";
        cout << "\n*            Andr� Dias Neto                             *";
        cout << "\n*            Felipe Soares Barbosa                       *";
        cout << "\n==========================================================";
        cout << "\n==========================================================";
        cout << "\n*                   MENU                                 *";
        cout << "\n==========================================================";
        cout << "\n* 1 -        Inserir uma chave de caractere              *";
        cout << "\n* 2 -        Remover uma chave de caractere              *";
        cout << "\n* 3 -        Buscar por uma chave                        *";
        cout << "\n* 4 -        Imprimir a �rvore                           *";
        cout << "\n* 5 -        Executar testes padronizados                *";
        cout << "\n* 6 -        Sair                                        *";
        cout << "\n==========================================================";
        cout << "\n> ";
        cin >> option;

        // Switch para as op��es do menu
        switch(option) {
        case 1:
            // Inser��o de uma chave de caractere
            cout << "\nInforme um valor de caractere para inserir: ";
            cin >> k;
            tree.insert(k);
            break;
        case 2:
            // Remo��o de uma chave de caractere
            cout << "\nInforme um valor de caractere para remover: ";
            cin >> k;
            tree.remove(k);
            break;
        case 3:
            // Busca por uma chave de caractere
            cout << "\nInforme um valor de caractere para buscar: ";
            cin >> k;
            if(tree.search(n, k) >= 0) {
                cout << "\nO caractere "<< k << " foi encontrado na �rvore.\n";
            } else {
                cout << "\nO caractere " << k << " n�o foi encontrado na �rvore.\n";
            }
            break;
        case 4:
            // Impress�o da �rvore B
            tree.print();
            break;
        case 5:
            // Execu��o de testes padronizados
            cout << "\nTestes de Inser��o" << endl;
            for(charSerial i : inserting) {
                cout << "\t\n- Inserindo o caractere " << i.getCharacter() << ":\n" << endl;
                tree.insert(i);
                cout << endl;
                cout << endl;
                tree.print();
                cout << endl;
            }
            cout << "\nTestes de Remo��o"  << endl;
            for (charSerial i : removing) {
                cout << "\t\n- Removendo o caractere " << i.getCharacter() << ":\n" << endl;
                tree.remove(i);
                cout << endl;
                cout << endl;
                tree.print();
                cout << endl;
            }
            break;
        case 6:
            // Encerra o programa
            quit = true;
            break;
        default:
            // Mensagem para op��o inv�lida
            cout << "\nOp��o inv�lida. Por favor, tente novamente.\n" << endl;
            break;
        }
    } while(!quit);

    return 0;
}
