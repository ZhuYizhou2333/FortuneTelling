#ifndef SI_ZHU
#define SI_ZHU
#include "xDate.h"

// 天干枚举类型
enum class TianGan
{
    Jia = 1,
    Yi,
    Bing,
    Ding,
    Wu,
    Ji,
    Geng,
    Xin,
    Ren,
    Kui
};
// 地支枚举类型
enum class DiZhi
{
    Zi = 1,
    Chou,
    Yin,
    Mao,
    Chen,
    Si,
    Wu,
    Wei,
    Shen,
    You,
    Xu,
    Hai
};

class sizhu
{
private:
    // 外界传进来生时,样例格式为：199005162312，即1990年，5月16日，23点12分。一共12位数字。
    long long _BirthTime;

    // 考虑把年，月，日，时，分设为五个整数。
    int _Year, _Month, _Day, _Hour, _Minute;

    // 考虑把真年，月，日，时，分设为五个整数。
    int _RYear, _RMonth, _RDay, _RHour, _RMinute;

    // 外界传进来经度
    double _Longitude;

public:
    sizhu(unsigned long long BBirthTime = 199002231934, double LLongitude = 120.0); // 北京时间东八区东经120°。
    // 四柱中的天干
    TianGan _NianGan, _YueGan, _RiGan, _ShiGan;
    // 四柱中的地支
    DiZhi _NianZhi, _YueZhi, _RiZhi, _ShiZhi;
    //农历年份等
    WORD LYear, LMonth, LDay;
};
// 每月的天数计算，a为年，b为月
int Days(int a, int b);

#endif