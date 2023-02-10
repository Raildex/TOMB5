#pragma once
#include "types.h"
#include "math_tbls.h"

// Variable macros
#define VAR_(address, type)			(*(type*)(address)) // uninitialized variable
#define ARRAY_(address, type, length)	(*(type(*)length)(address)) // array (can be multidimensional)

//vars
#define input VAR_(0x00878D98, long)
#define dbinput   VAR_(0x00878DAC, long)
#define lara_coll   VAR_(0x00508778, COLL_INFO*)
#define mycoll	VAR_(0x00E5BC20, COLL_INFO)
#define lara    VAR_(0x00E5BD60, LARA_INFO)
#define lara_item    VAR_(0x00E5BF08, ITEM_INFO*)
#define DashTimer VAR_(0x00E5BF04, ushort)
#define anims	VAR_(0x00875158, ANIM_STRUCT*)
#define items	VAR_(0x00EEEFF0, ITEM_INFO*)
#define effects	VAR_(0x00E5C5E0, FX_INFO*)
#define room	VAR_(0x00875154, ROOM_INFO*)
#define	meshes	VAR_(0x00875170, short**)
#define bones	VAR_(0x00875178, long*)
#define height_type VAR_(0x00EEEFF4, long)
#define trigger_index VAR_(0x00EEEF9C, short*)
#define GLOBAL_cutseq_frame VAR_(0x00E7F024, long)
#define old_lara_holster VAR_(0x00E7EFE0, ushort)
#define gfCurrentLevel VAR_(0x00E5C2D0, uchar)
#define gfLevelComplete VAR_(0x00E5C2F0, uchar)
#define gfLevelFlags	VAR_(0x00E5C2A0, short)
#define gfGameMode	VAR_(0x005082C0, uchar)
#define cutseq_num	VAR_(0x0051CAA8, long)
#define cutseq_trig	VAR_(0x0051CAAC, long)
#define cutseq_busy_timeout	VAR_(0x0051CAB4, char)
#define bTrackCamInit	VAR_(0x0051D010, long)
#define bUseSpotCam	VAR_(0x0051D018, long)
#define SetDebounce	VAR_(0x00EEEA38, long)
#define framecount	VAR_(0x0051CA78, long)
#define GlobalCounter	VAR_(0x0051CA58, ushort)
#define cdtrack	VAR_(0x00506C64, short)
#define bDisableLaraControl	VAR_(0x0051D01C, long)
#define GLOBAL_enterinventory	VAR_(0x00508E18, long)
#define GLOBAL_playing_cutseq	VAR_(0x0051CAB0, long)
#define GLOBAL_inventoryitemchosen	VAR_(0x00508E1C, long)
#define reset_flag	VAR_(0x0051CA6C, long)
#define FadeScreenHeight	VAR_(0x0051D074, short)
#define SniperCamActive	VAR_(0x0051CA1D, char)
#define BinocularRange	VAR_(0x0051CA30, long)
#define BinocularOn	VAR_(0x0051CA34, long)
#define BinocularOldCamera	VAR_(0x0051CA38, camera_type)
#define LaserSight	VAR_(0x0051CA3C, long)
#define InfraRed	VAR_(0x0051CA40, long)
#define inputBusy	VAR_(0x00878C94, long)
#define GotLaraSpheres	VAR_(0x00E51F2E, char)
#define InItemControlLoop	VAR_(0x0051CA53, uchar)
#define next_item_active	VAR_(0x00E5BF22, short)
#define next_item_free	VAR_(0x00E5BF16, short)
#define next_fx_active	VAR_(0x00E5C5FC, short)
#define next_fx_free	VAR_(0x00E5C5F4, short)
#define KillEverythingFlag	VAR_(0x0051CDF4, long)
#define SmokeCountL	VAR_(0x00E6C9E8, long)
#define SmokeCountR	VAR_(0x00E6C9EC, long)
#define SplashCount	VAR_(0x0051CDF8, long)
#define splash_setup	VAR_(0x00E6CAC0, SPLASH_SETUP)
#define WeaponDelay	VAR_(0x0051CA52, uchar)
#define wibble	VAR_(0x0051CDF0, long)
#define XSoff1	VAR_(0x0055D200, short)
#define XSoff2	VAR_(0x0055D1FC, short)
#define YSoff1	VAR_(0x0055D210, short)
#define YSoff2	VAR_(0x0055D214, short)
#define	ZSoff1	VAR_(0x0055D244, short)
#define ZSoff2	VAR_(0x0055D248, short)
#define PoisonFlag	VAR_(0x00E5BF3E, char)
#define LaraDrawType	VAR_(0x00EEEAD0, char)
#define WeatherType	VAR_(0x00EEF4A0, char)
#define CamRot	VAR_(0x00E4B0E0, SVECTOR)
#define SmashedMeshCount	VAR_(0x0051CA5C, short)
#define health_bar_timer	VAR_(0x0051CEA8, long)
#define GameTimer	VAR_(0x00E5C27C, ulong)
#define Gameflow	VAR_(0x00E5C2BC, GAMEFLOW*)
#define camera	VAR_(0x00EEF940, CAMERA_INFO)
#define CamOldPos	VAR_(0x00EEFB00, PHD_VECTOR)
#define savegame	VAR_(0x00E52EC0, SAVEGAME_INFO)
#define NumRPickups	VAR_(0x00E5970C, uchar)
#define AnimatingWaterfallsVOffset	VAR_(0x0051CF54, long)
#define next_blood	VAR_(0x0051D088, long)
#define floor_data	VAR_(0x00875168, short*)
#define rand_1	VAR_(0x00516A38, long)
#define	rand_2	VAR_(0x00516A3C, long)
#define	last_target	VAR_(0x00EEFA30, GAME_VECTOR)
#define	last_ideal	VAR_(0x00EEFA40, GAME_VECTOR)
#define UseForcedFixedCamera	VAR_(0x00EEFA50, char)
#define	cheat_hit_points	VAR_(0x00E5BBF8, short)
#define	gfNumPickups	VAR_(0x0051CE38, uchar)
#define gfNumTakeaways	VAR_(0x0051CE39, uchar)
#define	disable_horizon	VAR_(0x0051CAA4, uchar)
#define	level_items	VAR_(0x0051CEB8, long)
#define	cutseq_num	VAR_(0x0051CAA8, long)
#define	cutseq_trig	VAR_(0x0051CAAC, long)
#define	numnailed	VAR_(0x00E6E4E4, long)
#define	GLOBAL_cutme	VAR_(0x00E711B0, NEW_CUTSCENE*)
#define	dels_cutseq_player	VAR_(0x0051CE2C, ushort)
#define	GLOBAL_oldcamtype	VAR_(0x00E711AC, camera_type)
#define	CurrentAtmosphere	VAR_(0x00EEEB90, uchar)
#define	IsAtmospherePlaying	VAR_(0x00EEEFFC, uchar)
#define gfRequiredStartPos	VAR_(0x00E5C2B4, uchar)
#define	ScreenFade	VAR_(0x0051D068, short)
#define	dScreenFade	VAR_(0x0051D06A, short)
#define	ScreenFadeBack	VAR_(0x0051D06C, short)
#define ScreenFadeSpeed	VAR_(0x0050A178, short)
#define	ScreenFadedOut	VAR_(0x0051D06E, short)
#define ScreenFading	VAR_(0x0051D070, short)
#define	cut_seethrough	VAR_(0x00506D9C, long)
#define	cutrot	VAR_(0x0051CAA0, long)
#define bDoCredits	VAR_(0x0051CE35, uchar)
#define num_fmvs	VAR_(0x0051CE25, char)
#define gfScriptWad	VAR_(0x0051CE20, uchar*)
#define	gfStringWad	VAR_(0x00E5C310, char*)
#define	gfFilenameWad	VAR_(0x00E5C2CC, char*)
#define gfFilenameOffset	VAR_(0x00E5C34C, ushort*)
#define gfExtensions	VAR_(0x0051CE14, char*)
#define gfScriptOffset	VAR_(0x0051CE10, ushort*)
#define gfScriptFile	VAR_(0x00E5C2EC, uchar*)
#define gfLanguageFile	VAR_(0x00E5C2AC, uchar*)
#define gfStringOffset	VAR_(0x00E5C2B8, ushort*)
#define gfStatus	VAR_(0x00E5C2B0, long)
#define gfLegend	VAR_(0x00E5C348, uchar)
#define gfLegendTime	VAR_(0x0051CE34, uchar)
#define gfUVRotate	VAR_(0x00E5C349, char)
#define gfNumMips	VAR_(0x0051CE37, uchar)
#define gfMirrorRoom	VAR_(0x00E5C24C, uchar)
#define gfMirrorZPlane	VAR_(0x00E6D748, long)
#define gfInitialiseGame	VAR_(0x005082C1, uchar)	
#define	gfLayer1Col	VAR_(0x00E5C2A4, CVECTOR)
#define gfLayer2Col	VAR_(0x00E5C280, CVECTOR)
#define	gfLayer1Vel	VAR_(0x00E5C276, char)
#define	gfLayer2Vel	VAR_(0x00E5C275, char)	
#define gfLensFlare	VAR_(0x00E5C2E0, PHD_VECTOR)
#define gfLensFlareColour	VAR_(0x00E5C2F4, CVECTOR)
#define gfResetHubDest	VAR_(0x00E5C2C8, uchar)
#define gfCutNumber	VAR_(0x0051CE36, uchar)
#define	changes	VAR_(0x0087515C, CHANGE_STRUCT*)
#define ranges	VAR_(0x00875160, RANGE_STRUCT*)
#define commands	VAR_(0x0087517C, short*)
#define	FXType	VAR_(0x00EEF900, short)
#define flipeffect	VAR_(0x00506C60, long)
#define	KeyTriggerActive	VAR_(0x0051CA56, uchar)
#define TriggerTimer	VAR_(0x0051CA5A, char)
#define OnObject	VAR_(0x00EEEAC8, long)
#define FootPrintNum	VAR_(0x00E5C350, long)
#define	number_dynamics	VAR_(0x00E6D82C, long)
#define	tiltyoff	VAR_(0x00EEEADC, long)
#define	tiltxoff	VAR_(0x00EEEAD4, long)
#define	baddie_slots	VAR_(0x00E5B834, CREATURE_INFO*)
#define stats_mode	VAR_(0x0051CF26, short)
#define go_select	VAR_(0x00E59E2A, uchar)
#define	go_deselect	VAR_(0x00E5992C, uchar)
#define go_right	VAR_(0x00E5989C, uchar)
#define	go_left	VAR_(0x00E59899, uchar)
#define go_up	VAR_(0x00E59922, uchar)
#define go_down	VAR_(0x00E59929, uchar)
#define keypadx	VAR_(0x0051CF30, uchar)
#define keypady	VAR_(0x0051CF31, uchar)
#define keypadnuminputs	VAR_(0x0051CF32, uchar)
#define keypadpause	VAR_(0x0051CF33, uchar)
#define GnFrameCounter	VAR_(0x00E4B0FC, ulong)
#define use_the_bitch	VAR_(0x00E59921, char)	
#define menu_active	VAR_(0x00E5989A, char)
#define inventry_xpos	VAR_(0x0051CF34, short)
#define inventry_ypos	VAR_(0x0051CF36, short)
#define SmokeWeapon	VAR_(0x00E6CAA0, long)
#define HKTimer	VAR_(0x0051CEC9, char)
#define HKShotsFired	VAR_(0x0051CEC8, char)
#define joy_fire	VAR_(0x00878D9C, long)
#define joystick_read	VAR_(0x0086BA34, long)
#define joystick_read_x	VAR_(0x0086BA3C, long)
#define joystick_read_y	VAR_(0x0086BA40, long)
#define joystick_read_fire	VAR_(0x0086BA44, long)
#define KeyCount	VAR_(0x0086BA48, long)
#define XATrack	VAR_(0x00510B14, long)
#define old_MusicVolume	VAR_(0x00E4B0EC, long)	//no one writes to it, CalculateCamera reads it, useless
#define TargetSnaps	VAR_(0x0051CA2D, char)
#define SniperCount	VAR_(0x0051CA1C, char)
#define TLFlag	VAR_(0x0051CA44, char)
#define SniperOverlay	VAR_(0x0051D022, char)
#define sound_effects	VAR_(0x00E5C5F8, OBJECT_VECTOR*)
#define number_sound_effects	VAR_(0x00E5C5F0, long)
#define sound_active	VAR_(0x0051D004, long)
#define sample_infos	VAR_(0x00E528A8, SAMPLE_INFO*)
#define _wf	VAR_(0x005078F0, long)
#define sample_lut	VAR_(0x00E528A4, short*)
#define examine_mode	VAR_(0x0051CF24, short)
#define boxes	VAR_(0x00EEFB64, BOX_INFO*)
#define SubHitCount	VAR_(0x0051CEE4, char)
#define subsuit	VAR_(0x00E5B850, SUBSUIT_INFO)
#define OldPickupPos	VAR_(0x00E59700, PHD_VECTOR)
#define CurrentSequence	VAR_(0x00E4EA61, uchar)
#define FlashFadeR	VAR_(0x0051D07A, short)
#define FlashFadeG	VAR_(0x0051D07C, short)
#define FlashFadeB	VAR_(0x0051D07E, short)
#define FlashFader	VAR_(0x0051D080, short)
#define PickupX	VAR_(0x00E5BF38, short)
#define PickupY	VAR_(0x00E5BF26, short)
#define PickupVel	VAR_(0x00E5BF3A, short)
#define CurrentPickup	VAR_(0x00E5BF3C, short)
#define Chris_Menu	VAR_(0x0051CE2E, char)
#define title_controls_locked_out	VAR_(0x00E5C2A8, char)
#define jobyfrigger	VAR_(0x0051CA9C, char)
#define CurrentPistolsAmmoType	VAR_(0x0051CF06, char)
#define CurrentUziAmmoType	VAR_(0x0051CF11, char)
#define CurrentRevolverAmmoType	VAR_(0x0051CF0A, char)
#define CurrentShotGunAmmoType	VAR_(0x0051CF0B, char)
#define CurrentGrenadeGunAmmoType	VAR_(0x0051CF00, char)
#define CurrentCrossBowAmmoType	VAR_(0x0051CF1C, char)
#define AmountPistolsAmmo	VAR_(0x0051CF16, short)
#define AmountRevolverAmmo	VAR_(0x0051CF14, short)
#define AmountHKAmmo1	VAR_(0x0051CF08, short)
#define AmountCrossBowAmmo1	VAR_(0x0051CF0E, short)
#define AmountCrossBowAmmo2	VAR_(0x0051CF0C, short)
#define AmountShotGunAmmo1	VAR_(0x0051CF04, short)
#define AmountShotGunAmmo2	VAR_(0x0051CF02, short)
#define AmountUziAmmo	VAR_(0x0051CF1A, short)
#define current_selected_option	VAR_(0x00E598F9, char)
#define ammo_active	VAR_(0x00E5991F, char)
#define right_repeat	VAR_(0x00E59915, uchar)
#define right_debounce	VAR_(0x00E59914, uchar)
#define left_repeat	VAR_(0x00E59E29, uchar)
#define left_debounce	VAR_(0x00E5989B, uchar)
#define	ammo_selector_fade_dir	VAR_(0x00E59926, short)
#define	ammo_selector_fade_val	VAR_(0x00E5990A, short)
#define	ammo_selector_flag	VAR_(0x00E59928, char)
#define num_ammo_slots	VAR_(0x00E598A4, char)
#define current_ammo_type	VAR_(0x00E59918, char*)
#define OBJLIST_SPACING	VAR_(0x00E59894, long)
#define combine_ring_fade_dir	VAR_(0x00E5991C, short)
#define	combine_obj1	VAR_(0x00E59912, short)
#define	combine_obj2	VAR_(0x00E59910, short)
#define	combine_ring_fade_val	VAR_(0x00E598F6, short)
#define	combine_type_flag	VAR_(0x00E59E28, short)
#define seperate_type_flag	VAR_(0x00E598F8, short)
#define loading_or_saving	VAR_(0x00E5989D, char)
#define normal_ring_fade_dir	VAR_(0x00E59924, short)
#define normal_ring_fade_val	VAR_(0x00E59908, short)
#define StashedCurrentPistolsAmmoType	VAR_(0x0051CF12, char)
#define StashedCurrentUziAmmoType	VAR_(0x0051CF01, char)
#define StashedCurrentRevolverAmmoType	VAR_(0x0051CF1D, char)
#define StashedCurrentShotGunAmmoType	VAR_(0x0051CF18, char)
#define StashedCurrentGrenadeGunAmmoType	VAR_(0x0051CF10, char)
#define StashedCurrentCrossBowAmmoType	VAR_(0x0051CF13, char)
#define Stashedcurrent_selected_option	VAR_(0x00E5992B, char)
#define	GLOBAL_invkeypadmode	VAR_(0x0051CF28, long)
#define up_debounce	VAR_(0x00E5992A, uchar)
#define down_debounce	VAR_(0x00E598D8, uchar)
#define GLOBAL_lastinvitem	VAR_(0x00508E14, long)
#define select_debounce	VAR_(0x00E59920, uchar)
#define deselect_debounce	VAR_(0x00E598F2, uchar)
#define friggrimmer	VAR_(0x00E598F4, char)
#define friggrimmer2	VAR_(0x00E598F3, char)
#define oldLaraBusy	VAR_(0x00E59898, char)
#define GLOBAL_numcutseq_frames	VAR_(0x00E7F020, long)
#define camera_pnodes	VAR_(0x00E7EE9C, PACKNODE*)
#define GLaraShadowframe	VAR_(0x00E86300, short*)
#define malloc_buffer	VAR_(0x00E4B10C, char*)
#define malloc_ptr	VAR_(0x00E4B0DC, char*)
#define malloc_size	VAR_(0x00E4B058, long)
#define malloc_used	VAR_(0x00E4B0F0, long)
#define malloc_free	VAR_(0x00E4B0F4, long)
#define ShatterItem	VAR_(0x00EEFAE0, SHATTER_ITEM)
#define GLOBAL_invkeypadcombination	VAR_(0x0051CF2C, long)
#define DestFadeScreenHeight	VAR_(0x0051D076, short)
#define dels_cutseq_selector_flag	VAR_(0x0051CE2A, short)
#define pcring1	VAR_(0x00E59BC0, RINGME)
#define pcring2	VAR_(0x00E59940, RINGME)
#define InventoryActive	VAR_(0x0051CF20, long)
#define xoffset	VAR_(0x00E598A0, long)
#define yoffset	VAR_(0x00E5990C, long)
#define pcbright	VAR_(0x00508E10, long)
#define gfFog	VAR_(0x0051CE30, CVECTOR)
#define GlobalFogOff	VAR_(0x0051CE04, long)
#define LiftDoor	VAR_(0x0051CB40, char)
#define GlobalSoftReset	VAR_(0x00E5C2F8, long)
#define GlobalAlpha	VAR_(0x00506D3C, long)
#define current_item	VAR_(0x009158A8, ITEM_INFO*)
#define aGlobalSkinMesh	VAR_(0x00921680, long)
#define GLOBAL_gunflash_meshptr	VAR_(0x00E6D750, short*)
/*************************************************/
#define phd_top	VAR_(0x0051D0A8, long)
#define phd_bottom	VAR_(0x0055D204, long)
#define phd_left	VAR_(0x0055D20C, long)
#define phd_right	VAR_(0x0055DA3C, long)
#define	phd_winxmax	VAR_(0x0055D218, short)
#define	phd_winxmin	VAR_(0x0055D234, short)
#define	phd_winymax	VAR_(0x0055D240, short)
#define	phd_winymin	VAR_(0x0055D1E8, short)
#define phd_znear	VAR_(0x0055D21C, long)
#define phd_zfar	VAR_(0x0055D1F4, long)
#define phd_mxptr	VAR_(0x00E4B0F8, long*)
#define aMXPtr	VAR_(0x0055DA2C, float*)
#define IM_rate	VAR_(0x00E6E464, long)
#define IM_frac	VAR_(0x00E6D734, long)
#define IMptr	VAR_(0x00E6E468, long*)
#define aIMXPtr	VAR_(0x00E6D834, float*)
#define aIFMStack	ARRAY_(0x00E6D860, float, [768])
#define	IMstack	ARRAY_(0x00E6CB00, long, [768])
#define aFMatrixStack	ARRAY_(0x0055D2A0, float, [indices_count * 20])
#define matrix_stack	ARRAY_(0x0055D66C, long, [indices_count * 20])
#define f_mpersp	VAR_(0x0051D15C, float)
#define f_mznear	VAR_(0x0051D158, float)
#define	f_znear	VAR_(0x0055D24C, float)
#define	f_mzfar	VAR_(0x0055DA38, float)
#define f_moneopersp	VAR_(0x0055D254, float)
#define	f_oneopersp	VAR_(0x0055D1F8, float)
#define phd_centery	VAR_(0x0055D1B4, long)
#define	phd_centerx	VAR_(0x0055D1B0, long)
#define font_height	VAR_(0x00E4DEA8, long)
#define	small_font	VAR_(0x00E4DEAC, long)
#define	CurrentFov	VAR_(0x00E4F504, short)
#define	phd_winheight	VAR_(0x0055D164, long)
#define	phd_winwidth	VAR_(0x0055D29C, long)
#define	f_persp	VAR_(0x0055D268, float)
#define	f_perspoznear	VAR_(0x0055D238, float)
#define	mone	VAR_(0x0050A444, float)
#define one	VAR_(0x0050A440, float)
#define	phd_persp	VAR_(0x0055D208, long)
#define	LfAspectCorrection	VAR_(0x0055DA30, float)
#define	f_mperspoznear	VAR_(0x0055D668, float)
#define D3DMView	VAR_(0x00D9AD50, D3DMATRIX)
#define clip_left	VAR_(0x007EE0CC, float)
#define clip_right	VAR_(0x007ED698, float)
#define clip_top	VAR_(0x007EE0B0, float)
#define clip_bottom	VAR_(0x007E8EF0, float)
#define f_left	VAR_(0x0055D250, float)
#define f_right	VAR_(0x0051D160, float)
#define f_top	VAR_(0x0055D664, float)
#define f_bottom	VAR_(0x0055DA34, float)
#define f_centerx	VAR_(0x0055D22C, float)
#define f_centery	VAR_(0x0055D230, float)
#define f_a	VAR_(0x0051D150, float)
#define f_b	VAR_(0x0051D154, float)
#define f_boo	VAR_(0x0055D220, float)
#define f_moneoznear	VAR_(0x0055D25C, float)
/*************************************************/
#define IsRoomOutsideNo	VAR_(0x00EEF902, short)
#define OutsideRoomTable	VAR_(0x00EEF4AC, char*)
#define OutsideRoomOffsets	VAR_(0x00EEF040, short*)
#define _CutSceneTriggered1	VAR_(0x00EEF004, ulong)
#define _CutSceneTriggered2	VAR_(0x00EEF000, ulong)
#define richcutfrigflag	VAR_(0x0051CA5E, char)
#define number_los_rooms VAR_(0x0051CA70, long)
#define LaserSightActive VAR_(0x0051D072, char)
#define LaserSightY VAR_(0x00E4C9A0, long)
#define LaserSightZ VAR_(0x00E4C9A4, long)
#define LaserSightX VAR_(0x00E4C9A8, long)
#define LaserSightCol VAR_(0x0051D073, char)
#define GetLaraOnLOS VAR_(0x0051CA64, char)
#define ClosestDist VAR_(0x00EEF4A4, long)
#define ClosestCoord VAR_(0x00EEF460, PHD_VECTOR)
#define ClosestItem VAR_(0x00EEEFF8, long)
#define nRope VAR_(0x0051CA60, long)
#define CurrentPendulum VAR_(0x00EEF020, PENDULUM)
#define NullPendulum VAR_(0x0051CFD0, PENDULUM)
#define CamPos	VAR_(0x00E4B0D0, PHD_VECTOR)
#define bLaraUnderWater	VAR_(0x0057A150, long)
#define bLaraSkinBits	VAR_(0x0057A458, long)
#define aMappedNormals	VAR_(0x0057A45C, LPD3DVECTOR)
#define bLaraInWater	VAR_(0x0057A468, char)
#define SmokeWindZ	VAR_(0x00E6C9E4, long)
#define SmokeWindX	VAR_(0x00E6C9E0, long)
#define hair_wind	VAR_(0x0051CEA4, long)
#define hair_dwind_angle	VAR_(0x005084D4, long)
#define hair_wind_angle	VAR_(0x005084D0, long)
#define lGlobalMeshPos	VAR_(0x0091F3B8, FVECTOR)
#define GlobalAmbient	VAR_(0x0092167C, long)
#define dbm_command	VAR_(0x00E4ACB4, ulong)
#define dbm_clearlog	VAR_(0x00E4ACAC, ulong)
#define aAmbientR	VAR_(0x0087AD0C, long)
#define aAmbientG	VAR_(0x0087AD08, long)
#define aAmbientB	VAR_(0x0087AD04, long)
#define textinfo	VAR_(0x008751B0, TEXTURESTRUCT*)
#define nTextures	VAR_(0x00D9A868, long)
#define GLOBAL_resident_depack_buffers	VAR_(0x00E7EFDC, char*)
#define lastcamnum	VAR_(0x00E711A8, long)
#define next_fire_spark	VAR_(0x0050A17C, long)
#define next_smoke_spark	VAR_(0x0051D084, long)
#define next_gunshell	VAR_(0x0051D08C, long)
#define next_bubble	VAR_(0x0051D090, long)
#define next_drip	VAR_(0x0051D094, long)
#define next_debris	VAR_(0x0051CA8C, long)
#define WB_room	VAR_(0x00EEF044, short)
#define GlobalPulleyFrigItem	VAR_(0x00E5BF24, short)
#define globoncuttrig	VAR_(0x00EEEFA0, char)
#define HeavyTriggered	VAR_(0x00EEEA34, uchar)
#define LastSequence	VAR_(0x00E51F2C, short)
#define fliptimer	VAR_(0x0051CA68, long)
#define FileData	VAR_(0x00874964, char*)
#define textinfo	VAR_(0x008751B0, TEXTURESTRUCT*)
#define MaxRoomLights	VAR_(0x0087B0EC, long)
#define LevelFogBulbCnt	VAR_(0x007E7FE8, long)
#define number_rooms	VAR_(0x0087514C, short)
#define cd_drive	VAR_(0x00874960, char)
#define SubsuitAir	VAR_(0x0051CEE0, short)
#define WB_item VAR_(0x00EEEACC, ITEM_INFO*)
#define wbx VAR_(0x0051CEBC, short)
#define wbz VAR_(0x0051CEBE, short)
#define ItemNewRoomNo	VAR_(0x0051CA54, short)
#define spriteinfo	VAR_(0x008751B4, SPRITESTRUCT*)
#define clipflags	VAR_(0x00D9AB34, short*)
#define Rats	VAR_(0x00EEEFEC, RAT_STRUCT*)
#define Bats	VAR_(0x00EEEFE8, BAT_STRUCT*)
#define next_rat	VAR_(0x0051CF94, long)
#define next_bat	VAR_(0x0051CA18, long)
#define outside	VAR_(0x00E6CAF8, long)
#define LightningCount	VAR_(0x00E6D74C, short)
#define LightningRand	VAR_(0x00E6D73C, short)
#define dLightningRand	VAR_(0x00E6E4DC, short)
#define LightningSFXDelay	VAR_(0x0051CC5C, short)
#define nPolyType	VAR_(0x00E4B100, long)
#define SkyPos	VAR_(0x00E6E4B0, short)
#define SkyPos2	VAR_(0x00E6D73E, short)
#define torchroom	VAR_(0x00507AB0, short)
#define ForcedFixedCamera	VAR_(0x00EEFA20, GAME_VECTOR)
#define old_cam	VAR_(0x00EEFA60, OLD_CAMERA)
#define camerasnaps	VAR_(0x0051CA2C, uchar)
/***********************/
//Spotcams
#define number_spotcams	VAR_(0x00E4F428, short)
#define CameraFade	VAR_(0x00E4F36C, long)
#define LastFov	VAR_(0x00E4F506, short)
#define spotcam_timer	VAR_(0x0051D00C, short)
#define spotcam_loopcnt	VAR_(0x00E4F488, short)
#define LaraHealth	VAR_(0x00E51F20, long)
#define LaraAir	VAR_(0x00E4F6A8, long)
#define InitialCameraPosition	VAR_(0x00E4F3D0, PHD_VECTOR)
#define InitialCameraTarget	VAR_(0x00E4F350, PHD_VECTOR)
#define LaraFixedPosition	VAR_(0x00E4F360, PHD_VECTOR)
#define InitialCameraRoom	VAR_(0x00E4F588, short)
#define current_sequence	VAR_(0x00E4F502, short)
#define current_spline_camera	VAR_(0x00E4F500, short)
#define first_camera	VAR_(0x00E51F24, short)
#define last_camera	VAR_(0x00E4F6AC, short)
#define current_camera_cnt	VAR_(0x00E4EAA0, short)
#define current_spline_position	VAR_(0x00E51F28, long)
#define spline_to_camera	VAR_(0x00E4F48C, long)
#define spline_from_camera	VAR_(0x00E4F3DC, long)
#define bCheckTrigger	VAR_(0x0051D014, long)
#define SlowMotion	VAR_(0x0051CA50, short)
#define SCOverlay	VAR_(0x0051D020, char)
#define SCNoDrawLara	VAR_(0x0051D021, char)
#define quakecam	VAR_(0x00E4F520, QUAKE_CAM)

#define SpotCam	ARRAY_(0x00E4F6C0, SPOTCAM, [256])
#define CameraCnt	ARRAY_(0x00E51F10, uchar, [16])
#define SpotRemap	ARRAY_(0x00E4F4F0, uchar, [16])
#define camera_xposition	ARRAY_(0x00E4F440, long, [18])
#define camera_yposition	ARRAY_(0x00E4F600, long, [18])
#define camera_zposition	ARRAY_(0x00E4F540, long, [18])
#define camera_xtarget	ARRAY_(0x00E4F3E0, long, [18])
#define camera_ytarget	ARRAY_(0x00E51EC0, long, [18])
#define camera_ztarget	ARRAY_(0x00E4F5A0, long, [18])
#define camera_roll	ARRAY_(0x00E4F4A0, long, [18])
#define camera_fov	ARRAY_(0x00E4F380, long, [18])
#define camera_speed	ARRAY_(0x00E4F660, long, [18])
/***********************/
#define next_spider VAR_(0x0051D008, long)
#define Spiders VAR_(0x00EEF45C, SPIDER_STRUCT*)
#define NotHitLaraCount VAR_(0x0051D0A4, char)
#define nAIObjects	VAR_(0x00E5B842, short)
#define AIObjects	VAR_(0x00E5B844, AIOBJECT*)
#define gt VAR_(0x0051CE70, GUARDIAN_TARGET)
#define flip_status	VAR_(0x00EEEAE0, long)
#define static_lookcamp	VAR_(0x00EEFAB0, GAME_VECTOR)
#define static_lookcamt	VAR_(0x00EEFAA0, GAME_VECTOR)
#define credits_timer	VAR_(0x0051064C, long)
#define LSHKTimer	VAR_(0x0051CA46, char)
#define LSHKShotsFired	VAR_(0x0051CA45, char)
#define ExittingBinos	VAR_(0x0051CA20, long)
#define bLaraTorch	VAR_(0x0087B0F8, long)
#define FogStart	VAR_(0x0050A438, float)
#define FogEnd	VAR_(0x0050A43C, float)
#define f_zfar	VAR_(0x0055D228, float)
#define frames VAR_(0x00875174, short*)
#define rgt VAR_(0x0051CF98, RG_TARGET)
#define CurrentRoom	VAR_(0x00E6D754, long)
#define ClipRoomNum	VAR_(0x00E6D730, short)
#define SteelDoorLensPos	VAR_(0x00E4B110, PHD_VECTOR)
#define snow_outside	VAR_(0x00E6CAE8, long)
#define camera_underwater	VAR_(0x00E6E4B4, long)
#define room_list_start	VAR_(0x0051CD60, long)
#define room_list_end	VAR_(0x0051CD64, long)
#define number_draw_rooms	VAR_(0x00E6CAFC, long)
#define outside_top	VAR_(0x00E6E4E0, long)
#define outside_left	VAR_(0x00E6D83C, long)
#define outside_right	VAR_(0x00E6E4C0, long)
#define outside_bottom	VAR_(0x00E6D738, long)
#define ControlMethod	VAR_(0x008FBDA8, long)
#define SetupLight_thing	VAR_(0x0087B0D8, long)
#define unused_bLaraUnderWater	VAR_(0x0087B0FC, long)
#define NumSunLights	VAR_(0x0087B100, long)
#define NumPointLights	VAR_(0x0087B104, long)
#define NumShadowLights	VAR_(0x0087B10C, long)
#define NumFogBulbs	VAR_(0x0087B114, long)
#define NumSpotLights	VAR_(0x0087B108, long)
#define TotalNumLights	VAR_(0x0087B110, long)
#define aLightMatrix	VAR_(0x0087ACC0, D3DMATRIX)
#define D3DInvCameraMatrix	VAR_(0x0055D168, D3DMATRIX)
#define aCamera	VAR_(0x0051D0B0, FCAMERA)
#define aCamPos	VAR_(0x007ED6A0, FVECTOR)
#define aCamTar	VAR_(0x007EE0B8, FVECTOR)
#define aCamDir	VAR_(0x007ED0E8, FVECTOR)
#define room_clip_top	VAR_(0x007DFC08, float)
#define room_clip_right	VAR_(0x007DBC04, float)
#define room_clip_left	VAR_(0x007DBC00, float)
#define room_clip_bottom	VAR_(0x007DFC10, float)
#define current_room_ptr	VAR_(0x007DFC0C, ROOM_INFO*)
#define current_room_underwater	VAR_(0x007EE0C8, long)
#define RoomRGB	VAR_(0x0057A508, long)
#define old_lighting_water	VAR_(0x007EE0D4, long)
#define SFXVolume	VAR_(0x00517B6C, long)
#define MusicVolume	VAR_(0x00517B68, long)
#define SoundQuality	VAR_(0x00517B70, long)
#define NumSpecialFeatures	VAR_(0x008FBD9C, long)
#define SpecialFeaturesNum	VAR_(0x00517B28, long)
#define big_char_height	VAR_(0x00E4DEA4, long)
#define load_save_options_unk	VAR_(0x00E4DEAC, long)
#define default_font_height	VAR_(0x00E4DC40, long)
#define SGcount	VAR_(0x0051CFFC, long)
#define SGpoint	VAR_(0x0051CFF8, char*)
#define mesh_base	VAR_(0x0087516C, short*)
#define FmvSceneTriggered	VAR_(0x00EEEAD8, long)
#define number_cameras	VAR_(0x00EEFAC0, long)
#define spec_wibble	VAR_(0x0057753C, long)
#define acm_ready   VAR_(0x0057A00C, bool)
#define audio_counter   VAR_(0x0057A018, long)
#define num_items	VAR_(0x00874250, long)
#define nAnimUVRanges	VAR_(0x0087495C, long)
#define LevelFILEptr	VAR_(0x00875164, FILE*)
#define samples_buffer	VAR_(0x0086BEDC, char*)
#define slots_used	VAR_(0x0051CEE8, long)
#define number_boxes	VAR_(0x00EEFB68, long)
#define skelly_backgunbak	VAR_(0x00E6D732, short)
#define skelly_rhandbak	VAR_(0x00E6D840, short*)
#define skelly_lhandbak	VAR_(0x00E6D828, short*)
#define StaticMeshShade	VAR_(0x0087B0DC, long)
#define StaticMeshLightItem	VAR_(0x008796C8, ITEM_INFO)
#define D3DLights	VAR_(0x0087B0F0, D3DLIGHT_STRUCT*)
#define D3DDynamics	VAR_(0x0087B0F4, D3DLIGHT_STRUCT*)
#define DebrisFlags	VAR_(0x0051CA88, short)
#define DebrisMesh	VAR_(0x00E8CAB0, MESH_DATA*)
#define DebrisMeshC1	VAR_(0x00E912C4, long)
#define DebrisMeshC2	VAR_(0x00E912C0, long)
#define DebrisMeshC3	VAR_(0x00E912C8, long)
#define DebrisMeshAmbient	VAR_(0x00E8CAAC, long)
#define DebrisMeshFlags	VAR_(0x00E8CAB4, long)
#define rain_count	VAR_(0x00D6866C, short)
#define max_rain	VAR_(0x00C713D8, short)
#define snow_count	VAR_(0x00C713D0, short)
#define max_snow	VAR_(0x00C717E4, short)
#define MonoScreenOn	VAR_(0x0087B81C, char)
#define aRoomletTransformLight_num	VAR_(0x00511A64, float)
#define aRoomletTransformLight_bignum	VAR_(0x00511A5C, float)
#define nRoomletFogBulbs	VAR_(0x007DFFDC, long)
#define FPCW	VAR_(0x00878654, short)
#define save_counter	VAR_(0x008786EC, long)
#define NumLevelFogBulbs	VAR_(0x007DFFD8, long)
#define NumActiveFogBulbs	VAR_(0x007EE0C4, long)
#define nFXFogBulbs	VAR_(0x007EE0D8, long)
#define D3DCameraMatrix	VAR_(0x0057A0B0, D3DMATRIX)
#define D3DMW2VMatrix	VAR_(0x0057A0F0, D3DMATRIX)
#define DEL_playingamefmv	VAR_(0x0051CE24, char)
#define num_level_meshes	VAR_(0x007DFFE4, long)
#define mesh_vtxbuf	VAR_(0x007DFFE0, MESH_DATA**)
#define loadbar_steps	VAR_(0x008BBD94, float)
#define loadbar_pos	VAR_(0x008BBD90, float)
#define loadbar_maxpos	VAR_(0x008BBD64, long)
#define loadbar_on	VAR_(0x008FBDC0, long)
#define LevelLoadingThread	VAR_(0x00874968, THREAD)
#define load_cam	VAR_(0x00875198, PHD_VECTOR)
#define load_target	VAR_(0x008751A4, PHD_VECTOR)
#define load_roomnum	VAR_(0x005165CD, char)
#define DoFade	VAR_(0x00C87BF0, long)
#define FadeVal	VAR_(0x00C86BE8, long)
#define FadeStep	VAR_(0x00C713D4, long)
#define FadeCnt	VAR_(0x00C713DC, long)
#define FadeEnd	VAR_(0x00C713E0, long)
#define DestVB  VAR_(0x00D9AAC8, LPDIRECT3DVERTEXBUFFER)
#define wav_file_buffer	VAR_(0x0057A004, uchar*)
#define ADPCMBuffer	VAR_(0x0057A008, uchar*)
#define screen_surface	VAR_(0x0087BD58, LPDIRECTDRAWSURFACE4)
#define G_dxinfo	VAR_(0x0086B9AC, DXINFO*)
#define G_dxptr	VAR_(0x0086BD94, DXPTR*)
#define G_ddraw	VAR_(0x0086B9A8, LPDIRECTDRAW4)
#define G_hwnd	VAR_(0x0086B9A4, HWND)
#define G_d3d	VAR_(0x0086BA30, LPDIRECT3D3)
#define t_frequency	VAR_(0x00D9AAB0, __int64)
#define audio_stream_fp	VAR_(0x0057A010, FILE*)
#define DSBuffer	VAR_(0x00579FFC, LPDIRECTSOUNDBUFFER)
#define reading_audio_file	VAR_(0x0057A01C, volatile bool)
#define continue_reading_audio_file	VAR_(0x00579FE4, volatile bool)
#define XAFlag	VAR_(0x00510B18, long)
#define audio_cs	VAR_(0x00579FB0, CRITICAL_SECTION)
#define audio_fp_write_ptr	VAR_(0x00579FD4, uchar*)
#define audio_play_mode	VAR_(0x00579E30, long)
#define XAReqTrack	VAR_(0x0057A014, long)
#define audio_buffer_size	VAR_(0x00579FF8, long)
#define hACMStream	VAR_(0x00579FF0, HACMSTREAM)
#define pAudioWrite	VAR_(0x00579FE0, uchar*)
#define AudioBytes	VAR_(0x00579FE8, ulong)
#define CurrentNotify	VAR_(0x00579E4C, long)
#define NextWriteOffset	VAR_(0x00579FD8, long)
#define NotifySize	VAR_(0x00579FD0, long)
#define hACMDriverID	VAR_(0x00579FCC, HACMDRIVERID)
#define NotificationThreadHandle	VAR_(0x00579FA8, HANDLE)
#define DSNotify	VAR_(0x0057A000, LPDIRECTSOUNDNOTIFY)
#define hACMDriver	VAR_(0x00579FF4, HACMDRIVER)
#define resChangeCounter	VAR_(0x00D9AD9C, long)
#define start_setup	VAR_(0x0057A098, bool)
#define fmvs_disabled	VAR_(0x0057A099, bool)
#define level_fp	VAR_(0x00875164, FILE*)
#define CompressedData	VAR_(0x00875148, char*)
#define FileCompressed	VAR_(0x005165C8, long)
#define aranges	VAR_(0x00D9ADA0, short*)
#define AnimatingTexturesVOffset	VAR_(0x008751BC, short)
#define targetMeshP	VAR_(0x00E6E460, MESH_DATA*)
#define binocsMeshP	VAR_(0x00E6D744, MESH_DATA*)
#define ScaleFlag	VAR_(0x00E4EA60, char)
#define MonitorScreenTex	VAR_(0x0087497C, TEXTURESTRUCT*)
#define MonitorScreenU	VAR_(0x00874980, float)
#define LoadLevelName	VAR_(0x00D9AC48, LOADLEVELNAME)
#define MapData	VAR_(0x00874254, char*)
#define num_boxes	VAR_(0x00EEFB68, long)
#define overlap	VAR_(0x00EEFB5C, ushort*)

/*title shit*/
#define sound_cut_flag	VAR_(0x0051CE58, long)//DoTitle and SoundEffect. flag before and after doing some title cutscene, 
//if 0 + playing cut menu selections dont make a sound. never seems to be the case though!

#define title_string	ARRAY_(0x0050842C, char, [8])

#define nframes	VAR_(0x005082C4, long)

#define CreditsDone	VAR_(0x00E6D838, uchar)
#define CanLoad	VAR_(0x0051CE54, char)
#define JustLoaded	VAR_(0x0051D001, char)
/*title shit*/

/*Skin things*/
#define SkinXYZPtr	VAR_(0x00E5B918, SkinXYZ*)
#define BelowMeshXYZ	VAR_(0x00E5B930, SkinXYZ)
#define JointMeshXYZ	VAR_(0x00E5B920, SkinXYZ)
#define AboveMeshXYZ	VAR_(0x00E5B870, SkinXYZ)
#define XYZList	ARRAY_(0x00E5B940, SkinXYZ, [32])
#define SkinVertNums	ARRAY_(0x00E86100, char, [40][12])
#define HairSkinVertNums	ARRAY_(0x00508CEC, char, [6][12])
#define HairScratchVertNums	ARRAY_(0x00508D34, char, [4][12])
#define SkinJoints ARRAY_(0x00508CB4, uchar, [14][4])
#define ScratchVertNums ARRAY_(0x00E7F080, char, [40][12])
#define PointsToCalc ARRAY_(0x00E5BAC0, uchar, [26][12])

//arrays
#define cutseq_meshbits	ARRAY_(0x00E7EEA0, ulong, [10])
#define objects	ARRAY_(0x0086CF50, OBJECT_INFO, [460])
#define SmashedMesh	ARRAY_(0x00EEF8C0, MESH_INFO*, [16])
#define SmashedMeshRoom	ARRAY_(0x00EEF480, short, [16])
#define blood	ARRAY_(0x00E4C9C0, BLOOD_STRUCT, [32])
#define RPickups	ARRAY_(0x00E596E0, uchar, [16])
#define AnimatingWaterfalls	ARRAY_(0x00E59720, TEXTURESTRUCT*, [6])
#define AnimatingWaterfallsV	ARRAY_(0x00E59760, float, [6])
#define interpolated_bounds	ARRAY_(0x00E6E4D0, short, [6])
#define	keymap	ARRAY_(0x0086BB8C, char, [256])
#define gfTakeaways	ARRAY_(0x00E5C290, uchar, [16])
#define gfPickups	ARRAY_(0x00E5C300, uchar, [16])
#define	weapons	ARRAY_(0x005085B0, WEAPON_INFO, [9])
#define	DeadlyBounds	ARRAY_(0x00E6C3C0, long, [6])
#define cutseq_meshswapbits	ARRAY_(0x00E7EEE0, ulong, [10])
#define fmv_to_play	ARRAY_(0x0051CE28, char, [2])
#define gfResidentCut	ARRAY_(0x00E5C278, uchar, [4])
#define	LightningRGBs	ARRAY_(0x00E6E4B8, ushort, [3])
#define LightningRGB	ARRAY_(0x00E6CAF0, ushort, [3])
#define gfMips	ARRAY_(0x00E5C2C0, uchar, [8])
#define inventry_objects_list	ARRAY_(0x00508E38, INVOBJ, [100])
#define	FootPrint	ARRAY_(0x00E5C3E0, FOOTPRINT, [32])
#define	gfLevelNames	ARRAY_(0x00E5C320, uchar, [40])
#define	dynamics	ARRAY_(0x00E6C3E0, DYNAMIC, [64])
#define Slist	ARRAY_(0x00E51FE0, SPHERE, [34])
#define keypadinputs	ARRAY_(0x00E59778, uchar, [4])
#define hairs	ARRAY_(0x00E5C000, HAIR_STRUCT, [2][7])
#define smoke_spark	ARRAY_(0x00E4B940, SMOKE_SPARKS, [32])
#define fires	ARRAY_(0x00E4C7A0, FIRE_LIST, [32])
#define layout	ARRAY_(0x00516C3C, short, [2][18])
#define conflict	ARRAY_(0x00878C4C, long, [18])
#define reg_class	ARRAY_(0x0057A080, char, [4])
#define flip_stats	ARRAY_(0x00EEF060, long, [255])
#define LaSlot	ARRAY_(0x00E52420, SoundSlot, [32])
#define rings	ARRAY_(0x00E59900, RINGME*, [2])
#define SequenceUsed	ARRAY_(0x00E4EA78, uchar, [6])
#define SequenceResults	ARRAY_(0x00E4EA80, uchar, [3][3][3])
#define Sequences	ARRAY_(0x00E4EA9C, uchar, [3])
#define ClosedDoors	ARRAY_(0x0051CAC0, long, [32])
#define flipmap	ARRAY_(0x00EEEBA0, long, [255])
#define spark	ARRAY_(0x00E5F380, SPARKS, [1024])
#define spark_dynamics	ARRAY_(0x00E6C380, SP_DYNAMIC, [8])
#define pickups	ARRAY_(0x00E5BF40, DISPLAYPU, [8])
#define twogun	ARRAY_(0x00EEEB00, TWOGUN_INFO, [4])
#define ammo_object_list	ARRAY_(0x00E598E0, AMMOLIST, [3])
#define current_options	ARRAY_(0x00E598C0, MENUTHANG, [3])
#define actor_pnodes	ARRAY_(0x00E71180, PACKNODE*, [10])
#define temp_rotation_buffer	ARRAY_(0x00E711C0, short, [160])
#define los_rooms ARRAY_(0x00EEEFC0, short, [20])
#define static_objects ARRAY_(0x00874988, STATIC_INFO, [70])
#define RopeList ARRAY_(0x00E54CC0, ROPE_STRUCT, [8])
#define LaraNodeUnderwater	ARRAY_(0x00E862F0, uchar, [15])
#define lara_matrices	ARRAY_(0x00E86320, long, [180])
#define lara_joint_matrices	ARRAY_(0x00E86BC0, long, [180])
#define lara_matricesF	ARRAY_(0x00E868E0, float, [180])
#define lara_joint_matricesF	ARRAY_(0x00E86600, float, [180])
#define aScratchNormals	ARRAY_(0x0057A158, D3DVECTOR, [64])
#define duff_item	ARRAY_(0x00E71300, ITEM_INFO, [10])
#define LaraNodeAmbient	ARRAY_(0x0057A460, long, [2])
#define first_hair	ARRAY_(0x00E5BF60, long, [2])
#define aMappedEnvUV	ARRAY_(0x00920E18, ENVUV, [256])
#define aVertexBuffer	ARRAY_(0x007DFFE8, D3DTLVERTEX, [1024])
#define scratchpad	ARRAY_(0x00E912E0, char, [1024])
#define tsv_buffer	ARRAY_(0x00E86EA0, char, [16384])
#define old_status_flags	ARRAY_(0x00E7F000, char, [32])
#define old_status_flags2	ARRAY_(0x00E7F040, ushort, [32])
#define cutseq_resident_addresses	ARRAY_(0x00E7EF20, char*, [47])
#define fire_spark	ARRAY_(0x00E4CE40, FIRE_SPARKS, [20])
#define Gunshells	ARRAY_(0x00E4BEC0, GUNSHELL_STRUCT, [24])
#define Gunflashes	ARRAY_(0x00E4D660, GUNFLASH_STRUCT, [4])
#define debris	ARRAY_(0x00E8CAC0, DEBRIS_STRUCT, [256])
#define splashes	ARRAY_(0x00E6CA00, SPLASH_STRUCT, [4])
#define ripples	ARRAY_(0x00E5C600, RIPPLE_STRUCT, [32])
#define Bubbles	ARRAY_(0x00E4D160, BUBBLE_STRUCT, [40])
#define Drips	ARRAY_(0x00E4D740, DRIP_STRUCT, [32])
#define ShockWaves	ARRAY_(0x00E4C1A0, SHOCKWAVE_STRUCT, [16])
#define ItemNewRooms	ARRAY_(0x00EEF4C0, short, [256][2])
#define SaveGames	ARRAY_(0x0087B828, SAVEFILE_INFO, [15])
#define Lightning	ARRAY_(0x00E4C360, LIGHTNING_STRUCT, [16])
#define GlobalCollisionBounds ARRAY_(0x00EEF910, short, [6])
#define HairRotScratchVertNums	ARRAY_(0x00506D40, char, [5][12])
#define EnemyBites	ARRAY_(0x00509A30, BITE_INFO, [9])
#define fcossin_tbl	ARRAY_(0x0051D164, float, [65536])
#define StarFieldPositions	ARRAY_(0x00C86BEC, float, [1024])
#define StarFieldColors	ARRAY_(0x00C713E4, long, [256])
#define draw_room_list	ARRAY_(0x0051CB5C, long, [128])
#define draw_rooms	ARRAY_(0x00E6D760, short, [100])
#define jLayout	ARRAY_(0x00516AF0, long, [32])
#define SunLights	ARRAY_(0x00879538, SUNLIGHT_STRUCT, [16])
#define PointLights	ARRAY_(0x00878E28, POINTLIGHT_STRUCT, [64])
#define w2v_matrix	ARRAY_(0x0055D26C, long, [12])
#define SpecialFeaturesPage	ARRAY_(0x0087BD50, char, [5])
#define sfx_frequencies	ARRAY_(0x00517B5C, long, [3])
#define GermanKeyboard	ARRAY_(0x00516C84, char*, [272])
#define KeyboardButtons	ARRAY_(0x005170C4, char*, [272])
#define JoyStickButtons	ARRAY_(0x00517504, char*, [16])
#define defaultJLayout	ARRAY_(0x00516B70, long, [32])
#define cd_flags	ARRAY_(0x00EEEA40, char, [136])
#define Textures	ARRAY_(0x00D99DA8, TEXTURE, [64])
#define Bucket	ARRAY_(0x0057A510, TEXTUREBUCKET, [30])
#define BucketSpecular	ARRAY_(0x007EB068, long, [2080])
#define RoomletLights	ARRAY_(0x007ED6B0, ROOMLET_LIGHT, [64])

#define	LevelFogBulbs	ARRAY_(0x007ED0F8, FOGBULB_INFO, [64])		//list of all fogbulbs in the level (copied from room data)
#define FogBulbs	ARRAY_(0x0087AD18, FOGBULB_STRUCT, [16])		//to apply on object vertices
#define RoomletFogBulbs	ARRAY_(0x007DFC18, FOGBULB_STRUCT, [16])	//to apply on roomlet vertices
#define ActiveFogBulbs	ARRAY_(0x007E7FF0, FOGBULB_STRUCT, [64])	//list of active fog bulbs
#define FXFogBulbs	ARRAY_(0x007EAF78, FOGBULB_STRUCT, [4])			//list of fx fog bulbs (only used for Red Alert gas clouds)

#define MonoScreen	ARRAY_(0x008BBD68, MONOSCREEN_STRUCT, [5])
#define aBoundingBox	ARRAY_(0x00921618, float, [24])
#define AnimatingTexturesV	ARRAY_(0x0087435C, float, [16][8][3])
#define FontShades	ARRAY_(0x00E4E560, CVECTOR, [10][32])
#define CharDef	ARRAY_(0x00507AB8, CHARDEF, [106])
#define ground_zone	ARRAY_(0x00EEFB20, short*, [5][2])

//defs
#define NO_HEIGHT -32512
#define	NO_ITEM	-1
#define NO_ROOM	255
#define MAX_ITEMS	256
#define MAX_SAMPLES	450
#define FVF (D3DFVF_TEX2 | D3DFVF_SPECULAR | D3DFVF_DIFFUSE | D3DFVF_XYZRHW)
#define MALLOC_SIZE	5000000		//5MB
#define WINDOW_STYLE	(WS_OVERLAPPED | WS_BORDER | WS_CAPTION)
