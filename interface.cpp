#include <iostream>
#include "interface.h"

void GotoXY(int x, int y)
{
    COORD pos = {x, y};
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hOut, pos);
}
using std::cin;
using std::cout;

// void Fresh()
// {
//     GotoXY();
//     for (int i = 0; i < 20; i++)
//     {
//         cout <<"\r";
//     }
//     GotoXY();
// }

// 登录界面，包含账户密码输入等。
void LogIn()
{
}
// 功能选择界面，包含算命与占卜功能。
void FunctionChoose()
{
    system("cls");
    cout << "用户：1234Aa\n请输入数字进行对应操作\n\n";
    cout << "\t0.重新登录\n";
    cout << "\t1.排盘模式\n";
    cout << "\t2.占卜模式\n\n";
    cout << "请选择：";

    short in = 1;
    cin >> in;
    switch (in)
    {
    case 0:
        LogIn();
        break;
    case 1:
        AllTypeView();
        break;
    case 2:
        break;
    case 6:
        break;
    default:
        break;
    }
}
// 命例分类查看功能，包含命例的分类与可选的编辑选项。
void AllTypeView()
{
    system("cls");
    cout << "用户：1234Aa\n请输入数字进行对应操作\n\n";
    cout << "\t0.返回功能选择界面\n";
    cout << "\t1.编辑，导入与导出分类\n\n";
    // 这里是具体的命例分类。

    cout << "请选择：";

    short in = 1;
    cin >> in;
    switch (in)
    {
    case 0:
        FunctionChoose();
        break;
    case 1:
        TypeEdit();
    default:
        break;
    }
}
// 命例分类编辑功能，可以导向添加，删除，导入，导出。

void TypeEdit()
{
    system("cls");
    cout << "用户：1234Aa\n请输入数字进行对应操作\n\n";
    cout << "\t0.返回分类查看页面\n";
    cout << "\t1.添加分类\n";
    cout << "\t2.删除分类\n";
    cout << "\t3.导出指定分类（导出为加密文本文件）\n";
    cout << "\t4.导入分类\n\n";
    cout << "请选择：";
    // 接受选择的数字
    short in = 1;
    cin >> in;
    switch (in)
    {
    case 0:
        AllTypeView();
        break;
    case 1:
        TypeAdd();
        break;
    case 2:
        TypeDelete;
        break;
    case 3:

    case 4:

    default:
        break;
    }
}

// 命例分类添加功能。
void TypeAdd()
{
    system("cls");
    cout << "用户：1234Aa\n\n";
    cout << "\t请输入需要添加的分类名称（输入0代表取消新建）\n\n";
    cout << "请输入：";
    // 这里需要接受新建的分类名称。
}
// 命例分类删除功能
void TypeDelete()
{
    system("cls");
    cout << "用户：1234Aa\n";
    cout << "存在的分类：\n\n";
    cout << "\t1.家人\n";
    cout << "\tn.xyz\n\n";
    cout << "\t请输入需要删除的分类名称（输入0代表取消删除）\n\n";
    cout << "请输入：";
    // 这里需要接受删除的分类名称。
}
// 命例分类细致查看，可以看到姓名，生时，备注等。
void ParticularTypeView()
{
    system("cls");
    cout << "用户：1234Aa\n";
    cout << "分类《家人》中的命例：\n\n";
    cout << "\t1.姓名：  性别：   备注：   \n\n";

    cout << "\t请输入数字查看命例排盘结果\n\n";
    cout << "请输入：";
}
// 新建命例。
void NewCase()
{
}
// 排盘
void ViewCase()
{
}
