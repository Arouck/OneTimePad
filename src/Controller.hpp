#include "OneTimePad.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Controller
{

public:
    Controller()
    {
        option = 0;
        crypt = 0;
    }

    void printMainMenu()
    {
        if(crypt == 0) {
            cout << "###########################################################" << endl;
        cout << "Escolha uma das opcoes abaixo:\n\t1) Encriptar mensagem.\n\t2) Sair do programa." << endl;
        cout << "###########################################################" << endl;
        } else {
            cout << "###########################################################" << endl;
        cout << "Escolha uma das opcoes abaixo:\n\t1) Decriptar menssagem.\n\t2) Sair do programa." << endl;
        cout << "###########################################################" << endl;
        }
        
    }

    void encrypt()
    {
        if (crypt == 1)
        {
            cout << "Nao e possivel encriptar uma mensagem sem antes decriptar a que ja esta encriptada." << endl;
        }
        else
        {
            string temp = "";

            cout << "Escreva a mensagem que deseja encriptar: ";

            while(temp == "") {
                getline(cin, temp);
            }

            oneTimePad.setMessage(temp);
            cout << endl;
            oneTimePad.generateKey(oneTimePad.getMessage().size());

            while (find(used_keys.begin(), used_keys.end(), oneTimePad.getKey()) != used_keys.end())
            {
                oneTimePad.generateKey(oneTimePad.getMessage().size());
            }

            used_keys.push_back(oneTimePad.getKey());

            oneTimePad.oneTimePadEncrypt(oneTimePad.getMessage(), oneTimePad.getKey());

            cout << "Sua mensagem foi encriptada com sucesso." << endl;

            cout << "Menssagem encriptada: " << oneTimePad.getMessage() << "\tChave: " <<
                oneTimePad.getKey() << endl << endl;
            crypt = 1;
        }
    }

    void decrypt()
    {
        if(crypt == 0) {
            cout << "Nao e possivel decriptar uma menssagem vazia." << endl;
        } else {
            oneTimePad.oneTimePadEncrypt(oneTimePad.getMessage(), oneTimePad.getKey());

            cout << "Sua mensagem foi decriptada com sucesso." << endl;

            cout << "Menssagem decriptada: " << oneTimePad.getMessage() << "\tChave: " <<
                oneTimePad.getKey() << endl << endl;
            crypt = 0;
        }
    }

    void options() {
        if(option == 1 && crypt == 0) {
            encrypt();
        } else if(option == 1 && crypt == 1) {
            decrypt();
        }
    }

    int getOption()
    {
        return Controller::option;
    }

    void setOption(int option)
    {
        Controller::option = option;
    }

    vector<string> getUsed_keys()
    {
        return Controller::used_keys;
    }

    void setUsed_keys(vector<string> used_keys)
    {
        Controller::used_keys = used_keys;
    }

    int getCrypt()
    {
        return Controller::crypt;
    }

    void setCrypt(int crypt)
    {
        Controller::crypt = crypt;
    }

private:
    int option;
    vector<string> used_keys;
    OneTimePad oneTimePad;
    int crypt;
};