#include "global.h"

#include <new>

#include "hardware.hpp"
#include "hashtable.hpp"
#include "map.hpp"
#include "proc_ex.hpp"
#include "sound_manager.hpp"

EC void func_0206ce8c(s32);
EC void func_0206d2e8(s32, s32, s32, s32, s32, s32, s32);

namespace anime
{
class Effect;
}

class Anime;

struct Anime_3c_10
{
    /* 00 */ u16 unk_00;
    /* 02 */ u8 unk_02;
    /* 03 */ u8 unk_03;
    /* 04 */ u8 unk_04;
    /* 05 */ u8 unk_05;
    /* 06 */ s16 unk_06;
    /* 08 */ s16 unk_08;
    /* 0A */ s16 unk_0a;
    /* 0C */ u8 unk_0c;
    /* 0D */ u8 unk_0d;
    /* 0E */ u8 unk_0e;
    /* 0F */ u8 unk_0f;
};

class Anime_3c
{
public:
    /* 00 */ Anime * unk_00;
    /* 04 */ Anime_3c * unk_04;
    /* 08 */ Anime_3c * unk_08;
    /* 0C */ s32 * unk_0c;
    /* 10 */ struct Anime_3c_10 * unk_10;
    /* 14 */ s32 unk_14; // TODO: probably a pointer?
    /* 18 */ s32 unk_18; // TODO: probably a pointer?
    /* 1C */ struct Anime_3c_10 * unk_1c;
    /* 20 */ s32 unk_20;
    /* 24 */ s16 unk_24;
    /* 26 */ s16 unk_26;
    /* 28 */ u16 unk_28;
    /* 2A */ u16 unk_2a;
    /* 2C */ u32 unk_2c;
    /* 30 */ u16 unk_30;
    /* 32 */ u8 unk_32;
    /* 33 */ u8 unk_33;
    /* 34 */ u16 unk_34;
    /* 36 */ u8 unk_36;
    /* 37 */ u8 unk_37;
    /* 38 */ u8 unk_38;
    /* 39 */ u8 unk_39;
    /* 3A */ u8 unk_3a;
    /* 3B */ STRUCT_PAD(0x3B, 0x3C);

    Anime_3c(Anime *, void *, u16, u16, u16, u16, s32); // func_02019d80
    Anime_3c(Anime_3c *, u32); // func_02019e60
};

class Anime : public ProcEx
{
public:
    /* 38 */ void (*unk_38)(Anime *);
    /* 3C */ Anime_3c * unk_3c;
    /* 40 */ anime::Effect * unk_40;
    /* 44 */ void * unk_44;
    /* 48 */ s32 unk_48;
    /* 4C */ u8 unk_4c;

    Anime(void *, u16, u16, u16, u16, s32, u8); // func_0201ad9c

    virtual ~Anime();

    void func_02019f88(s32);
};

namespace anime
{
class Effect
{
public:
    /* 00 */ // vtable
    /* 04 */ Anime * unk_04;
    /* 08 */ Effect * unk_08;
    /* 0C */ Effect * unk_0c;

    Effect(Anime *);

    virtual void vfunc_00(void); // func_0201ad98

    // func_0201b050
    // func_0201ac88
    virtual ~Effect() {

    };
};

class EffectAlpha3D : public Effect
{
public:
    /* 10 */ s32 unk_10;
    /* 14 */ s32 unk_14;
    /* 18 */ s32 unk_18;
    /* 1C */ s32 unk_1c;

    EffectAlpha3D(Anime * anime, s32 b, s32 c);

    virtual void vfunc_00(void); // func_0201bba8
    // func_0201bb24
    // func_0201bb48
    virtual ~EffectAlpha3D();
};

class EffectBright : public Effect
{
public:
    /* 10 */ u32 unk_10;
    /* 14 */ u32 unk_14;
    /* 18 */ u32 unk_18;
    /* 1C */ u32 unk_1c;

    EffectBright(Anime * anime, s32 b, s32 c);

    virtual void vfunc_00(void); // func_0201b134
    // func_0201b0a8
    // func_0201b0cc
    virtual ~EffectBright();
};

class EffectBlend : public Effect
{
public:
    /* 10 */ s32 unk_10;
    /* 14 */ s32 unk_14;
    /* 18 */ s32 unk_18;
    /* 1C */ s32 unk_1c;
    /* 20 */ s32 unk_20;
    /* 24 */ s32 unk_24;

    EffectBlend(Anime * anime, s32 b, s32 c, s32 d); // func_0201b1b4

    virtual void vfunc_00(void); // func_0201b538
    // func_0201b21c
    // func_0201b244
    virtual ~EffectBlend();
};

class EffectBGBlend : public Effect
{
public:
    /* 10 */ s32 unk_10;
    /* 14 */ s32 unk_14;
    /* 18 */ s32 unk_18;
    /* 1C */ s32 unk_1c;
    /* 20 */ s32 unk_20;
    /* 24 */ s32 unk_24;

    EffectBGBlend(Anime * anime, s32 b, s32 c, s32 d); // func_0201b5b4

    virtual void vfunc_00(void); // func_0201b938
    // func_0201b61c
    // func_0201b644
    virtual ~EffectBGBlend();
};

} // namespace anime

// func_02019d80
Anime_3c::Anime_3c(Anime * arg0, void * arg1, u16 arg2, u16 arg3, u16 arg4, u16 arg5, s32 arg6)
{
    this->unk_0c = (s32 *)arg1;
    this->unk_38 = arg2;
    this->unk_14 = (s32)arg1 + this->unk_0c[0];
    this->unk_18 = (s32)arg1 + this->unk_0c[1];
    this->unk_10 = (struct Anime_3c_10 *)((u8 *)this->unk_0c + (this->unk_0c + this->unk_38)[2]);

    this->unk_24 = arg3 & 0x1ff;

    if ((arg3 & 0x100) != 0)
    {
        this->unk_24 |= 0xfe00;
    }

    this->unk_26 = arg4 & 0xff;

    if (arg4 >= 0xc0)
    {
        this->unk_26 |= 0xff00;
    }

    this->unk_28 = arg3 & 0xfe00;
    this->unk_2a = arg4 & 0xff00;

    this->unk_34 = arg5;
    this->unk_2c = 0;
    this->unk_30 = 0;
    this->unk_32 = 0;
    this->unk_33 = 0x1f;
    this->unk_36 = arg6;
    this->unk_37 = 0;
    this->unk_39 = 0;
    this->unk_3a = 0;
    this->unk_1c = 0;
    this->unk_20 = 0;
    this->unk_00 = arg0;
    this->unk_04 = 0;
    this->unk_08 = 0;

    arg0->unk_3c = this;
}

// func_02019e60
Anime_3c::Anime_3c(Anime_3c * other, u32 arg2)
{
    Anime_3c * it;
    Anime_3c * next;

    next = other->unk_08;

    for (it = next; it != NULL; it = it->unk_08)
    {
        other = it;
    }

    this->unk_0c = other->unk_0c;
    this->unk_38 = arg2;
    this->unk_14 = (s32)((u8 *)this->unk_0c + this->unk_0c[0]);
    this->unk_10 = (struct Anime_3c_10 *)((u8 *)this->unk_0c + (this->unk_0c + this->unk_38)[2]);
    this->unk_24 = other->unk_24;
    this->unk_26 = other->unk_26;
    this->unk_28 = other->unk_28;
    this->unk_2a = other->unk_2a;
    this->unk_34 = other->unk_34;
    this->unk_2c = other->unk_2c;
    this->unk_30 = other->unk_30;
    this->unk_32 = other->unk_32;
    this->unk_33 = other->unk_33;
    this->unk_36 = other->unk_36;
    this->unk_39 = other->unk_39;
    this->unk_3a = other->unk_3a;
    this->unk_1c = 0;
    this->unk_20 = 0;
    this->unk_00 = other->unk_00;

    this->unk_04 = other;
    next = other->unk_08;
    this->unk_08 = next;

    if (next != NULL)
    {
        next->unk_04 = this;
    }

    other->unk_08 = this;

    return;
}

EC void func_02019f40(Anime_3c * self, u8 arg2)
{
    self->unk_38 = arg2;
    self->unk_10 = (struct Anime_3c_10 *)((u8 *)self->unk_0c + (self->unk_0c + self->unk_38)[2]);
    self->unk_20 = 0;
    return;
}

EC void func_02019f68(Anime_3c * self, u32 arg2, u32 arg3)
{
    self->unk_24 = arg2;
    self->unk_26 = arg3;

    if (self->unk_08 != NULL)
    {
        func_02019f68(self->unk_08, arg2, arg3);
    }

    return;
}

EC void func_02019f88(Anime_3c * self, BOOL arg2)
{
    if (arg2)
    {
        self->unk_39 |= 1;
    }
    else
    {
        self->unk_39 &= ~1;
    }

    return;
}

EC void func_02019fa0(Anime_3c * self, BOOL arg2)
{
    if (arg2)
    {
        self->unk_39 |= 2;
    }
    else
    {
        self->unk_39 &= ~2;
    }

    if (self->unk_08 != NULL)
    {
        func_02019fa0(self->unk_08, arg2);
    }

    return;
}

EC void func_02019fcc(Anime_3c * self, BOOL arg2)
{
    if (arg2)
    {
        self->unk_39 |= 4;
    }
    else
    {
        self->unk_39 &= ~4;
    }

    if (self->unk_08 != NULL)
    {
        func_02019fcc(self->unk_08, arg2);
    }

    return;
}

EC void func_02019ff8(Anime_3c * self, s32 arg2)
{
    self->unk_3a = arg2;

    if (self->unk_08 != NULL)
    {
        func_02019ff8(self->unk_08, arg2);
    }

    return;
}

EC void func_0201a014(Anime_3c * self, s32 arg2, s32 arg3, s32 arg4, s32 arg5, u8 arg6)
{
    self->unk_39 |= 0x40;

    if (arg6 != 0)
    {
        self->unk_39 |= 0x80;
    }

    self->unk_2c = arg2;
    self->unk_30 = arg3;
    self->unk_32 = arg4;
    self->unk_33 = arg5;

    if (self->unk_08 != NULL)
    {
        func_0201a014(self->unk_08, arg2, arg3, arg4, arg5, 0);
    }

    return;
}

EC void func_0201a078(Anime_3c * self, s32 arg2)
{
    self->unk_30 = arg2;

    if (self->unk_08 != NULL)
    {
        func_0201a078(self->unk_08, arg2);
    }

    return;
}

EC void func_0201a094(Anime_3c * self, s32 arg2)
{
    self->unk_33 = arg2;

    if (self->unk_08 != NULL)
    {
        func_0201a094(self->unk_08, arg2);
    }

    return;
}

EC void func_0201a0dc(Anime_3c * self, BOOL arg2);

EC void func_0201a0b0(Anime_3c * self, BOOL arg2)
{
    if (arg2)
    {
        self->unk_39 |= 8;
    }
    else
    {
        self->unk_39 &= ~8;
    }

    if (self->unk_08 != NULL)
    {
        func_0201a0dc(self->unk_08, arg2);
    }

    return;
}

EC void func_0201a0dc(Anime_3c * self, BOOL arg2)
{
    if (arg2)
    {
        self->unk_39 |= 0x10;
    }
    else
    {
        self->unk_39 &= ~0x10;
    }

    if (self->unk_08 != NULL)
    {
        func_0201a0dc(self->unk_08, arg2);
    }

    return;
}

EC void func_0201a108(Anime_3c * self, BOOL arg2)
{
    if (arg2)
    {
        self->unk_39 |= 0x20;
    }
    else
    {
        self->unk_39 &= ~0x20;
    }

    if (self->unk_08 != NULL)
    {
        func_0201a108(self->unk_08, arg2);
    }

    return;
}

EC void func_0201a134(Anime_3c * self, s32 arg2)
{
    self->unk_34 = arg2;

    if (self->unk_08 != NULL)
    {
        func_0201a134(self->unk_08, arg2);
    }

    return;
}

EC void func_0201a5b0(Anime_3c *);

EC void func_0201a150(Anime_3c * self)
{
    if (self->unk_04 != NULL)
    {
        self->unk_04->unk_08 = self->unk_08;

        if (self->unk_08 != NULL)
        {
            self->unk_08->unk_04 = self->unk_04;
        }

        if (self != NULL)
        {
            delete self;
            return;
        }
    }
    else
    {
        self->unk_00->unk_3c = self->unk_08;

        if (self->unk_08 != NULL)
        {
            self->unk_08->unk_04 = NULL;
        }

        if (self != NULL)
        {
            delete self;
            return;
        }
    }

    return;
}

EC void func_0201a1b4(Anime_3c * self)
{
    Anime_3c * it;
    Anime_3c * next;

    it = self;

    func_0201a5b0(self);

    for (; it != NULL; it = next)
    {
        next = it->unk_08;
        if (it != NULL)
        {
            delete it;
        }
    }

    self->unk_00->unk_3c = NULL;

    return;
}

EC void func_0201acdc(anime::Effect *);
EC void func_0201b9b4(char *, char *);
EC void func_0201ba90(void);
EC void func_ov000_021d39a4(s32, s32, s32);
EC void func_ov000_021d3a2c(void);
EC s32 func_ov000_021d6f7c(s32);

EC void func_0201a1fc(Anime_3c * self)
{
    Anime_3c * child = self->unk_08;

    if (self->unk_20 == 0)
    {
        while (self->unk_10->unk_03 != 0 || self->unk_10->unk_00 == 0)
        {
            if (self->unk_10->unk_03 != 0)
            {
                switch (self->unk_10->unk_02)
                {
                    case 0x00:
                    case 0xFF:
                        if ((self->unk_39 & 8) != 0)
                        {
                            self->unk_10 = (Anime_3c_10 *)((int)self->unk_0c + self->unk_0c[self->unk_38 + 2]);
                        }
                        else
                        {
                            func_0201a150(self);
                            goto _0201a58c;
                        }

                        continue;

                    case 0x01:
                        self->unk_10 = (Anime_3c_10 *)((int)self->unk_0c + self->unk_0c[self->unk_38 + 2]);
                        continue;

                    case 0x02:
                        goto _0201a58c;
                        break;

                    case 0x03:
                        break;

                    case 0x04:
                    {
                        Anime_3c_10 * p = (Anime_3c_10 *)((int)self->unk_0c + self->unk_0c[self->unk_38 + 2]);

                        while (p->unk_03 == 0 || p->unk_02 != 0xFF)
                        {
                            if (p->unk_03 != 0)
                            {
                                if (p->unk_02 == 0x03)
                                {
                                    if (p->unk_06 == self->unk_10->unk_06)
                                    {
                                        self->unk_10 = p;
                                        break;
                                    }
                                }
                            }

                            self->unk_10++;
                        }

                        continue;
                    }

                    case 0x10:
                        if (self->unk_10->unk_06 > 0)
                        {
                            child = new Anime_3c(self, self->unk_10->unk_06 - 1);
                            child = self->unk_08;
                        }

                        break;

                    case 0x11:
                        self->unk_37 = self->unk_10->unk_06 & 0xFFFF;
                        break;

                    case 0x12:
                        self->unk_33 = self->unk_10->unk_06 & 0xFFFF;
                        new anime::EffectAlpha3D(self->unk_00, self->unk_10->unk_06, self->unk_10->unk_08);
                        break;

                    case 0x20:
                        new anime::EffectBright(self->unk_00, self->unk_10->unk_06, self->unk_10->unk_08);
                        break;

                    case 0x21:
                        new anime::EffectBlend(
                            self->unk_00, self->unk_10->unk_06, self->unk_10->unk_08, self->unk_10->unk_0a);
                        break;

                    case 0x22:
                        func_0201acdc(self->unk_00->unk_40);
                        data_027e1268->unk_00->bldcnt.effect = 0;
                        break;

                    case 0x23:
                        func_0201b9b4((char *)self->unk_00->unk_48, (char *)(self->unk_18 + self->unk_10->unk_06));
                        break;

                    case 0x24:
                        func_0201ba90();
                        break;

                    case 0x25:
                        new anime::EffectBGBlend(
                            self->unk_00, self->unk_10->unk_06, self->unk_10->unk_08, self->unk_10->unk_0a);
                        break;

                    case 0x26:
                    {
                        s32 v = self->unk_10->unk_06;
                        if (v == 0)
                        {
                            v = -1;
                        }
                        func_ov000_021d39a4(v, 9, 0);
                        break;
                    }

                    case 0x27:
                        func_ov000_021d3a2c();
                        break;

                    case 0x30:
                        if ((self->unk_39 & 0x10) == 0)
                        {
                            s32 arg = 0;
                            if (self->unk_39 & 0x20)
                            {
                                arg = func_ov000_021d6f7c(self->unk_24);
                            }

                            data_020efcc8->unk_b0->vfunc_2c(self->unk_18 + self->unk_10->unk_06, 0, arg);
                        }

                        break;
                }
            }

            self->unk_10++;
        }

        self->unk_20 = self->unk_10->unk_00;
        self->unk_1c = self->unk_10;
        self->unk_10++;
    }

    self->unk_20--;

_0201a58c:
    if (child != NULL)
    {
        func_0201a1fc(child);
    }
}

EC void func_0201ac9c(anime::Effect * param_1);

EC void func_0201a5b0(Anime_3c * self)
{
    Anime_3c * child = self->unk_08;

    if (self->unk_00->unk_40 != NULL)
    {
        func_0201ac9c(self->unk_00->unk_40);
    }

    while (self->unk_10->unk_03 != 0 || self->unk_10->unk_00 == 0)
    {
        if (self->unk_10->unk_03 != 0)
        {
            switch (self->unk_10->unk_02)
            {
                case 0x00:
                case 0x01:
                case 0x02:
                    goto _0201a854;

                case 0x04:
                {
                    Anime_3c_10 * p = (Anime_3c_10 *)((int)self->unk_0c + self->unk_0c[self->unk_38 + 2]);

                    while (p->unk_03 == 0 || p->unk_02 != 0xFF)
                    {
                        if (p->unk_03 != 0)
                        {
                            if (p->unk_02 == 0x03)
                            {
                                if (p->unk_06 == self->unk_10->unk_06)
                                {
                                    self->unk_10 = p;
                                    break;
                                }
                            }
                        }

                        self->unk_10++;
                    }

                    continue;
                }

                case 0x10:
                    if (self->unk_10->unk_06 > 0)
                    {
                        child = new Anime_3c(self, self->unk_10->unk_06 - 1);
                        child = self->unk_08;
                    }

                    break;

                case 0x20:
                    new anime::EffectBright(self->unk_00, self->unk_10->unk_06, self->unk_10->unk_08);
                    if (self->unk_00->unk_40 != NULL)
                    {
                        func_0201ac9c(self->unk_00->unk_40);
                    }
                    break;

                case 0x21:
                    new anime::EffectBlend(
                        self->unk_00, self->unk_10->unk_06, self->unk_10->unk_08, self->unk_10->unk_0a);
                    if (self->unk_00->unk_40 != NULL)
                    {
                        func_0201ac9c(self->unk_00->unk_40);
                    }
                    break;

                case 0x22:
                    data_027e1268->unk_00->bldcnt.effect = 0;
                    break;

                case 0x24:
                    func_0201ba90();
                    break;

                case 0x25:
                    new anime::EffectBGBlend(
                        self->unk_00, self->unk_10->unk_06, self->unk_10->unk_08, self->unk_10->unk_0a);
                    if (self->unk_00->unk_40 != NULL)
                    {
                        func_0201ac9c(self->unk_00->unk_40);
                    }
                    break;

                case 0x26:
                {
                    s32 v = self->unk_10->unk_06;
                    if (v == 0)
                    {
                        v = -1;
                    }
                    func_ov000_021d39a4(v, 9, 0);
                    break;
                }

                case 0x27:
                    func_ov000_021d3a2c();
                    break;

                case 0xFF:
                    goto _0201a854;
            }
        }

        self->unk_10++;
    }

    self->unk_10++;

_0201a854:
    if (child != NULL)
    {
        func_0201a5b0(child);
    }
}

EC void func_0201a894(Anime_3c *, s32, s32);

EC void func_0201a874(Anime_3c * param_1)
{
    if (!(param_1->unk_39 & 1))
    {
        func_0201a894(param_1, param_1->unk_24, param_1->unk_26);
    }

    return;
}

static inline s32 abs(s32 val)
{
    if (val < 0)
    {
        return -val;
    }

    return val;
}

static inline s32 clamp(s32 x, s32 lo, s32 hi)
{
    if (x > hi)
    {
        return hi;
    }

    if (x < lo)
    {
        return lo;
    }

    return x;
}

extern s16 data_020c53b0[]; // gSinLut?

static inline s32 sin(s32 aAngle)
{
    return data_020c53b0[((aAngle) >> 4) + 0];
}

static inline s32 cos(s32 aAngle)
{
    return data_020c53b0[((aAngle) >> 4) + 1];
}

EC s32 IntSys_Div(s32, s32);
EC void func_01ffb574(s32, s16, s16, s16, s16); // SetObjAffine?
EC void func_01ffc4e4(s16, s16, u16, u16, s32, s32, s32);
EC void func_01ffc614(s16, s16, u16, u16, s32, s32, s32);
EC void func_01ffc668(s16, s16, u16, u16, s32, s32, s32);

EC void func_0201a894(Anime_3c * arg0, s32 arg1, s32 arg2)
{
    s32 temp_r5;
    u16 var_r4;

    struct Anime_3c_10 * temp_r0 = arg0->unk_1c;

    if (temp_r0 != NULL)
    {
        temp_r5 = arg0->unk_0c[arg0->unk_14 + temp_r0->unk_02];

        if (arg0->unk_39 & 0x40)
        {
            if (arg0->unk_33 != 0)
            {
                func_0206ce8c(arg0->unk_32);
                func_0206d2e8(
                    arg1, arg2, arg0->unk_36 + arg0->unk_37, arg0->unk_2c + (arg0->unk_34 >> 5),
                    arg0->unk_30 + ((arg0->unk_34 >> 0xC) << 5), temp_r5,
                    ((arg0->unk_39 & 0x80) ? TRUE : FALSE) & 0xFF);
            }
        }
        else
        {
            var_r4 = arg0->unk_28;
            if (arg0->unk_3a != 0)
            {
                s32 xScale = clamp(abs(temp_r0->unk_08), -2, 2);
                s32 c = cos(temp_r0->unk_04);
                s32 yScale = clamp(abs(temp_r0->unk_06), -2, 2);
                s32 s = sin(temp_r0->unk_04);

                // clang-format off
                func_01ffb574(
                    arg0->unk_3a,
                    IntSys_Div(+c * 0x10, xScale),
                    IntSys_Div(-s * 0x10, yScale),
                    IntSys_Div(+s * 0x10, xScale),
                    IntSys_Div(+c * 0x10, yScale)
                );
                // clang-format on
                var_r4 |= (u32)(arg0->unk_3a << 0x1B) >> 0x12;
            }

            if (arg0->unk_39 & 2)
            {
                func_01ffc614(
                    arg1, arg2, var_r4, arg0->unk_2a, arg0->unk_34, temp_r5, (arg0->unk_36 + arg0->unk_37) & 0xff);
            }
            else
            {
                if (arg0->unk_39 & 4)
                {
                    func_01ffc668(
                        arg1, arg2, var_r4, arg0->unk_2a, arg0->unk_34, temp_r5, (arg0->unk_36 + arg0->unk_37) & 0xff);
                }
                else
                {
                    func_01ffc4e4(
                        arg1, arg2, var_r4, arg0->unk_2a, arg0->unk_34, temp_r5, (arg0->unk_36 + arg0->unk_37) & 0xff);
                }
            }
        }
    }

    if (arg0->unk_08 != NULL)
    {
        func_0201a894(arg0->unk_08, arg1, arg2);
    }

    return;
}

// func_0201abac
anime::Effect::Effect(Anime * anime)
{
    anime::Effect * it;
    anime::Effect * next;

    this->unk_04 = anime;
    next = anime->unk_40;

    if (next == NULL)
    {
        this->unk_08 = NULL;
        this->unk_0c = NULL;
        anime->unk_40 = this;
        return;
    }

    for (it = next->unk_0c; it != NULL; it = it->unk_0c)
    {
        next = it;
    }

    this->unk_08 = next;
    it = next->unk_0c;
    this->unk_0c = it;

    if (it != NULL)
    {
        it->unk_08 = this;
    }

    next->unk_0c = this;
}

EC void func_0201ac14(anime::Effect * effect)
{
    if (effect->unk_08 != NULL)
    {
        effect->unk_08->unk_0c = effect->unk_0c;

        if (effect->unk_0c != NULL)
        {
            effect->unk_0c->unk_08 = effect->unk_08;
        }

        delete effect;
    }
    else
    {
        effect->unk_04->unk_40 = effect->unk_0c;

        if (effect->unk_0c != NULL)
        {
            effect->unk_0c->unk_08 = NULL;
        }

        delete effect;
    }

    return;
}

// func_0201ac88
// anime::Effect::~Effect()
// {
// }

EC void func_0201ac9c(anime::Effect * effect)
{
    anime::Effect * next;

    anime::Effect * it = effect;

    for (; it != NULL; it = next)
    {
        next = it->unk_0c;
        delete it;
    }

    effect->unk_04->unk_40 = NULL;

    return;
}

EC void func_0201acdc(anime::Effect * effect)
{
    anime::Effect * next;

    anime::Effect * it = effect;

    for (; it != NULL; it = next)
    {
        next = it->unk_0c;

        if (dynamic_cast<anime::EffectBlend *>(it) != NULL)
        {
            func_0201ac14(it);
        }

        if (dynamic_cast<anime::EffectBGBlend *>(it) != NULL)
        {
            func_0201ac14(it);
        }
    }

    return;
}

EC void func_0201ad70(anime::Effect * effect)
{
    effect->vfunc_00();

    if (effect->unk_0c != NULL)
    {
        func_0201ad70(effect->unk_0c);
    }

    return;
}

EC void func_0201ad98(void)
{
    return;
}

// func_0201ad9c
Anime::Anime(void * file, u16 arg2, u16 arg3, u16 arg4, u16 arg5, s32 arg6, u8 arg7)
{
    this->unk_44 = file;
    this->unk_3c = NULL;
    this->unk_40 = 0;
    this->unk_38 = 0;
    this->unk_4c = arg7;

    new Anime_3c(this, file, arg2, arg3, arg4, arg5, arg6);
}

extern u8 data_027e1b9c[];

EC void func_01ffbb90(void *, void *);

EC void func_0201a1b4(Anime_3c *);

// func_0201ae24
// func_0201ae90
Anime::~Anime()
{
    if (this->unk_3c != NULL)
    {
        func_0201a1b4(this->unk_3c);
    }

    if (this->unk_40 != NULL)
    {
        func_0201ac9c(this->unk_40);
    }

    if (this->unk_38 != NULL)
    {
        this->unk_38(this);
    }

    if (this->unk_4c != 0)
    {
        func_01ffbb90(data_027e1b9c, this->unk_44);
    }
}

EC void func_0201a1fc(Anime_3c *);

EC void func_0201af04(Anime * self)
{
    if (self->unk_3c != NULL)
    {
        func_0201a1fc(self->unk_3c);
    }

    if (self->unk_40 != NULL)
    {
        func_0201ad70(self->unk_40);
    }

    if (self->unk_3c == NULL && self->unk_40 == NULL)
    {
        Proc_End(self);
    }

    return;
}

EC void func_0201a874(Anime_3c * self);

EC void func_0201af4c(Anime * self)
{
    if (self->unk_3c != NULL)
    {
        func_0201a874(self->unk_3c);
    }

    return;
}

EC void func_0201af64(Anime * proc)
{
    func_0201af04(proc);
    return;
}

EC void func_0201af70(Anime * proc)
{
    proc->Loop();
    return;
}

extern struct ProcCmd data_020ce810[];

EC void func_0201af84(void * file, u16 arg2, u16 arg3, u16 arg4, u16 arg5, s32 arg6, u8 arg7, ProcEx * parent)
{
    if (parent == NULL)
    {
        parent = static_cast<ProcEx *>(PROC_TREE_B);
    }

    new (Proc_Start(data_020ce810, parent)) Anime(file, arg2, arg3, arg4, arg5, arg6, arg7);

    return;
}

EC void * func_02011920(char *, BOOL);

EC void func_0201affc(char * animName, u16 arg2, u16 arg3, u16 arg4, u16 arg5, s32 arg6, ProcEx * parent)
{
    void * file = func_02011920(animName, 0);
    func_0201af84(file, arg2, arg3, arg4, arg5, arg6, 1, parent);
    return;
}

EC s32 func_0201b0f8(anime::EffectBright *);

// func_0201b054
anime::EffectBright::EffectBright(Anime * anime, s32 b, s32 c) : Effect(anime)
{
    this->unk_10 = func_0201b0f8(this);
    this->unk_14 = b;
    this->unk_1c = c;
    this->unk_18 = 0;

    if (c <= 0)
    {
        func_0201ac14(this);
    }
}

EC void func_0201b118(anime::EffectBright *, s32);

anime::EffectBright::~EffectBright()
{
    func_0201b118(this, this->unk_14);
}

EC BOOL func_0201b0f8(anime::EffectBright * self)
{
    if (gMapStateManager != NULL)
    {
        return gMapStateManager->unk_14->unk_25;
    }

    return FALSE;
}

EC void func_0201b118(anime::EffectBright * self, s32 arg2)
{
    if (gMapStateManager != NULL)
    {
        gMapStateManager->unk_14->unk_25 = arg2;
    }

    return;
}

EC s32 Interpolate(s32, s32, s32, s32, s32);

// func_0201b134
void anime::EffectBright::vfunc_00()
{
    this->unk_18++;

    Interpolate(0, this->unk_10, this->unk_14, this->unk_18, this->unk_1c);
    func_0201b118(this, Interpolate(0, this->unk_10, this->unk_14, this->unk_18, this->unk_1c));

    if (this->unk_18 == this->unk_1c)
    {
        func_0201ac14(this);
    }

    return;
}

EC s32 func_0201b274(anime::EffectBlend *);
EC s32 func_0201b2d0(anime::EffectBlend *);

// func_0201b1b4
anime::EffectBlend::EffectBlend(Anime * anime, s32 b, s32 c, s32 d) : Effect(anime)
{
    this->unk_10 = func_0201b274(this);
    this->unk_14 = func_0201b2d0(this);
    this->unk_18 = b;
    this->unk_1c = c;
    this->unk_24 = d;
    this->unk_20 = 0;

    if (d <= 0)
    {
        func_0201ac14(this);
    }
}

EC void func_0201b32c(anime::EffectBlend *, s32, s32);

// func_0201b21c
// func_0201b244
anime::EffectBlend::~EffectBlend()
{
    func_0201b32c(this, this->unk_18, this->unk_1c);
}

EC s32 func_0201b274(anime::EffectBlend * self)
{
    if ((data_027e1268->unk_00->bldcnt.effect == 1) && (data_027e1268->unk_00->bldcnt.target1_obj_on != 0) &&
        (data_027e1268->unk_00->bldcnt.target2_bg0_on != 0))
    {
        return data_027e1268->unk_00->blend_coeff_a;
    }

    return 0;
}

EC s32 func_0201b2d0(anime::EffectBlend * self)
{
    if ((data_027e1268->unk_00->bldcnt.effect == 1) && (data_027e1268->unk_00->bldcnt.target1_obj_on != 0) &&
        (data_027e1268->unk_00->bldcnt.target2_bg0_on != 0))
    {
        return data_027e1268->unk_00->blend_coeff_b;
    }

    return 0x10;
}

EC void func_0201b32c(anime::EffectBlend * self, s32 bldA, s32 bldB)
{
    data_027e1268->unk_00->bldcnt.effect = 1;
    data_027e1268->unk_00->blend_coeff_a = bldA;
    data_027e1268->unk_00->blend_coeff_b = bldB;

    data_027e1268->unk_00->bldcnt.target1_bg0_on = 0;
    data_027e1268->unk_00->bldcnt.target1_bg1_on = 0;
    data_027e1268->unk_00->bldcnt.target1_bg2_on = 0;
    data_027e1268->unk_00->bldcnt.target1_bg3_on = 0;
    data_027e1268->unk_00->bldcnt.target1_obj_on = 1;
    data_027e1268->unk_00->bldcnt.target1_bd_on = 0;

    data_027e1268->unk_00->bldcnt.target2_bg0_on = 1;
    data_027e1268->unk_00->bldcnt.target2_bg1_on = 0;
    data_027e1268->unk_00->bldcnt.target2_bg2_on = 0;
    data_027e1268->unk_00->bldcnt.target2_bg3_on = 0;
    data_027e1268->unk_00->bldcnt.target2_obj_on = 0;
    data_027e1268->unk_00->bldcnt.target2_bd_on = 1;

    return;
}

// func_0201b538
void anime::EffectBlend::vfunc_00()
{
    this->unk_20++;

    func_0201b32c(
        this, Interpolate(0, this->unk_10, this->unk_18, this->unk_20, this->unk_24),
        Interpolate(0, this->unk_14, this->unk_1c, this->unk_20, this->unk_24));

    if (this->unk_20 == this->unk_24)
    {
        func_0201ac14(this);
    }

    return;
}

EC s32 func_0201b674(anime::EffectBGBlend *);
EC s32 func_0201b6d0(anime::EffectBGBlend *);

// func_0201b5b4
anime::EffectBGBlend::EffectBGBlend(Anime * anime, s32 b, s32 c, s32 d) : Effect(anime)
{
    this->unk_10 = func_0201b674(this);
    this->unk_14 = func_0201b6d0(this);
    this->unk_18 = b;
    this->unk_1c = c;
    this->unk_24 = d;
    this->unk_20 = 0;

    if (d <= 0)
    {
        func_0201ac14((anime::Effect *)this);
    }
}

EC void func_0201b72c(anime::EffectBGBlend *, s32, s32);

anime::EffectBGBlend::~EffectBGBlend()
{
    func_0201b72c(this, this->unk_18, this->unk_1c);
}

EC s32 func_0201b674(anime::EffectBGBlend * self)
{
    if ((data_027e1268->unk_00->bldcnt.effect == 1) && (data_027e1268->unk_00->bldcnt.target1_bg2_on != 0) &&
        (data_027e1268->unk_00->bldcnt.target2_bg0_on != 0))
    {
        return data_027e1268->unk_00->blend_coeff_a;
    }

    return 0;
}

EC s32 func_0201b6d0(anime::EffectBGBlend * self)
{
    if ((data_027e1268->unk_00->bldcnt.effect == 1) && (data_027e1268->unk_00->bldcnt.target1_bg2_on != 0) &&
        (data_027e1268->unk_00->bldcnt.target2_bg0_on != 0))
    {
        return data_027e1268->unk_00->blend_coeff_b;
    }

    return 0x10;
}

EC void func_0201b72c(anime::EffectBGBlend * self, s32 bldA, s32 bldB)
{
    data_027e1268->unk_00->bldcnt.effect = 1;
    data_027e1268->unk_00->blend_coeff_a = bldA;
    data_027e1268->unk_00->blend_coeff_b = bldB;

    data_027e1268->unk_00->bldcnt.target1_bg0_on = 0;
    data_027e1268->unk_00->bldcnt.target1_bg1_on = 0;
    data_027e1268->unk_00->bldcnt.target1_bg2_on = 1;
    data_027e1268->unk_00->bldcnt.target1_bg3_on = 0;
    data_027e1268->unk_00->bldcnt.target1_obj_on = 0;
    data_027e1268->unk_00->bldcnt.target1_bd_on = 0;

    data_027e1268->unk_00->bldcnt.target2_bg0_on = 1;
    data_027e1268->unk_00->bldcnt.target2_bg1_on = 0;
    data_027e1268->unk_00->bldcnt.target2_bg2_on = 0;
    data_027e1268->unk_00->bldcnt.target2_bg3_on = 0;
    data_027e1268->unk_00->bldcnt.target2_obj_on = 0;
    data_027e1268->unk_00->bldcnt.target2_bd_on = 0;

    return;
}

// func_0201b938
void anime::EffectBGBlend::vfunc_00()
{
    this->unk_20++;

    func_0201b72c(
        this, Interpolate(0, this->unk_10, this->unk_18, this->unk_20, this->unk_24),
        Interpolate(0, this->unk_14, this->unk_1c, this->unk_20, this->unk_24));

    if (this->unk_20 == this->unk_24)
    {
        func_0201ac14(this);
    }

    return;
}

struct VmMap_Common
{
    STRUCT_PAD(0x00, 0x04);
    u16 unk_04;
    u8 unk_06;
    u8 unk_07;
    void * unk_08;
};

EC void func_02012180(char *);
EC s32 func_020b6de0(char *); // strlen?
EC void func_020b6c98(char *, char *); // strcpy?

EC void func_020a58b8(void *, void *, s32);

EC void func_0206e66c(struct VmMap_Common *, char *);
EC void func_0206e69c(struct VmMap_Common *, char *);
EC void func_0206e724(struct VmMap_Common *, char *, s32);

EC void func_0201b9b4(char * dirName, char * fileName)
{
    struct VmMap_Common * iVar1;
    s32 length;
    char buf[32];

    if (dirName != NULL)
    {
        func_02012180("/onfx");
        func_02012180(dirName);

        iVar1 = static_cast<struct VmMap_Common *>(HashTable::Get2("VmMap_BG2Free"));

        length = func_020b6de0(fileName);
        func_020a58b8(fileName, buf, length);

        func_020b6c98(buf + length, ".cg");
        func_0206e66c(iVar1, buf);

        func_020b6c98(buf + length, ".sc");
        func_0206e69c(iVar1, buf);

        func_020b6c98(buf + length, ".cl");
        func_0206e724(iVar1, buf, 0);

        data_027e1268->unk_3e |= (1 << iVar1->unk_07);
    }

    return;
}

EC void func_01ff9948(s32);

EC void func_0201ba90(void)
{
    struct VmMap_Common * iVar1;

    iVar1 = static_cast<struct VmMap_Common *>(HashTable::Get2("VmMap_BG2Free"));
    func_01ff9948(iVar1->unk_07);

    data_027e1268->unk_3e |= (1 << iVar1->unk_07);

    return;
}

EC s32 func_0201bb74(anime::EffectAlpha3D *);

// func_0201bad0
anime::EffectAlpha3D::EffectAlpha3D(Anime * anime, s32 b, s32 c) : Effect(anime)
{
    this->unk_10 = func_0201bb74(this);
    this->unk_14 = b;
    this->unk_1c = c;
    this->unk_18 = 0;

    if (c <= 0)
    {
        func_0201ac14(this);
    }
}

EC void func_0201bb8c(anime::EffectAlpha3D *, s32);

// func_0201bb24
// func_0201bb48
anime::EffectAlpha3D::~EffectAlpha3D()
{
    func_0201bb8c(this, this->unk_14);
}

EC s32 func_0201bb74(anime::EffectAlpha3D * self)
{
    Anime_3c * pAVar2 = self->unk_04->unk_3c;

    if (pAVar2 != NULL)
    {
        return pAVar2->unk_33;
    }

    return 31;
}

EC void func_0201bb8c(anime::EffectAlpha3D * self, s32 b)
{
    Anime_3c * pAVar1 = self->unk_04->unk_3c;

    if (pAVar1 != NULL)
    {
        func_0201a094(pAVar1, b);
    }

    return;
}

// func_0201bba8
void anime::EffectAlpha3D::vfunc_00(void)
{
    this->unk_18++;

    Interpolate(0, this->unk_10, this->unk_14, this->unk_18, this->unk_1c);

    func_0201bb8c(this, Interpolate(0, this->unk_10, this->unk_14, this->unk_18, this->unk_1c));

    if (this->unk_18 == this->unk_1c)
    {
        func_0201ac14(this);
    }

    return;
}
