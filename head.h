#pragma once
#include <iostream>
#include <deque>
#include <string>
#include <fstream>
#include <vector>
#include <map>
#include <algorithm>
#include<numeric>
#define file "D:\\c++\\speech\\champion.csv"
using namespace std;

class speaker;

class manage
{
public:
    manage();
    ~manage();
    void showmenu();
    void start();
    void clear();
    void create();
    void Draw();
    void game();
    void save();
    void seek();
    void fileclear();
    void contest(vector<int> &,vector<int> &);
    void showmem();

    vector<int> v1;
    vector<int> v2;
    vector<int> v3;
    map<int, speaker> m_map;
    int m_index;
};

class speaker
{
public:
    string m_name;
    double m_score[2];
    speaker(){}
    speaker(string name, double score1, double score2);
    

    void showoff(int i){
    cout<<"  ÐÕÃû£º"<<m_name<<"  µÃ·Ö£º"<<m_score[i]<<endl;
    }
};