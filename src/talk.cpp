#include "global.h"

#include "database.hpp"
#include "unit.hpp"
#include "unknown_types.h"
#include "unknown_types.hpp"
#include <new>

#include "face.hpp"
#include "hardware.hpp"
#include "heap.hpp"
#include "map.hpp"
#include "proc_ex.hpp"
#include "sound_manager.hpp"

#include "constants/sounds.h"

EC void func_0200dcb4(void * obj);
EC void func_0200dc80(void * obj);
EC void func_0200db64(void * obj);
EC void func_0200dc80(void * obj);
EC void func_0200db64(void * obj);

class TalkScroll : public ProcEx
{
public:
    /* 38 */ void * unk_38;
    /* 3C */ s32 unk_3c;
    /* 40 */ s32 unk_40;

    TalkScroll(void * param, s32 count = 1)
    {
        this->unk_40 = count;
        this->unk_38 = param;
        this->unk_3c = count * 8;
    }
    virtual ~TalkScroll();
    virtual void Loop();
};

EC void func_020049b4(void *, u32, u32, u32, u32, u32);

EC void func_0200452c(void *, u32, u32);
EC void func_0200456c(void *, void *, u32);
EC void func_0206eeb0(struct AbstCtrl *, u32, u32);
EC void func_0206ef14(struct AbstCtrl *, u32, u32, u32, u32);
extern AbstCtrl * data_02197718;

struct KWData
{
    STRUCT_PAD(0x00, 0x04);
    /* 04 */ u32 unk_04;
    STRUCT_PAD(0x08, 0x0C);
    /* 0C */ u32 unk_0c;
};

class KW : public ProcEx
{
public:
    /* 38 */ u32 unk_38;
    STRUCT_PAD(0x3C, 0x44);
    /* 44 */ u32 unk_44;
    /* 48 */ s32 unk_48;

    KW(struct KWData * data) : unk_44(0), unk_48(1)
    {
        func_0200452c(&this->unk_38, 0x1c0, 0);
        func_0200456c(&this->unk_38, data, 0);
        func_0206eeb0(data_02197718, data->unk_04, 0xE000);
        func_0206ef14(data_02197718, data->unk_0c, 0, 0, 0x20);
    }
    virtual ~KW();
    virtual void Loop();
    virtual void Init();
};

EC void func_020045fc(void *);
class ILogStream;
EC void func_0200cfb0(ILogStream * log, ProcPtr proc);
class TalkLog;
extern TalkLog data_020e3da8;
extern struct KeyState * gKeySt;
extern struct UnkStruct_02196f24 * data_02196f24;

struct TalkWindowEntry
{
    /* 00 */ struct TalkWindowData * unk_00;
    /* 04 */ s32 unk_04;
    /* 08 */ u16 unk_08;
    /* 0A */ u8 unk_0a;
    /* 0B */ u8 unk_0b;

    TalkWindowEntry()
    {
    }
};

EC void func_0200d73c(TalkWindowEntry * entry, s32, s32, s32);
extern BGCtrl * data_02197700;

struct TalkWindowData
{
    /* 00 */ class TalkFont * unk_00;
    /* 04 */ u32 * unk_04;
    /* 08 */ s32 unk_08;
    /* 0C */ u16 * unk_0c;
    /* 10 */ s32 unk_10;

    TalkWindowData(s32 base, u16 * map, s32 mode);
    ~TalkWindowData();
};

struct TalkPacked
{
    /* 00 */ u32 unk_00;
    /* 04 */ u8 unk_04[1];
};

union UnkStruct_0200c1d0
{
    /* 00 */ u32 word;
    /* 00 */ u8 pixels[4];
};

struct TalkGlyph
{
    /* 00 */ u16 unk_00;
    /* 02 */ s8 unk_02;
    STRUCT_PAD(0x03, 0x04);
    /* 04 */ u8 * unk_04;
};

EC void func_0200c098(u8 * src, u32 * dst, u32 size);
EC void func_0200c1d0(u8 * src, u32 * dst, u32 size);
EC void func_0200c350(u32 * a, u32 * b);

class TalkWindow : public ProcEx
{
public:
    /* 38 */ struct TalkWindowData * unk_38;
    /* 3C */ TalkWindowEntry entries[3];
    /* 60 */ s8 count;
    /* 61 */ s8 unk_61;

    TalkWindow();
    virtual ~TalkWindow();
    void Init();
    virtual void vfunc_10();

    TalkWindowEntry * GetEntry(u32 index)
    {
        return &this->entries[index];
    }
};

EC void func_0200d628(TalkWindowEntry * entry, struct TalkWindowData * data, s32 size);
EC void func_0200c7ac(s32 arg, s32 count, s32 color);

class ILogStream
{
public:
    virtual s32 vfunc_00();
    virtual s32 vfunc_04();
    virtual char * vfunc_08(s32 line);
};

EC void func_0200d65c(TalkWindowEntry * entry, s32);
EC u32 * func_0200d690(TalkWindowEntry * entry);
EC s32 func_0206e768(char * str);
EC char * func_0200d6e0(TalkWindowEntry * entry, char * str);
EC void func_ov000_021b969c(struct MapStateManager_14 *);
EC s32 func_0200c690(void * font, char * str, ...);
EC char * func_0200c4d0(void * font, u32 * arg1, s32 x, char * str);
EC char * func_0200c530(void * font, u32 * arg1, s32 x, char * str);
EC void func_020a5734(s32 value, void * dst, s32 size);
EC void func_0200c6c8(void * unused, u16 * dst, s32 tile, s32 count);
EC s32 func_0200d7f0(struct TalkWindowData * data, s32 size);
EC s32 func_0200d6a4(TalkWindowEntry * entry, char * str);
EC void func_0206f7cc(BGCtrl *, s32, s32, s32, s32, s32);
extern BGCtrl * data_0219770c;

class TalkLogViewer : public ProcEx
{
public:
    /* 38 */ ILogStream * unk_38;
    /* 3C */ struct TalkWindowData * unk_3c;
    /* 40 */ TalkWindowEntry * unk_40;
    /* 44 */ s32 unk_44;
    /* 48 */ s32 unk_48;
    /* 4C */ s32 unk_4c;
    /* 50 */ s32 unk_50;
    /* 54 */ s32 unk_54;

    static void * operator new(size_t size, void * ptr)
    {
        return ptr;
    }

    TalkLogViewer(ILogStream * log);
    virtual ~TalkLogViewer();
    void Loop();

    void DrawLine(s32 line)
    {
        s32 row;
        char * str;

        row = line & 15;
        func_0206f7cc(data_0219770c, 0, row * 2, 8, 2, 0);
        str = this->unk_38->vfunc_08(line);
        func_0200d65c(&this->unk_40[(s16)row], 0);
        if (*str == '~')
        {
            func_0200d6a4(&this->unk_40[(s16)row], &str[1]);
            func_0200d73c(&this->unk_40[(s16)row], 2, row * 2, 61440);
        }
        else
        {
            func_0200d6a4(&this->unk_40[(s16)row], str);
            func_0200d73c(&this->unk_40[(s16)row], 4, row * 2, 57344);
        }
    }

    void DrawLines()
    {
        s32 i;
        s32 line = this->unk_44 / 16;

        for (i = 0; i < 12; i++)
        {
            if (line + i >= 0)
            {
                this->DrawLine(line + i);
            }
        }
    }

    void ApplyScroll()
    {
        BGCtrl * bg;
        s32 scroll;
        s16 value;

        scroll = this->unk_44;
        bg = data_0219770c;
        value = 0;
        if (bg->unk_12 != 0)
        {
            value = bg->unk_16;
        }

        bg->unk_04->dispIo->unk_38[bg->unk_10] = value;
        bg->unk_04->dispIo->unk_40[bg->unk_10] = scroll;
    }
};

class BG1Clr : public ProcEx
{
public:
    /* 38 */ s32 unk_38;

    BG1Clr(s32 param) : unk_38(param)
    {
    }
    virtual ~BG1Clr();
    virtual void Loop();
};

extern BGCtrl * data_0219770c;
extern BGCtrl * data_0219771c;
EC void func_0206f4e0(AbstCtrl *, u8);

class TalkLog : public ILogStream
{
public:
    /* 04 */ char unk_04[64][64];
    /* 1004 */ u8 unk_1004;
    /* 1005 */ s8 unk_1005;
    STRUCT_PAD(0x1006, 0x1008);
    /* 1008 */ u32 unk_1008;
    /* 100C */ char unk_100c;

    s32 vfunc_00();
    s32 vfunc_04();
    char * vfunc_08(s32 line);
};

class TalkInput : public ProcEx
{
public:
    virtual ~TalkInput();
    virtual void Loop();
};

extern struct TouchState * gTouchSt;

EC void func_0200c7ac(s32, s32, s32);
EC void func_0200c850(TalkLog * log);
extern struct ProcCmd data_020ca1ec[];
extern struct ProcCmd data_020ca428[];
extern struct ProcCmd data_020ca588[];

class PalFader : public ProcEx
{
public:
    /* 38 */ s32 unk_38;
    /* 3C */ s32 unk_3c;
    /* 40 */ s32 unk_40;
    /* 44 */ s32 unk_44;

    PalFader(s32 a, s32 b, s32 c, s32 d) : unk_38(a), unk_3c(b), unk_40(c), unk_44(d)
    {
    }
    virtual ~PalFader();
    virtual void Loop();
};

class TalkWait : public ProcEx
{
public:
    /* 38 */ s32 unk_38;

    TalkWait(s32 param) : unk_38(param)
    {
    }
    virtual ~TalkWait();
    virtual void Loop();
};

extern char data_020ca348[];
EC s32 GetFileSize(char * name);
EC BOOL func_0206ec5c(s32 size);
EC void * LoadFileAndCache(char *, u32);

class TalkFont
{
public:
    /* 04 */ void * unk_04;
    /* 08 */ u8 unk_08;

    TalkFont(char * name);
    virtual ~TalkFont();
    virtual void vfunc_08(...);
};

EC s32 func_0200c764(TalkFont * font, char ** str);
EC void * func_0200c720(TalkFont * font, s32 code);

class NameFont : public TalkFont
{
public:
    NameFont(char * name) : TalkFont(name)
    {
    }
    virtual ~NameFont();
};

extern u32 data_020e3d44;
extern struct UnkStruct_021faf8c data_ov002_021faf8c;
EC BOOL IsOverlayLoaded(u32 overlayId);

struct UnkStruct_02197798
{
    ScreenState * unk_00;
    DispIo * unk_04;
};

EC void SetDispEnable_Maybe(struct UnkStruct_02197798 *, s32, s32, s32, s32, s32);
EC void SetBgPriority_Maybe(struct UnkStruct_02197798 *, s32, s32, s32, s32);
EC void SetBldTargetA_Maybe(void *, s32, s32, s32, s32, s32, s32);
EC void SetBldTargetB_Maybe(void *, s32, s32, s32, s32, s32, s32);
EC void func_02006204(void *, s32, s32, s32, struct ProcEx *);

struct TalkLoader
{
    STRUCT_PAD(0x00, 0x08);
};

EC struct TalkLoader * func_02006604(struct TalkLoader *, const char *, BGCtrl *);
EC void func_02006624(struct TalkLoader *);
EC void func_02006670(struct TalkLoader *);
extern struct TalkLoader * data_020e4dd4;
EC void func_02006694(struct TalkLoader *, s32);
EC void func_020066ec(struct TalkLoader *, s32);
EC void func_02006808(struct TalkLoader *, s32, s32, s32);
extern char data_020ca174[];
EC s32 func_02006b0c(struct TalkLoader *);
EC u8 * func_02006b18(struct TalkLoader *);
EC void * func_02006b24(struct TalkLoader *);
EC void func_0206ee78(AbstCtrl *, void *, s32, s32);
EC void func_0206fe18(AbstCtrl *, s32);
EC void func_0206fe20(AbstCtrl *, s32, s32);
EC void func_0206fe48(AbstCtrl *, s32);
EC void func_020a5780(void *, void *, s32);
EC char * GetText(char *);
EC void StartFaceHandle(ProcPtr parent);
EC void func_0200e0dc(void);
extern u8 data_020e4dd8;
extern char data_020ca5c0[];
EC void func_0200c7ac(s32 pal, s32 from, s32 to);
EC void func_0206f8a0(AbstCtrl *, s32, s32, s32, s32, s32);
EC void func_0206f580(AbstCtrl *, s32);
EC void func_0206eee0(AbstCtrl *, s32, s32, s32);
extern struct ProcCmd ProcScr_020ce750[];
EC void func_0206fc44(AbstCtrl *, s32);
EC void func_0206ef9c(AbstCtrl *, s32, s32, s32, s32, s32);
EC void func_0206f0fc(AbstCtrl *, s32, s32, s32, s32);
extern BGCtrl * data_021976f8;

struct UnkStruct_020e3cf8
{
    STRUCT_PAD(0x00, 0x02);
    /* 02 */ u8 unk_02;
    STRUCT_PAD(0x03, 0x18);
    /* 18 */ void * unk_18;

    BOOL HasUnk18()
    {
        return this->unk_18 != NULL;
    }
};

extern struct UnkStruct_020e3cf8 data_020e3cf8;
EC void func_02006b70(void * obj);
EC void func_02013530(void * obj, s32, s32, s32);
EC BOOL IsWirelessBattle(void);
EC struct UnkStruct_02197798 * func_0206ecb0(void);
EC struct UnkStruct_02197798 * func_0206eca4(void);
EC void func_02006398(void *, u32, u32, struct ProcEx *);
struct PersonData;
class Unit;
EC char * func_02008ae4(char ** ppStr);
EC s32 func_02008a48(char ** ppStr);
EC char * func_02037ef0(struct PersonData * pPerson, Unit * pUnit);
EC char * func_0206e7b8(char * dst, const char * src, s32 size);
EC char * func_0206e7f4(char * dst, const char * src, s32 size);
static inline Face * GetFaceAt(s32 index)
{
    return &gFaceHandle->faces[index];
}

EC s32 Interpolate(s32, s32, s32, s32, s32);
EC void AdjustPaletteBrightness(s32 dst, s32 src, u32 level, u32 count);
EC void func_0200c904(void * log);
EC void func_0200c8b0(void * log);
EC void func_0200c984(void * log, s32 chr);
EC void func_0200ca38(void * log, char * name);
EC void func_0200c9f0(void * log, char * str);
EC s32 func_020b6e2c(char *, char *);
EC void func_020062e8(void *, s32, s32, ProcPtr);
EC void func_0200452c(void *, u32, u32);
EC void func_0200456c(void *, void *, u32);
EC void func_0206eeb0(struct AbstCtrl *, u32, u32);
EC void func_0206ef14(struct AbstCtrl *, u32, u32, u32, u32);
class EventSkip
{
public:
    static void SkipTransitionFrom0To2(void);
    static BOOL IsSkipState4(void);
};
EC char * func_ov000_021a418c(char * str);
EC void func_02006e38(void * obj, char * path, s32, s32);
EC void func_02006d3c(void * obj);
EC BOOL FileExists(char * path);
EC void func_020a8f40(char * path);
extern Unit * data_021974f0;
extern char data_020ca15c[];
extern char data_020ca18c[];
extern char data_020ca148[];
extern char data_020ca14c[];
extern char data_020ca154[];
extern char data_020ca16c[];
extern char data_020e3d48[];

EC void func_020379c0(void * obj);
EC void func_020135b8(void);
EC BOOL func_0200e83c(s32 mode, char * name, struct Proc * parent);
EC BOOL func_0200e8e4(void);
EC void func_0200e208(void);
EC void func_02004460(void * obj);
EC void EndFaceHandle(void);
class Talk : public ProcEx
{
public:
    STRUCT_PAD(0x36, 0x38);
    /* 38 */ s8 unk_38;
    /* 39 */ s8 unk_39;
    /* 3A */ s8 unk_3a;
    /* 3B */ u8 unk_3b;
    /* 3C */ u8 unk_3c;
    /* 3D */ u8 unk_3d;
    STRUCT_PAD(0x3E, 0x40);
    /* 40 */ char * unk_40;
    /* 44 */ TalkWindow * unk_44;
    /* 48 */ void * unk_48;
    /* 4C */ ProcPtr unk_4c;
    /* 50 */ u8 * unk_50;

    Talk(char * str, s32 flag);
    virtual ~Talk();
    virtual void Loop();
    virtual void Init();

    s32 RunCommand();
    s32 Advance();
    s32 GetDelay();
    void SkipText();
    void Restart(char * str, s32 flag);
    void ScanHold();
};

EC s32 IsAddressInVramRange(s32);
EC void func_01ffc404(u16, u16, u16, u16 *, s32);
extern AbstCtrl * data_02197718;
extern u16 data_020ca54c[4];

class TalkName : public ProcEx
{
public:
    /* 38 */ s32 unk_38;
    /* 3C */ u8 unk_3c;
    /* 3D */ char unk_3d[0x28];

    TalkName(s32 param) : unk_38(param)
    {
    }
    TalkName(s32 param, char * name) : unk_38(param)
    {
        func_0206e7b8(this->unk_3d, name, 40);
        this->unk_3c = 1;
    }
    virtual ~TalkName();
    virtual void Loop();
};

EC s32 func_0200c628(char * font, char * str, ...);
EC s32 func_0200d7e0(struct TalkWindowData * data, char * str)
{
    return func_0200c628((char *)data->unk_00, str);
}

EC s32 func_0200d7f0(struct TalkWindowData * data, s32 size)
{
    s32 result = data->unk_08;

    data->unk_08 = result + size * 2;
    return result;
}

TalkWindow::TalkWindow()
{
    s32 i;
    s32 first;

    this->count = 3;
    this->unk_61 = 0;
    this->unk_38 = new TalkWindowData(data_02197700->vfunc_00() + 64, data_02197700->vfunc_08(), 2);

    first = 0;
    for (i = 0; i < this->count; i++)
    {
        func_0200d628(&this->entries[first + i], this->unk_38, 32);
    }

    func_0200c7ac(data_02197700->vfunc_04(), 8, 32767);
    data_02197700->unk_04->unk_3e |= 16;
    func_0200db64(this);
    this->Init();
}

TalkWindow::~TalkWindow()
{
    struct TalkWindowData * data = this->unk_38;

    if (data != NULL)
    {
        delete data;
    }
}

void TalkWindow::Init()
{
    s32 i;

    for (i = 0; i < this->count; i++)
    {
        func_0200d73c(&this->entries[i], 0, i * 2, 0);
    }

    data_02197700->unk_04->unk_3e |= 1 << data_02197700->unk_10;
}

EC void func_0200db64(void * obj)
{
    TalkWindow * window = (TalkWindow *)obj;
    s32 i;

    for (i = 0; i < window->count; i++)
    {
        func_0200d65c(&window->entries[i], 0);
    }

    window->unk_61 = 0;
}

EC char * func_0200dbb0(TalkWindow * window, char * str)
{
    window->vfunc_10();
    func_0200c984(&data_020e3da8, str[0]);

    if (func_0206e768(str))
    {
        func_0200c984(&data_020e3da8, str[1]);
    }

    return func_0200d6e0(&window->entries[window->unk_61], str);
}

EC void func_0200dc10(TalkWindow * window)
{
    gSoundManager->unk_b0->vfunc_28(SE_SYS_MOJI1, 0, 0);
}

EC void func_0200dc44(TalkWindow * window)
{
    func_0200c8b0(&data_020e3da8);
    window->unk_61++;
}

EC BOOL func_0200dc68(TalkWindow * window)
{
    return window->unk_61 >= window->count;
}

EC void func_0200dc80(void * obj)
{
    TalkWindow * window = (TalkWindow *)obj;

    window->unk_61--;
    if (window->unk_61 < 0)
    {
        window->unk_61 = 0;
    }
    window->entries[window->unk_61].unk_04 = 0;
}

extern u32 data_020e4dcc[];
EC void func_0200dcb4(void * obj)
{
    TalkWindow * window = (TalkWindow *)obj;
    u32 * dst;
    s32 i;
    s32 stride;
    s32 row;
    u32 * src;

    for (i = 0; i < window->count; i++)
    {
        dst = func_0200d690(&window->entries[i]);

        if (i == window->count - 1)
        {
            src = data_020e4dcc;
            stride = 0;
        }
        else
        {
            src = func_0200d690(window->GetEntry(i + 1));
            stride = 16;
        }

        for (row = 0; row < window->entries[i].unk_0b; row++)
        {
            dst[0] = dst[2];
            dst[1] = dst[3];
            dst[2] = dst[4];
            dst[3] = dst[5];
            dst[4] = dst[6];
            dst[5] = dst[7];
            dst[6] = dst[8];
            dst[7] = dst[9];
            dst[8] = dst[10];
            dst[9] = dst[11];
            dst[10] = dst[12];
            dst[11] = dst[13];
            dst[12] = dst[14];
            dst[13] = dst[15];
            dst[14] = src[0];
            dst[15] = src[1];
            src += stride;
            dst += 16;
        }
    }
}

EC void func_0200ddd8(void * obj, ProcPtr parent)
{
    new (Proc_StartBlocking(ProcScr_020ce750, parent)) TalkScroll(obj);
}

EC void func_0200de18(TalkWindow * window, ProcPtr parent)
{
    func_0200c8b0(&data_020e3da8);

    if (data_020e3d44 & 2)
    {
        func_0200db64(window);
        return;
    }

    new (Proc_StartBlocking(ProcScr_020ce750, parent)) TalkScroll(window, window->unk_61 + 1);
}

EC void func_0200de90(void * unused, struct KWData * data, ProcPtr parent)
{
    new (Proc_StartBlocking(ProcScr_020ce750, parent)) KW(data);
}

EC void func_0200df24(void * unused, s32 param, ProcPtr parent)
{
    new (Proc_StartBlocking(ProcScr_020ce750, parent)) TalkWait(param);
}

EC s32 func_02008a48(char ** ppStr)
{
    s32 i;
    s32 value;
    char * p;
    char c;

    p = *ppStr;
    if (p == NULL || (c = *p) == '\0')
    {
        return 0;
    }

    if (c == '|')
    {
        *ppStr = &p[1];
        return 0;
    }

    value = 0;
    i = 0;

    while ((c = **ppStr) != '|' && i < 8)
    {
        value = value * 10;
        if (c >= '0' && c <= '9')
        {
            value += c - '0';
        }
        (*ppStr)++;
        i++;
    }

    (*ppStr)++;
    return value;
}

extern char data_020ca31c[];
extern char data_020e3d68[];
EC s32 func_0206e768(char * str);
EC char * func_02008ae4(char ** ppStr)
{
    s32 i;
    char * p;
    char * out;
    char c;

    p = *ppStr;
    if (p == NULL || (c = *p) == '\0')
    {
        return data_020ca31c;
    }

    if (c == '|')
    {
        *ppStr = &p[1];
        return data_020ca31c;
    }

    out = data_020e3d68;
    i = 0;

    while (**ppStr != '|' && i < 64)
    {
        if (func_0206e768(*ppStr))
        {
            *out = *(*ppStr)++;
            i += 2;
            out[1] = *(*ppStr)++;
            out += 2;
        }
        else
        {
            *out++ = *(*ppStr)++;
            i++;
        }
    }

    *out = '\0';
    (*ppStr)++;
    return data_020e3d68;
}

EC void func_02008bb8(Talk * talk)
{
    if (gFaceHandle->_02008908())
    {
        return;
    }

    talk->Loop();

    return;
}

inline s32 Talk::RunCommand()
{
    s32 value;
    char buf[64];
    char fidBuf[64];
    char fullPath[32];
    char * p;
    char * name;
    char * path;
    Face * face;
    s32 num;

    switch (*this->unk_40)
    {
        case 0:
            func_0200c8b0(&data_020e3da8);
            return 0;
        case 10:
            this->unk_40++;
            func_0200dc44(this->unk_44);
            return 1;
        case 16:
            this->unk_40++;
            func_0200de18(this->unk_44, this);
            return 2;
        case 21:
            func_0200c904(&data_020e3da8);
            return 1;
        case 17:
            this->unk_40++;
            face = &gFaceHandle->faces[this->unk_39];
            if (face->unk_0c_6_7 == 1)
            {
                face->unk_0c_6_7 = 0;
            }
            func_0200de90(this->unk_44, (struct KWData *)this->unk_48, this);
            return 2;
        case 8:
            if (gFaceHandle->faces[this->unk_39].HasFaceInfo())
            {
                p = &this->unk_40[1];
                func_0206e7b8(buf, data_020ca14c, 64);
                func_0206e7f4(buf, func_02008ae4(&p), 64);
                if (func_020b6e2c(gFaceHandle->faces[this->unk_39].GetFid(), buf) == 0)
                {
                    this->unk_40 = p;
                    return 1;
                }
                face = &gFaceHandle->faces[this->unk_39];
                if ((face->unk_18 == 0) ? TRUE : FALSE)
                {
                    face->unk_18 = 8;
                    func_0200e8e4();
                    func_0200de18(this->unk_44, this);
                    return 2;
                }
                face->Hide();
                return 2;
            }
            this->unk_40++;
            gFaceHandle->faces[this->unk_39].unk_0c_8_9 = 2;
            name = func_02008ae4(&this->unk_40);
            if (name[0] == 'M' && name[1] == 'E' && name[2] == '\0')
            {
                if (data_021974f0 != NULL)
                {
                    func_0206e7b8(fidBuf, func_02037ef0(data_021974f0->pPersonData, data_021974f0), 64);
                }
                else
                {
                    func_0206e7b8(fidBuf, data_020ca18c, 64);
                }
            }
            else
            {
                func_0206e7b8(fidBuf, data_020ca15c, 64);
                func_0206e7f4(fidBuf, name, 64);
            }
            gFaceHandle->faces[this->unk_39].unk_0c_1 = (data_020e3d44 & 0x40) ? TRUE : FALSE;
            gFaceHandle->faces[this->unk_39].unk_18 = 8;
            gFaceHandle->faces[this->unk_39]._020077b8(fidBuf, this->unk_39, 0, data_020e3d44 & 0x80);
            return 2;
        case 9:
            face = &gFaceHandle->faces[this->unk_39];
            if ((face->unk_18 == 0) ? TRUE : FALSE)
            {
                face->unk_18 = 8;
                func_0200e8e4();
                func_0200de18(this->unk_44, this);
                return 2;
            }
            this->unk_40++;
            gFaceHandle->faces[this->unk_39].Hide();
            return 2;
        case 6:
            this->unk_39 = 0;
            this->unk_40++;
            return 1;
        case 7:
            this->unk_39 = 1;
            this->unk_40++;
            return 1;
        case 12:
            this->unk_39 = 2;
            this->unk_40++;
            return 1;
        case 14:
            this->unk_3b = 1;
            this->unk_40++;
            return 1;
        case 15:
            this->unk_3b = 0;
            this->unk_40++;
            return 1;
        case 1:
            this->unk_40 += 2;
            switch (this->unk_40[-1])
            {
                case 's':
                    gFaceHandle->faces[this->unk_39].isSmiling = TRUE;
                    return 1;
                case 'a':
                    gFaceHandle->faces[this->unk_39].isSmiling = FALSE;
                    return 1;
                case '@':
                    func_02019124((struct Proc *)this);
                    return 1;
                case 'h':
                    data_020e3d44 |= 0x20;
                    this->unk_40 -= 2;
                    face = &gFaceHandle->faces[this->unk_39];
                    if (face->unk_0c_6_7 != 2)
                    {
                        face->unk_0c_6_7 = 0;
                    }
                    return 2;
                case 'A':
                    face = &gFaceHandle->faces[this->unk_39];
                    face->unk_18 = face->unk_17 = 0;
                    return 1;
            }
            return 1;
        case 2:
            this->unk_40 += 3;
            switch (this->unk_40[-2])
            {
                case 'f':
                    switch (this->unk_40[-1])
                    {
                        case '2':
                            value = 16;
                            break;
                        case '0':
                            value = 0;
                            break;
                        case '1':
                            value = -16;
                            break;
                    }
                    func_02006398(func_0206ecb0(), value, this->unk_3c, this);
                    return 2;
                case 'd':
                    switch (this->unk_40[-1])
                    {
                        case 'l':
                            data_020e3d44 |= 0x200;
                            return 1;
                        case 's':
                            data_020e3d44 |= 0x400;
                            return 1;
                        case 'a':
                            data_020e3d44 |= 0x2000;
                            return 1;
                    }
                    return 4;
                case 'e':
                    switch (this->unk_40[-1])
                    {
                        case 'd':
                            gFaceHandle->faces[this->unk_39].unk_0c_4_5 = 0;
                            return 1;
                        case 'c':
                            gFaceHandle->faces[this->unk_39].unk_0c_4_5 = 1;
                            return 1;
                        case 'o':
                            gFaceHandle->faces[this->unk_39].unk_0c_4_5 = 2;
                            return 1;
                        case 'h':
                            gFaceHandle->faces[this->unk_39].unk_0c_4_5 = 3;
                            return 1;
                    }
                    return 4;
            }
            return 4;
        case 3:
            this->unk_40 += 4;
            return 1;
        case 13:
            this->unk_40++;
            path = func_02008ae4(&this->unk_40);
            if (this->unk_3d != 5)
            {
                func_020a8f40(data_020ca148);
                if (path == NULL || !FileExists(path))
                {
                    if (path == NULL || *path == '\0')
                    {
                        path = func_ov000_021a418c(NULL);
                    }
                    else
                    {
                        func_0206e7b8(fullPath, data_020ca154, 32);
                        func_0206e7f4(fullPath, path, 32);
                        path = func_ov000_021a418c(fullPath);
                    }
                }
                if (path == NULL || !FileExists(path))
                {
                    path = data_020ca16c;
                }
                func_02006e38(&data_020e3cf8, path, (data_020e3d44 & 0x40) ? 1 : 0, 0);
                func_02006d3c(&data_020e3cf8);
            }
            return 1;
        case 4:
            this->unk_40++;
            if (*this->unk_40 == 'F')
            {
                num = 56;
                this->unk_40++;
                if (*this->unk_40 == '|')
                {
                    this->unk_40++;
                }
                else
                {
                    num = func_02008a48(&this->unk_40);
                }
                gSoundManager->unk_a4->vfunc_64(0, num);
                return 1;
            }
            return 4;
        case 5:
            return 4;
        case 11:
            this->unk_40++;
            num = 1 << (*this->unk_40++ - '0');
            if (data_020e3d44 & 1)
            {
                return 1;
            }
            face = &gFaceHandle->faces[this->unk_39];
            if (face->unk_0c_6_7 == 1)
            {
                face->unk_0c_6_7 = 0;
            }
            func_0200df24(this->unk_44, num, this);
            return 2;
        case 18:
            this->unk_40++;
            data_020e3d44 ^= 0x40;
            return 1;
        case 19:
            this->unk_40++;
            num = func_02008a48(&this->unk_40);
            if (num > 255)
            {
                num = 255;
            }
            this->unk_3c = num;
            return 1;
    }
    return 3;
}

inline s32 Talk::Advance()
{
    s32 i;
    s32 index;

    while (TRUE)
    {
        switch (this->RunCommand())
        {
            case 0:
                return 0;
            case 1:
                continue;
            case 2:
                return 2;
            case 3:
            case 4:
                break;
        }

        if (this->unk_3a != this->unk_39)
        {
            this->unk_3a = this->unk_39;
            func_0200de18(this->unk_44, this);
            func_0200e8e4();
            return 2;
        }

        if (func_0200dc68(this->unk_44))
        {
            func_0200ddd8(this->unk_44, this);
            return 2;
        }

        for (i = 0; i < 3; i++)
        {
            gFaceHandle->faces[i].unk_18 = 8;
        }
        gFaceHandle->faces[this->unk_39].unk_18 = 0;

        index = this->unk_39;
        if (gFaceHandle->faces[index].HasFaceInfo())
        {
            if (func_0200e83c(index, gFaceHandle->faces[index].GetName(), (struct Proc *)this))
            {
                return 2;
            }
        }

        gFaceHandle->faces[this->unk_39].unk_0c_6_7 = this->unk_3b;
        this->unk_40 = func_0200dbb0(this->unk_44, this->unk_40);
        return 3;
    }
}

inline s32 Talk::GetDelay()
{
    switch (data_02196f24->messageSpeed)
    {
        case 0:
            return 6;
        case 1:
            return 3;
        case 2:
            return 1;
        case 3:
            return 1;
    }
    return 3;
}

void Talk::Loop()
{
    s32 result;
    s32 i;
    s32 count;

    this->unk_38--;
    count = (data_02196f24->messageSpeed == 3) ? 0xFFFF : 1;
    data_020e3d44 |= 0x4000;

    if (EventSkip::IsSkipState4() || (data_020e3d44 & 0x14))
    {
        Proc_Goto(this, 6, 0);
        return;
    }

    if (data_020e3d44 & 1)
    {
        this->unk_38 = 0;
        count = 0xFFFF;
    }

    if (this->unk_38 != 0)
    {
        return;
    }

    this->unk_38 = this->GetDelay();

    for (i = 0; i < count; i++)
    {
        result = this->Advance();
        if (result == 0)
        {
            Proc_Break(this, 0);
            return;
        }
        if (result != 3)
        {
            return;
        }
    }
}

void PalFader::Loop()
{
    s32 level;

    this->unk_40++;
    level = Interpolate(0, this->unk_38, this->unk_3c, this->unk_40, this->unk_44);

    func_0200c7ac(data_0219770c->vfunc_04() + 384, 0, 16927);
    func_0200c7ac(data_0219770c->vfunc_04() + 416, 0, 32536);
    func_0200c7ac(data_0219770c->vfunc_04() + 448, 0, 32767);
    func_0200c7ac(data_0219770c->vfunc_04() + 480, 0, 895);

    if (level != 16)
    {
        AdjustPaletteBrightness(data_0219770c->vfunc_04() + 384, data_0219770c->vfunc_04() + 384, level, 128);
    }

    data_0219770c->unk_04->unk_3e |= 0x10;

    if (this->unk_40 == this->unk_44)
    {
        Proc_Break(this, 0);
    }
}

void TalkInput::Loop()
{
    if (data_020e3d44 & 0x20)
    {
        return;
    }

    if (!(data_020e3d44 & 0x4000))
    {
        return;
    }

    data_020e3d44 &= ~3;

    if ((gKeySt->pressed & 3) || gTouchSt->unk_14 != 0)
    {
        data_020e3d44 |= 1;
    }

    if (gKeySt->pressed & KEY_BUTTON_R)
    {
        data_020e3d44 |= 8;
    }

    if (gKeySt->pressed & KEY_BUTTON_START)
    {
        if (data_020e3d44 & 0x400)
        {
            data_020e3d44 |= 1;
        }
        else
        {
            data_020e3d44 |= 0x10;
        }
    }

    if ((gKeySt->held & 0x81) == 0x81)
    {
        data_020e3d44 |= 3;
    }
}

void TalkLogViewer::Loop()
{
    BGCtrl * bg;
    s16 value;
    s32 scroll;
    s32 prev;
    s32 cur;
    s32 line;

    this->unk_48 = this->unk_44;

    if (!(gKeySt->held & (KEY_DPAD_UP | KEY_DPAD_DOWN)))
    {
        if (this->unk_4c < 0)
        {
            this->unk_4c++;
        }

        if (this->unk_4c > 0)
        {
            this->unk_4c--;
        }
    }

    if (gKeySt->held & KEY_DPAD_UP)
    {
        this->unk_4c--;
    }

    if (gKeySt->held & KEY_DPAD_DOWN)
    {
        this->unk_4c++;
    }

    if (this->unk_4c > 8)
    {
        this->unk_4c = 8;
    }

    if (this->unk_4c < -8)
    {
        this->unk_4c = -8;
    }

    this->unk_44 += this->unk_4c / 2;

    if (this->unk_44 > this->unk_54)
    {
        this->unk_44 = this->unk_54;
    }

    if (this->unk_44 < this->unk_50)
    {
        this->unk_44 = this->unk_50;
    }

    prev = this->unk_48;
    cur = this->unk_44;
    line = cur / 16;

    if (line < prev / 16)
    {
        if (line >= 0)
        {
            this->DrawLine(line);
        }
    }
    else
    {
        line = (cur + 15) / 16;
        if (line > (prev + 15) / 16)
        {
            if (line + 12 >= 0)
            {
                this->DrawLine(line + 12);
            }
        }
    }

    if (gKeySt->pressed & 0x10A)
    {
        Proc_Break(this, 0);
    }

    scroll = this->unk_44;
    bg = data_0219770c;
    value = 0;
    if (bg->unk_12 != 0)
    {
        value = bg->unk_16;
    }

    bg->unk_04->dispIo->unk_38[bg->unk_10] = value;
    bg->unk_04->dispIo->unk_40[bg->unk_10] = scroll;
}

inline TalkLogViewer::TalkLogViewer(ILogStream * log) : unk_38(log)
{
    struct UnkStruct_02197798 * screen;
    DispIo * dispIo;
    BGCtrl * bg;
    s16 value;
    s32 i;

    this->unk_44 = (log->vfunc_04() - 11) * 16;
    this->unk_48 = this->unk_44;
    this->unk_4c = 0;
    this->unk_54 = this->unk_44;
    this->unk_50 = this->unk_54 - (log->vfunc_00() - 12) * 16;
    if (this->unk_50 < 0)
    {
        this->unk_50 = 0;
    }

    func_0206eca4()->unk_04->dispcnt.mode = 0;
    screen = func_0206eca4();
    screen->unk_04->dispcnt.win0_on = 0;
    screen->unk_04->dispcnt.win1_on = 0;
    screen->unk_04->dispcnt.objWin_on = 0;
    dispIo = func_0206eca4()->unk_00->dispIo;
    dispIo->bldcnt.effect = 0;
    SetDispEnable_Maybe(func_0206eca4(), 1, 1, 0, 1, 1);
    SetBgPriority_Maybe(func_0206eca4(), 2, 0, 3, 2);
    func_0206ef9c(data_0219770c, 0, 0, 26, 0, 0);

    bg = data_0219770c;
    value = 0;
    if (bg->unk_12 != 0)
    {
        value = bg->unk_16;
    }
    bg->unk_04->dispIo->unk_38[bg->unk_10] = value;
    bg->unk_04->dispIo->unk_40[bg->unk_10] = 0;
    func_0206eee0(data_0219770c, 0, 0, 32);

    this->unk_3c = new TalkWindowData(data_0219770c->vfunc_00() + 32, data_0219770c->vfunc_08(), 1);
    this->unk_40 = new TalkWindowEntry[16];
    for (i = 0; i < 16; i++)
    {
        func_0200d628(&this->unk_40[i], this->unk_3c, 26);
    }

    data_0219770c->unk_04->unk_3e |= 1 << data_0219770c->unk_10;
    func_0206f580(data_0219770c, 0);

    this->DrawLines();

    if (this->unk_44 > this->unk_54)
    {
        this->unk_44 = this->unk_54;
    }

    if (this->unk_44 < this->unk_50)
    {
        this->unk_44 = this->unk_50;
    }

    this->ApplyScroll();
}

EC void func_0200cfb0(ILogStream * log, ProcPtr parent)
{
    if (data_020e3d44 & 0x200)
    {
        return;
    }

    new (Proc_StartBlocking(data_020ca428, parent)) TalkLogViewer(log);
}

void BG1Clr::Loop()
{
    this->unk_38--;
    if (this->unk_38 <= 0)
    {
        Proc_End(this);
    }
}

EC void func_0200984c(ProcPtr proc)
{
    struct Proc * p = (struct Proc *)proc;
    p->proc_funcTable->unk_0C(proc);
    return;
}

void TalkWait::Loop()
{
    this->unk_38--;
    if (this->unk_38 == 0)
    {
        Proc_End(this);
    }
}

void KW::Loop()
{
    this->unk_48--;
    if (this->unk_48 >= 0)
    {
        return;
    }

    func_020045fc(&this->unk_38);
    if (data_020e3d44 & 0x15)
    {
        Proc_End(this);
    }
    else if (gKeySt->pressed & KEY_BUTTON_R)
    {
        func_0200cfb0(&data_020e3da8, this);
    }
}

void TalkScroll::Loop()
{
    func_0200dcb4(this->unk_38);

    this->unk_3c--;
    if (this->unk_3c == 0)
    {
        Proc_End(this);
    }
}

s32 TalkLog::vfunc_04()
{
    return this->unk_1008;
}

s32 TalkLog::vfunc_00()
{
    return 64;
}

TalkLogViewer::~TalkLogViewer()
{
    struct TalkWindowData * data;

    delete[] this->unk_40;

    data = this->unk_3c;
    if (data != NULL)
    {
        delete data;
    }
}

BG1Clr::~BG1Clr()
{
    func_0206f4e0(data_0219770c, 0);
}

TalkName::~TalkName()
{
}

EC void func_0200c1d0(u8 * src, u32 * dst, u32 size);
EC void func_0200e938(s32 unused, u64 * dst, s32 x, TalkGlyph * glyph)
{
    u64 buf[32];
    u64 * src;
    u64 mask0;
    u64 mask1;
    s32 lo;
    s32 hi;
    s32 i;
    s32 j;

    func_0200c1d0(glyph->unk_04, (u32 *)buf, 256);
    dst = &dst[(x / 8) * 8];
    lo = (x & 7) * 8;
    hi = (8 - (x & 7)) * 8;
    src = buf;
    for (i = 0; i < 8; i++, dst++)
    {
        mask0 = src[0] & 0xF0F0F0F0F0F0F0F0ULL;
        mask0 = ~(mask0 | (mask0 >> 4));
        mask1 = src[1] & 0xF0F0F0F0F0F0F0F0ULL;
        mask1 = ~(mask1 | (mask1 >> 4));
        dst[0] &= (0xFFFFFFFFFFFFFFFFULL >> hi) | (mask0 << lo);
        dst[0] |= src[0] << lo;
        dst[8] &= (mask0 >> hi) | (mask1 << lo);
        dst[8] |= (src[0] >> hi) | (src[1] << lo);
        dst[16] &= (0xFFFFFFFFFFFFFFFFULL << lo) | (mask1 >> hi);
        dst[16] |= src[1] >> hi;
        src += 2;
    }

    dst += 72;
    for (j = 0; j < 8; j++, dst++)
    {
        mask0 = src[0] & 0xF0F0F0F0F0F0F0F0ULL;
        mask0 = ~(mask0 | (mask0 >> 4));
        mask1 = src[1] & 0xF0F0F0F0F0F0F0F0ULL;
        mask1 = ~(mask1 | (mask1 >> 4));
        dst[0] &= (0xFFFFFFFFFFFFFFFFULL >> hi) | (mask0 << lo);
        dst[0] |= src[0] << lo;
        dst[8] &= (mask0 >> hi) | (mask1 << lo);
        dst[8] |= (src[0] >> hi) | (src[1] << lo);
        dst[16] &= (0xFFFFFFFFFFFFFFFFULL << lo) | (mask1 >> hi);
        dst[16] |= src[1] >> hi;
        src += 2;
    }
}

TalkScroll::~TalkScroll()
{
    if (this->unk_40 == 1)
    {
        func_0200dc80(this->unk_38);
    }
    else
    {
        func_0200db64(this->unk_38);
    }
}

KW::~KW()
{
}

TalkWait::~TalkWait()
{
}

EC void func_0200e0dc(void)
{
    struct TalkLoader * loader;
    u16 * palBuf;
    s32 size;

    data_020e4dd8 = 0;
    if (data_020e4dd4 != NULL)
    {
        return;
    }

    loader = new TalkLoader;
    if (loader != NULL)
    {
        loader = func_02006604(loader, data_020ca5c0, data_0219771c);
    }
    data_020e4dd4 = loader;

    palBuf = static_cast<u16 *>(gHeap._01ffb9bc(512));
    size = func_02006b0c(data_020e4dd4);
    func_020a5780(func_02006b24(data_020e4dd4), palBuf, size);
    func_0200c7ac((s32)&palBuf[240], 0x216D, 0x7FFF);
    data_0219771c->vfunc_10((s32)palBuf, 0, 0x1E00, 512, 0);
    data_02197718->vfunc_10((s32)palBuf, 0, 0x1400, 512, 1);
    data_0219771c->unk_12 = 0;
}

EC void func_0200e208(void)
{
    struct TalkLoader * loader;

    if (data_020e4dd4 == NULL)
    {
        return;
    }
    func_02006670(data_020e4dd4);
    loader = data_020e4dd4;
    if (loader != NULL)
    {
        func_02006624(loader);
        delete loader;
    }
    data_020e4dd4 = NULL;
}

EC void func_0200e254(s32 index, char * str)
{
    s32 x;
    s32 base;

    func_0206eee0(data_0219771c, 0, 0, 64);
    func_0206ee78(data_0219771c, &func_02006b18(data_020e4dd4)[index * 0x780], 64, 0x780);

    NameFont font(NULL);
    x = 48 - func_0200c628((char *)&font, str) / 2;
    func_0200c4d0(&font, (u32 *)data_0219771c->vfunc_00(), x, str);

    base = data_0219771c->vfunc_00();
    func_0206fe18(data_02197718, 0xC800);
    func_0206fe20(data_02197718, base + 0x40, 0x200);
    func_0206fe20(data_02197718, base + 0x2C0, 0x200);
    func_0206fe20(data_02197718, base + 0x540, 0x200);
    func_0206fe48(data_02197718, 0x200);
    func_0206fe20(data_02197718, base + 0x240, 0x80);
    func_0206fe20(data_02197718, base + 0x4C0, 0x80);
    func_0206fe20(data_02197718, base + 0x740, 0x80);
    func_0206fe48(data_02197718, 0x80);
}

inline NameFont::~NameFont()
{
}

EC void func_0200e3e8(TalkFont * font)
{
    font->vfunc_08();
}

void TalkName::Loop()
{
    ScreenState * saved;
    s32 index;

    switch (this->unk_38)
    {
        case 0:
            index = 0;
            break;
        case 1:
            index = 22;
            break;
        case 2:
            index = 11;
            break;
        default:
            index = 0;
            break;
    }

    saved = gpActiveScreenSt;
    gpActiveScreenSt = IsAddressInVramRange(data_02197718->unk_04->objVram) ? gpMainScreenSt : gpSubScreenSt;
    func_01ffc404((index << 3) & 0x1FF, 120, 400, data_020ca54c, 15);
    gpActiveScreenSt = saved;
    this->unk_3c = 0;
}

EC void func_0200e254(s32, char *);
EC void func_0200e4cc(TalkName * name)
{
    s32 value;
    struct UnkStruct_02197798 * screen;
    DispIo * io;

    func_0206f0fc(data_0219771c, 0, 1, 30, 2);
    func_0206f4e0(data_0219771c, 1);
    func_0206f580(data_0219771c, 0);
    data_0219771c->unk_0c->priority = 0;
    data_0219771c->unk_04->dispIo->unk_40[data_0219771c->unk_10] = 0xFF88;

    switch (name->unk_38)
    {
        case 0:
            value = 0;
            break;
        case 1:
            value = 22;
            break;
        case 2:
            value = 11;
            break;
        default:
            value = 0;
            break;
    }

    func_0206f8a0(data_0219771c, value, 0, 10, 3, 0xF001);

    io = func_0206ecb0()->unk_00->dispIo;
    io->bldcnt.effect = 1;
    SetBldTargetA_Maybe(func_0206ecb0(), 0, 0, 0, 1, 0, 0);
    SetBldTargetB_Maybe(func_0206ecb0(), 1, 1, 1, 0, 1, 1);
    func_0200e254(name->unk_38, name->unk_3d);
    screen = func_0206ecb0();
    screen->unk_00->dispIo->blend_coeff_a = 0;
    screen->unk_00->dispIo->blend_coeff_b = 16;
    func_02006204(func_0206ecb0(), 16, 0, 8, name);
    func_020190ec((struct Proc *)name);
}

EC void func_0200e674(TalkName * name)
{
    s32 value;
    struct UnkStruct_02197798 * screen;
    DispIo * io;

    name->unk_3c = 1;
    func_0206f0fc(data_0219771c, 0, 1, 30, 2);
    func_0206f4e0(data_0219771c, 1);
    func_0206f580(data_0219771c, 0);
    data_0219771c->unk_0c->priority = 0;
    data_0219771c->unk_04->dispIo->unk_40[data_0219771c->unk_10] = 0xFF88;

    switch (name->unk_38)
    {
        case 0:
            value = 0;
            break;
        case 1:
            value = 22;
            break;
        case 2:
            value = 11;
            break;
        default:
            value = 0;
            break;
    }

    func_0206f8a0(data_0219771c, value, 0, 10, 3, 0xF001);

    io = func_0206ecb0()->unk_00->dispIo;
    io->bldcnt.effect = 1;
    SetBldTargetA_Maybe(func_0206ecb0(), 0, 0, 0, 1, 0, 0);
    SetBldTargetB_Maybe(func_0206ecb0(), 1, 1, 1, 0, 1, 1);
    screen = func_0206ecb0();
    screen->unk_00->dispIo->blend_coeff_a = 16;
    screen->unk_00->dispIo->blend_coeff_b = 0;
    func_02006204(func_0206ecb0(), 0, 16, 8, name);
    func_020190ec((struct Proc *)name);
}

EC void func_0200e814(struct Proc * proc)
{
    func_0206f4e0(data_0219771c, 0);
    func_02019124(proc);
}

EC BOOL func_0200e83c(s32 mode, char * name, struct Proc * parent)
{
    if (Proc_Find(data_020ca588) != NULL)
    {
        return FALSE;
    }

    if (data_020e3d44 & 0x80)
    {
        switch (mode)
        {
            case 0:
                mode = 1;
                break;
            case 1:
                mode = 0;
                break;
        }
    }

    func_0200ca38(&data_020e3da8, name);
    new (Proc_Start(data_020ca588, parent)) TalkName(mode, name);
    return TRUE;
}

EC BOOL func_0200e8e4(void)
{
    TalkName * name = (TalkName *)Proc_Find(data_020ca588);

    if (name == NULL)
    {
        return FALSE;
    }

    if (name->unk_3c != 0)
    {
        return FALSE;
    }

    Proc_Break(name, 0);
    return TRUE;
}

PalFader::~PalFader()
{
}

EC void func_0200d628(TalkWindowEntry * entry, struct TalkWindowData * data, s32 size)
{
    entry->unk_00 = data;
    entry->unk_08 = func_0200d7f0(data, size);
    entry->unk_0b = size;
    func_0200d65c(entry, 0);
}

EC void func_0200d65c(TalkWindowEntry * entry, s32 value)
{
    u32 size;
    u32 * dst;

    entry->unk_04 = 0;
    entry->unk_0a = 0;
    size = entry->unk_0b << 6;
    dst = func_0200d690(entry);
    func_020a5734(value, dst, size);
}

EC u32 * func_0200d690(TalkWindowEntry * entry)
{
    return &entry->unk_00->unk_04[entry->unk_08 * 8];
}

EC s32 func_0200d6a4(TalkWindowEntry * entry, char * str)
{
    struct TalkWindowData * data = entry->unk_00;

    func_0200c4d0(data->unk_00, &data->unk_04[entry->unk_08 * 32 / 4], entry->unk_04, str);
    return 0;
}

EC char * func_0200d6e0(TalkWindowEntry * entry, char * str)
{
    s32 width;
    char * result;

    width = func_0200c690(entry->unk_00->unk_00, str);
    result = func_0200c530(entry->unk_00->unk_00, &entry->unk_00->unk_04[entry->unk_08 * 32 / 4], entry->unk_04, str);
    entry->unk_04 += width;
    return result;
}

EC void func_0200d73c(TalkWindowEntry * entry, s32 base, s32 row, s32 offset)
{
    struct TalkWindowData * data = entry->unk_00;

    func_0200c6c8(data->unk_00, &data->unk_0c[base + row * 32], offset + (data->unk_10 + entry->unk_08), entry->unk_0b);
}

EC void func_0200d7d4(struct TalkWindowData * data);

TalkWindowData::TalkWindowData(s32 base, u16 * map, s32 mode)
{
    this->unk_04 = (u32 *)base;
    this->unk_0c = map;
    this->unk_10 = mode;
    func_0200d7d4(this);
    this->unk_00 = new TalkFont(NULL);
}

TalkWindowData::~TalkWindowData()
{
    if (this->unk_00 != NULL)
    {
        delete this->unk_00;
    }
}

EC void func_0200d7d4(struct TalkWindowData * data)
{
    data->unk_08 = 0;
}

TalkInput::~TalkInput()
{
}

EC void func_0200c084(struct TalkPacked * packed, u32 * dst)
{
    func_0200c098(packed->unk_04, dst, packed->unk_00 >> 8);
}

EC void func_0200c098(u8 * src, u32 * dst, u32 size)
{
    s32 end = (s32)&dst[(size & 0xFFFFFC) / 4];
    u32 acc = 0;
    s32 bits = 0;
    u8 flags;
    s32 i;
    s32 j;
    u8 table[8];

    while (TRUE)
    {
        flags = src[0];
        table[0] = src[1] >> 4;
        table[1] = src[1] & 15;
        table[2] = src[2] >> 4;
        table[3] = src[2] & 15;
        table[4] = src[3] >> 4;
        table[5] = src[3] & 15;
        table[6] = src[4] >> 4;
        table[7] = src[4] & 15;
        src += 5;

        for (i = 0; i < 8; i++, flags >>= 1)
        {
            if (flags & 1)
            {
                for (j = 0; j < table[i] + 1; j++)
                {
                    bits++;
                    acc <<= 4;
                    if (bits == 8)
                    {
                        bits = 0;
                        *dst++ = acc;
                    }
                    if ((s32)dst >= end)
                    {
                        return;
                    }
                }
            }
            else
            {
                bits++;
                acc = table[i] | (acc << 4);
                if (bits == 8)
                {
                    bits = 0;
                    *dst++ = acc;
                }
                if ((s32)dst >= end)
                {
                    return;
                }
            }
        }
    }
}

EC void func_0200c1d0(u8 * src, u32 * dst, u32 size)
{
    union UnkStruct_0200c1d0 * cur = (union UnkStruct_0200c1d0 *)dst;
    s32 k;
    s32 end;
    u32 acc = 0;
    s32 bits = 0;
    u8 flags;
    s32 i;
    s32 j;
    u8 table[8];

    size &= 0xFFFFFC;
    end = (s32)&cur->pixels[size];

    while (TRUE)
    {
        flags = src[0];
        table[0] = src[1] >> 4;
        table[1] = src[1] & 15;
        table[2] = src[2] >> 4;
        table[3] = src[2] & 15;
        table[4] = src[3] >> 4;
        table[5] = src[3] & 15;
        table[6] = src[4] >> 4;
        table[7] = src[4] & 15;
        src += 5;

        for (i = 0; i < 8; i++, flags >>= 1)
        {
            if (flags & 1)
            {
                for (j = 0; j < table[i] + 1; j++)
                {
                    bits++;
                    acc <<= 8;
                    if (bits == 4)
                    {
                        bits = 0;
                        (cur++)->word = acc;
                    }
                    if ((s32)cur >= end)
                    {
                        goto swap;
                    }
                }
            }
            else
            {
                bits++;
                acc = (table[i] | 0xF0) | (acc << 8);
                if (bits == 4)
                {
                    bits = 0;
                    (cur++)->word = acc;
                }
                if ((s32)cur >= end)
                {
                    goto swap;
                }
            }
        }
    }

swap:
    for (k = 0; k < (s32)size / 4; k += 2)
    {
        func_0200c350(&dst[k], &dst[k + 1]);
    }
}

EC void func_0200c350(u32 * a, u32 * b)
{
    u32 tmp = *a;

    *a = *b;
    *b = tmp;
}

TalkFont::TalkFont(char * name)
{
    this->unk_08 = FALSE;
    if (name == NULL)
    {
        this->unk_08 = TRUE;
        name = data_020ca348;
    }
    this->unk_04 = NULL;
    if (func_0206ec5c(GetFileSize(name)))
    {
        this->unk_04 = LoadFileAndCache(name, 0);
    }
}

TalkFont::~TalkFont()
{
    if (this->unk_04 != NULL)
    {
        func_020379c0(this->unk_04);
        this->unk_04 = NULL;
    }
}

EC s32 func_0200c690(void * font, char * str, ...);
EC char * func_0200c530(void * font, u32 * arg1, s32 x, char * str);

EC char * func_0200c4d0(void * font, u32 * arg1, s32 x, char * str)
{
    s32 width;

    while (*str != '\0')
    {
        width = func_0200c690(font, str);
        str = func_0200c530(font, arg1, x, str);
        x += width;
    }
    return str;
}

EC char * func_0200c530(void * font, u32 * arg1, s32 x, char * str)
{
    TalkFont * f = (TalkFont *)font;
    void * glyph;

    glyph = func_0200c720(f, func_0200c764(f, &str));
    if (glyph != NULL)
    {
        f->vfunc_08(arg1, x, glyph);
    }
    return str;
}

EC void func_0200c588(s32 unused, u32 * dst, s32 x, TalkGlyph * glyph)
{
    u32 buf[32];
    u32 * q;
    s32 lo;
    s32 hi;
    s32 i;

    func_0200c098(glyph->unk_04, buf, 128);
    dst = &dst[(x / 8) * 16];
    lo = (x & 7) * 4;
    hi = (8 - (x & 7)) * 4;
    q = buf;
    for (i = 0; i < 16; i++)
    {
        dst[0] |= q[0] << lo;
        dst[16] |= (q[0] >> hi) | (q[1] << lo);
        dst[32] |= q[1] >> hi;
        dst++;
        q += 2;
    }
}

EC s32 func_0200c628(char * font, char * str, ...)
{
    s32 width = 0;
    TalkGlyph * glyph;

    while (*str != '\0')
    {
        glyph = (TalkGlyph *)func_0200c720((TalkFont *)font, func_0200c764((TalkFont *)font, &str));
        if (glyph != NULL)
        {
            width += glyph->unk_02;
        }
    }
    return width;
}

EC s32 func_0200c690(void * font, char * str, ...)
{
    TalkFont * f = (TalkFont *)font;
    TalkGlyph * glyph = (TalkGlyph *)func_0200c720(f, func_0200c764(f, &str));

    if (glyph != NULL)
    {
        return glyph->unk_02;
    }
    return 6;
}

EC void func_0200c6c8(void * unused, u16 * dst, s32 tile, s32 count)
{
    s32 i;
    u16 t;
    u16 u;

    if (count > 32)
    {
        count = 32;
    }

    t = tile;
    for (i = 0; i < count; i++)
    {
        u = t + 1;
        dst[i] = t;
        dst[i + 32] = u;
        t = u + 1;
    }
}

EC void * func_0200c720(TalkFont * font, s32 code)
{
    TalkGlyph * glyph;
    TalkGlyph ** table;

    if (font->unk_04 == NULL)
    {
        return NULL;
    }

    table = (TalkGlyph **)font->unk_04;
    glyph = table[(u8)code - 32];
    while (glyph != NULL && glyph->unk_00 != 0)
    {
        if (glyph->unk_00 == code)
        {
            return glyph;
        }
        glyph++;
    }
    return NULL;
}

EC s32 func_0200c764(TalkFont * font, char ** str)
{
    u8 hi;
    u8 lo;

    if (func_0206e768(*str))
    {
        hi = (*str)[0];
        lo = (*str)[1];
        *str += 2;
        return lo | (hi << 8);
    }
    return *(*str)++;
}

EC void func_0200c7ac(s32 pal, s32 from, s32 to)
{
    u16 * dst = (u16 *)pal;
    s32 i;
    s32 r;
    s32 g;
    s32 b;

    for (i = 0; i < 16; i++)
    {
        r = ((from & 31) * (16 - i) + (to & 31) * i) / 16;
        g = (((from >> 5) & 31) * (16 - i) + ((to >> 5) & 31) * i) / 16;
        b = (((from >> 10) & 31) * (16 - i) + ((to >> 10) & 31) * i) / 16;
        dst[i] = r | (g << 5) | (b << 10);
    }
}

EC void func_0200c850(TalkLog * log)
{
    s32 i;

    for (i = 0; i < 64; i++)
    {
        log->unk_04[i & 63][0] = 0;
    }
    log->unk_1008 = 0;
    log->unk_1005 = 0;
    log->unk_1004 = 0;
    log->unk_100c = 0;
}

EC void func_0200c888(void)
{
    func_0200c850(&data_020e3da8);
}

EC void func_0200c89c(TalkLog * log)
{
    log->unk_1004 = 0;
    log->unk_100c = 0;
}

EC void func_0200c8b0(void * log)
{
    TalkLog * talkLog = (TalkLog *)log;

    if (talkLog->unk_1004 == 0)
    {
        return;
    }
    if (data_020e3d44 & 0x2000)
    {
        return;
    }
    talkLog->unk_1005 = 0;
    talkLog->unk_1008++;
    talkLog->unk_04[talkLog->unk_1008 & 63][talkLog->unk_1005] = 0;
    talkLog->unk_1004 = 0;
}

EC void func_0200c904(void * log)
{
    TalkLog * talkLog = (TalkLog *)log;

    if (data_020e3d44 & 0x2000)
    {
        return;
    }

    if (talkLog->unk_1004 != 0)
    {
        talkLog->unk_1005 = 0;
        talkLog->unk_1008++;
        talkLog->unk_04[talkLog->unk_1008 & 63][talkLog->unk_1005] = 0;
    }

    talkLog->unk_1005 = 0;
    talkLog->unk_1008++;
    talkLog->unk_04[talkLog->unk_1008 & 63][talkLog->unk_1005] = 0;
    talkLog->unk_1004 = 0;
}

EC void func_0200c984(void * log, s32 chr)
{
    TalkLog * talkLog = (TalkLog *)log;
    s32 pos;

    if (data_020e3d44 & 0x2000)
    {
        return;
    }

    pos = talkLog->unk_1005;
    if (pos < 63)
    {
        talkLog->unk_1005 = pos + 1;
        talkLog->unk_04[talkLog->unk_1008 & 63][pos] = chr;
        talkLog->unk_04[talkLog->unk_1008 & 63][talkLog->unk_1005] = 0;
        talkLog->unk_1004 = 1;
    }
}

EC void func_0200c9f0(void * log, char * str)
{
    if (data_020e3d44 & 0x2000)
    {
        return;
    }

    while (*str != 0)
    {
        func_0200c984(log, *(volatile char *)str);
        str++;
    }
}

EC void func_0200ca38(void * log, char * name)
{
    TalkLog * talkLog = (TalkLog *)log;

    if (func_020b6e2c(&talkLog->unk_100c, name) == 0)
    {
        return;
    }

    if (data_020e3d44 & 0x2000)
    {
        return;
    }

    func_0206e7b8(&talkLog->unk_100c, name, 24);
    func_0200c984(log, 126);
    func_0200c9f0(log, name);
    func_0200c8b0(log);
}

char * TalkLog::vfunc_08(s32 line)
{
    return this->unk_04[line & 63];
}

EC void func_0200cab4(ProcPtr parent)
{
    DispIo * dispIo;

    dispIo = func_0206eca4()->unk_00->dispIo;
    dispIo->bldcnt.effect = 3;
    SetBldTargetA_Maybe(func_0206eca4(), 1, 0, 0, 1, 0, 0);
    SetBldTargetB_Maybe(func_0206eca4(), 0, 0, 0, 0, 0, 0);
    func_0206eca4()->unk_00->dispIo->blend_y = 0;
    func_020062e8(func_0206eca4(), 10, 10, parent);
    new (Proc_Start(ProcScr_020ce750, parent)) PalFader(8, 16, 0, 8);
}

EC void func_0200cb8c(ProcPtr parent)
{
    func_020062e8(func_0206eca4(), 0, 10, parent);
    new (Proc_Start(ProcScr_020ce750, parent)) PalFader(16, 8, 0, 8);
    new (Proc_Start(ProcScr_020ce750, parent)) BG1Clr(7);
}

EC void func_0200cc14(void)
{
    SetDispEnable_Maybe(func_0206eca4(), 1, 0, 0, 1, 1);
    data_020e3d44 &= ~0x1F;

    if (data_020e3d44 & 0x1000)
    {
        return;
    }

    if (gMapStateManager != NULL && gMapStateManager->unk_14 != NULL)
    {
        func_ov000_021b969c(gMapStateManager->unk_14);
    }
}

EC void func_0200cc84(TalkFont * font)
{
    font->vfunc_08();
}

void KW::Init()
{
    func_020049b4(&this->unk_38, 0, 222, 180, 0, 0);
}

void Talk::Init()
{
}

EC void func_02009864(void)
{
    struct UnkStruct_02197798 * screen;
    BGCtrl * bg;
    s32 scroll;

    screen = func_0206ecb0();
    screen->unk_04->dispcnt.win0_on = 0;
    screen->unk_04->dispcnt.win1_on = 0;
    screen->unk_04->dispcnt.objWin_on = 0;

    SetDispEnable_Maybe(func_0206ecb0(), 0, 1, 0, 0, 1);
    SetBgPriority_Maybe(func_0206ecb0(), 1, 3, 1, 1);

    func_0206fc44(data_02197718, 0x200010);
    func_0206ef9c(data_02197700, 0, 0, 24, 0, 0);

    bg = data_02197700;
    scroll = -32;
    if (bg->unk_12 != 0)
    {
        scroll = bg->unk_16 + 32;
    }
    bg->unk_04->dispIo->unk_38[bg->unk_10] = scroll;
    bg->unk_04->dispIo->unk_40[bg->unk_10] = 0xFF75;

    func_0206f0fc(data_021976f8, 0, 0, 28, 0);
}

EC void func_02009984(Talk * talk)
{
    struct UnkStruct_02197798 * screen;
    BGCtrl * bg;
    s32 scroll;
    ScreenState * saved;

    func_02006b70(&data_020e3cf8);

    screen = func_0206ecb0();
    screen->unk_04->dispcnt.win0_on = 0;
    screen->unk_04->dispcnt.win1_on = 0;
    screen->unk_04->dispcnt.objWin_on = 0;

    SetDispEnable_Maybe(func_0206ecb0(), 0, 1, 0, 0, 1);
    SetBgPriority_Maybe(func_0206ecb0(), 1, 3, 1, 1);

    func_0206fc44(data_02197718, 0x200010);
    func_0206ef9c(data_02197700, 0, 0, 24, 0, 0);

    bg = data_02197700;
    scroll = -32;
    if (bg->unk_12 != 0)
    {
        scroll = bg->unk_16 + 32;
    }
    bg->unk_04->dispIo->unk_38[bg->unk_10] = scroll;
    bg->unk_04->dispIo->unk_40[bg->unk_10] = 0xFF75;

    func_0206f0fc(data_021976f8, 0, 0, 28, 0);

    if (IsWirelessBattle())
    {
        saved = gpActiveScreenSt;
        gpActiveScreenSt = gpSubScreenSt;
        func_02013530(talk, 0x710, 14, 0);
        gpActiveScreenSt = saved;
    }
}

EC void func_02009afc(void)
{
    if (IsOverlayLoaded(2) && data_ov002_021faf8c.unk_bc == 0)
    {
        data_020e3d44 |= 0x80;
    }
}

EC void func_02009b3c(Talk * talk)
{
    struct TalkLoader loader;
    BGCtrl * bg;
    s16 value;
    DispIo * dispIo;
    struct UnkStruct_02197798 * screen;

    if (IsOverlayLoaded(2) && data_ov002_021faf8c.unk_bc == 0)
    {
        data_020e3d44 |= 0x80;
    }
    func_0206f580(data_021976f8, 0);
    bg = data_021976f8;
    value = 0;
    if (bg->unk_12 != 0)
    {
        value = bg->unk_16;
    }
    bg->unk_04->dispIo->unk_38[bg->unk_10] = value;
    bg->unk_04->dispIo->unk_40[bg->unk_10] = 0;

    func_02006604(&loader, data_020ca174, data_021976f8);
    func_02006694(&loader, 0x2000);
    func_020066ec(&loader, 0x100);
    func_02006808(&loader, 0, 17, 0x8100);
    func_02006670(&loader);
    func_0206eee0(data_02197700, 0, 0, 64);
    func_0206f580(data_02197700, 0);

    talk->unk_44 = new (Proc_Start(ProcScr_020ce750, talk)) TalkWindow();
    func_02006624(&loader);

    SetDispEnable_Maybe(func_0206ecb0(), 1, 1, 1, 0, 1);
    dispIo = func_0206ecb0()->unk_00->dispIo;
    dispIo->bldcnt.effect = 1;
    SetBldTargetA_Maybe(func_0206ecb0(), 0, 0, 1, 0, 0, 0);
    SetBldTargetB_Maybe(func_0206ecb0(), 1, 1, 0, 1, 1, 1);
    screen = func_0206ecb0();
    screen->unk_00->dispIo->blend_coeff_a = 0;
    screen->unk_00->dispIo->blend_coeff_b = 16;
    func_02006204(func_0206ecb0(), 16, 0, 8, talk);
}

EC void func_02009d38(Talk * talk)
{
    char fullPath[32];
    char buf[64];
    char * p;
    struct TalkLoader loader;
    BGCtrl * bg;
    s16 value;
    char * name;
    char * path;
    BOOL found;
    s32 num;
    s32 pending;
    Face * face;

    func_0206f580(data_021976f8, 0);
    bg = data_021976f8;
    value = 0;
    if (bg->unk_12 != 0)
    {
        value = bg->unk_16;
    }
    bg->unk_04->dispIo->unk_38[bg->unk_10] = value;
    bg->unk_04->dispIo->unk_40[bg->unk_10] = 0;

    func_02006604(&loader, data_020ca174, data_021976f8);
    func_02006694(&loader, 0x2000);
    func_020066ec(&loader, 0x100);
    func_02006808(&loader, 0, 17, 0x8100);
    func_02006670(&loader);
    func_0206eee0(data_02197700, 0, 0, 64);
    func_0206f580(data_02197700, 0);

    talk->unk_44 = new (Proc_Start(ProcScr_020ce750, talk)) TalkWindow();
    func_02006624(&loader);

    SetDispEnable_Maybe(func_0206ecb0(), 1, 1, 1, 0, 1);

    p = talk->unk_40;
    found = FALSE;
    while (TRUE)
    {
        switch (*p)
        {
            case 4:
            case 8:
            case 19:
                p++;
                func_02008ae4(&p);
                break;
            case 6:
            case 7:
            case 10:
            case 12:
            case 14:
            case 15:
            case 16:
            case 18:
            case 21:
                p += 1;
                break;
            case 1:
                p += 2;
                break;
            case 2:
                p += 3;
                break;
            case 3:
                p += 4;
                break;
            case 13:
                found = TRUE;
                goto scanned;
            default:
                goto scanned;
        }
    }
scanned:
    if (!found)
    {
        path = NULL;
    }
    else
    {
        p = talk->unk_40;
        while (TRUE)
        {
            switch (*p)
            {
                case 8:
                    p++;
                    gFaceHandle->faces[talk->unk_39].unk_0c_8_9 = 3;
                    name = func_02008ae4(&p);
                    if (name[0] == 'M' && name[1] == 'E' && name[2] == '\0')
                    {
                        if (data_021974f0 != NULL)
                        {
                            func_0206e7b8(buf, func_02037ef0(data_021974f0->pPersonData, data_021974f0), 64);
                        }
                        else
                        {
                            func_0206e7b8(buf, data_020ca18c, 64);
                        }
                    }
                    else
                    {
                        func_0206e7b8(buf, data_020ca15c, 64);
                        func_0206e7f4(buf, name, 64);
                    }
                    gFaceHandle->faces[talk->unk_39].unk_0c_1 = (data_020e3d44 & 0x40) ? TRUE : FALSE;
                    gFaceHandle->faces[talk->unk_39].unk_18 = 8;
                    gFaceHandle->faces[talk->unk_39]._020077b8(buf, talk->unk_39, 0, data_020e3d44 & 0x80);
                    break;
                case 6:
                    talk->unk_39 = 0;
                    p++;
                    break;
                case 7:
                    talk->unk_39 = 1;
                    p++;
                    break;
                case 12:
                    talk->unk_39 = 2;
                    p++;
                    break;
                case 21:
                    p++;
                    func_0200c904(&data_020e3da8);
                    break;
                case 18:
                    p++;
                    data_020e3d44 ^= 0x40;
                    break;
                case 13:
                    p++;
                    func_0206e7b8(data_020e3d48, func_02008ae4(&p), 32);
                    goto done;
                case 19:
                    p++;
                    num = func_02008a48(&p);
                    if (num > 255)
                    {
                        num = 255;
                    }
                    talk->unk_3c = num;
                    break;
                case 14:
                    talk->unk_3b = 1;
                    p++;
                    break;
                case 15:
                    talk->unk_3b = 0;
                    p++;
                    break;
                case 1:
                    p += 2;
                    switch (p[-1])
                    {
                        case 's':
                            gFaceHandle->faces[talk->unk_39].isSmiling = TRUE;
                            break;
                        case 'a':
                            gFaceHandle->faces[talk->unk_39].isSmiling = FALSE;
                            break;
                        case 'A':
                            face = &gFaceHandle->faces[talk->unk_39];
                            face->unk_18 = face->unk_17 = 0;
                            break;
                    }
                    break;
                case 2:
                    p += 3;
                    switch (p[-2])
                    {
                        case 'd':
                            switch (p[-1])
                            {
                                case 'l':
                                    data_020e3d44 |= 0x200;
                                    break;
                                case 's':
                                    data_020e3d44 |= 0x400;
                                    break;
                                case 'a':
                                    data_020e3d44 |= 0x2000;
                                    break;
                            }
                            break;
                        case 'e':
                            switch (p[-1])
                            {
                                case 'd':
                                    gFaceHandle->faces[talk->unk_39].unk_0c_4_5 = 0;
                                    break;
                                case 'c':
                                    gFaceHandle->faces[talk->unk_39].unk_0c_4_5 = 1;
                                    break;
                                case 'o':
                                    gFaceHandle->faces[talk->unk_39].unk_0c_4_5 = 2;
                                    break;
                                case 'h':
                                    gFaceHandle->faces[talk->unk_39].unk_0c_4_5 = 3;
                                    break;
                            }
                            break;
                    }
                    break;
                default:
                    goto done;
            }
        }
    done:
        talk->unk_40 = p;
        path = data_020e3d48;
    }

    if (talk->unk_3d != 5)
    {
        func_020a8f40(data_020ca148);
        if (path == NULL || !FileExists(path))
        {
            if (path == NULL || *path == '\0')
            {
                path = func_ov000_021a418c(NULL);
            }
            else
            {
                func_0206e7b8(fullPath, data_020ca154, 32);
                func_0206e7f4(fullPath, path, 32);
                path = func_ov000_021a418c(fullPath);
            }
        }
        if (path == NULL || !FileExists(path))
        {
            path = data_020ca16c;
        }
        func_02006e38(&data_020e3cf8, path, (data_020e3d44 & 0x40) ? 1 : 0, 0);
        func_02006d3c(&data_020e3cf8);
    }

    pending = talk->unk_3c;
    func_02006398(func_0206ecb0(), 0, pending, talk);
    if ((data_020e3d44 & 0x100) || ((data_020e3d44 & 0x10) && !(data_020e3d44 & 0x1000)))
    {
        func_02006398(func_0206eca4(), 0, pending, talk);
    }
}

EC void func_0200a500(Talk * talk)
{
    s32 blend;
    u32 param;

    blend = func_0206ecb0()->unk_00->dispIo->unk_50;
    if (blend == -16 || blend == 16)
    {
        return;
    }

    param = talk->unk_3c;
    func_02006398(func_0206ecb0(), -16, param, talk);

    if ((data_020e3d44 & 0x100) || ((data_020e3d44 & 0x10) && !(data_020e3d44 & 0x1000)))
    {
        func_02006398(func_0206eca4(), -16, param, talk);
    }
}

EC void func_02006c14(void *);
EC void func_0200a57c(void)
{
    func_02006c14(&data_020e3cf8);
}

EC void func_0200a590(Talk * talk)
{
    Proc_Goto(talk, talk->unk_3d, 0);
}

EC void func_0200a5a4(Talk * talk)
{
    data_020e3d44 |= 0x8000;

    if (talk->unk_3d != 4)
    {
        return;
    }

    func_02006398(func_0206ecb0(), -16, 8, talk);

    if ((data_020e3d44 & 0x100) || ((data_020e3d44 & 0x10) && !(data_020e3d44 & 0x1000)))
    {
        func_02006398(func_0206eca4(), -16, 8, talk);
    }
}

inline void Talk::SkipText()
{
    char buf[64];
    char * name;
    Face * face;
    s32 i;

    data_020e3d44 &= ~0x20;

    while (TRUE)
    {
        switch (*this->unk_40)
        {
            case 0:
                func_0200c8b0(&data_020e3da8);
                return;
            case 21:
                func_0200c904(&data_020e3da8);
                this->unk_40++;
                break;
            case 10:
            case 16:
                func_0200c8b0(&data_020e3da8);
            case 14:
            case 15:
            case 17:
            case 18:
                this->unk_40++;
                break;
            case 8:
                face = &gFaceHandle->faces[this->unk_39];
                if (face->HasFaceInfo())
                {
                    if ((face->unk_18 == 0) ? TRUE : FALSE)
                    {
                        func_0200c8b0(&data_020e3da8);
                        gFaceHandle->faces[this->unk_39].unk_18 = 8;
                    }
                    gFaceHandle->faces[this->unk_39].Clear();
                    break;
                }
                this->unk_40++;
                gFaceHandle->faces[this->unk_39].unk_0c_8_9 = 0;
                name = func_02008ae4(&this->unk_40);
                if (name[0] == 'M' && name[1] == 'E' && name[2] == '\0')
                {
                    if (data_021974f0 != NULL)
                    {
                        func_0206e7b8(buf, func_02037ef0(data_021974f0->pPersonData, data_021974f0), 64);
                    }
                    else
                    {
                        func_0206e7b8(buf, data_020ca18c, 64);
                    }
                }
                else
                {
                    func_0206e7b8(buf, data_020ca15c, 64);
                    func_0206e7f4(buf, name, 64);
                }
                gFaceHandle->faces[this->unk_39].unk_0c_1 = (data_020e3d44 & 0x40) ? TRUE : FALSE;
                gFaceHandle->faces[this->unk_39].unk_18 = 8;
                gFaceHandle->faces[this->unk_39]._020077b8(buf, this->unk_39, 0, data_020e3d44 & 0x80);
                break;
            case 9:
                this->unk_40++;
                func_0200c8b0(&data_020e3da8);
                break;
            case 4:
            case 13:
            case 19:
                this->unk_40++;
                func_02008ae4(&this->unk_40);
                break;
            case 6:
                this->unk_39 = 0;
                this->unk_40++;
                break;
            case 7:
                this->unk_39 = 1;
                this->unk_40++;
                break;
            case 12:
                this->unk_39 = 2;
                this->unk_40++;
                break;
            case 1:
                this->unk_40 += 2;
                switch (this->unk_40[-1])
                {
                    case '@':
                        func_02019124((struct Proc *)this);
                        break;
                    case 'h':
                        data_020e3d44 |= 0x20;
                        this->unk_40 -= 2;
                        return;
                }
                break;
            case 11:
                this->unk_40 += 2;
                break;
            case 2:
                this->unk_40 += 3;
                break;
            case 3:
                this->unk_40 += 4;
                break;
            default:
                if (this->unk_3a != this->unk_39)
                {
                    this->unk_3a = this->unk_39;
                    func_0200c8b0(&data_020e3da8);
                    break;
                }
                if (gFaceHandle->faces[this->unk_39].GetName() != NULL)
                {
                    func_0200ca38(&data_020e3da8, gFaceHandle->faces[this->unk_39].GetName());
                }
                for (i = 0; i < 3; i++)
                {
                    gFaceHandle->faces[i].unk_18 = 8;
                }
                gFaceHandle->faces[this->unk_39].unk_18 = 0;
                func_0200c984(&data_020e3da8, *this->unk_40++);
                if (func_0206e768(this->unk_40))
                {
                    func_0200c984(&data_020e3da8, *this->unk_40++);
                }
                break;
        }
    }
}

EC void func_0200a618(Talk * talk)
{
    talk->SkipText();

    if ((data_020e3d44 & 0x10) && !(data_020e3d44 & 0x1000))
    {
        EventSkip::SkipTransitionFrom0To2();
    }
    if (data_020e3d44 & 0x20)
    {
        Proc_Goto(talk, 7, 0);
    }
}

EC void func_0200aaf0(Talk * talk)
{
    func_0200e8e4();
    func_0200de18(talk->unk_44, talk);
}

EC void func_0200ab0c(ProcPtr proc)
{
    s32 i;
    Face * face;
    Face * faces;
    struct UnkStruct_02197798 * screen;
    DispIo * io;

    faces = gFaceHandle->faces;
    face = faces;
    for (i = 0; i < 3; i++)
    {
        if (face->HasFaceInfo())
        {
            faces[i].Hide();
            return;
        }
        face++;
    }

    Proc_Break(proc, 0);

    io = func_0206ecb0()->unk_00->dispIo;
    io->bldcnt.effect = 1;
    SetBldTargetA_Maybe(func_0206ecb0(), 0, 0, 1, 0, 0, 0);
    SetBldTargetB_Maybe(func_0206ecb0(), 1, 1, 0, 1, 1, 1);
    screen = func_0206ecb0();
    screen->unk_00->dispIo->blend_coeff_a = 16;
    screen->unk_00->dispIo->blend_coeff_b = 0;
    func_02006204(func_0206ecb0(), 0, 16, 8, (ProcEx *)proc);
}

EC void * func_02004450(char *);
EC BOOL func_ov000_021ccbdc(void);
extern char data_020ca180[];

inline Talk::Talk(char * str, s32 flag)
    : unk_38(1), unk_39(0), unk_3a(0), unk_3b(1), unk_3c(16), unk_3d(4), unk_40(str), unk_44(NULL), unk_48(NULL),
      unk_4c(NULL), unk_50(NULL)
{
    data_020e3d44 &= 0x1000;
    func_0200c89c(&data_020e3da8);
    StartFaceHandle(0);

    if (EventSkip::IsSkipState4())
    {
        this->SkipText();
        this->unk_3d = 8;
        if (data_020e3d44 & 0x20)
        {
            Proc_Goto(this, 7, 0);
        }
        else
        {
            Proc_Goto(this, 8, 0);
        }
        return;
    }

    func_0200e0dc();
    this->unk_4c = new (Proc_Start(ProcScr_020ce750, PROC_TREE_8)) TalkInput();
    this->unk_48 = func_02004450(data_020ca180);
    if (func_ov000_021ccbdc())
    {
        data_020e3d44 |= 0x600;
    }

    if (data_020e3cf8.HasUnk18())
    {
        this->unk_3d = 5;
        if (data_020e3cf8.unk_02 == 4)
        {
            data_020e3cf8.unk_02 = 3;
            Proc_Goto(this, 1, 0);
        }
        else
        {
            data_020e3cf8.unk_02 = 3;
            Proc_Goto(this, 2, 0);
        }
        return;
    }

    this->unk_3d = 4;
    if (flag)
    {
        data_020e3d44 |= 0x100;
    }
    Proc_Goto(this, 0, 0);
}

inline void Talk::Restart(char * str, s32 flag)
{
    gKeySt->pressed = 0;
    this->unk_40 = str;
    data_020e3d44 &= ~0x120;
    if (flag)
    {
        data_020e3d44 |= 0x100;
    }
    func_020190ec((struct Proc *)this);

    if (EventSkip::IsSkipState4() || (data_020e3d44 & 0x8000))
    {
        this->SkipText();
        if (!(data_020e3d44 & 0x20))
        {
            Proc_Goto(this, this->unk_3d, 0);
            return;
        }
    }

    Proc_Goto(this, 3, 0);
}

inline void Talk::ScanHold()
{
    char * p;

    data_020e3d44 &= ~0x10000;
    p = this->unk_40;

    while (TRUE)
    {
        switch (*p)
        {
            case 0:
                return;
            case 4:
            case 8:
            case 13:
            case 19:
                func_02008ae4(&p);
                break;
            case 3:
                p += 4;
                break;
            case 2:
                p += 3;
                break;
            case 1:
                if (p[1] == 'h')
                {
                    data_020e3d44 |= 0x10000;
                }
                p += 2;
                break;
            default:
                p++;
                break;
        }
    }
}

EC void func_0200ac20(char * text, ProcPtr parent, s32 flag)
{
    Talk * talk;
    char * str;

    str = GetText(text);
    talk = (Talk *)Proc_Find(data_020ca1ec);
    if (talk == NULL)
    {
        if (IsRootProcess((struct Proc *)parent))
        {
            talk = new (Proc_Start(data_020ca1ec, parent)) Talk(str, flag);
        }
        else
        {
            talk = new (Proc_StartBlocking(data_020ca1ec, parent)) Talk(str, flag);
        }
    }
    else
    {
        talk->Restart(str, flag);
    }

    talk->ScanHold();
}

EC BOOL func_0200be60(void)
{
    return Proc_Find(data_020ca1ec) != NULL;
}

EC BOOL func_0200be80(void)
{
    if (Proc_Find(data_020ca1ec) == NULL)
    {
        return FALSE;
    }

    return (data_020e3d44 & 0x20) == 0;
}

Talk::~Talk()
{
    func_020135b8();

    if (this->unk_50 != NULL)
    {
        delete[] this->unk_50;
        this->unk_50 = NULL;
    }

    if (this->unk_4c != NULL)
    {
        Proc_End(this->unk_4c);
    }

    if (this->unk_48 != NULL)
    {
        func_02004460(this->unk_48);
    }

    if (this->unk_44 != NULL)
    {
        Proc_End(this->unk_44);
    }

    func_0200e208();
    EndFaceHandle();
}
