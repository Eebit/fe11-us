#ifndef FACE_HPP
#define FACE_HPP

#include "global.h"

#include "proc_ex.hpp"

struct FaceInfo
{
    /* 00 */ char * fid; // "face ID"? lookup key
    /* 04 */ char * mpid; // localized name string
    /* 08 */ char * faceFile; // face filename in "/f/" directory
    /* 0C */ char * sfImgFile; // face graphic filename in "/sf/" directory
    /* 10 */ char * sfPalFile; // face palette filename in "/sf/" directory
    /* 14 */ u8 mouthFrames[5][2];
    /* 1E */ u8 eyeFrames[2][2]; //  +0x1e and +0x1f are midblink frame, +0x20 and +0x21 are for closed frame
    /* 22 */ STRUCT_PAD(0x22, 0x24);
};

class Face
{
public:
    /* 00 */ struct FaceInfo * pInfo;
    /* 04 */ s32 chrBase;
    /* 08 */ s32 palBase;
    /* 0C */ union
    {
        u32 flags;
        struct
        {
            u32 unk_0c_0 : 2;
            u32 isFlipped : 1;
            u32 isSmiling : 1;
            u32 unk_0c_4_5 : 2;
            u32 unk_0c_6_7 : 2;
            u32 unk_0c_8_9 : 2;
            u32 unk_0c_a : 22;
        };
    };
    /* 10 */ s16 xBase;
    /* 12 */ s16 yBase;
    /* 14 */ u8 unk_14;
    /* 15 */ s8 alpha;
    /* 16 */ s8 unk_16;
    /* 17 */ s8 unk_17;
    /* 18 */ s8 unk_18;
    /* 19 */ STRUCT_PAD(0x19, 0x1C);
    /* 1C */ s32 blinkCnt;
    /* 20 */ s32 mouthState;
    /* 24 */ s32 mouthCnt;

    Face() {};

    inline BOOL HasFaceInfo()
    {
        return this->pInfo != NULL;
    }

    inline u32 GetPaletteIndex(void)
    {
        return this->palBase + (this->unk_17 >> 1);
    }

    inline BOOL CheckUnk15(void)
    {
        return (this->alpha != 0 && this->alpha != 0x10) ? TRUE : FALSE;
    }

    char * GetFid(void);
    char * GetName(void);
    u16 * GetSprite(void);
    s32 GetX(s32, s32);
    void Init(s32, s32);
    void _020077b8(char *, s32, s32, u8);
    void _02007874(char *, s32, s32);
    void Update(void);
    void Draw(void);
    void Hide(void);
    void Clear(void);
    void LoadGfx(char * fidStr);
    void UpdateBlink(void);
    void DrawBlink(void);
    void UpdateMouth(void);
    void DrawMouth(void);
    void DrawMouthExt(s32 x, s32 y, s32);
    void _02008454(void);
    void _02008780(void);
};

class FaceHandle : public ProcEx
{
public:
    /* 38 */ struct Face * faces;

    FaceHandle();

    virtual ~FaceHandle();

    void InitFaces(void);
    void UpdateFaces(void);
    void DrawFaces(void);
    BOOL _02008908(void);
};

extern FaceHandle * gFaceHandle;

#endif // FACE_HPP