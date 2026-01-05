#include "global.h"

#include <new>

#include "hashtable.hpp"
#include "proc_ex.hpp"
#include "sound_manager.hpp"

#include "unknown_funcs.h"
#include "unknown_types.hpp"

#include "constants/sounds.h"

struct UnkStruct_020efcd4
{
    STRUCT_PAD(0x0000, 0x1000);
    u8 unk_1000[0xc0];
    UnkStruct_020efcd4 * unk_10c0;
    SoundHandle * unk_10c4;
    u32 unk_10c8;
    u32 unk_10cc;
    u32 unk_10d0;
};

// .bss

SoundManager * gSoundManager = NULL;

BOOL data_020efccc = FALSE;

UnkStruct_020efcd4 * data_020efcd0 = NULL;
UnkStruct_020efcd4 * data_020efcd4 = NULL;

u8 data_020efce0[0x1000] = {};

u8 data_020f0ce0[0xA0000] = {};

// end .bss

EC void func_02097ff8(void);
EC void func_02015ec0(u32);

// clang-format off

EC void SoundWaitTo_Loop(SoundWaitTo * proc);

struct ProcCmd ProcScr_SoundWaitTo[] =
{
    PROC_NAME,
    PROC_REPEAT(SoundWaitTo_Loop),
    PROC_END,
};

EC void SoundTemporarySe_Loop(SoundTemporarySe * proc);

struct ProcCmd ProcScr_SoundTemporarySe[] =
{
    PROC_NAME,
    PROC_REPEAT(SoundTemporarySe_Loop),
    PROC_END,
};

EC void SoundVolumeMoveVC_Loop(SoundVolumeMoveVC * proc);

struct ProcCmd ProcScr_SoundVolumeMoveVC[] =
{
    PROC_NAME,
    PROC_SLEEP(0),
    { PROC_CMD_1C, 0x0000, 0x00000000, },
    PROC_REPEAT(SoundVolumeMoveVC_Loop),
    PROC_END,
};

// clang-format on

EC void Sound_Init(void)
{
    gSoundManager = new SoundManager;
    gSoundManager->unk_a0 = 1;
    gSoundManager->unk_a1 = 0x7f;
    gSoundManager->unk_9c = 0;
    gSoundManager->unk_94 = NULL;
    gSoundManager->unk_98 = NULL;

    func_02097ff8();
    func_02015ec0(0);

    gSoundManager->unk_a4 = new SoundHandle;
    gSoundManager->unk_a4->vfunc_24();

    gSoundManager->unk_a8 = new SoundHandle;
    gSoundManager->unk_a8->vfunc_24();

    gSoundManager->unk_ac = new SoundStrmHandle;
    gSoundManager->unk_ac->vfunc_24();

    gSoundManager->unk_b0 = new SoundSeHandle;
    gSoundManager->unk_b0->vfunc_24();

    gSoundManager->unk_b4 = new SoundSeHandle;
    gSoundManager->unk_b4->vfunc_24();

    return;
}

EC void func_02015f58(void);
EC void * func_0209a1a8(void *, s32);

EC void func_02015dc8(u32 param_1)
{
    func_02015f58();

    if (param_1 != 0)
    {
        gSoundManager->unk_94 = func_0209a1a8(data_020f0ce0, 0xa0000);
        return;
    }

    gSoundManager->unk_94 = func_0209a1a8(&data_020f0ce0[0x00000], 0x7d000);
    gSoundManager->unk_98 = func_0209a1a8(&data_020f0ce0[0x7d000], 0x23000);

    return;
}

EC void func_0209a218(void *);

EC void func_02015e38(void)
{
    if (gSoundManager->unk_94 != NULL)
    {
        func_0209a218(gSoundManager->unk_94);
    }

    if (gSoundManager->unk_98 != NULL)
    {
        func_0209a218(gSoundManager->unk_98);
    }

    gSoundManager->unk_94 = NULL;
    gSoundManager->unk_98 = NULL;

    return;
}

EC BOOL func_0209a520(s32, void *);

EC void func_02015e8c(void)
{
    func_0209a520(0, gSoundManager->unk_94);
    func_0209a520(1, gSoundManager->unk_94);
    return;
}

EC void func_02015dc8(u32);
EC BOOL func_0201160c(char *);
EC void func_0209a170(s32);
EC void func_02099990(void *, char *, void *, s32);
EC void func_0209af64(void *);
EC u32 func_0209a354(void *);
EC void func_0209b288(s32, void *);

EC void func_02015ec0(u32 param_1)
{
    func_02015dc8(param_1);

    if (!func_0201160c("/sound/fe11_sound_all.sdat"))
    {
        gSoundManager->unk_a0 = FALSE;
        return;
    }

    func_02099990(gSoundManager, "/sound/fe11_sound_all.sdat", gSoundManager->unk_94, 0);
    func_0209a170(0x1000);
    func_0209af64(gSoundManager->unk_94);
    func_0209b288(10, gSoundManager->unk_94);
    func_02015e8c();
    func_0209a354(gSoundManager->unk_94);

    return;
}

EC void func_02015f58(void)
{
    func_02015e38();
    return;
}

struct SoundEffectEntry
{
    /* 00 */ u32 id;
    /* 04 */ char * name;
};

// clang-format off

struct SoundEffectEntry gSoundEffectLut[] =
{
    BGM_BTL_PL1, "BGM_BTL_PL1",
    BGM_BTL_CP1, "BGM_BTL_CP1",
    BGM_BTL_BOSS1, "BGM_BTL_BOSS1",
    BGM_BTL_BOSS2, "BGM_BTL_BOSS2",
    BGM_BTL_BOSS3, "BGM_BTL_BOSS3",
    BGM_BTL_STARLIGHT1, "BGM_BTL_STARLIGHT1",
    BGM_BTL_MAFU1, "BGM_BTL_MAFU1",
    BGM_BTL_TUE1, "BGM_BTL_TUE1",
    BGM_BTL_TUE2, "BGM_BTL_TUE2",
    BGM_BTL_TOUGIJOU1, "BGM_BTL_TOUGIJOU1",
    BGM_MAP_PL1, "BGM_MAP_PL1",
    BGM_MAP_CP1, "BGM_MAP_CP1",
    BGM_MAP_PL2, "BGM_MAP_PL2",
    BGM_MAP_CP2, "BGM_MAP_CP2",
    BGM_MAP_PL3, "BGM_MAP_PL3",
    BGM_MAP_CP3, "BGM_MAP_CP3",
    BGM_MAP_PL4, "BGM_MAP_PL4",
    BGM_MAP_CP4, "BGM_MAP_CP4",
    BGM_MAP_PL5, "BGM_MAP_PL5",
    BGM_MAP_CP5, "BGM_MAP_CP5",
    BGM_MAP_PL6, "BGM_MAP_PL6",
    BGM_MAP_CP6, "BGM_MAP_CP6",
    BGM_MAP_PL7, "BGM_MAP_PL7",
    BGM_EVT_KIKI1, "BGM_EVT_KIKI1",
    BGM_EVT_SINGEKI1, "BGM_EVT_SINGEKI1",
    BGM_EVT_SINGEKI2, "BGM_EVT_SINGEKI2",
    BGM_EVT_ENEMY1, "BGM_EVT_ENEMY1",
    BGM_EVT_ENEMY2, "BGM_EVT_ENEMY2",
    BGM_EVT_MEET1, "BGM_EVT_MEET1",
    BGM_EVT_GANEF1, "BGM_EVT_GANEF1",
    BGM_EVT_GATO1, "BGM_EVT_GATO1",
    BGM_EVT_NINA1, "BGM_EVT_NINA1",
    BGM_EVT_MEET_AGAIN1, "BGM_EVT_MEET_AGAIN1",
    BGM_EVT_MEDIUS1, "BGM_EVT_MEDIUS1",
    BGM_EVT_ARITIA1, "BGM_EVT_ARITIA1",
    BGM_EVT_WIN1, "BGM_EVT_WIN1",
    BGM_EVT_WIN2, "BGM_EVT_WIN2",
    BGM_EVT_VILLAGE1, "BGM_EVT_VILLAGE1",
    BGM_GMAP1, "BGM_GMAP1",
    BGM_GMAP2, "BGM_GMAP2",
    BGM_GMAP3, "BGM_GMAP3",
    BGM_SYS_TITLE1, "BGM_SYS_TITLE1",
    BGM_SYS_GOPENING1, "BGM_SYS_GOPENING1",
    BGM_SYS_ENDING1, "BGM_SYS_ENDING1",
    BGM_SYS_STAFF1, "BGM_SYS_STAFF1",
    BGM_SYS_SENSEKI1, "BGM_SYS_SENSEKI1",
    BGM_SYS_ENDING3, "BGM_SYS_ENDING3",
    BGM_SYS_SINGEKI1, "BGM_SYS_SINGEKI1",
    BGM_SYS_CC1, "BGM_SYS_CC1",
    BGM_SYS_DIE_MARTH1, "BGM_SYS_DIE_MARTH1",
    BGM_SYS_DIE1, "BGM_SYS_DIE1",
    BGM_SYS_GAMEOVER1, "BGM_SYS_GAMEOVER1",
    BGM_SYS_TOUGIJOU1, "BGM_SYS_TOUGIJOU1",
    BGM_SYS_TOUGIJOU2, "BGM_SYS_TOUGIJOU2",
    BGM_SYS_BUKIYA1, "BGM_SYS_BUKIYA1",
    BGM_SYS_DOUGUYA1, "BGM_SYS_DOUGUYA1",
    BGM_SYS_SECRET1, "BGM_SYS_SECRET1",
    FF_ITEM_GET1, "FF_ITEM_GET1",
    FF_ITEM_LOST1, "FF_ITEM_LOST1",
    FF_LEVELUP1, "FF_LEVELUP1",
    FF_ITEM_GET2, "FF_ITEM_GET2",
    BGM_EVT_KIKI2, "BGM_EVT_KIKI2",
    BGM_EVT_SAD1, "BGM_EVT_SAD1",
    BGM_EVT_TIKI1, "BGM_EVT_TIKI1",
    BGM_EVT_ENEMY3, "BGM_EVT_ENEMY3",
    SE_EVT_ENV1, "SE_EVT_ENV1",
    SE_EVT_ENV2, "SE_EVT_ENV2",
    SE_EVT_ENV3, "SE_EVT_ENV3",
    SE_EVT_ENV4, "SE_EVT_ENV4",
    SE_EVT_ENV5, "SE_EVT_ENV5",
    BGM_BTL_TOUGIJOU1_2, "BGM_BTL_TOUGIJOU1_2",
    BGM_BTL_BOSS3_2, "BGM_BTL_BOSS3_2",
    BGM_SYS_COMMUNI1, "BGM_SYS_COMMUNI1",
    BGM_SYS_MENU1, "BGM_SYS_MENU1",
    BGM_FF_COMMUNI_WIN1, "BGM_FF_COMMUNI_WIN1",
    BGM_FF_COMMUNI_LOSE1, "BGM_FF_COMMUNI_LOSE1",
    FF_COMMUNI_FLAG1, "FF_COMMUNI_FLAG1",
    FF_COMMUNI_FLAG2, "FF_COMMUNI_FLAG2",
    STRM_SYS_OPENING1, "STRM_SYS_OPENING1",
    STRM_SYS_TITLE1, "STRM_SYS_TITLE1",
    STRM_SYS_ENDING2, "STRM_SYS_ENDING2",
    SE_SYS_CURSOL_MAP1, "SE_SYS_CURSOL_MAP1",
    SE_SYS_CURSOL2_WIN1, "SE_SYS_CURSOL2_WIN1",
    SE_SYS_MISS1, "SE_SYS_MISS1",
    SE_SYS_WINDOW_OPEN1, "SE_SYS_WINDOW_OPEN1",
    SE_SYS_EXP1, "SE_SYS_EXP1",
    SE_SYS_HP1, "SE_SYS_HP1",
    SE_SYS_MOJI1, "SE_SYS_MOJI1",
    SE_SYS_WINDOW_INFO1, "SE_SYS_WINDOW_INFO1",
    SE_SYS_TURN1, "SE_SYS_TURN1",
    SE_SYS_PARAUP1, "SE_SYS_PARAUP1",
    SE_SYS_START1, "SE_SYS_START1",
    SE_SYS_HELP_WIN_OPEN1, "SE_SYS_HELP_WIN_OPEN1",
    SE_SYS_HELP_WIN_CLOSE1, "SE_SYS_HELP_WIN_CLOSE1",
    SE_SYS_ENCOUNT1, "SE_SYS_ENCOUNT1",
    SE_SYS_SAVE_OK1, "SE_SYS_SAVE_OK1",
    SE_SYS_UNIT_CHANGE1, "SE_SYS_UNIT_CHANGE1",
    SE_MAP_SWORD_STORE1, "SE_MAP_SWORD_STORE1",
    SE_MAP_SWORD_STORE2, "SE_MAP_SWORD_STORE2",
    SE_MAP_HIT1, "SE_MAP_HIT1",
    SE_MAP_CRITICAL1, "SE_MAP_CRITICAL1",
    SE_MAP_MISS1, "SE_MAP_MISS1",
    SE_MAP_NODAMAGE1, "SE_MAP_NODAMAGE1",
    SE_SYS_SELECT1, "SE_SYS_SELECT1",
    SE_SYS_CANSEL1, "SE_SYS_CANSEL1",
    SE_SYS_WINDOW_INFO2, "SE_SYS_WINDOW_INFO2",
    SE_MAP_FADE_DIE_AWAY1, "SE_MAP_FADE_DIE_AWAY1",
    SE_MAP_DAMAGE_LAST1, "SE_MAP_DAMAGE_LAST1",
    SE_SYS_ENEMY_ON1, "SE_SYS_ENEMY_ON1",
    SE_SYS_ENEMY_OFF1, "SE_SYS_ENEMY_OFF1",
    SE_SYS_CURSOL2_WIN2, "SE_SYS_CURSOL2_WIN2",
    SE_SYS_CURSOL2_WIN31, "SE_SYS_CURSOL2_WIN31",
    SE_SYS_CURSOL2_WIN32, "SE_SYS_CURSOL2_WIN32",
    SE_SYS_CURSOL2_WIN33, "SE_SYS_CURSOL2_WIN33",
    SE_SYS_TUTORIAL1, "SE_SYS_TUTORIAL1",
    SE_SYS_COMMUNI_HAND1, "SE_SYS_COMMUNI_HAND1",
    SE_SYS_COMMUNI_ERROR1, "SE_SYS_COMMUNI_ERROR1",
    SE_SYS_POINT_UP1, "SE_SYS_POINT_UP1",
    SE_SYS_POINT_UP2, "SE_SYS_POINT_UP2",
    SE_SYS_POINT_UP3, "SE_SYS_POINT_UP3",
    SE_SYS_UNIT_WARP, "SE_SYS_UNIT_WARP",
    SE_SYS_kansei1, "SE_SYS_kansei1",
    SE_SYS_CHAPTER_OP1, "SE_SYS_CHAPTER_OP1",
    SE_SYS_START_GAME1, "SE_SYS_START_GAME1",
    SE_SYS_MOJI2, "SE_SYS_MOJI2",
    SE_SYS_CHAPTER_OP2, "SE_SYS_CHAPTER_OP2",
    SE_SYS_CHAPTER_OP3, "SE_SYS_CHAPTER_OP3",
    SE_SYS_CHAPTER_OP4, "SE_SYS_CHAPTER_OP4",
    SE_SYS_CHAPTER_OP5, "SE_SYS_CHAPTER_OP5",
    SE_SYS_CHAPTER_OP6, "SE_SYS_CHAPTER_OP6",
    SE_MAP_BRIDGE1, "SE_MAP_BRIDGE1",
    SE_MAP_VILLAGE_BOM1, "SE_MAP_VILLAGE_BOM1",
    SE_MAP_KEY_OPEN1, "SE_MAP_KEY_OPEN1",
    SE_MAP_DOOR_OPEN1, "SE_MAP_DOOR_OPEN1",
    SE_MAP_MONEY1, "SE_MAP_MONEY1",
    SE_SYS_KANSEI1, "SE_SYS_KANSEI1",
    SE_MAP_TAIMATU1, "SE_MAP_TAIMATU1",
    SE_MAP_HAMMARNE1, "SE_MAP_HAMMARNE1",
    SE_MAP_MAGICSHIELD1, "SE_MAP_MAGICSHIELD1",
    SE_MAP_LIVE1, "SE_MAP_LIVE1",
    SE_MAP_RELIVE1, "SE_MAP_RELIVE1",
    SE_MAP_RECOVER1, "SE_MAP_RECOVER1",
    SE_MAP_RESERVE1, "SE_MAP_RESERVE1",
    SE_MAP_WARP_START1, "SE_MAP_WARP_START1",
    SE_MAP_WARP_END1, "SE_MAP_WARP_END1",
    SE_MAP_AREA_OPEN1, "SE_MAP_AREA_OPEN1",
    SE_MAP_AREA_OPEN2, "SE_MAP_AREA_OPEN2",
    SE_MAP_DOPING1, "SE_MAP_DOPING1",
    SE_MAP_VALNERARY1, "SE_MAP_VALNERARY1",
    SE_MAP_HEALTERRAIN1, "SE_MAP_HEALTERRAIN1",
    SE_MAP_OM1, "SE_MAP_OM1",
    SE_MAP_TRANSFORM1, "SE_MAP_TRANSFORM1",
    SE_MAP_CLASSCHANGE1, "SE_MAP_CLASSCHANGE1",
    SE_MAP_HUMAN1_FLAT1, "SE_MAP_HUMAN1_FLAT1",
    SE_MAP_HUMAN1_WATER1, "SE_MAP_HUMAN1_WATER1",
    SE_MAP_HUMAN1_SAND1, "SE_MAP_HUMAN1_SAND1",
    SE_MAP_HUMAN1_WOOD1, "SE_MAP_HUMAN1_WOOD1",
    SE_MAP_HUMAN1_STON1, "SE_MAP_HUMAN1_STON1",
    SE_MAP_HUMAN2_FLAT1, "SE_MAP_HUMAN2_FLAT1",
    SE_MAP_HUMAN2_WATER1, "SE_MAP_HUMAN2_WATER1",
    SE_MAP_HUMAN2_SAND1, "SE_MAP_HUMAN2_SAND1",
    SE_MAP_HUMAN2_WOOD1, "SE_MAP_HUMAN2_WOOD1",
    SE_MAP_HUMAN2_STON1, "SE_MAP_HUMAN2_STON1",
    SE_MAP_HORSE1_FLAT1, "SE_MAP_HORSE1_FLAT1",
    SE_MAP_HORSE1_WATER1, "SE_MAP_HORSE1_WATER1",
    SE_MAP_HORSE1_SAND1, "SE_MAP_HORSE1_SAND1",
    SE_MAP_HORSE1_WOOD1, "SE_MAP_HORSE1_WOOD1",
    SE_MAP_HORSE1_STON1, "SE_MAP_HORSE1_STON1",
    SE_MAP_HORSE2_FLAT1, "SE_MAP_HORSE2_FLAT1",
    SE_MAP_HORSE2_WATER1, "SE_MAP_HORSE2_WATER1",
    SE_MAP_HORSE2_SAND1, "SE_MAP_HORSE2_SAND1",
    SE_MAP_HORSE2_WOOD1, "SE_MAP_HORSE2_WOOD1",
    SE_MAP_HORSE2_STON1, "SE_MAP_HORSE2_STON1",
    SE_MAP_DORAGON1, "SE_MAP_DORAGON1",
    SE_MAP_PEGASUS1, "SE_MAP_PEGASUS1",
    SE_MAP_SHOOTER1_FLAT1, "SE_MAP_SHOOTER1_FLAT1",
    SE_MAP_SHOOTER1_SAND1, "SE_MAP_SHOOTER1_SAND1",
    SE_MAP_SHOOTER1_WOOD1, "SE_MAP_SHOOTER1_WOOD1",
    SE_MAP_SHOOTER1_STON1, "SE_MAP_SHOOTER1_STON1",
    SE_BTL_NO_DAMAGE1, "SE_BTL_NO_DAMAGE1",
    SE_BTL_MISS1, "SE_BTL_MISS1",
    SE_BTL_FADE_DIE_AWAY1, "SE_BTL_FADE_DIE_AWAY1",
    SE_BTL_DAMAGE_UPDOWN1, "SE_BTL_DAMAGE_UPDOWN1",
    SE_BTL_DAMAGE_DOWNUP1, "SE_BTL_DAMAGE_DOWNUP1",
    SE_BTL_DAMAGE_TUKI1, "SE_BTL_DAMAGE_TUKI1",
    SE_BTL_DAMAGE_LAST1, "SE_BTL_DAMAGE_LAST1",
    SE_BTL_EFECT_CRITICAL1, "SE_BTL_EFECT_CRITICAL1",
    SE_BTL_BODY_MOVE1, "SE_BTL_BODY_MOVE1",
    SE_BTL_BODY_MOVE2, "SE_BTL_BODY_MOVE2",
    SE_BTL_BODY_MOVE3, "SE_BTL_BODY_MOVE3",
    SE_BTL_SWORD_DOWN1, "SE_BTL_SWORD_DOWN1",
    SE_BTL_SWORD_UP1, "SE_BTL_SWORD_UP1",
    SE_BTL_STORE1, "SE_BTL_STORE1",
    SE_BTL_STORE2, "SE_BTL_STORE2",
    SE_BTL_LANCE1, "SE_BTL_LANCE1",
    SE_BTL_LANCE_TURN1, "SE_BTL_LANCE_TURN1",
    SE_BTL_AXE_ROTATION1, "SE_BTL_AXE_ROTATION1",
    SE_BTL_AXE_DOWN1, "SE_BTL_AXE_DOWN1",
    SE_BTL_AXE_UP1, "SE_BTL_AXE_UP1",
    SE_BTL_AXE_ROUND1, "SE_BTL_AXE_ROUND1",
    SE_BTL_ARROW1, "SE_BTL_ARROW1",
    SE_BTL_BOW1, "SE_BTL_BOW1",
    SE_BTL_BOW_CRITICAL1, "SE_BTL_BOW_CRITICAL1",
    SE_BTL_ARROW_OUT1, "SE_BTL_ARROW_OUT1",
    SE_BTL_TRAIANGLE1, "SE_BTL_TRAIANGLE1",
    SE_BTL_THUNDERSWORD11, "SE_BTL_THUNDERSWORD11",
    SE_BTL_THUNDERSWORD12, "SE_BTL_THUNDERSWORD12",
    SE_BTL_EFFECT_GODARM1, "SE_BTL_EFFECT_GODARM1",
    SE_BTL_DRAGON_FIRE1, "SE_BTL_DRAGON_FIRE1",
    SE_BTL_DRAGON_TIKI1, "SE_BTL_DRAGON_TIKI1",
    SE_BTL_DRAGON_IN1, "SE_BTL_DRAGON_IN1",
    SE_BTL_DRAGON_OUT1, "SE_BTL_DRAGON_OUT1",
    SE_BTL_DRAGON1, "SE_BTL_DRAGON1",
    SE_BTL_GODDRAGON_FLAP1, "SE_BTL_GODDRAGON_FLAP1",
    SE_BTL_DARK_DRAGON1, "SE_BTL_DARK_DRAGON1",
    SE_BTL_CLASS_CHANGE1, "SE_BTL_CLASS_CHANGE1",
    SE_BTL_CLASS_CHANGE2, "SE_BTL_CLASS_CHANGE2",
    SE_BTL_CLASS_CHANGE3, "SE_BTL_CLASS_CHANGE3",
    SE_BTL_FIRE11, "SE_BTL_FIRE11",
    SE_BTL_FIRE12, "SE_BTL_FIRE12",
    SE_BTL_THUNDER1, "SE_BTL_THUNDER1",
    SE_BTL_BLIZZAR11, "SE_BTL_BLIZZAR11",
    SE_BTL_BLIZZAR12, "SE_BTL_BLIZZAR12",
    SE_BTL_LFIRE11, "SE_BTL_LFIRE11",
    SE_BTL_LFIRE12, "SE_BTL_LFIRE12",
    SE_BTL_LFIRE13, "SE_BTL_LFIRE13",
    SE_BTL_TORON11, "SE_BTL_TORON11",
    SE_BTL_TORON12, "SE_BTL_TORON12",
    SE_BTL_VOLGANON11, "SE_BTL_VOLGANON11",
    SE_BTL_VOLGANON12, "SE_BTL_VOLGANON12",
    SE_BTL_VOLGANON13, "SE_BTL_VOLGANON13",
    SE_BTL_EXCALIBUR10, "SE_BTL_EXCALIBUR10",
    SE_BTL_EXCALIBUR11, "SE_BTL_EXCALIBUR11",
    SE_BTL_EXCALIBUR12, "SE_BTL_EXCALIBUR12",
    SE_BTL_STARLIGHT1, "SE_BTL_STARLIGHT1",
    SE_BTL_STARLIGHT12, "SE_BTL_STARLIGHT12",
    SE_BTL_STARLIGHT13, "SE_BTL_STARLIGHT13",
    SE_BTL_WORM1, "SE_BTL_WORM1",
    SE_BTL_WORM2, "SE_BTL_WORM2",
    SE_BTL_EFECT_CLTWIZARD1, "SE_BTL_EFECT_CLTWIZARD1",
    SE_BTL_EFECT_CLTPRIEST1, "SE_BTL_EFECT_CLTPRIEST1",
    SE_BTL_AURA1, "SE_BTL_AURA1",
    SE_BTL_AURA1_2, "SE_BTL_AURA1_2",
    SE_BTL_MAFU1, "SE_BTL_MAFU1",
    SE_BTL_SHO_STONEHEDGE1, "SE_BTL_SHO_STONEHEDGE1",
    SE_BTL_SHO_THUNDERBOLT1, "SE_BTL_SHO_THUNDERBOLT1",
    SE_BTL_SHO_FIREGUN1, "SE_BTL_SHO_FIREGUN1",
    SE_BTL_SHO_ELEPHANT1, "SE_BTL_SHO_ELEPHANT1",
    SE_BTL_HUMAN1_FLAT, "SE_BTL_HUMAN1_FLAT",
    SE_BTL_HUMAN2_FLAT, "SE_BTL_HUMAN2_FLAT",
    SE_BTL_HUMAN3_FLAT, "SE_BTL_HUMAN3_FLAT",
    SE_BTL_HUMAN1_WATER, "SE_BTL_HUMAN1_WATER",
    SE_BTL_HUMAN2_WATER, "SE_BTL_HUMAN2_WATER",
    SE_BTL_HUMAN3_WATER, "SE_BTL_HUMAN3_WATER",
    SE_BTL_HUMAN1_SAND, "SE_BTL_HUMAN1_SAND",
    SE_BTL_HUMAN2_SAND, "SE_BTL_HUMAN2_SAND",
    SE_BTL_HUMAN3_SAND, "SE_BTL_HUMAN3_SAND",
    SE_BTL_HUMAN1_WOOD, "SE_BTL_HUMAN1_WOOD",
    SE_BTL_HUMAN2_WOOD, "SE_BTL_HUMAN2_WOOD",
    SE_BTL_HUMAN3_WOOD, "SE_BTL_HUMAN3_WOOD",
    SE_BTL_HUMAN1_STONE, "SE_BTL_HUMAN1_STONE",
    SE_BTL_HUMAN2_STONE, "SE_BTL_HUMAN2_STONE",
    SE_BTL_HUMAN3_STONE, "SE_BTL_HUMAN3_STONE",
    SE_BTL_HORSE1_FLAT_F1, "SE_BTL_HORSE1_FLAT_F1",
    SE_BTL_HORSE1_FLAT_B1, "SE_BTL_HORSE1_FLAT_B1",
    SE_BTL_HORSE1_FLAT_T1, "SE_BTL_HORSE1_FLAT_T1",
    SE_BTL_HORSE3_FLAT_F1, "SE_BTL_HORSE3_FLAT_F1",
    SE_BTL_HORSE3_FLAT_B1, "SE_BTL_HORSE3_FLAT_B1",
    SE_BTL_HORSE3_FLAT_T1, "SE_BTL_HORSE3_FLAT_T1",
    SE_BTL_HORSE1_WATER_F1, "SE_BTL_HORSE1_WATER_F1",
    SE_BTL_HORSE1_WATER_B1, "SE_BTL_HORSE1_WATER_B1",
    SE_BTL_HORSE1_WATER_T1, "SE_BTL_HORSE1_WATER_T1",
    SE_BTL_HORSE3_WATER_F1, "SE_BTL_HORSE3_WATER_F1",
    SE_BTL_HORSE3_WATER_B1, "SE_BTL_HORSE3_WATER_B1",
    SE_BTL_HORSE3_WATER_T1, "SE_BTL_HORSE3_WATER_T1",
    SE_BTL_HORSE1_SAND_F1, "SE_BTL_HORSE1_SAND_F1",
    SE_BTL_HORSE1_SAND_B1, "SE_BTL_HORSE1_SAND_B1",
    SE_BTL_HORSE1_SAND_T1, "SE_BTL_HORSE1_SAND_T1",
    SE_BTL_HORSE3_SAND_F1, "SE_BTL_HORSE3_SAND_F1",
    SE_BTL_HORSE3_SAND_B1, "SE_BTL_HORSE3_SAND_B1",
    SE_BTL_HORSE3_SAND_T1, "SE_BTL_HORSE3_SAND_T1",
    SE_BTL_HORSE1_WOOD_F1, "SE_BTL_HORSE1_WOOD_F1",
    SE_BTL_HORSE1_WOOD_B1, "SE_BTL_HORSE1_WOOD_B1",
    SE_BTL_HORSE1_WOOD_T1, "SE_BTL_HORSE1_WOOD_T1",
    SE_BTL_HORSE3_WOOD_F1, "SE_BTL_HORSE3_WOOD_F1",
    SE_BTL_HORSE3_WOOD_B1, "SE_BTL_HORSE3_WOOD_B1",
    SE_BTL_HORSE3_WOOD_T1, "SE_BTL_HORSE3_WOOD_T1",
    SE_BTL_HORSE1_STONE_F1, "SE_BTL_HORSE1_STONE_F1",
    SE_BTL_HORSE1_STONE_B1, "SE_BTL_HORSE1_STONE_B1",
    SE_BTL_HORSE1_STONE_T1, "SE_BTL_HORSE1_STONE_T1",
    SE_BTL_HORSE3_STONE_F1, "SE_BTL_HORSE3_STONE_F1",
    SE_BTL_HORSE3_STONE_B1, "SE_BTL_HORSE3_STONE_B1",
    SE_BTL_HORSE3_STONE_T1, "SE_BTL_HORSE3_STONE_T1",
    SE_BTL_ARMOR1, "SE_BTL_ARMOR1",
    SE_BTL_BIRD_GLIDING2, "SE_BTL_BIRD_GLIDING2",
    SE_BTL_PEGASUS_FLAP1, "SE_BTL_PEGASUS_FLAP1",
    SE_BTL_PEGASUS_GLIDING1, "SE_BTL_PEGASUS_GLIDING1",
    SE_BTL_DRAGON_FLAP1, "SE_BTL_DRAGON_FLAP1",
    SE_BTL_DRAGON_GLIDING1, "SE_BTL_DRAGON_GLIDING1",
    SE_MAP_EARTHORB1, "SE_MAP_EARTHORB1",
    SE_MAP_TRANSFORM2, "SE_MAP_TRANSFORM2",
    SE_EVT_EARTHQUAKE1, "SE_EVT_EARTHQUAKE1",
    SE_EVT_APPLAUSE1, "SE_EVT_APPLAUSE1",
    SE_EVT_DOOR_LOCK1, "SE_EVT_DOOR_LOCK1",
    SE_EVT_APPLAUSE2, "SE_EVT_APPLAUSE2",
    SE_BTL_COMMAND1, "SE_BTL_COMMAND1",
    SE_EVT_SPARK1, "SE_EVT_SPARK1",
    SE_EVT_STARLIGHT1, "SE_EVT_STARLIGHT1",
    SE_EVT_TRAP1, "SE_EVT_TRAP1",
    SE_EVT_HITUGI1, "SE_EVT_HITUGI1",
    SE_EVT_NAGI1, "SE_EVT_NAGI1",
    SE_EVT_LIGHT1, "SE_EVT_LIGHT1",
    SE_MAP_DRAGON_GLIDING1, "SE_MAP_DRAGON_GLIDING1",
    SE_MAP_PEGASUS_GLIDING1, "SE_MAP_PEGASUS_GLIDING1",
    SE_MAP_ARMOR1, "SE_MAP_ARMOR1",
    SE_SYS_PHASE1, "SE_SYS_PHASE1",
    SE_BTL_SHOOTER_FLY1, "SE_BTL_SHOOTER_FLY1",
    SE_BTL_SHOOTER_LAUNCH1, "SE_BTL_SHOOTER_LAUNCH1",
    SE_BTL_HORSE_INANAKI1, "SE_BTL_HORSE_INANAKI1",
    SE_SYS_GMAP_EFFECT1, "SE_SYS_GMAP_EFFECT1",
    SE_EVT_DOOR_OPEN1, "SE_EVT_DOOR_OPEN1",
    SE_EVT_TRAP2, "SE_EVT_TRAP2",
    SE_SYS_LVUP1, "SE_SYS_LVUP1",
    SE_BTL_TRANSFORM2, "SE_BTL_TRANSFORM2",
    SE_BTL_MEDIUS_TRANSFORM1, "SE_BTL_MEDIUS_TRANSFORM1",
    SE_BTL_MEDIUS_TRANSFORM2, "SE_BTL_MEDIUS_TRANSFORM2",
    SE_BTL_MEDIUS_TRANSFORM3, "SE_BTL_MEDIUS_TRANSFORM3",
    SE_BTL_MEDIUS_ROAR1, "SE_BTL_MEDIUS_ROAR1",
    SE_BTL_MEDIUS_DIE1, "SE_BTL_MEDIUS_DIE1",
    SE_BTL_MEDIUS_DIE2, "SE_BTL_MEDIUS_DIE2",
    SE_SYS_OP_JINGLE1, "SE_SYS_OP_JINGLE1",
    SE_MAP_CARD1, "SE_MAP_CARD1",
    SE_EVT_DOOR_OPEN2, "SE_EVT_DOOR_OPEN2",
    SE_MAP_CARD_MOJI1, "SE_MAP_CARD_MOJI1",
    SE_SYS_OP_THUNDER1, "SE_SYS_OP_THUNDER1",
    SE_SYS_OP_THUNDER2, "SE_SYS_OP_THUNDER2",
    SE_SYS_OP_THUNDER3, "SE_SYS_OP_THUNDER3",
};

// clang-format on

EC void func_02015f64(void)
{
    s32 i;

    for (i = 0; gSoundEffectLut[i].name != NULL; i++)
    {
        HashTable::Put(gSoundEffectLut[i].name, &gSoundEffectLut[i]);
    }

    return;
}

EC void func_02070570(s32);
EC void func_0207058c(s32);
EC void func_02098080(void);

EC void func_02015fb4(void)
{
    if (gSoundManager->unk_a0)
    {
        func_02070570(4);

        if ((data_020efcd4 != NULL) ? TRUE : FALSE)
        {
            func_02098080();
        }

        func_0207058c(4);
    }

    return;
}

extern void * data_0219e298;
EC UnkStruct_020efcd4 * func_020a375c(void *);

EC void func_02016004(void)
{
    UnkStruct_020efcd4 * iVar1 = func_020a375c(data_0219e298);

    if (iVar1 == data_020efcd4)
    {
        data_020efcd0 = NULL;
        data_020efcd4 = NULL;
    }
    else
    {
        data_020efcd0 = iVar1->unk_10c0;
        func_020a341c(iVar1->unk_10c0->unk_1000);
    }

    delete iVar1;

    return;
}

EC void func_02016064(s32 arg_0)
{
    if (gSoundManager->unk_98 == NULL)
    {
        return;
    }

    func_0209a520(arg_0, gSoundManager->unk_98);
    func_0209a354(gSoundManager->unk_98);

    return;
}

EC void func_020a3320(void *);

EC void func_02016098(s32 param_1)
{
    if (data_020efcd4 != NULL)
    {
        func_020a3320(data_020efcd4->unk_1000);
    }

    func_02016064(param_1);

    return;
}

EC void func_020a3080(void *, void *, void *, void *, s32, s32);
EC void func_020a3754(void *, void *);
EC void func_020a374c(void *, void (*)(void));
EC void func_020a341c(void *);

EC void func_02016188(UnkStruct_020efcd4 *);

EC void func_020160d4(u32 param_1)
{
    UnkStruct_020efcd4 * iVar1 = new UnkStruct_020efcd4();

    iVar1->unk_10c0 = 0;
    iVar1->unk_10c4 = NULL;
    iVar1->unk_10c8 = param_1;
    iVar1->unk_10cc = 0;
    iVar1->unk_10d0 = 0;

    func_020a3080(iVar1->unk_1000, (void *)func_02016188, iVar1, iVar1->unk_1000, 0x1000, 0x11);
    func_020a3754(iVar1->unk_1000, iVar1);
    func_020a374c(iVar1->unk_1000, func_02016004);

    if (data_020efcd4 == NULL)
    {
        data_020efcd0 = iVar1;
        data_020efcd4 = iVar1;
        func_020a341c(iVar1->unk_1000);
        return;
    }

    data_020efcd4->unk_10c0 = iVar1;
    data_020efcd4 = iVar1;

    return;
}

EC void func_02016188(UnkStruct_020efcd4 * param_1)
{
    func_02016064(param_1->unk_10c8);
    return;
}

EC u32 func_0201619c(char * key)
{
    SoundEffectEntry * entry = static_cast<SoundEffectEntry *>(HashTable::Get1(key));

    if (entry != NULL)
    {
        return entry->id;
    }

    return -1;
}

EC s32 func_0209a474(void *);
EC void * func_0209a3a0(void *, u32);

EC u32 func_020161b4(void)
{
    if (data_020efcd4 != NULL ? TRUE : FALSE)
    {
        func_020a3320(data_020efcd4->unk_1000);
    }

    if (gSoundManager->unk_98 != NULL)
    {
        return func_0209a474(gSoundManager->unk_98);
    }

    return 0;
}

EC void func_02016200(u32 param_1)
{
    if (data_020efcd4 != NULL ? TRUE : FALSE)
    {
        func_020a3320(data_020efcd4->unk_1000);
    }

    if (gSoundManager->unk_98 != NULL)
    {
        func_0209a3a0(gSoundManager->unk_98, param_1);
    }

    return;
}

EC BOOL func_02016304(s16);
EC BOOL func_020162ec(s16, s32);
EC BOOL func_0209b56c(void *);

EC BOOL func_02016250(s16 param_1)
{
    if (param_1 != 0x7fff)
    {
        if ((func_0209b56c(&gSoundManager->unk_ac->unk_04) != 0) && (param_1 == gSoundManager->unk_ac->unk_08))
        {
            return 1;
        }

        return 0;
    }

    if ((param_1 & 0xff) != 0)
    {
        return func_020162ec(param_1, -1);
    }

    return func_02016304(param_1);
}

EC BOOL func_020983d4(s32, s32);

EC BOOL func_020162ec(s16 arg_0, s32 arg_1)
{
    return func_020983d4(arg_0, arg_1) != 0;
}

EC BOOL func_02098380(s32);

EC BOOL func_02016304(s16 arg_0)
{
    return func_02098380(arg_0) != 0;
}

EC void func_0209ca20(void *, u32, u32);
EC void func_0209ca74(void);
EC void func_0209ca9c(u32);

EC void func_0201631c(u32 param_1)
{
    if (gSoundManager->unk_a0 && param_1 != gSoundManager->unk_9c)
    {
        if (data_020efcd4 != NULL ? TRUE : FALSE)
        {
            func_020a3320(data_020efcd4->unk_1000);
        }

        if (gSoundManager->unk_9c == 0)
        {
            func_0209ca20(data_020efce0, 0x1000, param_1);
        }
        else if (param_1 == 0)
        {
            func_0209ca74();
        }
        else
        {
            func_0209ca9c(param_1);
        }

        gSoundManager->unk_9c = param_1;
    }

    return;
}

// TODO: Is this an inline?
EC BOOL func_020163c0(void)
{
    return data_020efcd4 != NULL;
}

EC void SoundWaitTo_Loop(SoundWaitTo * proc)
{
    proc->Loop();
    return;
}

EC void SoundWaitTo::Loop(void)
{
    if (this->unk_3c->vfunc_58())
    {
        return;
    }

    this->unk_38->unk_18 = 0;

    switch (this->unk_40)
    {
        case 0:
            this->unk_38->vfunc_30(this->unk_44, this->unk_48, 0);
            break;

        case 1:
            this->unk_38->vfunc_4c(this->unk_48);
            break;

        case 2:
            this->unk_38->vfunc_38(0);
            break;

        case 3:
            break;
    }

    Proc_End(this);

    return;
}

EC void func_020164ac(SoundWaitTo *);

EC void func_02016490(void)
{
    Proc_ForEach(ProcScr_SoundWaitTo, (ProcFunc)func_020164ac);
}

EC void func_020164ac(SoundWaitTo * param_1)
{
    if (param_1->unk_38->unk_18 == 0)
    {
        return;
    }

    param_1->Loop();

    return;
}

EC void func_02098354(void *);

void SoundHandle::vfunc_24(void)
{
    func_02098354(&this->unk_04);

    this->unk_08 = -1;
    this->unk_0c = 0;

    return;
}

EC void func_0209a564(u32, u32, void *);
EC BOOL func_0209b000(void *, u32);
EC void func_020984c8(void *, u16, u32);

void SoundHandle::vfunc_00(u32 param_2, u32 param_3, u32 param_4)
{
    this->unk_0d = func_0209a474(gSoundManager->unk_94);
    func_0209a564(param_2, 3, gSoundManager->unk_94);
    this->unk_0e = func_0209a354(gSoundManager->unk_94);
    func_0209a564(param_2, 4, gSoundManager->unk_94);
    this->unk_0f = func_0209a354(gSoundManager->unk_94);

    if ((func_0209b000(&this->unk_04, param_2) & 0xFF) && param_4 != 0)
    {
        func_020984c8(&this->unk_04, 0xffff, param_4);
    }

    if (param_3 != 0)
    {
        this->vfunc_14(0, 0);
        this->vfunc_14(this->unk_10, param_3);
        return;
    }

    this->vfunc_14(this->unk_10, 0);

    return;
}

void SoundHandle::vfunc_18(u32 param_2, u32 param_3, u32 param_4)
{
    u32 uVar2;

    if (this->unk_0c != 1 || param_2 != this->unk_08)
    {
        if (this->unk_18 != NULL)
        {
            uVar2 = func_020a4a38();
            Proc_End(this->unk_18);
            func_020a4a4c(uVar2);
        }
        if (this->unk_0c != 0)
        {
            this->vfunc_1c();
        }

        this->unk_08 = param_2;
        this->unk_0c = 1;
        this->vfunc_00(param_2, param_3, param_4);
    }

    return;
}

EC BOOL func_0209b048(void *, u32, u32);

void SoundHandle::vfunc_04(u32 param_2, u32 param_3, u32 param_4, u32 param_5)
{
    if ((func_0209b048(&this->unk_04, param_2, param_3) & 0xFF) && param_5 != 0)
    {
        func_020984c8(&this->unk_04, 0xffff, param_5);
    }

    if (param_4 != 0)
    {
        this->vfunc_14(0, 0);
        this->vfunc_14(this->unk_10, param_4);
    }
    else
    {
        this->vfunc_14(this->unk_10, 0);
    }

    return;
}

extern struct UnkStruct_02196f24 * data_02196f24;

void SoundHandle::vfunc_28(u32 param_2, u32 param_3, u32 param_4)
{
    if (!gSoundManager->unk_a0)
    {
        return;
    }

    if (!data_02196f24->enableBgm)
    {
        return;
    }

    if (data_020efcd4 != NULL ? TRUE : FALSE)
    {
        func_020a3320(data_020efcd4->unk_1000);
    }

    if (!this->vfunc_58() && this->unk_0c == 1 && param_2 == this->unk_08)
    {
        func_02070570(4);

        if (this->unk_18 != NULL)
        {
            Proc_End(this->unk_18);
        }

        if (this->unk_0c != 0)
        {
            this->vfunc_38(0);
        }

        this->vfunc_00(param_2, param_3, param_4);

        this->unk_08 = param_2;
        this->unk_0c = 1;

        func_0207058c(4);
    }

    return;
}

EC u32 func_0201619c(char *);

void SoundHandle::vfunc_2c(char * param_2, u32 param_3, u32 param_4)
{
    u32 iVar1 = func_0201619c(param_2);

    if (iVar1 == -1)
    {
        return;
    }

    this->vfunc_28(iVar1, param_3, param_4);

    return;
}

EC void func_020169bc(UnkStruct_020efcd4 *);

void SoundHandle::vfunc_30(u32 param_2, u32 param_3, u32 param_4)
{
    UnkStruct_020efcd4 * iVar2;

    if (!gSoundManager->unk_a0)
    {
        return;
    }

    if (!data_02196f24->enableBgm)
    {
        return;
    }

    if (!this->vfunc_58() && this->unk_0c == 1 && param_2 == this->unk_08)
    {
        func_02070570(4);

        if (!(data_020efcd4 != NULL ? TRUE : FALSE))
        {
            if (this->unk_18 != NULL)
            {
                Proc_End(this->unk_18);
            }

            if (this->unk_0c != 0)
            {
                this->vfunc_38(0);
            }
        }

        iVar2 = new UnkStruct_020efcd4();

        iVar2->unk_10c0 = 0;
        iVar2->unk_10c4 = this;
        iVar2->unk_10c8 = param_2;
        iVar2->unk_10cc = param_3;
        iVar2->unk_10d0 = param_4;

        func_020a3080(iVar2->unk_1000, (void *)func_020169bc, iVar2, iVar2->unk_1000, 0x1000, 0x11);
        func_020a3754(iVar2->unk_1000, iVar2);
        func_020a374c(iVar2->unk_1000, func_02016004);

        if (data_020efcd4 == NULL)
        {
            data_020efcd0 = iVar2;
            data_020efcd4 = iVar2;
            func_020a341c(iVar2->unk_1000);
        }
        else
        {
            data_020efcd4->unk_10c0 = iVar2;
            data_020efcd4 = iVar2;
        }

        func_0207058c(4);
    }

    return;
}

EC void func_020169bc(UnkStruct_020efcd4 * param_1)
{
    param_1->unk_10c4->vfunc_18(param_1->unk_10c8, param_1->unk_10cc, param_1->unk_10d0);
    return;
}

void SoundHandle::vfunc_34(char * arg_0, u32 arg_1, u32 arg_2)
{
    s32 iVar1 = func_0201619c(arg_0);

    if (iVar1 == -1)
    {
        return;
    }

    this->vfunc_30(iVar1, arg_1, arg_2);

    return;
}

EC void func_02098334(void *, u32);

void SoundHandle::vfunc_08(void)
{
    func_02098334(&this->unk_04, 0);
    this->unk_08 = -1;
    return;
}

extern struct ProcCmd ProcScr_020ce750[];

void SoundHandle::vfunc_38(s32 param_2)
{
    if (!gSoundManager->unk_a0)
    {
        return;
    }

    if (data_020efcd4 != NULL ? TRUE : FALSE)
    {
        func_020a3320(data_020efcd4->unk_1000);
    }

    if (this->unk_18 != NULL)
    {
        this->unk_18->unk_40 = 2;
        this->unk_18->unk_44 = 0;
        this->unk_18->unk_48 = 0;
        return;
    }

    if (this->unk_0c == 0)
    {
        return;
    }

    if (this->unk_0c == 2)
    {
        param_2 = 0;
    }

    if (this->vfunc_58())
    {
        this->unk_14->unk_3c = 0;
        this->unk_14->unk_48 = -1;

        if (param_2 == 0)
        {
            Proc_End(this->unk_14);
            return;
        }

        if (param_2 < this->unk_14->unk_40)
        {
            this->unk_14->unk_40 = param_2;
            this->vfunc_14(0, param_2);
        }

        return;
    }

    new (Proc_Start(ProcScr_020ce750, PROC_TREE_5)) SoundFade(this, param_2, -1, 0);

    return;
}

void SoundHandle::vfunc_1c(void)
{
    u32 uVar1;
    s32 iVar2;
    SoundFade * pSVar3;

    if (!gSoundManager->unk_a0)
    {
        return;
    }

    if (this->unk_18 != NULL)
    {
        uVar1 = func_020a4a38();
        Proc_End(this->unk_18);
        func_020a4a4c(uVar1);
    }

    if (this->unk_0c == 0)
    {
        return;
    }

    if (this->vfunc_58())
    {
        this->unk_14->unk_3c = 0;

        uVar1 = func_020a4a38();

        Proc_End(this->unk_14);
        Proc_ForEach(ProcScr_SoundWaitTo, (ProcFunc)func_020164ac);

        func_020a4a4c(uVar1);

        return;
    }

    uVar1 = func_020a4a38();
    new (Proc_Start(ProcScr_020ce750, PROC_TREE_5)) SoundFade(this, 0, -1, 0);
    func_020a4a4c(uVar1);

    return;
}

void SoundHandle::vfunc_3c(s32 param_2, u32 param_3, u32 param_4)
{
    if (!gSoundManager->unk_a0)
    {
        return;
    }

    if (data_020efcd4 != NULL ? TRUE : FALSE)
    {
        func_020a3320(data_020efcd4->unk_1000);
    }

    if (this->unk_18 != NULL)
    {
        Proc_End(this->unk_18);
    }

    if (this->unk_0c == 0)
    {
        this->vfunc_30(param_3, param_4, 0);
        return;
    }

    if (this->vfunc_58())
    {
        this->unk_14->unk_3c = 0;
        this->unk_14->unk_48 = param_3;
        this->unk_14->unk_44 = param_4;

        if (param_2 == 0)
        {
            Proc_End(this->unk_14);
            return;
        }

        if (param_2 < this->unk_14->unk_40)
        {
            this->unk_14->unk_40 = param_2;
            this->vfunc_14(0, param_2);
        }
    }
    else
    {
        new (Proc_Start(ProcScr_020ce750, PROC_TREE_5)) SoundFade(this, param_2, param_3, param_4);
    }

    return;
}

void SoundHandle::vfunc_40(u32 param_2, char * param_3, u32 param_4)
{
    u32 iVar1 = func_0201619c(param_3);

    if (iVar1 != -1)
    {
        this->vfunc_3c(param_2, iVar1, param_4);
    }
    else
    {
        this->vfunc_38(param_2);
    }

    return;
}

EC void func_02098344(void *, u32);

void SoundHandle::vfunc_0c(void)
{
    func_02098344(&this->unk_04, 1);
    return;
}

void SoundHandle::vfunc_44(s32 param_2)
{
    if (!gSoundManager->unk_a0)
    {
        return;
    }

    if (data_020efcd4 != NULL ? TRUE : FALSE)
    {
        func_020a3320(data_020efcd4->unk_1000);
    }

    if (this->unk_18 != NULL)
    {
        if (this->unk_18->unk_40 <= 1 ? TRUE : FALSE)
        {
            this->unk_18->unk_40 = 3;
            this->unk_18->unk_44 = 0;
            this->unk_18->unk_48 = 0;
        }

        Proc_End(this->unk_18);
    }

    if (this->unk_0c != 1)
    {
        return;
    }

    if (this->vfunc_58())
    {
        if (this->unk_14->unk_3c != 0)
        {
            this->unk_14->unk_3c = 2;
        }

        if (param_2 == 0)
        {
            Proc_End(this->unk_14);
            return;
        }

        if (param_2 < this->unk_14->unk_40)
        {
            this->unk_14->unk_40 = param_2;
            this->vfunc_14(0, param_2);

            return;
        }
    }
    else
    {
        new (Proc_Start(ProcScr_020ce750, PROC_TREE_5)) SoundFade(this, param_2, -1, 0);
    }

    return;
}

void SoundHandle::vfunc_10(u32 param_2)
{
    this->unk_0e = func_0209a474(gSoundManager->unk_94);
    func_0209a564(this->unk_08, 4, gSoundManager->unk_94);

    this->unk_0f = func_0209a354(gSoundManager->unk_94);
    func_02098344(&this->unk_04, 0);

    this->unk_0c = 1;

    if (param_2 != 0)
    {
        this->vfunc_14(0, 0);
        this->vfunc_14(this->unk_10, param_2);
    }
    else
    {
        this->vfunc_14(this->unk_10, 0);
    }

    return;
}

void SoundHandle::vfunc_20(u32 param_2)
{
    u32 uVar1;

    if (this->unk_18 != NULL)
    {
        uVar1 = func_020a4a38();
        Proc_End(this->unk_18);
        func_020a4a4c(uVar1);
    }

    if (this->unk_0c == 2)
    {
        this->vfunc_10(param_2);
    }

    return;
}

void SoundHandle::vfunc_48(u32 param_2)
{
    if (data_020efcd4 != NULL ? TRUE : FALSE)
    {
        func_020a3320(data_020efcd4->unk_1000);
    }

    if (this->unk_18 != NULL)
    {
        Proc_End(this->unk_18);
    }

    if (this->unk_0c == 2)
    {
        this->vfunc_10(param_2);
    }

    return;
}

EC void func_02017258(UnkStruct_020efcd4 *);

void SoundHandle::vfunc_4c(s32 param_2)
{
    UnkStruct_020efcd4 * iVar1;

    if (!(data_020efcd4 != NULL ? TRUE : FALSE))
    {
        if (this->unk_18 != NULL)
        {
            Proc_End(this->unk_18);
        }

        if (this->unk_0c != 2)
        {
            return;
        }
    }

    iVar1 = new UnkStruct_020efcd4();

    iVar1->unk_10c0 = 0;
    iVar1->unk_10c4 = NULL;
    iVar1->unk_10c8 = (u32)this;
    iVar1->unk_10cc = 0;
    iVar1->unk_10d0 = 0;

    func_020a3080(iVar1->unk_1000, (void *)func_02017258, iVar1, iVar1->unk_1000, 0x1000, 0x11);
    func_020a3754(iVar1->unk_1000, iVar1);
    func_020a374c(iVar1->unk_1000, func_02016004);

    if (data_020efcd4 == NULL)
    {
        data_020efcd0 = iVar1;
        data_020efcd4 = iVar1;
        func_020a341c(iVar1->unk_1000);
        return;
    }

    data_020efcd4->unk_10c0 = iVar1;
    data_020efcd4 = iVar1;

    return;
}

EC void func_02017258(UnkStruct_020efcd4 * param_1)
{
    param_1->unk_10c4->vfunc_20(param_1->unk_10cc);
    return;
}

BOOL SoundHandle::vfunc_50(void)
{
    return this->unk_0c == 1;
}

BOOL SoundHandle::vfunc_54(void)
{
    return this->unk_0c == 2;
}

BOOL SoundHandle::vfunc_58(void)
{
    if (this->unk_14 != NULL)
    {
        return TRUE;
    }

    if ((this->unk_18 != NULL) && (this->unk_18->unk_40 == 2 ? TRUE : FALSE))
    {
        return TRUE;
    }

    return FALSE;
}

BOOL SoundHandle::vfunc_5c(void)
{
    if ((this->unk_14 != NULL) && (this->unk_14->unk_3c == 0 ? TRUE : FALSE))
    {
        return TRUE;
    }

    if ((this->unk_18 != NULL) && (this->unk_18->unk_40 == 2 ? TRUE : FALSE))
    {
        return TRUE;
    }

    return FALSE;
}

BOOL SoundHandle::vfunc_60(void)
{
    UnkStruct_020efcd4 * iVar2;
    BOOL uVar1;

    if ((this->unk_14 != NULL) && (this->unk_14->unk_48 != -1 ? TRUE : FALSE))
    {
        return TRUE;
    }

    if ((this->unk_18 != NULL) && (this->unk_18->unk_40 <= 1 ? TRUE : FALSE))
    {
        return TRUE;
    }

    if (!(data_020efcd4 != NULL ? TRUE : FALSE))
    {
        uVar1 = FALSE;
    }
    else if (this == data_020efcd0->unk_10c4)
    {
        uVar1 = TRUE;
    }
    else
    {
        for (iVar2 = data_020efcd0; iVar2 != NULL; iVar2 = iVar2->unk_10c0)
        {
            if (iVar2->unk_10c4 == this)
            {
                uVar1 = TRUE;
                break;
            }
        }
    }

    return uVar1 ? TRUE : FALSE;
}

EC void func_0209845c(void *, u32, u32);

void SoundHandle::vfunc_14(u32 arg_0, u32 arg_1)
{
    func_0209845c(&this->unk_04, arg_0, arg_1);
    return;
}

void SoundHandle::vfunc_64(u32 param_2, u32 unused)
{
    this->unk_10 = param_2;

    if (data_020efcd4 != NULL ? TRUE : FALSE)
    {
        func_020a3320(data_020efcd4->unk_1000);
    }

    if (this->unk_0c == 1)
    {
        if (!this->vfunc_58())
        {
            this->vfunc_14(this->unk_10, param_2);
        }
    }

    return;
}

void SoundHandle::vfunc_68(u32 param_2)
{
    this->unk_10 = 0x7f;

    if (data_020efcd4 != NULL ? TRUE : FALSE)
    {
        func_020a3320(data_020efcd4->unk_1000);
    }

    if (this->unk_0c == 1)
    {
        if (!this->vfunc_58())
        {
            this->vfunc_14(this->unk_10, param_2);
        }
    }

    return;
}

void SoundHandle::vfunc_6c(u32 param_2)
{
    this->unk_10 = param_2;
    return;
}

EC void StartSoundWaitTo_02017518(SoundHandle * param_1, SoundHandle * param_2, s32 param_3, s32 param_4, s32 param_5)
{
    SoundWaitTo * puVar2;
    SoundWaitTo * pSVar2;
    SoundFade * pSVar3;

    if (!gSoundManager->unk_a0)
    {
        return;
    }

    if (data_020efcd4 != NULL ? TRUE : FALSE)
    {
        func_020a3320(data_020efcd4->unk_1000);
    }

    if (param_1->unk_18 != NULL)
    {
        if ((param_1->unk_18->unk_3c == param_2) && (param_2->vfunc_58()))
        {
            pSVar3 = param_2->unk_14;
            pSVar3->unk_3c = 0;
            pSVar3->unk_48 = -1;
            pSVar3->unk_44 = 0;

            if (pSVar3->unk_40 > param_3)
            {
                pSVar3->unk_40 = param_3;
                pSVar3->unk_38->vfunc_14(0, param_3);
            }

            if (param_3 <= 0)
            {
                Proc_End(pSVar3);
            }

            pSVar2 = param_1->unk_18;
            pSVar2->unk_40 = 0;
            pSVar2->unk_44 = param_4;
            pSVar2->unk_48 = param_5;

            return;
        }

        Proc_End(param_1->unk_18);
    }

    if (param_2->vfunc_58())
    {
        pSVar3 = param_2->unk_14;
        pSVar3->unk_3c = 0;
        pSVar3->unk_48 = -1;
        pSVar3->unk_44 = 0;

        if (pSVar3->unk_40 > param_3)
        {
            pSVar3->unk_40 = param_3;
            pSVar3->unk_38->vfunc_14(0, param_3);
        }

        if (param_3 <= 0)
        {
            Proc_End(pSVar3);
        }
    }
    else
    {
        param_2->vfunc_44(param_3);
    }

    new (Proc_Start(ProcScr_SoundWaitTo, PROC_TREE_5)) SoundWaitTo(param_1, param_2, param_4, param_5);

    return;
}

EC void StartSoundWaitTo_0201775c(SoundHandle * param_1, SoundHandle * param_2, s32 param_3)
{
    s32 iVar1;
    SoundWaitTo * puVar2;
    SoundWaitTo * pSVar2;
    SoundFade * pSVar3;

    if (!gSoundManager->unk_a0)
    {
        return;
    }

    if (data_020efcd4 != NULL ? TRUE : FALSE)
    {
        func_020a3320(data_020efcd4->unk_1000);
    }

    if (param_1->unk_18 != NULL)
    {
        if ((param_1->unk_18->unk_3c == param_2) && (param_2->vfunc_58()))
        {
            pSVar3 = param_2->unk_14;
            pSVar3->unk_3c = 0;
            pSVar3->unk_48 = -1;
            pSVar3->unk_44 = 0;

            if (pSVar3->unk_40 > param_3)
            {
                pSVar3->unk_40 = param_3;
                pSVar3->unk_38->vfunc_14(0, param_3);
            }

            if (param_3 <= 0)
            {
                Proc_End(pSVar3);
            }

            pSVar2 = param_1->unk_18;
            pSVar2->unk_40 = 0;
            pSVar2->unk_44 = -1;
            pSVar2->unk_48 = 0;

            return;
        }

        Proc_End(param_1->unk_18);
    }

    param_2->vfunc_38(param_3);

    new (Proc_Start(ProcScr_SoundWaitTo, PROC_TREE_5)) SoundWaitTo(param_1, param_2, -1, 0);

    return;
}

EC void StartSoundWaitTo_02017938(SoundHandle * param_1, SoundHandle * param_2, u32 param_3, u32 param_4, u32 param_5)
{
    SoundWaitTo * pSVar2;
    SoundFade * pSVar3;

    if (!gSoundManager->unk_a0)
    {
        return;
    }

    if (param_2 == NULL || param_2 == param_1)
    {
        param_1->vfunc_38(param_3);
        return;
    }

    if (data_020efcd4 != NULL ? TRUE : FALSE)
    {
        func_020a3320(data_020efcd4->unk_1000);
    }

    if (param_1->unk_18 != NULL)
    {
        if ((param_1->unk_18->unk_3c == param_2) && param_2->vfunc_58())
        {
            pSVar3 = param_2->unk_14;
            pSVar3->unk_3c = 0;
            pSVar3->unk_48 = -1;
            pSVar3->unk_44 = 0;

            if (pSVar3->unk_40 > param_3)
            {
                pSVar3->unk_40 = param_3;
                pSVar3->unk_38->vfunc_14(0, param_3);
            }

            if (param_3 <= 0)
            {
                Proc_End(pSVar3);
            }

            pSVar2 = param_1->unk_18;
            pSVar2->unk_40 = 0;
            pSVar2->unk_44 = param_4;
            pSVar2->unk_48 = param_5;

            return;
        }

        Proc_End(param_1->unk_18);
    }

    param_2->vfunc_38(param_3);

    new (Proc_Start(ProcScr_SoundWaitTo, PROC_TREE_5)) SoundWaitTo(param_1, param_2, param_4, param_5);

    return;
}

EC void StartSoundWaitTo_02017b40(SoundHandle * param_1, SoundHandle * param_2, int param_3)
{
    SoundWaitTo * pSVar2;
    SoundFade * pSVar3;

    if (!gSoundManager->unk_a0)
    {
        return;
    }

    if (param_2 == NULL || param_2 == param_1)
    {
        param_1->vfunc_38(param_3);
        return;
    }

    if (data_020efcd4 != NULL ? TRUE : FALSE)
    {
        func_020a3320(data_020efcd4->unk_1000);
    }

    if (param_1->unk_18 != NULL)
    {
        if ((param_1->unk_18->unk_3c == param_2) && param_2->vfunc_58())
        {
            pSVar3 = param_2->unk_14;
            pSVar3->unk_3c = 0;
            pSVar3->unk_48 = -1;
            pSVar3->unk_44 = 0;

            if (pSVar3->unk_40 > param_3)
            {
                pSVar3->unk_40 = param_3;
                pSVar3->unk_38->vfunc_14(0, param_3);
            }

            if (param_3 <= 0)
            {
                Proc_End(pSVar3);
            }

            pSVar2 = param_1->unk_18;
            pSVar2->unk_40 = 2;
            pSVar2->unk_44 = -1;
            pSVar2->unk_48 = 0;

            return;
        }

        Proc_End(param_1->unk_18);
    }

    param_2->vfunc_38(param_3);

    new (Proc_Start(ProcScr_SoundWaitTo, PROC_TREE_5)) SoundWaitTo(param_1, param_2, -1, 0);

    return;
}

EC void func_0209b548(void *);

void SoundStrmHandle::vfunc_24(void)
{
    func_0209b548(&this->unk_04);

    this->unk_08 = -1;

    this->unk_0d = this->unk_0e = this->unk_0f = -1;

    return;
}

EC void func_0209b4d0(void *, u16, u32);

void SoundStrmHandle::vfunc_00(u32 param_2, u32 param_3, u32 param_4)
{
    func_0209b4d0(&this->unk_04, param_2, 0);
    return;
}

EC void func_0209b4f8(void *, u32);

void SoundStrmHandle::vfunc_08(void)
{
    func_0209b4f8(&this->unk_04, 0);
    this->unk_08 = -1;
    return;
}

EC void func_0209b514(void *, u32, u32);

void SoundStrmHandle::vfunc_14(u32 param_2, u32 param_3)
{
    func_0209b514(&this->unk_04, param_2, param_3);
    return;
}

void SoundSeHandle::vfunc_24(void)
{
    SoundHandle::vfunc_24();

    this->unk_0f = -1;
    this->unk_0e = -1;
    this->unk_0d = -1;

    return;
}

EC void func_02018014(UnkStruct_020efcd4 *);

void SoundSeHandle::vfunc_00(u32 param_2, u32 param_3, u32 param_4)
{
    UnkStruct_020efcd4 * iVar2;

    if ((((s32)param_2 >> 0x18) & 0xff))
    {
        if (gSoundManager->unk_98 == 0)
        {
            return;
        }

        iVar2 = new UnkStruct_020efcd4();

        iVar2->unk_10c0 = 0;
        iVar2->unk_10c4 = this;
        iVar2->unk_10c8 = param_2;
        iVar2->unk_10cc = param_3;
        iVar2->unk_10d0 = param_4;

        func_020a3080(iVar2->unk_1000, (void *)func_02018014, iVar2, iVar2->unk_1000, 0x1000, 0x11);
        func_020a3754(iVar2->unk_1000, iVar2);
        func_020a374c(iVar2->unk_1000, func_02016004);

        if (data_020efcd4 == NULL)
        {
            data_020efcd0 = iVar2;
            data_020efcd4 = iVar2;
            func_020a341c(iVar2->unk_1000);
        }
        else
        {
            data_020efcd4->unk_10c0 = iVar2;
            data_020efcd4 = iVar2;
        }
    }
    else
    {
        if ((((s32)param_2 >> 0x10) & 0xff))
        {
            iVar2 = new UnkStruct_020efcd4();

            iVar2->unk_10c0 = 0;
            iVar2->unk_10c4 = this;
            iVar2->unk_10c8 = param_2;
            iVar2->unk_10cc = param_3;
            iVar2->unk_10d0 = param_4;

            func_020a3080(iVar2->unk_1000, (void *)func_02018014, iVar2, iVar2->unk_1000, 0x1000, 0x11);
            func_020a3754(iVar2->unk_1000, iVar2);
            func_020a374c(iVar2->unk_1000, func_02016004);

            if (data_020efcd4 == NULL)
            {
                data_020efcd0 = iVar2;
                data_020efcd4 = iVar2;
                func_020a341c(iVar2->unk_1000);
            }
            else
            {
                data_020efcd4->unk_10c0 = iVar2;
                data_020efcd4 = iVar2;
            }
        }
        else
        {
            if (gSoundManager->unk_98 == 0)
            {
                return;
            }

            iVar2 = new UnkStruct_020efcd4();

            iVar2->unk_10c0 = 0;
            iVar2->unk_10c4 = this;
            iVar2->unk_10c8 = param_2;
            iVar2->unk_10cc = param_3;
            iVar2->unk_10d0 = param_4;

            func_020a3080(iVar2->unk_1000, (void *)func_02018014, iVar2, iVar2->unk_1000, 0x1000, 0x11);
            func_020a3754(iVar2->unk_1000, iVar2);
            func_020a374c(iVar2->unk_1000, func_02016004);

            if (data_020efcd4 == NULL)
            {
                data_020efcd0 = iVar2;
                data_020efcd4 = iVar2;
                func_020a341c(iVar2->unk_1000);
            }
            else
            {
                data_020efcd4->unk_10c0 = iVar2;
                data_020efcd4 = iVar2;
            }
        }
    }

    this->unk_0c = 1;

    return;
}

EC void StartSoundTemporarySe(SoundHandle *, s32, u32, u32);

EC void func_02018014(UnkStruct_020efcd4 * param_1)
{
    StartSoundTemporarySe(param_1->unk_10c4, param_1->unk_10c8, param_1->unk_10cc, param_1->unk_10d0);
    return;
}

void SoundSeHandle::vfunc_18(u32 param_2, u32 param_3, u32 param_4)
{
    this->vfunc_04((((s32)param_2 >> 0x10) & 0xff) - 1, param_2 & 0xffff, param_3, param_4);
    return;
}

extern struct UnkStruct_02196f0c * data_02196f0c;

EC void SoundSeHandle::vfunc_28(u32 param_2, u32 param_3, u32 param_4)
{
    if (!gSoundManager->unk_a0)
    {
        return;
    }

    if ((!data_02196f24->enableSoundEffects) && !(data_02196f0c->state & 0x2000000))
    {
        return;
    }

    func_02070570(4);
    this->vfunc_00(param_2, param_3, param_4);
    func_0207058c(4);

    return;
}

EC void SoundTemporarySe_Loop(SoundTemporarySe * proc)
{
    proc->Loop();
    return;
}

void SoundTemporarySe::Loop(void)
{
    u32 puVar2;

    if (data_020efccc == 0)
    {
        if (this->unk_40 != -1)
        {
            if (func_020983d4(this->unk_40, this->unk_44))
            {
                return;
            }
        }
        else
        {
            if (func_02098380(this->unk_44))
            {
                return;
            }
        }
    }

    puVar2 = func_0209a474(gSoundManager->unk_98);

    if (this->unk_3c == puVar2)
    {
        Proc_End(this);
    }

    return;
}

EC void func_02018184(void)
{
    data_020efccc = TRUE;
    Proc_ForEach(ProcScr_SoundTemporarySe, (ProcFunc)SoundTemporarySe_Loop);
    data_020efccc = FALSE;

    return;
}

EC void func_020181bc(void)
{
    Proc_ForEach(ProcScr_SoundTemporarySe, (ProcFunc)SoundTemporarySe_Loop);
    return;
}

EC void func_020181d8(void)
{
    func_020181bc();
    return;
}

EC void func_02018184(void);
EC BOOL func_0209a538(u32, void *);

EC void StartSoundTemporarySe(SoundHandle * param_1, s32 param_2, u32 param_3, u32 param_4)
{
    u8 cVar1;
    s32 iVar2;
    u32 uVar3;
    u32 puVar4;
    u32 uVar5;

    uVar5 = (param_2 >> 0x18) & 0xff;
    iVar2 = func_0209a474(gSoundManager->unk_98);

    if (uVar5 != 0)
    {
        cVar1 = func_0209a520(uVar5, gSoundManager->unk_98);
    }
    else
    {
        cVar1 = func_0209a538(param_2, gSoundManager->unk_98);
    }

    if (cVar1 == 0)
    {
        uVar3 = func_020a4a38();
        func_02018184();
        func_020a4a4c(uVar3);

        iVar2 = func_0209a474(gSoundManager->unk_98);

        if (uVar5 != 0)
        {
            func_0209a520(uVar5, gSoundManager->unk_98);
        }
        else
        {
            func_0209a538(param_2, gSoundManager->unk_98);
        }
    }

    puVar4 = func_0209a354(gSoundManager->unk_98);

    uVar3 = func_020a4a38();
    new (Proc_Start(ProcScr_SoundTemporarySe, PROC_TREE_5))
        SoundTemporarySe(param_1, param_2, param_3, param_4, iVar2, puVar4);
    func_020a4a4c(uVar3);

    return;
}

EC void StartVolumeDownPlayingSE(s32 param_1, s32 param_2)
{
    new (Proc_Start(ProcScr_020ce750, PROC_TREE_5)) VolumeDownPlayingSE(param_1, param_2);
    return;
}

EC void SoundVolumeMoveVC_Loop(SoundVolumeMoveVC * proc)
{
    proc->Loop();
    return;
}

void SoundVolumeMoveVC::Loop(void)
{
    s32 uVar2;
    s8 * pcVar3;

    this->unk_38++;

    uVar2 = Interpolate(0, this->unk_40, this->unk_44, this->unk_38, this->unk_3c);

    pcVar3 = data_020cc030;

    while (*pcVar3 != -1)
    {
        func_02098250(*pcVar3++, uVar2);
    }

    gSoundManager->unk_a1 = uVar2;

    if (this->unk_38 == this->unk_3c)
    {
        Proc_End(this);
    }

    return;
}

extern struct ProcCmd ProcScr_SoundVolumeMoveVC[];

EC void StartSoundVolumeMoveVC(u32 param_1, u32 param_2)
{
    s32 bVar1 = gSoundManager->unk_a1;
    new (Proc_Start(ProcScr_SoundVolumeMoveVC, PROC_TREE_5)) SoundVolumeMoveVC(param_1, param_2, bVar1);
    return;
}
