#ifndef XDATE_H
#define XDATE_H

// using namespace std; 

#include <windows.h>
extern const WORD START_YEAR;
extern const WORD END_YEAR;
//农历公历互转
class xDate
{
private:
   WORD m_iYear, m_iMonth, m_iDay;
   void l_InitData();
   // 计算从1901年1月1日过iSpanDays天后的阴历日期
   static void l_CalcLunarDate(WORD &iYear, WORD &iMonth, WORD &iDay, LONG iSpanDays);
   // 计算公历iYear年iMonth月iDay日对应的节气 0-24，0表不是节气
   static WORD l_GetLunarHolDay(WORD iYear, WORD iMonth, WORD iDay);

public:
   //===================================================================================//
   xDate(WORD iYear, WORD iMonth, WORD iDay);
   xDate();
   //===================================================================================//

   WORD GetYear() { return m_iYear; }
   WORD GetMonth() { return m_iMonth; }
   WORD GetDay() { return m_iDay; }

   //=====================================================================================//
   void GetDate(WORD &iYear, WORD &iMonth, WORD &iDay);
   BOOL SetDate(WORD iYear, WORD iMonth, WORD iDay);
   //=====================================================================================//
   // 判断iYear是不是闰年
   static BOOL IsLeapYear(WORD iYear) { return !(iYear % 4) && (iYear % 100) || !(iYear % 400); }

   // 计算iYear,iMonth,iDay对应是星期几 1年1月1日 --- 65535年12月31日
   static WORD WeekDay(WORD iYear, WORD iMonth, WORD iDay);

   // 返回iYear年iMonth月的天数 1年1月 --- 65535年12月
   static WORD MonthDays(WORD iYear, WORD iMonth);

   // 返回阴历iLunarYer年阴历iLunarMonth月的天数，如果iLunarMonth为闰月，
   // 高字为第二个iLunarMonth月的天数，否则高字为0
   //  1901年1月---2050年12月
   static LONG LunarMonthDays(WORD iLunarYear, WORD iLunarMonth);

   // 返回阴历iLunarYear年的总天数
   //  1901年1月---2050年12月
   static WORD LunarYearDays(WORD iLunarYear);

   // 返回阴历iLunarYear年的闰月月份，如没有返回0
   //  1901年1月---2050年12月
   static WORD GetLeapMonth(WORD iLunarYear);

   // 把iYear年格式化成天干记年法表示的字符串
   static void FormatLunarYear(WORD iYear, char *pBuffer);

   // 把iMonth格式化成中文字符串
   static void FormatMonth(WORD iMonth, char *pBuffer, BOOL bLunar = TRUE);

   // 把iDay格式化成中文字符串
   static void FormatLunarDay(WORD iDay, char *pBuffer);

   // 计算公历两个日期间相差的天数  1年1月1日 --- 65535年12月31日
   static LONG CalcDateDiff(WORD iEndYear, WORD iEndMonth, WORD iEndDay, WORD iStartYear = START_YEAR, WORD iStartMonth = 1, WORD iStartDay = 1);

   // 计算公历iYear年iMonth月iDay日对应的阴历日期,返回对应的阴历节气 0-24
   // 1901年1月1日---2050年12月31日
   static WORD GetLunarDate(WORD iYear, WORD iMonth, WORD iDay, WORD &iLunarYear, WORD &iLunarMonth, WORD &iLunarDay);
};

#endif // XDATE_H
