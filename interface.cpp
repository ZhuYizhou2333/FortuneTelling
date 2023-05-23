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

void Stringsplit(std::string str, const char split, std::vector<std::string> &res)
{
    std::istringstream iss(str);       // 输入流
    std::string token;                 // 接收缓冲区
    while (getline(iss, token, split)) // 以split为分隔符
    {
        res.push_back(token);
    }
}

// 存储格式：命例分类名 姓名 生时 男女 出生经度 备注

// 使用文件初始化命例分类。
TypesManage InitTypes()
{
    TypesManage alltype;
    // 打开文件
    std::ifstream infile("file.txt");
    if (!infile.is_open())
    {
        std::cerr << "错误：无法打开文件" << std::endl;
        system("pause");
    }
    // 读取数据
    std::string line;
    while (std::getline(infile, line))
    {
        std::vector<std::string> strList;
        Stringsplit(line, ' ', strList); // strList中存储有一系列可以构造命例的信息。
        Case c;
        if (strList.size() == 6)
        {
            // 构造命例
            Gender g;
            if (strList[3] == "男")
            {
                g = Gender::Male;
            }
            else
            {
                g = Gender::Female;
            }
            unsigned long long birth = 0;
            std::istringstream bb(strList[2]);
            bb >> birth;
            double longitude = 120;
            std::istringstream ll(strList[4]);
            ll >> longitude;
            c = Case(birth, longitude, g, strList[1], strList[5]);
            // 遍历alltype，找到对应的Type，将Case添加进去。如果没有Type，就新建一个Type。
            bool flag = false;
            for (auto &i : alltype._Types)
            {
                if (i.GetName() == strList[0])
                {
                    i.AddCase(c);
                    flag = true;
                    break;
                }
            }
            if (!flag)
            {
                Type t(strList[0]);
                t.AddCase(c);
                alltype._Types.push_back(t);
            }
        }
        else
        {
            bool flag = false;
            for (auto &i : alltype._Types)
            {
                if (i.GetName() == strList[0])
                {
                    flag = true;
                    break;
                }
            }
            if (!flag)
            {
                Type t(strList[0]);
                alltype._Types.push_back(t);
            }
        }
    }

    // 关闭文件
    infile.close();

    return alltype;
}
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
    TypesManage alltype(InitTypes()); // 从文件中构造。
    system("cls");
    cout << "用户：1234Aa\n请输入数字进行对应操作\n\n";
    cout << "\t0.返回功能选择界面\n";
    cout << "\t1.编辑，导入与导出分类\n";
    // 这里是具体的命例分类。
    for (int i = 0; i < alltype.ShowAmount(); i++)
    {
        cout << "\t" << i + 2 << "." << alltype._Types[i].GetName() << "\n";
    }

    cout << "\n请选择：";

    short in = 1;
    cin >> in;
    switch (in)
    {
    case 0:
        FunctionChoose();
        break;
    case 1:
        TypeEdit(alltype); // 进入分类编辑界面，传入类型管理对象。
    default:
        // 进入命例查看界面，传入类型管理对象与选择的命例分类。
        ParticularTypeView(alltype, alltype._Types[in - 2]);
        break;
    }
}
// 命例分类编辑功能，可以导向添加，删除，导入，导出。

void TypeEdit(TypesManage alltype)
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
        TypeAdd(alltype);
        break;
    case 2:
        TypeDelete(alltype);
        break;
    case 3:

    case 4:

    default:
        break;
    }
}

// 命例分类添加功能。
void TypeAdd(TypesManage alltype)
{
    system("cls");
    cout << "用户：1234Aa\n\n";
    cout << "\t请输入需要添加的分类名称（输入0代表取消新建）\n\n";
    cout << "请输入：";
    // 这里需要接受新建的分类名称。
    std::string Name;
    cin >> Name;
    if (Name == "0")
    {
        TypeEdit(alltype);
    }
    else
    {
        alltype.AddType(Name);
        // 将新添加的分类写入文件：“file.txt”。
        // 打开文件
        std::ofstream outfile;
        outfile.open("file.txt", std::ios::app);
        // 向文件末尾换行写入字符串Name。
        outfile << "\n"
                << Name;
        // 关闭文件
        outfile.close();
        TypeEdit(alltype);
    }
}
// 命例分类删除功能
void TypeDelete(TypesManage alltype)
{
    system("cls");
    cout << "用户：1234Aa\n";
    cout << "存在的分类：\n\n";
    // 这里需要遍历alltype，输出所有的分类名称。
    for (int i = 0; i < alltype.ShowAmount(); i++)
    {
        cout << "\t" <<alltype._Types[i].GetName() << "\n";
    }
    cout << "\t请输入需要删除的分类名称（输入0代表取消删除）\n\n";
    cout << "请输入：";
    // 这里需要接受删除的分类名称。
    std::string Name;
    cin >> Name;
    if (Name == "0")
    {
        TypeEdit(alltype);
    }
    else
    {
        // 打开文件
        std::ofstream outfile("file_temp.txt"); // 以输出模式打开一个临时文件

        // 逐行读取文件信息
        std::string line;
        std::ifstream infile("file.txt");
        while (getline(infile, line))
        {
            std::vector<std::string> strList;
            Stringsplit(line, ' ', strList); // strList的第一位存有分类名称。
            // 如果分类名称与删除的名称相同，则删除这一行。
            if (strList[0] != Name)
            {
                outfile << line << "\n";
            }
        }

        // 关闭文件
        infile.close();
        outfile.close();

        // 删除原文件
        std::remove("file.txt");

        // 重命名临时文件为原文件名
        std::rename("file_temp.txt", "file.txt");

        TypeEdit(alltype);
    }
}
// 命例分类细致查看，可以看到姓名，生时，备注等。
void ParticularTypeView(TypesManage alltype, Type type)
{
    system("cls");
    cout << "用户：1234Aa\n";
    cout << "分类 " << type.GetName() << " 中的命例：\n\n";
    // 遍历type中的命例，输出姓名，性别，备注等。
    for (int i = 0; i < type._Cases.size(); i++)
    {
        cout << "\t" << i + 1 << ".姓名：" << type._Cases[i]._name << "\t备注：" << type._Cases[i]._remark << "\n";
    }
    cout << "请输入数字查看命例排盘结果（输入0返回命例分类查看界面）\n\n";
    cout << "请输入：";
    // 接受选择的数字
    short in = 1;
    cin >> in;
    switch (in)
    {
    case 0:
        AllTypeView();
        break;
    default:
        // 进入命例查看界面，传入类型管理对象与选择的命例。
        ViewCase(alltype, type._Cases[in - 1]);
        break;
    }
}
// 新建命例。
void NewCase()
{
}
// 排盘
void ViewCase(TypesManage alltype, Case c)
{
    system("cls");
    c.show();
    // system("pause");
}

TypesManage::TypesManage() : _Types(4)
{
    _Types[0] = Type("家人");
    _Types[1] = Type("朋友");
    _Types[2] = Type("亲戚");
    _Types[3] = Type("同学");
}