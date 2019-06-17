#ifndef PREWORK_H
#define PREWORK_H
#include<vector>
#include<string>
using namespace std;
class Prework
{
private:
    int M;
    int N;
    vector<char> new_T;
    vector<char> new_N;
    vector<vector<string> > new_Grammer;
    vector<vector<char> > first;
    vector<vector<char> > follow;
    vector<vector<string> > AT;

    bool isN(char c);
    void add_to_first(int i, int index);
    void add_first_to_first(int des, int src);
    int locate(char c);
    int locate2(char c);
    void solve_first();
    bool ok_to_add(int index, char c);
    bool can_infer_empty(int index);
    void add_to_follow(int index, string str);
    void solve_follow();
    void create_analyze_table();

public:
    Prework();
    bool isT(char c);
    vector<vector<string> > get_analyze_table();
};

#endif // PREWORK_H
