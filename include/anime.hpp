#ifndef ANIME_HPP
#define ANIME_HPP

#include "global.h"

#include "proc_ex.hpp"

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

EC Anime * StartAnimByName(char * animName, u16 arg2, u16 arg3, u16 arg4, u16 arg5, s32 arg6, ProcEx * parent);

#endif // ANIME_HPP