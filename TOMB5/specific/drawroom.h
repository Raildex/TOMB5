#pragma once
#include "../global/vars.h"

void inject_drawroom(bool replace);

void DrawBoundsRectangle(float left, float top, float right, float bottom);
void DrawBoundsRectangleII(float left, float top, float right, float bottom, int rgba);
void DrawClipRectangle(ROOM_INFO* r);
void InsertRoom(ROOM_INFO* r);
void InsertRoomlet(ROOMLET* roomlet);
void RoomTestThing();

#define DrawBuckets	( (void(__cdecl*)()) 0x0049D750 )
#define TriggerFogBulbFX	( (void(__cdecl*)(long, long, long, long, long, long, long, long)) 0x0049AEF0 )
#define aResetFogBulbList	( (void(__cdecl*)()) 0x0049AD70 )
#define aBuildFogBulbList	( (void(__cdecl*)()) 0x0049AFB0 )
#define aBuildFXFogBulbList	( (void(__cdecl*)()) 0x0049B1C0 )
#define CheckBoundsClip	( (long(__cdecl*)(float*)) 0x0049C6B0 )
#define aBuildRoomletLights	( (long(__cdecl*)(ROOMLET*)) 0x0049B390 )
#define aRoomletTransformLight	( (void(__cdecl*)(float*, long, long, long, long)) 0x0049B7B0 )
#define ProcessMeshData	( (void(__cdecl*)(long)) 0x0049A3D0 )
#define InitBuckets	( (void(__cdecl*)()) 0x0049D220 )
