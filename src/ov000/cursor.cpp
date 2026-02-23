#include "global.h"

#include "map.hpp"
#include "sound_manager.hpp"

#include "unknown_funcs.h"

#include "constants/sounds.h"

void Cursor::Init(void)
{
    int i;

    for (i = 0; i < 2; i++)
    {
        this->unk_00[i] = -1;
        this->unk_02[i] = -1;
    }

    this->xDisplay = 0;
    this->yDisplay = 0;
    this->xTile = 0;
    this->yTile = 0;
    this->isVisible = FALSE;
    this->changed = TRUE;
    this->unk_0b = 1;
    this->soundCooldownTimer = 0;
    this->unk_0e = 0;

    return;
}

void Cursor::SetPos(s32 x, s32 y, s32 param_4)
{
    if (x == this->xTile && y == this->yTile)
    {
        this->changed = FALSE;
        return;
    }

    this->xTile = x;
    this->yTile = y;

    this->changed = TRUE;

    if (param_4 != 0 && this->isVisible)
    {
        if (this->soundCooldownTimer == 0)
        {
            gSoundManager->unk_b0->vfunc_28(SE_SYS_CURSOL_MAP1, 0, 0);
            this->soundCooldownTimer = 2;
        }
    }

    return;
}

void Cursor::SetPosAnimated(s32 x, s32 y, s32 param_4, u8 param_5)
{
    s32 xNew;
    s32 yNew;

    this->SetPos(x, y, param_5);

    if (this->changed)
    {
        this->unk_0b = 2;

        if (gMapStateManager->camera->func_ov000_021a4f7c(x, y, 0))
        {
            gMapStateManager->camera->func_ov000_021a4cec(x, y, 0, param_4 != 0 ? 8 : 0x10, 0);
        }

        this->xLerpStart = this->xDisplay;
        this->yLerpStart = this->yDisplay;
        this->unk_0b = 2;

        xNew = this->xTile * GetTileSize() - this->xDisplay;
        yNew = this->yTile * GetTileSize() - this->yDisplay;

        if (xNew < 0)
        {
            xNew = -xNew;
        }

        if (yNew < 0)
        {
            yNew = -yNew;
        }

        this->lerpDuration = IntSys_Div(IntSys_Sqrt(xNew * xNew + yNew * yNew), gMapStateManager->camera->unk_12);

        if (this->lerpDuration > 4)
        {
            this->lerpDuration = 4;
        }

        this->lerpElapsed = 0;
    }

    return;
}

void Cursor::SetPosImmediate(s16 x, s16 y)
{
    this->SetPos(x, y, 1);

    this->xDisplay = this->xTile * GetTileSize();
    this->yDisplay = this->yTile * GetTileSize();

    return;
}

void Cursor::CenterOnCamera(void)
{
    s32 x = gMapStateManager->camera->unk_00;
    s32 y = gMapStateManager->camera->unk_04;

    this->SetPosImmediate(IntSys_Div(x + 0x80, GetTileSize()), IntSys_Div(y + 0x60, GetTileSize()));

    return;
}

void Cursor::_021a6b4c(s32 xPx, s32 yPx)
{
    s32 diff;
    s32 var_r4 = gMapStateManager->camera->unk_12;

    if (gMapStateManager->inputHandler->unk_24 != 0)
    {
        var_r4 *= 2;
    }

    diff = xPx - this->xDisplay;

    if (diff > var_r4)
    {
        this->xDisplay += var_r4;
    }
    else if (diff < -var_r4)
    {
        this->xDisplay -= var_r4;
    }
    else
    {
        this->xDisplay = xPx;
    }

    diff = yPx - this->yDisplay;

    if (diff > var_r4)
    {
        this->yDisplay += var_r4;
    }
    else if (diff < -var_r4)
    {
        this->yDisplay -= var_r4;
    }
    else
    {
        this->yDisplay = yPx;
    }

    return;
}

void Cursor::_021a6bd0(void)
{
    this->xDisplay = this->xTile * GetTileSize();
    this->yDisplay = this->yTile * GetTileSize();

    if (gMapStateManager->inputHandler->IsUsingKeyInputs())
    {
        gMapStateManager->camera->func_ov000_021a4ba0(this->xDisplay, this->yDisplay, 0);
    }

    return;
}

void Cursor::_021a6c38(void)
{
    s32 xDisp;
    s32 yDisp;

    xDisp = this->xTile * GetTileSize();
    yDisp = this->yTile * GetTileSize();

    if (gMapStateManager->inputHandler->unk_1e != 0)
    {
        xDisp = this->xTile * GetTileSize();
        yDisp = this->yTile * GetTileSize();

        if (ABS(xDisp - this->xDisplay) <= GetTileSize() && ABS(yDisp - this->yDisplay) <= GetTileSize())
        {
            this->_021a6b4c(xDisp, yDisp);
            return;
        }

        this->xDisplay = this->xTile * GetTileSize();
        this->yDisplay = this->yTile * GetTileSize();

        return;
    }

    this->_021a6b4c(xDisp, yDisp);

    if (!this->isVisible)
    {
        return;
    }

    if (gMapStateManager->inputHandler->IsUsingKeyInputs())
    {
        gMapStateManager->camera->func_ov000_021a4ba0(this->xDisplay, this->yDisplay, 0);
    }

    return;
}

struct UnkStruct_02196f20
{
    STRUCT_PAD(0x000, 0x184);
    s32 unk_184;
    u32 unk_188;
    u32 unk_18c;
    s32 unk_190;
    u32 unk_194;
    u8 unk_198;
    u8 unk_199;
    u8 unk_19a;
    u8 unk_19b;
    s8 unk_19c;
    STRUCT_PAD(0x19D, 0x1A4);
};
extern struct UnkStruct_02196f20 * data_02196f20;

void Cursor::_021a6d48(void)
{
    if (this->lerpDuration != 0)
    {
        this->lerpElapsed++;

        if (this->lerpDuration < 4)
        {
            this->xDisplay =
                Interpolate(0, this->xLerpStart, this->xTile * GetTileSize(), this->lerpElapsed, this->lerpDuration);
            this->yDisplay =
                Interpolate(0, this->yLerpStart, this->yTile * GetTileSize(), this->lerpElapsed, this->lerpDuration);
        }
        else
        {
            this->xDisplay =
                Interpolate(4, this->xLerpStart, this->xTile * GetTileSize(), this->lerpElapsed, this->lerpDuration);
            this->yDisplay =
                Interpolate(4, this->yLerpStart, this->yTile * GetTileSize(), this->lerpElapsed, this->lerpDuration);
        }

        if (this->lerpElapsed == this->lerpDuration)
        {
            this->lerpElapsed = 0;
            this->lerpDuration = 0;
        }
    }

    if (this->lerpDuration == 0 && !(gMapStateManager->camera->unk_18 < 2 ? FALSE : TRUE))
    {
        this->unk_0b = 1;
    }

    return;
}

void Cursor::Update(void)
{
    switch (this->unk_0b)
    {
        case 1:
            this->_021a6c38();
            break;

        case 2:
            this->_021a6d48();
            break;
    }

    if (this->soundCooldownTimer != 0)
    {
        this->soundCooldownTimer--;
    }

    return;
}

BOOL Cursor::_021a6ea8(s32 param_2)
{
    s32 iVar3;

    s32 idk = (this->xTile * GetTileSize() + (GetTileSize() >> 1));

    if (param_2 != 0)
    {
        iVar3 = gMapStateManager->camera->unk_14;
    }
    else
    {
        iVar3 = gMapStateManager->camera->unk_00;
    }

    if ((idk - iVar3) < 0x80)
    {
        return TRUE;
    }

    return FALSE;
}
