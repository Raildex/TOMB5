#pragma once
#include "../global/types.h"

void setXY3(D3DTLVERTEX* v, long x1, long y1, long x2, long y2, long x3, long y3, long z, short* clip);
void setXY4(D3DTLVERTEX* v, long x1, long y1, long x2, long y2, long x3, long y3, long x4, long y4, long z, short* clip);
void aSetXY4(D3DTLVERTEX* v, float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4, float z, short* clip);
void setXYZ3(D3DTLVERTEX* v, long x1, long y1, long z1, long x2, long y2, long z2, long x3, long y3, long z3, short* clip);
void setXYZ4(D3DTLVERTEX* v, long x1, long y1, long z1, long x2, long y2, long z2, long x3, long y3, long z3, long x4, long y4, long z4, short* clip);
void ClipCheckPoint(D3DTLVERTEX* v, float x, float y, float z, short* clip);
void aTransformPerspSV(SVECTOR* vec, D3DTLVERTEX* v, short* c, long nVtx, long col);
void AddPolyLine(D3DTLVERTEX* vtx, TEXTURESTRUCT* tex);
bool ClipLine(long& x1, long& y1, long z1, long& x2, long& y2, long z2, long xMin, long yMin, long w, long h);
void aInitFX();
void ClearFX();
void InitTarget();
void InitBinoculars();
void OutputSky();
void SuperShowLogo();
void SetFade(long start, long end);
void DoScreenFade();
void DoWeather();
void DoRain();
void DoSnow();
void DrawBinoculars();
void S_DrawSparks();
void S_DrawDrawSparksNEW(SPARKS* sptr, long smallest_size, float* xyz);
void S_DrawFireSparks(long size, long life);
void S_DrawSmokeSparks();
void DrawPsxTile(long x_y, long height_width, long color, long u0, long u1);
void DrawFlash();
void DrawDebris();
void DrawBlood();
void DrawDrips();
void DoUwEffect();
void DrawBubbles();
void DrawShockwaves();
void DrawLightning();
void S_DrawSplashes();
void DrawRope(ROPE_STRUCT* rope);
void DrawTwogunLaser(TWOGUN_INFO* info);
void DrawLasers(ITEM_INFO* item);
void DrawSteamLasers(ITEM_INFO* item);
void S_DrawFloorLasers(ITEM_INFO* item);
void DrawGasCloud(ITEM_INFO* item);
void S_DrawDarts(ITEM_INFO* item);
void DrawLaserSightSprite();
void DrawMoon();
void DrawStars();
void DrawFlatSky(ulong color, long zpos, long ypos, long drawtype);
void aDrawWreckingBall(ITEM_INFO* item, long shade);
void S_PrintShadow(short size, short* box, ITEM_INFO* item);

extern long DoFade;
extern long snow_outside;
