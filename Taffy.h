/*            Taffy.h header               */

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <stack>

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cctype>

using namespace std;

#define SHORT_SIZE sizeof(short int)
#define SHORT_P(p) (short int *)(p)
#define UCHAR_P(p) (unsigned char *)(p)
#define LIN_SIZ 255

/* enum struct etc */

enum TokenKind {
    L소괄호 = '(', R소괄호 = ')', L중괄호 = '{', R중괄호 = '}', L대괄호 = '[', R대괄호 = ']',
    합 = '+', 차 = '-', 곱 = '*', 분 = '/', Mod = '%', Not = '!', Comma = ','
    If, Elif, Else, Print, Input, Exit, Ident, IntNum, String, 
};

struct Token {
    TokenKind kind;
    string text;
    double dblVal;
    Token(){kind=Others; text=""; dblVal=0.0;}
    Token(TokenKind k)      {kind=k; text=""; dblVal=0.0;}
    Token(TokenKind k, double d) {kind=k; text=""; dblVal=d;}
    Token(TokenKind k, const string& s) {kind=k; text=s; dblVal=0.0;}
    Token(TokenKind k, const string& s, double d) {kind=k; text=s; dblVal=d;}
};

enum SymKind {noId, varId, fncId, paraId};
enum DataType {NON_T, DBL_T};

struct SymTbl{
    string name;
    SymKind nmKind;
    char DataTyp;
    int aryLen;
    short args;
    int adrs;
    int frame;
    SymTbl() {clear();}
    void clear(){
        name=""; nmKind=noId; DataTyp=NON_T;
        aryLen=0; args=0; adrs=0; frame=0;
    }
};

struct Codeset{
    TokenKind kind;
    const char *text;
    double dblVal;
    int symNbr;
    int jumpAdress;
    Codeset(){clear();}
    Codeset(TokenKind k) {clear();kind=k;}
    Codeset(TokenKind k; double d) {clear();kind=k; dblVal=d;}
    Codeset(TokenKind k; const char *s) {clear();kind=k; text=s;}
    Codeset(TokenKind k, int sym, int jump) {
        clear(); kind=k; symNbr=sym; jumpAdress=jump;
    }
    void clear() {kind=Others; text=""; dblVal=0.0;jumpAdress=0; symNbr=-1;}
};

struct Tobj {
    char type;
    double d;
    string s;
    Tobj() {type = '-'; d=0.0; s="";}
    Tobj(double dt) {type ='d'; d=dt; s="";}
    Tobj(const string& st) {type='s'; d=0.0; s=st;}
    Tobj(const char *st) {type='s'; d=0.0; s=st;}
};

class Mymemory {
    private:
    vector<double> mem;
    public:
    void auto_resize(int n) {
        if (n >= (int)mem.size()) {n=(n/256 + 1)*256; mem.resize(n);}
    }
    void set(int adrs, double dt) {mem[adrs]=dt;}
    void add(int adrs, double dt) {mem[adrs] += dt;}
    double get(int adrs) {return mem[adrs];}
    int size() {return (int)mem.size();}
    void resize(unsigned int n) {mem.resize(n);}
};






