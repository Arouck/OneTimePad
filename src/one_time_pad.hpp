#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

// Encrypts a message text, using the same
// method One-Time Pad algorithm.
string oneTimePad(string message, string key)
{
    string crypt = "";
    for (int i = 0; i < message.size(); i++)
    {
        // xor operation.
        crypt += message[i] ^ key[i];
    }

    return crypt;
}

// Decrypts a message text, using the same
// method One-Time Pad algorithm.
string oneTimePadReverse(string crypt, string key)
{
    string message = "";
    for (int i = 0; i < key.size(); i++)
    {
        // xor operation.
        message += crypt[i] ^ key[i];
    }

    return message;
}

// Generates a key with the given size,
// in One-Time Pad algorithm, it is
// the same size as the message.
string generateKey(int size)
{
    string key = "";
    for (int i = 0; i < size; i++)
    {
        key += static_cast<char>(rand() % 128);
    }
    return key;
}