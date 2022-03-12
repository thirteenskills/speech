#include "D:\c++\speech\head\head.h"

int main()
{
    manage ma;
    while (1)
    {
        ma.showmenu();
        int sele;
        cin >> sele;
        switch (sele)
        {
        case 1:
        {   
            ma.clear();
            ma.create();
            ma.start();
            system("cls");
            break;
        }
        

        case 2:
        {
            ma.seek();
            system("pause");
            system("cls");
            break;
        }
        
        case 3:
            ma.fileclear();
            break;
        case 0:
        {
            cout << "您已退出系统" << endl;
            system("pause");
            return 0;
        }
        default:
            system("cls");
            break;
        }
    }
    return 0;
}