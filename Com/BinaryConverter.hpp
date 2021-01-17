#ifndef BINARYCONVERTER_HPP_
#define BINARYCONVERTER_HPP_

typedef struct decode_s {
    int Texture_Id;
    int Value;
    int X;
    int Y;
    int State;
    int Id;
}decode_s;

typedef struct decode_c {
    int Vertical;
    int Horizontal;
    int Other;
    int Id;
}decode_c;

decode_s Decode_fromServ(std::string Binary);
decode_c Decode_fromClient(std::string Binary);
std::string Encode_toClient(decode_s test);
std::string Encode_toServ(int Vertical, int Horizontal, int Other, int ID);

template <class T>
T GetMax (T a, T b) {
    return (a > b ? a : b);
}

template <class T>
T GetMin(T x, T y) {
    return (x < y ? x : y);
}

#endif /* !BINARYCONVERTER_HPP_ */
