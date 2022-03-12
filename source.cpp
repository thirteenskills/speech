#include "D:\c++\speech\head\head.h"

speaker::speaker(string name, double score1 = 0.0, double score2 = 0.0)
{
    m_name = name;
    m_score[0] = score1;
    m_score[1] = score2;
}
void manage::Draw()
{
    cout << "第《" << m_index << "》轮选手正在比赛" << endl
         << "----------------------------" << endl
         << "抽签结果如下：" << endl;
    if (m_index == 1)
    {
        random_shuffle(v1.begin(), v1.end());
        cout << "第一组：";
        for (int i = 0; i < v1.size(); i++)
        {
            cout << v1[i] << ' ';
            if (i == 5)
            {
                cout << "第二组：";
            }
        }
    }
    else
    {
        random_shuffle(v2.begin(), v2.end());
        cout << "第一组：";
        for (vector<int>::iterator it = v2.begin(); it != v2.end(); it++)
        {
            cout << *it << ' ';
        }
    }
    cout << endl;
    cout << "-------------------------" << endl;
    system("pause");
    cout << endl;
}
void manage::contest(vector<int> &v, vector<int> &va)
{
    multimap<double, int> abc;
    for (int j = 0; j < v.size(); j++)
    {
        deque<double> d;
        for (int i = 0; i < 10; i++)
        {
            double s = (rand() % 1000 + 1) / 10.f;
            d.push_back(s);
        }
        sort(d.begin(), d.end());
        d.pop_front();
        d.pop_back();
        double sc = accumulate(d.begin(), d.end(), 0.0f) / double(8.0);
        m_map[v[j]].m_score[m_index - 1] = sc;
        abc.insert(make_pair(sc, v[j]));
        if ((j + 1) % 6 == 0)
        {
            cout << "第《" << (j + 1) / 6 << "》组比赛结果如下：" << endl;
            int x = 0;
            for (multimap<double, int>::iterator it = abc.begin(); it != abc.end(); it++)
            {
                if (x < 3)
                {
                    va.push_back((*it).second);
                }
                cout << "编号： " << (*it).second;
                m_map[(*it).second].showoff(m_index - 1);
                x++;
            }
            abc.clear();
        }
    }
    m_index += 1;
}
void manage::create()
{
    string seed = "ABCDEFGHIJKL";
    string a = "选手";
    for (int i = 0; i < 12; i++)
    {
        string b = a + seed[i];
        v1.push_back(i + 1);
        speaker s1(b);
        m_map.insert(make_pair(i + 1, s1));
    }
}
void manage::game()
{
    cout << "-------------------------" << endl
         << "第" << m_index << "次比赛开始" << endl;
    if (m_index == 1)
    {
        contest(v1, v2);
    }
    else
    {
        contest(v2, v3);
    }

    cout << "--------------------" << endl;
    system("pause");
}
void manage::showmem()
{
    string seed = "冠军亚军季军";
    cout << "-------------------" << endl;
    cout << "晋级的人为：" << endl;
    if (m_index == 2)
    {
        for (int i = 5; i != -1; i--)
        {
            cout << "编号：" << v2[i];
            m_map[v2[i]].showoff(0);
        }
    }
    else
    {
        for (int i = 2; i != -1; i--)
        {
            cout << seed.substr(4 * (2 - i), 4) << ": 编号：" << v3[i];
            m_map[v3[i]].showoff(0);
        }
    }
    system("pause");
}
void manage::showmenu()
{
    cout << string(30, '*') << endl
         << string(7, '*') << "欢迎参加演讲比赛" << string(7, '*') << endl
         << string(7, '*') << "1、开始演讲比赛" << string(7, '*') << endl
         << string(7, '*') << "2、查看往届记录" << string(7, '*') << endl
         << string(7, '*') << "3、清空比赛记录" << string(7, '*') << endl
         << string(7, '*') << "0、退出比赛程序" << string(7, '*') << endl
         << string(30, '*') << endl;
}
void manage::clear()
{
    v1.clear();
    v2.clear();
    v3.clear();
    m_map.clear();
    m_index = 1;
}
void manage::start()
{
    while (m_index < 3)
    {
        Draw();
        game();
        showmem();
    }
    save();
    cout << "比赛结束" << endl;
    system("pause");
    return;
}
manage::manage()
{
    clear();
    create();
}
manage::~manage() {}
void manage::save()
{
    ofstream ofs;
    ofs.open(file, ios::app);
    for (int i = 0; i < 3; i++)
    {
        ofs << m_map[v3[2 - i]].m_name << "," << m_map[v3[2 - i]].m_score[1] << ",";
    }
    ofs.close();
    return;
}
void manage::seek()
{
    ifstream ifs;
    ifs.open(file, ios::in);
    char ch;
    if (!ifs.is_open())
    {
        cout << "文件不存在\n";
        ifs.close();
        return;
    }
    ifs >> ch;
    if (ifs.eof())
    {
        cout << "文件为空" << endl;
        ifs.close();
        return;
    }
    string name, sente, seed = "冠军亚军季军";
    double score;
    int x = 0, start = 0, end = -1;
    ifs >> sente;
    while (true)
    {   start=end+1;
        end = sente.find(',', start);
        if (end == -1)
        {
            break;
        }
        cout << seed.substr(4 * x, 4) << ":姓名：" << sente.substr(start, end - start);
        start = end + 1;
        end = sente.find(",", start);
        cout << "  得分：" << sente.substr(start, end - start)<<"  ";
        if (x == 2)
            cout << endl;
        x = (x + 1) % 3;
    }
    ifs.close();
    cout << "查询完毕" << endl;
}
void manage::fileclear()
{
    ofstream ofs;
    ofs.open(file, ios::out);
    ofs.close();
    cout << "清除完毕" << endl;
    system("pause");
    system("cls");
}