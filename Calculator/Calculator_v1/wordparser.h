#ifndef WORDPARSER_H
#define WORDPARSER_H
#define INF 11111111111
#define END 127
#include<iostream>
#include<string>
#include<vector>
#include<cmath>
using namespace std;
struct Word{
    char type;
    double value;
};

class WordParser{
    private:
        string exp;
        int index;
        bool isfunc(string funcname);
    public:
        WordParser(string exp = "", int index = 0)
        {
            this->exp = exp;
            this->index = index;
        }
        Word getNextWord();
        int getIndex(){
            return index;
        }
        void setExp(string exp){
            this->exp = exp;
        }
        void resetIndex(){
            index = 0;
        }
};
#endif // WORDPARSER_H
