#include <iostream>
#include <cstring>
#include <stdlib.h>
#include "BinaryConverter.hpp"

decode_c deserialize_c(char *toRead) 
{
    decode_c data_c;
    memcpy(&data_c, (void*)&toRead, sizeof(decode_c));
    return data_c;
}

void serialize_c(char *toSend) 
{
    char *data = new char[sizeof(decode_c)];
    memcpy((void*)data, (void*)&toSend, sizeof(decode_c));
    delete data;
}

decode_s deserialize_s(char *toRead) 
{
    decode_s data_s;
    memcpy(&data_s, (void*)&toRead, sizeof(decode_s));
    return data_s;
}

void serialize_s(char *toSend) 
{
    char *data = new char[sizeof(decode_s)];
    memcpy((void*)data, (void*)&toSend, sizeof(decode_s));
    delete data;
}

static std::string toOctet(int n)
{
    std::string r;

    while(n!=0) {r=(n%2==0 ?"0":"1")+r; n/=2;}
    if (r.size() != 8) {
        while (r.size() != 8) {
            r = "0" + r;
        }
    }
    return (r);
}

static int toInt(char *str)
{
    int n = std::stoi(str);
    int r = 0;
    int base = 1;
    int temp = n;
    while (temp) {
        int lastDigit = temp % 10;
        temp = temp/10;
        r += lastDigit*base;
        base = base*2;
    }
    return (r);
}

//entrer l'input pour le coder pour le server
std::string Encode_toServ(int Vertical, int Horizontal, int Other, int ID)
{
    std::string Coded;

    Coded = toOctet(Vertical) + toOctet(Horizontal) + toOctet(Other) + toOctet(ID);
    return (Coded);
}

//entrer la structure de données pour la coder pour le client
std::string Encode_toClient(decode_s test)
{
    std::string Coded;

    int X = test.X;
    int Y = test.Y;
    int texture_Id = test.Texture_Id;
    int Value = test.Value;
    int State = test.State;
    int Id = test.Id;
    int X1 = X / 100;
    int X2 = X - (X1 * 100);
    int Y1 = Y / 100;
    int Y2 = Y - (Y1 * 100);

    Coded = toOctet(texture_Id) + toOctet(Value) + toOctet(X1) + toOctet(X2) + toOctet(Y1) + toOctet(Y2) + toOctet(State) + toOctet(Id);
    return (Coded);
}

//donne l'input au server
decode_c Decode_fromClient(std::string Binary)
{
    int a = 0;
    decode_c decoded;
    char Vertical[9];
    char Horizontal[9];
    char Other[9];
    char Id[9];

    if (Binary.size() == 32) {
        for (int b = 0; b <= 7; b++) {
            Vertical[b] = Binary[a];
            a++;
        }
        for (int b = 0; b <= 7; b++) {
            Horizontal[b] = Binary[a];
            a++;
        }
        for (int b = 0; b <= 7; b++) {
            Other[b] = Binary[a];
            a++;
        }
        for (int b = 0; b <= 7; b++) {
            Id[b] = Binary[a];
            a++;
        }
        Vertical[8] = '\0';
        Horizontal[8] = '\0';
        Other[8] = '\0';
        Id[8] = '\0';
        decoded.Vertical = toInt(Vertical);
        decoded.Horizontal = toInt(Horizontal);
        decoded.Other = toInt(Other);
        decoded.Id = toInt(Id);
    } else
        std::cerr << "Decode ERROR : Wrong size for Binary code, not 32" << std::endl;
    return (decoded);
}

//remplis la strucutre pour le client
decode_s Decode_fromServ(std::string Binary)
{
    int a = 0;
    int b = 0;
    int stockX;
    int stockY;
    decode_s decoded;
    char texture_Id[9];
    char Value[9];
    char X1[9];
    char X2[9];
    char Y1[9];
    char Y2[9];
    char State[9];
    char Id[9];

// Ne pas oublier, si la valeur de X ou de Y est ne contient que deux chiffres, il faut remplir X2 et laisser X1 vide =)

    if (Binary.size() == 64) {
        for (int b = 0; b <= 7; b++) {
            texture_Id[b] = Binary[a];
            a++;
        }
	texture_Id[9] = '\0';
        for (int b = 0; b <= 7; b++) {
            Value[b] = Binary[a];
            a++;
        }
        for (int b = 0; b <= 7; b++) {
            X1[b] = Binary[a];
            a++;
        }
        b = 0;
        while (a <= 31) {
            X2[b] = Binary[a];
            a++;
            b++;
        }
        b = 0;
        while (a <= 39) {
            Y1[b] = Binary[a];
            a++;
            b++;
        }
        b = 0;
        while (a <= 47) {
            Y2[b] = Binary[a];
            a++;
            b++;
        }
        b = 0;
        for (int b = 0; b <= 7; b++) {
            State[b] = Binary[a];
            a++;
        }
        for (int b = 0; b <= 7; b++) {
            Id[b] = Binary[a];
            a++;
        }
        stockX = toInt(X1) * 100 + toInt(X2);
        stockY = toInt(Y1) * 100 + toInt(Y2);
        decoded.Texture_Id = toInt(texture_Id);
        decoded.Value = toInt(Value);
        decoded.X = stockX;
        decoded.Y = stockY;
        decoded.State = toInt(State);
        decoded.Id = toInt(Id);
    } else
        std::cerr << "Decode ERROR : Wrong size for Binary code, not 64" << std::endl;
    return (decoded);
}
/*
int main(int ac, char **av)
{
    decode_s test;
    decode_c test2;

    std::cout << "Tests°1 - using 5" << std::endl;
    std::cout << "Int to octet : " << toOctet(5) << std::endl;
//    std::cout << "Octet to int : " << toInt("00000101") << std::endl;
    std::cout << "\nTests°2" << std::endl;
    std::cout << "Encode to serv (3 octet) : "<< Encode_toServ(1, 2, 3) << std::endl;
    std::cout << "Encode to client (7 octet) : "<< Encode_toClient(test) << std::endl;
    std::cout << std::endl;
    test2 = Decode_fromClient("00000001000000100000000100000101");
    std::cout << test2.Other << std::endl;
    test = Decode_fromServ("0000000100001110000100110001010000001010010100000000000100000010");
    std::cout << test.Texture_Id << std::endl;
    // Ne pas oublier, si la valeur de X ou de Y est ne contient que deux chiffres, il faut remplir X2 et laisser X1 vide =)
}
*/
