#include "wordparser.h"
bool WordParser::isfunc(string funcname){
    vector<string> f;
    f.push_back("sin");
    f.push_back("cos");
    f.push_back("tan");
    f.push_back("log");
    f.push_back("pow");
    if(find(f.begin(), f.end(), funcname) != f.end())
        return true;
    return false;
}

Word WordParser::getNextWord(){
    Word res;
    res.type = END;
    res.value = INF;
    if(index >= exp.size())
        return res;
    char now = exp[index];
    if(isdigit(now) || now == '.'){
        for(res.value = 0; isdigit(now); now = exp[++index])
            res.value = 10 * res.value + (now - '0');
        if(now == '.'){
            double decplace = 1;
            now = exp[++index];
            while(isdigit(now)){
                res.value = res.value + (now - '0') * (decplace /= 10);
                now = exp[++index];
            }
        }
        res.type = 'd';
        return res;
    }
    if(isalpha(now)){
        char name = now;
        string funcname;
        while(isalpha(now)){
            funcname.push_back(now);
            now = exp[++index];
          }
        if(isfunc(funcname))
        res.type = name;
        else
        res.type = 'x';
        return res;
    }
    res.type = now;
    // cout << "parse: " << (int)now << endl;
    index++;
    return res;
}
