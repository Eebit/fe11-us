#ifndef TALK_HPP
#define TALK_HPP

#include "global.h"
#include "proc.h"

// extern ??? _ZTS4Talk
extern char data_020ca16c[];
extern char data_020ca174[];
extern char data_020ca180[];
extern char data_020ca18c[];
// extern ??? _ZTS9TalkInput
// extern ??? _ZTI4Talk
// extern ??? _ZTI9TalkInput
// extern ??? _ZTV9TalkInput
// extern ??? _ZTV4Talk
extern struct ProcCmd ProcScr_Talk[];
extern char data_020ca31c[];
// extern ??? _ZTI8TalkFont
// extern ??? _ZTS8TalkFont
// extern ??? _ZTV8TalkFont
extern char data_020ca348[];
// extern ??? _ZTS6BG1Clr
// extern ??? _ZTI10ILogStream
// extern ??? _ZTS7TalkLog
// extern ??? _ZTS8PalFader
// extern ??? _ZTI7TalkLog
// extern ??? _ZTI6BG1Clr
// extern ??? _ZTI8PalFader
// extern ??? _ZTI13TalkLogViewer
// extern ??? _ZTS10ILogStream
// extern ??? _ZTS13TalkLogViewer
// extern ??? _ZTV7TalkLog
// extern ??? _ZTV6BG1Clr
// extern ??? _ZTV8PalFader
// extern ??? _ZTV13TalkLogViewer
extern struct ProcCmd ProcScr_TalkLogViewer[];
// extern ??? _ZTS2KW
// extern ??? _ZTS8TalkWait
// extern ??? _ZTI10TalkScroll
// extern ??? _ZTI8TalkWait
// extern ??? _ZTI2KW
// extern ??? _ZTI10TalkWindow
// extern ??? _ZTS10TalkWindow
// extern ??? _ZTS10TalkScroll
// extern ??? _ZTV8TalkWait
// extern ??? _ZTV2KW
// extern ??? _ZTV10TalkScroll
// extern ??? _ZTV10TalkWindow
// extern ??? _ZTS8NameFont
// extern ??? _ZTS8TalkName
// extern ??? _ZTI8NameFont
// extern ??? _ZTI8TalkName
extern u16 data_020ca54c[4];
// extern ??? _ZTV8NameFont
// extern ??? _ZTV8TalkName
extern struct ProcCmd ProcScr_TalkName[];
extern char data_020ca5c0[];
extern char data_020e3d48[];
extern char data_020e3d68[];
extern struct TalkLog gTalkLog;

EC s32 func_02008a48(char **);
EC char * func_02008ae4(char **);
// EC ??? func_02008bb8
// EC ??? _ZN4Talk4LoopEv
// EC ??? func_0200984c
// EC ??? _ZN4Talk4InitEv
// EC ??? func_02009864
// EC ??? func_02009984
// EC ??? func_02009afc
// EC ??? func_02009b3c
// EC ??? func_02009d38
// EC ??? func_0200a500
// EC ??? func_0200a57c
// EC ??? func_0200a590
// EC ??? func_0200a5a4
// EC ??? func_0200a618
// EC ??? func_0200aaf0
// EC ??? func_0200ab0c
// EC ??? func_0200ac20
// EC ??? func_0200be60
// EC ??? func_0200be80
// EC ??? _ZN4TalkD0Ev
// EC ??? _ZN4TalkD1Ev
// EC ??? _ZN9TalkInput4LoopEv
// EC ??? _ZN9TalkInputD1Ev
// EC ??? _ZN9TalkInputD0Ev
// EC ??? func_0200c084
EC void func_0200c098(u8 *, u32 *, u32);
// EC ??? func_0200c1d0
EC void func_0200c350(u32 *, u32 *);
// EC ??? _ZN8TalkFontC2EPc
// EC ??? _ZN8TalkFontC1EPc
// EC ??? _ZN8TalkFontD1Ev
// EC ??? _ZN8TalkFontD0Ev
// EC ??? _ZN8TalkFontD2Ev
// EC ??? _ZN8TalkFont9_0200c4d0EPmlPc
// EC ??? _ZN8TalkFont9_0200c530EPmlPc
// EC ??? _ZN8TalkFont8vfunc_08EPmlP9TalkGlyph
// EC ??? _ZN8TalkFont9_0200c628EPc
// EC ??? _ZN8TalkFont9_0200c690EPc
// EC ??? _ZN8TalkFont9_0200c6c8EPtll
// EC ??? _ZN8TalkFont9_0200c720El
// EC ??? _ZN8TalkFont9_0200c764EPPc
// EC ??? func_0200c7ac
// EC ??? _ZN7TalkLog9_0200c850Ev
EC void func_0200c888(void);
// EC ??? _ZN7TalkLog9_0200c89cEv
// EC ??? _ZN7TalkLog9_0200c8b0Ev
// EC ??? _ZN7TalkLog9_0200c904Ev
// EC ??? _ZN7TalkLog9_0200c984Ec
// EC ??? _ZN7TalkLog9_0200c9f0EPc
// EC ??? _ZN7TalkLog9_0200ca38EPc
// EC ??? _ZN7TalkLog8vfunc_08El
// EC ??? func_0200cab4
// EC ??? func_0200cb8c
// EC ??? func_0200cc14
// EC ??? func_0200cc84
// EC ??? _ZN13TalkLogViewer4LoopEv
// EC ??? func_0200cfb0
// EC ??? _ZN7TalkLog8vfunc_00Ev
// EC ??? _ZN13TalkLogViewerD0Ev
// EC ??? _ZN13TalkLogViewerD1Ev
// EC ??? _ZN6BG1ClrD0Ev
// EC ??? _ZN6BG1Clr4LoopEv
// EC ??? _ZN6BG1ClrD1Ev
// EC ??? _ZN8PalFader4LoopEv
// EC ??? _ZN7TalkLog8vfunc_04Ev
// EC ??? _ZN8PalFaderD1Ev
// EC ??? _ZN8PalFaderD0Ev
// EC ??? _ZN18UnkStruct_0200d6289_0200d628EP18UnkStruct_0200d770l
// EC ??? _ZN18UnkStruct_0200d6289_0200d65cEl
// EC ??? _ZN18UnkStruct_0200d6289_0200d690Ev
// EC ??? _ZN18UnkStruct_0200d6289_0200d6a4EPc
// EC ??? _ZN18UnkStruct_0200d6289_0200d6e0EPc
// EC ??? _ZN18UnkStruct_0200d6289_0200d73cElll
// EC ??? _ZN18UnkStruct_0200d770C1ElPtl
// EC ??? _ZN18UnkStruct_0200d770D1Ev
// EC ??? _ZN18UnkStruct_0200d7709_0200d7d4Ev
// EC ??? _ZN18UnkStruct_0200d7709_0200d7e0EPc
// EC ??? _ZN18UnkStruct_0200d7709_0200d7f0El
// EC ??? _ZN10TalkWindowC2Ev
// EC ??? _ZN10TalkWindowC1Ev
// EC ??? _ZN10TalkWindowD1Ev
// EC ??? _ZN10TalkWindowD0Ev
// EC ??? _ZN10TalkWindowD2Ev
// EC ??? _ZN10TalkWindow4InitEv
// EC ??? _ZN10TalkWindow9_0200db64Ev
// EC ??? _ZN10TalkWindow9_0200dbb0EPc
// EC ??? _ZN10TalkWindow8vfunc_10Ev
// EC ??? _ZN10TalkWindow9_0200dc44Ev
// EC ??? _ZN10TalkWindow9_0200dc68Ev
// EC ??? _ZN10TalkWindow9_0200dc80Ev
// EC ??? _ZN10TalkWindow9_0200dcb4Ev
// EC ??? _ZN10TalkWindow9_0200ddd8EPv
// EC ??? _ZN10TalkWindow9_0200de18EPv
// EC ??? _ZN10TalkWindow9_0200de90EP18UnkStruct_0200de90Pv
// EC ??? _ZN10TalkWindow9_0200df24ElPv
// EC ??? _ZN8TalkWait4LoopEv
// EC ??? _ZN2KW4InitEv
// EC ??? _ZN2KW4LoopEv
// EC ??? _ZN10TalkScrollD0Ev
// EC ??? _ZN10TalkScroll4LoopEv
// EC ??? _ZN10TalkScrollD1Ev
// EC ??? _ZN2KWD1Ev
// EC ??? _ZN2KWD0Ev
// EC ??? _ZN8TalkWaitD1Ev
// EC ??? _ZN8TalkWaitD0Ev
EC void func_0200e0dc(void);
EC void func_0200e208(void);
// EC ??? func_0200e254
// EC ??? _ZN8NameFontD1Ev
// EC ??? TalkName_Loop
// EC ??? _ZN8TalkName4LoopEv
// EC ??? func_0200e4cc
// EC ??? func_0200e674
// EC ??? func_0200e814
EC BOOL TryStartTalkName(s32, char *, struct Proc *);
EC BOOL TryBreakTalkName(void);
// EC ??? _ZN8TalkNameD0Ev
// EC ??? _ZN8TalkNameD1Ev
// EC ??? _ZN8NameFont8vfunc_08EPmlP9TalkGlyph
// EC ??? _ZN8NameFontD0Ev
// EC ??? __sinit_talk.cpp

#endif // TALK_HPP
