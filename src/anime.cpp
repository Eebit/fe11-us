#include "global.h"

#include <new>

#include "hardware.hpp"
#include "hashtable.hpp"
#include "heap.hpp"
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
    /* 00 */ u16 frameCount;
    /* 02 */ u8 opcode;
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
    /* 00 */ Anime * owner;
    /* 04 */ AnimeInterpreter * prev;
    /* 08 */ AnimeInterpreter * next;
    /* 0C */ s32 * unk_0c;
    /* 10 */ struct AnimeCmd * cmd;
    /* 14 */ s32 unk_14; // TODO: probably a pointer?
    /* 18 */ s32 unk_18; // TODO: probably a pointer?
    /* 1C */ struct AnimeCmd * lastCmd;
    /* 20 */ s32 delayTimer;
    /* 24 */ s16 xPos;
    /* 26 */ s16 yPos;
    /* 28 */ u16 unk_28;
    /* 2A */ u16 unk_2a;
    /* 2C */ u32 unk_2c;
    /* 30 */ u16 unk_30;
    /* 32 */ u8 unk_32;
    /* 33 */ u8 alpha;
    /* 34 */ u16 unk_34;
    /* 36 */ u8 unk_36;
    /* 37 */ u8 unk_37;
    /* 38 */ u8 unk_38;
    /* 39 */ u8 flags;
    /* 3A */ u8 affineId;
    /* 3B */ STRUCT_PAD(0x3B, 0x3C);

    AnimeInterpreter(Anime *, void *, u16, u16, u16, u16, s32);
    AnimeInterpreter(AnimeInterpreter *, u32);

    void func_02019f40(u8 arg2);
    void SetPosition(u32 x, u32 y);
    void SetVisible(BOOL isVisible);
    void SetFlag2(BOOL arg2);
    void SetFlag4(BOOL arg2);
    void SetAffineId(s32 id);
    void SetRotScale(s32 arg2, s32 arg3, s32 arg4, s32 arg5, u8 arg6);
    void func_0201a078(s32 arg2);
    void SetAlpha(s32 alpha);
    void SetLoopingEnabled(BOOL isEnabled);
    void SetFlag16(BOOL arg2);
    void SetFlag32(BOOL arg2);
    void SetUnk34(s32 arg2);
    void UnlinkAndDestroy(void);
    void DestroyAll(void);
    void Execute(void);
    void func_0201a5b0(void);
    void Draw(void);
    void DrawInternal(s32 x, s32 y);
};

class Anime : public ProcEx
{
public:
    /* 38 */ void (*onDestroy)(Anime *);
    /* 3C */ AnimeInterpreter * interpreter;
    /* 40 */ anime::Effect * effect;
    /* 44 */ void * file;
    /* 48 */ s32 unk_48;
    /* 4C */ u8 ownsFile;

    Anime(void *, u16, u16, u16, u16, s32, u8);

    virtual ~Anime();
    virtual void Loop();

    void Update(void);
};

namespace anime
{
class Effect
{
public:
    /* 00 */ // vtable
    /* 04 */ Anime * parent;
    /* 08 */ Effect * prev;
    /* 0C */ Effect * next;

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
    /* 10 */ s32 initial;
    /* 14 */ s32 target;
    /* 18 */ s32 currentFrame;
    /* 1C */ s32 duration;

    EffectAlpha3D(Anime * anime, s32 targetAlpha, s32 duration);

    s32 GetAlpha(void);
    void SetAlpha(s32);

    virtual void Tick(void);
    virtual ~EffectAlpha3D();
};

class EffectBright : public Effect
{
public:
    /* 10 */ u32 initialBrightness;
    /* 14 */ u32 targetBrightness;
    /* 18 */ u32 currentFrame;
    /* 1C */ u32 duration;

    EffectBright(Anime * anime, s32 targetBrightness, s32 duration);

    s32 GetBrightness(void);
    void SetBrightness(s32 arg2);

    virtual void Tick(void);
    virtual ~EffectBright();
};

class EffectBlend : public Effect
{
public:
    /* 10 */ s32 initialBldA;
    /* 14 */ s32 initialBldB;
    /* 18 */ s32 targetBldA;
    /* 1C */ s32 targetBldB;
    /* 20 */ s32 currentFrame;
    /* 24 */ s32 duration;

    EffectBlend(Anime * anime, s32 targetBldA, s32 targetBldB, s32 duration);

    s32 GetBlendCoeffA(void);
    s32 GetBlendCoeffB(void);
    void SetBlend(s32, s32);

    virtual void Tick(void);
    virtual ~EffectBlend();
};

class EffectBGBlend : public Effect
{
public:
    /* 10 */ s32 initialBldA;
    /* 14 */ s32 initialBldB;
    /* 18 */ s32 targetBldA;
    /* 1C */ s32 targetBldB;
    /* 20 */ s32 currentFrame;
    /* 24 */ s32 duration;

    EffectBGBlend(Anime * anime, s32 targetBldA, s32 targetBldB, s32 duration);

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
    this->cmd = (struct AnimeCmd *)((u8 *)this->unk_0c + (this->unk_0c + this->unk_38)[2]);

    this->xPos = arg3 & 0x1ff;

    if ((arg3 & 0x100) != 0)
    {
        this->xPos |= 0xfe00;
    }

    this->yPos = arg4 & 0xff;

    if (arg4 >= 0xc0)
    {
        this->yPos |= 0xff00;
    }

    this->unk_28 = arg3 & 0xfe00;
    this->unk_2a = arg4 & 0xff00;

    this->unk_34 = arg5;
    this->unk_2c = 0;
    this->unk_30 = 0;
    this->unk_32 = 0;
    this->alpha = 0x1f;
    this->unk_36 = arg6;
    this->unk_37 = 0;
    this->flags = 0;
    this->affineId = 0;
    this->lastCmd = 0;
    this->delayTimer = 0;
    this->owner = arg0;
    this->prev = 0;
    this->next = 0;

    arg0->interpreter = this;
}

AnimeInterpreter::AnimeInterpreter(AnimeInterpreter * other, u32 arg2)
{
    AnimeInterpreter * it;
    AnimeInterpreter * next;

    next = other->next;

    for (it = next; it != NULL; it = it->next)
    {
        other = it;
    }

    this->unk_0c = other->unk_0c;
    this->unk_38 = arg2;
    this->unk_14 = (s32)((u8 *)this->unk_0c + this->unk_0c[0]);
    this->cmd = (struct AnimeCmd *)((u8 *)this->unk_0c + (this->unk_0c + this->unk_38)[2]);
    this->xPos = other->xPos;
    this->yPos = other->yPos;
    this->unk_28 = other->unk_28;
    this->unk_2a = other->unk_2a;
    this->unk_34 = other->unk_34;
    this->unk_2c = other->unk_2c;
    this->unk_30 = other->unk_30;
    this->unk_32 = other->unk_32;
    this->alpha = other->alpha;
    this->unk_36 = other->unk_36;
    this->flags = other->flags;
    this->affineId = other->affineId;
    this->lastCmd = 0;
    this->delayTimer = 0;
    this->owner = other->owner;

    this->prev = other;
    next = other->next;
    this->next = next;

    if (next != NULL)
    {
        next->prev = this;
    }

    other->next = this;

    return;
}

void AnimeInterpreter::func_02019f40(u8 arg2)
{
    this->unk_38 = arg2;
    this->cmd = (struct AnimeCmd *)((u8 *)this->unk_0c + (this->unk_0c + this->unk_38)[2]);
    this->delayTimer = 0;
    return;
}

void AnimeInterpreter::SetPosition(u32 x, u32 y)
{
    this->xPos = x;
    this->yPos = y;

    if (this->next != NULL)
    {
        this->next->SetPosition(x, y);
    }

    return;
}

void AnimeInterpreter::SetVisible(BOOL isVisible)
{
    if (isVisible)
    {
        this->flags |= 1;
    }
    else
    {
        this->flags &= ~1;
    }

    return;
}

void AnimeInterpreter::SetFlag2(BOOL isFlag2)
{
    if (isFlag2)
    {
        this->flags |= 2;
    }
    else
    {
        this->flags &= ~2;
    }

    if (this->next != NULL)
    {
        this->next->SetFlag2(isFlag2);
    }

    return;
}

void AnimeInterpreter::SetFlag4(BOOL isFlag4)
{
    if (isFlag4)
    {
        this->flags |= 4;
    }
    else
    {
        this->flags &= ~4;
    }

    if (this->next != NULL)
    {
        this->next->SetFlag4(isFlag4);
    }

    return;
}

void AnimeInterpreter::SetAffineId(s32 id)
{
    this->affineId = id;

    if (this->next != NULL)
    {
        this->next->SetAffineId(id);
    }

    return;
}

void AnimeInterpreter::SetRotScale(s32 arg2, s32 arg3, s32 arg4, s32 alpha, u8 arg6)
{
    this->flags |= 0x40;

    if (arg6 != 0)
    {
        this->flags |= 0x80;
    }

    this->unk_2c = arg2;
    this->unk_30 = arg3;
    this->unk_32 = arg4;
    this->alpha = alpha;

    if (this->next != NULL)
    {
        this->next->SetRotScale(arg2, arg3, arg4, alpha, 0);
    }

    return;
}

void AnimeInterpreter::func_0201a078(s32 arg2)
{
    this->unk_30 = arg2;

    if (this->next != NULL)
    {
        this->next->func_0201a078(arg2);
    }

    return;
}

void AnimeInterpreter::SetAlpha(s32 alpha)
{
    this->alpha = alpha;

    if (this->next != NULL)
    {
        this->next->SetAlpha(alpha);
    }

    return;
}

void AnimeInterpreter::SetLoopingEnabled(BOOL isEnabled)
{
    if (isEnabled)
    {
        this->flags |= 8;
    }
    else
    {
        this->flags &= ~8;
    }

    if (this->next != NULL)
    {
        // BUG: Should this call `SetLoopingEnabled`?
        this->next->SetFlag16(isEnabled);
    }

    return;
}

void AnimeInterpreter::SetFlag16(BOOL arg2)
{
    if (arg2)
    {
        this->flags |= 0x10;
    }
    else
    {
        this->flags &= ~0x10;
    }

    if (this->next != NULL)
    {
        this->next->SetFlag16(arg2);
    }

    return;
}

void AnimeInterpreter::SetFlag32(BOOL arg2)
{
    if (arg2)
    {
        this->flags |= 0x20;
    }
    else
    {
        this->flags &= ~0x20;
    }

    if (this->next != NULL)
    {
        this->next->SetFlag32(arg2);
    }

    return;
}

void AnimeInterpreter::SetUnk34(s32 arg2)
{
    this->unk_34 = arg2;

    if (this->next != NULL)
    {
        this->next->SetUnk34(arg2);
    }

    return;
}

void AnimeInterpreter::UnlinkAndDestroy(void)
{
    if (this->prev != NULL)
    {
        this->prev->next = this->next;

        if (this->next != NULL)
        {
            this->next->prev = this->prev;
        }

        if (this != NULL)
        {
            delete this;
            return;
        }
    }
    else
    {
        this->owner->interpreter = this->next;

        if (this->next != NULL)
        {
            this->next->prev = NULL;
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
        next = it->next;
        if (it != NULL)
        {
            delete it;
        }
    }

    this->owner->interpreter = NULL;

    return;
}

void AnimeInterpreter::Execute(void)
{
    AnimeInterpreter * child = this->next;

    if (this->delayTimer == 0)
    {
        while (this->cmd->unk_03 != 0 || this->cmd->frameCount == 0)
        {
            if (this->cmd->unk_03 != 0)
            {
                switch (this->cmd->opcode)
                {
                    case 0x00:
                    case 0xFF:
                        if ((this->flags & 8) != 0)
                        {
                            this->cmd = (AnimeCmd *)((int)this->unk_0c + this->unk_0c[this->unk_38 + 2]);
                        }
                        else
                        {
                            this->UnlinkAndDestroy();
                            goto _0201a58c;
                        }

                        continue;

                    case 0x01:
                        this->cmd = (AnimeCmd *)((int)this->unk_0c + this->unk_0c[this->unk_38 + 2]);
                        continue;

                    case 0x02:
                        goto _0201a58c;
                        break;

                    case 0x03:
                        break;

                    case 0x04:
                    {
                        AnimeCmd * p = (AnimeCmd *)((int)this->unk_0c + this->unk_0c[this->unk_38 + 2]);

                        while (p->unk_03 == 0 || p->opcode != 0xFF)
                        {
                            if (p->unk_03 != 0)
                            {
                                if (p->opcode == 0x03)
                                {
                                    if (p->unk_06 == this->cmd->unk_06)
                                    {
                                        this->cmd = p;
                                        break;
                                    }
                                }
                            }

                            this->cmd++;
                        }

                        continue;
                    }

                    case 0x10:
                        if (this->cmd->unk_06 > 0)
                        {
                            child = new AnimeInterpreter(this, this->cmd->unk_06 - 1);
                            child = this->next;
                        }

                        break;

                    case 0x11:
                        this->unk_37 = this->cmd->unk_06 & 0xFFFF;
                        break;

                    case 0x12:
                        this->alpha = this->cmd->unk_06 & 0xFFFF;
                        new anime::EffectAlpha3D(this->owner, this->cmd->unk_06, this->cmd->unk_08);
                        break;

                    case 0x20:
                        new anime::EffectBright(this->owner, this->cmd->unk_06, this->cmd->unk_08);
                        break;

                    case 0x21:
                        new anime::EffectBlend(
                            this->owner, this->cmd->unk_06, this->cmd->unk_08, this->cmd->unk_0a);
                        break;

                    case 0x22:
                        this->owner->effect->DestroyBlendEffects();
                        data_027e1268->unk_00->bldcnt.effect = 0;
                        break;

                    case 0x23:
                        func_0201b9b4((char *)this->owner->unk_48, (char *)(this->unk_18 + this->cmd->unk_06));
                        break;

                    case 0x24:
                        func_0201ba90();
                        break;

                    case 0x25:
                        new anime::EffectBGBlend(
                            this->owner, this->cmd->unk_06, this->cmd->unk_08, this->cmd->unk_0a);
                        break;

                    case 0x26:
                    {
                        s32 v = this->cmd->unk_06;
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
                        if ((this->flags & 0x10) == 0)
                        {
                            s32 arg = 0;
                            if (this->flags & 0x20)
                            {
                                arg = func_ov000_021d6f7c(this->xPos);
                            }

                            data_020efcc8->unk_b0->vfunc_2c(this->unk_18 + this->cmd->unk_06, 0, arg);
                        }

                        break;
                }
            }

            this->cmd++;
        }

        this->delayTimer = this->cmd->frameCount;
        this->lastCmd = this->cmd;
        this->cmd++;
    }

    this->delayTimer--;

_0201a58c:
    if (child != NULL)
    {
        child->Execute();
    }
}

void AnimeInterpreter::func_0201a5b0(void)
{
    AnimeInterpreter * child = this->next;

    if (this->owner->effect != NULL)
    {
        this->owner->effect->DestroyAll();
    }

    while (this->cmd->unk_03 != 0 || this->cmd->frameCount == 0)
    {
        if (this->cmd->unk_03 != 0)
        {
            switch (this->cmd->opcode)
            {
                case 0x00:
                case 0x01:
                case 0x02:
                    goto _0201a854;

                case 0x04:
                {
                    AnimeCmd * p = (AnimeCmd *)((int)this->unk_0c + this->unk_0c[this->unk_38 + 2]);

                    while (p->unk_03 == 0 || p->opcode != 0xFF)
                    {
                        if (p->unk_03 != 0)
                        {
                            if (p->opcode == 0x03)
                            {
                                if (p->unk_06 == this->cmd->unk_06)
                                {
                                    this->cmd = p;
                                    break;
                                }
                            }
                        }

                        this->cmd++;
                    }

                    continue;
                }

                case 0x10:
                    if (this->cmd->unk_06 > 0)
                    {
                        child = new AnimeInterpreter(this, this->cmd->unk_06 - 1);
                        child = this->next;
                    }

                    break;

                case 0x20:
                    new anime::EffectBright(this->owner, this->cmd->unk_06, this->cmd->unk_08);
                    if (this->owner->effect != NULL)
                    {
                        this->owner->effect->DestroyAll();
                    }
                    break;

                case 0x21:
                    new anime::EffectBlend(
                        this->owner, this->cmd->unk_06, this->cmd->unk_08, this->cmd->unk_0a);
                    if (this->owner->effect != NULL)
                    {
                        this->owner->effect->DestroyAll();
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
                        this->owner, this->cmd->unk_06, this->cmd->unk_08, this->cmd->unk_0a);
                    if (this->owner->effect != NULL)
                    {
                        this->owner->effect->DestroyAll();
                    }
                    break;

                case 0x26:
                {
                    s32 v = this->cmd->unk_06;
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

        this->cmd++;
    }

    this->cmd++;

_0201a854:
    if (child != NULL)
    {
        child->func_0201a5b0();
    }
}

void AnimeInterpreter::Draw(void)
{
    if (!(this->flags & 1))
    {
        this->DrawInternal(this->xPos, this->yPos);
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

    struct AnimeCmd * temp_r0 = this->lastCmd;

    if (temp_r0 != NULL)
    {
        temp_r5 = this->unk_0c[this->unk_14 + temp_r0->opcode];

        if (this->flags & 0x40)
        {
            if (this->alpha != 0)
            {
                func_0206ce8c(this->unk_32);
                func_0206d2e8(
                    arg1, arg2, this->unk_36 + this->unk_37, this->unk_2c + (this->unk_34 >> 5),
                    this->unk_30 + ((this->unk_34 >> 0xC) << 5), temp_r5,
                    ((this->flags & 0x80) ? TRUE : FALSE) & 0xFF);
            }
        }
        else
        {
            var_r4 = this->unk_28;
            if (this->affineId != 0)
            {
                s32 xScale = clamp(abs(temp_r0->unk_08), -2, 2);
                s32 c = cos(temp_r0->unk_04);
                s32 yScale = clamp(abs(temp_r0->unk_06), -2, 2);
                s32 s = sin(temp_r0->unk_04);

                // clang-format off
                func_01ffb574(
                    this->affineId,
                    IntSys_Div(+c * 0x10, xScale),
                    IntSys_Div(-s * 0x10, yScale),
                    IntSys_Div(+s * 0x10, xScale),
                    IntSys_Div(+c * 0x10, yScale)
                );
                // clang-format on
                var_r4 |= (u32)(this->affineId << 0x1B) >> 0x12;
            }

            if (this->flags & 2)
            {
                func_01ffc614(
                    arg1, arg2, var_r4, this->unk_2a, this->unk_34, temp_r5, (this->unk_36 + this->unk_37) & 0xff);
            }
            else
            {
                if (this->flags & 4)
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

    if (this->next != NULL)
    {
        this->next->DrawInternal(arg1, arg2);
    }

    return;
}

anime::Effect::Effect(Anime * anime)
{
    anime::Effect * it;
    anime::Effect * next;

    this->parent = anime;
    next = anime->effect;

    if (next == NULL)
    {
        this->prev = NULL;
        this->next = NULL;
        anime->effect = this;
        return;
    }

    for (it = next->next; it != NULL; it = it->next)
    {
        next = it;
    }

    this->prev = next;
    it = next->next;
    this->next = it;

    if (it != NULL)
    {
        it->prev = this;
    }

    next->next = this;
}

void anime::Effect::UnlinkAndDestroy(void)
{
    if (this->prev != NULL)
    {
        this->prev->next = this->next;

        if (this->next != NULL)
        {
            this->next->prev = this->prev;
        }

        delete this;
    }
    else
    {
        this->parent->effect = this->next;

        if (this->next != NULL)
        {
            this->next->prev = NULL;
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
        next = it->next;
        delete it;
    }

    this->parent->effect = NULL;

    return;
}

void anime::Effect::DestroyBlendEffects(void)
{
    anime::Effect * next;

    anime::Effect * it = this;

    for (; it != NULL; it = next)
    {
        next = it->next;

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

    if (this->next != NULL)
    {
        this->next->TickAll();
    }

    return;
}

void anime::Effect::Tick(void)
{
    return;
}

Anime::Anime(void * file, u16 arg2, u16 arg3, u16 arg4, u16 arg5, s32 arg6, u8 arg7)
{
    this->file = file;
    this->interpreter = NULL;
    this->effect = 0;
    this->onDestroy = 0;
    this->ownsFile = arg7;

    new AnimeInterpreter(this, file, arg2, arg3, arg4, arg5, arg6);
}

Anime::~Anime()
{
    if (this->interpreter != NULL)
    {
        this->interpreter->DestroyAll();
    }

    if (this->effect != NULL)
    {
        this->effect->DestroyAll();
    }

    if (this->onDestroy != NULL)
    {
        this->onDestroy(this);
    }

    if (this->ownsFile != 0)
    {
        gHeap.Free(this->file);
    }
}

void Anime::Update(void)
{
    if (this->interpreter != NULL)
    {
        this->interpreter->Execute();
    }

    if (this->effect != NULL)
    {
        this->effect->TickAll();
    }

    if (this->interpreter == NULL && this->effect == NULL)
    {
        Proc_End(this);
    }

    return;
}

void Anime::Loop(void)
{
    if (this->interpreter != NULL)
    {
        this->interpreter->Draw();
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

// clang-format off

struct ProcCmd ProcScr_Anime[] =
{
    PROC_NAME,
    PROC_SLEEP(0),

    PROC_06(0, Anime_Loop),
    PROC_REPEAT(Anime_Update),

    PROC_END,
};

// clang-format on

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

anime::EffectBright::EffectBright(Anime * anime, s32 targetBrightness, s32 duration) : Effect(anime)
{
    this->initialBrightness = this->GetBrightness();
    this->targetBrightness = targetBrightness;
    this->duration = duration;
    this->currentFrame = 0;

    if (duration <= 0)
    {
        this->UnlinkAndDestroy();
    }
}

anime::EffectBright::~EffectBright()
{
    this->SetBrightness(this->targetBrightness);
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
    this->currentFrame++;

    Interpolate(0, this->initialBrightness, this->targetBrightness, this->currentFrame, this->duration);
    this->SetBrightness(Interpolate(0, this->initialBrightness, this->targetBrightness, this->currentFrame, this->duration));

    if (this->currentFrame == this->duration)
    {
        this->UnlinkAndDestroy();
    }

    return;
}

anime::EffectBlend::EffectBlend(Anime * anime, s32 targetBldA, s32 targetBldB, s32 duration) : Effect(anime)
{
    this->initialBldA = this->GetBlendCoeffA();
    this->initialBldB = this->GetBlendCoeffB();
    this->targetBldA = targetBldA;
    this->targetBldB = targetBldB;
    this->duration = duration;
    this->currentFrame = 0;

    if (duration <= 0)
    {
        this->UnlinkAndDestroy();
    }
}

anime::EffectBlend::~EffectBlend()
{
    this->SetBlend(this->targetBldA, this->targetBldB);
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
    this->currentFrame++;

    this->SetBlend(
        Interpolate(0, this->initialBldA, this->targetBldA, this->currentFrame, this->duration),
        Interpolate(0, this->initialBldB, this->targetBldB, this->currentFrame, this->duration));

    if (this->currentFrame == this->duration)
    {
        this->UnlinkAndDestroy();
    }

    return;
}

anime::EffectBGBlend::EffectBGBlend(Anime * anime, s32 targetBldA, s32 targetBldB, s32 duration) : Effect(anime)
{
    this->initialBldA = this->GetBlendCoeffA();
    this->initialBldB = this->GetBlendCoeffB();
    this->targetBldA = targetBldA;
    this->targetBldB = targetBldB;
    this->duration = duration;
    this->currentFrame = 0;

    if (duration <= 0)
    {
        this->UnlinkAndDestroy();
    }
}

anime::EffectBGBlend::~EffectBGBlend()
{
    this->SetBGBlend(this->targetBldA, this->targetBldB);
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
    this->currentFrame++;

    this->SetBGBlend(
        Interpolate(0, this->initialBldA, this->targetBldA, this->currentFrame, this->duration),
        Interpolate(0, this->initialBldB, this->targetBldB, this->currentFrame, this->duration));

    if (this->currentFrame == this->duration)
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

anime::EffectAlpha3D::EffectAlpha3D(Anime * anime, s32 targetAlpha, s32 duration) : Effect(anime)
{
    this->initial = this->GetAlpha();
    this->target = targetAlpha;
    this->duration = duration;
    this->currentFrame = 0;

    if (duration <= 0)
    {
        this->UnlinkAndDestroy();
    }
}

anime::EffectAlpha3D::~EffectAlpha3D()
{
    this->SetAlpha(this->target);
}

s32 anime::EffectAlpha3D::GetAlpha(void)
{
    AnimeInterpreter * interpreter = this->parent->interpreter;

    if (interpreter != NULL)
    {
        return interpreter->alpha;
    }

    return 31;
}

void anime::EffectAlpha3D::SetAlpha(s32 alpha)
{
    AnimeInterpreter * interpreter = this->parent->interpreter;

    if (interpreter != NULL)
    {
        interpreter->SetAlpha(alpha);
    }

    return;
}

void anime::EffectAlpha3D::Tick(void)
{
    this->currentFrame++;

    Interpolate(0, this->initial, this->target, this->currentFrame, this->duration);

    this->SetAlpha(Interpolate(0, this->initial, this->target, this->currentFrame, this->duration));

    if (this->currentFrame == this->duration)
    {
        this->UnlinkAndDestroy();
    }

    return;
}
