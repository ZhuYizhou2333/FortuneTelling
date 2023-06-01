#include <iostream>
#include "sizhu.h"
#include "xDate.h"
#include <cmath>
#include "Stars.h"
#include "interface.h"
#include <time.h>
#include <tchar.h>

/**
 *               ii.                                         ;9ABH,
 *              SA391,                                    .r9GG35&G
 *              &#ii13Gh;                               i3X31i;:,rB1
 *              iMs,:,i5895,                         .5G91:,:;:s1:8A
 *               33::::,,;5G5,                     ,58Si,,:::,sHX;iH1
 *                Sr.,:;rs13BBX35hh11511h5Shhh5S3GAXS:.,,::,,1AG3i,GG
 *                .G51S511sr;;iiiishS8G89Shsrrsh59S;.,,,,,..5A85Si,h8
 *               :SB9s:,............................,,,.,,,SASh53h,1G.
 *            .r18S;..,,,,,,,,,,,,,,,,,,,,,,,,,,,,,....,,.1H315199,rX,
 *          ;S89s,..,,,,,,,,,,,,,,,,,,,,,,,....,,.......,,,;r1ShS8,;Xi
 *        i55s:.........,,,,,,,,,,,,,,,,.,,,......,.....,,....r9&5.:X1
 *       59;.....,.     .,,,,,,,,,,,...        .............,..:1;.:&s
 *      s8,..;53S5S3s.   .,,,,,,,.,..      i15S5h1:.........,,,..,,:99
 *      93.:39s:rSGB@A;  ..,,,,.....    .SG3hhh9G&BGi..,,,,,,,,,,,,.,83
 *      G5.G8  9#@@@@@X. .,,,,,,.....  iA9,.S&B###@@Mr...,,,,,,,,..,.;Xh
 *      Gs.X8 S@@@@@@@B:..,,,,,,,,,,. rA1 ,A@@@@@@@@@H:........,,,,,,.iX:
 *     ;9. ,8A#@@@@@@#5,.,,,,,,,,,... 9A. 8@@@@@@@@@@M;    ....,,,,,,,,S8
 *     X3    iS8XAHH8s.,,,,,,,,,,...,..58hH@@@@@@@@@Hs       ...,,,,,,,:Gs
 *    r8,        ,,,...,,,,,,,,,,.....  ,h8XABMMHX3r.          .,,,,,,,.rX:
 *   :9, .    .:,..,:;;;::,.,,,,,..          .,,.               ..,,,,,,.59
 *  .Si      ,:.i8HBMMMMMB&5,....                    .            .,,,,,.sMr
 *  SS       :: h@@@@@@@@@@#; .                     ...  .         ..,,,,iM5
 *  91  .    ;:.,1&@@@@@@MXs.                            .          .,,:,:&S
 *  hS ....  .:;,,,i3MMS1;..,..... .  .     ...                     ..,:,.99
 *  ,8; ..... .,:,..,8Ms:;,,,...                                     .,::.83
 *   s&: ....  .sS553B@@HX3s;,.    .,;13h.                            .:::&1
 *    SXr  .  ...;s3G99XA&X88Shss11155hi.                             ,;:h&,
 *     iH8:  . ..   ,;iiii;,::,,,,,.                                 .;irHA
 *      ,8X5;   .     .......                                       ,;iihS8Gi
 *         1831,                                                 .,;irrrrrs&@
 *           ;5A8r.                                            .:;iiiiirrss1H
 *             :X@H3s.......                                .,:;iii;iiiiirsrh
 *              r#h:;,...,,.. .,,:;;;;;:::,...              .:;;;;;;iiiirrss1
 *             ,M8 ..,....,.....,,::::::,,...         .     .,;;;iiiiiirss11h
 *             8B;.,,,,,,,.,.....          .           ..   .:;;;;iirrsss111h
 *            i@5,:::,,,,,,,,.... .                   . .:::;;;;;irrrss111111
 *            9Bi,:,,,,......                        ..r91;;;;;iirrsss1ss1111


                     狗头保佑                              永无BUG

 */

// 填入1代表编译完整程序，填入0代表编译测试程序
#if 1

//*******************************这下面是正式程序**********************************

int main()

{
   // 新建文件并追加内容
   std::ofstream outfile;
   outfile.open("file.txt", std::ios::app);

   // 检测文件是否打开成功
   if (!outfile.is_open())
   {
      std::cout << "文件打开失败" << std::endl;
      system("pause");
      return 0;
   }

   // 关闭文件
   outfile.close();

   // 隐藏文件
   if (!SetFileAttributes(_T("file.txt"), FILE_ATTRIBUTE_HIDDEN))
   {
      std::cout << "设置文件属性失败" << std::endl;
      system("pause");
      return 0;
   }

   // std::cout << "文件创建并隐藏成功" << std::endl;
   // system("pause");
   FunctionChoose();
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

   // Case p2(200503141923,120,Gender::Male,"朱羿州","无");
   // p2.show();
   // end = clock();// 结束时间
   // std::cout << "time = " << double(end - start) / CLOCKS_PER_SEC << "s" << std::endl; // 输出时间（单位：ｓ）
   // sizhu sizhu1;//这是用来测试构造函数的。
   // Case a;
   FunctionChoose();
   // Case p3(p2);
   // p3.show();

   // system("pause");

   return 0;
}
#endif
