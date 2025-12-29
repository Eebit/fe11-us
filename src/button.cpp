#include "global.h"

#include <new>

#include "unknown_data.h"
#include "unknown_funcs.h"

#include "anime.hpp"
#include "hardware.hpp"
#include "heap.hpp"
#include "proc_ex.hpp"

extern u16 data_020ca6c4[];
extern u16 data_027e0010[];
extern u16 data_027e0038[];

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
    void func_02034d40(s32);
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

class ScrollMenu_unk_04
{
public:
    virtual s32 vfunc_00(void);
    virtual s32 vfunc_04(void);
};

class ScrollMenu_unk_08
{
public:
    s32 unk_00;
    s32 unk_04;
    s32 unk_08;
    s32 unk_0c;
    s32 unk_10;
    s32 unk_14;
    s32 unk_18;
    s32 unk_1c;
    s16 unk_20;
    s16 unk_22;

    ScrollMenu_unk_08(s32, s32); // func_020340f0
};

namespace menu
{
class ScrollMenu
{
public:
    /* 00 */ // vtable
    /* 04 */ ScrollMenu_unk_04 * unk_04;
    /* 08 */ ScrollMenu_unk_08 * unk_08;
    /* 0C */ u32 unk_0c;
    /* 10 */ Button * unk_10;
    /* 14 */ Button * unk_14;
    /* 18 */ ProcEx * unk_18;
    /* 1C */ u32 unk_1c;
    /* 20 */ u32 unk_20;
    /* 24 */ u32 unk_24;
    /* 28 */ u32 unk_28;
    /* 2C */ u32 unk_2c;
    /* 30 */ u32 unk_30;
    /* 34 */ u32 unk_34;
    /* 38 */ u32 unk_38;
    /* 3C */ u32 unk_3c;
    /* 40 */ u32 unk_40;
    /* 44 */ u32 unk_44;
    /* 48 */ u32 unk_48;
    /* 4C */ s8 unk_4c;
    /* 4D */ s8 unk_4d;
    /* 4E */ s8 unk_4e;
    /* 4F */ s8 unk_4f;
    /* 50 */ u16 unk_50;
    /* 52 */ u16 unk_52;
    /* 54 */ u16 unk_54;
    /* 56 */ u8 unk_56;
    /* 57 */ u8 unk_57;
    /* 58 */ s8 unk_58;
    STRUCT_PAD(0x59, 0x5C);
    /* 5C */ s8 unk_5c;
    /* 5D */ s8 unk_5d;
    /* 5E */ u8 unk_5e;
    /* 5F */ s8 unk_5f;
    STRUCT_PAD(0x60, 0x61);
    /* 61 */ u8 unk_61;
    /* 62 */ u8 unk_62;
    /* 63 */ u8 unk_63;
    STRUCT_PAD(0x64, 0x6A);
    /* 6A */ s16 unk_6a;
    STRUCT_PAD(0x6C, 0x7B);
    /* 7B */ u8 unk_7b;
    /* 7C */ u8 unk_7c;
    /* 7D */ s8 unk_7d;
    /* 7E */ u8 unk_7e;
    /* 7F */ u8 unk_7f;

    virtual void vfunc_00(/* ? */); // func_020336d4
    virtual void vfunc_04(/* ? */); // func_020337c8
    virtual void vfunc_08(/* ? */); // func_020338fc
    virtual void vfunc_0c(/* ? */); // func_02033990
    virtual void vfunc_10(/* ? */); // func_02003f84
    virtual void vfunc_14(/* ? */); // func_020316a4
    virtual void vfunc_18(/* ? */); // func_02032f14
    virtual s32 vfunc_1c(void); // func_02033b84
    virtual void vfunc_20(/* ? */); // func_02033b8c
    virtual void vfunc_24(/* ? */); // func_02033bd8
    virtual void vfunc_28(/* ? */); // func_02033d0c
    virtual void vfunc_2c(/* ? */); // func_02033df0
    virtual void vfunc_30(/* ? */); // func_02033dac
    virtual void vfunc_34(/* ? */); // func_02033e38
    virtual void vfunc_38(s32, s32, s32, s32, s32); // func_02033ec0
    virtual void vfunc_3c(/* ? */); // func_02033e7c
    virtual s32 vfunc_40(void); // func_02032ff8
    virtual void vfunc_44(/* ? */); // func_02033004
    virtual void vfunc_48(void); // func_02032ff4
    virtual void vfunc_4c(s32); // func_02003f80
    virtual s32 vfunc_50(void); // func_02032fc4
    virtual void vfunc_54(void); // func_02033c20
    virtual void vfunc_58(void); // func_02033d38
    virtual void vfunc_5c(/* ? */); // func_02031c6c
    virtual void vfunc_60(/* ? */); // func_02031ccc
    virtual void vfunc_64(/* ? */); // func_02031d74
    virtual void vfunc_68(/* ? */); // func_02031d2c
    virtual void vfunc_6c(s32); // func_02031dd4
    virtual void vfunc_70(/* ? */); // func_02031dec
    virtual void vfunc_74(/* ? */); // func_02003f60
    virtual void vfunc_78(/* ? */); // func_02003f68
    virtual void vfunc_7c(/* ? */); // func_02003f40
    virtual void vfunc_80(/* ? */); // func_02003f48
    virtual void vfunc_84(/* ? */); // func_02003f20
    virtual void vfunc_88(/* ? */); // func_02003f28
    virtual void vfunc_8c(/* ? */); // func_02003f18
    virtual void vfunc_90(/* ? */); // func_02003ef8
    virtual void vfunc_94(s32, s32); // func_02003f00
    virtual void vfunc_98(/* ? */); // func_02003ed8
    virtual void vfunc_9c(/* ? */); // func_02003ee0
    virtual void vfunc_a0(/* ? */); // func_02003ed0
    virtual void vfunc_a4(/* ? */); // func_02003ea0
    virtual void vfunc_a8(/* ? */); // func_02003e98
    virtual void vfunc_ac(/* ? */); // func_02003e90
    virtual void vfunc_b0(/* ? */); // func_02003e88
    virtual void vfunc_b4(/* ? */); // func_02003e80
    virtual void vfunc_b8(/* ? */); // func_02003e78
    virtual void vfunc_bc(/* ? */); // func_02003e70
    virtual void vfunc_c0(/* ? */); // func_02032800
    virtual void vfunc_c4(/* ? */); // func_0203288c
    virtual void vfunc_c8(/* ? */); // func_02032918
    virtual void vfunc_cc(/* ? */); // func_020329a4
    virtual void vfunc_d0(void); // func_02033aa4
    virtual void vfunc_d4(void); // func_02033b14
    virtual void vfunc_d8(/* ? */); // func_02032c00
    virtual void vfunc_dc(/* ? */); // func_02003e6c
    virtual void vfunc_e0(/* ? */); // func_02032e98
    virtual void vfunc_e4(/* ? */); // func_02031040
    virtual void vfunc_e8(void); // func_02033efc
    virtual void vfunc_ec(/* ? */); // func_02030fb4
    virtual void vfunc_f0(); // func_02031044

    ScrollMenu();
    void func_02031944();
};

class ScrollMenuItem
{
public:
    virtual s32 vfunc_00(void); // func_020340d8
    virtual void vfunc_04(/* ? */); // func_0205b454
    virtual void vfunc_08(/* ? */); // func_0205b464
    virtual void vfunc_0c(/* ? */); // func_0205b45c
    virtual void vfunc_10(/* ? */); // func_02034054
    virtual void vfunc_14(/* ? */); // func_0205b46c
    virtual void vfunc_18(/* ? */); // func_02031cc4
    virtual void vfunc_1c(/* ? */); // func_0205ae94
    virtual s32 vfunc_20(s32); // func_02031d24
    virtual s32 vfunc_24(s32, s32); // func_02031d0c
    virtual s32 vfunc_28(s32); // func_02031dcc
    virtual s32 vfunc_2c(s32, s32); // func_02031db4
    virtual void vfunc_30(/* ? */); // func_02031d6c
    virtual void vfunc_34(/* ? */); // func_0205af88
    virtual void vfunc_38(/* ? */); // func_0203127c
    virtual void vfunc_3c(/* ? */); // func_0205af00
    virtual void vfunc_40(/* ? */); // func_020311ec
    virtual void vfunc_44(/* ? */); // func_020327fc
    virtual void vfunc_48(/* ? */); // func_0205aef8
    virtual s32 vfunc_4c(s32, s32); // func_020340e0
};
}; // namespace menu

class ProcScrollMenu : public ProcEx
{
public:
    menu::ScrollMenu * unk_38;

    virtual ~ProcScrollMenu();
};

class ScrollMenuButton : public Button
{
public:
    menu::ScrollMenu * unk_6c;

    ScrollMenuButton(menu::ScrollMenu * pScrollMenu)
    {
        this->unk_6c = pScrollMenu;
    };

    virtual BOOL vfunc_10(void);
    virtual ~ScrollMenuButton();
};

// func_020317e8
menu::ScrollMenu::ScrollMenu()
{
    this->unk_18 = 0;
    this->unk_24 = 0x20;
    this->unk_28 = 0;
    this->unk_2c = 0;
    this->unk_30 = 1;
    this->unk_34 = 0;
    this->unk_38 = 0;
    this->unk_3c = 8;
    this->unk_40 = 1;
    this->unk_44 = 1;
    this->unk_48 = 2;
    this->unk_4c = -1;
    this->unk_4d = -1;
    this->unk_7b = 0;
    this->unk_7c = 0;
    this->unk_7d = 0;
    this->unk_50 = -1;
    this->unk_54 = 0;
    this->unk_52 = 0;
    this->unk_5f = 0;
    this->unk_63 = -1;
    this->unk_7e = 1;
    this->unk_7f = 1;
    this->unk_56 = 0;
    this->unk_57 = 0;
    this->unk_58 = 0;
    this->unk_08 = NULL;
    this->unk_0c = 0;
    this->unk_10 = NULL;
    this->unk_14 = NULL;
    this->unk_1c = 0;
    this->unk_20 = 0;
}

ProcScrollMenu::~ProcScrollMenu()
{
    if (this->unk_38 != NULL)
    {
        this->unk_38->vfunc_f0();
    }
}

BOOL Button::vfunc_18(void)
{
    return this->vfunc_10();
}

// #func_020347b0

// #func_020347f0

BOOL ScrollMenuButton::vfunc_10(void)
{
    menu::ScrollMenu * unk_6c = this->unk_6c;

    if (unk_6c->unk_7e == 0)
    {
        return 0;
    }

    if (unk_6c->unk_7f == 0)
    {
        return FALSE;
    }

    if (!IsProcLocked(reinterpret_cast<struct Proc *>(unk_6c->unk_18)))
    {
        return Button::vfunc_10();
    }

    return FALSE;
}

void Button::func_02034838(s32 param_2, s32 param_3, s32 param_4, u8 param_5, s32 param_6)
{
    this->xPos = 0;
    this->yPos = 0;
    this->unk_44 = 0;
    this->unk_46 = 0;
    this->unk_48 = 0;
    this->unk_4a = 0;
    this->unk_4c = param_3;
    this->unk_50 = param_4;
    this->unk_6a = param_6;

    if (param_5 != 0)
    {
        func_02034930(param_2, param_3, param_4);
    }

    this->func_02034d40(param_2);

    this->unk_69 = 0;
    this->unk_58 = 0;
    this->unk_64 = 0;
    this->unk_66 = 0;
    this->isVisible = FALSE;

    this->unk_38 = new Button_unk_38;

    this->func_020354a0();

    return;
}

EC void func_02034930(s32 param_1, s32 param_2, s32 param_3)
{
    func_020a8f40("/button");

    switch (param_1)
    {
        case 0:
            func_0201177c("a_menu.cg", ((u32)gpActiveScreenSt->bgTiles[4]) + param_2 * 0x20);
            break;
        case 1:
            func_0201177c("b_cancel.cg", ((u32)gpActiveScreenSt->bgTiles[4]) + param_2 * 0x20);
            break;
        case 2:
            func_0201177c("r_change.cg", ((u32)gpActiveScreenSt->bgTiles[4]) + param_2 * 0x20);
            break;
        case 3:
            func_0201177c("start_start.cg", ((u32)gpActiveScreenSt->bgTiles[4]) + param_2 * 0x20);
            break;
        case 4:
            func_0201177c("b_menu.cg", ((u32)gpActiveScreenSt->bgTiles[4]) + param_2 * 0x20);
            break;
        case 5:
            func_0201177c("b_end.cg", ((u32)gpActiveScreenSt->bgTiles[4]) + param_2 * 0x20);
            break;
        case 6:
            func_0201177c("a_decide.cg", ((u32)gpActiveScreenSt->bgTiles[4]) + param_2 * 0x20);
            break;
        case 7:
            func_0201177c("b_stop.cg", ((u32)gpActiveScreenSt->bgTiles[4]) + param_2 * 0x20);
            break;
        case 8:
            func_0201177c("a_start.cg", ((u32)gpActiveScreenSt->bgTiles[4]) + param_2 * 0x20);
            break;
        case 9:
            func_0201177c("select_random.cg", ((u32)gpActiveScreenSt->bgTiles[4]) + param_2 * 0x20);
            break;
        case 10:
            func_0201177c("start_end.cg", ((u32)gpActiveScreenSt->bgTiles[4]) + param_2 * 0x20);
            break;
        case 0xb:
            func_0201177c("x_danger.cg", ((u32)gpActiveScreenSt->bgTiles[4]) + param_2 * 0x20);
            break;
        case 0xc:
            func_0201177c("l_arrow.cg", ((u32)gpActiveScreenSt->bgTiles[4]) + param_2 * 0x20);
            break;
        case 0xd:
            func_0201177c("r_arrow.cg", ((u32)gpActiveScreenSt->bgTiles[4]) + param_2 * 0x20);
            break;
        case 0xe:
            func_0201177c("l_refine.cg", ((u32)gpActiveScreenSt->bgTiles[4]) + param_2 * 0x20);
            break;
        case 0xf:
            func_0201177c("r_refine.cg", ((u32)gpActiveScreenSt->bgTiles[4]) + param_2 * 0x20);
            break;
        case 0x10:
            func_0201177c("scrollerU.cg", ((u32)gpActiveScreenSt->bgTiles[4]) + param_2 * 0x20);
            break;
        case 0x11:
            func_0201177c("scrollerD.cg", ((u32)gpActiveScreenSt->bgTiles[4]) + param_2 * 0x20);
            break;
        case 0x12:
            func_0201177c("scrollerL.cg", ((u32)gpActiveScreenSt->bgTiles[4]) + param_2 * 0x20);
            break;
        case 0x13:
            func_0201177c("scrollerR.cg", ((u32)gpActiveScreenSt->bgTiles[4]) + param_2 * 0x20);
            break;
    }

    if (param_3 >= 0)
    {
        func_02034c44(param_1, param_3, 0);
    }

    return;
}

EC void func_02034c44(s32 param_1, s32 param_2, s32 param_3)
{
    if (param_3 != 0)
    {
        func_020a8f40("/button");
    }

    switch (param_1)
    {
        case 0:
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
        case 0xa:
        case 0xb:
            func_02011a70("button.cl", (param_2 + 0x10) * 0x20, 0, 0);
            return;

        case 0xc:
        case 0xd:
            func_02011a70("arrow.cl", (param_2 + 0x10) * 0x20, 0, 0);
            return;

        case 0xe:
        case 0xf:
            func_02011a70("refine.cl", (param_2 + 0x10) * 0x20, 0, 0);
            return;

        case 0x10:
        case 0x11:
        case 0x12:
        case 0x13:
            func_02011a70("scroller.cl", (param_2 + 0x10) * 0x20, 0, 0);
            return;
    }

    return;
}

void Button::func_02034d40(s32 param_2)
{
    char * animName;
    Anime * anime;

    switch (param_2)
    {
        case 0:
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
        case 0xa:
        case 0xb:
            this->unk_44 = 0x20;
            this->unk_46 = 0x18;
            this->unk_54 = data_020ca6c4;
            this->anime = NULL;

            switch (param_2)
            {
                case 2:
                case 0xb:
                    this->unk_48 = 7;
                    break;

                case 3:
                case 0xa:
                    this->unk_48 = 2;
                    break;
            }

            return;

        case 0xc:
        case 0xd:
            this->unk_44 = 0x20;
            this->unk_46 = 0x10;
            this->unk_54 = data_027e0010;
            this->anime = NULL;

            return;

        case 0xe:
        case 0xf:
            this->unk_44 = 0x10;
            this->unk_46 = 0x10;
            this->unk_54 = data_027e0038;
            this->anime = NULL;
            return;

        case 0x10:
        case 0x11:
        case 0x12:
        case 0x13:
            this->unk_44 = 0x10;
            this->unk_46 = 0x10;
            this->unk_54 = NULL;

            func_020a8f40("/button");

            animName = NULL;

            switch (param_2)
            {
                case 0x10:
                    animName = "scrollerU.anm";
                    break;

                case 0x11:
                    animName = "scrollerD.anm";
                    break;

                case 0x12:
                    animName = "scrollerL.anm";
                    break;

                case 0x13:
                    animName = "scrollerR.anm";
                    break;
            }

            anime = StartAnimByName(
                animName, 0, 0, 0,
                (this->unk_50 << 0xC) | ((this->unk_4c >> (gpActiveScreenSt->dispIo->dispcnt.mode)) & 0x3ff), 0, NULL);

            this->anime = anime;

            if (anime->interpreter == NULL)
            {
                return;
            }

            anime->interpreter->SetLoopingEnabled(TRUE);

            return;

        default:
            return;
    }
}

EC s32 func_02034f74(s32 param_1)
{
    switch (param_1)
    {
        case 0:
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
        case 0xa:
        case 0xb:
            return 0xc;

        case 0xc:
        case 0xd:
            return 8;

        case 0xe:
        case 0xf:
            return 4;

        case 0x10:
        case 0x11:
        case 0x12:
        case 0x13:
            return 0x10;

        default:
            return 0;
    }
}
void Button::func_02034ff8(void)
{
    if (((this->unk_38->unk_12 == 0 ? FALSE : TRUE) & 0xFF))
    {
        return;
    }

    func_0206d7c8(
        this->unk_38, this->xPos + this->unk_48, this->yPos + this->unk_4a, this->unk_44 - this->unk_48 * 2,
        this->unk_46 - this->unk_4a * 2, 0, this->unk_6a);

    return;
}

void Button::func_02035088(void)
{
    if (!((this->unk_38->unk_12 == 0 ? FALSE : TRUE) & 0xFF))
    {
        return;
    }

    func_0206d868(this->unk_38, 0);

    return;
}

void Button::func_020350b4(void)
{
    if (!((this->unk_38->unk_12 == 0 ? FALSE : TRUE) & 0xFF))
    {
        return;
    }

    func_0206d834(
        this->unk_38, 0, this->xPos + this->unk_48, this->yPos + this->unk_4a, this->unk_44 - this->unk_48 * 2,
        this->unk_46 - this->unk_4a * 2);

    return;
}

BOOL Button::vfunc_10(void)
{
    if (!((this->unk_38->unk_12 == 0 ? FALSE : TRUE) & 0xFF))
    {
        return FALSE;
    }

    return this->unk_38->unk_0c == 0;
}

void Button::vfunc_08(void)
{
    if (this->unk_64 < this->unk_66)
    {
        this->unk_64++;
        this->SetPosition(
            Interpolate(this->unk_68, this->unk_5c, this->unk_60, this->unk_64, this->unk_66),
            Interpolate(this->unk_68, this->unk_5e, this->unk_62, this->unk_64, this->unk_66));
    }

    if (this->unk_38 != NULL)
    {
        func_0206db20();

        if ((!(this->unk_38->unk_0b < 0) ? TRUE : FALSE) & 0xFF)
        {
            this->vfunc_14();
        }
    }

    return;
}

static inline u32 GetOam2Palette(u32 a)
{
    return (a << 0xc);
}

static inline u32 GetOam2Priority(u32 b)
{
    return (b << 0xa);
}

static inline u32 GetOam2Chr(u32 c)
{
    return (c & 0x3ff);
}

// NONMATCHING: https://decomp.me/scratch/04U8Z
void Button::vfunc_0c(void)
{
    s32 iVar2 = this->unk_50;

    if (this->vfunc_18() != 0)
    {
        iVar2++;
    }

    if ((this->unk_54 != NULL) && (!this->isVisible))
    {
        func_01ffc404(
            this->xPos & 0x1ff, this->yPos & 0xff,
            (GetOam2Palette(iVar2) | GetOam2Priority(this->unk_69) |
             GetOam2Chr((this->unk_4c >> gpActiveScreenSt->dispIo->dispcnt.bit_13_14))),
            this->unk_54, this->unk_58);
    }

    if (this->anime != NULL)
    {
        if (this->anime->interpreter != NULL)
        {
            this->anime->interpreter->SetUnk34(
                (u16)(GetOam2Palette(iVar2) | GetOam2Priority(this->unk_69) |
                      GetOam2Chr((this->unk_4c >> gpActiveScreenSt->dispIo->dispcnt.bit_13_14))));
        }
    }

    return;
}

void Button::SetPosition(s32 x, s32 y)
{
    this->xPos = x;
    this->yPos = y;

    this->func_020350b4();

    if (this->anime != NULL && this->anime->interpreter != NULL)
    {
        this->anime->interpreter->SetPosition((s16)x, (s16)y);
    }

    return;
}

void Button::SetVisible(BOOL isVisible)
{
    this->isVisible = isVisible;

    if (this->anime != NULL && this->anime->interpreter != NULL)
    {
        this->anime->interpreter->SetVisible(this->isVisible);
    }

    return;
}

BOOL Button::func_020353b8(void)
{
    return !(!((this->unk_38->unk_12 != 0) & 0xFF)) & 0xFF;
}

BOOL Button::func_020353e0(s32 param_2, s32 param_3)
{
    if ((param_2 < this->xPos + this->unk_48) || (param_2 >= (this->xPos + this->unk_44) - this->unk_48))
    {
        return FALSE;
    }

    if ((param_3 < this->yPos + this->unk_4a) || (param_3 >= (this->yPos + this->unk_46) - this->unk_4a))
    {
        return FALSE;
    }

    return TRUE;
}

void Button::vfunc_14(void)
{
    return;
}

BOOL Button::func_02035450(void)
{
    return (this->unk_38->unk_0b >= 0) & 0xFF;
}

void Button::func_0203546c(s32 param_2, s32 param_3, s32 param_4, s32 param_5)
{
    this->unk_5c = this->xPos;
    this->unk_5e = this->yPos;
    this->unk_60 = param_2;
    this->unk_62 = param_3;
    this->unk_64 = 0;
    this->unk_66 = param_4;
    this->unk_68 = param_5;

    return;
}

void Button::func_020354a0(void)
{
    this->func_02034ff8();
    this->SetVisible(FALSE);
    return;
}

void Button::func_020354bc(s32 param_2)
{
    this->func_02035088();

    if (param_2 == 0)
    {
        return;
    }

    this->SetVisible(TRUE);

    return;
}

extern struct ProcCmd ProcScr_020ce750[];

EC Button * StartButton(ProcPtr parent, s32 param_2, s32 param_3, s32 param_4, s32 param_5)
{
    Button * button;

    if (parent == NULL)
    {
        parent = PROC_TREE_6;
    }

    button = new (Proc_Start(ProcScr_020ce750, parent)) Button;
    button->func_02034838(param_2, param_3, param_4, 1, param_5);

    return button;
}
