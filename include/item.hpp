#ifndef ITEM_HPP
#define ITEM_HPP

#include "global.h"

enum
{
    ITYPE_SWORD       = 0,
    ITYPE_LANCE       = 1,
    ITYPE_AXE         = 2,
    ITYPE_BOW         = 3,
    ITYPE_MAGIC       = 4,
    ITYPE_STAFF       = 5,
    ITYPE_DRAGONSTONE = 6,
    ITYPE_BALLISTA    = 7,
    ITYPE_ITEM        = 8,
};

enum
{
    ITEM_EFFECT_HEAL           = 0,
    ITEM_EFFECT_STAT_BOOST     = 1,
    ITEM_EFFECT_WLVL_BOOST     = 2,
    ITEM_EFFECT_TEMP_RES_BOOST = 3, // Pure Water, Barrier, Parthia
    ITEM_EFFECT_TORCH          = 4,
    ITEM_EFFECT_PROMOTE        = 5,
    ITEM_EFFECT_IOTES_SHIELD   = 6,
    ITEM_EFFECT_WARP           = 7,
    ITEM_EFFECT_REPAIR         = 8, // Hammerne
    ITEM_EFFECT_REVIVE         = 9, // Aum
    ITEM_EFFECT_A              = 10,
    ITEM_EFFECT_FIRESTONE      = 11,
    ITEM_EFFECT_EARTHSTONE     = 12,
    ITEM_EFFECT_MAGESTONE      = 13,
    ITEM_EFFECT_DIVINESTONE    = 14,
};

#pragma enumsalwaysint off
#pragma longlong_enums on

enum
{
    IA_USABLE = (1ull << 0),
    IA_BRAVE = (1ull << 1),
    IA_MAGIC = (1ull << 2),
    IA_SIEGE = (1ull << 3), // ballista? long range?
    IA_FORTIFY = (1ull << 4),
    IA_HEAL_STAFF = (1ull << 5), // TODO: Bad name? Applies to Mend, Physic, Fortify
    IA_DEVIL = (1ull << 6),

    IA_INVINCIBLE = (1ull << 10), // Prevent enemy attack, maybe?
    IA_NEGATE_INVINCIBLE = (1ull << 11),

    IA_LIGHTSPHERE = (1ull << 16), // Negate terrain effect, maybe?

    IA_UNLOCK_CHEST = (1ull << 19),
    IA_UNLOCK_DOOR = (1ull << 20),
    IA_UNLOCK_BRIDGE = (1ull << 21),
    IA_UNK_22 = (1ull << 22), // TODO: Name - possibly thief-related?
    IA_SILVER_CARD = (1ull << 23),
    IA_MEMBER_CARD = (1ull << 24),
    IA_UNSELLABLE = (1ull << 25), // TODO: Confirm; applies to Aura, Excalibur, Starlight
    IA_FIRE_EMBLEM = (1ull << 26), // TODO: What does it do?
    IA_UNK_27 = (1ull << 27), // TODO: Name - applies to Imhullu, Fire Emblem
    IA_UNK_28 = (1ull << 28), // TODO: Name - applies to Starsphere; maybe prevents reducing uses?

    IA_UNK_31 = (1ull << 31),

    IA_FALSE_IMHULLU = (1ull << 33),
    IA_ELYSIAN_WHIP = (1ull << 34),
    IA_UNK_35 = (1ull << 35), // TODO: Name - applies to Lightsphere, Starsphere, Fire Emblem
    IA_GRADIUS_LOCK = (1ull << 36),

    IA_AURA_WLVL = (1ull << 48), // Allow Linde to use at rank E
    IA_EXCALIBUR_WLVL = (1ull << 49), // Allow Merric to use at rank E
    IA_UNK_50 = (1ull << 50),
    IA_MARTH_LOCK = (1ull << 51), // Rapier
    IA_PRINCESS_LOCK = (1ull << 52), // Aum
    IA_CAEDA_LOCK = (1ull << 53), // Winged Spear
    IA_LENA_LOCK = (1ull << 54), // Hammerne
    IA_UNK_55 = (1ull << 55),
    IA_UNK_56 = (1ull << 56),
    IA_LONGBOW = (1ull << 57),
    IA_EXCALIBUR_LOCK = (1ull << 58), // Lock to males only
    IA_AURA_LOCK = (1ull << 59), // Lock to females only

    IA_UNK_62 = (1ull << 62), // TODO: Name - applies to Devil Axe, Devil Sword, Hauteclare, Parthia, Firestone, Earthstone, Magestone, Divinestone, Imhullu (false)
    IA_UNK_63 = (1ull << 63),

    _IA_FORCE_ULONGLONG = 0xFFFFFFFFFFFFFFF,
};

#pragma longlong_enums reset
#pragma enumsalwaysint reset

#endif // ITEM_HPP