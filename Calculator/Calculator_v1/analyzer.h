#ifndef ANALYZER_H
#define ANALYZER_H
#include "wordparser.h"
#include "prework.h"
#include <QDebug>
#include <map>
class Analyzer{
    private:
        Word ahead;
        Prework pw;
        WordParser wp;
        bool flag;
        vector<vector<string> > AT;
        map<string, int> FM;
    public:
        Analyzer(){
            AT = pw.get_analyze_table();
            flag = true;
            FM["TA"] = 1;
            FM["+TA"] = 2;
            FM["-TA"] = 3;
            FM["empty"] = 4;
            FM["FB"] = 5;
            FM["*FB"] = 6;
            FM["/FB"] = 7;
            FM["MD"] = 8;
            FM["^MD"] = 9;
            FM["-M"] = 10;
            FM["i"] = 11;
            FM["(E)"] = 12;
            FM["C"] = 13;
            FM["n(E)"] = 14;
        }
        int get_function_code(int n, char c);
        double calc(string exp);
        double expr();
        double expr_();
        double term();
        double term_();
        double factor();
        double factor_();
        double power();
        double funcall(char type);
        void errorHandler();
        bool getFlag(){
            return flag;
        }
        void resetFlag(){
            flag = true;
        }
        string output_AT(){
            return AT[0][3];
        }
};

#endif // ANALYZER_H
