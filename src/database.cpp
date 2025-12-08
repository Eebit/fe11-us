#include "global.h"

#include "unknown_types.h"

#include "database.hpp"
#include "hashtable.hpp"
#include "unit.hpp"

extern s32 data_020eea90;

EC void func_020a8f40(char *);
EC void * func_020379e0(char *, u32);

EC BOOL CheckUnitAttribute(struct Unit *, s32);
EC Unit * func_0203fd84(struct PersonData *);

EC char * func_02039e10(char *);
EC char * func_020076d4(char *);

EC char * func_02038328(struct UnkData *);
EC char * func_0203802c(struct ItemData *);

EC void func_020a58b8(void *, void *, s32);
EC void func_020b6c98(char *, char *);
EC void func_020b6e08(char *, char *);
EC s32 GetUnitMaxHp(Unit *);
EC void func_020208b0(s32, s32, s32 *, s32 *);

EC void FE11Database::Init(void)
{
    Unit_unk_a4 * puVar4;
    s32 i;

    func_020a8f40("/data");

    this->unk_00 = func_020379e0("database", 1);
    this->unk_04 = func_020379e0("tut", 1);

    this->pPerson = static_cast<struct PersonData *>(HashTable::Get2("Person"));
    this->pJob = static_cast<struct JobData *>(HashTable::Get2("Job"));
    this->pItem = static_cast<struct ItemData *>(HashTable::Get2("Item"));
    this->unk_14 = HashTable::Get2("ItemRefine");
    this->unk_18 = HashTable::Get2("MapTbl");
    this->unk_1c = HashTable::Get2("Belong");
    this->pTerrain = static_cast<struct TerrainData *>(HashTable::Get2("Terrain"));
    this->unk_24 = HashTable::Get2("TerrainCategory");
    this->unk_28 = HashTable::Get2("TerrainCost");
    this->pWeaponLevel = static_cast<u8 *>(HashTable::Get2("WeaponLevel"));
    this->unk_30 = HashTable::Get2("WeaponBonus");
    this->unk_34 = HashTable::Get2("WeaponDeadlock");
    this->unk_38 = static_cast<Unit_unk_a4 *>(HashTable::Get2("StringTable"));
    this->unk_3c = HashTable::Get2("Tutorial");
    this->unk_40 = HashTable::Get2("TutHelp");
    this->unk_44 = HashTable::Get2("Charm");
    this->pDBFE11Footer = static_cast<struct DBFE11Footer *>(HashTable::Get2("DBFE11Footer"));

    for (i = 0; i < gFE11Database->pDBFE11Footer->pidTableLength; i++)
    {
        HashTable::Put(gFE11Database->pPerson[i].unk_00, &gFE11Database->pPerson[i]);
    }

    for (i = 0; i < gFE11Database->pDBFE11Footer->jidTableLength; i++)
    {
        HashTable::Put(gFE11Database->pJob[i].unk_00, &gFE11Database->pJob[i]);
    }

    for (i = 0; i < gFE11Database->pDBFE11Footer->iidTableLength; i++)
    {
        HashTable::Put(gFE11Database->pItem[i].id, &gFE11Database->pItem[i]);
    }

    for (puVar4 = this->unk_38; puVar4->unk_00 != NULL; puVar4++)
    {
        HashTable::Put(puVar4->unk_00, puVar4);
    }

    return;
}

EC struct PersonData * GetPersonByPidStr(char * pidStr)
{
    return static_cast<struct PersonData *>(HashTable::Get2(pidStr));
}

EC struct JobData * GetJobByJidStr(char * jidStr)
{
    return static_cast<struct JobData *>(HashTable::Get2(jidStr));
}

EC struct ItemData * GetItemByIidStr(char * iidStr)
{
    return static_cast<struct ItemData *>(HashTable::Get2(iidStr));
}

EC struct MapData * GetMapByMidStr(char * midStr)
{
    return static_cast<struct MapData *>(HashTable::Get2(midStr));
}

EC struct MapData * func_02037c80(s32 idx)
{
    return GetMapByMidStr("arena01") + idx;
}

EC void * func_02037c9c(char * str)
{
    return HashTable::Get1(str);
}

EC char * func_02037ca8(s32 param_1, BOOL isCapital)
{
    if (isCapital)
    {
        switch (param_1)
        {
            case 0:
                return "";
            case 1:
                break;
            case 2:
                return "A ";
            case 3:
                return "An ";
            case 4:
                return "The ";
        }
    }
    else
    {
        switch (param_1)
        {
            case 0:
                return "";
            case 1:
                break;
            case 2:
                return "a ";
            case 3:
                return "an ";
            case 4:
                return "the ";
        }
    }

    return "";
}

EC s32 func_02037d54(s32 arg0, char * arg1)
{
    if (arg0 != 1)
    {
        return arg0;
    }

    if (arg1 == NULL)
    {
        return 0;
    }

    switch (*arg1)
    {
        case 'A':
        case 'E':
        case 'I':
        case 'O':
        case 'U':

        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
            return 3;

        default:
            return 2;
    }
}

EC char * func_02037dfc(struct ItemData * pItem, s32 param_2)
{
    if (data_020eea90 == 1)
    {
        return func_02037ca8(func_02037d54(pItem->unk_3b, func_0203802c(pItem)), param_2);
    }

    return "";
}

EC char * func_02037e44(struct UnkData * param_1, s32 param_2)
{
    if (data_020eea90 == 1)
    {
        return func_02037ca8(func_02037d54(param_1->unk_09, func_02038328(param_1)), param_2);
    }

    return "";
}

EC s32 GetPersonDBIndex(struct PersonData * pPerson)
{
    return ((s32)pPerson - (s32)gFE11Database->pPerson) / (s32)sizeof(struct PersonData);
}

EC char * func_02037eb8(struct PersonData * pPerson)
{
    if (pPerson->unk_08 != NULL)
    {
        return func_02039e10(pPerson->unk_08);
    }

    if (pPerson->unk_04 != NULL)
    {
        return func_020076d4(pPerson->unk_04);
    }

    return "NoName";
}

EC char * func_02037ef0(struct PersonData * pPerson, Unit * pUnit)
{
    BOOL bVar4 = FALSE;

    if (pUnit != NULL)
    {
        if ((func_02037ef0(pUnit->pPersonData, NULL) == 0) && (pUnit->pJobData->unk_48 != NULL))
        {
            return pUnit->pJobData->unk_48;
        }

        if (CheckUnitAttribute(pUnit, 0x4000000) != 0)
        {
            bVar4 = TRUE;
        }
    }
    else
    {
        if ((pPerson->unk_24 & 0x4000000) != 0)
        {
            bVar4 = TRUE;
        }
    }

    if ((bVar4) && (func_0203fd84(pPerson) != 0) && (pPerson == GetPersonByPidStr("PID_MARS")))
    {
        return "FID_S_MARS";
    }

    return pPerson->unk_04;
}

EC void * func_02037f88(struct PersonData * pPerson, Unit * pUnit)
{
    return HashTable::Get1(func_02037ef0(pPerson, pUnit));
}

EC s32 GetJobDBIndex(struct JobData * pJob)
{
    return ((s32)pJob - (s32)gFE11Database->pJob) / (s32)sizeof(struct JobData);
}

EC char * func_02037fc8(struct JobData * pJob)
{
    return func_02039e10(pJob->unk_04);
}

EC s32 GetJobMaxLevel(struct JobData * pJob)
{
    if ((pJob->attributes & 0x800) != 0)
    {
        return 20;
    }

    if (pJob->pPromoteJob != NULL)
    {
        return 20;
    }

    return 30;
}

EC s32 GetItemDBIndex(struct ItemData * pItem)
{
    return ((s32)pItem - (s32)gFE11Database->pItem) / (s32)sizeof(struct ItemData);
}

EC char * func_0203802c(struct ItemData * pItem)
{
    s32 len = gFE11Database->pDBFE11Footer->iidTableLength;

    if (GetItemDBIndex(pItem) >= len)
    {
        return pItem->pName;
    }

    return func_02039e10(pItem->pName);
}

EC char * func_02038060(struct ItemData * pItem)
{
    if (pItem->pDescription != NULL)
    {
        return func_02039e10(pItem->pDescription);
    }

    return NULL;
}

EC void
func_0203807c(struct ItemData * dst, struct ItemData * src, char * str, s32 might, s32 hit, s32 critical, s32 weight)
{
    char * uVar1;

    uVar1 = dst->id;
    func_020a58b8(src, dst, sizeof(struct ItemData));
    dst->id = uVar1;

    dst->might += might;
    dst->hit += hit;
    dst->critical += critical;
    dst->weight += weight;

    dst->pName = str;

    dst->attributes |= 0x8000000000000000;

    dst->unk_3b = 4;

    return;
}

EC s32 GetMapDBIndex(struct MapData * pMap)
{
    return ((s32)pMap - (s32)gFE11Database->unk_18) / (s32)sizeof(struct MapData);
}

EC char * func_0203812c(struct MapData * pMap)
{
    char * mapName = static_cast<char *>(HashTable::Get1(pMap->unk_04));

    if (mapName == NULL)
    {
        return pMap->unk_00;
    }

    return mapName;
}

EC void * func_02038148(struct MapData * pMap)
{
    char * ret;
    char str[32];

    func_020b6c98(str, pMap->unk_04);
    func_020b6e08(str, "SM");

    ret = static_cast<char *>(HashTable::Get1(str));

    if (ret == NULL)
    {
        return pMap->unk_00;
    }

    return ret;
}

EC void * func_02038188(struct MapData * pMap)
{
    char * ret;
    char str[32];

    func_020b6c98(str, pMap->unk_04);
    func_020b6e08(str, "AF");

    ret = static_cast<char *>(HashTable::Get1(str));

    if (ret == NULL)
    {
        return pMap->unk_00;
    }

    return ret;
}

EC char * func_020381c8(struct TerrainData * pTerrain)
{
    return func_02039e10(pTerrain->unk_00);
}

static inline s32 min(s32 a, s32 b)
{
    if (a < b)
    {
        return a;
    }

    return b;
}

EC s32 func_020381d8(struct TerrainData * pTerrain, Unit * pUnit, s32 param_3)
{
    s32 maxHp;
    s32 curHp;
    s32 quotient;
    s32 remainder;

    curHp = pUnit->hp;
    maxHp = GetUnitMaxHp(pUnit);

    func_020208b0(maxHp * pTerrain->unk_08[3], 100, &quotient, &remainder);

    if (remainder != 0)
    {
        quotient = quotient + 1;
    }

    return min(maxHp - curHp, quotient = quotient + param_3);
}

EC s32 GetTerrainCategoryDBIndex(void * pTerrainCategory)
{
    return ((s32)pTerrainCategory - (s32)gFE11Database->unk_24) / 4;
}

EC s32 func_0203826c(void * pTerrainCategory, s32 b)
{
    s32 iVar1 = GetTerrainCategoryDBIndex(pTerrainCategory);
    s32 stride = (((struct TerrainCostData *)gFE11Database->unk_28)->size + 3) & ~3;

    return ((struct TerrainCostData *)gFE11Database->unk_28)->unk_04[b * stride + iVar1];
}

EC BOOL func_020382a4(void * param_1)
{
    return (!((((s32)param_1 - (s32)gFE11Database->unk_34) / 12) & 1) ? TRUE : FALSE) & 0xFF;
}

// clang-format off

char * data_020d4734[] =
{
    "MP_HP",
    "MP_STR",
    "MP_MPOW",
    "MP_TECH",
    "MP_QUICK",
    "MP_LUCK",
    "MP_DEF",
    "MP_MDEF",
};

// clang-format on

EC char * func_020382e0(s32 idx)
{
    return func_02039e10(data_020d4734[idx]);
}

// clang-format off

char * data_020d4754[] =
{
    "MP_HP_L",
    "MP_STR_L",
    "MP_MPOW_L",
    "MP_TECH_L",
    "MP_QUICK_L",
    "MP_LUCK_L",
    "MP_DEF_L",
    "MP_MDEF_L",
};

// clang-format on

EC char * func_020382f8(s32 idx)
{
    return func_02039e10(data_020d4754[idx]);
}

// clang-format off

char * data_020d471c[] =
{
    "ML_A",
    "ML_B",
    "ML_C",
    "ML_D",
    "ML_E",
    "ML_N",
};

// clang-format on

EC char * func_02038310(s32 idx)
{
    return func_02039e10(data_020d471c[idx]);
}

// clang-format off

// unused?
char * data_020d470c[] =
{
    "ML_N",
    "ML_C",
    "ML_B",
    "ML_A",
};

// clang-format on

EC char * func_02038328(struct UnkData * param_1)
{
    return func_02039e10(param_1->unk_00);
}

EC char * func_02038338(struct CharmData * pCharm)
{
    return func_02039e10(pCharm->unk_04);
}
