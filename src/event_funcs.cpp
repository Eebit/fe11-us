#include "global.h"

#include "unit.hpp"

extern struct Unit * gUnitList;

// FE11U = 0x02044974
BOOL SetUnitEventDead(void * unused, s32 unitId)
{

    struct Unit * unit;
    
    if (!unitId)
    {
        unit = NULL;
    }
    else
    {
        unit = gUnitList + unitId - 1;
    }
    
    if (!unit)
    {
        return FALSE;
    }

    unit->state2 |= (0x88 | 0x20000000);
    return TRUE;
}