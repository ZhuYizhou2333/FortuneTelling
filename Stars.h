#ifndef PAI_PAN_H
#define PAI_PAN_H

#include "sizhu.h"
#include <string>

// 此头文件及实现主要包含了排盘过程中的数据与函数。有一个星的基类。
// 以此发展出不同的星，不同的星具有不同的安星方法。
// 不同的星之间有着一些联系，比如某星的安星方法需要借用到另一个星的数据（位置）。
// 在构建星这个对象时，可能会调用别的类，形成类的组合。
// 需要在本类声明前声明组合类。

enum class WuXingJu
{
    ShuiEr = 1,
    HuoLiu,
    TuWu,
    MuSan,
    JinSi
};
enum class Gender
{
    Male,
    Female
};
enum class YinYang
{
    Yin,
    Yang
};

class StarBase
{
private:
protected:
    DiZhi Palace;

public:
    StarBase();
    // 要有宫的信息，宫的信息即为12地支之一。

    DiZhi showPalace(){return this->Palace;};
    void setPalace(DiZhi palace){Palace = palace;};
    void setName(std::string name){Name = name;};
    std::string Name;
};

class BodyPalace : public StarBase
{
private:
public:
    // 身宫的构造函数。
    BodyPalace(DiZhi YYueZhi = DiZhi::Yin, DiZhi SShiZhi = DiZhi::Xu);
};

class LifePalace : public StarBase
{
private:
public:
    // 命宫的构造函数。
    LifePalace(DiZhi YYueZhi = DiZhi::Yin, DiZhi SShiZhi = DiZhi::Xu);
};

class BrotherPalace : public StarBase
{
private:
public:
    // 兄弟宫构造函数。
    BrotherPalace(DiZhi YYueZhi = DiZhi::Yin, DiZhi SShiZhi = DiZhi::Xu);
};

class CouplePalace : public StarBase
{
private:
public:
    // 夫妻宫构造函数。
    CouplePalace(DiZhi YYueZhi = DiZhi::Yin, DiZhi SShiZhi = DiZhi::Xu);
};

class ChildrenPalace : public StarBase
{
private:
public:
    // 兄弟宫构造函数。
    ChildrenPalace(DiZhi YYueZhi = DiZhi::Yin, DiZhi SShiZhi = DiZhi::Xu);
};

class MoneyPalace : public StarBase
{
private:
public:
    // 兄弟宫构造函数。
    MoneyPalace(DiZhi YYueZhi = DiZhi::Yin, DiZhi SShiZhi = DiZhi::Xu);
};

class DiseasePalace : public StarBase
{
private:
public:
    // 疾厄宫构造函数。
    DiseasePalace(DiZhi YYueZhi = DiZhi::Yin, DiZhi SShiZhi = DiZhi::Xu);
};

class MigrationPalace : public StarBase
{
private:
public:
    // 迁移宫构造函数。
    MigrationPalace(DiZhi YYueZhi = DiZhi::Yin, DiZhi SShiZhi = DiZhi::Xu);
};

class SlavePalace : public StarBase
{
private:
public:
    // 仆役宫构造函数。
    SlavePalace(DiZhi YYueZhi = DiZhi::Yin, DiZhi SShiZhi = DiZhi::Xu);
};

class FunctionaryPalace : public StarBase
{
private:
public:
    // 官禄宫构造函数。
    FunctionaryPalace(DiZhi YYueZhi = DiZhi::Yin, DiZhi SShiZhi = DiZhi::Xu);
};

class FarmlandPalace : public StarBase
{
private:
public:
    // 田宅宫构造函数。
    FarmlandPalace(DiZhi YYueZhi = DiZhi::Yin, DiZhi SShiZhi = DiZhi::Xu);
};

class FortunePalace : public StarBase
{
private:
public:
    // 福德宫构造函数。
    FortunePalace(DiZhi YYueZhi = DiZhi::Yin, DiZhi SShiZhi = DiZhi::Xu);
};

class ParentPalace : public StarBase
{
private:
public:
    // 父母宫构造函数。
    ParentPalace(DiZhi YYueZhi = DiZhi::Yin, DiZhi SShiZhi = DiZhi::Xu);
};

class WuXingJuXing
{
private:
public:
    WuXingJu WuXing;
    // 五行局构造函数。
    WuXingJuXing(TianGan NNianGan = TianGan::Geng, DiZhi LLifePalace = DiZhi::Chen);
};

class ZiWei : public StarBase
{
private:
public:
    // 紫微星构造函数。
    ZiWei(WuXingJu WWuXing = WuXingJu::JinSi, int LLDay = 28);
};

class TianJi : public StarBase
{
private:
public:
    // 天机星构造函数。
    TianJi(DiZhi ZiWei = DiZhi::Shen);
};

class TaiYang : public StarBase
{
private:
public:
    // 太阳星构造函数。
    TaiYang(DiZhi ZiWei = DiZhi::Shen);
};

class WuQu : public StarBase
{
private:
public:
    // 武曲星构造函数。
    WuQu(DiZhi ZiWei = DiZhi::Shen);
};

class TianTong : public StarBase
{
private:
public:
    // 天同星构造函数。
    TianTong(DiZhi ZiWei = DiZhi::Shen);
};

class LianZhen : public StarBase
{
private:
public:
    // 廉贞星构造函数。
    LianZhen(DiZhi ZiWei = DiZhi::Shen);
};
//*************************************天府星系*****************************************
class TianFu : public StarBase
{
private:
public:
    // 天府星构造函数。
    TianFu(DiZhi ZiWei = DiZhi::Shen);
};
// 太阴星类
class TaiYin : public StarBase
{
private:
public:
    // 太阴星构造函数。
    TaiYin(DiZhi Tianfu = DiZhi::Shen);
};

// 贪狼星类
class TanLang : public StarBase
{
private:
public:
    // 贪狼星构造函数。
    TanLang(DiZhi Tianfu = DiZhi::Shen);
};
// 巨门星类
class JuMen : public StarBase
{
private:
public:
    // 巨门星构造函数。
    JuMen(DiZhi Tianfu = DiZhi::Shen);
};
// 天相星类
class TianXiang : public StarBase
{
private:
public:
    // 天相星构造函数。
    TianXiang(DiZhi Tianfu = DiZhi::Shen);
};
// 天梁星类
class TianLiang : public StarBase
{
private:
public:
    // 天梁星构造函数。
    TianLiang(DiZhi Tianfu = DiZhi::Shen);
};
// 七杀星类
class QiSha : public StarBase
{
private:
public:
    // 七杀星构造函数。
    QiSha(DiZhi Tianfu = DiZhi::Shen);
};
// 破军星类
class PoJun : public StarBase
{
private:
public:
    // 破军星构造函数。
    PoJun(DiZhi Tianfu = DiZhi::Shen);
};

//****************************************时系诸星****************************************
// 文昌星类
class WenChang : public StarBase
{
private:
public:
    // 文昌星构造函数。
    WenChang(DiZhi ShiZhi = DiZhi::Xu);
};
// 文曲星类
class WenQu : public StarBase
{
private:
public:
    // 文曲星构造函数。
    WenQu(DiZhi ShiZhi = DiZhi::Xu);
};
// 火星类
class HuoXing : public StarBase
{
private:
public:
    // 火星构造函数。
    HuoXing(DiZhi ShiZhi = DiZhi::Xu, DiZhi NianZhi = DiZhi::Wu);
};
// 铃星类
class LingXing : public StarBase
{
private:
public:
    // 铃星构造函数。
    LingXing(DiZhi ShiZhi = DiZhi::Xu, DiZhi NianZhi = DiZhi::Wu);
};
// 地劫星类
class DiJie : public StarBase
{
private:
public:
    // 地劫星构造函数。
    DiJie(DiZhi ShiZhi = DiZhi::Xu);
};
// 天空星类
class TianKong : public StarBase
{
private:
public:
    // 天空星构造函数。
    TianKong(DiZhi ShiZhi = DiZhi::Xu);
};
// 台辅星类
class TaiFu : public StarBase
{
private:
public:
    // 台辅星构造函数。
    TaiFu(DiZhi ShiZhi = DiZhi::Xu);
};
// 封诰星类
class FengGao : public StarBase
{
private:
public:
    // 封诰星构造函数。
    FengGao(DiZhi ShiZhi = DiZhi::Xu);
};

//***********************************月系诸星**************************************

// 左辅星类
class ZuoFu : public StarBase
{
private:
public:
    // 左辅星构造函数。
    ZuoFu(WORD llmonth=1);
};

// 右弼星类
class YouBi : public StarBase
{
private:
public:
    // 右弼星构造函数。
    YouBi(WORD llmonth=1);
};

// 天刑星类
class TianXing : public StarBase
{
private:
public:
    // 天刑星构造函数。
    TianXing(WORD llmonth=1);
};

// 天姚星类
class TianYao : public StarBase
{
private:
public:
    // 天姚星构造函数。
    TianYao(WORD llmonth=1);
};

// 天马星类
class TianMa : public StarBase
{
private:
public:
    // 天马星构造函数。
    TianMa(WORD llmonth=1);
};

// 解神星类
class JieShen : public StarBase
{
private:
public:
    // 解神星构造函数。
    JieShen(WORD llmonth=1);
};

// 天巫星类
class TianWu : public StarBase
{
private:
public:
    // 天巫星构造函数。
    TianWu(WORD llmonth=1);
};

// 天月星类
class TianYue_2 : public StarBase
{
private:
public:
    // 天月星构造函数。
    TianYue_2(WORD llmonth=1);
};

// 阴煞星类
class YinSha : public StarBase
{
private:
public:
    // 阴煞星构造函数。
    YinSha(WORD llmonth=1);
};

//**********************************日系诸星******************************************

// 三台星类
class SanTai : public StarBase
{
private:
public:
    // 三台星构造函数。
    SanTai(DiZhi ZuoFu = DiZhi::Chen, int LDay = 28);
};

// 八座星类
class BaZuo : public StarBase
{
private:
public:
    // 八座星构造函数。
    BaZuo(DiZhi YouBi = DiZhi::Xu, int LDay = 28);
};

// 恩光星类
class EnGuang : public StarBase
{
private:
public:
    // 恩光星构造函数。
    EnGuang(DiZhi WenChang = DiZhi::Zi, int LDay = 28);
};

// 天贵星类
class TianGui : public StarBase
{
private:
public:
    // 天贵星构造函数。
    TianGui(DiZhi WenQu = DiZhi::Yin, int LDay = 28);
};

//***********************************干系诸星******************************************

// 禄存星类
class LuCun_ : public StarBase
{
private:
public:
    // 禄存星构造函数。
    LuCun_(TianGan NianGan = TianGan::Geng);
};

// 擎羊星类
class QingYang : public StarBase
{
private:
public:
    // 擎羊星构造函数。
    QingYang(TianGan NianGan = TianGan::Geng);
};

// 陀罗星类
class TuoLuo : public StarBase
{
private:
public:
    // 陀罗星构造函数。
    TuoLuo(TianGan NianGan = TianGan::Geng);
};

// 天魁星类
class TianKui : public StarBase
{
private:
public:
    // 天魁星构造函数。
    TianKui(TianGan NianGan = TianGan::Geng);
};

// 天钺星类
class TianYue : public StarBase
{
private:
public:
    // 天钺星构造函数。
    TianYue(TianGan NianGan = TianGan::Geng);
};

// 天官星类
class TianGuan : public StarBase
{
private:
public:
    // 天官星构造函数。
    TianGuan(TianGan NianGan = TianGan::Geng);
};

// 天福星类
class TianFu_2 : public StarBase
{
private:
public:
    // 天福星构造函数。
    TianFu_2(TianGan NianGan = TianGan::Geng);
};

// 化禄星类
class HuaLu : public StarBase
{
private:
public:
    // 化禄星构造函数。
    HuaLu(TianGan NianGan = TianGan::Geng, DiZhi *array=nullptr);
}; // 在case类中需要提前定义好array数组，需要按照构造顺序定义。

// 化权星类
class HuaQuan : public StarBase
{
private:
public:
    // 化权星构造函数。
    HuaQuan(TianGan NianGan = TianGan::Geng, DiZhi *array=nullptr);
};

// 化科星类
class HuaKe : public StarBase
{
private:
public:
    // 化科星构造函数。
    HuaKe(TianGan NianGan = TianGan::Geng, DiZhi *array=nullptr);
};

// 化忌星类
class HuaJi : public StarBase
{
private:
public:
    // 化忌星构造函数。
    HuaJi(TianGan NianGan = TianGan::Geng, DiZhi *array=nullptr);
};

//*******************************生年博士十二星****************************************

// 博士星类
class BoShi : public StarBase
{
private:
public:
    // 博士星构造函数。
    BoShi(DiZhi LLuCun = DiZhi::Shen, YinYang YYinYang = YinYang::Yang, Gender GGender = Gender::Male);
};

// 力士星类
class LiShi : public StarBase
{
private:
public:
    // 力士星构造函数。
    LiShi(DiZhi LLuCun = DiZhi::Shen, YinYang YYinYang = YinYang::Yang, Gender GGender = Gender::Male);
};

// 青龙星类
class QingLong : public StarBase
{
private:
public:
    // 青龙星构造函数。
    QingLong(DiZhi LLuCun = DiZhi::Shen, YinYang YYinYang = YinYang::Yang, Gender GGender = Gender::Male);
};

// 小耗星类
class XiaoHao : public StarBase
{
private:
public:
    // 小耗星构造函数。
    XiaoHao(DiZhi LLuCun = DiZhi::Shen, YinYang YYinYang = YinYang::Yang, Gender GGender = Gender::Male);
};

// 将军星类
class JiangJun : public StarBase
{
private:
public:
    // 将军星构造函数。
    JiangJun(DiZhi LLuCun = DiZhi::Shen, YinYang YYinYang = YinYang::Yang, Gender GGender = Gender::Male);
};

// 奏书星类
class ZouShu : public StarBase
{
private:
public:
    // 奏书星构造函数。
    ZouShu(DiZhi LLuCun = DiZhi::Shen, YinYang YYinYang = YinYang::Yang, Gender GGender = Gender::Male);
};

// 飞廉星类
class FeiLian : public StarBase
{
private:
public:
    // 飞廉星构造函数。
    FeiLian(DiZhi LLuCun = DiZhi::Shen, YinYang YYinYang = YinYang::Yang, Gender GGender = Gender::Male);
};

// 喜神星类
class XiShen : public StarBase
{
private:
public:
    // 喜神星构造函数。
    XiShen(DiZhi LLuCun = DiZhi::Shen, YinYang YYinYang = YinYang::Yang, Gender GGender = Gender::Male);
};

// 病符星类
class BingFu : public StarBase
{
private:
public:
    // 病符星构造函数。
    BingFu(DiZhi LLuCun = DiZhi::Shen, YinYang YYinYang = YinYang::Yang, Gender GGender = Gender::Male);
};

// 大耗星类
class DaHao : public StarBase
{
private:
public:
    // 大耗星构造函数。
    DaHao(DiZhi LLuCun = DiZhi::Shen, YinYang YYinYang = YinYang::Yang, Gender GGender = Gender::Male);
};

// 伏兵星类
class FuBing : public StarBase
{
private:
public:
    // 伏兵星构造函数。
    FuBing(DiZhi LLuCun = DiZhi::Shen, YinYang YYinYang = YinYang::Yang, Gender GGender = Gender::Male);
};

// 官府星类
class GuanFu : public StarBase
{
private:
public:
    // 官府星构造函数。
    GuanFu(DiZhi LLuCun = DiZhi::Shen, YinYang YYinYang = YinYang::Yang, Gender GGender = Gender::Male);
};

//*********************************年支系诸星*************************************

// 地空星类
class DiKong : public StarBase
{
private:
public:
    // 地空星构造函数。
    DiKong(DiZhi NianZhi = DiZhi::Wu);
};

// 天哭星类
class TianKu : public StarBase
{
private:
public:
    // 天哭星构造函数。
    TianKu(DiZhi NianZhi = DiZhi::Wu);
};

// 天虚星类
class TianXu : public StarBase
{
private:
public:
    // 天虚星构造函数。
    TianXu(DiZhi NianZhi = DiZhi::Wu);
};

// 龙池星类
class LongChi : public StarBase
{
private:
public:
    // 龙池星构造函数。
    LongChi(DiZhi NianZhi = DiZhi::Wu);
};

// 凤阁星类
class FengGe : public StarBase
{
private:
public:
    // 凤阁星构造函数。
    FengGe(DiZhi NianZhi = DiZhi::Wu);
};

// 红鸾星类
class HongLuan : public StarBase
{
private:
public:
    // 红鸾星构造函数。
    HongLuan(DiZhi NianZhi = DiZhi::Wu);
};

// 天喜星类
class TianXi : public StarBase
{
private:
public:
    // 天喜星构造函数。
    TianXi(DiZhi NianZhi = DiZhi::Wu);
};

// 蜚蠊星类
class FeiLian_2 : public StarBase
{
private:
public:
    // 蜚蠊星构造函数。
    FeiLian_2(DiZhi NianZhi = DiZhi::Wu);
};

// 破碎星类
class PoSui : public StarBase
{
private:
public:
    // 破碎星构造函数。
    PoSui(DiZhi NianZhi = DiZhi::Wu);
};

// 孤辰星类
class GuChen : public StarBase
{
private:
public:
    // 孤辰星构造函数。
    GuChen(DiZhi NianZhi = DiZhi::Wu);
};

// 寡宿星类
class GuaSu : public StarBase
{
private:
public:
    // 寡宿星构造函数。
    GuaSu(DiZhi NianZhi = DiZhi::Wu);
};

// 天才星类
class TianCai : public StarBase
{
private:
public:
    // 天才星构造函数。
    TianCai(DiZhi NianZhi = DiZhi::Wu, DiZhi *array = nullptr);
};

// 天寿星类
class TianShou : public StarBase
{
private:
public:
    // 天寿星构造函数。
    TianShou(DiZhi NianZhi = DiZhi::Wu, DiZhi BBodyPalace = DiZhi::Zi);
};

//**********************************五行长生十二星************************************

// 长生星类
class ChangSheng : public StarBase
{
private:
public:
    // 长生星构造函数。
    ChangSheng(WuXingJu wwuxing = WuXingJu::JinSi, Gender ggender = Gender::Male, YinYang yyinyang = YinYang::Yang);
};

// 沐浴星类
class MuYu : public StarBase
{
private:
public:
    // 沐浴星构造函数。
    MuYu(WuXingJu wwuxing = WuXingJu::JinSi, Gender ggender = Gender::Male, YinYang yyinyang = YinYang::Yang);
};
// 冠带星类
class GuanDai : public StarBase
{
private:
public:
    // 冠带星构造函数。
    GuanDai(WuXingJu wwuxing = WuXingJu::JinSi, Gender ggender = Gender::Male, YinYang yyinyang = YinYang::Yang);
};
// 临官星类
class LinGuan : public StarBase
{
private:
public:
    // 临官星构造函数。
    LinGuan(WuXingJu wwuxing = WuXingJu::JinSi, Gender ggender = Gender::Male, YinYang yyinyang = YinYang::Yang);
};

// 帝王星类
class DiWang : public StarBase
{
private:
public:
    // 帝王星构造函数。
    DiWang(WuXingJu wwuxing = WuXingJu::JinSi, Gender ggender = Gender::Male, YinYang yyinyang = YinYang::Yang);
};
// 衰星类
class ShuaiXing : public StarBase
{
private:
public:
    // 衰星构造函数。
    ShuaiXing(WuXingJu wwuxing = WuXingJu::JinSi, Gender ggender = Gender::Male, YinYang yyinyang = YinYang::Yang);
};
// 病星类
class BingXing : public StarBase
{
private:
public:
    // 病星构造函数。
    BingXing(WuXingJu wwuxing = WuXingJu::JinSi, Gender ggender = Gender::Male, YinYang yyinyang = YinYang::Yang);
};

// 死星类
class SiXing : public StarBase
{
private:
public:
    // 死星构造函数。
    SiXing(WuXingJu wwuxing = WuXingJu::JinSi, Gender ggender = Gender::Male, YinYang yyinyang = YinYang::Yang);
};

// 墓星类
class MuXing : public StarBase
{
private:
public:
    // 墓星构造函数。
    MuXing(WuXingJu wwuxing = WuXingJu::JinSi, Gender ggender = Gender::Male, YinYang yyinyang = YinYang::Yang);
};

// 绝星类
class JueXing : public StarBase
{
private:
public:
    // 绝星构造函数。
    JueXing(WuXingJu wwuxing = WuXingJu::JinSi, Gender ggender = Gender::Male, YinYang yyinyang = YinYang::Yang);
};

// 胎星类
class TaiXing : public StarBase
{
private:
public:
    // 胎星构造函数。
    TaiXing(WuXingJu wwuxing = WuXingJu::JinSi, Gender ggender = Gender::Male, YinYang yyinyang = YinYang::Yang);
};

// 养星类
class YangXing : public StarBase
{
private:
public:
    // 养星构造函数。
    YangXing(WuXingJu wwuxing = WuXingJu::JinSi, Gender ggender = Gender::Male, YinYang yyinyang = YinYang::Yang);
};

//************************************截路空亡**************************************

// // 截路空亡星类
// class JieLuKongWang : public StarBase
// {
// private:
// public:
//     // 截路空亡星构造函数。
//     JieLuKongWang(TianGan NianGan = TianGan::Geng);
// };

//************************************旬空*****************************************

// 旬空类

//************************************天伤天使**************************************

// // 天伤星类
// class TianShang : public StarBase
// {
// private:
// public:
//     // 天伤星构造函数。
//     TianShang(DiZhi PPuYi = DiZhi::Chen);
// };

// // 天使星类
// class TianShi : public StarBase
// {
// private:
// public:
//     // 天使星构造函数。
//     TianShi(DiZhi JJiE = DiZhi::Chen);
// };

//**************************************命主身主************************************

// 命主
// class MingZhu
// {
// private:
// public:
//     // 命主构造函数。
//     MingZhu(DiZhi LifePalace = DiZhi::Chen);
// };

// // 身主

// class ShenZhu
// {
// private:
// public:
//     // 身主构造函数。
//     ShenZhu(DiZhi LifePalace = DiZhi::Chen);
// };

// 这个类用来统一初始化星，只需要一次计算八字。
class Case
{
private:
    sizhu info;

    BodyPalace s1;
    LifePalace s2;
    BrotherPalace s3;
    CouplePalace s4;
    ChildrenPalace s5;
    MoneyPalace s6;
    DiseasePalace s7;
    MigrationPalace s8;
    SlavePalace s9;
    FunctionaryPalace s10;
    FarmlandPalace s11;
    FortunePalace s12;
    ParentPalace s13;

    WuXingJuXing wuxing;//！！！这个不是星！！！
    ZiWei s15;

    TianJi s16;
    TaiYang s17;
    WuQu s18;
    TianTong s19;
    LianZhen s20;
    TianFu s21;

    TaiYin s22;
    TanLang s23;
    JuMen s24;
    TianXiang s25;
    TianLiang s26;
    QiSha s27;
    PoJun s28;
    WenChang s29;
    WenQu s30;
    HuoXing s31;
    LingXing s32;
    DiJie s33;
    TianKong s34;
    TaiFu s35;
    FengGao s36;
    ZuoFu s37;
    YouBi s38;
    TianXing s39;
    TianYao s40;
    TianMa s41;
    JieShen s42;
    TianWu s43;
    TianYue_2 s44;
    YinSha s45;

    SanTai s46;
    BaZuo s47;
    EnGuang s48;
    TianGui s49;

    LuCun_ s50;
    QingYang s51;
    TuoLuo s52;
    TianKui s53;
    TianYue s54;
    TianGuan s55;
    TianFu_2 s56;

    HuaLu s57;
    HuaQuan s58;
    HuaKe s59;
    HuaJi s60;

    BoShi s61;
    LiShi s62;
    QingLong s63;
    XiaoHao s64;
    JiangJun s65;
    ZouShu s66;
    FeiLian s67;
    XiShen s68;
    BingFu s69;
    DaHao s70;
    FuBing s71;
    GuanFu s72;

    DiKong s73;
    TianKu s74;
    TianXu s75;
    LongChi s76;
    FengGe s77;
    HongLuan s78;
    TianXi s79;
    FeiLian_2 s80;
    PoSui s81;
    GuChen s82;
    GuaSu s83;
    TianCai s84;
    TianShou s85;

    ChangSheng s86;
    MuYu s87;
    GuanDai s88;
    LinGuan s89;
    DiWang s90;
    ShuaiXing s91;
    BingXing s92;
    SiXing s93;
    MuXing s94;
    JueXing s95;
    TaiXing s96;
    YangXing s97;

    StarBase *_stars[100]{&s1,&s2,&s3,&s4,&s5,&s6,&s7,&s8,&s9,&s10,&s11,&s12,&s13,nullptr,&s15,&s16,&s17,&s18,&s19,&s20,&s21,&s22,&s23,&s24,&s25,&s26,&s27,&s28,&s29,&s30,&s31,&s32,&s33,&s34,&s35,&s36,&s37,&s38,&s39,&s40,&s41,&s42,&s43,&s44,&s45,&s46,&s47,&s48,&s49,&s50,&s51,&s52,&s53,&s54,&s55,&s56,&s57,&s58,&s59,&s60,&s61,&s62,&s63,&s64,&s65,&s66,&s67,&s68,&s69,&s70,&s71,&s72,&s73,&s74,&s75,&s76,&s77,&s78,&s79,&s80,&s81,&s82,&s83,&s84,&s85,&s86,&s87,&s88,&s89,&s90,&s91,&s92,&s93,&s94,&s95,&s96,&s97};

public:
    YinYang _yinyang;
    Gender _gender;
    std::string _name;
    std::string _remark;
    Case(unsigned long long BBirthTime = 199002231934, double LLongitude = 120.0, Gender ggender = Gender::Male, std::string nname = "张三", std::string rremark = "无备注");
    void show();
    //复制构造函数
    Case(const Case &c);
};

#endif