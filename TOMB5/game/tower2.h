#pragma once
#include "../global/vars.h"

void inject_tower2(bool replace);

void ControlGunship(short item_number);
void DrawSteelDoorLensFlare(ITEM_INFO* item);

#define TriggerLiftBrakeSparks	( (void(__cdecl*)(PHD_VECTOR*, short)) 0x00487B60 )
