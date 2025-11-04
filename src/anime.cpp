#include "global.h"

#include <new>

#include "hardware.hpp"
#include "hashtable.hpp"
#include "map.hpp"
#include "proc_ex.hpp"
#include "sound_manager.hpp"

EC void func_02012180(char *);
EC s32 func_020b6de0(char *); // strlen?
EC void func_020b6c98(char *, char *); // strcpy?

EC void func_020a58b8(void *, void *, s32);

EC void func_0206e66c(struct VmMap_Common *, char *);
EC void func_0206e69c(struct VmMap_Common *, char *);
EC void func_0206e724(struct VmMap_Common *, char *, s32);

EC s32 Interpolate(s32, s32, s32, s32, s32);
EC s32 IntSys_Div(s32, s32);

EC void func_01ff9948(s32);
EC void func_01ffb574(s32, s16, s16, s16, s16); // SetObjAffine?
EC void func_01ffbb90(void *, void *);
EC void func_01ffc4e4(s16, s16, u16, u16, s32, s32, s32);
EC void func_01ffc614(s16, s16, u16, u16, s32, s32, s32);
EC void func_01ffc668(s16, s16, u16, u16, s32, s32, s32);

EC void func_0201b9b4(char *, char *);
EC void func_0201ba90(void);
EC void func_ov000_021d39a4(s32, s32, s32);
EC void func_ov000_021d3a2c(void);
EC s32 func_ov000_021d6f7c(s32);

EC void * func_02011920(char *, BOOL);

EC void func_0206ce8c(s32);
EC void func_0206d2e8(s32, s32, s32, s32, s32, s32, s32);

namespace anime
{
class Effect;
}

class Anime;

struct AnimeCmd
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

class AnimeInterpreter
{
public:
    /* 00 */ Anime * unk_00;
    /* 04 */ AnimeInterpreter * unk_04;
    /* 08 */ AnimeInterpreter * unk_08;
    /* 0C */ s32 * unk_0c;
    /* 10 */ struct AnimeCmd * unk_10;
    /* 14 */ s32 unk_14; // TODO: probably a pointer?
    /* 18 */ s32 unk_18; // TODO: probably a pointer?
    /* 1C */ struct AnimeCmd * unk_1c;
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

    AnimeInterpreter(Anime *, void *, u16, u16, u16, u16, s32);
    AnimeInterpreter(AnimeInterpreter *, u32);

    void func_02019f40(u8 arg2);
    void SetPosition(u32 arg2, u32 arg3);
    void SetVisible(BOOL arg2);
    void SetFlag2(BOOL arg2);
    void SetFlag4(BOOL arg2);
    void SetAffineId(s32 arg2);
    void SetRotScale(s32 arg2, s32 arg3, s32 arg4, s32 arg5, u8 arg6);
    void func_0201a078(s32 arg2);
    void SetAlpha(s32 arg2);
    void SetLoopingEnabled(BOOL arg2);
    void SetFlag16(BOOL arg2);
    void SetFlag32(BOOL arg2);
    void SetUnk34(s32 arg2);
    void UnlinkAndDestroy(void);
    void DestroyAll(void);
    void Execute(void);
    void func_0201a5b0(void);
    void Draw(void);
    void DrawInternal(s32 arg1, s32 arg2);
};

class Anime : public ProcEx
{
public:
    /* 38 */ void (*unk_38)(Anime *);
    /* 3C */ AnimeInterpreter * unk_3c;
    /* 40 */ anime::Effect * unk_40;
    /* 44 */ void * unk_44;
    /* 48 */ s32 unk_48;
    /* 4C */ u8 unk_4c;

    Anime(void *, u16, u16, u16, u16, s32, u8);

    virtual ~Anime();

    void Update(void);
    void Draw(void);
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

    void UnlinkAndDestroy(void);
    void DestroyAll(void);
    void DestroyBlendEffects(void);
    void TickAll(void);

    virtual void Tick(void);
    virtual ~Effect() {};
};

class EffectAlpha3D : public Effect
{
public:
    /* 10 */ s32 unk_10;
    /* 14 */ s32 unk_14;
    /* 18 */ s32 unk_18;
    /* 1C */ s32 unk_1c;

    EffectAlpha3D(Anime * anime, s32 b, s32 c);

    s32 GetAlpha(void);
    void SetAlpha(s32);

    virtual void Tick(void);
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

    s32 GetBrightness(void);
    void SetBrightness(s32 arg2);

    virtual void Tick(void);
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

    EffectBlend(Anime * anime, s32 b, s32 c, s32 d);

    s32 GetBlendCoeffA(void);
    s32 GetBlendCoeffB(void);
    void SetBlend(s32, s32);

    virtual void Tick(void);
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

    EffectBGBlend(Anime * anime, s32 b, s32 c, s32 d);

    s32 GetBlendCoeffA(void);
    s32 GetBlendCoeffB(void);
    void SetBGBlend(s32, s32);

    virtual void Tick(void);
    virtual ~EffectBGBlend();
};

} // namespace anime

AnimeInterpreter::AnimeInterpreter(Anime * arg0, void * arg1, u16 arg2, u16 arg3, u16 arg4, u16 arg5, s32 arg6)
{
    this->unk_0c = (s32 *)arg1;
    this->unk_38 = arg2;
    this->unk_14 = (s32)arg1 + this->unk_0c[0];
    this->unk_18 = (s32)arg1 + this->unk_0c[1];
    this->unk_10 = (struct AnimeCmd *)((u8 *)this->unk_0c + (this->unk_0c + this->unk_38)[2]);

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

AnimeInterpreter::AnimeInterpreter(AnimeInterpreter * other, u32 arg2)
{
    AnimeInterpreter * it;
    AnimeInterpreter * next;

    next = other->unk_08;

    for (it = next; it != NULL; it = it->unk_08)
    {
        other = it;
    }

    this->unk_0c = other->unk_0c;
    this->unk_38 = arg2;
    this->unk_14 = (s32)((u8 *)this->unk_0c + this->unk_0c[0]);
    this->unk_10 = (struct AnimeCmd *)((u8 *)this->unk_0c + (this->unk_0c + this->unk_38)[2]);
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

void AnimeInterpreter::func_02019f40(u8 arg2)
{
    this->unk_38 = arg2;
    this->unk_10 = (struct AnimeCmd *)((u8 *)this->unk_0c + (this->unk_0c + this->unk_38)[2]);
    this->unk_20 = 0;
    return;
}

void AnimeInterpreter::SetPosition(u32 x, u32 y)
{
    this->unk_24 = x;
    this->unk_26 = y;

    if (this->unk_08 != NULL)
    {
        this->unk_08->SetPosition(x, y);
    }

    return;
}

void AnimeInterpreter::SetVisible(BOOL isVisible)
{
    if (isVisible)
    {
        this->unk_39 |= 1;
    }
    else
    {
        this->unk_39 &= ~1;
    }

    return;
}

void AnimeInterpreter::SetFlag2(BOOL isFlag2)
{
    if (isFlag2)
    {
        this->unk_39 |= 2;
    }
    else
    {
        this->unk_39 &= ~2;
    }

    if (this->unk_08 != NULL)
    {
        this->unk_08->SetFlag2(isFlag2);
    }

    return;
}

void AnimeInterpreter::SetFlag4(BOOL isFlag4)
{
    if (isFlag4)
    {
        this->unk_39 |= 4;
    }
    else
    {
        this->unk_39 &= ~4;
    }

    if (this->unk_08 != NULL)
    {
        this->unk_08->SetFlag4(isFlag4);
    }

    return;
}

void AnimeInterpreter::SetAffineId(s32 id)
{
    this->unk_3a = id;

    if (this->unk_08 != NULL)
    {
        this->unk_08->SetAffineId(id);
    }

    return;
}

void AnimeInterpreter::SetRotScale(s32 arg2, s32 arg3, s32 arg4, s32 arg5, u8 arg6)
{
    this->unk_39 |= 0x40;

    if (arg6 != 0)
    {
        this->unk_39 |= 0x80;
    }

    this->unk_2c = arg2;
    this->unk_30 = arg3;
    this->unk_32 = arg4;
    this->unk_33 = arg5;

    if (this->unk_08 != NULL)
    {
        this->unk_08->SetRotScale(arg2, arg3, arg4, arg5, 0);
    }

    return;
}

void AnimeInterpreter::func_0201a078(s32 arg2)
{
    this->unk_30 = arg2;

    if (this->unk_08 != NULL)
    {
        this->unk_08->func_0201a078(arg2);
    }

    return;
}

void AnimeInterpreter::SetAlpha(s32 arg2)
{
    this->unk_33 = arg2;

    if (this->unk_08 != NULL)
    {
        this->unk_08->SetAlpha(arg2);
    }

    return;
}

void AnimeInterpreter::SetLoopingEnabled(BOOL isEnabled)
{
    if (isEnabled)
    {
        this->unk_39 |= 8;
    }
    else
    {
        this->unk_39 &= ~8;
    }

    if (this->unk_08 != NULL)
    {
        // BUG: Should this call `SetLoopingEnabled`?
        this->unk_08->SetFlag16(isEnabled);
    }

    return;
}

void AnimeInterpreter::SetFlag16(BOOL arg2)
{
    if (arg2)
    {
        this->unk_39 |= 0x10;
    }
    else
    {
        this->unk_39 &= ~0x10;
    }

    if (this->unk_08 != NULL)
    {
        this->unk_08->SetFlag16(arg2);
    }

    return;
}

void AnimeInterpreter::SetFlag32(BOOL arg2)
{
    if (arg2)
    {
        this->unk_39 |= 0x20;
    }
    else
    {
        this->unk_39 &= ~0x20;
    }

    if (this->unk_08 != NULL)
    {
        this->unk_08->SetFlag32(arg2);
    }

    return;
}

void AnimeInterpreter::SetUnk34(s32 arg2)
{
    this->unk_34 = arg2;

    if (this->unk_08 != NULL)
    {
        this->unk_08->SetUnk34(arg2);
    }

    return;
}

void AnimeInterpreter::UnlinkAndDestroy(void)
{
    if (this->unk_04 != NULL)
    {
        this->unk_04->unk_08 = this->unk_08;

        if (this->unk_08 != NULL)
        {
            this->unk_08->unk_04 = this->unk_04;
        }

        if (this != NULL)
        {
            delete this;
            return;
        }
    }
    else
    {
        this->unk_00->unk_3c = this->unk_08;

        if (this->unk_08 != NULL)
        {
            this->unk_08->unk_04 = NULL;
        }

        if (this != NULL)
        {
            delete this;
            return;
        }
    }

    return;
}

void AnimeInterpreter::DestroyAll(void)
{
    AnimeInterpreter * it;
    AnimeInterpreter * next;

    it = this;

    this->func_0201a5b0();

    for (; it != NULL; it = next)
    {
        next = it->unk_08;
        if (it != NULL)
        {
            delete it;
        }
    }

    this->unk_00->unk_3c = NULL;

    return;
}

void AnimeInterpreter::Execute(void)
{
    AnimeInterpreter * child = this->unk_08;

    if (this->unk_20 == 0)
    {
        while (this->unk_10->unk_03 != 0 || this->unk_10->unk_00 == 0)
        {
            if (this->unk_10->unk_03 != 0)
            {
                switch (this->unk_10->unk_02)
                {
                    case 0x00:
                    case 0xFF:
                        if ((this->unk_39 & 8) != 0)
                        {
                            this->unk_10 = (AnimeCmd *)((int)this->unk_0c + this->unk_0c[this->unk_38 + 2]);
                        }
                        else
                        {
                            this->UnlinkAndDestroy();
                            goto _0201a58c;
                        }

                        continue;

                    case 0x01:
                        this->unk_10 = (AnimeCmd *)((int)this->unk_0c + this->unk_0c[this->unk_38 + 2]);
                        continue;

                    case 0x02:
                        goto _0201a58c;
                        break;

                    case 0x03:
                        break;

                    case 0x04:
                    {
                        AnimeCmd * p = (AnimeCmd *)((int)this->unk_0c + this->unk_0c[this->unk_38 + 2]);

                        while (p->unk_03 == 0 || p->unk_02 != 0xFF)
                        {
                            if (p->unk_03 != 0)
                            {
                                if (p->unk_02 == 0x03)
                                {
                                    if (p->unk_06 == this->unk_10->unk_06)
                                    {
                                        this->unk_10 = p;
                                        break;
                                    }
                                }
                            }

                            this->unk_10++;
                        }

                        continue;
                    }

                    case 0x10:
                        if (this->unk_10->unk_06 > 0)
                        {
                            child = new AnimeInterpreter(this, this->unk_10->unk_06 - 1);
                            child = this->unk_08;
                        }

                        break;

                    case 0x11:
                        this->unk_37 = this->unk_10->unk_06 & 0xFFFF;
                        break;

                    case 0x12:
                        this->unk_33 = this->unk_10->unk_06 & 0xFFFF;
                        new anime::EffectAlpha3D(this->unk_00, this->unk_10->unk_06, this->unk_10->unk_08);
                        break;

                    case 0x20:
                        new anime::EffectBright(this->unk_00, this->unk_10->unk_06, this->unk_10->unk_08);
                        break;

                    case 0x21:
                        new anime::EffectBlend(
                            this->unk_00, this->unk_10->unk_06, this->unk_10->unk_08, this->unk_10->unk_0a);
                        break;

                    case 0x22:
                        this->unk_00->unk_40->DestroyBlendEffects();
                        data_027e1268->unk_00->bldcnt.effect = 0;
                        break;

                    case 0x23:
                        func_0201b9b4((char *)this->unk_00->unk_48, (char *)(this->unk_18 + this->unk_10->unk_06));
                        break;

                    case 0x24:
                        func_0201ba90();
                        break;

                    case 0x25:
                        new anime::EffectBGBlend(
                            this->unk_00, this->unk_10->unk_06, this->unk_10->unk_08, this->unk_10->unk_0a);
                        break;

                    case 0x26:
                    {
                        s32 v = this->unk_10->unk_06;
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
                        if ((this->unk_39 & 0x10) == 0)
                        {
                            s32 arg = 0;
                            if (this->unk_39 & 0x20)
                            {
                                arg = func_ov000_021d6f7c(this->unk_24);
                            }

                            data_020efcc8->unk_b0->vfunc_2c(this->unk_18 + this->unk_10->unk_06, 0, arg);
                        }

                        break;
                }
            }

            this->unk_10++;
        }

        this->unk_20 = this->unk_10->unk_00;
        this->unk_1c = this->unk_10;
        this->unk_10++;
    }

    this->unk_20--;

_0201a58c:
    if (child != NULL)
    {
        child->Execute();
    }
}

void AnimeInterpreter::func_0201a5b0(void)
{
    AnimeInterpreter * child = this->unk_08;

    if (this->unk_00->unk_40 != NULL)
    {
        this->unk_00->unk_40->DestroyAll();
    }

    while (this->unk_10->unk_03 != 0 || this->unk_10->unk_00 == 0)
    {
        if (this->unk_10->unk_03 != 0)
        {
            switch (this->unk_10->unk_02)
            {
                case 0x00:
                case 0x01:
                case 0x02:
                    goto _0201a854;

                case 0x04:
                {
                    AnimeCmd * p = (AnimeCmd *)((int)this->unk_0c + this->unk_0c[this->unk_38 + 2]);

                    while (p->unk_03 == 0 || p->unk_02 != 0xFF)
                    {
                        if (p->unk_03 != 0)
                        {
                            if (p->unk_02 == 0x03)
                            {
                                if (p->unk_06 == this->unk_10->unk_06)
                                {
                                    this->unk_10 = p;
                                    break;
                                }
                            }
                        }

                        this->unk_10++;
                    }

                    continue;
                }

                case 0x10:
                    if (this->unk_10->unk_06 > 0)
                    {
                        child = new AnimeInterpreter(this, this->unk_10->unk_06 - 1);
                        child = this->unk_08;
                    }

                    break;

                case 0x20:
                    new anime::EffectBright(this->unk_00, this->unk_10->unk_06, this->unk_10->unk_08);
                    if (this->unk_00->unk_40 != NULL)
                    {
                        this->unk_00->unk_40->DestroyAll();
                    }
                    break;

                case 0x21:
                    new anime::EffectBlend(
                        this->unk_00, this->unk_10->unk_06, this->unk_10->unk_08, this->unk_10->unk_0a);
                    if (this->unk_00->unk_40 != NULL)
                    {
                        this->unk_00->unk_40->DestroyAll();
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
                        this->unk_00, this->unk_10->unk_06, this->unk_10->unk_08, this->unk_10->unk_0a);
                    if (this->unk_00->unk_40 != NULL)
                    {
                        this->unk_00->unk_40->DestroyAll();
                    }
                    break;

                case 0x26:
                {
                    s32 v = this->unk_10->unk_06;
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

        this->unk_10++;
    }

    this->unk_10++;

_0201a854:
    if (child != NULL)
    {
        child->func_0201a5b0();
    }
}

void AnimeInterpreter::Draw(void)
{
    if (!(this->unk_39 & 1))
    {
        this->DrawInternal(this->unk_24, this->unk_26);
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

void AnimeInterpreter::DrawInternal(s32 arg1, s32 arg2)
{
    s32 temp_r5;
    u16 var_r4;

    struct AnimeCmd * temp_r0 = this->unk_1c;

    if (temp_r0 != NULL)
    {
        temp_r5 = this->unk_0c[this->unk_14 + temp_r0->unk_02];

        if (this->unk_39 & 0x40)
        {
            if (this->unk_33 != 0)
            {
                func_0206ce8c(this->unk_32);
                func_0206d2e8(
                    arg1, arg2, this->unk_36 + this->unk_37, this->unk_2c + (this->unk_34 >> 5),
                    this->unk_30 + ((this->unk_34 >> 0xC) << 5), temp_r5,
                    ((this->unk_39 & 0x80) ? TRUE : FALSE) & 0xFF);
            }
        }
        else
        {
            var_r4 = this->unk_28;
            if (this->unk_3a != 0)
            {
                s32 xScale = clamp(abs(temp_r0->unk_08), -2, 2);
                s32 c = cos(temp_r0->unk_04);
                s32 yScale = clamp(abs(temp_r0->unk_06), -2, 2);
                s32 s = sin(temp_r0->unk_04);

                // clang-format off
                func_01ffb574(
                    this->unk_3a,
                    IntSys_Div(+c * 0x10, xScale),
                    IntSys_Div(-s * 0x10, yScale),
                    IntSys_Div(+s * 0x10, xScale),
                    IntSys_Div(+c * 0x10, yScale)
                );
                // clang-format on
                var_r4 |= (u32)(this->unk_3a << 0x1B) >> 0x12;
            }

            if (this->unk_39 & 2)
            {
                func_01ffc614(
                    arg1, arg2, var_r4, this->unk_2a, this->unk_34, temp_r5, (this->unk_36 + this->unk_37) & 0xff);
            }
            else
            {
                if (this->unk_39 & 4)
                {
                    func_01ffc668(
                        arg1, arg2, var_r4, this->unk_2a, this->unk_34, temp_r5, (this->unk_36 + this->unk_37) & 0xff);
                }
                else
                {
                    func_01ffc4e4(
                        arg1, arg2, var_r4, this->unk_2a, this->unk_34, temp_r5, (this->unk_36 + this->unk_37) & 0xff);
                }
            }
        }
    }

    if (this->unk_08 != NULL)
    {
        this->unk_08->DrawInternal(arg1, arg2);
    }

    return;
}

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

void anime::Effect::UnlinkAndDestroy(void)
{
    if (this->unk_08 != NULL)
    {
        this->unk_08->unk_0c = this->unk_0c;

        if (this->unk_0c != NULL)
        {
            this->unk_0c->unk_08 = this->unk_08;
        }

        delete this;
    }
    else
    {
        this->unk_04->unk_40 = this->unk_0c;

        if (this->unk_0c != NULL)
        {
            this->unk_0c->unk_08 = NULL;
        }

        delete this;
    }

    return;
}

// anime::Effect::~Effect()
// {
// }

void anime::Effect::DestroyAll(void)
{
    anime::Effect * next;

    anime::Effect * it = this;

    for (; it != NULL; it = next)
    {
        next = it->unk_0c;
        delete it;
    }

    this->unk_04->unk_40 = NULL;

    return;
}

void anime::Effect::DestroyBlendEffects(void)
{
    anime::Effect * next;

    anime::Effect * it = this;

    for (; it != NULL; it = next)
    {
        next = it->unk_0c;

        if (dynamic_cast<anime::EffectBlend *>(it) != NULL)
        {
            it->UnlinkAndDestroy();
        }

        if (dynamic_cast<anime::EffectBGBlend *>(it) != NULL)
        {
            it->UnlinkAndDestroy();
        }
    }

    return;
}

void anime::Effect::TickAll(void)
{
    this->Tick();

    if (this->unk_0c != NULL)
    {
        this->unk_0c->TickAll();
    }

    return;
}

void anime::Effect::Tick(void)
{
    return;
}

Anime::Anime(void * file, u16 arg2, u16 arg3, u16 arg4, u16 arg5, s32 arg6, u8 arg7)
{
    this->unk_44 = file;
    this->unk_3c = NULL;
    this->unk_40 = 0;
    this->unk_38 = 0;
    this->unk_4c = arg7;

    new AnimeInterpreter(this, file, arg2, arg3, arg4, arg5, arg6);
}

extern u8 data_027e1b9c[];

Anime::~Anime()
{
    if (this->unk_3c != NULL)
    {
        this->unk_3c->DestroyAll();
    }

    if (this->unk_40 != NULL)
    {
        this->unk_40->DestroyAll();
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

void Anime::Update(void)
{
    if (this->unk_3c != NULL)
    {
        this->unk_3c->Execute();
    }

    if (this->unk_40 != NULL)
    {
        this->unk_40->TickAll();
    }

    if (this->unk_3c == NULL && this->unk_40 == NULL)
    {
        Proc_End(this);
    }

    return;
}

void Anime::Draw(void)
{
    if (this->unk_3c != NULL)
    {
        this->unk_3c->Draw();
    }

    return;
}

EC void Anime_Update(Anime * proc)
{
    proc->Update();
    return;
}

EC void Anime_Loop(Anime * proc)
{
    proc->Loop();
    return;
}

extern struct ProcCmd ProcScr_Anime[];

EC void StartAnimFromFile(void * file, u16 arg2, u16 arg3, u16 arg4, u16 arg5, s32 arg6, u8 arg7, ProcEx * parent)
{
    if (parent == NULL)
    {
        parent = static_cast<ProcEx *>(PROC_TREE_B);
    }

    new (Proc_Start(ProcScr_Anime, parent)) Anime(file, arg2, arg3, arg4, arg5, arg6, arg7);

    return;
}

EC void StartAnimByName(char * animName, u16 arg2, u16 arg3, u16 arg4, u16 arg5, s32 arg6, ProcEx * parent)
{
    void * file = func_02011920(animName, 0);
    StartAnimFromFile(file, arg2, arg3, arg4, arg5, arg6, 1, parent);
    return;
}

anime::EffectBright::EffectBright(Anime * anime, s32 b, s32 c) : Effect(anime)
{
    this->unk_10 = this->GetBrightness();
    this->unk_14 = b;
    this->unk_1c = c;
    this->unk_18 = 0;

    if (c <= 0)
    {
        this->UnlinkAndDestroy();
    }
}

anime::EffectBright::~EffectBright()
{
    this->SetBrightness(this->unk_14);
}

s32 anime::EffectBright::GetBrightness(void)
{
    if (gMapStateManager != NULL)
    {
        return gMapStateManager->unk_14->unk_25;
    }

    return 0;
}

void anime::EffectBright::SetBrightness(s32 arg2)
{
    if (gMapStateManager != NULL)
    {
        gMapStateManager->unk_14->unk_25 = arg2;
    }

    return;
}

void anime::EffectBright::Tick()
{
    this->unk_18++;

    Interpolate(0, this->unk_10, this->unk_14, this->unk_18, this->unk_1c);
    this->SetBrightness(Interpolate(0, this->unk_10, this->unk_14, this->unk_18, this->unk_1c));

    if (this->unk_18 == this->unk_1c)
    {
        this->UnlinkAndDestroy();
    }

    return;
}

anime::EffectBlend::EffectBlend(Anime * anime, s32 b, s32 c, s32 d) : Effect(anime)
{
    this->unk_10 = this->GetBlendCoeffA();
    this->unk_14 = this->GetBlendCoeffB();
    this->unk_18 = b;
    this->unk_1c = c;
    this->unk_24 = d;
    this->unk_20 = 0;

    if (d <= 0)
    {
        this->UnlinkAndDestroy();
    }
}

anime::EffectBlend::~EffectBlend()
{
    this->SetBlend(this->unk_18, this->unk_1c);
}

s32 anime::EffectBlend::GetBlendCoeffA(void)
{
    if ((data_027e1268->unk_00->bldcnt.effect == 1) && (data_027e1268->unk_00->bldcnt.target1_obj_on != 0) &&
        (data_027e1268->unk_00->bldcnt.target2_bg0_on != 0))
    {
        return data_027e1268->unk_00->blend_coeff_a;
    }

    return 0;
}

s32 anime::EffectBlend::GetBlendCoeffB(void)
{
    if ((data_027e1268->unk_00->bldcnt.effect == 1) && (data_027e1268->unk_00->bldcnt.target1_obj_on != 0) &&
        (data_027e1268->unk_00->bldcnt.target2_bg0_on != 0))
    {
        return data_027e1268->unk_00->blend_coeff_b;
    }

    return 0x10;
}

void anime::EffectBlend::SetBlend(s32 bldA, s32 bldB)
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

void anime::EffectBlend::Tick()
{
    this->unk_20++;

    this->SetBlend(
        Interpolate(0, this->unk_10, this->unk_18, this->unk_20, this->unk_24),
        Interpolate(0, this->unk_14, this->unk_1c, this->unk_20, this->unk_24));

    if (this->unk_20 == this->unk_24)
    {
        this->UnlinkAndDestroy();
    }

    return;
}

anime::EffectBGBlend::EffectBGBlend(Anime * anime, s32 b, s32 c, s32 d) : Effect(anime)
{
    this->unk_10 = this->GetBlendCoeffA();
    this->unk_14 = this->GetBlendCoeffB();
    this->unk_18 = b;
    this->unk_1c = c;
    this->unk_24 = d;
    this->unk_20 = 0;

    if (d <= 0)
    {
        this->UnlinkAndDestroy();
    }
}

anime::EffectBGBlend::~EffectBGBlend()
{
    this->SetBGBlend(this->unk_18, this->unk_1c);
}

s32 anime::EffectBGBlend::GetBlendCoeffA(void)
{
    if ((data_027e1268->unk_00->bldcnt.effect == 1) && (data_027e1268->unk_00->bldcnt.target1_bg2_on != 0) &&
        (data_027e1268->unk_00->bldcnt.target2_bg0_on != 0))
    {
        return data_027e1268->unk_00->blend_coeff_a;
    }

    return 0;
}

s32 anime::EffectBGBlend::GetBlendCoeffB(void)
{
    if ((data_027e1268->unk_00->bldcnt.effect == 1) && (data_027e1268->unk_00->bldcnt.target1_bg2_on != 0) &&
        (data_027e1268->unk_00->bldcnt.target2_bg0_on != 0))
    {
        return data_027e1268->unk_00->blend_coeff_b;
    }

    return 0x10;
}

void anime::EffectBGBlend::SetBGBlend(s32 bldA, s32 bldB)
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

void anime::EffectBGBlend::Tick()
{
    this->unk_20++;

    this->SetBGBlend(
        Interpolate(0, this->unk_10, this->unk_18, this->unk_20, this->unk_24),
        Interpolate(0, this->unk_14, this->unk_1c, this->unk_20, this->unk_24));

    if (this->unk_20 == this->unk_24)
    {
        this->UnlinkAndDestroy();
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

EC void func_0201ba90(void)
{
    struct VmMap_Common * iVar1;

    iVar1 = static_cast<struct VmMap_Common *>(HashTable::Get2("VmMap_BG2Free"));
    func_01ff9948(iVar1->unk_07);

    data_027e1268->unk_3e |= (1 << iVar1->unk_07);

    return;
}

anime::EffectAlpha3D::EffectAlpha3D(Anime * anime, s32 b, s32 c) : Effect(anime)
{
    this->unk_10 = this->GetAlpha();
    this->unk_14 = b;
    this->unk_1c = c;
    this->unk_18 = 0;

    if (c <= 0)
    {
        this->UnlinkAndDestroy();
    }
}

anime::EffectAlpha3D::~EffectAlpha3D()
{
    this->SetAlpha(this->unk_14);
}

s32 anime::EffectAlpha3D::GetAlpha(void)
{
    AnimeInterpreter * interpreter = this->unk_04->unk_3c;

    if (interpreter != NULL)
    {
        return interpreter->unk_33;
    }

    return 31;
}

void anime::EffectAlpha3D::SetAlpha(s32 alpha)
{
    AnimeInterpreter * interpreter = this->unk_04->unk_3c;

    if (interpreter != NULL)
    {
        interpreter->SetAlpha(alpha);
    }

    return;
}

void anime::EffectAlpha3D::Tick(void)
{
    this->unk_18++;

    Interpolate(0, this->unk_10, this->unk_14, this->unk_18, this->unk_1c);

    this->SetAlpha(Interpolate(0, this->unk_10, this->unk_14, this->unk_18, this->unk_1c));

    if (this->unk_18 == this->unk_1c)
    {
        this->UnlinkAndDestroy();
    }

    return;
}
