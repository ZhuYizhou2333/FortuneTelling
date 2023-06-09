#include <iostream>
#include "interface.h"

void GotoXY(SHORT x, SHORT y)
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
    std::ifstream infile;
    infile.open("file.txt");
    // if (!infile.is_open())
    // {
    //     std::cerr << "错误：无法打开文件" << std::endl;
    //     system("pause");
    // }
    // 读取数据
    std::string line;
    while (std::getline(infile, line))
    {
        std::vector<std::string> strList;
        if (line != "\n" && line != "\r" && line != "\r\n" && line != "\n\r" && line != "" && line != " ")
        {

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
            else if (strList.size() == 1)
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
    bool shouldExit = false; // 控制循环是否退出的变量

    while (!shouldExit)
    {
        system("cls");
        cout << "请输入数字进行对应操作\n\n";
        cout << "\t0.退出程序\n";
        cout << "\t1.排盘模式\n\n";
        // cout << "\t2.占卜模式\n\n";
        cout << "请选择：";

        short in = 1;
        cin >> in;
        switch (in)
        {
        case 0:
            shouldExit = true;
            break;
        case 1:
            AllTypeView();
            break;
        case 2:
            // break;
        case 6:
            // break;
        default:
            cout << "输入错误，请重新输入：";
            Sleep(400);
            cout <<".";
            Sleep(400);
            cout <<".";
            Sleep(400);
            cout <<".";
            Sleep(800);
            break;
        }
    }
}
// 命例分类查看功能，包含命例的分类与可选的编辑选项。
void AllTypeView()
{
    bool shouldExit = false; // 控制循环是否退出的变量

    while (!shouldExit)
    {
        TypesManage alltype(InitTypes()); // 从文件中构造。
        system("cls");
        cout << "请输入数字进行对应操作\n\n";
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
        // 检测数字是否大于范围
        while (in > alltype.ShowAmount() + 1)
        {
            cout << "输入错误，请重新输入：";
            cin >> in;
        }
        switch (in)
        {
        case 0: // 返回功能选择界面
            shouldExit = true;
            break;
        case 1:
            TypeEdit(); // 进入分类编辑界面，传入类型管理对象。
            break;
        default:
            // 进入命例查看界面，传入类型管理对象与选择的命例分类。
            ParticularTypeView(in - 2);
            break;
        }
    }
}
// 命例分类编辑功能，可以导向添加，删除，导入，导出。

void TypeEdit()
{
    bool shouldExit = false; // 控制循环是否退出的变量

    while (!shouldExit)
    {
        TypesManage alltype(InitTypes()); // 从文件中构造。
        system("cls");
        cout << "请输入数字进行对应操作\n\n";
        cout << "\t0.返回分类查看页面\n";
        cout << "\t1.添加分类\n";
        cout << "\t2.删除分类\n";
        cout << "\t3.导出全部\n";
        cout << "\t4.导入文件\n\n";
        cout << "请选择：";
        // 接受选择的数字
        short in = 1;
        cin >> in;
        switch (in)
        {
        case 0:
            shouldExit = true;
            break;
        case 1:
            TypeAdd();
            break;
        case 2:
            TypeDelete();
            break;
        case 3:
            TypeExport();
            break;
        case 4:
            TypeImport();
        default:
            break;
        }
    }
}

// 命例分类添加功能。
void TypeAdd()
{
    TypesManage alltype(InitTypes()); // 从文件中构造。
    system("cls");
    // cout << "用户：1234Aa\n\n";
    cout << "请输入需要添加的分类名称（输入0代表取消新建）\n\n";
    cout << "请输入：";
    // 这里需要接受新建的分类名称。
    std::string Name;
    cin >> Name;
    if (Name == "0")
        return;
    alltype.AddType(Name);
    // 将新添加的分类写入文件：“file.txt”。
    // 打开文件
    std::ofstream outfile;
    outfile.open("file.txt", std::ios::app);
    // 向文件末尾换行写入字符串Name。
    outfile << "\n"
            << Name << " ";
    // 关闭文件
    outfile.close();
}
// 命例分类删除功能
void TypeDelete()
{
    TypesManage alltype(InitTypes()); // 从文件中构造。
    system("cls");
    cout << "存在的分类：\n\n";
    // 这里需要遍历alltype，输出所有的分类名称。
    for (int i = 0; i < alltype.ShowAmount(); i++)
    {
        cout << "\t" << alltype._Types[i].GetName() << "\n";
    }
    cout << "\t请输入需要删除的分类名称（输入0代表取消删除）\n\n";
    cout << "请输入：";
    // 这里需要接受删除的分类名称。
    std::string Name;
    cin >> Name;
    if (Name == "0")
        return;
    // 打开文件
    std::ofstream outfile("file_temp.txt"); // 以输出模式打开一个临时文件

    // 逐行读取文件信息
    std::string line;
    std::ifstream infile("file.txt");
    while (getline(infile, line))
    {
        if (line == ""||line=="\n"||line==" "||line==" \n")
            continue;
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
}
// 命例导入功能
void TypeImport()
{
    //接受要导入的文件名
    std::string fileName;
    std::cout << "请输入要导入的文件名：（注意要包含拓展名）";
    std::cin >> fileName;
    //打开文件
    std::ifstream infile(fileName);
    //打开失败则输出报错
    if (!infile)
    {
        std::cout << "打开文件失败！\n";
        system("pause");
        return;
    }
    //逐行读取文件信息
    std::string line;
    //将文件逐行复制到file.txt中
    std::ofstream outfile("file.txt", std::ios::app);
    outfile << "\n";
    while (getline(infile, line))
    {
        outfile << line << "\n";
    }
    //关闭文件
    infile.close();
    outfile.close();
    cout << "导入成功！\n";
    Sleep(1000);

}
// 命例导出功能
void TypeExport()
{
    //新建文件
    std::ofstream outfile;
    outfile.open("Export.txt");
    //把file.txt中的内容复制到file_temp.txt中
    std::string line;
    std::ifstream infile("file.txt");
    while (getline(infile, line))
    {
        outfile << line << "\n";
    }
    //关闭文件
    infile.close();
    outfile.close();
    cout << "导出成功！\n";
    Sleep(1000);
}
// 命例分类细致查看，可以看到姓名，生时，备注等。
void ParticularTypeView(short typeNum)
{
    bool shouldExit = false; // 控制循环是否退出的变量
    while (!shouldExit)
    {
        TypesManage alltype(InitTypes()); // 从文件中构造。
        system("cls");
        cout << "请输入数字进行对应操作\n\n";
        cout << "\t0.返回功能选择界面\n";
        cout << "\t1.新建命例\n";
        cout << "\t2.删除命例" << std::endl;
        // 遍历type中的命例，输出姓名，性别，备注等。
        for (int i = 0; i < static_cast<int>(alltype._Types[typeNum]._Cases.size()); i++)
        {
            cout << "\t" << i + 3 << ".姓名：" << alltype._Types[typeNum]._Cases[i]._name << "\t备注：" << alltype._Types[typeNum]._Cases[i]._remark << "\n";
        }
        cout << "请输入：";
        // 接受选择的数字
        short in = 1;
        cin >> in;
        switch (in)
        {
        case 0:
            shouldExit = true;
            break;
        case 1:
            NewCase(typeNum);
            break;
        case 2:
            DeleteCase(typeNum);
            break;
        default:
            // 进入命例查看界面，传入类型管理对象与选择的命例。
            ViewCase(alltype._Types[typeNum]._Cases[in - 3]);
            break;
        }
    }
}
// 新建命例。
void NewCase(short typeNum)
{
    TypesManage alltype(InitTypes()); // 从文件中构造。
    system("cls");
    // 这里需要接受新建的命例的姓名，性别，备注等。
    std::string name;
    cout << "请输入姓名：（输入0代表取消新建）";
    cin >> name;
    if (name == "0")
        return;
    Gender ggender;
    bool RightIn = false;
    std::string GenderS;
    cout << "请输入性别（男/女）：";
    while (!RightIn)
    {
        cin >> GenderS;
        if (GenderS == "男")
        {
            ggender = Gender::Male;
            RightIn = true;
        }
        else if (GenderS == "女")
        {
            ggender = Gender::Female;
            RightIn = true;
        }
        else
            cout << "输入错误！请重新输入：";
    }
    RightIn = false;
    int yy, mm, dd, hh, min;
    while (!RightIn)
    {
        cout << "请输入出生年份：";
        cin >> yy;
        if (yy < 1910 || yy > 2085)
            cout << "只接受1910-2085间的年份。请重新输入：";
        else
            RightIn = true;
    }
    RightIn = false;
    while (!RightIn)
    {
        cout << "请输入出生月份：";
        cin >> mm;
        if (mm < 1 || mm > 12)
            cout << "只接受1-12间的月份。请重新输入：";
        else
            RightIn = true;
    }
    RightIn = false;
    while (!RightIn)
    {
        cout << "请输入出生日期：";
        cin >> dd;
        if (dd < 1 || dd > 31)
            cout << "只接受1-31间的日期。请重新输入：";
        else
            RightIn = true;
    }
    RightIn = false;
    while (!RightIn)
    {
        cout << "请输入出生小时：";
        cin >> hh;
        if (hh < 0 || hh > 23)
            cout << "只接受0-23间的小时。请重新输入：";
        else
            RightIn = true;
    }
    RightIn = false;
    while (!RightIn)
    {
        cout << "请输入出生分钟：";
        cin >> min;
        if (min < 0 || min > 59)
            cout << "只接受0-59间的分钟。请重新输入：";
        else
            RightIn = true;
    }
    RightIn = false;
    double longitude;
    while (!RightIn)
    {
        cout << "请输入出生地经度：";
        cin >> longitude;
        if (longitude < -180 || longitude > 180)
            cout << "只接受-180-180间的经度。请重新输入：";
        else
            RightIn = true;
    }
    RightIn = false;
    std::string remark;
    cout << "请输入备注：";
    cin >> remark;
    unsigned long long id = 0;
    id = static_cast<unsigned long long>(yy) * 100000000 + static_cast<unsigned long long>(mm) * 1000000 + static_cast<unsigned long long>(dd) * 10000 + static_cast<unsigned long long>(hh) * 100 + min;
    // 生成命例对象
    Case c(id, longitude, ggender, name, remark);
    // 将命例对象加入到类型管理对象中。
    alltype._Types[typeNum]._Cases.push_back(c);
    // 以追加的方式打开文件
    std::ofstream outfile;
    outfile.open("file.txt", std::ios::app);
    // 将命例对象写入文件
    outfile << "\n"
            << alltype._Types[typeNum].GetName() << " " << name << " " << id << " ";
    if (ggender == Gender::Male)
    {
        outfile << "男 ";
    }
    else
    {
        outfile << "女 ";
    }
    outfile << longitude << " " << remark;
    // 关闭文件
    outfile.close();
}

// 删除命例
void DeleteCase(short typeNum)
{
    TypesManage alltype(InitTypes()); // 从文件中构造。
    // 不清屏，直接输出。
    //  输入要删除的命例对象的序号
    std::string Name;
    cout << "请输入要删除的命例的姓名：（输入0代表取消删除）";
    cin >> Name;
    if (Name == "0")
        return;
    // 打开文件
    std::ofstream outfile("file_temp.txt"); // 以输出模式打开一个临时文件

    // 逐行读取文件信息
    std::string line;
    std::ifstream infile("file.txt");
    while (getline(infile, line))
    {
        if (line == ""||line=="\n"||line==" "||line==" \n")
            continue;
        std::vector<std::string> strList;
        Stringsplit(line, ' ', strList); // strList的第一位存有分类名称。
        // 如果分类名称与删除的名称相同且命例名相同，则删除这一行。
        if (strList[1] != Name || strList[0] != alltype._Types[typeNum].GetName())
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
}
// 排盘
void ViewCase(Case c)
{
    system("cls");
    c.show();
    system("pause");
}

TypesManage::TypesManage() : _Types(4)
{
    _Types[0] = Type("家人");
    _Types[1] = Type("朋友");
    _Types[2] = Type("亲戚");
    _Types[3] = Type("同学");
}