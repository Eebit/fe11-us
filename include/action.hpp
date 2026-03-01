#ifndef ACTION_HPP
#define ACTION_HPP

#include "global.h"

enum
{
    ACTION_NONE = 0x00,
    ACTION_FIGHT = 0x01,
    ACTION_STAFF = 0x02,
    // 0x03
    ACTION_WAIT = 0x04,
    ACTION_DOOR = 0x05,
    ACTION_CHEST = 0x06,
    ACTION_BRIDGE = 0x07,
    ACTION_VISIT_08 = 0x08,
    ACTION_VISIT_09 = 0x09,
    ACTION_ARMORY = 0x0A,
    ACTION_VENDOR = 0x0B,
    ACTION_SECRET_SHOP = 0x0C,
    ACTION_ARENA = 0x0D,
    ACTION_SEIZE = 0x0E,
    ACTION_ESCAPE = 0x0F,
    ACTION_10 = 0x10,
    ACTION_IMITATION = 0x11,
    // 0x12
    ACTION_DECOY = 0x13,
    ACTION_TALK = 0x14,
    // 0x15
    ACTION_END_TURN = 0x16,
    // 0x17
    ACTION_SURRENDER = 0x18,
};

class ActionState
{
public:
    STRUCT_PAD(0x00, 0x14);
    u32 unk_14;
    STRUCT_PAD(0x18, 0x2C);
    s8 unk_2c;
    s8 unk_2d;
    u8 unk_2e;
    u8 unk_2f;
    /* 30 */ s8 xDecision;
    /* 31 */ s8 yDecision;
    /* 32 */ u8 unitId; // "MindGetUnit" returns this
    /* 33 */ u8 actionId; // "MindGetMind" returns this
    u8 unk_34; // target unit ID?
    u8 unk_35;
    u8 unk_36;
    u8 unk_37; // item slot?

    void func_ov000_021b0eb4(struct Unit *);
    void func_ov000_021b0ee8(struct Unit *);
    void func_ov000_021b0f1c(struct Unit *);
};

extern struct ActionState * gActionSt;

#endif // ACTION_HPP