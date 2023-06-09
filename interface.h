#ifndef INTERFACE_H
#define INTERFACE_H

#include <bits/stdc++.h>
#include <windows.h>
#include <string>
#include <vector>
#include "Stars.h"
#include <sstream>
// 用来移动输出光标。
void GotoXY(SHORT x = 0, SHORT y = 0);

class Type
{
private:
    std::string _Name;

public:
    std::vector<Case> _Cases;
    Type(std::string nname = "未命名分类") : _Name(nname){};
    std::string GetName() const { return _Name; };
    void AddCase(Case c){_Cases.push_back(c);};
    int ShowAmount() const {return _Cases.size();};
};

class TypesManage
{
public:
    std::vector<Type> _Types; // 在构造函数中初始化大小等。
    TypesManage(); // TypeManage由Type组成，Type由Case组成。
    void AddType(std::string name){_Types.push_back(Type(name));};
    int ShowAmount() const {return _Types.size();};
};

void Stringsplit(std::string str, const char split, std::vector<std::string> &rst);
// 默认将传入的字符串str以split为分隔符进行分割，    不会将子串打印在屏幕上，无返回值
// 					分割的子串将会保存在rst数组中被带出函数。

// 登录界面，包含账户密码输入等。
void LogIn();
// 使用文件初始化命例分类。
TypesManage InitTypes();
// 功能选择界面，包含算命与占卜功能。
void FunctionChoose();
// 命例分类查看功能，包含命例的分类与可选的编辑选项。
void AllTypeView();
// 分类编辑选择界面，可以导向添加，删除，导入，导出。
void TypeEdit();
// 命例添加功能，添加后自动写入文件。
void TypeAdd();
// 命例删除功能
void TypeDelete();
// 命例导入功能
void TypeImport();
// 命例导出功能
void TypeExport();
// 命例分类细致查看，可以看到姓名，生时，备注等。
void ParticularTypeView(short typeNum);
// 新建命例。
void NewCase(short typeNum);
//删除命例。
void DeleteCase(short typeNum);
// 排盘
void ViewCase(Case c);

#endif