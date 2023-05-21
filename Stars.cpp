#include <iostream>
#include "Stars.h"
#include "sizhu.h"
StarBase::StarBase()
{

} // 我在这里不写构造函数是不是也可以？直接在后面初始化？因为基类构造函数太简单了。

BodyPalace::BodyPalace(DiZhi YYueZhi, DiZhi SShiZhi) : StarBase()
{
    // 接下来计算身宫的信息
    Palace = static_cast<DiZhi>((static_cast<int>(YYueZhi) - 1 + static_cast<int>(SShiZhi) + 11) % 12 + 1);
    Name = "身宫";
}

LifePalace::LifePalace(DiZhi YYueZhi, DiZhi SShiZhi) : StarBase()
{
    // 接下来计算命宫的信息
    Palace = static_cast<DiZhi>((static_cast<int>(YYueZhi) + 1 - static_cast<int>(SShiZhi) + 23) % 12 + 1);
    Name = "命宫";
}

BrotherPalace::BrotherPalace(DiZhi YYueZhi, DiZhi SShiZhi) : StarBase()
{
    // 接下来计算兄弟宫的信息
    Palace = static_cast<DiZhi>((static_cast<int>(YYueZhi) + 1 - static_cast<int>(SShiZhi) + 23 - 1) % 12 + 1);
    Name = "兄弟宫";
}

CouplePalace::CouplePalace(DiZhi YYueZhi, DiZhi SShiZhi) : StarBase()
{
    // 接下来计算夫妻宫的信息
    Palace = static_cast<DiZhi>((static_cast<int>(YYueZhi) + 1 - static_cast<int>(SShiZhi) + 23 - 2) % 12 + 1);
    Name = "夫妻宫";
}

ChildrenPalace::ChildrenPalace(DiZhi YYueZhi, DiZhi SShiZhi) : StarBase()
{
    // 接下来计算子女宫的信息
    Palace = static_cast<DiZhi>((static_cast<int>(YYueZhi) + 1 - static_cast<int>(SShiZhi) + 23 - 3) % 12 + 1);
    Name = "子女宫";
}

MoneyPalace::MoneyPalace(DiZhi YYueZhi, DiZhi SShiZhi) : StarBase()
{
    // 接下来计算财帛宫的信息
    Palace = static_cast<DiZhi>((static_cast<int>(YYueZhi) + 1 - static_cast<int>(SShiZhi) + 23 - 4) % 12 + 1);
    Name = "财帛宫";
}

DiseasePalace::DiseasePalace(DiZhi YYueZhi, DiZhi SShiZhi) : StarBase()
{
    // 接下来计算疾厄宫的信息
    Palace = static_cast<DiZhi>((static_cast<int>(YYueZhi) + 1 - static_cast<int>(SShiZhi) + 23 - 5) % 12 + 1);
    Name = "疾厄宫";
}

MigrationPalace::MigrationPalace(DiZhi YYueZhi, DiZhi SShiZhi) : StarBase()
{
    // 接下来计算迁移宫的信息
    Palace = static_cast<DiZhi>((static_cast<int>(YYueZhi) + 1 - static_cast<int>(SShiZhi) + 23 - 6) % 12 + 1);
    Name = "迁移宫";
}

SlavePalace::SlavePalace(DiZhi YYueZhi, DiZhi SShiZhi) : StarBase()
{
    // 接下来计算仆役宫的信息
    Palace = static_cast<DiZhi>((static_cast<int>(YYueZhi) + 1 - static_cast<int>(SShiZhi) + 23 - 7) % 12 + 1);
    Name = "仆役宫";
}

FunctionaryPalace::FunctionaryPalace(DiZhi YYueZhi, DiZhi SShiZhi) : StarBase()
{
    // 接下来计算官禄宫的信息
    Palace = static_cast<DiZhi>((static_cast<int>(YYueZhi) + 1 - static_cast<int>(SShiZhi) + 23 - 8) % 12 + 1);
    Name = "官禄宫";
}

FarmlandPalace::FarmlandPalace(DiZhi YYueZhi, DiZhi SShiZhi) : StarBase()
{
    // 接下来计算田宅宫的信息
    Palace = static_cast<DiZhi>((static_cast<int>(YYueZhi) + 1 - static_cast<int>(SShiZhi) + 23 - 9) % 12 + 1);
    Name = "田宅宫";
}

FortunePalace::FortunePalace(DiZhi YYueZhi, DiZhi SShiZhi) : StarBase()
{
    // 接下来计算福德宫的信息
    Palace = static_cast<DiZhi>((static_cast<int>(YYueZhi) + 1 - static_cast<int>(SShiZhi) + 23 - 10) % 12 + 1);
    Name = "福德宫";
}

ParentPalace::ParentPalace(DiZhi YYueZhi, DiZhi SShiZhi) : StarBase()
{
    // 接下来计算父母宫的信息
    Palace = static_cast<DiZhi>((static_cast<int>(YYueZhi) + 1 - static_cast<int>(SShiZhi) + 23 - 11) % 12 + 1);
    Name = "父母宫";
}

WuXingJuXing::WuXingJuXing(TianGan NNianGan /* =TianGan::Geng */, DiZhi LLifePalace /* =DiZhi::Chen */)
{
    // 接下来计算五行局的信息。
    switch (LLifePalace)
    {
    case DiZhi::Zi:
    case DiZhi::Chou:
        WuXing = static_cast<WuXingJu>(static_cast<int>(NNianGan) % 5);
        break;
    case DiZhi::Yin:
    case DiZhi::Mao:
        WuXing = static_cast<WuXingJu>(((static_cast<int>(NNianGan)) % 5 + 1 - 1) % 5 + 1);
        break;
    case DiZhi::Chen:
    case DiZhi::Si:
        WuXing = static_cast<WuXingJu>(((static_cast<int>(NNianGan)) % 5 + 3 - 1) % 5 + 1);
        break;
    case DiZhi::Wu:
    case DiZhi::Wei:
        WuXing = static_cast<WuXingJu>(((static_cast<int>(NNianGan)) % 5 + 2 - 1) % 5 + 1);
        break;
    case DiZhi::Shen:
    case DiZhi::You:
        WuXing = static_cast<WuXingJu>(((static_cast<int>(NNianGan)) % 5 + 4 - 1) % 5 + 1);
        break;
    case DiZhi::Xu:
    case DiZhi::Hai:
        WuXing = static_cast<WuXingJu>(((static_cast<int>(NNianGan)) % 5 + 1 - 1) % 5 + 1);
        break;
    default:
        break;
    }
}

//**********************************紫薇诸星**************************************

ZiWei::ZiWei(WuXingJu WWuXing /* =WuXingJu::JinSi */, int LLDay /* =28 */)
{
    /*     enum class WuXingJu
    {
        ShuiEr=1,
        HuoLiu,
        TuWu,
        MuSan,
        JinSi
    }; */

    // 使用农历生日和五行局初始化紫微星。但是计算无规律，因此使用查表法。

    DiZhi ziwei[5][30] =
        {
            {DiZhi::Chou, DiZhi::Yin, DiZhi::Yin, DiZhi::Mao, DiZhi::Mao, DiZhi::Chen, DiZhi::Chen, DiZhi::Si, DiZhi::Si, DiZhi::Wu, DiZhi::Wu, DiZhi::Wei, DiZhi::Wei, DiZhi::Shen, DiZhi::Shen, DiZhi::You, DiZhi::You, DiZhi::Xu, DiZhi::Xu, DiZhi::Hai, DiZhi::Hai, DiZhi::Zi, DiZhi::Zi, DiZhi::Chou, DiZhi::Chou, DiZhi::Yin, DiZhi::Yin, DiZhi::Mao, DiZhi::Mao, DiZhi::Chen}, // 水二
            {DiZhi::You, DiZhi::Wu, DiZhi::Hai, DiZhi::Chen, DiZhi::Chou, DiZhi::Yin, DiZhi::Xu, DiZhi::Wei, DiZhi::Zi, DiZhi::Si, DiZhi::Yin, DiZhi::Mao, DiZhi::Hai, DiZhi::Shen, DiZhi::Chou, DiZhi::Wu, DiZhi::Mao, DiZhi::Chen, DiZhi::Zi, DiZhi::You, DiZhi::Yin, DiZhi::Wei, DiZhi::Chen, DiZhi::Si, DiZhi::Chou, DiZhi::Xu, DiZhi::Mao, DiZhi::Shen, DiZhi::Si, DiZhi::Wu},   // 火六
            {DiZhi::Wu, DiZhi::Hai, DiZhi::Chen, DiZhi::Chou, DiZhi::Yin, DiZhi::Wei, DiZhi::Zi, DiZhi::Si, DiZhi::Yin, DiZhi::Mao, DiZhi::Shen, DiZhi::Chou, DiZhi::Wu, DiZhi::Mao, DiZhi::Chen, DiZhi::You, DiZhi::Yin, DiZhi::Wei, DiZhi::Chen, DiZhi::Si, DiZhi::Xu, DiZhi::Mao, DiZhi::Shen, DiZhi::Si, DiZhi::Wu, DiZhi::Hai, DiZhi::Chen, DiZhi::You, DiZhi::Wu, DiZhi::Wei},  // 土五
            {DiZhi::Chen, DiZhi::Chou, DiZhi::Yin, DiZhi::Si, DiZhi::Yin, DiZhi::Mao, DiZhi::Wu, DiZhi::Mao, DiZhi::Chen, DiZhi::Wei, DiZhi::Chen, DiZhi::Si, DiZhi::Shen, DiZhi::Si, DiZhi::Wu, DiZhi::You, DiZhi::Wu, DiZhi::Wei, DiZhi::Xu, DiZhi::Wei, DiZhi::Shen, DiZhi::Hai, DiZhi::Shen, DiZhi::You, DiZhi::Zi, DiZhi::You, DiZhi::Xu, DiZhi::You, DiZhi::Xu, DiZhi::Hai},    // 木三
            {DiZhi::Hai, DiZhi::Chen, DiZhi::Chou, DiZhi::Yin, DiZhi::Zi, DiZhi::Si, DiZhi::Yin, DiZhi::Mao, DiZhi::Chou, DiZhi::Wu, DiZhi::Mao, DiZhi::Chen, DiZhi::Yin, DiZhi::Wei, DiZhi::Chen, DiZhi::Si, DiZhi::Mao, DiZhi::Shen, DiZhi::Si, DiZhi::Wu, DiZhi::Chen, DiZhi::You, DiZhi::Wu, DiZhi::Wei, DiZhi::Si, DiZhi::Xu, DiZhi::Wei, DiZhi::Shen, DiZhi::Wu, DiZhi::Hai},   // 金四
        };
    Palace = ziwei[static_cast<int>(WWuXing) - 1][LLDay - 1];
    Name = "紫薇";
}

TianJi::TianJi(DiZhi ZiWei /* =DiZhi::Shen */)
{
    Palace = static_cast<DiZhi>((static_cast<int>(ZiWei) - 1 + 12 - 1) % 12 + 1);
    Name = "天机";
}

TaiYang::TaiYang(DiZhi ZiWei /* =DiZhi::Shen */)
{
    Palace = static_cast<DiZhi>((static_cast<int>(ZiWei) - 3 + 12 - 1) % 12 + 1);
    Name = "太阳";
}

WuQu::WuQu(DiZhi ZiWei /* =DiZhi::Shen */)
{
    Palace = static_cast<DiZhi>((static_cast<int>(ZiWei) - 4 + 12 - 1) % 12 + 1);
    Name = "武曲";
}

TianTong::TianTong(DiZhi ZiWei /* =DiZhi::Shen */)
{
    Palace = static_cast<DiZhi>((static_cast<int>(ZiWei) - 5 + 12 - 1) % 12 + 1);
    Name = "天同";
}

LianZhen::LianZhen(DiZhi ZiWei /* =DiZhi::Shen */)
{
    Palace = static_cast<DiZhi>((static_cast<int>(ZiWei) - 8 + 12 - 1) % 12 + 1);
    Name = "廉贞";
}

//************************************天府诸星**************************************

// 天府星构造函数
TianFu::TianFu(DiZhi ZiWei /* =DiZhi::Shen */)
{
    Palace = static_cast<DiZhi>((6 - static_cast<int>(ZiWei) + 12 - 1) % 12 + 1);
    Name = "天府";
}

// 太阴星构造函数
TaiYin::TaiYin(DiZhi TianFu /* =DiZhi::Shen */)
{
    Palace = static_cast<DiZhi>((static_cast<int>(TianFu) + 1 + 12 - 1) % 12 + 1);
    Name = "太阴";
}
// 贪狼星构造函数
TanLang::TanLang(DiZhi TianFu /* =DiZhi::Shen */)
{
    Palace = static_cast<DiZhi>((static_cast<int>(TianFu) + 2 + 12 - 1) % 12 + 1);
    Name = "贪狼";
}
// 巨门星构造函数
JuMen::JuMen(DiZhi TianFu /* =DiZhi::Shen */)
{
    Palace = static_cast<DiZhi>((static_cast<int>(TianFu) + 3 + 12 - 1) % 12 + 1);
    Name = "巨门";
}
// 天相星构造函数
TianXiang::TianXiang(DiZhi TianFu /* =DiZhi::Shen */)
{
    Palace = static_cast<DiZhi>((static_cast<int>(TianFu) + 4 + 12 - 1) % 12 + 1);
    Name = "天相";
}
// 天梁星构造函数
TianLiang::TianLiang(DiZhi TianFu /* =DiZhi::Shen */)
{
    Palace = static_cast<DiZhi>((static_cast<int>(TianFu) + 5 + 12 - 1) % 12 + 1);
    Name = "天梁";
}
// 七杀星构造函数
QiSha::QiSha(DiZhi TianFu /* =DiZhi::Shen */)
{
    Palace = static_cast<DiZhi>((static_cast<int>(TianFu) + 6 + 12 - 1) % 12 + 1);
    Name = "七杀";
}
// 破军星构造函数
PoJun::PoJun(DiZhi TianFu /* =DiZhi::Shen */)
{
    Palace = static_cast<DiZhi>((static_cast<int>(TianFu) + 10 + 12 - 1) % 12 + 1);
    Name = "破军";
}

//************************************时系诸星**************************************

// 文昌星构造函数
WenChang::WenChang(DiZhi ShiZhi /* =DiZhi::Xu */)
{
    Palace = static_cast<DiZhi>((12 - static_cast<int>(ShiZhi) + 12 - 1) % 12 + 1);
    Name = "文昌";
}

// 文曲星构造函数
WenQu::WenQu(DiZhi ShiZhi /* =DiZhi::Xu */)
{
    Palace = static_cast<DiZhi>((static_cast<int>(ShiZhi) - 8 + 12 - 1) % 12 + 1);
    Name = "文曲";
}
// 火星构造函数
HuoXing::HuoXing(DiZhi ShiZhi /* =DiZhi::Xu */, DiZhi NianZhi /* = DiZhi::Wu */)
{
    switch (NianZhi)
    {
    case DiZhi::Yin:
    case DiZhi::Wu:
    case DiZhi::Xu:
        Palace = static_cast<DiZhi>((static_cast<int>(ShiZhi) - 11 + 12 - 1) % 12 + 1);
        break;
    case DiZhi::Shen:
    case DiZhi::Zi:
    case DiZhi::Chen:
        Palace = static_cast<DiZhi>((static_cast<int>(ShiZhi) - 10 + 12 - 1) % 12 + 1);
        break;
    case DiZhi::Si:
    case DiZhi::You:
    case DiZhi::Chou:
        Palace = static_cast<DiZhi>((static_cast<int>(ShiZhi) - 9 + 12 - 1) % 12 + 1);
        break;
    case DiZhi::Hai:
    case DiZhi::Mao:
    case DiZhi::Wei:
        Palace = static_cast<DiZhi>((static_cast<int>(ShiZhi) - 3 + 12 - 1) % 12 + 1);
        break;
    default:
        break;
    }
    Name = "火星";
}
// 铃星构造函数
LingXing::LingXing(DiZhi ShiZhi /* =DiZhi::Xu */, DiZhi NianZhi /* = DiZhi::Wu */)
{
    switch (ShiZhi)
    {
    case DiZhi::Yin:
    case DiZhi::Wu:
    case DiZhi::Xu:
        Palace = static_cast<DiZhi>((static_cast<int>(ShiZhi) - 9 + 12 - 1) % 12 + 1);
        break;
    case DiZhi::Shen:
    case DiZhi::Zi:
    case DiZhi::Chen:
    case DiZhi::Si:
    case DiZhi::You:
    case DiZhi::Chou:
    case DiZhi::Hai:
    case DiZhi::Mao:
    case DiZhi::Wei:
        Palace = static_cast<DiZhi>((static_cast<int>(ShiZhi) - 2 + 12 - 1) % 12 + 1);
        break;
    default:
        break;
    }
    Name = "铃星";
}
// 地劫星构造函数
DiJie::DiJie(DiZhi ShiZhi /* =DiZhi::Xu */)
{
    Palace = static_cast<DiZhi>((static_cast<int>(ShiZhi) - 1 + 12 - 1) % 12 + 1);
    Name = "地劫";
}
// 天空星构造函数
TianKong::TianKong(DiZhi ShiZhi /* =DiZhi::Xu */)
{
    Palace = static_cast<DiZhi>((12 - static_cast<int>(ShiZhi) + 1 + 12 - 1) % 12 + 1);
    Name = "天空";
}
// 台辅星构造函数
TaiFu::TaiFu(DiZhi ShiZhi /* =DiZhi::Xu */)
{
    Palace = static_cast<DiZhi>((static_cast<int>(ShiZhi) - 6 + 12 - 1) % 12 + 1);
    Name = "台辅";
}
// 封诰星构造函数
FengGao::FengGao(DiZhi ShiZhi /* =DiZhi::Xu */)
{
    Palace = static_cast<DiZhi>((static_cast<int>(ShiZhi) - 10 + 12 - 1) % 12 + 1);
    Name = "封诰";
}

//***********************************月系诸星**************************************

// 左辅星类构造函数
ZuoFu::ZuoFu(DiZhi YueZhi /* = DiZhi::Yin */)
{
    Palace = static_cast<DiZhi>((static_cast<int>(YueZhi) - 8 + 12 - 1) % 12 + 1);
    Name = "左辅";
}

// 右弼星类构造函数
YouBi::YouBi(DiZhi YueZhi /* = DiZhi::Yin */)
{
    Palace = static_cast<DiZhi>((12 - static_cast<int>(YueZhi) + 12 - 1) % 12 + 1);
    Name = "右弼";
}

// 天刑星类构造函数
TianXing::TianXing(DiZhi YueZhi /* = DiZhi::Yin */)
{
    Palace = static_cast<DiZhi>((static_cast<int>(YueZhi) - 3 + 12 - 1) % 12 + 1);
    Name = "天刑";
}

// 天姚星类构造函数
TianYao::TianYao(DiZhi YueZhi /* = DiZhi::Yin */)
{
    Palace = static_cast<DiZhi>((static_cast<int>(YueZhi) - 11 + 12 - 1) % 12 + 1);
    Name = "天姚";
}

// 天马星类构造函数
TianMa::TianMa(DiZhi YueZhi /* = DiZhi::Yin */)
{
    switch (static_cast<int>(YueZhi) % 4)
    {
        {
        case 0:
            Palace = DiZhi::Hai;
            break;
        case 1:
            Palace = DiZhi::Shen;
            break;
        case 2:
            Palace = DiZhi::Si;
            break;
        case 3:
            Palace = DiZhi::Yin;
            break;
        default:
            break;
        }
    }
    Name = "天马";
}

// 解神星类构造函数
JieShen::JieShen(DiZhi YueZhi /* = DiZhi::Yin */)
{
    DiZhi a[12] = {DiZhi::Shen, DiZhi::Shen, DiZhi::Xu, DiZhi::Xu, DiZhi::Zi, DiZhi::Zi, DiZhi::Yin, DiZhi::Yin, DiZhi::Chen, DiZhi::Chen, DiZhi::Wu, DiZhi::Wu};

    Palace = a[static_cast<int>(YueZhi) - 1];
    Name = "解神";
}

// 天巫星类构造函数
TianWu::TianWu(DiZhi YueZhi /* = DiZhi::Yin */)
{
    switch (static_cast<int>(YueZhi) % 4)
    {
        {
        case 0:
            Palace = DiZhi::Hai;
            break;
        case 1:
            Palace = DiZhi::Si;
            break;
        case 2:
            Palace = DiZhi::Shen;
            break;
        case 3:
            Palace = DiZhi::Yin;
            break;
        default:
            break;
        }
    }
    Name = "天巫";
}

// 天月星类构造函数
TianYue_2::TianYue_2(DiZhi YueZhi /* = DiZhi::Yin */)
{
    DiZhi a[12] = {DiZhi::Xu, DiZhi::Si, DiZhi::Chen, DiZhi::Yin, DiZhi::Wei, DiZhi::Mao, DiZhi::Hai, DiZhi::Wei, DiZhi::Yin, DiZhi::Wu, DiZhi::Xu, DiZhi::Yin};

    Palace = a[static_cast<int>(YueZhi) - 1];
    Name = "天月";
}

// 阴煞星类构造函数

YinSha::YinSha(DiZhi YueZhi /* = DiZhi::Yin */)
{
    DiZhi a[12] = {DiZhi::Yin, DiZhi::Zi, DiZhi::Xu, DiZhi::Shen, DiZhi::Wu, DiZhi::Chen, DiZhi::Yin, DiZhi::Zi, DiZhi::Xu, DiZhi::Shen, DiZhi::Wu, DiZhi::Chen};

    Palace = a[static_cast<int>(YueZhi) - 1];
    Name = "阴煞";
}

//**********************************日系诸星******************************************

// 三台星类构造函数
SanTai::SanTai(DiZhi ZuoFu /* = DiZhi::Chen */, int LDay /*  = 28 */)
{
    Palace = static_cast<DiZhi>((static_cast<int>(ZuoFu) + LDay - 1 + 36 - 1) % 12 + 1);
    Name = "三台";
}

// 八座星类构造函数
BaZuo::BaZuo(DiZhi YouBi /* = DiZhi::Chen */, int LDay /*  = 28 */)
{
    Palace = static_cast<DiZhi>((static_cast<int>(YouBi) - LDay + 1 + 48 - 1) % 12 + 1);
    Name = "八座";
}

// 恩光星类构造函数
EnGuang::EnGuang(DiZhi WenChang /* = DiZhi::Chen */, int LDay /*  = 28 */)
{
    Palace = static_cast<DiZhi>((static_cast<int>(WenChang) + LDay - 1 - 1 + 60 - 1) % 12 + 1);
    Name = "恩光";
}

// 天贵星类构造函数
TianGui::TianGui(DiZhi WenQu /* = DiZhi::Chen */, int LDay /*  = 28 */)
{
    Palace = static_cast<DiZhi>((static_cast<int>(WenQu) + LDay + -1 - 1 + 72 - 1) % 12 + 1);
    Name = "天贵";
}

//***********************************干系诸星******************************************

// 根据头文件中类的构造顺序写出干系诸星类的构造函数
// 禄存星类构造函数
LuCun_::LuCun_(TianGan NianGan /* = TianGan::Geng */)
{
    DiZhi a[10]{DiZhi::Yin, DiZhi::Mao, DiZhi::Si, DiZhi::Wu, DiZhi::Si, DiZhi::Wu, DiZhi::Shen, DiZhi::You, DiZhi::Hai, DiZhi::Zi};
    Palace = a[static_cast<int>(NianGan) - 1];
    Name = "禄存";
}
// 擎羊星类构造函数
QingYang::QingYang(TianGan NianGan /* = TianGan::Geng */)
{
    DiZhi a[10]{DiZhi::Mao, DiZhi::Chen, DiZhi::Wu, DiZhi::Wei, DiZhi::Wu, DiZhi::Wei, DiZhi::You, DiZhi::Xu, DiZhi::Zi, DiZhi::Chou};
    Palace = a[static_cast<int>(NianGan) - 1];
    Name = "擎羊";
}

// 陀罗星构造函数

TuoLuo::TuoLuo(TianGan NianGan /* = TianGan::Geng */)
{
    DiZhi a[10]{DiZhi::Chou, DiZhi::Yin, DiZhi::Chen, DiZhi::Si, DiZhi::Chen, DiZhi::Si, DiZhi::Wei, DiZhi::Shen, DiZhi::Xu, DiZhi::Hai};
    Palace = a[static_cast<int>(NianGan) - 1];
    Name = "陀罗";
}

// 天魁星类构造函数
TianKui::TianKui(TianGan NianGan /* = TianGan::Geng */)
{
    DiZhi a[10]{DiZhi::Chou, DiZhi::Zi, DiZhi::Hai, DiZhi::Hai, DiZhi::Chou, DiZhi::Zi, DiZhi::Chou, DiZhi::Wu, DiZhi::Mao, DiZhi::Mao};
    Palace = a[static_cast<int>(NianGan) - 1];
    Name = "天魁";
}

// 天钺星类构造函数
TianYue::TianYue(TianGan NianGan /* = TianGan::Geng */)
{
    DiZhi a[10]{DiZhi::Wei, DiZhi::Shen, DiZhi::You, DiZhi::You, DiZhi::Wei, DiZhi::Shen, DiZhi::Wei, DiZhi::Yin, DiZhi::Si, DiZhi::Si};
    Palace = a[static_cast<int>(NianGan) - 1];
    Name = "天钺";
}
// 天官星类构造函数
TianGuan::TianGuan(TianGan NianGan /* = TianGan::Geng */)
{
    DiZhi a[10]{DiZhi::Wei, DiZhi::Chen, DiZhi::Si, DiZhi::Yin, DiZhi::Mao, DiZhi::You, DiZhi::Hai, DiZhi::You, DiZhi::Xu, DiZhi::Wu};
    Palace = a[static_cast<int>(NianGan) - 1];
    Name = "天官";
}

// 天福星类构造函数

TianFu_2::TianFu_2(TianGan NianGan /* = TianGan::Geng */)
{
    DiZhi a[10]{DiZhi::You, DiZhi::Shen, DiZhi::Zi, DiZhi::Hai, DiZhi::Mao, DiZhi::Yin, DiZhi::Wu, DiZhi::Si, DiZhi::Wu, DiZhi::Si};
    Palace = a[static_cast<int>(NianGan) - 1];
    Name = "天福";
}

// 化禄星类构造函数
HuaLu::HuaLu(TianGan NianGan /* = TianGan::Geng */, DiZhi *array /* = nullptr */)
{
    if (array != nullptr)
    {
        Palace = array[static_cast<int>(NianGan) - 1];
    }
    else
    {
        Palace = DiZhi::Si;
    }
    Name = "化禄";
}
// 化权星类构造函数
HuaQuan::HuaQuan(TianGan NianGan /* = TianGan::Geng */, DiZhi *array /* = nullptr */)
{

    if (array != nullptr)
    {
        Palace = array[static_cast<int>(NianGan) - 1];
    }
    else
    {
        Palace = DiZhi::Chen;
    }

    Name = "化权";
}

// 化科星类构造函数
HuaKe::HuaKe(TianGan NianGan /* = TianGan::Geng */, DiZhi *array /* = nullptr */)
{
    if (array != nullptr)
    {
        Palace = array[static_cast<int>(NianGan) - 1];
    }
    else
    {
        Palace = DiZhi::You;
    }
    Name = "化科";
}

// 化忌星类构造函数
HuaJi::HuaJi(TianGan NianGan /* = TianGan::Geng */, DiZhi *array /* = nullptr */)
{
    if (array != nullptr)
    {
        Palace = array[static_cast<int>(NianGan) - 1];
    }
    else
    {
        Palace = DiZhi::Mao;
    }
    Name = "化忌";
}

//*******************************生年博士十二星****************************************

// 博士星类构造函数
BoShi::BoShi(DiZhi LLuCun /* = DiZhi::Shen */, YinYang YYinYang /* = YinYang::Yang */, Gender GGender /* = Gender::Male */)
{
    Palace = LLuCun;
    Name = "博士";
}

// 力士星类构造函数
LiShi::LiShi(DiZhi LLuCun /* = DiZhi::Shen */, YinYang YYinYang /* = YinYang::Yang */, Gender GGender /* = Gender::Male */)
{
    int a = (static_cast<int>(YYinYang) + static_cast<int>(GGender)) % 2; /* 阳男阴女为1，顺行，阴男阳女得0，逆行 */
    Palace = static_cast<DiZhi>((static_cast<int>(LLuCun) + (a * 2 - 1) * 1 + 24 - 1) % 12 + 1);
    Name = "力士";
}

// 青龙星类构造函数

QingLong::QingLong(DiZhi LLuCun /* = DiZhi::Shen */, YinYang YYinYang /* = YinYang::Yang */, Gender GGender /* = Gender::Male */)
{
    int a = (static_cast<int>(YYinYang) + static_cast<int>(GGender)) % 2; /* 阳男阴女为1，顺行，阴男阳女得0，逆行 */
    Palace = static_cast<DiZhi>((static_cast<int>(LLuCun) + (a * 2 - 1) * 2 + 24 - 1) % 12 + 1);
    Name = "青龙";
}

// 小耗星类构造函数
XiaoHao::XiaoHao(DiZhi LLuCun /* = DiZhi::Shen */, YinYang YYinYang /* = YinYang::Yang */, Gender GGender /* = Gender::Male */)
{
    int a = (static_cast<int>(YYinYang) + static_cast<int>(GGender)) % 2; /* 阳男阴女为1，顺行，阴男阳女得0，逆行 */
    Palace = static_cast<DiZhi>((static_cast<int>(LLuCun) + (a * 2 - 1) * 3 + 24 - 1) % 12 + 1);
    Name = "小耗";
}

// 将军星类构造函数
JiangJun::JiangJun(DiZhi LLuCun /* = DiZhi::Shen */, YinYang YYinYang /* = YinYang::Yang */, Gender GGender /* = Gender::Male */)
{
    int a = (static_cast<int>(YYinYang) + static_cast<int>(GGender)) % 2; /* 阳男阴女为1，顺行，阴男阳女得0，逆行 */
    Palace = static_cast<DiZhi>((static_cast<int>(LLuCun) + (a * 2 - 1) * 3 + 24 - 1) % 12 + 1);
    Name = "将军";
}

// 奏书星类构造函数
ZouShu::ZouShu(DiZhi LLuCun /* = DiZhi::Shen */, YinYang YYinYang /* = YinYang::Yang */, Gender GGender /* = Gender::Male */)
{
    int a = (static_cast<int>(YYinYang) + static_cast<int>(GGender)) % 2; /* 阳男阴女为1，顺行，阴男阳女得0，逆行 */
    Palace = static_cast<DiZhi>((static_cast<int>(LLuCun) + (a * 2 - 1) * 3 + 24 - 1) % 12 + 1);
    Name = "奏书";
}

// 飞廉星类构造函数
FeiLian::FeiLian(DiZhi LLuCun /* = DiZhi::Shen */, YinYang YYinYang /* = YinYang::Yang */, Gender GGender /* = Gender::Male */)
{
    int a = (static_cast<int>(YYinYang) + static_cast<int>(GGender)) % 2; /* 阳男阴女为1，顺行，阴男阳女得0，逆行 */
    Palace = static_cast<DiZhi>((static_cast<int>(LLuCun) + (a * 2 - 1) * 4 + 24 - 1) % 12 + 1);
    Name = "飞廉";
}

// 喜神星类构造函数
XiShen::XiShen(DiZhi LLuCun /* = DiZhi::Shen */, YinYang YYinYang /* = YinYang::Yang */, Gender GGender /* = Gender::Male */)
{
    int a = (static_cast<int>(YYinYang) + static_cast<int>(GGender)) % 2; /* 阳男阴女为1，顺行，阴男阳女得0，逆行 */
    Palace = static_cast<DiZhi>((static_cast<int>(LLuCun) + (a * 2 - 1) * 5 + 24 - 1) % 12 + 1);
    Name = "喜神";
}

// 病符星类构造函数
BingFu::BingFu(DiZhi LLuCun /* = DiZhi::Shen */, YinYang YYinYang /* = YinYang::Yang */, Gender GGender /* = Gender::Male */)
{
    int a = (static_cast<int>(YYinYang) + static_cast<int>(GGender)) % 2; /* 阳男阴女为1，顺行，阴男阳女得0，逆行 */
    Palace = static_cast<DiZhi>((static_cast<int>(LLuCun) + (a * 2 - 1) * 6 + 24 - 1) % 12 + 1);
    Name = "病符";
}

// 大耗星类构造函数

DaHao::DaHao(DiZhi LLuCun /* = DiZhi::Shen */, YinYang YYinYang /* = YinYang::Yang */, Gender GGender /* = Gender::Male */)
{
    int a = (static_cast<int>(YYinYang) + static_cast<int>(GGender)) % 2; /* 阳男阴女为1，顺行，阴男阳女得0，逆行 */
    Palace = static_cast<DiZhi>((static_cast<int>(LLuCun) + (a * 2 - 1) * 7 + 24 - 1) % 12 + 1);
    Name = "大耗";
}

// 伏兵星类构造函数
FuBing::FuBing(DiZhi LLuCun /* = DiZhi::Shen */, YinYang YYinYang /* = YinYang::Yang */, Gender GGender /* = Gender::Male */)
{
    int a = (static_cast<int>(YYinYang) + static_cast<int>(GGender)) % 2; /* 阳男阴女为1，顺行，阴男阳女得0，逆行 */
    Palace = static_cast<DiZhi>((static_cast<int>(LLuCun) + (a * 2 - 1) * 8 + 24 - 1) % 12 + 1);
    Name = "伏兵";
}

// 官府星类构造函数
GuanFu::GuanFu(DiZhi LLuCun /* = DiZhi::Shen */, YinYang YYinYang /* = YinYang::Yang */, Gender GGender /* = Gender::Male */)
{
    int a = (static_cast<int>(YYinYang) + static_cast<int>(GGender)) % 2; /* 阳男阴女为1，顺行，阴男阳女得0，逆行 */
    Palace = static_cast<DiZhi>((static_cast<int>(LLuCun) + (a * 2 - 1) * 9 + 24 - 1) % 12 + 1);
    Name = "官府";
}

//*********************************年支系诸星*************************************

// 地空星类构造函数
DiKong::DiKong(DiZhi NianZhi /* = DiZhi::Wu */)
{
    Palace = static_cast<DiZhi>((static_cast<int>(NianZhi) - 11 + 24 - 1) % 12 + 1);
    Name = "地空";
}

// 天哭星类构造函数
TianKu::TianKu(DiZhi NianZhi /* = DiZhi::Wu */)
{
    Palace = static_cast<DiZhi>((8 - static_cast<int>(NianZhi) + 24 - 1) % 12 + 1);
    Name = "天哭";
}
// 天虚星类构造函数
TianXu::TianXu(DiZhi NianZhi /* = DiZhi::Wu */)
{
    Palace = static_cast<DiZhi>((static_cast<int>(NianZhi) - 6 + 24 - 1) % 12 + 1);
    Name = "天虚";
}
// 龙池星类构造函数
LongChi::LongChi(DiZhi NianZhi /* = DiZhi::Wu */)
{
    Palace = static_cast<DiZhi>((static_cast<int>(NianZhi) - 8 + 24 - 1) % 12 + 1);
    Name = "龙池";
}

// 凤阁星类构造函数
FengGe::FengGe(DiZhi NianZhi /* = DiZhi::Wu */)
{
    Palace = static_cast<DiZhi>((12 - static_cast<int>(NianZhi) + 24 - 1) % 12 + 1);
    Name = "凤阁";
}
// 红鸾星类构造函数
HongLuan::HongLuan(DiZhi NianZhi /* = DiZhi::Wu */)
{
    Palace = static_cast<DiZhi>((5 - static_cast<int>(NianZhi) + 24 - 1) % 12 + 1);
    Name = "红鸾";
}
// 天喜星类构造函数
TianXi::TianXi(DiZhi NianZhi /* = DiZhi::Wu */)
{
    Palace = static_cast<DiZhi>((11 - static_cast<int>(NianZhi) + 24 - 1) % 12 + 1);
    Name = "天喜";
}
// 蜚蠊星类构造函数
FeiLian_2::FeiLian_2(DiZhi NianZhi /* = DiZhi::Wu */)
{
    Palace = static_cast<DiZhi>((12 - static_cast<int>(NianZhi) + 24 - 1) % 12 + 1);
    Name = "蜚蠊";
}
// 破碎星类构造函数
PoSui::PoSui(DiZhi NianZhi /* = DiZhi::Wu */)
{
    DiZhi a[12] = {DiZhi::Si, DiZhi::Chou, DiZhi::You, DiZhi::Si, DiZhi::Chou, DiZhi::You, DiZhi::Si, DiZhi::Chou, DiZhi::You, DiZhi::Si, DiZhi::Chou, DiZhi::You};
    Palace = a[static_cast<int>(NianZhi) - 1];
    Name = "破碎";
}

// 孤辰星类构造函数
GuChen::GuChen(DiZhi NianZhi /* = DiZhi::Wu */)
{
    DiZhi a[12] = {DiZhi::Yin, DiZhi::Yin, DiZhi::Si, DiZhi::Si, DiZhi::Si, DiZhi::Shen, DiZhi::Shen, DiZhi::Shen, DiZhi::Hai, DiZhi::Hai, DiZhi::Hai, DiZhi::Yin};
    Palace = a[static_cast<int>(NianZhi) - 1];
    Name = "孤辰";
}

// 寡宿星类构造函数
GuaSu::GuaSu(DiZhi NianZhi /* = DiZhi::Wu */)
{
    DiZhi a[12] = {DiZhi::Si, DiZhi::Si, DiZhi::Si, DiZhi::Shen, DiZhi::Shen, DiZhi::Shen, DiZhi::Hai, DiZhi::Hai, DiZhi::Hai, DiZhi::Yin, DiZhi::Yin, DiZhi::Si};
    Palace = a[static_cast<int>(NianZhi) - 1];
    Name = "寡宿";
}

// 天才星类构造函数
TianCai::TianCai(DiZhi NianZhi /*  = DiZhi ::Wu*/, DiZhi *array /*  = nullptr */)
{
    if (array != nullptr)
    {
        Palace = array[static_cast<int>(NianZhi) - 1];
    }
    else
    {
        Palace = DiZhi::Xu;
    }

    Name = "天才";
}

// 天寿星类构造函数
TianShou::TianShou(DiZhi NianZhi /* = DiZhi::Wu */, DiZhi BBodyPalace /* = DiZhi::Zi */)
{

    Palace = static_cast<DiZhi>((static_cast<int>(NianZhi) + static_cast<int>(BBodyPalace) - 1 + 24 - 1) % 12 + 1);
    Name = "天寿";
}

//**********************************五行长生十二星************************************

// 长生星类构造函数
ChangSheng::ChangSheng(WuXingJu wwuxing /* = WuXingJu::JinSi */, Gender ggender /*  = Gender::Male */, YinYang yyinyang /*  = YinYang::Yang */)
{
    switch (wwuxing)
    {
    case WuXingJu::ShuiEr:
        Palace = DiZhi::Shen;
        break;
    case WuXingJu::MuSan:
        Palace = DiZhi::Hai;
        break;
    case WuXingJu::JinSi:
        Palace = DiZhi::Si;
        break;
    case WuXingJu::TuWu:
        Palace = DiZhi::Shen;
        break;
    case WuXingJu::HuoLiu:
        Palace = DiZhi::Yin;
        break;
    }
    Name = "长生";
}
// 沐浴星类构造函数
MuYu::MuYu(WuXingJu wwuxing /* = WuXingJu::JinSi */, Gender ggender /*  = Gender::Male */, YinYang yyinyang /*  = YinYang::Yang */)
{
    int a = static_cast<int>(ggender) + static_cast<int>(yyinyang); // 1是阳男阴女，2是阴男阳女
    switch (wwuxing)
    {
    case WuXingJu::ShuiEr:
        if (a == 1)
            Palace = DiZhi::You;
        else
            Palace = DiZhi::Wei;
        break;
    case WuXingJu::MuSan:
        if (a == 1)
            Palace = DiZhi::Zi;
        else
            Palace = DiZhi::Xu;
        break;
    case WuXingJu::JinSi:
        if (a == 1)
            Palace = DiZhi::Wu;
        else
            Palace = DiZhi::Chen;
        break;
    case WuXingJu::TuWu:
        if (a == 1)
            Palace = DiZhi::You;
        else
            Palace = DiZhi::Wei;
        break;
    case WuXingJu::HuoLiu:
        if (a == 1)
            Palace = DiZhi::Mao;
        else
            Palace = DiZhi::Chou;
        break;
    }
    Name = "沐浴";
}

// 冠带星类构造函数
GuanDai::GuanDai(WuXingJu wwuxing /* = WuXingJu::JinSi */, Gender ggender /*  = Gender::Male */, YinYang yyinyang /*  = YinYang::Yang */)
{
    int a = static_cast<int>(ggender) + static_cast<int>(yyinyang); // 1是阳男阴女，2是阴男阳女
    switch (wwuxing)
    {
    case WuXingJu::ShuiEr:
        if (a == 1)
            Palace = DiZhi::Xu;
        else
            Palace = DiZhi::Wu;
        break;
    case WuXingJu::MuSan:
        if (a == 1)
            Palace = DiZhi::Chou;
        else
            Palace = DiZhi::You;
        break;
    case WuXingJu::JinSi:
        if (a == 1)
            Palace = DiZhi::Wei;
        else
            Palace = DiZhi::Mao;
        break;
    case WuXingJu::TuWu:
        if (a == 1)
            Palace = DiZhi::Xu;
        else
            Palace = DiZhi::Wu;
        break;
    case WuXingJu::HuoLiu:
        if (a == 1)
            Palace = DiZhi::Chen;
        else
            Palace = DiZhi::Zi;
        break;
    }
    Name = "冠带";
}

// 临官星类构造函数

LinGuan::LinGuan(WuXingJu wwuxing /* = WuXingJu::JinSi */, Gender ggender /*  = Gender::Male */, YinYang yyinyang /*  = YinYang::Yang */)
{
    int a = static_cast<int>(ggender) + static_cast<int>(yyinyang); // 1是阳男阴女，2是阴男阳女
    switch (wwuxing)
    {
    case WuXingJu::ShuiEr:
        if (a == 1)
            Palace = DiZhi::Hai;
        else
            Palace = DiZhi::Si;
        break;
    case WuXingJu::MuSan:
        if (a == 1)
            Palace = DiZhi::Yin;
        else
            Palace = DiZhi::Shen;
        break;
    case WuXingJu::JinSi:
        if (a == 1)
            Palace = DiZhi::Shen;
        else
            Palace = DiZhi::Yin;
        break;
    case WuXingJu::TuWu:
        if (a == 1)
            Palace = DiZhi::Hai;
        else
            Palace = DiZhi::Si;
        break;
    case WuXingJu::HuoLiu:
        if (a == 1)
            Palace = DiZhi::Si;
        else
            Palace = DiZhi::Hai;
        break;
    }
    Name = "临官";
}

// 帝王星类构造函数
DiWang::DiWang(WuXingJu wwuxing /* = WuXingJu::JinSi */, Gender ggender /*  = Gender::Male */, YinYang yyinyang /*  = YinYang::Yang */)
{
    int a = static_cast<int>(ggender) + static_cast<int>(yyinyang); // 1是阳男阴女，2是阴男阳女
    switch (wwuxing)
    {
    case WuXingJu::ShuiEr:
        if (a == 1)
            Palace = DiZhi::Zi;
        else
            Palace = DiZhi::Chen;
        break;
    case WuXingJu::MuSan:
        if (a == 1)
            Palace = DiZhi::Mao;
        else
            Palace = DiZhi::Wei;
        break;
    case WuXingJu::JinSi:
        if (a == 1)
            Palace = DiZhi::You;
        else
            Palace = DiZhi::Chou;
        break;
    case WuXingJu::TuWu:
        if (a == 1)
            Palace = DiZhi::Zi;
        else
            Palace = DiZhi::Chen;
        break;
    case WuXingJu::HuoLiu:
        if (a == 1)
            Palace = DiZhi::Wu;
        else
            Palace = DiZhi::Xu;
        break;
    }
    Name = "帝旺";
}

// 衰星类构造函数
ShuaiXing::ShuaiXing(WuXingJu wwuxing /* = WuXingJu::JinSi */, Gender ggender /*  = Gender::Male */, YinYang yyinyang /*  = YinYang::Yang */)
{
    int a = static_cast<int>(ggender) + static_cast<int>(yyinyang); // 1是阳男阴女，2是阴男阳女
    switch (wwuxing)
    {
    case WuXingJu::ShuiEr:
        if (a == 1)
            Palace = DiZhi::Chou;
        else
            Palace = DiZhi::Mao;
        break;
    case WuXingJu::MuSan:
        if (a == 1)
            Palace = DiZhi::Chen;
        else
            Palace = DiZhi::Wu;
        break;
    case WuXingJu::JinSi:
        if (a == 1)
            Palace = DiZhi::Xu;
        else
            Palace = DiZhi::Zi;
        break;
    case WuXingJu::TuWu:
        if (a == 1)
            Palace = DiZhi::Chou;
        else
            Palace = DiZhi::Mao;
        break;
    case WuXingJu::HuoLiu:
        if (a == 1)
            Palace = DiZhi::Wei;
        else
            Palace = DiZhi::You;
        break;
    }
    Name = "衰";
}

// 病星类构造函数

BingXing::BingXing(WuXingJu wwuxing /* = WuXingJu::JinSi */, Gender ggender /*  = Gender::Male */, YinYang yyinyang /*  = YinYang::Yang */)
{
    int a = static_cast<int>(ggender) + static_cast<int>(yyinyang); // 1是阳男阴女，2是阴男阳女
    switch (wwuxing)
    {
    case WuXingJu::ShuiEr:
        if (a == 1)
            Palace = DiZhi::Yin;
        else
            Palace = DiZhi::Yin;
        break;
    case WuXingJu::MuSan:
        if (a == 1)
            Palace = DiZhi::Si;
        else
            Palace = DiZhi::Si;
        break;
    case WuXingJu::JinSi:
        if (a == 1)
            Palace = DiZhi::Hai;
        else
            Palace = DiZhi::Hai;
        break;
    case WuXingJu::TuWu:
        if (a == 1)
            Palace = DiZhi::Yin;
        else
            Palace = DiZhi::Yin;
        break;
    case WuXingJu::HuoLiu:
        if (a == 1)
            Palace = DiZhi::Shen;
        else
            Palace = DiZhi::Shen;
        break;
    }
    Name = "病";
}

// 死星类构造函数

SiXing::SiXing(WuXingJu wwuxing /* = WuXingJu::JinSi */, Gender ggender /*  = Gender::Male */, YinYang yyinyang /*  = YinYang::Yang */)
{
    int a = static_cast<int>(ggender) + static_cast<int>(yyinyang); // 1是阳男阴女，2是阴男阳女
    switch (wwuxing)
    {
    case WuXingJu::ShuiEr:
        if (a == 1)
            Palace = DiZhi::Mao;
        else
            Palace = DiZhi::Chou;
        break;
    case WuXingJu::MuSan:
        if (a == 1)
            Palace = DiZhi::Wu;
        else
            Palace = DiZhi::Chen;
        break;
    case WuXingJu::JinSi:
        if (a == 1)
            Palace = DiZhi::Zi;
        else
            Palace = DiZhi::Xu;
        break;
    case WuXingJu::TuWu:
        if (a == 1)
            Palace = DiZhi::Mao;
        else
            Palace = DiZhi::Chou;
        break;
    case WuXingJu::HuoLiu:
        if (a == 1)
            Palace = DiZhi::You;
        else
            Palace = DiZhi::Wei;
        break;
    }
    Name = "死";
}

// 墓星类构造函数
MuXing::MuXing(WuXingJu wwuxing /* = WuXingJu::JinSi */, Gender ggender /*  = Gender::Male */, YinYang yyinyang /*  = YinYang::Yang */)
{
    int a = static_cast<int>(ggender) + static_cast<int>(yyinyang); // 1是阳男阴女，2是阴男阳女
    switch (wwuxing)
    {
    case WuXingJu::ShuiEr:
        if (a == 1)
            Palace = DiZhi::Chen;
        else
            Palace = DiZhi::Zi;
        break;
    case WuXingJu::MuSan:
        if (a == 1)
            Palace = DiZhi::Wei;
        else
            Palace = DiZhi::Mao;
        break;
    case WuXingJu::JinSi:
        if (a == 1)
            Palace = DiZhi::Chou;
        else
            Palace = DiZhi::You;
        break;
    case WuXingJu::TuWu:
        if (a == 1)
            Palace = DiZhi::Chen;
        else
            Palace = DiZhi::Zi;
        break;
    case WuXingJu::HuoLiu:
        if (a == 1)
            Palace = DiZhi::Xu;
        else
            Palace = DiZhi::Wu;
        break;
    }
    Name = "墓";
}

// 绝星类构造函数

JueXing::JueXing(WuXingJu wwuxing /* = WuXingJu::JinSi */, Gender ggender /*  = Gender::Male */, YinYang yyinyang /*  = YinYang::Yang */)
{
    int a = static_cast<int>(ggender) + static_cast<int>(yyinyang); // 1是阳男阴女，2是阴男阳女
    switch (wwuxing)
    {
    case WuXingJu::ShuiEr:
        if (a == 1)
            Palace = DiZhi::Si;
        else
            Palace = DiZhi::Hai;
        break;
    case WuXingJu::MuSan:
        if (a == 1)
            Palace = DiZhi::Shen;
        else
            Palace = DiZhi::Yin;
        break;
    case WuXingJu::JinSi:
        if (a == 1)
            Palace = DiZhi::Yin;
        else
            Palace = DiZhi::Shen;
        break;
    case WuXingJu::TuWu:
        if (a == 1)
            Palace = DiZhi::Si;
        else
            Palace = DiZhi::Hai;
        break;
    case WuXingJu::HuoLiu:
        if (a == 1)
            Palace = DiZhi::Zi;
        else
            Palace = DiZhi::Si;
        break;
    }
    Name = "绝";
}

// 胎星类构造函数

TaiXing::TaiXing(WuXingJu wwuxing /* = WuXingJu::JinSi */, Gender ggender /*  = Gender::Male */, YinYang yyinyang /*  = YinYang::Yang */)
{
    int a = static_cast<int>(ggender) + static_cast<int>(yyinyang); // 1是阳男阴女，2是阴男阳女
    switch (wwuxing)
    {
    case WuXingJu::ShuiEr:
        if (a == 1)
            Palace = DiZhi::Wu;
        else
            Palace = DiZhi::Xu;
        break;
    case WuXingJu::MuSan:
        if (a == 1)
            Palace = DiZhi::You;
        else
            Palace = DiZhi::Chou;
        break;
    case WuXingJu::JinSi:
        if (a == 1)
            Palace = DiZhi::Mao;
        else
            Palace = DiZhi::Wei;
        break;
    case WuXingJu::TuWu:
        if (a == 1)
            Palace = DiZhi::Wu;
        else
            Palace = DiZhi::Xu;
        break;
    case WuXingJu::HuoLiu:
        if (a == 1)
            Palace = DiZhi::Chou;
        else
            Palace = DiZhi::Chen;
        break;
    }
    Name = "胎";
}

// 养星类构造函数
YangXing::YangXing(WuXingJu wwuxing /* = WuXingJu::JinSi */, Gender ggender /*  = Gender::Male */, YinYang yyinyang /*  = YinYang::Yang */)
{
    int a = static_cast<int>(ggender) + static_cast<int>(yyinyang); // 1是阳男阴女，2是阴男阳女
    switch (wwuxing)
    {
    case WuXingJu::ShuiEr:
        if (a == 1)
            Palace = DiZhi::Wei;
        else
            Palace = DiZhi::You;
        break;
    case WuXingJu::MuSan:
        if (a == 1)
            Palace = DiZhi::Xu;
        else
            Palace = DiZhi::Zi;
        break;
    case WuXingJu::JinSi:
        if (a == 1)
            Palace = DiZhi::Chen;
        else
            Palace = DiZhi::Wu;
        break;
    case WuXingJu::TuWu:
        if (a == 1)
            Palace = DiZhi::Wei;
        else
            Palace = DiZhi::You;
        break;
    case WuXingJu::HuoLiu:
        if (a == 1)
            Palace = DiZhi::Yin;
        else
            Palace = DiZhi::Mao;
        break;
    }
    Name = "养";
}

//**************************************命主身主************************************

Case::Case(unsigned long long BBirthTime /*= 199002231934 */, double LLongitude /* = 120.0 */, Gender ggender /* =Gender::Male */, std::string nname /*  = "张三" */, std::string rremark /*  = "无备注" */) : info(BBirthTime, LLongitude), _gender(ggender), _name(nname), _remark(rremark)
{
    _yinyang = static_cast<YinYang>(static_cast<int>(info._NianZhi) % 2);
    s1 = BodyPalace(info._YueZhi, info._ShiZhi);
    s2 = LifePalace(info._YueZhi, info._ShiZhi);
    s3 = BrotherPalace(info._YueZhi, info._ShiZhi);
    s4 = CouplePalace(info._YueZhi, info._ShiZhi);
    s5 = ChildrenPalace(info._YueZhi, info._ShiZhi);
    s6 = MoneyPalace(info._YueZhi, info._ShiZhi);
    s7 = DiseasePalace(info._YueZhi, info._ShiZhi);
    s8 = MigrationPalace(info._YueZhi, info._ShiZhi);
    s9 = SlavePalace(info._YueZhi, info._ShiZhi);
    s10 = FunctionaryPalace(info._YueZhi, info._ShiZhi);
    s11 = FarmlandPalace(info._YueZhi, info._ShiZhi);
    s12 = FortunePalace(info._YueZhi, info._ShiZhi);
    s13 = ParentPalace(info._YueZhi, info._ShiZhi);
    wuxing = WuXingJuXing(info._NianGan, s2.showPalace()); // 五行局
    s15 = ZiWei(wuxing.WuXing, info.LDay);
    s16 = TianJi(s15.showPalace());
    s17 = TaiYang(s15.showPalace());
    s18 = WuQu(s15.showPalace());
    s19 = TianTong(s15.showPalace());
    s20 = LianZhen(s15.showPalace());
    s21 = TianFu(s15.showPalace());
    s22 = TaiYin(s21.showPalace());
    s23 = TanLang(s21.showPalace());
    s24 = JuMen(s21.showPalace());
    s25 = TianXiang(s21.showPalace());
    s26 = TianLiang(s21.showPalace());
    s27 = QiSha(s21.showPalace());
    s28 = PoJun(s21.showPalace());

    s29 = WenChang(info._ShiZhi);
    s30 = WenQu(info._ShiZhi);
    s31 = HuoXing(info._ShiZhi, info._NianZhi);
    s32 = LingXing(info._ShiZhi, info._NianZhi);
    s33 = DiJie(info._ShiZhi);
    s34 = TianKong(info._ShiZhi);
    s35 = TaiFu(info._ShiZhi);
    s36 = FengGao(info._ShiZhi);
    // 根据本文件中构造函数，初始化剩余星
    s37 = ZuoFu(info._YueZhi);
    s38 = YouBi(info._YueZhi);
    s39 = TianXing(info._YueZhi);
    s40 = TianYao(info._YueZhi);
    s41 = TianMa(info._YueZhi);
    s42 = JieShen(info._YueZhi);
    s43 = TianWu(info._YueZhi);
    s44 = TianYue_2(info._YueZhi);
    s45 = YinSha(info._YueZhi);

    s46 = SanTai(s37.showPalace(), info.LDay);
    s47 = BaZuo(s38.showPalace(), info.LDay);
    s48 = EnGuang(s29.showPalace(), info.LDay);
    s49 = TianGui(s30.showPalace(), info.LDay);
    s50 = LuCun_(info._NianGan);
    s51 = QingYang(info._NianGan);
    s52 = TuoLuo(info._NianGan);
    s53 = TianKui(info._NianGan);
    s54 = TianYue(info._NianGan);
    s55 = TianGuan(info._NianGan);
    s56 = TianFu_2(info._NianGan);

    DiZhi HUALU[10]{s20.showPalace(), s16.showPalace(), s19.showPalace(), s22.showPalace(), s23.showPalace(), s18.showPalace(), s17.showPalace(), s24.showPalace(), s26.showPalace(), s28.showPalace()};
    s57 = HuaLu(info._NianGan, HUALU);

    DiZhi HUAQUAN[10]{s28.showPalace(), s26.showPalace(), s16.showPalace(), s19.showPalace(), s22.showPalace(), s23.showPalace(), s18.showPalace(), s17.showPalace(), s15.showPalace(), s24.showPalace()};
    s58 = HuaQuan(info._NianGan, HUAQUAN);

    DiZhi HUAKE[10]{s18.showPalace(), s15.showPalace(), s29.showPalace(), s16.showPalace(), s38.showPalace(), s26.showPalace(), s22.showPalace(), s30.showPalace(), s37.showPalace(), s22.showPalace()};
    s59 = HuaKe(info._NianGan, HUAKE);

    DiZhi HUAJI[10]{s17.showPalace(), s22.showPalace(), s20.showPalace(), s24.showPalace(), s16.showPalace(), s30.showPalace(), s19.showPalace(), s29.showPalace(), s18.showPalace(), s23.showPalace()};
    s60 = HuaJi(info._NianGan, HUAJI);

    s61 = BoShi(s50.showPalace(), _yinyang, _gender);
    s62 = LiShi(s50.showPalace(), _yinyang, _gender);
    s63 = QingLong(s50.showPalace(), _yinyang, _gender);
    s64 = XiaoHao(s50.showPalace(), _yinyang, _gender);
    s65 = JiangJun(s50.showPalace(), _yinyang, _gender);
    s66 = ZouShu(s50.showPalace(), _yinyang, _gender);
    s67 = FeiLian(s50.showPalace(), _yinyang, _gender);
    s68 = XiShen(s50.showPalace(), _yinyang, _gender);
    s69 = BingFu(s50.showPalace(), _yinyang, _gender);
    s70 = DaHao(s50.showPalace(), _yinyang, _gender);
    s71 = FuBing(s50.showPalace(), _yinyang, _gender);
    s72 = GuanFu(s50.showPalace(), _yinyang, _gender);

    s73 = DiKong(info._NianZhi);
    s74 = TianKu(info._NianZhi);
    s75 = TianXu(info._NianZhi);
    s76 = LongChi(info._NianZhi);
    s77 = FengGe(info._NianZhi);
    s78 = HongLuan(info._NianZhi);
    s79 = TianXi(info._NianZhi);
    s80 = FeiLian_2(info._NianZhi);
    s81 = PoSui(info._NianZhi);
    s82 = GuChen(info._NianZhi);
    s83 = GuaSu(info._NianZhi);

    DiZhi TIANCAI[12]{s2.showPalace(), s13.showPalace(), s12.showPalace(), s11.showPalace(), s10.showPalace(), s9.showPalace(), s8.showPalace(), s7.showPalace(), s6.showPalace(), s5.showPalace(), s4.showPalace(), s3.showPalace()};
    s84 = TianCai(info._NianZhi, TIANCAI);

    s85 = TianShou(info._NianZhi, s1.showPalace());

    s86 = ChangSheng(wuxing.WuXing, _gender, _yinyang);
    s87 = MuYu(wuxing.WuXing, _gender, _yinyang);
    s88 = GuanDai(wuxing.WuXing, _gender, _yinyang);
    s89 = LinGuan(wuxing.WuXing, _gender, _yinyang);
    s90 = DiWang(wuxing.WuXing, _gender, _yinyang);
    s91 = ShuaiXing(wuxing.WuXing, _gender, _yinyang);
    s92 = BingXing(wuxing.WuXing, _gender, _yinyang);
    s93 = SiXing(wuxing.WuXing, _gender, _yinyang);
    s94 = MuXing(wuxing.WuXing, _gender, _yinyang);
    s95 = JueXing(wuxing.WuXing, _gender, _yinyang);
    s96 = TaiXing(wuxing.WuXing, _gender, _yinyang);
    s97 = YangXing(wuxing.WuXing, _gender, _yinyang);
}
// 排盘函数，可以展示命例的排盘结果
void Case::show()
{ // 使用循环，如果宫位信息等于对应宫信息，那么输出星的名字。

    std::cout << "子: ";
    for (int i = 0; i < 97; i++)
    {
        if (_stars[i] != nullptr)
        {
            if (_stars[i]->showPalace() == DiZhi::Zi)
            {
                std::cout << _stars[i]->Name << std::flush << " ";
            }
        }
    }

    std::cout << "\n丑：";
    for (int i = 0; i < 97; i++)
    {
        if (_stars[i] != nullptr)
        {
            if (_stars[i]->showPalace() == DiZhi::Chou)
            {
                std::cout << _stars[i]->Name << std::flush << " ";
            }
        }
    }

    std::cout << "\n寅：";
    for (int i = 0; i < 97; i++)
    {
        if (_stars[i] != nullptr)
        {
            if (_stars[i]->showPalace() == DiZhi::Yin)
            {
                std::cout << _stars[i]->Name << " ";
            }
        }
    }
    std::cout << "\n卯：";
    for (int i = 0; i < 97; i++)
    {
        if (_stars[i] != nullptr)
        {
            if (_stars[i]->showPalace() == DiZhi::Mao)
            {
                std::cout << _stars[i]->Name << " ";
            }
        }
    }
    std::cout << "\n辰：";
    for (int i = 0; i < 97; i++)
    {
        if (_stars[i] != nullptr)
        {
            if (_stars[i]->showPalace() == DiZhi::Chen)
            {
                std::cout << _stars[i]->Name << " ";
            }
        }
    }
    std::cout << "\n巳：";
    for (int i = 0; i < 97; i++)
    {
        if (_stars[i] != nullptr)
        {
            if (_stars[i]->showPalace() == DiZhi::Si)
            {
                std::cout << _stars[i]->Name << " ";
            }
        }
    }
    std::cout << "\n午：";
    for (int i = 0; i < 97; i++)
    {
        if (_stars[i] != nullptr)
        {
            if (_stars[i]->showPalace() == DiZhi::Wu)
            {
                std::cout << _stars[i]->Name << " ";
            }
        }
    }
    std::cout << "\n未：";
    for (int i = 0; i < 97; i++)
    {
        if (_stars[i] != nullptr)
        {
            if (_stars[i]->showPalace() == DiZhi::Wei)
            {
                std::cout << _stars[i]->Name << " ";
            }
        }
    }
    std::cout << "\n申：";
    for (int i = 0; i < 97; i++)
    {
        if (_stars[i] != nullptr)
        {
            if (_stars[i]->showPalace() == DiZhi::Shen)
            {
                std::cout << _stars[i]->Name << " ";
            }
        }
    }
    std::cout << "\n酉：";
    for (int i = 0; i < 97; i++)
    {
        if (_stars[i] != nullptr)
        {
            if (_stars[i]->showPalace() == DiZhi::You)
            {
                std::cout << _stars[i]->Name << " ";
            }
        }
    }

    std::cout << "\n戌：";
    for (int i = 0; i < 97; i++)
    {
        if (_stars[i] != nullptr)
        {
            if (_stars[i]->showPalace() == DiZhi::Xu)
            {
                std::cout << _stars[i]->Name << " ";
            }
        }
    }
    std::cout << "\n亥：";
    for (int i = 0; i < 97; i++)
    {
        if (_stars[i] != nullptr)
        {
            if (_stars[i]->showPalace() == DiZhi::Hai)
            {
                std::cout << _stars[i]->Name << " ";
            }
        }
    }
    std::cout << "\n";
}

// 复制构造函数
Case::Case(const Case &c)
    : info(c.info), s1(c.s1), s2(c.s2), s3(c.s3), s4(c.s4),
      s5(c.s5), s6(c.s6), s7(c.s7), s8(c.s8), s9(c.s9),
      s10(c.s10), s11(c.s11), s12(c.s12), s13(c.s13), wuxing(c.wuxing), s15(c.s15),
      s16(c.s16), s17(c.s17), s18(c.s18), s19(c.s19), s20(c.s20),
      s21(c.s21), s22(c.s22), s23(c.s23), s24(c.s24), s25(c.s25),
      s26(c.s26), s27(c.s27), s28(c.s28), s29(c.s29), s30(c.s30),
      s31(c.s31), s32(c.s32), s33(c.s33), s34(c.s34), s35(c.s35),
      s36(c.s36), s37(c.s37), s38(c.s38), s39(c.s39), s40(c.s40),
      s41(c.s41), s42(c.s42), s43(c.s43), s44(c.s44), s45(c.s45),
      s46(c.s46), s47(c.s47), s48(c.s48), s49(c.s49), s50(c.s50),
      s51(c.s51), s52(c.s52), s53(c.s53), s54(c.s54), s55(c.s55),
      s56(c.s56), s57(c.s57), s58(c.s58), s59(c.s59), s60(c.s60),
      s61(c.s61), s62(c.s62), s63(c.s63), s64(c.s64), s65(c.s65),
      s66(c.s66), s67(c.s67), s68(c.s68), s69(c.s69), s70(c.s70),
      s71(c.s71), s72(c.s72), s73(c.s73), s74(c.s74), s75(c.s75),
      s76(c.s76), s77(c.s77), s78(c.s78), s79(c.s79), s80(c.s80),
      s81(c.s81), s82(c.s82), s83(c.s83), s84(c.s84), s85(c.s85),
      s86(c.s86), s87(c.s87), s88(c.s88), s89(c.s89), s90(c.s90),
      s91(c.s91), s92(c.s92), s93(c.s93), s94(c.s94), s95(c.s95),
      s96(c.s96), s97(c.s97), _yinyang(c._yinyang), _gender(c._gender),
      _name(c._name), _remark(c._remark)
{
    // 深复制 StarBase 对象数组
    _stars[0] = &s1;
    _stars[1] = &s2;
    _stars[2] = &s3;
    _stars[3] = &s4;
    _stars[4] = &s5;
    _stars[5] = &s6;
    _stars[6] = &s7;
    _stars[7] = &s8;
    _stars[8] = &s9;
    _stars[9] = &s10;
    _stars[10] = &s11;
    _stars[11] = &s12;
    _stars[12] = &s13;
    _stars[13] = nullptr;
    _stars[14] = &s15;
    _stars[15] = &s16;
    _stars[16] = &s17;
    _stars[17] = &s18;
    _stars[18] = &s19;
    _stars[19] = &s20;
    _stars[20] = &s21;
    _stars[21] = &s22;
    _stars[22] = &s23;
    _stars[23] = &s24;
    _stars[24] = &s25;
    _stars[25] = &s26;
    _stars[26] = &s27;
    _stars[27] = &s28;
    _stars[28] = &s29;
    _stars[29] = &s30;
    _stars[30] = &s31;
    _stars[31] = &s32;
    _stars[32] = &s33;
    _stars[33] = &s34;
    _stars[34] = &s35;
    _stars[35] = &s36;
    _stars[36] = &s37;
    _stars[37] = &s38;
    _stars[38] = &s39;
    _stars[39] = &s40;
    _stars[40] = &s41;
    _stars[41] = &s42;
    _stars[42] = &s43;
    _stars[43] = &s44;
    _stars[44] = &s45;
    _stars[45] = &s46;
    _stars[46] = &s47;
    _stars[47] = &s48;
    _stars[48] = &s49;
    _stars[49] = &s50;
    _stars[50] = &s51;
    _stars[51] = &s52;
    _stars[52] = &s53;
    _stars[53] = &s54;
    _stars[54] = &s55;
    _stars[55] = &s56;
    _stars[56] = &s57;
    _stars[57] = &s58;
    _stars[58] = &s59;
    _stars[59] = &s60;
    _stars[60] = &s61;
    _stars[61] = &s62;
    _stars[62] = &s63;
    _stars[63] = &s64;
    _stars[64] = &s65;
    _stars[65] = &s66;
    _stars[66] = &s67;
    _stars[67] = &s68;
    _stars[68] = &s69;
    _stars[69] = &s70;
    _stars[70] = &s71;
    _stars[71] = &s72;
    _stars[72] = &s73;
    _stars[73] = &s74;
    _stars[74] = &s75;
    _stars[75] = &s76;
    _stars[76] = &s77;
    _stars[77] = &s78;
    _stars[78] = &s79;
    _stars[79] = &s80;
    _stars[80] = &s81;
    _stars[81] = &s82;
    _stars[82] = &s83;
    _stars[83] = &s84;
    _stars[84] = &s85;
    _stars[85] = &s86;
    _stars[86] = &s87;
    _stars[87] = &s88;
    _stars[88] = &s89;
    _stars[89] = &s90;
    _stars[90] = &s91;
    _stars[91] = &s92;
    _stars[92] = &s93;
    _stars[93] = &s94;
    _stars[94] = &s95;
    _stars[95] = &s96;
    _stars[96] = &s97;
}