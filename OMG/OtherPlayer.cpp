#include "stdafx.h"
#include"OtherPlayer.h"
void OtherPlayer::setPoint(float x, float y){ px = x; py = y; }
float OtherPlayer::getPointX(){ return px; }
float OtherPlayer::getPointY(){ return py; }

void OtherPlayer::sethp(int i){ hp = i; }
int OtherPlayer::gethp(){ return hp; }

void OtherPlayer::setmp(int i){ mp = i; }
int OtherPlayer::getmp(){ return mp; }

void OtherPlayer::setattack(bool b){ attack = b; }
bool OtherPlayer::isattack(){ return attack; }

void OtherPlayer::setjump(bool b){ jump = b; }
bool OtherPlayer::isjump(){ return jump; }

void OtherPlayer::setrun(bool b){ run = b; }
bool OtherPlayer::isrun(){ return run; }

void OtherPlayer::setright(bool b){ right = b; }
bool OtherPlayer::isright(){ return right; }

void OtherPlayer::setsattack(bool b){ sattack = b; }
bool OtherPlayer::issattack(){ return sattack; }

void OtherPlayer::setated(bool b){ ated = b; }
bool OtherPlayer::isated(){ return ated; }

void OtherPlayer::setatype(int i){ atype = i; }
int OtherPlayer::getatype(){ return atype; }

void OtherPlayer::setatime(int i){ atime = i; }
int OtherPlayer::getatime(){ return atime; }

void OtherPlayer::setatedtime(int i){ atedtime = i; }
int OtherPlayer::getatedtime(){ return atedtime; }

void OtherPlayer::setrole(int i){ role = i; }
int OtherPlayer::getrole(){ return role; }