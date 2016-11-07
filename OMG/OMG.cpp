// OMG.cpp : 定义 DLL 应用程序的导出函数。
//

#include "stdafx.h"
#include "OMG.h"

#include "State.h"	

// 这是导出变量的一个示例
OMG_API int nOMG=0;

// 这是导出函数的一个示例。
OMG_API int fnOMG(void)
{
	return 42;
}
OMG_API int Add(){
	return 120;
}
// 这是已导出类的构造函数。
// 有关类定义的信息，请参阅 OMG.h
COMG::COMG()
{
	return;
}
/************************************************* 自己加的代码 **********************************************************************/
#include <math.h>
struct PlayerState{
	//死神的攻击范围是110px
	const float atRange = 110.0;
	//血量
	float h0 = 0; int h1 = 0; int h2 = 0; int h3 = 0;
	//魔法
	float m0 = 0; int m1 = 0; int m2 = 0; int m3 = 0;
	//距离
	float d1 = 0; float d2 = 0;	float d3 = 0;
	//所在层数
	int floor0 = 1; int floor1 = 1;	int floor2 = 1;	int floor3 = 1;
	//是否一层,0不是，1是
	bool sf1 = 0; bool sf2 = 0;	bool sf3 = 0;
	//玩家是否朝向敌人，朝向为1，背对为0
	bool pface1 = 0; bool pface2 = 0; bool pface3 = 0;
	//是否在攻击范围&视野内
	bool inrange1 = 0; bool inrange2 = 0; bool inrange3 = 0;
	//更新数值
	void update(SoursePlayer &mp,OtherPlayer &mop1,OtherPlayer &mop2,OtherPlayer &mop3)
	{
		d1 = sqrt( pow(mp.getPosiX() - mop1.getPointX(), 2) + pow(mp.getPosiY() - mop1.getPointY(), 2) );
		d2 = sqrt( pow(mp.getPosiX() - mop2.getPointX(), 2) + pow(mp.getPosiY() - mop2.getPointY(), 2) );
		d3 = sqrt( pow(mp.getPosiX() - mop3.getPointX(), 2) + pow(mp.getPosiY() - mop3.getPointY(), 2) );

		h0 = mp.gethp();
		h1 = mop1.gethp();
		h2 = mop2.gethp();
		h3 = mop3.gethp();

		m0 = mp.getmp();
		m1 = mop1.getmp();
		m2 = mop2.getmp();
		m3 = mop3.getmp();

		(mp.getPosiY() >= 120 && mp.getPosiY() < 370) ? (floor0 = 1) :
			(mp.getPosiY() >= 370 && mp.getPosiY() < 600) ? (floor0 = 2) : (floor0 = 3);
		(mop1.getPointY() >= 120 && mop1.getPointY() < 370) ? (floor1 = 1) :
			(mop1.getPointY() >= 370 && mop1.getPointY() < 600) ? (floor1 = 2) : (floor1 = 3);
		(mop2.getPointY() >= 120 && mop2.getPointY() < 370) ? (floor2 = 1) :
			(mop2.getPointY() >= 370 && mop2.getPointY() < 600) ? (floor2 = 2) : (floor2 = 3);
		(mop3.getPointY() >= 120 && mop3.getPointY() < 370) ? (floor3 = 1) :
			(mop3.getPointY() >= 370 && mop3.getPointY() < 600) ? (floor3 = 2) : (floor3 = 3);

		if (floor0 == floor1) sf1 = 1; else sf1 = 0;
		if (floor0 == floor2) sf2 = 1; else sf2 = 0;
		if (floor0 == floor3) sf3 = 1; else sf3 = 0;

		if (mp.getPosiX() <= mop1.getPointX() && mp.isright())
		{
			pface1 = 1;
		}else if (mp.getPosiX() > mop1.getPointX() && !mp.isright())
		{
			pface1 = 1;
		}else{ pface1 = 0; }

		if (mp.getPosiX() <= mop2.getPointX() && mp.isright())
		{
			pface2 = 1;
		}else if (mp.getPosiX() > mop2.getPointX() && !mp.isright())
		{
			pface2 = 1;
		}else{ pface2 = 0; }

		if (mp.getPosiX() <= mop3.getPointX() && mp.isright())
		{
			pface3 = 1;
		}else if (mp.getPosiX() > mop3.getPointX() && !mp.isright())
		{
			pface3 = 1;
		}else{ pface3 = 0; }


	}
};


OMG_API bool playrole(SoursePlayer*p, OtherPlayer*op1, OtherPlayer*op2, OtherPlayer*op3,int*box){
	
	PlayerState mp;
	mp.update(*p, *op1, *op2, *op3);
	if (mp.pface2 == 0)
		p->pdirection();
	if (mp.d2 > 110)
	{
		p->prun(1);
	}
	else
	{
		p->prun(0);
		p->pattack(3);
	}
	
	return true;
}
OMG_API int selectplayer(SoursePlayer*p){

	return 0;
}