#include "analyzer.h"

double Analyzer::calc(string exp){
//    qDebug() << QString::fromStdString(AT[5][END]) << endl;
    wp.resetIndex();
    wp.setExp(exp);
    ahead = wp.getNextWord();
    return expr();
}

int Analyzer::get_function_code(int n, char c)
{

    if(c == 's' || c == 'c' || c == 't' || c == 'l')
        c = 'n';
    if(c == 'd')
        c = 'i';
//    qDebug() << "c" << c << "n" << n << "AT" << QString::fromStdString(AT[n][c]) << endl;
    if( !(pw.isT(c)||c==END) || AT[n][c] == " ")
        return -1;
    return FM[AT[n][c]];
}

double Analyzer::expr() {
    int code = get_function_code(0,ahead.type);
//    qDebug() << "expr  " << code << endl;
    if(code == 1)
        return term() + expr_();
    else{
        errorHandler();
            return 0;
    }
}

double Analyzer::expr_()
{
    char type = ahead.type;
    int code = get_function_code(1,type);
//    qDebug() << "expr_  " << code << 't' << (int)type << endl;
    if(code == 4)
        return 0;
    else if(code == 2){
        ahead = wp.getNextWord();
        return term() + expr_();
    }
    else if(code == 3){
        ahead = wp.getNextWord();
        return -term() + expr_();
    }
    else{
        errorHandler();
            return 0;
    }
}

double Analyzer::term() {
    int code = get_function_code(2,ahead.type);
    if(code == 5)
        return factor() * term_();
    else{
        errorHandler();
            return 0;
    }
}

double Analyzer::term_() {
    char type = ahead.type;
    double temp;
    int code = get_function_code(3,ahead.type);
    if(code == 4)
        return 1;
    else if(code == 6){
        ahead = wp.getNextWord();
        return factor() * term_();
    }
    else if(code == 7){
        ahead = wp.getNextWord();
        temp = factor();
        if(temp == 0){
            errorHandler();
            return 1;
        }
        else
            return 1 / temp * term_();
    }
    else{
        errorHandler();
            return 1;
    }
}

double Analyzer::factor(){
    double a,b;
    int code = get_function_code(4,ahead.type);
    if(code == 8){
        a = power();
        b = factor_();
        if(a == 0 && b == 0){
            errorHandler();
            return 0;
        }
        else
        return pow(a,b);
    }
    else{
        errorHandler();
            return 0;
    }
}

double Analyzer::factor_(){
    char type = ahead.type;
    int code = get_function_code(5,type);
    double a,b;
    if(code == 4){
        return 1;
    }
    else if(code == 9){
        ahead = wp.getNextWord();
        a = power();
        b = factor_();
        if(a == 0 && b == 0){
            errorHandler();
            return 0;
        }
        else
        return pow(a,b);
    }
    else{
        errorHandler();
            return 1;
    }
}

double Analyzer::power(){
    // cout << "power()" << endl;
    char type = ahead.type;
    int code = get_function_code(6,type);
    double value = ahead.value;
    if (type != END)
        ahead = wp.getNextWord();
    if(code == 11)
        return value;
    else if(code == 12){
        value = expr();
        ahead = wp.getNextWord();
        return value;
    }
    else if(code == 10){
        return -power();
    }
    else if(code == 13){
        return funcall(type);
    }
    else{
        errorHandler();
            return 0;
    }
}

double Analyzer::funcall(char functype){
    char type = ahead.type;
    if(type == '('){
        ahead = wp.getNextWord();
        double value;
        switch(functype){
            case 's':
                value =  sin(expr());
                ahead = wp.getNextWord();
                return value;
            case 'c':
                value =  cos(expr());
                ahead = wp.getNextWord();
                return value;
            case 't':
                value =  tan(expr());
                ahead = wp.getNextWord();
                return value;
            case 'l':
                value =  log10(expr());
                ahead = wp.getNextWord();
                return value;
        }
    }
    else{
        errorHandler();
        return 0;
    }
}

void Analyzer::errorHandler(){
    flag = false;
}


