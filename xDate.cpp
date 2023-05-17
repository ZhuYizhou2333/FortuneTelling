#include "xDate.h"  

 
extern WORD gLunarMonthDay[];  
extern BYTE gLunarMonth[];  
extern BYTE gLunarHolDay[];  
 
const  WORD START_YEAR =1901;  
const  WORD END_YEAR   =2050;  
//===========================================================================//
//这里有一个函数定义
void xDate::l_InitData()  
{  
   SYSTEMTIME systime;  
   ::GetSystemTime(&systime);  
    
   m_iYear  = systime.wYear;  
   m_iMonth = systime.wMonth;  
   m_iDay   = systime.wDay;  
}  
//===========================================================================//
xDate::xDate(WORD iYear, WORD iMonth, WORD iDay)  
{  
   if(!SetDate(iYear, iMonth, iDay))  
      l_InitData();  
}  
//===========================================================================//
xDate::xDate()  
{  
   l_InitData();  
}  
//===========================================================================//
LONG xDate::CalcDateDiff(WORD iEndYear, WORD iEndMonth, WORD iEndDay,WORD  iStartYear, WORD iStartMonth, WORD iStartDay)  
{  
   WORD monthday[]={0, 31, 59 ,90, 120, 151, 181, 212, 243, 273, 304, 334};  
   //计算两个年份1月1日之间相差的天数  
   LONG iDiffDays =(iEndYear - iStartYear)*365;  
   iDiffDays += (iEndYear-1)/4 - (iStartYear-1)/4;  
   iDiffDays -= ((iEndYear-1)/100 - (iStartYear-1)/100);  
   iDiffDays += (iEndYear-1)/400 - (iStartYear-1)/400;  
   //加上iEndYear年1月1日到iEndMonth月iEndDay日之间的天数  
   iDiffDays += monthday[iEndMonth-1] +  
      (IsLeapYear(iEndYear)&&iEndMonth>2? 1: 0);  
   iDiffDays += iEndDay;  
   //减去iStartYear年1月1日到iStartMonth月iStartDay日之间的天数  
   iDiffDays -= (monthday[iStartMonth-1] +(IsLeapYear(iStartYear)&&iStartMonth>2 ? 1: 0));  
   iDiffDays -= iStartDay;  
   return iDiffDays;  
}  
//===========================================================================//
void  xDate::l_CalcLunarDate(WORD &iYear, WORD &iMonth ,WORD &iDay, LONG iSpanDays)  
{  
   //阳历1901年2月19日为阴历1901年正月初一  
   //阳历1901年1月1日到2月19日共有49天  
   if(iSpanDays <49) 
   { 
      iYear = START_YEAR-1; 
      if(iSpanDays <19) 
      { 
         iMonth = 11; 
         iDay = 11+WORD(iSpanDays); 
      } 
      else 
      { 
         iMonth = 12; 
         iDay = WORD(iSpanDays) -18; 
      } 
      return ; 
   } 
   //下面从阴历1901年正月初一算起 
   iSpanDays -=49; 
   iYear = START_YEAR; 
   iMonth = 1; 
   iDay = 1; 
   //计算年 
   LONG tmp = LunarYearDays(iYear); 
   while(iSpanDays >= tmp)  
   {  
      iSpanDays -= tmp;  
      tmp = LunarYearDays(++iYear);  
   }  
   //计算月  
   tmp = LOWORD(LunarMonthDays(iYear, iMonth));  
   while(iSpanDays >= tmp)  
   {  
      iSpanDays -= tmp;  
      if(iMonth == GetLeapMonth(iYear))  
      {  
         tmp  = HIWORD(LunarMonthDays(iYear, iMonth));  
         if(iSpanDays < tmp) 
            break; 
         iSpanDays -= tmp; 
      } 
      tmp = LOWORD(LunarMonthDays(iYear, ++iMonth)); 
   } 
   //计算日 
   iDay += WORD(iSpanDays); 
} 
//===========================================================================//
WORD xDate::GetLunarDate(WORD iYear, WORD iMonth, WORD iDay,WORD &iLunarYear, WORD &iLunarMonth, WORD &iLunarDay) 
{ 
   l_CalcLunarDate(iLunarYear, iLunarMonth, iLunarDay,CalcDateDiff(iYear, iMonth, iDay)); 
   return l_GetLunarHolDay(iYear, iMonth, iDay); 
} 
//===========================================================================//
//根据节气数据存储格式,计算阳历iYear年iMonth月iDay日对应的节气, 
WORD xDate::l_GetLunarHolDay(WORD iYear, WORD iMonth, WORD iDay) 
 
 
{ 
   BYTE &flag = gLunarHolDay[(iYear - START_YEAR)*12+iMonth -1]; 
   WORD day; 
   if(iDay <15) 
      day= 15 - ((flag>>4)&0x0f);  
   else  
      day = ((flag)&0x0f)+15;  
   if(iDay == day)  
      return (iMonth-1) *2 + (iDay>15? 1: 0) +1;  
   else  
      return 0;  
}  
//===========================================================================//
void xDate::GetDate(WORD &iYear, WORD &iMonth, WORD &iDay)  
{  
   iYear  = m_iYear;  
   iMonth = m_iMonth;  
   iDay   = m_iDay;  
}  
//===========================================================================//
BOOL xDate::SetDate(WORD iYear, WORD iMonth, WORD iDay)  
{  
   if(iYear < START_YEAR || iYear > END_YEAR || iMonth <1 || iMonth >12)  
      return FALSE;  
    
   if(iDay <1 || iDay > MonthDays(iYear, iMonth))  
      return FALSE;  
    
   m_iYear   = iYear;  
   m_iMonth  = iMonth;  
   m_iDay    = iDay;  
    
   return TRUE;  
}  
//===========================================================================//
WORD xDate::WeekDay(WORD iYear, WORD iMonth, WORD iDay)  
{  
   //数组元素monthday[i]表示第i个月以前的总天数除以7的余数  
   WORD monthday[]={0,3,3,6,1,4,6,2,5,0,3,5};  
   WORD iDays = (iYear-1)%7 + (iYear-1)/4 - (iYear-1)/100 +(iYear-1)/400;  
   iDays += (monthday[iMonth-1] +iDay) ;  
   //如果iYear是闰年  
   if(IsLeapYear(iYear) && iMonth>2)  
      iDays++;  
   //返回:0,1,2,3,4,5,6表日、一、二、三、四、五、六  
   return iDays%7;  
}  
//===========================================================================//
WORD xDate::MonthDays(WORD iYear, WORD iMonth)  
{  
   switch(iMonth)  
   {  
   case 1: //一  (月) 
   case 3: //三  (月) 
   case 5: //五  (月) 
   case 7: //七  (月) 
   case 8: //八  (月) 
   case 10://十  (月) 
   case 12://十二(月) 
      return 31;  
 
   case 4: //四  (月) 
   case 6: //六  (月) 
   case 9: //九  (月) 
   case 11://十一(月)  
      return 30;  
 
   case 2: //二  (月) 
      //如果是闰年  
      if(IsLeapYear(iYear))  
         return 29;  
      else  
         return 28;  
        
   }  
   return 0;  
}  
//===========================================================================//
WORD xDate::GetLeapMonth(WORD iLunarYear)  
{  
   BYTE &flag = gLunarMonth[(iLunarYear - START_YEAR)/2];  
   return  (iLunarYear - START_YEAR)%2 ? flag&0x0f : flag>>4;  
}  
//===========================================================================//
LONG xDate::LunarMonthDays(WORD iLunarYear, WORD iLunarMonth)  
{  
   if(iLunarYear < START_YEAR) 
      return 30L; 
    
   WORD height =0 ,low =29; 
   int iBit = 16 - iLunarMonth; 
    
   if(iLunarMonth > GetLeapMonth(iLunarYear) && GetLeapMonth(iLunarYear))  
      iBit --;  
    
   if(gLunarMonthDay[iLunarYear - START_YEAR] & (1<<iBit)) 
      low ++; 
    
   if(iLunarMonth == GetLeapMonth(iLunarYear)) 
   {
      if(gLunarMonthDay[iLunarYear - START_YEAR] & (1<< (iBit -1))) 
         height =30; 
      else 
         height =29; 
   }
      return MAKELONG(low, height); 
   // if(iLunarMonth == GetLeapMonth(iLunarYear)) 
   // {
   //    if(gLunarMonthDay[iLunarYear - START_YEAR] & (1<< (iBit -1))) 
   //       height =30; 
   //    else 
   //       height =29; 
   // }

   // if (height==0)
   // {
   //    return low;
   // }
   // else return low*100+height; 
      
//注意源程序在这里有较大改动！！！！
} 
//===========================================================================//
WORD xDate::LunarYearDays(WORD iLunarYear) 
{ 
/* 
   WORD days=348 ; //12*29 
   int month = 12 ; 
    
   //如果iYear年有闰月，则为13个月 
   if(gLanarMonth[iYear - START_YEAR]) 
      month ++; 
   //如果某月是三十天则days++ 
   while(month >=0 && (gLanarMonthDay[iYear - START_YEAR] & (1 << (16 - month)))) 
   { 
      days ++; 
      month --; 
   } 
   return days; 
*/ 
   WORD days =0; 
   for(WORD i=1; i<=12; i++) 
   { 
      LONG tmp = LunarMonthDays(iLunarYear ,i); 
      days += HIWORD(tmp); 
      days += LOWORD(tmp); 
   } 
   return days; 
} 
//===========================================================================//
void xDate::FormatLunarYear(WORD iYear, char *pBuffer) 
{ 
   char szText1[]="甲乙丙丁戊己庚辛壬癸"; 
   char szText2[]="子丑寅卯辰巳午未申酉戌亥"; 
   char szText3[]="鼠牛虎免龙蛇马羊猴鸡狗猪"; 
    
   memcpy(pBuffer  ,szText1+((iYear-4)%10)*2,2); 
   memcpy(pBuffer+2,szText2+((iYear-4)%12)*2,2); 
   pBuffer[4]=' '; 
   memcpy(pBuffer+5,szText3+((iYear-4)%12)*2,2); 
   strcpy(pBuffer+7,"年"); 
} 
//===========================================================================//
void xDate::FormatMonth(WORD iMonth, char *pBuffer, BOOL bLunar) 
 
{ 
   if(!bLunar && iMonth==1) 
   { 
      strcpy(pBuffer, " 一月"); 
      return; 
   } 
   char szText[]="正二三四五六七八九十"; 
   if(iMonth<=10) 
   { 
      memcpy(pBuffer  ," ", 2); 
      memcpy(pBuffer+2, szText + (iMonth -1)*2, 2); 
      strcpy(pBuffer+4, "月"); 
      return; 
   } 
   if (iMonth == 11) 
      strcpy(pBuffer, "十一"); 
   else 
      strcpy(pBuffer, "十二"); 
   strcpy(pBuffer+4  , "月"); 
    
    
} 
//===========================================================================//
void xDate::FormatLunarDay(WORD iDay, char *pBuffer) 
{ 
   char szText1[]="初十廿三"; 
   char szText2[]="一二三四五六七八九十"; 
   if(iDay != 20 && iDay !=30) 
   { 
      memcpy(pBuffer  , szText1 + (iDay-1)/10*2   ,2); 
      memcpy(pBuffer+2, szText2 + ((iDay-1)%10)*2 ,2); 
      pBuffer[4]='/0'; 
   } 
   else 
   { 
      memcpy(pBuffer  , szText1 + iDay/10*2, 2); 
      strcpy(pBuffer+2, szText2 +18); 
   } 
} 
 
  
/******************************************************************************  
下面为阴历计算所需的数据,为节省存储空间,所以采用下面比较变态的存储方法.  
*******************************************************************************/  
//数组gLunarDay存入阴历1901年到2100年每年中的月天数信息，  
//阴历每月只能是29或30天，一年用12（或13）个二进制位表示，对应位为1表30天，否则为29天  
WORD gLunarMonthDay[]=  
{  
   //测试数据只有1901.1.1 --2050.12.31  
   0X4ae0, 0Xa570, 0X5268, 0Xd260, 0Xd950, 0X6aa8, 0X56a0, 0X9ad0, 0X4ae8, 0X4ae0,   //1910  
   0Xa4d8, 0Xa4d0, 0Xd250, 0Xd548, 0Xb550, 0X56a0, 0X96d0, 0X95b0, 0X49b8, 0X49b0,   //1920  
   0Xa4b0, 0Xb258, 0X6a50, 0X6d40, 0Xada8, 0X2b60, 0X9570, 0X4978, 0X4970, 0X64b0,   //1930  
   0Xd4a0, 0Xea50, 0X6d48, 0X5ad0, 0X2b60, 0X9370, 0X92e0, 0Xc968, 0Xc950, 0Xd4a0,   //1940  
   0Xda50, 0Xb550, 0X56a0, 0Xaad8, 0X25d0, 0X92d0, 0Xc958, 0Xa950, 0Xb4a8, 0X6ca0,   //1950  
   0Xb550, 0X55a8, 0X4da0, 0Xa5b0, 0X52b8, 0X52b0, 0Xa950, 0Xe950, 0X6aa0, 0Xad50,   //1960  
   0Xab50, 0X4b60, 0Xa570, 0Xa570, 0X5260, 0Xe930, 0Xd950, 0X5aa8, 0X56a0, 0X96d0,   //1970  
   0X4ae8, 0X4ad0, 0Xa4d0, 0Xd268, 0Xd250, 0Xd528, 0Xb540, 0Xb6a0, 0X96d0, 0X95b0,   //1980  
   0X49b0, 0Xa4b8, 0Xa4b0, 0Xb258, 0X6a50, 0X6d40, 0Xada0, 0Xab60, 0X9370, 0X4978,   //1990  
   0X4970, 0X64b0, 0X6a50, 0Xea50, 0X6b28, 0X5ac0, 0Xab60, 0X9368, 0X92e0, 0Xc960,   //2000  
   0Xd4a8, 0Xd4a0, 0Xda50, 0X5aa8, 0X56a0, 0Xaad8, 0X25d0, 0X92d0, 0Xc958, 0Xa950,   //2010  
   0Xb4a0, 0Xb550, 0Xb550, 0X55a8, 0X4ba0, 0Xa5b0, 0X52b8, 0X52b0, 0Xa930, 0X74a8,   //2020  
   0X6aa0, 0Xad50, 0X4da8, 0X4b60, 0X9570, 0Xa4e0, 0Xd260, 0Xe930, 0Xd530, 0X5aa0,   //2030  
   0X6b50, 0X96d0, 0X4ae8, 0X4ad0, 0Xa4d0, 0Xd258, 0Xd250, 0Xd520, 0Xdaa0, 0Xb5a0,   //2040  
   0X56d0, 0X4ad8, 0X49b0, 0Xa4b8, 0Xa4b0, 0Xaa50, 0Xb528, 0X6d20, 0Xada0, 0X55b0,   //2050  
       
};  
 
//数组gLanarMonth存放阴历1901年到2050年闰月的月份，如没有则为0，每字节存两年  
BYTE  gLunarMonth[]=  
{  
   0X00, 0X50, 0X04, 0X00, 0X20,   //1910  
   0X60, 0X05, 0X00, 0X20, 0X70,   //1920  
   0X05, 0X00, 0X40, 0X02, 0X06,   //1930  
   0X00, 0X50, 0X03, 0X07, 0X00,   //1940  
   0X60, 0X04, 0X00, 0X20, 0X70,   //1950  
   0X05, 0X00, 0X30, 0X80, 0X06,   //1960  
   0X00, 0X40, 0X03, 0X07, 0X00,   //1970  
   0X50, 0X04, 0X08, 0X00, 0X60,   //1980  
   0X04, 0X0a, 0X00, 0X60, 0X05,   //1990  
   0X00, 0X30, 0X80, 0X05, 0X00,   //2000  
   0X40, 0X02, 0X07, 0X00, 0X50,   //2010  
   0X04, 0X09, 0X00, 0X60, 0X04,   //2020  
   0X00, 0X20, 0X60, 0X05, 0X00,   //2030  
   0X30, 0Xb0, 0X06, 0X00, 0X50,   //2040  
   0X02, 0X07, 0X00, 0X50, 0X03    //2050  
};  
 
//数组gLanarHoliDay存放每年的二十四节气对应的阳历日期  
//每年的二十四节气对应的阳历日期几乎固定，平均分布于十二个月中  
//   1月          2月         3月         4月         5月         6月  
//小寒 大寒   立春  雨水   惊蛰 春分   清明 谷雨   立夏 小满   芒种 夏至  
//   7月          8月         9月         10月       11月        12月  
//小暑 大暑   立秋  处暑   白露 秋分   寒露 霜降   立冬 小雪   大雪 冬至  
/*********************************************************************************  
节气无任何确定规律,所以只好存表,要节省空间,所以....  
下面这种存法实在是太变态了,你就将就着看吧  
**********************************************************************************/  
//数据格式说明:  
//如1901年的节气为  
//  1月     2月     3月   4月    5月   6月   7月    8月   9月    10月  11月     12月  
// 6, 21, 4, 19,  6, 21, 5, 21, 6,22, 6,22, 8, 23, 8, 24, 8, 24, 8, 24 , 8, 23, 8, 22  
// 9, 6,  11,4,   9, 6,  10,6,  9,7,  9,7,  7, 8,  7, 9,  7,  9, 7,  9, 7,  8, 7, 15  
//上面第一行数据为每月节气对应日期,15减去每月第一个节气,每月第二个节气减去15得第二行  
// 这样每月两个节气对应数据都小于16,每月用一个字节存放,高位存放第一个节气数据,低位存放  
//第二个节气的数据,可得下表  
 
BYTE gLunarHolDay[]=  
{  
      0X96, 0XB4, 0X96, 0XA6, 0X97, 0X97, 0X78, 0X79, 0X79, 0X69, 0X78, 0X77,   //1901  
      0X96, 0XA4, 0X96, 0X96, 0X97, 0X87, 0X79, 0X79, 0X79, 0X69, 0X78, 0X78,   //1902  
      0X96, 0XA5, 0X87, 0X96, 0X87, 0X87, 0X79, 0X69, 0X69, 0X69, 0X78, 0X78,   //1903  
      0X86, 0XA5, 0X96, 0XA5, 0X96, 0X97, 0X88, 0X78, 0X78, 0X79, 0X78, 0X87,   //1904  
      0X96, 0XB4, 0X96, 0XA6, 0X97, 0X97, 0X78, 0X79, 0X79, 0X69, 0X78, 0X77,   //1905  
      0X96, 0XA4, 0X96, 0X96, 0X97, 0X97, 0X79, 0X79, 0X79, 0X69, 0X78, 0X78,   //1906  
      0X96, 0XA5, 0X87, 0X96, 0X87, 0X87, 0X79, 0X69, 0X69, 0X69, 0X78, 0X78,   //1907  
      0X86, 0XA5, 0X96, 0XA5, 0X96, 0X97, 0X88, 0X78, 0X78, 0X69, 0X78, 0X87,   //1908  
      0X96, 0XB4, 0X96, 0XA6, 0X97, 0X97, 0X78, 0X79, 0X79, 0X69, 0X78, 0X77,   //1909  
      0X96, 0XA4, 0X96, 0X96, 0X97, 0X97, 0X79, 0X79, 0X79, 0X69, 0X78, 0X78,   //1910  
      0X96, 0XA5, 0X87, 0X96, 0X87, 0X87, 0X79, 0X69, 0X69, 0X69, 0X78, 0X78,   //1911  
      0X86, 0XA5, 0X96, 0XA5, 0X96, 0X97, 0X88, 0X78, 0X78, 0X69, 0X78, 0X87,   //1912  
      0X95, 0XB4, 0X96, 0XA6, 0X97, 0X97, 0X78, 0X79, 0X79, 0X69, 0X78, 0X77,   //1913  
      0X96, 0XB4, 0X96, 0XA6, 0X97, 0X97, 0X79, 0X79, 0X79, 0X69, 0X78, 0X78,   //1914  
      0X96, 0XA5, 0X97, 0X96, 0X97, 0X87, 0X79, 0X79, 0X69, 0X69, 0X78, 0X78,   //1915  
      0X96, 0XA5, 0X96, 0XA5, 0X96, 0X97, 0X88, 0X78, 0X78, 0X79, 0X77, 0X87,   //1916  
      0X95, 0XB4, 0X96, 0XA6, 0X96, 0X97, 0X78, 0X79, 0X78, 0X69, 0X78, 0X87,   //1917  
      0X96, 0XB4, 0X96, 0XA6, 0X97, 0X97, 0X79, 0X79, 0X79, 0X69, 0X78, 0X77,   //1918  
      0X96, 0XA5, 0X97, 0X96, 0X97, 0X87, 0X79, 0X79, 0X69, 0X69, 0X78, 0X78,   //1919  
      0X96, 0XA5, 0X96, 0XA5, 0X96, 0X97, 0X88, 0X78, 0X78, 0X79, 0X77, 0X87,   //1920  
      0X95, 0XB4, 0X96, 0XA5, 0X96, 0X97, 0X78, 0X79, 0X78, 0X69, 0X78, 0X87,   //1921  
      0X96, 0XB4, 0X96, 0XA6, 0X97, 0X97, 0X79, 0X79, 0X79, 0X69, 0X78, 0X77,   //1922  
      0X96, 0XA4, 0X96, 0X96, 0X97, 0X87, 0X79, 0X79, 0X69, 0X69, 0X78, 0X78,   //1923  
      0X96, 0XA5, 0X96, 0XA5, 0X96, 0X97, 0X88, 0X78, 0X78, 0X79, 0X77, 0X87,   //1924  
      0X95, 0XB4, 0X96, 0XA5, 0X96, 0X97, 0X78, 0X79, 0X78, 0X69, 0X78, 0X87,   //1925  
      0X96, 0XB4, 0X96, 0XA6, 0X97, 0X97, 0X78, 0X79, 0X79, 0X69, 0X78, 0X77,   //1926  
      0X96, 0XA4, 0X96, 0X96, 0X97, 0X87, 0X79, 0X79, 0X79, 0X69, 0X78, 0X78,   //1927  
      0X96, 0XA5, 0X96, 0XA5, 0X96, 0X96, 0X88, 0X78, 0X78, 0X78, 0X87, 0X87,   //1928  
      0X95, 0XB4, 0X96, 0XA5, 0X96, 0X97, 0X88, 0X78, 0X78, 0X79, 0X77, 0X87,   //1929  
      0X96, 0XB4, 0X96, 0XA6, 0X97, 0X97, 0X78, 0X79, 0X79, 0X69, 0X78, 0X77,   //1930  
      0X96, 0XA4, 0X96, 0X96, 0X97, 0X87, 0X79, 0X79, 0X79, 0X69, 0X78, 0X78,   //1931  
      0X96, 0XA5, 0X96, 0XA5, 0X96, 0X96, 0X88, 0X78, 0X78, 0X78, 0X87, 0X87,   //1932  
      0X95, 0XB4, 0X96, 0XA5, 0X96, 0X97, 0X88, 0X78, 0X78, 0X69, 0X78, 0X87,   //1933  
      0X96, 0XB4, 0X96, 0XA6, 0X97, 0X97, 0X78, 0X79, 0X79, 0X69, 0X78, 0X77,   //1934  
      0X96, 0XA4, 0X96, 0X96, 0X97, 0X97, 0X79, 0X79, 0X79, 0X69, 0X78, 0X78,   //1935  
      0X96, 0XA5, 0X96, 0XA5, 0X96, 0X96, 0X88, 0X78, 0X78, 0X78, 0X87, 0X87,   //1936  
      0X95, 0XB4, 0X96, 0XA5, 0X96, 0X97, 0X88, 0X78, 0X78, 0X69, 0X78, 0X87,   //1937  
      0X96, 0XB4, 0X96, 0XA6, 0X97, 0X97, 0X78, 0X79, 0X79, 0X69, 0X78, 0X77,   //1938  
      0X96, 0XA4, 0X96, 0X96, 0X97, 0X97, 0X79, 0X79, 0X79, 0X69, 0X78, 0X78,   //1939  
      0X96, 0XA5, 0X96, 0XA5, 0X96, 0X96, 0X88, 0X78, 0X78, 0X78, 0X87, 0X87,   //1940  
      0X95, 0XB4, 0X96, 0XA5, 0X96, 0X97, 0X88, 0X78, 0X78, 0X69, 0X78, 0X87,   //1941  
      0X96, 0XB4, 0X96, 0XA6, 0X97, 0X97, 0X78, 0X79, 0X79, 0X69, 0X78, 0X77,   //1942  
      0X96, 0XA4, 0X96, 0X96, 0X97, 0X97, 0X79, 0X79, 0X79, 0X69, 0X78, 0X78,   //1943  
      0X96, 0XA5, 0X96, 0XA5, 0XA6, 0X96, 0X88, 0X78, 0X78, 0X78, 0X87, 0X87,   //1944  
      0X95, 0XB4, 0X96, 0XA5, 0X96, 0X97, 0X88, 0X78, 0X78, 0X79, 0X77, 0X87,   //1945  
      0X95, 0XB4, 0X96, 0XA6, 0X97, 0X97, 0X78, 0X79, 0X78, 0X69, 0X78, 0X77,   //1946  
      0X96, 0XB4, 0X96, 0XA6, 0X97, 0X97, 0X79, 0X79, 0X79, 0X69, 0X78, 0X78,   //1947  
      0X96, 0XA5, 0XA6, 0XA5, 0XA6, 0X96, 0X88, 0X88, 0X78, 0X78, 0X87, 0X87,   //1948  
      0XA5, 0XB4, 0X96, 0XA5, 0X96, 0X97, 0X88, 0X79, 0X78, 0X79, 0X77, 0X87,   //1949  
      0X95, 0XB4, 0X96, 0XA5, 0X96, 0X97, 0X78, 0X79, 0X78, 0X69, 0X78, 0X77,   //1950  
      0X96, 0XB4, 0X96, 0XA6, 0X97, 0X97, 0X79, 0X79, 0X79, 0X69, 0X78, 0X78,   //1951  
      0X96, 0XA5, 0XA6, 0XA5, 0XA6, 0X96, 0X88, 0X88, 0X78, 0X78, 0X87, 0X87,   //1952  
      0XA5, 0XB4, 0X96, 0XA5, 0X96, 0X97, 0X88, 0X78, 0X78, 0X79, 0X77, 0X87,   //1953  
      0X95, 0XB4, 0X96, 0XA5, 0X96, 0X97, 0X78, 0X79, 0X78, 0X68, 0X78, 0X87,   //1954  
      0X96, 0XB4, 0X96, 0XA6, 0X97, 0X97, 0X78, 0X79, 0X79, 0X69, 0X78, 0X77,   //1955  
      0X96, 0XA5, 0XA5, 0XA5, 0XA6, 0X96, 0X88, 0X88, 0X78, 0X78, 0X87, 0X87,   //1956  
      0XA5, 0XB4, 0X96, 0XA5, 0X96, 0X97, 0X88, 0X78, 0X78, 0X79, 0X77, 0X87,   //1957  
      0X95, 0XB4, 0X96, 0XA5, 0X96, 0X97, 0X88, 0X78, 0X78, 0X69, 0X78, 0X87,   //1958  
      0X96, 0XB4, 0X96, 0XA6, 0X97, 0X97, 0X78, 0X79, 0X79, 0X69, 0X78, 0X77,   //1959  
      0X96, 0XA4, 0XA5, 0XA5, 0XA6, 0X96, 0X88, 0X88, 0X88, 0X78, 0X87, 0X87,   //1960  
      0XA5, 0XB4, 0X96, 0XA5, 0X96, 0X96, 0X88, 0X78, 0X78, 0X78, 0X87, 0X87,   //1961  
      0X96, 0XB4, 0X96, 0XA5, 0X96, 0X97, 0X88, 0X78, 0X78, 0X69, 0X78, 0X87,   //1962  
      0X96, 0XB4, 0X96, 0XA6, 0X97, 0X97, 0X78, 0X79, 0X79, 0X69, 0X78, 0X77,   //1963  
      0X96, 0XA4, 0XA5, 0XA5, 0XA6, 0X96, 0X88, 0X88, 0X88, 0X78, 0X87, 0X87,   //1964  
      0XA5, 0XB4, 0X96, 0XA5, 0X96, 0X96, 0X88, 0X78, 0X78, 0X78, 0X87, 0X87,   //1965  
      0X95, 0XB4, 0X96, 0XA5, 0X96, 0X97, 0X88, 0X78, 0X78, 0X69, 0X78, 0X87,   //1966  
      0X96, 0XB4, 0X96, 0XA6, 0X97, 0X97, 0X78, 0X79, 0X79, 0X69, 0X78, 0X77,   //1967  
      0X96, 0XA4, 0XA5, 0XA5, 0XA6, 0XA6, 0X88, 0X88, 0X88, 0X78, 0X87, 0X87,   //1968  
      0XA5, 0XB4, 0X96, 0XA5, 0X96, 0X96, 0X88, 0X78, 0X78, 0X78, 0X87, 0X87,   //1969  
      0X95, 0XB4, 0X96, 0XA5, 0X96, 0X97, 0X88, 0X78, 0X78, 0X69, 0X78, 0X87,   //1970  
      0X96, 0XB4, 0X96, 0XA6, 0X97, 0X97, 0X78, 0X79, 0X79, 0X69, 0X78, 0X77,   //1971  
      0X96, 0XA4, 0XA5, 0XA5, 0XA6, 0XA6, 0X88, 0X88, 0X88, 0X78, 0X87, 0X87,   //1972  
      0XA5, 0XB5, 0X96, 0XA5, 0XA6, 0X96, 0X88, 0X78, 0X78, 0X78, 0X87, 0X87,   //1973  
      0X95, 0XB4, 0X96, 0XA5, 0X96, 0X97, 0X88, 0X78, 0X78, 0X69, 0X78, 0X87,   //1974  
      0X96, 0XB4, 0X96, 0XA6, 0X97, 0X97, 0X78, 0X79, 0X78, 0X69, 0X78, 0X77,   //1975  
      0X96, 0XA4, 0XA5, 0XB5, 0XA6, 0XA6, 0X88, 0X89, 0X88, 0X78, 0X87, 0X87,   //1976  
      0XA5, 0XB4, 0X96, 0XA5, 0X96, 0X96, 0X88, 0X88, 0X78, 0X78, 0X87, 0X87,   //1977  
      0X95, 0XB4, 0X96, 0XA5, 0X96, 0X97, 0X88, 0X78, 0X78, 0X79, 0X78, 0X87,   //1978  
      0X96, 0XB4, 0X96, 0XA6, 0X96, 0X97, 0X78, 0X79, 0X78, 0X69, 0X78, 0X77,   //1979  
      0X96, 0XA4, 0XA5, 0XB5, 0XA6, 0XA6, 0X88, 0X88, 0X88, 0X78, 0X87, 0X87,   //1980  
      0XA5, 0XB4, 0X96, 0XA5, 0XA6, 0X96, 0X88, 0X88, 0X78, 0X78, 0X77, 0X87,   //1981  
      0X95, 0XB4, 0X96, 0XA5, 0X96, 0X97, 0X88, 0X78, 0X78, 0X79, 0X77, 0X87,   //1982  
      0X95, 0XB4, 0X96, 0XA5, 0X96, 0X97, 0X78, 0X79, 0X78, 0X69, 0X78, 0X77,   //1983  
      0X96, 0XB4, 0XA5, 0XB5, 0XA6, 0XA6, 0X87, 0X88, 0X88, 0X78, 0X87, 0X87,   //1984  
      0XA5, 0XB4, 0XA6, 0XA5, 0XA6, 0X96, 0X88, 0X88, 0X78, 0X78, 0X87, 0X87,   //1985  
      0XA5, 0XB4, 0X96, 0XA5, 0X96, 0X97, 0X88, 0X78, 0X78, 0X79, 0X77, 0X87,   //1986  
      0X95, 0XB4, 0X96, 0XA5, 0X96, 0X97, 0X88, 0X79, 0X78, 0X69, 0X78, 0X87,   //1987  
      0X96, 0XB4, 0XA5, 0XB5, 0XA6, 0XA6, 0X87, 0X88, 0X88, 0X78, 0X87, 0X86,   //1988  
      0XA5, 0XB4, 0XA5, 0XA5, 0XA6, 0X96, 0X88, 0X88, 0X88, 0X78, 0X87, 0X87,   //1989  
      0XA5, 0XB4, 0X96, 0XA5, 0X96, 0X96, 0X88, 0X78, 0X78, 0X79, 0X77, 0X87,   //1990  
      0X95, 0XB4, 0X96, 0XA5, 0X86, 0X97, 0X88, 0X78, 0X78, 0X69, 0X78, 0X87,   //1991  
      0X96, 0XB4, 0XA5, 0XB5, 0XA6, 0XA6, 0X87, 0X88, 0X88, 0X78, 0X87, 0X86,   //1992  
      0XA5, 0XB3, 0XA5, 0XA5, 0XA6, 0X96, 0X88, 0X88, 0X88, 0X78, 0X87, 0X87,   //1993  
      0XA5, 0XB4, 0X96, 0XA5, 0X96, 0X96, 0X88, 0X78, 0X78, 0X78, 0X87, 0X87,   //1994  
      0X95, 0XB4, 0X96, 0XA5, 0X96, 0X97, 0X88, 0X76, 0X78, 0X69, 0X78, 0X87,   //1995  
      0X96, 0XB4, 0XA5, 0XB5, 0XA6, 0XA6, 0X87, 0X88, 0X88, 0X78, 0X87, 0X86,   //1996  
      0XA5, 0XB3, 0XA5, 0XA5, 0XA6, 0XA6, 0X88, 0X88, 0X88, 0X78, 0X87, 0X87,   //1997  
      0XA5, 0XB4, 0X96, 0XA5, 0X96, 0X96, 0X88, 0X78, 0X78, 0X78, 0X87, 0X87,   //1998  
      0X95, 0XB4, 0X96, 0XA5, 0X96, 0X97, 0X88, 0X78, 0X78, 0X69, 0X78, 0X87,   //1999  
      0X96, 0XB4, 0XA5, 0XB5, 0XA6, 0XA6, 0X87, 0X88, 0X88, 0X78, 0X87, 0X86,   //2000  
      0XA5, 0XB3, 0XA5, 0XA5, 0XA6, 0XA6, 0X88, 0X88, 0X88, 0X78, 0X87, 0X87,   //2001  
      0XA5, 0XB4, 0X96, 0XA5, 0X96, 0X96, 0X88, 0X78, 0X78, 0X78, 0X87, 0X87,   //2002  
      0X95, 0XB4, 0X96, 0XA5, 0X96, 0X97, 0X88, 0X78, 0X78, 0X69, 0X78, 0X87,   //2003  
      0X96, 0XB4, 0XA5, 0XB5, 0XA6, 0XA6, 0X87, 0X88, 0X88, 0X78, 0X87, 0X86,   //2004  
      0XA5, 0XB3, 0XA5, 0XA5, 0XA6, 0XA6, 0X88, 0X88, 0X88, 0X78, 0X87, 0X87,   //2005  
      0XA5, 0XB4, 0X96, 0XA5, 0XA6, 0X96, 0X88, 0X88, 0X78, 0X78, 0X87, 0X87,   //2006  
      0X95, 0XB4, 0X96, 0XA5, 0X96, 0X97, 0X88, 0X78, 0X78, 0X69, 0X78, 0X87,   //2007  
      0X96, 0XB4, 0XA5, 0XB5, 0XA6, 0XA6, 0X87, 0X88, 0X87, 0X78, 0X87, 0X86,   //2008  
      0XA5, 0XB3, 0XA5, 0XB5, 0XA6, 0XA6, 0X88, 0X88, 0X88, 0X78, 0X87, 0X87,   //2009  
      0XA5, 0XB4, 0X96, 0XA5, 0XA6, 0X96, 0X88, 0X88, 0X78, 0X78, 0X87, 0X87,   //2010  
      0X95, 0XB4, 0X96, 0XA5, 0X96, 0X97, 0X88, 0X78, 0X78, 0X79, 0X78, 0X87,   //2011  
      0X96, 0XB4, 0XA5, 0XB5, 0XA5, 0XA6, 0X87, 0X88, 0X87, 0X78, 0X87, 0X86,   //2012  
      0XA5, 0XB3, 0XA5, 0XB5, 0XA6, 0XA6, 0X87, 0X88, 0X88, 0X78, 0X87, 0X87,   //2013  
      0XA5, 0XB4, 0X96, 0XA5, 0XA6, 0X96, 0X88, 0X88, 0X78, 0X78, 0X87, 0X87,   //2014  
      0X95, 0XB4, 0X96, 0XA5, 0X96, 0X97, 0X88, 0X78, 0X78, 0X79, 0X77, 0X87,   //2015  
      0X95, 0XB4, 0XA5, 0XB4, 0XA5, 0XA6, 0X87, 0X88, 0X87, 0X78, 0X87, 0X86,   //2016  
      0XA5, 0XC3, 0XA5, 0XB5, 0XA6, 0XA6, 0X87, 0X88, 0X88, 0X78, 0X87, 0X87,   //2017  
      0XA5, 0XB4, 0XA6, 0XA5, 0XA6, 0X96, 0X88, 0X88, 0X78, 0X78, 0X87, 0X87,   //2018  
      0XA5, 0XB4, 0X96, 0XA5, 0X96, 0X96, 0X88, 0X78, 0X78, 0X79, 0X77, 0X87,   //2019  
      0X95, 0XB4, 0XA5, 0XB4, 0XA5, 0XA6, 0X97, 0X87, 0X87, 0X78, 0X87, 0X86,   //2020  
      0XA5, 0XC3, 0XA5, 0XB5, 0XA6, 0XA6, 0X87, 0X88, 0X88, 0X78, 0X87, 0X86,   //2021  
      0XA5, 0XB4, 0XA5, 0XA5, 0XA6, 0X96, 0X88, 0X88, 0X88, 0X78, 0X87, 0X87,   //2022  
      0XA5, 0XB4, 0X96, 0XA5, 0X96, 0X96, 0X88, 0X78, 0X78, 0X79, 0X77, 0X87,   //2023  
      0X95, 0XB4, 0XA5, 0XB4, 0XA5, 0XA6, 0X97, 0X87, 0X87, 0X78, 0X87, 0X96,   //2024  
      0XA5, 0XC3, 0XA5, 0XB5, 0XA6, 0XA6, 0X87, 0X88, 0X88, 0X78, 0X87, 0X86,   //2025  
      0XA5, 0XB3, 0XA5, 0XA5, 0XA6, 0XA6, 0X88, 0X88, 0X88, 0X78, 0X87, 0X87,   //2026  
      0XA5, 0XB4, 0X96, 0XA5, 0X96, 0X96, 0X88, 0X78, 0X78, 0X78, 0X87, 0X87,   //2027  
      0X95, 0XB4, 0XA5, 0XB4, 0XA5, 0XA6, 0X97, 0X87, 0X87, 0X78, 0X87, 0X96,   //2028  
      0XA5, 0XC3, 0XA5, 0XB5, 0XA6, 0XA6, 0X87, 0X88, 0X88, 0X78, 0X87, 0X86,   //2029  
      0XA5, 0XB3, 0XA5, 0XA5, 0XA6, 0XA6, 0X88, 0X88, 0X88, 0X78, 0X87, 0X87,   //2030  
      0XA5, 0XB4, 0X96, 0XA5, 0X96, 0X96, 0X88, 0X78, 0X78, 0X78, 0X87, 0X87,   //2031  
      0X95, 0XB4, 0XA5, 0XB4, 0XA5, 0XA6, 0X97, 0X87, 0X87, 0X78, 0X87, 0X96,   //2032  
      0XA5, 0XC3, 0XA5, 0XB5, 0XA6, 0XA6, 0X88, 0X88, 0X88, 0X78, 0X87, 0X86,   //2033  
      0XA5, 0XB3, 0XA5, 0XA5, 0XA6, 0XA6, 0X88, 0X78, 0X88, 0X78, 0X87, 0X87,   //2034  
      0XA5, 0XB4, 0X96, 0XA5, 0XA6, 0X96, 0X88, 0X88, 0X78, 0X78, 0X87, 0X87,   //2035  
      0X95, 0XB4, 0XA5, 0XB4, 0XA5, 0XA6, 0X97, 0X87, 0X87, 0X78, 0X87, 0X96,   //2036  
      0XA5, 0XC3, 0XA5, 0XB5, 0XA6, 0XA6, 0X87, 0X88, 0X88, 0X78, 0X87, 0X86,   //2037  
      0XA5, 0XB3, 0XA5, 0XA5, 0XA6, 0XA6, 0X88, 0X88, 0X88, 0X78, 0X87, 0X87,   //2038  
      0XA5, 0XB4, 0X96, 0XA5, 0XA6, 0X96, 0X88, 0X88, 0X78, 0X78, 0X87, 0X87,   //2039  
      0X95, 0XB4, 0XA5, 0XB4, 0XA5, 0XA6, 0X97, 0X87, 0X87, 0X78, 0X87, 0X96,   //2040  
      0XA5, 0XC3, 0XA5, 0XB5, 0XA5, 0XA6, 0X87, 0X88, 0X87, 0X78, 0X87, 0X86,   //2041  
      0XA5, 0XB3, 0XA5, 0XB5, 0XA6, 0XA6, 0X88, 0X88, 0X88, 0X78, 0X87, 0X87,   //2042  
      0XA5, 0XB4, 0X96, 0XA5, 0XA6, 0X96, 0X88, 0X88, 0X78, 0X78, 0X87, 0X87,   //2043  
      0X95, 0XB4, 0XA5, 0XB4, 0XA5, 0XA6, 0X97, 0X87, 0X87, 0X88, 0X87, 0X96,   //2044  
      0XA5, 0XC3, 0XA5, 0XB4, 0XA5, 0XA6, 0X87, 0X88, 0X87, 0X78, 0X87, 0X86,   //2045  
      0XA5, 0XB3, 0XA5, 0XB5, 0XA6, 0XA6, 0X87, 0X88, 0X88, 0X78, 0X87, 0X87,   //2046  
      0XA5, 0XB4, 0X96, 0XA5, 0XA6, 0X96, 0X88, 0X88, 0X78, 0X78, 0X87, 0X87,   //2047  
      0X95, 0XB4, 0XA5, 0XB4, 0XA5, 0XA5, 0X97, 0X87, 0X87, 0X88, 0X86, 0X96,   //2048  
      0XA4, 0XC3, 0XA5, 0XA5, 0XA5, 0XA6, 0X97, 0X87, 0X87, 0X78, 0X87, 0X86,   //2049  
      0XA5, 0XC3, 0XA5, 0XB5, 0XA6, 0XA6, 0X87, 0X88, 0X78, 0X78, 0X87, 0X87    //2050  
       
};