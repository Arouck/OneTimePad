#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

class OneTimePad
{
    public:
        OneTimePad() {
            key = "";
            message = "";
        }

        // Encrypts a message text, using the same
        // method One-Time Pad algorithm.
        void oneTimePadEncrypt(string message, string key)
        {
            string crypt = "";
            for (int i = 0; i < message.size(); i++)
            {
                // xor operation.
                crypt += message[i] ^ key[i];
            }

            OneTimePad::message = crypt;
        }

        // Decrypts a message text, using the same
        // method One-Time Pad algorithm.
        // void oneTimePadDecrypt(string crypt, string key)
        // {
        //     string message = "";
        //     for (int i = 0; i < key.size(); i++)
        //     {
        //         // xor operation.
        //         message += crypt[i] ^ key[i];
        //     }

        //     OneTimePad::message = message;
        // }

        // Generates a key with the given size,
        // in One-Time Pad algorithm, it is
        // the same size as the message.
        void generateKey(int size)
        {
            string key = "";
            for (int i = 0; i < size; i++)
            {
                key += static_cast<char>(rand() % 126+32);
            }
            
            OneTimePad::key = key;
        }

        string getKey() {
            return OneTimePad::key;
        }

        void setKey(string key) {
            OneTimePad::key = key;
        }

        string getMessage() {
            return OneTimePad::message;
        }

        void setMessage(string message) {
            OneTimePad::message = message;
        }


    private:
        string key;
        string message;
};