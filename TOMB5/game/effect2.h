#pragma once
#include "../global/types.h"

void inject_effect2();

void SoundEffects();
void FireChaff();
void DoSubsuitStuff();

#define TriggerDynamic	( (void(__cdecl*)(long, long, long, int, int, int, int)) 0x00431240 )
#define TriggerDynamic_MIRROR	( (void(__cdecl*)(long, long, long, int, int, int, int)) 0x00431420 )
#define TriggerGunSmoke	( (void(__cdecl*)(long, long, long, long, long, long, int, int, int)) 0x004820A0 )
#define KillEverything	( (void(__cdecl*)()) 0x00431050 )
#define UpdateDebris	( (void(__cdecl*)()) 0x0041D500 )
#define UpdateSparks	( (void(__cdecl*)()) 0x0042E8B0 )
#define UpdateSplashes	( (void(__cdecl*)()) 0x00430710 )
#define TriggerWaterfallMist	( (void(__cdecl*)(long, long, long, long)) 0x00430A40 )
#define TriggerAirBubbles	( (void(__cdecl*)()) 0x0047C4D0 )
#define TriggerEngineEffects	( (void(__cdecl*)()) 0x0047CB70 )
#define TriggerEngineEffects_CUT	( (void(__cdecl*)()) 0x0047D140 )
#define TriggerTorpedoSteam	( (void(__cdecl*)(PHD_VECTOR*, PHD_VECTOR*, int)) 0x0045C5E0 )
#define TriggerFireFlame	( (void(__cdecl*)(int, int, int, int, signed int)) 0x0042FE20 )
#define TriggerFontFire	( (void(__cdecl*)(ITEM_INFO*, int, int)) 0x00477ED0 )
