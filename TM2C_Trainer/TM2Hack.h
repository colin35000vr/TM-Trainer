#pragma once

#include "Globals.h"
#include "cHack.h"
#include "CodeInjection.h"
#include "CodeChange.h"
#include "Nop.h"



struct POSITION
{
	float fPosX;
	float fPosZ;
	float fPosY;
};

class CTM2Hack : public cHack
{
public:
	CTM2Hack(void);
	~CTM2Hack(void);

	virtual void DefineAddresses(void);

	void MeterHack(void);
	void CheckpointHack(void);
	void BoostHack(void);
	void Boost(bool bKeyDown);
	void NoGrasDrive(void);
	void NoPlatformCounterIncrease(void);
	void NoFreeDrive(void);
	void NoGravity(bool playSound);
	void SpeedHandlingHack(double newValue);
	void NoWallFriction(void);
	void UnlockNadeos(void);
	void UnlockTracks(void);
	void TimeFreeze(int iTimeSec, int iTimeCentiSec);

	float GetBoostMulti(void);
	void SetBoostMulti(float fNewMulti);
	int GetBoostDuration(void);
	void SetBoostDuration(int iNewDuration);

	void SwitchNoGravityStatus(void);
	void CheckVersion(void);

	/*
	Settings
	*/
	bool m_bBoostEnabled;
	WORD m_wBoostHotkey;
	float m_fBoostMulti;
	float m_fBoostMultiHack;
	bool m_bUseBoostMultiHack;
	bool m_bNoGravityEnabled;
	WORD m_wNoGravityHotkey;

	/*
	TELEPORT
	*/
	DWORD GetPositionAddress(void);
	void TeleportToPos(int iIndex);
	void SaveCurPos(int iIndex);
	void SaveCurPosToSeries(void);
	void LoadTeleportArray(void);
	void DoCarJump(int iHeight);
	POSITION m_SavedPos[4];
	std::vector<POSITION> m_vecAutoPositions;
};

extern CTM2Hack *g_pTM2Hack;

