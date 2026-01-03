#ifndef BUTTON_HPP
#define BUTTON_HPP

#include "global.h"

#include "anime.hpp"
#include "heap.hpp"

enum
{
    BUTTON_KIND_A_MENU = 0,
    BUTTON_KIND_B_CANCEL = 1,
    BUTTON_KIND_R_CHANGE = 2,
    BUTTON_KIND_START_START = 3,
    BUTTON_KIND_B_MENU = 4,
    BUTTON_KIND_B_END = 5,
    BUTTON_KIND_A_DECIDE = 6,
    BUTTON_KIND_B_STOP = 7,
    BUTTON_KIND_A_START = 8,
    BUTTON_KIND_SELECT_RANDOM = 9,
    BUTTON_KIND_START_END = 10,
    BUTTON_KIND_X_DANGER = 11,
    BUTTON_KIND_L_ARROW = 12,
    BUTTON_KIND_R_ARROW = 13,
    BUTTON_KIND_L_REFINE = 14,
    BUTTON_KIND_R_REFINE = 15,
    BUTTON_KIND_SCROLLER_UP = 16,
    BUTTON_KIND_SCROLLER_DOWN = 17,
    BUTTON_KIND_SCROLLER_LEFT = 18,
    BUTTON_KIND_SCROLLER_RIGHT = 19,
};

EC void func_020a5824(void * buf, int a, int b);

struct Button_unk_38
{
    /* 00 */ u32 unk_00;
    /* 04 */ u32 unk_04;
    /* 08 */ s8 unk_08;
    /* 09 */ s8 unk_09;
    /* 0A */ s8 unk_0a;
    /* 0B */ s8 unk_0b;
    /* 0C */ s8 unk_0c;
    /* 0D */ u8 unk_0d;
    /* 0E */ u8 unk_0e;
    /* 0F */ u8 unk_0f;
    /* 10 */ u16 unk_10;
    /* 12 */ u8 unk_12;
    /* 14 */ void * unk_14;
    /* 18 */ STRUCT_PAD(0x18, 0x24);

    Button_unk_38()
    {
        this->unk_10 = 1;
        this->unk_12 = 0;
        this->unk_00 = 0;
        this->unk_04 = 0;
        this->unk_08 = -1;
        this->unk_09 = -1;
        this->unk_0a = -1;
        this->unk_0b = -1;
        this->unk_0d = -1;
        this->unk_0c = 1;
        this->unk_0e = 0;
        this->unk_0f = -1;

        this->unk_14 = gHeap.Alloc(0xc);
        func_020a5824(this->unk_14, 0, 0xc);
    }

    ~Button_unk_38()
    {
        gHeap.Free(this->unk_14);
    }
};

EC void func_0206d834(struct Button_unk_38 *, s32, s16, s16, u16, u16);
EC void func_0206d868(struct Button_unk_38 *, s32);
EC void func_0206d7c8(struct Button_unk_38 *, s16, s16, u16, u16, s32, s32);
EC void func_0206db20(void);

class Button : public ProcEx
{
public:
    /* 38 */ struct Button_unk_38 * unk_38;
    /* 3C */ Anime * anime;
    /* 40 */ s16 xPos;
    /* 42 */ s16 yPos;
    /* 44 */ s16 unk_44;
    /* 46 */ s16 unk_46;
    /* 48 */ s16 unk_48;
    /* 4A */ s16 unk_4a;
    /* 4C */ s32 unk_4c;
    /* 50 */ s32 unk_50;
    /* 54 */ u16 * unk_54;
    /* 58 */ u32 unk_58;
    /* 5C */ s16 unk_5c;
    /* 5E */ s16 unk_5e;
    /* 60 */ s16 unk_60;
    /* 62 */ s16 unk_62;
    /* 64 */ s16 unk_64;
    /* 66 */ s16 unk_66;
    /* 68 */ u8 unk_68;
    /* 69 */ u8 unk_69;
    /* 6A */ u8 unk_6a;
    /* 6B */ u8 isVisible;

    Button()
    {
        this->unk_38 = NULL;
    }

    /* 08 */ virtual void vfunc_08(void);
    /* 0C */ virtual void vfunc_0c(void);
    /* 10 */ virtual BOOL vfunc_10(void);
    /* 14 */ virtual void vfunc_14(void);
    /* 18 */ virtual BOOL vfunc_18(void);

    virtual ~Button()
    {
        delete this->unk_38;
    }

    void func_02034838(s32, s32, s32, u8, s32);
    void func_02034d40(s32 kind);
    void func_02034ff8(void);
    void func_02035088(void);
    void func_020350b4(void);
    void SetPosition(s32, s32);
    void SetVisible(s32);
    BOOL func_020353b8(void);
    BOOL func_020353e0(s32, s32);
    BOOL func_02035450(void);
    void func_0203546c(s32, s32, s32, s32);
    void func_020354a0(void);
    void func_020354bc(s32);
};


EC Button * StartButton(ProcPtr parent, s32 kind, s32, s32, s32);

#endif // BUTTON_HPP