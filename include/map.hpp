#ifndef MAP_HPP
#define MAP_HPP

#include "global.h"

#include "heap.hpp"

class UnkStruct_021e334c
{
public:
    /* 00 */ STRUCT_PAD(0x00, 0x24);

    UnkStruct_021e334c();
    ~UnkStruct_021e334c();
};

extern struct UnkStruct_021e334c * data_ov000_021e334c;

class UnkStruct_021E3324
{
public:
    /* 00 */ u8 phase;
    /* 01 */ u8 unk_01;
    /* 02 */ u8 unk_02;
    /* 03 */ u8 unk_03;
    /* 04 */ u16 turn;
    /* 06 */ u16 unk_06;
    /* 08 */ u32 unk_08;
    /* 0C */ u32 unk_0c;
    /* 10 */ u32 unk_10;
    /* 14 */ u8 unk_14;
    /* 15 */ u8 unk_15;
    /* 16 */ u8 unk_16;
    /* 17 */ u8 unk_17;
    /* 18 */ u8 unk_18[4];
    /* 1C */ u8 unk_1c;

    UnkStruct_021E3324()
    {
            s32 j;

            this->phase = 0;
            this->unk_01 = 0;
            this->turn = 1;
            this->unk_06 = 0;
            this->unk_08 = 0;
            this->unk_0c = 0;
            this->unk_02 = 0;
            this->unk_03 = 0;
            this->unk_14 = 0x1f;
            this->unk_15 = 0x1f;
            this->unk_16 = 0x1f;

            for (j = 0; j < 4; j++)
            {
                this->unk_18[j] = 0;
            }

            this->unk_1c = 0;
    }
};

struct Vec3
{
    /* 00 */ s32 x;
    /* 04 */ s32 y;
    /* 08 */ s32 z;
};

class Camera
{
public:
    /* 00 */ s32 x; // camera x
    /* 04 */ s32 y; // camera y
    /* 08 */ s32 z; // camera z??
    /* 0C */ s16 tileSize;
    /* 0E */ s16 screenWidthTiles;
    /* 10 */ s16 screenHeightTiles;
    /* 12 */ s16 speed;
    /* 14 */ s16 xTarget; // next camera x?
    /* 16 */ s16 yTarget; // next camera y?
    /* 18 */ u8 state;
    /* 19 */ u8 unk_19;
    /* 1A */ u8 unk_1a;
    /* 1C */ s16 xStart;
    /* 1E */ s16 yStart;
    /* 20 */ u16 duration;
    /* 22 */ u16 timer;

    void Init(void);
    void SetGoalTile(s32, s32, BOOL);
    void SetGoalPx(s32, s32, BOOL);
    BOOL _021a4c30(s32, s32);
    void Scroll(s32, s32, s32, s32, u8);
    void ScrollEx(s32, s32, s32, s32, s32, u8);
    void ScrollInstant(s32, s32, s32);
    void Clamp(void);
    BOOL IsAtEdge(void);
    BOOL NeedsScroll(s32, s32, s32);
    void _021a4fb4(void);
    void _021a5030(s32);
    void Update(void);
    void StopScroll(void);
    BOOL _021a51b8(s32, s32, struct Vec3 *);
    BOOL _021a5228(s32, s32, struct Vec3 *);
    void ResetPos(void);
    void SetPos(s32, s32, s32);
    void AddPos(s32, s32, s32);
    BOOL _021a52f8(s32, s32, struct Vec3 *);

    inline BOOL IsMoving()
    {
        return this->state >= 2;
    }
};

class MapStateManager_04_04
{
public:
    STRUCT_PAD(0x00, 0x04);
    void * unk_04;
    STRUCT_PAD(0x04, 0x54);
    u16 unk_54;
    STRUCT_PAD(0x56, 0x5f);
    s8 unk_5f;
    s8 unk_60;
    u8 unk_61;

    void ClearValues()
    {
        this->unk_5f = 0;

        if (this->unk_61 != 0)
        {
            this->unk_61 = 0;
            this->unk_60 = -1;
        }
    }

    inline u8 Check_54(void)
    {
        return (!(this->unk_54 & 1)) & 0xFF;
    }
};

class MapStateManager_04
{
public:
    /* 00 */ struct Unit * unk_00;
    /* 04 */ struct MapStateManager_04_04 * unk_04;
    /* 08 */ u32 unk_08;

    MapStateManager_04()
    {
        this->unk_00 = 0;
        this->unk_04 = 0;
        this->unk_08 = 0;
    }
};

struct MapStateManager_08
{
    u8 unk_0000;
    STRUCT_PAD(0x0001, 0x0040);
    s8 unk_0040;
    s8 unk_0041;
    s8 unk_0042;
    s8 unk_0043;
    s8 unk_0044;
    s8 unk_0045;
    u8 unk_0046;
    u8 unk_0047;
    s8 unk_0048;
    STRUCT_PAD(0x0049, 0x0854);

    /* 0854 */ s8 * unk_0854;
    /* 0858 */ void * unk_0858;
    /* 085C */ void * unk_085c;
    /* 0860 */ void * unk_0860;

    STRUCT_PAD(0x0864, 0x086E);

    /* 086E */ u8 unk_086e;
    /* 086F */ u8 unk_086f;
    /* 0870 */ u8 unk_0870;
    /* 0871 */ u8 unk_0871;
    /* 0872 */ u8 unk_0872;
    /* 0873 */ u8 unk_0873;
    /* 0874 */ u8 unk_0874;

    STRUCT_PAD(0x0875, 0x0878);

    /* 0878 */ s8 unk_0878[0x400];
    /* 0C78 */ s8 unk_0c78[0x400];
    /* 1078 */ s8 unk_1078[0x80];
    /* 10F8 */ s8 unk_10f8[0x80];
};

class Button;

enum
{
    INPUT_TYPE_NONE = 0,
    INPUT_TYPE_KEY = 1,
    INPUT_TYPE_TOUCH = 2,
};

class InputHandler
{
public:
    /* 00 */ Button * buttons[4];
    /* 10 */ s16 xTouchPrev;
    /* 12 */ s16 yTouchPrev;
    /* 14 */ s16 xTouchCur;
    /* 16 */ s16 yTouchCur;
    /* 18 */ u16 keyHeld;
    /* 1A */ u16 keyRepeated;
    /* 1C */ u16 keyPressed;
    /* 1E */ u8 unk_1e;
    /* 1F */ u8 inputType;
    /* 20 */ u8 unk_20;
    /* 21 */ u8 unk_21_0 : 2;
    /* 21 */ u8 unk_21_2 : 2;
    /* 21 */ u8 unk_21_4 : 2;
    /* 21 */ u8 unk_21_6 : 2;
    /* 22 */ u8 buttonVisibilityMask;
    /* 23 */ u8 unk_23;
    /* 24 */ u8 unk_24;
    /* 25 */ u8 unk_25;
    /* 26 */ u8 unk_26;
    /* 27 */ s8 unk_27;

    void Init(void);
    void CreateButtons(void);
    void DestroyButtons(void);
    BOOL _021a5650(s32);
    void _021a5688(void);
    BOOL IsButtonVisible(u8);
    void SetButtonVisibility(s32);
    void HideButton(s32);
    void ShowButton(s32);
    void _021a5840(s32);
    void _021a585c(s32);
    BOOL _021a5abc(s32, s32, BOOL);
    BOOL _021a5c80(s32, s32);
    void _021a5d08(void);
    void _021a5d5c(s32);
    BOOL _021a63cc(s32, s32);
    void _021a6438(void);
    BOOL _021a6800(void);

    inline BOOL IsUsingKeyInputs(void)
    {
        return this->inputType == INPUT_TYPE_KEY;
    }

    inline u8 IsKeyPressed(s32 key)
    {
        return this->keyPressed & key ? TRUE : FALSE;
    }

    inline void SetValues(s32 a, s32 b, s32 c)
    {
        this->unk_23 = a;
        this->unk_21_0 = b;
        this->unk_21_4 = c;
    }
};

class Cursor
{
public:
    /* 00 */ s8 unk_00[2];
    /* 02 */ s8 unk_02[2];
    /* 04 */ s16 xDisplay; // in px
    /* 06 */ s16 yDisplay; // in px
    /* 08 */ u8 xTile;
    /* 09 */ u8 yTile;
    /* 0A */ u8 isVisible;
    /* 0B */ u8 unk_0b;
    /* 0C */ u8 changed;
    /* 0D */ u8 soundCooldownTimer;
    /* 0E */ u8 unk_0e;
    /* 0F */ STRUCT_PAD(0x0F, 0x12);
    /* 12 */ s16 xLerpStart;
    /* 14 */ s16 yLerpStart;
    /* 16 */ u16 lerpDuration;
    /* 18 */ u16 lerpElapsed;

    inline void SetUnk00And02(u8 phase, u8 r12, u8 r2)
    {
        this->unk_00[phase] = r12;
        this->unk_02[phase] = r2;
    }

    void Init(void);
    void SetPos(s32 x, s32 y, s32);
    void SetPosAnimated(s32 x, s32 y, s32, u8);
    void SetPosImmediate(s16, s16);
    void CenterOnCamera(void);
    void _021a6b4c(s32, s32);
    void _021a6bd0(void);
    void _021a6c38(void);
    void _021a6d48(void);
    void Update(void);
    BOOL _021a6ea8(s32);
};

class MapStateManager_14_00
{
public:
    STRUCT_PAD(0x00, 0x08);
    u16 unk_08;
    u16 unk_0a;
};

EC void func_ov000_021b9a1c(struct MapStateManager_14 *);

class MapStateManager_14_04
{
public:
    STRUCT_PAD(0x00, 0x10);
    u8 unk_10;
    STRUCT_PAD(0x11, 0x13);
    s8 unk_13;
    u8 unk_14;
    u8 unk_15;
    u8 unk_16;
    /* 17 */ u8 unk_17;
    /* 18 */ u8 unk_18;
    u8 unk_19;
    u8 unk_1a;

    inline void SetUnk14Unk16(s32 a, s32 b)
    {
        this->unk_14 = a;
        this->unk_16 = b;
    }
};

class MapStateManager_14
{
public:
    /* 00 */ MapStateManager_14_00 * unk_00;
    /* 04 */ MapStateManager_14_04 * unk_04;
    /* 08 */ u32 unk_08;
    /* 0C */ u32 unk_0c;
    /* 10 */ u32 unk_10;
    /* 14 */ u32 unk_14;
    /* 18 */ u32 unk_18;
    /* 1C */ u32 unk_1c;
    /* 20 */ u32 unk_20;
    /* 24 */ u8 unk_24;
    /* 25 */ s8 unk_25;
    /* 26 */ u8 unk_26;
    /* 27 */ u8 unk_27;
    /* 28 */ u8 unk_28;
    /* 29 */ u8 unk_29;
    /* 2A */ u8 unk_2a;
    /* 2B */ u8 unk_2b;
    /* 2C */ u32 unk_2c;

    MapStateManager_14()
    {
        this->unk_00 = 0;
        this->unk_04 = 0;
        this->unk_08 = 0;
        this->unk_0c = 0;
        this->unk_10 = 0;
        this->unk_14 = 0;
        this->unk_18 = 0;
        this->unk_1c = 0;
        this->unk_20 = 0;
        this->unk_25 = 0;
        this->unk_26 = 0;
        this->unk_29 = 0;
        this->unk_27 = 0;
        this->unk_28 = 0;
        this->unk_2c = 0;
    }

    ~MapStateManager_14()
    {
        func_ov000_021b9a1c(this);
    }
};

class MapStateManager_1C
{
public:
    /* 00 */ void * unk_00;
    /* 04 */ void * unk_04;
    /* 08 */ u32 unk_08;
    /* 0C */ u8 unk_0c;

    MapStateManager_1C()
    {
        void * ret = gHeap.Alloc(0x4000);
        this->unk_04 = ret;
        this->unk_00 = ret;
        this->unk_08 = 0x4000;
        this->unk_0c = 1;
    }

    ~MapStateManager_1C()
    {
        if (this->unk_0c != 0)
        {
            gHeap.Free(this->unk_00);
        }
    }
};

class MapStateManager
{
public:
    /* 000 */ Camera * camera;
    /* 004 */ struct MapStateManager_04 * unk_04;
    /* 008 */ struct MapStateManager_08 * unk_08;
    /* 00C */ InputHandler * inputHandler;
    /* 010 */ Cursor * cursor;
    /* 014 */ struct MapStateManager_14 * unk_14;
    /* 018 */ void * unk_18;
    /* 01C */ struct MapStateManager_1C * unk_1c;
    /* 020 */ u16 unk_20;
    /* 022 */ u16 unk_22;
    /* 024 */ u8 unk_24;
    /* 025 */ u8 unk_25;
    /* 026 */ u8 unk_26;
    /* 027 */ u8 unk_27;
    /* 028 */ u8 unk_028[0x400];
    /* 428 */ u8 unk_428[0x400];
    /* 828 */ u8 * unk_828;
    /* 82C */ u8 * unk_82c;
    /* 830 */ u8 unk_830[0x400];
    /* C30 */ u8 unk_c30[0x80];
    /* CB0 */ u8 unk_cb0[0x80];
    /* D30 */ u8 unk_d30[0x80];
    /* DB0 */ u8 unk_db0[0x80];
    /* E30 */ u8 unk_e30[0x80];
    /* EB0 */ s8 unk_eb0[4];
    /* EB4 */ s8 unk_eb4[4];
    /* EB8 */ u8 unk_eb8;
    /* EB9 */ STRUCT_PAD(0xEB9, 0xEBC);

    MapStateManager();
    ~MapStateManager();

    void func_ov000_021a276c(char *);
    void func_ov000_021a28cc();
    void func_ov000_021a2918();
    void func_ov000_021a29f4();

    u8 tst(s32 x, s32 y)
    {
        return this->unk_82c[x | y << 5] & 0x80;
    }
};

extern UnkStruct_021E3324 * data_ov000_021e3324;
extern MapStateManager * gMapStateManager;

#endif // MAP_HPP
