#include <iostream>
#include "sizhu.h"
#include <cmath>
#include "Stars.h"

// 每月的天数计算，a为年，b为月
int Days(int a, int b)
{
    switch (b)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
    case 0:
        return 31;
    case 4:
    case 6:
    case 9:
    case 11:
        return 30;
    case 2:
        switch (a % 4)
        {
        case 0:
            if (a % 100 == 0 && a % 400 != 0)
                return 28;
            else
                return 29;

        default:
            return 28;
        }
    default:
        std::cout << "不是合法的月份";
        return 0; // 这里数据不合法，返回0。
        break;
    }
}

sizhu::sizhu(unsigned long long BBirthTime /* =199002231934 */, double LLongitude /* =120.0 */)
{
    _BirthTime = BBirthTime;
    _Longitude = LLongitude;

    _Minute = _BirthTime % 100;
    _Hour = (_BirthTime / 100) % 100;
    _Day = (_BirthTime / 10000) % 100;
    _Month = (_BirthTime / 1000000) % 100;
    _Year = _BirthTime / 100000000;

    // *********************接下来要对数据合法性进行审查************************//
    if (_Minute > 59)
    {
        std::cout << "输入的分钟不合法";
    }
    if (_Hour > 23)
    {
        std::cout << "输入的小时不合法";
    }
    if (_Day > Days(_Year, _Month) || _Day == 0)
    {
        std::cout << "输入的日期不合法";
    }
    if (_Month == 0 || _Month > 12)
    {
        std::cout << "输入的月份不合法";
    }

    // *************************接下来要进行真太阳时的求解*************************

    // 先计算小时和分的变化
    int ChangeOfHour, ChangeOfMinute;
    ChangeOfHour = static_cast<int>((_Longitude - 120.0) * 4) / 60;
    ChangeOfMinute = static_cast<int>((_Longitude - 120.0) * 4) % 60; // 结果在+-60之间。

    // 此处计算分钟
    _RMinute = (120 + /* 这是为了保证求解余数的结果为正 */ _Minute + ChangeOfMinute) % 60;

    int CChangeOfDay, CChangeOfMonth, CChangeOfYear;
    // 此处计算小时进位，要判断进位还是退位
    if ((_Minute + ChangeOfMinute) >= 60) // 进一位
    {
        _RHour = (48 + /* 这是为了保证结果为正 */ _Hour + ChangeOfHour + 1) % 24;
        if ((_Hour + ChangeOfHour + 1) >= 24)
        {
            CChangeOfDay = 1;
        }
        else
        {
            if ((_Hour + ChangeOfHour + 1) < 0)
            {
                CChangeOfDay = -1;
            }
            else
            {
                CChangeOfDay = 0;
            }
        }
    }
    else
    {
        if ((_Minute + ChangeOfMinute) < 0) // 退一位
        {
            _RHour = (48 + /* 这是为了保证结果为正 */ _Hour + ChangeOfHour - 1) % 24;
            if ((_Hour + ChangeOfHour - 1) >= 24)
            {
                CChangeOfDay = 1;
            }
            else
            {
                if ((_Hour + ChangeOfHour - 1) < 0)
                {
                    CChangeOfDay = -1;
                }
                else
                {
                    CChangeOfDay = 0;
                }
            }
        }
        else // 不进不退
        {
            _RHour = (48 + /* 这是为了保证结果为正 */ _Hour + ChangeOfHour) % 24;
            if ((_Hour + ChangeOfHour) >= 24)
            {
                CChangeOfDay = 1;
            }
            else
            {
                if ((_Hour + ChangeOfHour) < 0)
                {
                    CChangeOfDay = -1;
                }
                else
                {
                    CChangeOfDay = 0;
                }
            }
        }
    }

    // 此处进行天的进位
    if ((_Day + CChangeOfDay) > Days(_Year, _Month))
    {
        _RDay = (_Day + CChangeOfDay) % Days(_Year, _Month);
        CChangeOfMonth = 1;
    }
    else
    {
        if ((_Day + CChangeOfDay) == 0) // 当变为某月0号时
        {
            _RDay = Days(_Year, _Month - 1); // 变为同年上一月，若本来月份为1，则返回31，因为变为12月。
            CChangeOfMonth = -1;
        }
        else
        {
            _RDay = _Day + CChangeOfDay;
            CChangeOfMonth = 0;
        }
    }

    // 此处进行月的进位。
    if ((_Month + CChangeOfMonth) > 12)
    {
        _RMonth = 1;
        CChangeOfYear = 1;
    }
    else
    {
        if ((_Month + CChangeOfMonth) == 0)
        {
            _RMonth = 12;
            CChangeOfYear = -1;
        }
        else
        {
            _RMonth = _Month + CChangeOfMonth;
            CChangeOfYear = 0;
        }
    }
    _RYear = _Year + CChangeOfYear;

    //************************这里已经把真太阳时全部计算完毕*************************//
    // 此处为了计算月干支，使用了农历信息，注意GetLunarDate是传引用。


    xDate::GetLunarDate(_RYear, _RMonth, _RDay, LYear, LMonth, LDay);
    // 如果对应了闰月，那么在天数一半之前，算前一月，在天数一半之后，算后一月。
    if (LMonth == xDate::GetLeapMonth(_RYear))
    {
        if (LDay > 15)
        {
            LMonth++;
        }
    }

    //*******************************接下来计算八字***************************************//

    // *****************************计算年干*********************************
    // switch ((_RYear - 3) % 10)
    // {
    // case 1:
    //     _NiGan = TianGan::Jia;
    //     break;
    // case 2:
    //     _NiGan = TianGan::Yi;
    //     break;
    // case 3:
    //     _NiGan = TianGan::Bing;
    //     break;
    // case 4:
    //     _NiGan = TianGan::Ding;
    //     break;
    // case 5:
    //     _NiGan = TianGan::Wu;
    //     break;
    // case 6:
    //     _NiGan = TianGan::Ji;
    //     break;
    // case 7:
    //     _NiGan = TianGan::Geng;
    //     break;
    // case 8:
    //     _NiGan = TianGan::Xin;
    //     break;
    // case 9:
    //     _NiGan = TianGan::Ren;
    //     break;
    // case 0:
    //     _NiGan = TianGan::Kui;
    //     break;
    // default: /* throw std::invalid_argument("Invalid month number"); */
    //     // 注意这里有对异常信息的处理。
    //     break;
    // }
    _NianGan = static_cast<TianGan>(((_RYear - 3) % 10) ? ((_RYear - 3) % 10) : 10);

    // *****************************计算年支*********************************
    // switch ((_RYear - 3) % 12)
    // {
    // case 1:
    //     _NianZhi = DiZhi::Zi;
    //     break;
    // case 2:
    //     _NianZhi = DiZhi::Chou;
    //     break;
    // case 3:
    //     _NianZhi = DiZhi::Yin;
    //     break;
    // case 4:
    //     _NianZhi = DiZhi::Mao;
    //     break;
    // case 5:
    //     _NianZhi = DiZhi::Chen;
    //     break;
    // case 6:
    //     _NianZhi = DiZhi::Si;
    //     break;
    // case 7:
    //     _NianZhi = DiZhi::Wu;
    //     break;
    // case 8:
    //     _NianZhi = DiZhi::Wei;
    //     break;
    // case 9:
    //     _NianZhi = DiZhi::Shen;
    //     break;
    // case 10:
    //     _NianZhi = DiZhi::You;
    //     break;
    // case 11:
    //     _NianZhi = DiZhi::Xu;
    //     break;
    // case 0:
    //     _NianZhi = DiZhi::Hai;
    //     break;
    // default: /* throw std::invalid_argument("Invalid month number"); */
    //     // 注意这里有对异常信息的处理。
    //     break;
    // }
    _NianZhi = static_cast<DiZhi>(((_RYear - 3) % 12) ? (_RYear - 3) % 12 : 12);

    //******************************计算月干********************************
    // switch (_NiGan)
    // {
    // case TianGan::Jia:
    // case TianGan::Ji:
    //     _YueGan = static_cast<TianGan>((LMonth + 1) % 10 + 1);
    //     break;
    // case TianGan::Yi:
    // case TianGan::Geng:
    //     _YueGan = static_cast<TianGan>((LMonth + 3) % 10 + 1);
    //     break;

    // case TianGan::Bing:
    // case TianGan::Xin:
    //     _YueGan = static_cast<TianGan>((LMonth + 5) % 10 + 1);
    //     break;
    // case TianGan::Ding:
    // case TianGan::Ren:
    //     _YueGan = static_cast<TianGan>((LMonth + 7) % 10 + 1);
    //     break;
    // case TianGan::Wu:
    // case TianGan::Kui:
    //     _YueGan = static_cast<TianGan>((LMonth + 9) % 10 + 1);
    //     break;

    // default: /* throw std::invalid_argument("Invalid month number"); */
    //     // 注意这里有对异常信息的处理。
    //     break;
    // }

    _YueGan = static_cast<TianGan>((LMonth + (static_cast<int>(_NianGan) % 5 ? static_cast<int>(_NianGan) % 5 : 5) * 2 - 1) % 10 + 1);

    // *****************************计算月支********************************
    //  每个月的地支是固定的
    //  11月为子，12月为丑，1月为寅，以此类推
    // switch (LMonth)
    // {
    // case 11:
    //     _YueZhi = DiZhi::Zi;
    //     break;
    // case 12:
    //     _YueZhi = DiZhi::Chou;
    //     break;
    // case 1:
    //     _YueZhi = DiZhi::Yin;
    //     break;
    // case 2:
    //     _YueZhi = DiZhi::Mao;
    //     break;
    // case 3:
    //     _YueZhi = DiZhi::Chen;
    //     break;
    // case 4:
    //     _YueZhi = DiZhi::Si;
    //     break;
    // case 5:
    //     _YueZhi = DiZhi::Wu;
    //     break;
    // case 6:
    //     _YueZhi = DiZhi::Wei;
    //     break;
    // case 7:
    //     _YueZhi = DiZhi::Shen;
    //     break;
    // case 8:
    //     _YueZhi = DiZhi::You;
    //     break;
    // case 9:
    //     _YueZhi = DiZhi::Xu;
    //     break;
    // case 10:
    //     _YueZhi = DiZhi::Hai;
    //     break;
    // default: /* throw std::invalid_argument("Invalid month number"); */
    //     // 注意这里有对异常信息的处理。
    //     break;
    // }
    _YueZhi = static_cast<DiZhi>((LMonth + 2) % 12 ? (LMonth + 2) : 12);

    //****************************计算天干天支******************************//

    // int a = ((100 + _RYear % 100) * 5) % 60;
    // int b = (100 + _RYear % 100) / 4;
    // int c = 0;
    // switch (_RMonth)
    // {
    // case 1:
    // case 2:
    // case 3:
    //     c = 0;
    //     break;
    // case 4:
    // case 5:
    //     c = 1;
    //     break;
    // case 6:
    // case 7:
    //     c = 2;
    //     break;
    // case 8:
    //     c = 3;
    //     break;
    // case 9:
    // case 10:
    //     c = 4;
    //     break;
    // case 11:
    // case 12:
    //     c = 5;
    //     break;
    // default:
    //     break;
    // }
    // int d = (60 + a + b + 9 + _RDay + c - ((_RMonth % 2) ? 0 : 30)) % 60;

    int d = (xDate::CalcDateDiff(_RYear, _RMonth, _RDay, 1901, 12, 11)) % 60;
    _RiGan = static_cast<TianGan>(((d - 1) % 10 + 1) ? ((d - 1) % 10 + 1) : 10);
    _RiZhi = static_cast<DiZhi>(((d - 1) % 12 + 1) ? ((d - 1) % 12 + 1) : 12);

    //*************************下面计算时干****************************************

    // switch (_RiGan)
    // {
    // case TianGan::Jia:
    // case TianGan::Ji:
    //     _ShiGan = static_cast<TianGan>((((_RHour + 1) % 24) / 2) % 10 + 1);
    //     break;
    // case TianGan::Yi:
    // case TianGan::Geng:
    //     _ShiGan = static_cast<TianGan>((((_RHour + 1) % 24) / 2 + 2) % 10 + 1);
    //     break;
    // case TianGan::Bing:
    // case TianGan::Xin:
    //     _ShiGan = static_cast<TianGan>((((_RHour + 1) % 24) / 2 + 4) % 10 + 1);
    //     break;
    // case TianGan::Ding:
    // case TianGan::Ren:
    //     _ShiGan = static_cast<TianGan>((((_RHour + 1) % 24) / 2 + 6) % 10 + 1);
    //     break;
    // case TianGan::Wu:
    // case TianGan::Kui:
    //     _ShiGan = static_cast<TianGan>((((_RHour + 1) % 24) / 2 + 8) % 10 + 1);
    //     break;
    // default:
    //     break;
    // }

    _ShiGan = static_cast<TianGan>((((_RHour + 1) % 24) / 2 + ((static_cast<int>(_RiGan) - 1) % 5) * 2) % 10 + 1);
    //*************************下面计算时支****************************************

    _ShiZhi = static_cast<DiZhi>(((_RHour + 1) % 24) / 2 + 1);
}
