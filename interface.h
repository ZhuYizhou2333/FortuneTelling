#ifndef INTERFACE_H
#define INTERFACE_H

#include <bits/stdc++.h>
#include <windows.h>
// 用来移动输出光标。
void GotoXY(int x = 0, int y = 0);
// 登录界面，包含账户密码输入等。
void LogIn();
// 功能选择界面，包含算命与占卜功能。
void FunctionChoose();
// 命例分类查看功能，包含命例的分类与可选的编辑选项。
void AllTypeView();
// 命例分类编辑功能，可以导向添加，删除，导入，导出。

void TypeEdit();

// 命例添加功能。
void TypeAdd();
// 命例删除功能
void TypeDelete();
// 命例分类细致查看，可以看到姓名，生时，备注等。
void ParticularTypeView();
// 新建命例。
void NewCase();
// 排盘
void ViewCase();

#endif