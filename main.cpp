#include <iostream>
#include "sizhu.h"
#include "xDate.h"
#include <cmath>
#include "Stars.h"
#include "interface.h"
#include <time.h>
// 填入1代表编译完整程序，填入0代表编译测试程序
#if 0

//*******************************这下面是正式程序**********************************

int main()

{

   return 0;
}

#else

//*****************************这下面是测试程序*************************************

int main()
{
   // SetConsoleOutputCP(65001);//set output encoding to UTF8
   // TianGan a = TianGan::Jia;//这是一种初始化方式
   /* TianGan a = static_cast<TianGan>(2);//这也是一种初始化方式
   switch (a)
   {
   case TianGan::Jia:
      std::cout << "甲";
      break;
   default:
      std::cout << "非甲";
      break;
   }
 */
   /*    sizhu sizhu1(198404280413, 120.0);//这是用来测试构造函数的。

      std::cout << xDate::WeekDay(2023, 4, 20) << "\n";//这是用来测试返回星期几函数的。


      WORD y = 0, m = 0, d = 0;
      xDate::GetLunarDate(2023, 3, 21, y, m, d);
      std::cout << y << " " << m << " " << d << "\n"; // 这是计算农历的方式。

      std::cout << xDate::GetLeapMonth(2022) << "\n"; // 返回闰月月份

      long e = xDate::LunarMonthDays(2023, 2);
      std::cout << "前一个月" << (e- ((e>>16)<<16))  << "\n"
                << "后一个月" << (e >> 16); // 这是返回月份天数，对于闰月，输出两个，对于非闰月，输出天数和0.
    */

   // BodyPalace p1;

   // clock_t start, end; // 定义clock_t变量
   // start = clock();//开始时间
   
   Case p2(200503141923,120,Gender::Male,"朱羿州","无");
   p2.show();
   // end = clock();// 结束时间
   // std::cout << "time = " << double(end - start) / CLOCKS_PER_SEC << "s" << std::endl; // 输出时间（单位：ｓ）
   // sizhu sizhu1;//这是用来测试构造函数的。
   // FunctionChoose();
   // system("pause");


   return 0;
}
#endif
