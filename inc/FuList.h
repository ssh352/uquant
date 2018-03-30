#ifndef UBEE_FULIST_H
#define UBEE_FULIST_H

#include <map>

namespace uBEE
{

/*
  # cffe  中金所 ----------------------------------------------------------------
  最后交易日    第三个周五  假日顺延 (第三个周，是指有交易的周，如果本月 1 号 是周六，那这一周不算。)
  # shfe  上期所-------------------------------------------------------
  最后交易日   15日    假日顺延 (比如 15日如果是周六，那么17日是当月最后一个交易日，本月结束，18日,下月开始)
  # czce  郑商所 --------------------------------------------------------------
  最后交易日   第10个交易日
  # dce   大商所 --------------------------------------------------------------
  最后交易日   第10个交易日
  # ine   上能所  http://www.ine.cn
  
*/
#define FUTURE_NUMBER    700
#define DCE_NUMBER       220
#define CZCE_NUMBER      220
#define SHFE_NUMBER      220
#define CFFE_NUMBER      30

#define FUTRUE_ID_LEN    31
#define FUTURE_NAME_LEN  3

#define TYPE_CFFE   0
#define TYPE_SHFE   1
#define TYPE_CZCE   2
#define TYPE_DCE    3

#define NON_FIRST_DAY  0
#define FIRST_DAY      1
/*
  下面定义的 FirstDay16[12][4] ;
  是指12个月，每个月的第几号是 新合约开始 （ 因为要换合约 ）
  4 指有4个所，如下：分别是： 中金所， 上期所， 郑商所， 大商所
  --- [0]: CFFE  --- [1]: SHFE  --- [2]: CZCE  --- [3]: DCE  ---
*/
static const int FirstDay16[12][4] {
  {18,18,18,18},  // 1
  {22,16,22,22},  // 2
  {21,16,15,15},  // 3
  {18,18,18,18},  // 4
  {23,17,17,17},  // 5
  {20,16,17,17},  // 6
  {18,18,15,15},  // 7
  {22,16,15,15},  // 8
  {20,20,19,19},  // 9
  {24,18,24,24},  // 10
  {21,16,15,15},  // 11
  {19,16,15,15},  // 12
};

static const int FirstDay17[12][4] {
  {23,17,17,17},  // 1
  {20,16,17,17},  // 2
  {20,16,15,15},  // 3
  {24,18,19,19},  // 4
  {22,16,16,16},  // 5
  {19,16,15,15},  // 6
  {24,18,17,17},  // 7
  {21,16,15,15},  // 8
  {18,18,15,15},  // 9
  {23,17,23,23},  // 10
  {20,16,15,15},  // 11
  {18,18,15,15},  // 12
};

static const int FirstDay18[12][5] {
  {22,16,16,16,0},  // 1
  {23,12,22,22,0},  // 2  cj
  {19,16,15,15,30},  // 3
  {23,17,18,18,30},  // 4
  {21,16,16,16,31},  // 5
  {19,19,15,15,29},  // 6
  {23,17,16,16,31},  // 7
  {20,16,15,15,31},  // 8
  {25,18,17,17,20},  // 9
  {22,16,22,22,31},  // 10
  {19,16,15,15,30},  // 11
  {24,18,17,17,31},  // 12
};

static const int FirstDay19[12][4] {
  {00,00,00,00},  // 1
  {00,00,00,00},  // 2
  {00,20,00,00},  // 3
  {3,00,00,00},  // 4
  {4,00,00,00},  // 5
  {00,00,00,00},  // 6
  {00,00,00,00},  // 7
  {00,00,00,00},  // 8
  {00,00,00,00},  // 9
  {00,00,00,00},  // 10
  {00,00,00,00},  // 11
  {00,00,00,00},  // 12
};

static const int FirstDay20[12][4] {
  {00,16,17,18},  // 1
  {00,00,00,00},  // 2
  {00,20,00,00},  // 3
  {3,00,00,00},  // 4
  {4,00,00,00},  // 5
  {00,00,00,00},  // 6
  {00,00,00,00},  // 7
  {00,00,00,00},  // 8
  {00,00,00,00},  // 9
  {00,00,00,00},  // 10
  {00,00,00,00},  // 11
  {00,00,00,00},  // 12
};

// -- 交易时间类型 -- 有的有夜盘，有的没有夜盘，夜盘的交易时间不一样 --
static const std::map<std::string,int> M_FuTime = {
  //  czce 郑商所 -------801 4位------------
  {"AP",  2 }, // 苹果
  {"CF",  2   }, // 棉花
  {"CY",  2 }, // 棉纱
  {"FG",  2   }, // 玻璃
  {"JR",  0   }, // 粳稻
  {"LR",  0   }, // 晚籼稻
  {"MA",  2   }, // 甲醇N
  {"OI",  2   }, // 菜籽油
  {"PM",  0   }, // 普麦
  {"RI",  0   }, // 早籼稻
  {"RM",  2   }, // 菜籽粕
  {"RS",  0   }, // 油菜籽
  {"SF",  0   }, // 硅铁
  {"SM",  0   }, // 锰硅
  {"SR",  2   }, // 白糖
  {"TA",  2   }, // PTA
  {"WH",  0   }, // 强麦
  {"ZC",  0   }, // 新动力煤
  // {"TC",  2   }, // 动力煤
  // {"ME",  0   }, // 甲醇
  //  dce 大商所 --- 16 --- 20180109 ----------- 1801 4---------------------------------------------
  {"a",  2  },//   豆一
  {"b",  2  },//   豆二
  {"bb", 0  },//   胶合板
  {"c",  0  },//   玉米
  {"cs", 0  },//   玉米淀粉
  {"fb", 0  },//   纤维板
  {"i",  2  },//   铁矿石
  {"j",  2  },//   焦炭
  {"jd", 0  },//   鸡蛋
  {"jm", 2  },//   焦煤
  {"l",  0  },//   聚乙烯
  {"m",  2  },//   豆粕
  {"p",  2  },//   棕榈油
  {"pp", 0  },//   聚丙烯
  {"v",  0  },//   聚氯乙烯
  {"y",  2  },//   豆油
  // shfe  上期所--- 14 --- 20180109 -----------------------
  {"cu", 3 }, //   铜
  {"al", 3 }, //   铝
  {"zn", 3 }, //   锌
  {"pb", 3 }, //   铅
  {"ni", 3 }, //   镍
  {"sn", 3 }, //   锡
  {"au", 4 }, //   黄金
  {"ag", 4 }, //   银
  {"rb", 1 }, //   螺纹钢
  {"wr", 0 }, //   线材
  {"hc", 1 }, //   热轧卷板
  {"fu", 0 }, //   燃料油
  {"bu", 1 }, //   石油沥青
  {"ru", 1 }, //   天然橡胶
  //cffe 中金所 --- 5 --- 20180109 -------------------------
  {"IF",  5 }, // 沪深300
  {"IC",  5 }, // 中证500
  {"IH",  5 }, // 上证50
  {"TF",  6 }, // 国债5年期
  {"T",   6 }, // 国债10年期

};



//  czce 郑商所 -------801 4位------------------------------------------------------
static const std::map<std::string,std::string> M_CZCE = {
  {"AP","{\"N\":7,\"M\":[1,3,5,7,10,11,12]}"},   			//   苹果   2017.12.22    AP1805、AP1807、AP1810、AP1811、AP1812
  {"CF","{\"N\":6,\"M\":[1,3,5,7,9,11]}"},   				//   棉花
  {"CY","{\"N\":12,\"M\":[1,2,3,4,5,6,7,8,9,10,11,12]}"},   //   棉纱
  {"FG","{\"N\":12,\"M\":[1,2,3,4,5,6,7,8,9,10,11,12]}"},   //   玻璃
  {"JR","{\"N\":6,\"M\":[1,3,5,7,9,11]}"},   				//   粳稻
  {"LR","{\"N\":6,\"M\":[1,3,5,7,9,11]}"},   				//   晚籼稻
  {"MA","{\"N\":12,\"M\":[1,2,3,4,5,6,7,8,9,10,11,12]}"},   //   甲醇N
  {"OI","{\"N\":6,\"M\":[1,3,5,7,9,11]}"},   				//   菜籽油
  {"PM","{\"N\":6,\"M\":[1,3,5,7,9,11]}"},   				//   普麦
  {"RI","{\"N\":6,\"M\":[1,3,5,7,9,11]}"},   				//   早籼稻
  {"RM","{\"N\":7,\"M\":[1,3,5,7,8,9,11]}"},   				//   菜籽粕
  {"RS","{\"N\":4,\"M\":[7,8,9,11]}"},   					//   油菜籽
  {"SF","{\"N\":12,\"M\":[1,2,3,4,5,6,7,8,9,10,11,12]}"},   //   硅铁
  {"SM","{\"N\":12,\"M\":[1,2,3,4,5,6,7,8,9,10,11,12]}"},   //   锰硅
  {"SR","{\"N\":6,\"M\":[1,3,5,7,9,11]}"},   				//   白糖
  {"TA","{\"N\":12,\"M\":[1,2,3,4,5,6,7,8,9,10,11,12]}"},   //   PTA
  {"WH","{\"N\":6,\"M\":[1,3,5,7,9,11]}"},   				//   强麦
  {"ZC","{\"N\":12,\"M\":[1,2,3,4,5,6,7,8,9,10,11,12]}"},   //   新动力煤
//  {"TC","{\"N\":8,\"M\":[]}"},   //   # 动力煤  (已退)
//  {"ME","{\"N\":8,\"M\":[]}"}    //   # 甲醇 (已退)
};


//  dce 大商所 --- 16 --- 20180109 ----------- 1801 4---------------------------------------------
static const std::map<std::string,std::string> M_DCE = {
  {"a","{\"N\":9,\"M\":[1,3,5,7,9,11]}"},    				//   豆一
  //{"b","{\"N\":12,\"M\":[1,3,5,7,9,11]}"},    			//   豆二  2018.5之前是 1,3,5,7,9,11
  {"b","{\"N\":12,\"M\":[1,2,3,4,5,6,7,8,9,10,11,12]}"},    //   豆二  2018.5之前是 1,3,5,7,9,11
  {"bb","{\"N\":12,\"M\":[1,2,3,4,5,6,7,8,9,10,11,12]}"},   //   胶合板
  {"c","{\"N\":6,\"M\":[1,3,5,7,9,11]}"},    				//   玉米
  {"cs","{\"N\":6,\"M\":[1,3,5,7,9,11]}"},   				//   玉米淀粉
  {"fb","{\"N\":12,\"M\":[1,2,3,4,5,6,7,8,9,10,11,12]}"},   //   纤维板
  {"i","{\"N\":12,\"M\":[1,2,3,4,5,6,7,8,9,10,11,12]}"},    //   铁矿石
  {"j","{\"N\":12,\"M\":[1,2,3,4,5,6,7,8,9,10,11,12]}"},    //   焦炭
  {"jd","{\"N\":12,\"M\":[1,2,3,4,5,6,7,8,9,10,11,12]}"},   //   鸡蛋
  {"jm","{\"N\":12,\"M\":[1,2,3,4,5,6,7,8,9,10,11,12]}"},   //   焦煤
  {"l","{\"N\":12,\"M\":[1,2,3,4,5,6,7,8,9,10,11,12]}"},    //   聚乙烯
  {"m","{\"N\":8,\"M\":[1,3,5,7,8,9,11,12]}"},    			//   豆粕
  {"p","{\"N\":12,\"M\":[1,2,3,4,5,6,7,8,9,10,11,12]}"},    //   棕榈油
  {"pp","{\"N\":12,\"M\":[1,2,3,4,5,6,7,8,9,10,11,12]}"},   //   聚丙烯
  {"v","{\"N\":12,\"M\":[1,2,3,4,5,6,7,8,9,10,11,12]}"},    //   聚氯乙烯
  {"y","{\"N\":8,\"M\":[1,3,5,7,8,9,11,12]}"},     			//   豆油
};

// shfe  上期所--- 14 --- 20180109 -------------------------------------------------
static const std::map<std::string,std::string> M_SHFE = {
  {"cu","{\"N\":12,\"M\":[1,2,3,4,5,6,7,8,9,10,11,12]}"},    //   铜
  {"al","{\"N\":12,\"M\":[1,2,3,4,5,6,7,8,9,10,11,12]}"},    //   铝
  {"zn","{\"N\":12,\"M\":[1,2,3,4,5,6,7,8,9,10,11,12]}"},    //   锌
  {"pb","{\"N\":12,\"M\":[1,2,3,4,5,6,7,8,9,10,11,12]}"},    //   铅
  {"ni","{\"N\":12,\"M\":[1,2,3,4,5,6,7,8,9,10,11,12]}"},    //   镍
  {"sn","{\"N\":12,\"M\":[1,2,3,4,5,6,7,8,9,10,11,12]}"},    //   锡
  {"au","{\"8\":12,\"M\":[1,2,3]}"},    							 //   黄金  ==> 最近三个连续月份的合约以及最近13个月以内的双月合约
  {"ag","{\"N\":12,\"M\":[1,2,3,4,5,6,7,8,9,10,11,12]}"},    //   银
  {"rb","{\"N\":12,\"M\":[1,2,3,4,5,6,7,8,9,10,11,12]}"},    //   螺纹钢
  {"wr","{\"N\":12,\"M\":[1,2,3,4,5,6,7,8,9,10,11,12]}"},    //   线材
  {"hc","{\"N\":12,\"M\":[1,2,3,4,5,6,7,8,9,10,11,12]}"},    //   热轧卷板
  {"fu","{\"N\":12,\"M\":[1,2,3,4,5,6,7,8,9,10,11,12]}"},    //   燃料油 ==> 1 -12月（春节月份除外） (2016.2 2017.1   2018.2  2019.2 2020.1 )
  {"bu","{\"N\":12,\"M\":[]}"},    							 //   石油沥青   ==> 24个月以内，其中最近1-6个月为连续月份合约，6个月以后为季月合约。
  {"ru","{\"N\":10,\"M\":[1,3,4,5,6,7,8,9,10,11]}"},    	 //   天然橡胶
};

//cffe 中金所 --- 5 --- 20180109 ----------------------------------------------------------
static const std::map<std::string,std::string> M_CFFE = {
  {"IF","{\"N\":4,\"M\":[1,3,5,7,9,11]}"},    //   沪深300   ==> (first 2 mouth, + 3,6,9,12 取前2)
  {"IC","{\"N\":4,\"M\":[1,3,5,7,9,11]}"},    //   中证500   ==> (first 2 mouth, + 3,6,9,12 取前2)
  {"IH","{\"N\":4,\"M\":[1,3,5,7,9,11]}"},    //   上证50    ==> (first 2 mouth, + 3,6,9,12 取前2)
  {"TF","{\"N\":4,\"M\":[1,3,5,7,9,11]}"},    //   国债5年期   ==> (3,6,9,12) first three
  {"T","{\"N\":4,\"M\":[1,3,5,7,9,11]}"},     //   国债10年期  ==> (3,6,9,12) first three
};

//......................................................................................

struct FuList {
  char      Date[9];
  int 		Week;
  int       Year;
  int       Month;
  int       Day;

  char      ca_futures [FUTURE_NUMBER][FUTRUE_ID_LEN];
  char     *pc_futures [FUTURE_NUMBER] ;

  char        CffeList [CFFE_NUMBER][FUTRUE_ID_LEN];
  char      *pCffeList [CFFE_NUMBER ];

  char        ShfeList [SHFE_NUMBER][FUTRUE_ID_LEN];
  char      *pShfeList [SHFE_NUMBER];

  char         DceList [DCE_NUMBER][FUTRUE_ID_LEN];
  char       *pDceList [DCE_NUMBER];

  char        CzceList [CZCE_NUMBER][FUTRUE_ID_LEN];
  char      *pCzceList [CZCE_NUMBER];

public:
  FuList();
  int Init(int y,int m, int d);
private:

  int DateDeal(int y,int m, int d);
  /*
   @ int type:  [1][0]: CFFE  --- [1][1]: SHFE  --- [1][2]: CZCE  --- [1][3]: DCE  ---
   @ return  :  1: >=firstday  0: less than firstday -1: error
  */
  int isFirstDay(int type,int y,int m, int d);
  void CffeListInit();
  //void ShfeListInit();
  //void CzceListInit();
  //void DceListInit();
  void ListInit(int);
  void pListInit();
};

} // namespace
#endif // UBEE_FULIST_H

/*
 CY 棉纱 ？
 金
 燃料油 ==> 1 -12月（春节月份除外）
 石油沥青   ==> 24个月以内，其中最近1-6个月为连续月份合约，6个月以后为季月合约。
*/
