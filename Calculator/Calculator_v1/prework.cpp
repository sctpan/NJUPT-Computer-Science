#include "prework.h"

Prework::Prework()
{
    N = 8;
    M = 9;
    new_Grammer.resize(50, vector<string>());
    first.resize(30, vector<char>());
    follow.resize(30, vector<char>());
    AT.resize(30, vector<string>());
    char VT[9] = {'(',')','+','-','*','/','^','i','n'};
    char VN[8] = {'E','A','T','B','F','D','M','C'};
    new_Grammer[0].push_back("TA");
    new_Grammer[1].push_back("+TA");
    new_Grammer[1].push_back("-TA");
    new_Grammer[1].push_back("empty");
    new_Grammer[2].push_back("FB");
    new_Grammer[3].push_back("*FB");
    new_Grammer[3].push_back("/FB");
    new_Grammer[3].push_back("empty");
    new_Grammer[4].push_back("MD");
    new_Grammer[5].push_back("^MD");
    new_Grammer[5].push_back("empty");
    new_Grammer[6].push_back("-M");
    new_Grammer[6].push_back("i");
    new_Grammer[6].push_back("(E)");
    new_Grammer[6].push_back("C");
    new_Grammer[7].push_back("n(E)");
    for(int i=0; i<M; i++)
    new_T.push_back(VT[i]);
    for(int i=0; i<N; i++)
    new_N.push_back(VN[i]);
    for(int i=0; i<3*N; i++)
    {
        for(int j=0; j<3*M; j++)
        AT[i].push_back(" ");
    }
}

bool Prework::isT(char c)
{
    if(find(new_T.begin(), new_T.end(), c) != new_T.end())
    return true;
    return false;
}

bool Prework::isN(char c)
{
    if(find(new_N.begin(), new_N.end(), c) != new_N.end())
    return true;
    return false;
}

void Prework::add_to_first(int i, int index)
{
    for(int j=0; j<new_Grammer[i].size(); j++)
    {
        if(isT(new_Grammer[i][j][0]))
            first[index].push_back(new_Grammer[i][j][0]);
        else if(new_Grammer[i][j] == "empty")
            first[index].push_back('e');
    }
}

void Prework::add_first_to_first(int des, int src)
{
    for(int i=0; i<first[src].size(); i++)
    {
        if(find(first[des].begin(), first[des].end(), first[src][i]) == first[des].end()
            && first[src][i] != 'e')
        first[des].push_back(first[src][i]);
    }
}

int Prework::locate(char c)
{
    for(int i=0; i<new_N.size(); i++)
    if(new_N[i] == c)
    return i;
}

int Prework::locate2(char c)
{
    for(int i=0; i<new_T.size(); i++)
    if(new_T[i] == c)
    return i;
    return new_T.size();
}

void Prework::solve_first()
{
    int n_num = new_N.size();
    for(int i=0; i<n_num; i++)
        add_to_first(i,i);
    for(int cnt=0; cnt<N; cnt++)
    {
        for(int i=0; i<N; i++)
        {
            for(int j=0; j<new_Grammer[i].size(); j++)
            {
                if(isN(new_Grammer[i][j][0]))
                    add_first_to_first(i, locate(new_Grammer[i][j][0]));
            }
        }
    }
}

bool Prework::ok_to_add(int index, char c)
{
    if(find(follow[index].begin(), follow[index].end(), c) == follow[index].end() && c!='e')
    return true;
    return false;
}

bool Prework::can_infer_empty(int index)
{
    for(int i=0; i<new_Grammer[index].size(); i++)
    {
        if(new_Grammer[index][i] == "empty")
        return true;
    }
    return false;
}

void Prework::add_to_follow(int index, string str)
{
    for(int i=0; i<str.size()-1; i++)
    {
        if(isN(str[i]) && isT(str[i+1]) && ok_to_add(locate(str[i]),str[i+1]))
            follow[locate(str[i])].push_back(str[i+1]);
        else if(isN(str[i]) && isN(str[i+1]) && follow[locate(str[i+1])].size() != 0)
        {
            for(int j=0; j<first[locate(str[i+1])].size(); j++)
                if(ok_to_add(locate(str[i]),first[locate(str[i+1])][j]))
                follow[locate(str[i])].push_back(first[locate(str[i+1])][j]);
        }
    }
    if(isN(str[str.size()-1]) && follow[index].size() != 0)
    {
        for(int k=0; k<follow[index].size(); k++)
        if(ok_to_add(locate(str[str.size()-1]),follow[index][k]))
        follow[locate(str[str.size()-1])].push_back(follow[index][k]);
    }
    if(str.size()-2 >= 0 && isN(str[str.size()-2]) && isN(str[str.size()-1]) && can_infer_empty(locate(str[str.size()-1])))
    {
        for(int k=0; k<follow[index].size(); k++)
        if(ok_to_add(locate(str[str.size()-2]),follow[index][k]))
        follow[locate(str[str.size()-2])].push_back(follow[index][k]);
    }
}

void Prework::solve_follow()
{
    int n_num = new_N.size();
    follow[0].push_back('#');
    for(int cnt=0; cnt<n_num; cnt++)
    {
      for(int i=0; i<n_num; i++)
      {
        for(int j=0; j<new_Grammer[i].size(); j++)
        {
            add_to_follow(i,new_Grammer[i][j]);
        }
      }
    }
}

void Prework::create_analyze_table()
{
    int n_num = new_N.size();
    int t_num = new_T.size();
    for(int i=0; i<n_num; i++)
    {
        for(int j=0; j<new_Grammer[i].size(); j++)
        {
            if(isN(new_Grammer[i][j][0]))
            {
                for(int k=0; k<first[locate(new_Grammer[i][j][0])].size(); k++)
                   if(first[locate(new_Grammer[i][j][0])][k] != 'e')
                    AT[i][locate2(first[locate(new_Grammer[i][j][0])][k])] = new_Grammer[i][j];
            }
            else if(isT(new_Grammer[i][j][0]))
                AT[i][locate2(new_Grammer[i][j][0])] = new_Grammer[i][j];
            else
            {
                for(int k=0; k<follow[i].size(); k++)
                  if(follow[i][k] == '#')
                    AT[i][t_num] = new_Grammer[i][j];
                  else
                    AT[i][locate2(follow[i][k])] = new_Grammer[i][j];
            }
        }
    }
}

vector<vector<string>> Prework::get_analyze_table()
{
    solve_first();
    solve_follow();
    create_analyze_table();
    vector<vector<string> > AT2(30,vector<string>(256,string()));
    for(int j=0; j<new_N.size(); j++){
        for(int i=0; i<=new_T.size(); i++){
            if(i < new_T.size()){
                int pos = locate2(new_T[i]);
                AT2[j][new_T[i]] = AT[j][pos];
            }
            else{
                AT2[j][127] = AT[j][new_T.size()];
            }
        }
    }
   return AT2;
}

