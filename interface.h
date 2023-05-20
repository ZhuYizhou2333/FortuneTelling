#ifndef INTERFACE_H
#define INTERFACE_H

#include <bits/stdc++.h>
#include <windows.h>
#include <string>
#include <vector>
#include "Stars.h"
#include <sstream>
// 用来移动输出光标。
void GotoXY(int x = 0, int y = 0);



class Type
{
public:
    std::string _Name;
    std::vector<Case>_Cases;
    Type(std::string nname="未命名分类") : _Name(nname){};
    void AddCase(Case &c);
    int ShowAmount();
};


class TypesManage
{
public:
    std::vector<Type>_Types;//在构造函数中初始化大小等。
    int ShowAmount();
    TypesManage();//TypeManage由Type组成，Type由Case组成。因此构造的时候，既要知道Type的信息，也要知道Case的信息。
    void AddType(std::string name);
};


void Stringsplit(std::string str,const char split,std::vector<std::string>& rst);
// 默认将传入的字符串str以split为分隔符进行分割，    不会将子串打印在屏幕上，无返回值
// 					分割的子串将会保存在rst数组中被带出函数。

// 登录界面，包含账户密码输入等。
void LogIn();
//使用文件初始化命例分类。
void InitTypes(TypesManage &alltype);
// 功能选择界面，包含算命与占卜功能。
void FunctionChoose();
// 命例分类查看功能，包含命例的分类与可选的编辑选项。
void AllTypeView();
// 分类编辑选择界面，可以导向添加，删除，导入，导出。
void TypeEdit(TypesManage &alltype);
// 命例添加功能。
void TypeAdd(TypesManage &alltype);
// 命例删除功能
void TypeDelete(TypesManage &alltype);
// 命例分类细致查看，可以看到姓名，生时，备注等。
void ParticularTypeView(TypesManage &alltype,Type &type);
// 新建命例。
void NewCase(TypesManage &alltype);
// 排盘
void ViewCase(Case &c);



#endif