#ifndef _OTHERPLAYER_H_
#define _OTHERPLAYER_H_
#include<stdlib.h>
class OtherPlayer{
	float px, py;
	int hp, mp;
	bool attack, jump, run, right, sattack, ated;
	int  atype, atime, atedtime;
	int role;
public:
	void setPoint(float x, float y);
	float getPointX();
	float getPointY();

	void sethp(int i);
	int gethp();

	void setmp(int i);
	int getmp();

	void setattack(bool b);
	bool isattack();

	void setjump(bool b);
	bool isjump();

	void setrun(bool b);
	bool isrun();

	void setright(bool b);
	bool isright();

	void setsattack(bool b);
	bool issattack();

	void setated(bool b);
	bool isated();

	void setatype(int i);
	int getatype();

	void setatime(int i);
	int getatime();

	void setatedtime(int i);
	int getatedtime();

	void setrole(int i);
	int getrole();
};
#endif