#include "global.h"

#include "unknown_funcs.h"
#include "proc.h"

extern void * data_027e1268;

extern void * data_027e0000;
extern void * data_027e0004;

extern vu8 gMainLoopBlocked;
extern vu8 data_027e125c;
extern vu32 gClock;
extern vu32 data_027e1264;

// TODO: "nds/io_reg.h"
#define REG_DISPCNT_SUB *(vu32 *)(0x04001000)

void func_0200ef04(void)
{
    void * tmp;
    s32 i;

    gClock = 0;
    data_027e1264 = 0;
    gMainLoopBlocked = 0;
    data_027e125c = 0;

    func_0200edf0();
    func_020120f4();
    func_02012124();
    func_020100ac();
    func_0201032c();
    func_0200f3b8();
    func_0200fcdc();
    func_0200f1e8();
    func_0200f350(1);

    tmp = data_027e1268;

    for (i = 0; i < 2; i++)
    {
        data_027e1268 = i == 0 ? data_027e0000 : data_027e0004;

        func_01ffa764();
        func_02010c84(NULL);
    }

    data_027e1268 = tmp;

    func_02019bd4();
    func_02011458();
    func_020115d4();
    func_02015bd0();
    Proc_Init();
    func_0201bc28();
    func_0200eecc();
    func_0201f3dc();
    rtc_init();
    func_0201ff20();
    func_020217b4();

    tmp = data_027e1268;

    for (i = 0; i < 2; i++)
    {
        data_027e1268 = (i == 0) ? data_027e0000 : data_027e0004;

        func_0201c204();
        func_01ffa720();
    }

    data_027e1268 = tmp;
}

EC void func_0200f028(void)
{
    OS_WaitVBlankIntr();
    GX_DispOn();

    REG_DISPCNT_SUB |= 0x10000;
}

EC void func_0200f04c(void)
{
    if (!gMainLoopBlocked)
        return;

    func_02070468();
    gClock++;

    func_0201018c();
    func_02010398();
    func_02015fb4();
    func_0201079c();

    Proc_Run(5);
    Proc_Run(6);
    Proc_Run(7);
    Proc_Run(8);
    Proc_Run(9);
    Proc_Run(10);
    Proc_Run(11);
    Proc_Run(12);

    func_02019c30();
    gMainLoopBlocked = FALSE;

    func_02070480();
    OS_WaitIrq(1, 1);
}
