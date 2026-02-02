#include "global.h"

#include <new>

#include "hardware.hpp"
#include "heap.hpp"
#include "menu.hpp"
#include "sound_manager.hpp"

#include "unknown_funcs.h"

#include "constants/sounds.h"

extern struct KeyState * gKeySt;
extern struct TouchState * gTouchSt;

Menu::Menu(void)
{
    s32 i;

    this->unk_10 = NULL;
    this->unk_04 = 0;
    this->unk_14 = 0x20;
    this->unk_18 = 0;
    this->unk_1c = 0;
    this->unk_20 = 1;
    this->unk_24 = 0;
    this->unk_28 = 0;
    this->unk_2c = 1;
    this->unk_30 = 2;
    this->unk_34 = this->unk_35 = this->unk_36 = this->unk_37 = -1;
    this->unk_41 = 0;
    this->unk_42 = 0;
    this->unk_48 = 0;
    this->unk_3b = 0;
    this->unk_3c = 0;
    this->unk_3e = 0;
    this->unk_3f = 0;
    this->unk_40 = 0;
    this->unk_43 = 1;
    this->unk_44 = 1;
    this->unk_45 = 0;
    this->unk_46 = 0;
    this->unk_0c = 0;
    this->unk_38 = 0;
    this->unk_47 = 0;

    for (i = 0; i < 4; i++)
    {
        this->unk_4a[i] = -1;
    }

    return;
}

Menu::~Menu()
{
    if (this->unk_0c != NULL)
    {
        gHeap.Free(this->unk_0c);
    }
}

EC void ProcMenu_0202d618(ProcMenu * proc)
{
    proc->unk_38->vfunc_124();
    return;
}

EC void ProcMenu_0202d630(ProcMenu * proc)
{
    proc->unk_38->_0202f7d0();
    proc->unk_3c = 1;

    proc->unk_38->vfunc_dc();
    proc->unk_38->vfunc_e4();

    func_02018f54((struct Proc *)proc, 0);

    return;
}

EC void ProcMenu_0202d678(ProcMenu * proc)
{
    proc->unk_38->_0202f6d0();
    return;
}

EC void ProcMenu_0202d688(ProcMenu * proc)
{
    proc->unk_38->vfunc_e0();
    proc->unk_38->vfunc_d8();

    proc->unk_38->_0202f674();

    return;
}

EC void ProcMenu_0202d6bc(ProcMenu * proc)
{
    proc->unk_38->_0202f72c();
    return;
}

EC void ProcMenu_0202d6cc(ProcMenu * proc)
{
    proc->unk_38->vfunc_120();
    return;
}

EC void ProcMenu_0202d6e4(ProcMenu * proc)
{
    proc->unk_38->vfunc_11c();
    return;
}

void Menu::_0202d6fc(s32 param_2)
{
    this->unk_10->unk_38->vfunc_11c();

    this->unk_47 = 4;

    if (param_2 != 0)
    {
        this->vfunc_e8();
    }

    func_02018f54((struct Proc *)this->unk_10, (void *)ProcMenu_0202d6bc);

    this->unk_10->ProcMenu_0202d688();

    Proc_Goto(this->unk_10, 0, 0);

    return;
}

struct UnkStruct_021970c4
{
    void * unk_00;
    void * unk_04;
    void * unk_08;
};

extern struct UnkStruct_021970c4 * data_021970c4;
extern struct UnkStruct_021970c4 * data_021970cc;

s32 MenuItem::vfunc_ac(MenuItemState * param_2, s32 param_3, s32 param_4, s32 param_5, s32 param_6)
{
    s32 bVar1;
    s32 bVar2;
    ScreenState * pSVar3;
    s32 uVar6;

    bVar1 = param_2->unk_04;
    bVar2 = param_2->unk_05;
    uVar6 = 0;

    if (this->vfunc_04(param_2) != 0)
    {
        data_021970c4->unk_08 = (void *)((u32 *)(data_021970cc->unk_00))[this->vfunc_10(param_2)];

        pSVar3 = gpActiveScreenSt;

        if (param_6 != 0)
        {
            uVar6 = func_0202972c(
                data_021970c4, this->vfunc_04(param_2), pSVar3->bgTiles[param_3], pSVar3->tilemap[param_3], bVar1,
                bVar2, param_4, param_5, param_6, 0, 0);
        }
        else
        {
            uVar6 = func_020295ec(
                data_021970c4, this->vfunc_04(param_2), pSVar3->bgTiles[param_3], pSVar3->tilemap[param_3], bVar1,
                bVar2, param_4, param_5, 0, 0);
        }
    }

    return uVar6;
}

EC u32 func_02028e7c(UnkStruct_021970c4 *, char *, s32);

u32 MenuItem::vfunc_c8(MenuItemState * param_2)
{
    u32 uVar1 = this->vfunc_c4();

    if (uVar1 != -1)
    {
        return uVar1;
    }

    if (this->vfunc_04(param_2) != NULL)
    {
        return (func_02028e7c(data_021970c4, this->vfunc_04(param_2), 0) + 7 & ~7) / 8;
    }

    return 0;
}

s32 MenuItem::vfunc_10(MenuItemState * param_2)
{
    if ((param_2->unk_09 & 7) != 1)
    {
        return MENU_COLOR_WHITE;
    }

    return MENU_COLOR_GRAY;
}

void MenuItem::vfunc_b4(Menu * param_2, MenuItemState * param_3)
{
    param_2->vfunc_fc(param_3->unk_04, param_3->unk_05, param_3->unk_06, param_3->unk_07);
    gpActiveScreenSt->unk_3e |= (1 << param_2->unk_30);
    return;
}

void MenuItem::vfunc_b8(Menu * param_2, MenuItemState * param_3)
{
    param_2->vfunc_108(param_3->unk_04, param_3->unk_05, param_3->unk_06, param_3->unk_07);
    gpActiveScreenSt->unk_3e |= (1 << param_2->unk_30);
    return;
}

void MenuItem::vfunc_bc(Menu * param_2, MenuItemState * param_3)
{
    param_2->vfunc_100(param_3->unk_04, param_3->unk_05, param_3->unk_06, param_3->unk_07);
    gpActiveScreenSt->unk_3e |= (1 << param_2->unk_30);
    return;
}

void MenuItem::vfunc_c0(Menu * param_2, MenuItemState * param_3)
{
    param_2->vfunc_fc(param_3->unk_04, param_3->unk_05, param_3->unk_06, param_3->unk_07);
    gpActiveScreenSt->unk_3e |= (1 << param_2->unk_30);
    return;
}

EC BOOL func_0202dad0(MenuItemState * param_1, Menu * param_2)
{
    return (&param_2->unk_0c[param_2->unk_38] == param_1) & 0xff;
}

s32 Menu::vfunc_78(void)
{
    u32 uVar2;

    if (this->unk_3b == 0)
    {
        uVar2 = this->unk_0c[this->unk_38].unk_00->vfunc_24(this, &this->unk_0c[this->unk_38]);
        return this->vfunc_24(&this->unk_0c[this->unk_38], uVar2);
    }

    return 0;
}

s32 Menu::vfunc_7c(void)
{
    u32 uVar2;

    if (this->unk_3b == 0)
    {
        uVar2 = this->unk_0c[this->unk_38].unk_00->vfunc_30(this, &this->unk_0c[this->unk_38]);
        return this->vfunc_2c(&this->unk_0c[this->unk_38], uVar2);
    }

    return 0x800;
}

s32 Menu::vfunc_80(void)
{
    u32 uVar2;

    if (this->unk_3b == 0)
    {
        uVar2 = this->unk_0c[this->unk_38].unk_00->vfunc_3c(this, &this->unk_0c[this->unk_38]);
        return this->vfunc_34(&this->unk_0c[this->unk_38], uVar2);
    }

    return 0;
}

s32 Menu::vfunc_84(void)
{
    u32 uVar2;

    if (this->unk_3b == 0)
    {
        uVar2 = this->unk_0c[this->unk_38].unk_00->vfunc_48(this, &this->unk_0c[this->unk_38]);
        return this->vfunc_3c(&this->unk_0c[this->unk_38], uVar2);
    }

    return 0;
}

s32 Menu::vfunc_88(void)
{
    u32 uVar2;

    if (this->unk_3b == 0)
    {
        uVar2 = this->unk_0c[this->unk_38].unk_00->vfunc_54(this, &this->unk_0c[this->unk_38]);
        return this->vfunc_44(&this->unk_0c[this->unk_38], uVar2);
    }

    return 0;
}

s32 Menu::vfunc_8c(void)
{
    u32 uVar2;

    if (this->unk_3b != 0)
    {
        return this->vfunc_4c(&this->unk_0c[this->unk_38], 0x800);
    }

    uVar2 = this->unk_0c[this->unk_38].unk_00->vfunc_60(this, &this->unk_0c[this->unk_38]);
    return this->vfunc_4c(&this->unk_0c[this->unk_38], uVar2);
}

s32 Menu::vfunc_90(void)
{
    u32 uVar2;

    if (this->unk_3b == 0)
    {
        uVar2 = this->unk_0c[this->unk_38].unk_00->vfunc_6c(this, &this->unk_0c[this->unk_38]);
        return this->vfunc_54(&this->unk_0c[this->unk_38], uVar2);
    }

    return 0;
}

EC void func_0202fef8(Menu *);
EC void func_0202ff08(void);
EC void func_0202fe9c(Menu *, s32);
EC void func_0202febc(s32);

void Menu::vfunc_64(void)
{
    s32 r5;
    u32 action;
    s32 touchIndex;
    s32 prevTouchIndex;
    s32 i;

    action = 0;
    touchIndex = -1;
    prevTouchIndex = -1;

    this->unk_39 = this->unk_38;

    if (this->unk_43 == 0 || this->unk_43 > 1)
    {
        if (this->unk_43 > 1)
        {
            this->unk_43--;
            return;
        }

        this->unk_3c = 0;
        return;
    }

    if (this->vfunc_ac())
    {
        action = this->vfunc_60();
    }

    if (this->unk_44 != 0)
    {
        if (gTouchSt->unk_12 != 0 || gTouchSt->unk_15 != 0)
        {
            for (i = 0; i < this->unk_3a; i++)
            {
                MenuItemState * item = &this->unk_0c[i];

                if ((item->unk_09 & 7) == 3)
                {
                    continue;
                }

                if (!this->vfunc_b0(item, gTouchSt->unk_00, gTouchSt->unk_02))
                {
                    continue;
                }

                touchIndex = i;
                break;
            }

            if (gTouchSt->unk_14)
            {
                this->unk_3d = (u8)touchIndex;
                this->unk_3c = 1;
            }

            if (touchIndex != this->unk_3d)
            {
                this->unk_3c = 0;
            }

            if (this->unk_3c && touchIndex == -1 &&
                (!this->vfunc_94(gTouchSt->unk_00, gTouchSt->unk_02) ||
                 this->vfunc_98(gTouchSt->unk_00, gTouchSt->unk_02)))
            {
                this->unk_3c = 0;
            }

            if (touchIndex != -1)
                this->unk_38 = touchIndex;

            prevTouchIndex = touchIndex;

            if (gTouchSt->unk_15 == 0 && touchIndex != -1)
            {
                if (this->unk_3e == 0)
                {
                    this->unk_0c[this->unk_38].unk_00->vfunc_bc(this, &this->unk_0c[this->unk_38]);
                    this->unk_3e = 1;
                }
            }
            else if (this->unk_3e != 0)
            {
                this->unk_0c[this->unk_38].unk_00->vfunc_c0(this, &this->unk_0c[this->unk_38]);
                this->unk_3e = 0;
            }
        }
    }
    else
    {
        this->unk_3c = 0;

        if (gKeySt->repeated & KEY_DPAD_UP)
        {
            this->vfunc_68(((gKeySt->pressed & KEY_DPAD_UP) != 0) & 0xFF);
        }

        if (gKeySt->repeated & KEY_DPAD_DOWN)
        {
            this->vfunc_6c(((gKeySt->pressed & KEY_DPAD_DOWN) != 0) & 0xFF);
        }

        if (gKeySt->repeated & KEY_DPAD_LEFT)
        {
            this->vfunc_70(((gKeySt->pressed & KEY_DPAD_LEFT) != 0) & 0xFF);
        }

        if (gKeySt->repeated & KEY_DPAD_RIGHT)
        {
            this->vfunc_74(((gKeySt->pressed & KEY_DPAD_RIGHT) != 0) & 0xFF);
        }

        if (action == 0 && (gKeySt->repeated & KEY_DPAD_ANY))
        {
            action = this->vfunc_90();
        }
    }

    if (this->unk_39 != this->unk_38)
    {
        if (this->unk_3e)
        {
            this->unk_0c[this->unk_38].unk_00->vfunc_c0(this, &this->unk_0c[this->unk_38]);
            this->unk_3e = 0;
        }

        this->unk_0c[this->unk_39].unk_00->vfunc_b8(this, &this->unk_0c[this->unk_39]);
        this->unk_0c[this->unk_38].unk_00->vfunc_b4(this, &this->unk_0c[this->unk_38]);
        this->unk_0c[this->unk_39].unk_00->vfunc_84(this, &this->unk_0c[this->unk_39]);
        this->unk_0c[this->unk_38].unk_00->vfunc_78(this, &this->unk_0c[this->unk_38]);

        this->vfunc_bc();
    }

    if (this->unk_44 != 0)
    {
        if ((gTouchSt->unk_12 != 0) || (gTouchSt->unk_15 != 0))
        {
            if (gTouchSt->unk_15 != 0)
            {
                if (((gTouchSt->unk_10 < 30) ? TRUE : FALSE) && this->unk_3c != 0)
                {
                    if (touchIndex == this->unk_3d)
                    {
                        if (touchIndex == -1)
                        {
                            action = this->vfunc_7c();
                        }
                        else
                        {
                            action = this->vfunc_78();
                        }
                    }
                }
            }

            goto _0202e430;
        }
    }

    if (action == 0 && (gKeySt->pressed & KEY_BUTTON_A))
    {
        action = this->vfunc_78();
    }

    if (action == 0 && (gKeySt->pressed & KEY_BUTTON_B))
    {
        action = this->vfunc_7c();
    }

    if (action == 0 && (gKeySt->pressed & KEY_BUTTON_X))
    {
        action = this->vfunc_80();
    }

    if (action == 0 && (gKeySt->pressed & KEY_BUTTON_Y))
    {
        action = this->vfunc_84();
    }

    if (action == 0 && (gKeySt->pressed & KEY_BUTTON_L))
    {
        action = this->vfunc_88();
    }

    if (action == 0 && (gKeySt->pressed & KEY_BUTTON_R))
    {
        action = this->vfunc_8c();
    }

    if (action == 0 && (gKeySt->pressed & KEY_BUTTON_START))
    {
        action = this->vfunc_58(action);
    }

_0202e430:
    if (action == 0 && this->vfunc_9c())
    {
        action = this->vfunc_78();
    }

    if (action == 0 && this->vfunc_a0())
    {
        action = this->vfunc_7c();
    }

    if (action == 0 && this->vfunc_a4())
    {
        action = this->vfunc_8c();
    }

    if (action == 0 && this->vfunc_a8())
    {
        action = this->vfunc_58(action);
    }

    if (action & 0x40)
    {
        this->vfunc_c0();
    }
    else if (action & 0x80)
    {
        this->vfunc_c4();
    }
    else if (action & 0x100)
    {
        this->vfunc_c8();
    }

    if (action & 0x1000)
    {
        if (this->unk_10->proc_parent != NULL)
        {
            Proc_Lock((struct Proc *)this->unk_10->proc_parent);
        }
    }

    r5 = ((action & 0x2000) != 0) & 0xFF;

    if (action & 8)
    {
        func_0202fef8(this);
        return;
    }

    if (action & 0x10)
    {
        func_0202fef8(this->unk_04);
        return;
    }

    if (action & 0x20)
    {
        func_0202ff08();
        return;
    }

    if (action & 1)
    {
        func_0202fe9c(this, r5);
        return;
    }

    if (action & 2)
    {
        func_0202fe9c(this, r5);
        func_0202fe9c(this->unk_04, r5);
        return;
    }

    if (action & 4)
    {
        func_0202febc(r5);
        return;
    }
}

void Menu::vfunc_bc(void)
{
    gSoundManager->unk_b0->vfunc_28(SE_SYS_CURSOL2_WIN1, 0, 0);
    return;
}

void Menu::vfunc_c0(void)
{
    gSoundManager->unk_b0->vfunc_28(SE_SYS_SELECT1, 0, 0);
    return;
}

void Menu::vfunc_c4(void)
{
    gSoundManager->unk_b0->vfunc_28(SE_SYS_CANSEL1, 0, 0);
    return;
}

void Menu::vfunc_c8(void)
{
    gSoundManager->unk_b0->vfunc_28(SE_SYS_MISS1, 0, 0);
    return;
}

BOOL Menu::vfunc_b0(MenuItemState * arg1, s32 arg2, s32 arg3)
{
    if ((arg2 < ((arg1->unk_04 - 1) * 8)) || (arg2 >= ((arg1->unk_04 + arg1->unk_06 + 1) * 8)))
    {
        return FALSE;
    }

    if ((arg3 < (arg1->unk_05 * 8)) || (arg3 >= ((arg1->unk_05 + arg1->unk_07) * 8)))
    {
        return FALSE;
    }

    return TRUE;
}

BOOL Menu::vfunc_b4(void)
{
    s32 i;

    for (i = 0; i < this->unk_3a; i++)
    {
        if (this->vfunc_b0(&this->unk_0c[i], gTouchSt->unk_00, gTouchSt->unk_02))
        {
            return TRUE;
        }
    }

    return FALSE;
}

void Menu::vfunc_68(s32 param_2)
{
    MenuItemState * pMVar1;
    int iVar2;
    int iVar3;
    int iVar4;
    u32 uVar5;
    MenuItemState * pMVar6;

    iVar2 = IntSys_Div(this->unk_38, this->unk_48);

    uVar5 = this->unk_48;
    iVar2 = iVar2 * uVar5;
    if (this->unk_3a < (iVar2 + uVar5))
    {
        uVar5 = this->unk_3a - iVar2;
    }

    iVar3 = this->unk_38 - iVar2;

    while (TRUE)
    {
        if (iVar3 == 0)
        {
            if (param_2 != 0)
            {
                this->unk_3f = 1;
                iVar3 = uVar5 - 1;
            }
        }
        else
        {
            iVar3--;
        }

        if (iVar3 == 0)
        {
            for (pMVar6 = &this->unk_0c[iVar2]; (pMVar6->unk_09 & 7) == 3; pMVar6++)
            {
                iVar3++;
            }
        }

        if ((this->unk_0c[iVar2 + iVar3].unk_09 & 7) == 3)
        {
            break;
        }
    }

    this->unk_38 = iVar2 + iVar3;

    return;
}

void Menu::vfunc_6c(s32 param_2)
{
    s32 iVar2;
    s32 iVar3;
    s32 uVar5;
    MenuItemState * pMVar6;

    iVar2 = IntSys_Div(this->unk_38, this->unk_48);

    uVar5 = this->unk_48;
    iVar2 = iVar2 * uVar5;

    if ((iVar2 + uVar5) > this->unk_3a)
    {
        uVar5 = this->unk_3a - iVar2;
    }

    iVar3 = this->unk_38 - iVar2;

    while (TRUE)
    {
        if (iVar3 < (uVar5 - 1))
        {
            iVar3++;
        }
        else if (param_2 != 0)
        {
            this->unk_3f = 1;
            iVar3 = 0;
        }

        if (iVar3 >= (uVar5 - 1))
        {
            for (pMVar6 = &this->unk_0c[iVar2 + iVar3]; (pMVar6->unk_09 & 7) == 3; pMVar6--)
            {
                iVar3--;
            }
        }

        if ((this->unk_0c[iVar2 + iVar3].unk_09 & 7) != 3)
        {
            break;
        }
    }

    this->unk_38 = iVar2 + iVar3;

    return;
}

EC void func_020208b0(s32, s32, s32 *, s32 *);

EC void Menu::vfunc_70(s32 param_2)
{
    s32 iVar1;
    s32 acStack_14;
    s32 iStack_18;

    iVar1 = IntSys_Div(this->unk_3a + this->unk_48 - 1, this->unk_48);

    if (iVar1 != 0)
    {
        func_020208b0(this->unk_38, this->unk_48, &iStack_18, &acStack_14);

        if (iStack_18 != 0)
        {
            iStack_18--;
        }
        else
        {
            if (param_2 != 0)
            {
                iStack_18 = iVar1 - 1;
                this->unk_3f = 1;
            }
        }

        this->unk_38 = iStack_18 * this->unk_48 + acStack_14;
    }

    return;
}

EC void Menu::vfunc_74(s32 param_2)
{
    s32 iVar1;
    s32 acStack_14;
    s32 iStack_18;

    iVar1 = IntSys_Div(this->unk_3a + this->unk_48 - 1, this->unk_48);

    if (iVar1 != 0)
    {
        func_020208b0(this->unk_38, this->unk_48, &iStack_18, &acStack_14);

        if (iStack_18 < iVar1 - 1)
        {
            iStack_18++;
        }
        else if (param_2 != 0)
        {
            iStack_18 = 0;
            this->unk_3f = 1;
        }

        this->unk_38 = iStack_18 * this->unk_48 + acStack_14;
    }

    return;
}

void Menu::vfunc_d8(void)
{
    s32 iVar1;
    MenuItemState * pMVar2;
    s32 iVar3;
    s32 iVar4;

    iVar3 = this->unk_14;

    pMVar2 = this->unk_0c;

    for (iVar4 = 0; iVar4 < this->unk_3a; iVar4++)
    {
        if (this->unk_40 != 0)
        {
            iVar1 = (this->unk_36 - 2) * 8;
        }
        else
        {
            iVar1 = 0;
        }

        iVar1 = pMVar2->unk_00->vfunc_ac(pMVar2, this->unk_2c, iVar3, this->unk_18, iVar1);
        iVar3 = iVar3 + iVar1;
        pMVar2 = pMVar2 + 1;
    }

    data_021970c4->unk_08 = data_021970cc->unk_04;
    gpActiveScreenSt->unk_3e |= 1 << this->unk_2c;

    return;
}

EC void func_02010f98(u16 *, s32, s32);

void Menu::vfunc_dc(void)
{
    s32 i;
    s32 quotient;
    s32 iVar6;

    quotient = IntSys_Div(this->unk_3a + this->unk_48 - 1, this->unk_48);

    for (i = 0; i < quotient; i++)
    {
        if (i == 0)
        {
            iVar6 = this->unk_37;
        }
        else
        {
            iVar6 = this->unk_4a[i];
        }

        func_02010f98(
            (u16 *)(gpActiveScreenSt->tilemap[this->unk_2c]) + (this->unk_36 * i + this->unk_34 + 1) +
                ((this->unk_35 + 1) * 0x20),
            (u16)(this->unk_36 - 2), (u16)(iVar6 - 2));
    }

    gpActiveScreenSt->unk_3e |= 1 << this->unk_2c;

    return;
}

s32 Menu::vfunc_cc(void)
{
    return this->unk_47;
}

void Menu::vfunc_d0(s32 param_2)
{
    this->unk_47 = param_2;
    return;
}

s32 Menu::vfunc_d4(s32 index)
{
    s32 offset;

    if (index == -1)
    {
        index = this->unk_36;
    }

    if (index >= 8)
    {
        return (index * this->vfunc_cc()) >> 2;
    }

    offset = index - ((4 - this->vfunc_cc()) * 2);

    return MAX(offset, 0);
}

struct Idk
{
    s32 a;
    s32 b;
    s32 c;
    s32 d;
};
EC void func_0202a718(void *, s32, s32, struct Idk *);

void Menu::vfunc_f0(s32 arg1, s32 arg2, s32 arg3, s32 arg4)
{
    struct Idk sp;
    sp.a = arg4;
    sp.b = this->unk_1c;
    sp.c = this->unk_20;
    sp.d = this->unk_36;
    func_0202a718(gpActiveScreenSt->tilemap[this->unk_30], arg1, arg2, &sp);
}

void Menu::vfunc_e8(void)
{
    s32 bVar1;
    s32 iVar2;
    s32 iVar3;
    s32 iVar4;
    s32 iVar5;
    s32 iVar6;

    iVar2 = this->vfunc_d4(-1);

    iVar5 = (this->unk_36 >> 1) - (iVar2 >> 1);

    if (iVar2 >= 2)
    {
        iVar3 = IntSys_Div(this->unk_3a + this->unk_48 - 1, this->unk_48);

        for (iVar6 = 0; iVar6 < iVar3; iVar6++)
        {
            if (iVar6 == 0)
            {
                bVar1 = this->unk_37;
            }
            else
            {
                bVar1 = this->unk_4a[iVar6];
            }

            this->vfunc_f0(iVar5 + this->unk_36 * iVar6 + this->unk_34, this->unk_35, iVar2, bVar1);

            iVar4 = this->unk_38;

            if ((iVar4 >= (this->unk_48 * iVar6)) && (iVar4 < (this->unk_48 * (iVar6 + 1))))
            {
                MenuItemState * mis = &this->unk_0c[iVar4];
                this->vfunc_fc(
                    iVar5 + this->unk_36 * iVar6 + this->unk_34 + 1, mis->unk_05, iVar2 - 2, mis->unk_07);
            }
        }
    }

    gpActiveScreenSt->unk_3e |= 1 << this->unk_30;

    return;
}

EC void func_0202b260(void *, s32, s32, s32, s32);

void Menu::vfunc_f4(s32 param_2, s32 param_3, s32 param_4, s32 param_5)
{
    func_0202b260(gpActiveScreenSt->tilemap[this->unk_30], param_2, param_3, param_4, param_5);
    return;
}

void Menu::vfunc_ec(void)
{
    s32 r4;
    s32 bVar2;
    s32 r5;
    s32 r6;
    s32 r7;

    r5 = this->vfunc_d4(-1);

    r4 = ((this->unk_36 >> 1) - (r5 >> 1));

    r7 = IntSys_Div(this->unk_3a + this->unk_48 - 1, this->unk_48);

    for (r6 = 0; r6 < r7; r6++)
    {
        if (r6 == 0)
        {
            bVar2 = this->unk_37;
        }
        else
        {
            bVar2 = this->unk_4a[r6];
        }

        this->vfunc_f4(r4 + (this->unk_36 * r6 + this->unk_34), this->unk_35, r5, bVar2);
    }

    gpActiveScreenSt->unk_3e |= 1 << this->unk_30;

    return;
}

void Menu::vfunc_fc(s32 param_2, s32 param_3, s32 param_4, s32 param_5)
{
    this->vfunc_f8(gpActiveScreenSt->tilemap[this->unk_30], param_2, param_3, param_4, param_5);
    return;
}

EC void func_0202ad68(void *, s32, s32, s32, s32, s32, s32, s32, s32);

void Menu::vfunc_f8(void * param_2, s32 param_3, s32 param_4, s32 param_5, s32 param_6)
{
    func_0202ad68(param_2, param_3, param_4, param_5, param_6, this->unk_1c, this->unk_20, 0, 0);
    return;
}

EC void func_0202b014(void *, s32, s32, s32, s32);

void Menu::vfunc_100(s32 param_2, s32 param_3, s32 param_4, s32 param_5)
{
    func_0202b014(gpActiveScreenSt->tilemap[this->unk_30], param_2, param_3, param_4, param_5);
    return;
}

void Menu::vfunc_108(s32 param_2, s32 param_3, s32 param_4, s32 param_5)
{
    this->vfunc_104(gpActiveScreenSt->tilemap[this->unk_30], param_2, param_3, param_4, param_5);
    return;
}

EC void func_0202b1e4(void *, s32, s32, s32, s32, s32, s32);

void Menu::vfunc_104(void * param_2, s32 param_3, s32 param_4, s32 param_5, s32 param_6)
{
    func_0202b1e4(param_2, param_3, param_4, param_5, param_6, this->unk_1c, this->unk_20);
    return;
}

s32 Menu::vfunc_10c(void)
{
    return this->unk_10->proc_lockCnt;
}

void Menu::vfunc_110(void)
{
    this->_0202f040(0, 0, 0);
}

void Menu::_0202f020(s32 param_2, s32 param_3)
{
    this->_0202f040(param_2, param_3, 1);
}

void Menu::_0202f030(s32 param_2, s32 param_3)
{
    this->_0202f040(param_2, param_3, 2);
}

EC void func_0202b538(u16, u16, u32, u32);
EC void func_0202b624(u16, u16, u32, u32);
EC void func_0202b31c(u16, u16, u32, u32);

void Menu::_0202f040(s32 param_2, s32 param_3, s32 param_4)
{
    s32 sVar1;
    s32 sVar2;
    s32 a;
    s32 r3;
    u32 bVar3;
    u32 bVar4;
    u32 bVar5;
    s32 iVar6;
    s32 iVar7;
    MenuItemState * pMVar8;
    MenuItemState * pMVar9;
    s32 iVar10;
    s32 iVar11;

    switch (param_4)
    {
        case 0:
            iVar10 = param_3 - 8;
            break;

        case 1:
            iVar10 = param_3 - 0x20;
            break;

        case 2:
            iVar10 = param_3 - 0x18;
            break;
    }

    pMVar8 = this->unk_0c;
    bVar3 = pMVar8[this->unk_39].unk_04;
    iVar6 = pMVar8[this->unk_39].unk_00->vfunc_cc();

    pMVar9 = this->unk_0c;
    bVar4 = pMVar8[this->unk_39].unk_05;
    iVar11 = pMVar9[this->unk_38].unk_04 * 8;
    iVar7 = pMVar9[this->unk_38].unk_00->vfunc_cc();
    iVar7 = iVar7 * 4 + pMVar9[this->unk_38].unk_05 * 8;

    if (this->unk_3f == 0)
    {
        iVar11 = iVar11 + ((bVar3 * 8 + bVar5 * -8) >> 1);
        iVar7 = iVar7 + (((iVar6 * 4 + bVar4 * 8) - iVar7) >> 1);
    }

    iVar11 = param_2 - 0x10 + iVar11;
    iVar10 = iVar10 + iVar7;

    a = this->vfunc_10c();

    switch (param_4)
    {
        case 0:
            r3 = a ? this->unk_42 + 1 : this->unk_42;
            func_0202b31c(
                iVar11, iVar10,
                (this->unk_28 << 0xc) | (this->unk_41 << 0x1e) >> 0x14 |
                    (this->unk_24 >> gpActiveScreenSt->dispIo->dispcnt.bit_13_14) & 0x3ffU,
                r3);
            break;

        case 1:
            r3 = a ? this->unk_42 + 1 : this->unk_42;
            func_0202b538(
                iVar11, iVar10,
                (this->unk_28 << 0xc) | (this->unk_41 << 0x1e) >> 0x14 |
                    (this->unk_24 >> gpActiveScreenSt->dispIo->dispcnt.bit_13_14) & 0x3ffU,
                r3);
            break;

        case 2:
            r3 = a ? this->unk_42 + 1 : this->unk_42;
            func_0202b624(
                iVar11, iVar10,
                (this->unk_28 << 0xc) | (this->unk_41 << 0x1e) >> 0x14 |
                    (this->unk_24 >> gpActiveScreenSt->dispIo->dispcnt.bit_13_14) & 0x3ffU,
                r3);
            break;
    }

    return;
}

void Menu::vfunc_118(void)
{
    return;
}

EC void Menu::vfunc_08(void)
{
    s32 iVar1;
    s32 iVar2;
    s32 iVar3;
    MenuItemState * pMVar4;

    iVar1 = 0;
    iVar2 = iVar1;
    for (pMVar4 = this->unk_0c, iVar3 = 0; iVar3 < this->unk_3a; iVar3++, pMVar4++)
    {
        pMVar4->unk_04 = 1;

        iVar1 = pMVar4->unk_00->vfunc_c8(pMVar4);

        if (iVar1 <= iVar2)
        {
            iVar1 = iVar2;
        }

        iVar2 = iVar1;
    }

    if (this->unk_36 == -1)
    {
        this->unk_36 = iVar1 + 2;
    }

    for (pMVar4 = this->unk_0c, iVar3 = 0; iVar1 < this->unk_3a; iVar3++, pMVar4++)
    {
        pMVar4->unk_06 = this->unk_36 - 2;
    }

    return;
}

void Menu::vfunc_0c(void)
{
    u32 bVar1;
    s32 cVar2;
    MenuItemState * pMVar3;
    s32 cVar4;
    s32 i;
    u32 uVar6;
    s32 iVar7;

    cVar2 = 0;
    cVar4 = 0;
    iVar7 = 0;
    uVar6 = 0;

    for (i = 0, pMVar3 = this->unk_0c; i < this->unk_3a; i++, pMVar3++)
    {
        if (uVar6 == 0)
        {
            cVar2 = 0;
        }

        pMVar3->unk_05 = cVar2 + 1;

        bVar1 = pMVar3->unk_00->vfunc_cc();

        pMVar3->unk_07 = bVar1;
        cVar4 = cVar2 + bVar1;

        if (uVar6 != this->unk_48 - 1)
        {
            cVar4 = cVar4 + pMVar3->unk_00->vfunc_d0();
        }

        uVar6 = uVar6 + 1;

        if (uVar6 == this->unk_48)
        {
            if (iVar7 == 0)
            {
                if (this->unk_37 == -1)
                {
                    this->unk_37 = cVar4 + 2;
                }
            }
            else if (this->unk_4a[iVar7] == -1)
            {
                this->unk_4a[iVar7] = cVar4 + 2;
            }

            uVar6 = 0;
            iVar7 = iVar7 + 1;
        }
    }

    if (uVar6 == 0)
    {
        return;
    }

    if (iVar7 == 0)
    {
        if (this->unk_37 == -1)
        {
            this->unk_37 = cVar4 + 2;
        }

        return;
    }

    if (this->unk_4a[iVar7] == -1)
    {
        this->unk_4a[iVar7] = cVar4 + 2;
    }

    return;
}

void Menu::vfunc_10(void)
{
    this->vfunc_08();
    this->vfunc_0c();

    return;
}

EC void Menu::vfunc_14(void)
{
    s32 iVar1;

    if (this->unk_34 == -1)
    {
        iVar1 = IntSys_Div(this->unk_3a + this->unk_48 - 1, this->unk_48);
        this->unk_34 = ((u32)(0x20 - ((this->unk_36 * iVar1 + 1) & ~1)) >> 1);
    }

    if (this->unk_35 == -1)
    {
        this->unk_35 = ((u32)(0x18 - ((this->unk_37 + 1) & ~1)) >> 1);
    }

    return;
}

void Menu::vfunc_18(void)
{
    MenuItemState * pMVar1;
    s32 i;
    u32 uVar3 = 0;
    u32 cVar4 = 0;

    for (i = 0, pMVar1 = this->unk_0c; i < this->unk_3a; i++, pMVar1++)
    {
        uVar3++;

        pMVar1->unk_04 = this->unk_36 * cVar4 + this->unk_34 + pMVar1->unk_04;
        pMVar1->unk_05 = this->unk_35 + pMVar1->unk_05;

        if (uVar3 == this->unk_48)
        {
            uVar3 = 0;
            cVar4++;
        }
    }

    return;
}

void Menu::vfunc_1c(void)
{
    this->vfunc_10();
    this->vfunc_14();
    this->vfunc_18();

    return;
}

void Menu::vfunc_11c(void)
{
    s32 i;

    for (i = 0; i < this->unk_3a; i++)
    {
        this->unk_0c[i].unk_00->vfunc_90(this, &this->unk_0c[i]);
    }

    return;
}

void Menu::vfunc_120(void)
{
    this->vfunc_ec();

    if (++this->unk_47 > 4)
    {
        this->unk_47 = 4;
    }

    this->vfunc_e8();
    this->vfunc_b8(this->unk_47);

    if (this->unk_47 == 4)
    {
        Proc_Break(this->unk_10, 1);
    }

    return;
}

EC void func_0202fc30(Menu * param_1, s32 param_2, s32 param_3);

void Menu::_0202f674(void)
{
    this->unk_0c[this->unk_38].unk_00->vfunc_b0(this, &this->unk_0c[this->unk_38]);
    this->unk_0c[this->unk_38].unk_00->vfunc_78(this, &this->unk_0c[this->unk_38]);
    return;
}

void Menu::_0202f6d0(void)
{
    if (this->unk_45 != 0)
    {
        func_0202fc30(this, 0, 1);
    }

    this->vfunc_64();

    this->unk_0c[this->unk_38].unk_00->vfunc_9c(this, &this->unk_0c[this->unk_38]);

    return;
}

void Menu::_0202f72c(void)
{
    MenuItemState * pMVar1;
    s32 iVar2;

    if (this->unk_45 != 0)
    {
        func_0202fc30(this, 0, 1);
    }

    this->vfunc_110();
    this->vfunc_118();
    this->vfunc_114();

    for (pMVar1 = this->unk_0c, iVar2 = 0; iVar2 < this->unk_3a; iVar2++, pMVar1++)
    {
        pMVar1->unk_00->vfunc_a8(this, pMVar1);
    }

    this->unk_39 = this->unk_38;
    this->unk_3f = 0;

    return;
}

void Menu::_0202f7d0(void)
{
    this->unk_0c[this->unk_38].unk_00->vfunc_84(this, &this->unk_0c[this->unk_38]);
    return;
}

void Menu::vfunc_124(void)
{
    this->vfunc_ec();

    this->unk_47--;

    this->vfunc_e8();

    this->vfunc_b8(this->unk_47);

    if (this->unk_47 == 0)
    {
        Proc_Break(this->unk_10, 1);
    }

    return;
}

s32 Menu::_0202f860(void)
{
    MenuItem * piVar1;

    MenuItem ** piVar3 = this->unk_08;
    s32 iVar4 = 0;

    for (piVar1 = *piVar3; piVar1 != NULL; piVar1 = *++piVar3)
    {
        iVar4 += piVar1->vfunc_d4();
    }

    return iVar4;
}

void Menu::vfunc_12c(void)
{
    this->unk_0c = static_cast<MenuItemState *>(gHeap.Alloc(this->_0202f860() * sizeof(MenuItemState)));
    return;
}

void Menu::_0202f8c4(void)
{
    MenuItem * piVar1;
    MenuItem ** piVar4;
    s32 iVar5;
    s32 iVar6;
    s32 i;
    s32 iVar2;
    s32 uVar11;

    piVar4 = this->unk_08;

    if (this->unk_0c == NULL)
    {
        this->vfunc_12c();
    }

    iVar6 = 0;
    iVar5 = 0;

    this->unk_48 = this->unk_49;

    for (piVar1 = *piVar4; piVar1 != NULL; piVar1 = *++piVar4)
    {
        iVar2 = (*piVar4)->vfunc_d4();

        for (i = 0; i < iVar2; i++)
        {
            uVar11 = (*piVar4)->vfunc_18(iVar5);

            if (!(iVar6 == 0 && this->unk_46 == 0 && (uVar11 & 7) == 3) && (uVar11 & 7) != 2)
            {
                this->unk_0c[i].unk_00 = *piVar4;

                this->unk_0c[i].unk_09 = uVar11;
                this->unk_0c[i].unk_08 = iVar5;

                if (this->unk_38 == iVar5 && uVar11 == 3)
                {
                    this->unk_38++;
                }
                else if ((uVar11 & 8) != 0)
                {
                    this->unk_38 = iVar6;
                }

                iVar6++;
            }

            iVar5++;
        }
    }

    if (this->unk_38 >= iVar6)
    {
        this->unk_38 = iVar6 - 1;
    }

    this->unk_3a = iVar6;

    if ((this->unk_48 == 0) || (this->unk_48 >= this->unk_3a))
    {
        this->unk_48 = this->unk_3a;
    }

    this->vfunc_1c();

    this->unk_39 = this->unk_38;

    return;
}

EC void func_0202a5e0(void *, s32, s32);

void Menu::vfunc_128(void)
{
    func_0202a4dc(this->unk_18, 0);
    func_0202a5e0(gpActiveScreenSt->bgTiles[this->unk_30], this->unk_1c, this->unk_20);
    func_0202b294((void *)gpActiveScreenSt->objVram, this->unk_24, this->unk_28);
    return;
}

// clang-format off

struct ProcCmd ProcScr_ProcMenu[] =
{
    PROC_NAME,
    PROC_SLEEP(0),

    PROC_CALL(ProcMenu_0202d6e4),
    PROC_REPEAT(ProcMenu_0202d6cc),
    PROC_06(0, ProcMenu_0202d6bc),
    PROC_CALL(ProcMenu_0202d688),

PROC_LABEL(0),
    PROC_REPEAT(ProcMenu_0202d678),

PROC_LABEL(1),
    PROC_CALL(ProcMenu_0202d630),
    PROC_REPEAT(ProcMenu_0202d618),

    PROC_END,
};

// clang-format on

EC void StartMenu(Menu * param_1, MenuItem ** param_2, s32 param_3)
{
    param_1->unk_08 = param_2;

    param_1->vfunc_00();

    if (param_3 != 0)
    {
        param_1->vfunc_128();
    }

    param_1->unk_49 = param_1->unk_48;

    param_1->_0202f8c4();

    param_1->vfunc_04();

    if (param_1->unk_04 != NULL)
    {
        param_1->unk_10 = new (Proc_StartBlocking(ProcScr_ProcMenu, param_1->unk_04->unk_10)) ProcMenu(param_1);
    }
    else
    {
        param_1->unk_10 = new (Proc_Start(ProcScr_ProcMenu, PROC_TREE_9)) ProcMenu(param_1);
    }
    return;
}

EC void StartChildMenu(Menu * param_1, MenuItem ** param_2, ProcPtr param_3, u32 param_4, u8 param_5)
{
    param_1->unk_08 = param_2;

    if ((!IsRootProcess((struct Proc *)param_3)) && (func_020190c4((struct Proc *)param_3) == ProcScr_ProcMenu))
    {
        param_1->unk_04 = static_cast<ProcMenu *>(param_3)->unk_38;
    }

    param_1->vfunc_00();

    if (param_5 != 0)
    {
        param_1->vfunc_128();
    }

    param_1->unk_49 = param_1->unk_48;

    param_1->_0202f8c4();

    param_1->vfunc_04();

    if (param_4)
    {
        param_1->unk_10 = new (Proc_StartBlocking(ProcScr_ProcMenu, param_3)) ProcMenu(param_1);
    }
    else
    {
        param_1->unk_10 = new (Proc_Start(ProcScr_ProcMenu, param_3)) ProcMenu(param_1);
    }
}

EC void func_0202fc30(Menu * param_1, s32 param_2, s32 param_3)
{
    param_1->unk_0c[param_1->unk_38].unk_00->vfunc_84(param_1, &param_1->unk_0c[param_1->unk_38]);

    param_1->vfunc_dc();
    param_1->vfunc_ec();

    if (param_2 != 0)
    {
        param_1->unk_34 = param_1->unk_35 = -1;
    }

    if (param_3 != 0)
    {
        param_1->unk_36 = param_1->unk_37 = -1;
    }

    param_1->_0202f8c4();

    param_1->vfunc_e8();
    param_1->vfunc_d8();

    param_1->unk_3f = 1;

    param_1->unk_0c[param_1->unk_38].unk_00->vfunc_78(param_1, &param_1->unk_0c[param_1->unk_38]);

    param_1->unk_45 = 0;

    return;
}

EC void func_0202fd1c(Menu * param_1, s32 param_2, s32 param_3)
{
    if (param_3 != 0 || param_2 != param_1->unk_38)
    {
        param_1->unk_0c[param_1->unk_38].unk_00->vfunc_b8(param_1, &param_1->unk_0c[param_1->unk_38]);
        param_1->unk_0c[param_1->unk_38].unk_00->vfunc_84(param_1, &param_1->unk_0c[param_1->unk_38]);

        param_1->vfunc_ec();

        param_1->unk_39 = param_2;
        param_1->unk_38 = param_2;

        param_1->vfunc_e8();

        param_1->unk_0c[param_1->unk_38].unk_00->vfunc_78(param_1, &param_1->unk_0c[param_1->unk_38]);
        param_1->unk_0c[param_1->unk_38].unk_00->vfunc_b4(param_1, &param_1->unk_0c[param_1->unk_38]);

        param_1->unk_3f = 1;
    }

    return;
}

EC void func_02033f98(void);
EC BOOL func_02033f54(ProcMenu *);

EC BOOL func_0202fe14(ProcMenu * param_1)
{
    if (func_020190c4((struct Proc *)param_1) == ProcScr_ProcMenu)
    {
        return TRUE;
    }

    return func_02033f54(param_1) != 0;
}

EC void func_0202fe4c(ProcMenu * param_1)
{
    ProcMenu * p;

    Proc_Goto(param_1, 1, 0);

    p = (ProcMenu *)func_020190cc((struct Proc *)param_1);
    if (p == NULL)
    {
        return;
    }

    if (func_0202fe14(p) == 0)
    {
        return;
    }

    func_02019124((struct Proc *)param_1);

    return;
}

EC void func_0202fe88(ProcMenu * param_1)
{
    Proc_Goto(param_1, 1, 0);
    return;
}

EC void func_0202fe9c(Menu * param_1, s32 param_2)
{
    if (param_2 != 0)
    {
        func_0202fe88(param_1->unk_10);
    }
    else
    {
        func_0202fe4c(param_1->unk_10);
    }

    return;
}

EC void func_0202febc(s32 param_1)
{
    if (param_1 != 0)
    {
        Proc_ForEach(ProcScr_ProcMenu, (ProcFunc)func_0202fe88);
    }
    else
    {
        Proc_ForEach(ProcScr_ProcMenu, (ProcFunc)func_0202fe4c);
    }

    func_02033f98();

    return;
}

EC void func_0202fef8(Menu * param_1)
{
    Proc_End(param_1->unk_10);
    return;
}

EC void func_02033fc4(void);

EC void func_0202ff08(void)
{
    Proc_EndEach(ProcScr_ProcMenu);
    func_02033fc4();
    return;
}

EC void LockMenu(Menu * param_1)
{
    Proc_Lock((struct Proc *)param_1->unk_10);
    return;
}

EC void UnlockMenu(Menu * param_1)
{
    Proc_Release((struct Proc *)param_1->unk_10);
    return;
}

EC BOOL IsMenuLocked(Menu * param_1)
{
    return IsProcLocked((struct Proc *)param_1->unk_10);
}

EC BOOL func_0202ff50(Menu * param_1)
{
    return func_02018f5c((struct Proc *)param_1->unk_10) != NULL;
}

EC BOOL IsMenuActive(void)
{
    return Proc_Find(ProcScr_ProcMenu) != NULL;
}

EC Menu * func_0202ff8c(ProcMenu * param_1)
{
    if (param_1 == NULL)
    {
        param_1 = static_cast<ProcMenu *>(Proc_Find(ProcScr_ProcMenu));
    }

    if (param_1 == NULL)
    {
        return NULL;
    }
    else
    {
        return param_1->unk_38;
    }
}

EC Menu * func_0202ffb4(ProcPtr param_1)
{
    ProcMenu * proc = static_cast<ProcMenu *>((void *)func_02018d9c(ProcScr_ProcMenu, (struct Proc *)param_1));

    if (proc != NULL)
    {
        return proc->unk_38;
    }

    return NULL;
}

EC Menu * func_0202ffd8(ProcPtr param_1)
{
    ProcMenu * proc = static_cast<ProcMenu *>((void *)func_02018df4(ProcScr_ProcMenu, (struct Proc *)param_1));

    if (proc != NULL)
    {
        return proc->unk_38;
    }

    return NULL;
}

BOOL SplitMenu::vfunc_b0(MenuItemState * arg1, s32 arg2, s32 arg3)
{
    if ((arg2 < ((arg1->unk_04) * 8)) || (arg2 >= ((arg1->unk_04 + arg1->unk_06) * 8)))
    {
        return FALSE;
    }

    if ((arg3 < (arg1->unk_05 * 8)) || (arg3 >= ((arg1->unk_05 + arg1->unk_07) * 8)))
    {
        return FALSE;
    }

    return TRUE;
}

void SplitMenu::vfunc_08(void)
{
    s32 iVar1;
    s32 iVar2;
    s32 iVar3;
    MenuItemState * pMVar4;

    iVar1 = 0;
    iVar2 = iVar1;
    for (pMVar4 = this->unk_0c, iVar3 = 0; iVar3 < this->unk_3a; iVar3++, pMVar4++)
    {
        pMVar4->unk_04 = 1;

        iVar1 = pMVar4->unk_00->vfunc_c8(pMVar4);

        if (iVar1 <= iVar2)
        {
            iVar1 = iVar2;
        }

        iVar2 = iVar1;
    }

    if (this->unk_36 == -1)
    {
        this->unk_36 = iVar1 + 2;
    }

    for (pMVar4 = this->unk_0c, iVar3 = 0; iVar1 < this->unk_3a; iVar3++, pMVar4++)
    {
        pMVar4->unk_06 = this->unk_36 - 2;
    }

    return;
}

void SplitMenu::vfunc_0c(void)
{
    u32 bVar1;
    s32 cVar2;
    MenuItemState * pMVar3;
    s32 cVar4;
    s32 i;
    u32 uVar6;
    s32 iVar7;

    cVar2 = 0;
    cVar4 = 0;
    iVar7 = 0;
    uVar6 = 0;

    for (i = 0, pMVar3 = this->unk_0c; i < this->unk_3a; i++, pMVar3++)
    {
        if (uVar6 == 0)
        {
            cVar2 = 0;
        }

        pMVar3->unk_05 = cVar2 + 1;

        bVar1 = pMVar3->unk_00->vfunc_cc();

        pMVar3->unk_07 = bVar1;
        cVar4 = cVar2 + bVar1;

        if (uVar6 != this->unk_48 - 1)
        {
            cVar4 = cVar4 + pMVar3->unk_00->vfunc_d0();
        }

        uVar6 = uVar6 + 1;

        if (uVar6 == this->unk_48)
        {
            if (iVar7 == 0)
            {
                if (this->unk_37 == -1)
                {
                    this->unk_37 = cVar4;
                }
            }
            else if (this->unk_4a[iVar7] == -1)
            {
                this->unk_4a[iVar7] = cVar4;
            }

            uVar6 = 0;
            iVar7 = iVar7 + 1;
        }
    }

    if (uVar6 == 0)
    {
        return;
    }

    if (iVar7 == 0)
    {
        if (this->unk_37 == -1)
        {
            this->unk_37 = cVar4;
        }

        return;
    }

    if (this->unk_4a[iVar7] == -1)
    {
        this->unk_4a[iVar7] = cVar4;
    }

    return;
}
