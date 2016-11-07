#include "stdafx.h"
#include"SoursePlayer.h"
SoursePlayer::SoursePlayer(){
	right = false;
	run = false;
	jump = false;
	j1 = 0;
	movespeed;
	attack = false;atime = 0;atype = 0;
	atdistance = 80;
	atnumber = 1;
	ated = false;
	atedtime = 0;
	atedtype = 0;
	atedright = false;
	sattack = false;
	ateddistance = 6;
	invincible = false;
	damage = 0;
	role = 10;
	hp = 80; mp = 90;//mp58-90,hp32-80
	dietime = 0;
	killcount = 0; diecount = 0;
	runtime = 0;
	blink = false;
	bx = 0; by = 0;
	px = 0; py = 0;
}
	int SoursePlayer::getruntime(){ return runtime; }
	void SoursePlayer::setruntime(int i){ runtime = i; }
	void SoursePlayer::addruntime(){ runtime++; }
	int SoursePlayer::getkillcount(){ return killcount; }
	void SoursePlayer::addkillcount(){ if (killcount<10)killcount++; }
	void SoursePlayer::adddiecount(){ if (diecount<10)diecount++; }
	int SoursePlayer::getdiecount(){ return diecount; }
	int SoursePlayer::getdietime(){ return dietime; }
	void SoursePlayer::adddietime(){ dietime++; }
	void SoursePlayer::setdietime(int i){ dietime = i; }
	void SoursePlayer::restart(){
		killcount = 0;
		diecount = 0;
	}
	void SoursePlayer::revhp(){
		hp = 80;
		mp = 90;
		atedtime = 0;
		attack = false;
		sattack = false;
		atype = 0;
		run = false;
		jump = false;
		changeatime[0] = -1;
		changeatime[1] = -1;
		atnumber = 1;
		atedtype = 0;
	}
	void SoursePlayer::addmp(){ if (mp + 0.03 <= 90)mp += 0.03; else mp = 90; }
	void SoursePlayer::increasemp(float i){ if (mp + i <= 90)mp += i; else mp = 90; }
	float SoursePlayer::getmp(){ return mp; }
	int SoursePlayer::getdamage(){ return damage; }
	bool SoursePlayer::isinvincible(){ return invincible; }
	void SoursePlayer::setinvincible(bool b){ invincible = b; }
	int SoursePlayer::getateddistance(){ return ateddistance; }
	int SoursePlayer::getrole(){ return role; }
	void SoursePlayer::setmos(int i){ movespeed = i; }
	void SoursePlayer::setatdis(int i){ atdistance = i; }
	void SoursePlayer::setro(int i){ role = i; }
	void SoursePlayer::haha(){
		changeatime[0] = -1;
		changeatime[1] = -1;
	}

	bool SoursePlayer::canuse(int i){
		if (i == 1){
			if (role == 0 && mp < 58 + 22){ return false; }
			else if (role == 1 && mp < 58 + 20){ return false; }
			else if (role == 2 && mp < 58 + 13){ return false; }
			else if (role == 3 && mp < 58 + 15){ return false; }
		}
		else if (i == 2){
			if (role == 0 && mp < 58 + 15){ return false; }
			else if (role == 1 && mp < 58 + 15){ return false; }
			else if (role == 2 && mp < 58 + 16){ return false; }
			else if (role == 3 && mp < 58 + 7){ return false; }
		}
		else if (i == 3){
			if (role == 0 && mp < 58 + 11){ return false; }
			else if (role == 1 && mp < 58 + 15){ return false; }
			else if (role == 2 && mp < 58 + 6){ return false; }
			else if (role == 3 && mp < 58 + 15){ return false; }
		}
		return true;
	}
	//移动
	void SoursePlayer::prun(bool b){
		if (hp > 0 && !sattack && !ated && !attack){
			if (!run&&b){
				run = b;
			}
			else if (run&&!b){
				run = b;
				runtime = -10;
			}
		}
	}
	//转向
	void SoursePlayer::pdirection(){
		if (hp>0 && !sattack && !ated && !attack)
		{
			right = !right;
		}
	}
	//跳跃
	void SoursePlayer::pjump(){
		if (hp>0 && !sattack && !ated && !jump && !attack){
			jump = true;
			j1 = 25;
		}
	}
	//攻击
	void SoursePlayer::pattack(int i){
		if (hp > 0 && !sattack && !ated && !attack && !jump){
			attack = true;
			setAttackAction(i);
		}
	}
	void SoursePlayer::setAttackAction(int i){
		atmovespeed = 8;
		atcounts = i;
		if (role == 0 || role == 1)damage = 2;
		else damage = 1;
		if (i == 1){
			if (role == 0 || role == 1){ aend = 30; amstart = 10; amend = 20; }
			if (role == 2 || role == 3){ aend = 20; amstart = 5; amend = 15; }
		}
		else if (i == 2){
			if (role == 0){ aend = 45; changeatime[0] = 20; amstart = 10; amend = 20; }
			if (role == 1){ aend = 50; changeatime[0] = 20; amstart = 10; amend = 20; }
			if (role == 2){ aend = 45; changeatime[0] = 20; amstart = 5; amend = 15; }
			if (role == 3){ aend = 50; changeatime[0] = 20; amstart = 5; amend = 15; }
		}
		else if (i == 3){
			if (role == 0){ aend = 80; changeatime[0] = 20; changeatime[1] = 35; amstart = 10; amend = 20; }
			if (role == 1){ aend = 70; changeatime[0] = 20; changeatime[1] = 40; amstart = 10; amend = 20; }
			if (role == 2){ aend = 65; changeatime[0] = 20; changeatime[1] = 35; amstart = 5; amend = 15; }
			if (role == 3){ aend = 70; changeatime[0] = 20; changeatime[1] = 45; amstart = 5; amend = 15; }
		}
	}
	//技能1
	void SoursePlayer::s1(){
		if (hp>0 && !ated && !sattack){
			if (!jump){
				int skill = 1;
				if (canuse(skill))
				{
					setatype(skill);
					setsattack(true);
				}
			}
		}
	}
	//技能2
	void SoursePlayer::s2(){
		if (hp>0 && !ated && !sattack){
			if (!jump){
				int skill = 2;
				if (canuse(skill))
				{
					setatype(skill);
					setsattack(true);
				}
			}
		}
	}
	//技能3
	void SoursePlayer::s3(){
		if (hp>0 && !ated && !sattack){
			if (!jump){
				if (role != 2){
					int skill = 3;
					if (canuse(skill))
					{
						setatype(skill);
						if (!(role == 1))
							setsattack(true);
					}
				}
			}
			else if (role == 2 && canuse(3)){ setatype(3); setsattack(true); }
		}
	}
	//死神瞬移位置
	void SoursePlayer::setBlinkPosition(int x, int y){
		bx = x;
		by = y;
	}
	int SoursePlayer::getbx(){ return bx; }
	int SoursePlayer::getby(){ return by; }

	void SoursePlayer::setsattack(bool b){
		sattack = b;
		if (b){
			attack = false;
			run = false;
			jump = false;
			atime = 0;
			changeatime[0] = -1;
			changeatime[1] = -1;
			atnumber = 1;
		}
		else{ atype = 0; invincible = false; }
	}

	void SoursePlayer::setatype(int i){
		atype = i;
		if (i == 1){
			if (role == 0){ damage = 18; mp -= 22; }
			if (role == 1){ damage = 20;  mp -= 20; }
			if (role == 2){ damage = 3;  mp -= 13; }
			if (role == 3){ damage = 1; mp -= 15; }
		}
		else if (i == 2){
			if (role == 0){ damage = 1;  mp -= 15; }
			if (role == 1){ damage = 9;  mp -= 15; }
			if (role == 2){ damage = 16;  mp -= 16; }
			if (role == 3){ damage = 5;  mp -= 7; }
			invincible = true;
		}
		else if (i == 3)
		{
			if (role == 0){ mp -= 11; }
			if (role == 1){ mp -= 15; }
			if (role == 2){ damage = 4; mp -= 6; }
			if (role == 3){ damage = 8; mp -= 15; }
			if (role == 0 || role == 2)invincible = true;
		}
	}

	//获取玩家位置
	float SoursePlayer::getPosiX(){ return px; }
	float SoursePlayer::getPosiY(){ return py; }
	void SoursePlayer::setPosiX(float g){ px = g; }
	void SoursePlayer::setPosiY(float g){ py = g; }

	//是否是攻击状态
	bool SoursePlayer::isattack(){ return attack; }
	void SoursePlayer::addatime(){ atime++; }
	int SoursePlayer::getatime(){ return atime; }
	void SoursePlayer::setatime(int i){ atime = i; }
	//是否是使用技能状态
	bool SoursePlayer::issattack(){ return sattack; }

	int SoursePlayer::getatype(){ return atype; }

	//是否是被攻击状态
	bool SoursePlayer::isated(){ return ated; }
	void SoursePlayer::addatedtime(){ atedtime++; }
	int SoursePlayer::getatedtime(){ return atedtime; }
	void SoursePlayer::setatedtime(int i){ atedtime = i; }
	int SoursePlayer::getatedtype(){ return atedtype; }
	int SoursePlayer::getatnumber(){ return atnumber; }

	//获取基本数据
	float SoursePlayer::gethp(){ return hp; }


	void SoursePlayer::setright(bool b){ right = b; }
	bool SoursePlayer::isright(){ return right; }

	void SoursePlayer::setrun(bool b){ run = b; }
	bool SoursePlayer::isrun(){ return run; }

	void SoursePlayer::setjump(bool b){ jump = b; }
	bool SoursePlayer::isjump(){ return jump; }

	void SoursePlayer::setj1(int i){ j1 = i; }
	int SoursePlayer::getj1(){ return j1; }
	void SoursePlayer::decreaj1(){ j1--; }

	int SoursePlayer::getmovespeed(){ return movespeed; }

	void SoursePlayer::setattack(bool b){
		attack = b;
		if (!b){
			changeatime[0] = -1;
			changeatime[1] = -1;
			atnumber = 1;
		}
	}

	void SoursePlayer::setatdistance(int i){ atdistance = i; }
	int SoursePlayer::getatdistance(){ return atdistance; }

	void SoursePlayer::setaend(int i){ aend = i; }
	int SoursePlayer::getaend(){ return aend; }
	bool SoursePlayer::isaend(){ if (atime == aend)return true; else return false; }

	void SoursePlayer::setattacktime(int i, int j){ atstart = i; atend = j; }
	void SoursePlayer::setattackmovetime(int i, int j){ amstart = i; amend = j; }
	bool SoursePlayer::canattack(){ if (atime >= atstart&&atime <= atend)return true; else return false; }
	bool SoursePlayer::canatmove(){ if (atime >= amstart&&atime <= amend)return true; else return false; }
	int SoursePlayer::getamstart(){ return amstart; }
	void SoursePlayer::setatmovespeed(int i){ atmovespeed = i; }
	int SoursePlayer::getatmovespeed(){ return atmovespeed; }

	bool SoursePlayer::isatedright(){ return atedright; }

	void SoursePlayer::sethp(float h){ hp = h; }
	void SoursePlayer::setmp(float m){ mp = m; }
	void SoursePlayer::setate(bool b){ ated = b; }
	void SoursePlayer::setateddistance(int ateddis){ ateddistance = ateddis; }
	void SoursePlayer::setatdtype(int atdtype){ atedtype = atdtype; }
	void SoursePlayer::setatedright(bool c){ atedright = c; }

	void SoursePlayer::hehe(){
		attack = false;
		sattack = false;
		atype = 0;
		run = false;
		jump = false;
		atime = 0;
		changeatime[0] = -1;
		changeatime[1] = -1;
		atnumber = 1;
	}
	int SoursePlayer::getchangeatime0(){ return changeatime[0]; }
	int SoursePlayer::getchangeatime1(){ return changeatime[1]; }
	void SoursePlayer::setshuxing(int a, int b, int c){ amstart = a; amend = b; damage = c; }
	int SoursePlayer::getatcounts(){ return atcounts; }
	void SoursePlayer::addatnumber(){ atnumber++; }