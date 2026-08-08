#include "global.h"

#include "map.hpp"
#include "unknown_funcs.h"

// TODO: Constants for screen height, width, and tile size

void Camera::Init(void)
{
    this->tileSize = 24;
    this->screenWidthTiles = 0x100 / this->tileSize;
    this->screenHeightTiles = 0xC0 / this->tileSize;
    this->speed = this->tileSize / 4;
    this->xTarget = 0;
    this->yTarget = 0;
    this->state = 1;
    this->unk_19 = 1;

    this->ResetPos();

    return;
}

void Camera::SetGoalTile(s32 x, s32 y, BOOL snapToCenter)
{
    if (snapToCenter)
    {
        this->xTarget = x * 0x18 - 0x74;
        this->yTarget = y * 0x18 - 0x54;
    }
    else
    {
        this->xTarget = this->x;
        this->yTarget = this->y;

        if (this->x >= (x - 2) * 0x18 - 1)
        {
            this->xTarget = (x - 2) * 0x18;
        }

        if (this->x + 0x100 <= (x + 3) * 0x18 + 1)
        {
            this->xTarget = (x + 3) * 0x18 - 0x100;
        }

        if (this->y >= (y - 2) * 0x18 - 1)
        {
            this->yTarget = (y - 2) * 0x18;
        }

        if (this->y + 0xc0 <= (y + 3) * 0x18 + 1)
        {
            this->yTarget = (y + 3) * 0x18 - 0xc0;
        }
    }

    this->Clamp();

    return;
}

void Camera::SetGoalPx(s32 x, s32 y, BOOL snapToCenter)
{
    if (snapToCenter)
    {
        this->xTarget = x - 0x80;
        this->yTarget = y - 0x60;
    }
    else
    {
        this->xTarget = this->x;
        this->yTarget = this->y;

        if (this->x >= x - 0x31)
        {
            this->xTarget = x - 0x30;
        }

        if (this->x + 0x100 <= x + 0x49)
        {
            this->xTarget = x - 0xb8;
        }

        if (this->y >= y - 0x31)
        {
            this->yTarget = y - 0x30;
        }

        if (this->y + 0xc0 <= y + 0x49)
        {
            this->yTarget = y - 0x78;
        }
    }

    this->Clamp();

    return;
}

BOOL Camera::_021a4c30(s32 x, s32 y)
{
    s16 xTarget = this->xTarget;
    s16 yTarget = this->yTarget;

    if (x < 0x10)
    {
        if (x < 8)
        {
            this->xTarget = this->x - 8;
        }
        else
        {
            this->xTarget = this->x - 4;
        }
    }
    else if (x >= 0xf0)
    {
        if (x >= 0xf8)
        {
            this->xTarget = this->x + 8;
        }
        else
        {
            this->xTarget = this->x + 4;
        }
    }
    if (y < 0x10)
    {
        if (y < 8)
        {
            this->yTarget = this->y - 8;
        }
        else
        {
            this->yTarget = this->y - 4;
        }
    }
    else if (y >= 0xb0)
    {
        if (y >= 0xb8)
        {
            this->yTarget = this->y + 8;
        }
        else
        {
            this->yTarget = this->y + 4;
        }
    }

    this->Clamp();

    return xTarget != this->xTarget || yTarget != this->yTarget;
}

static inline s32 SQRT_WRAPPER(s32 a, s32 b, s32 c, s32 d)
{
    s32 iVar5 = ABS(a - b);
    s32 iVar3 = ABS(c - d);

    return IntSys_Sqrt(iVar5 * iVar5 + iVar3 * iVar3);
}

void Camera::Scroll(s32 x, s32 y, BOOL snapToCenter, s32 duration, u8 flag)
{
    s32 d;
    s32 c;
    s32 b;
    s32 a;
    s32 sqrt;

    if (this->NeedsScroll(x, y, snapToCenter) != 0)
    {
        this->xStart = this->x;
        this->yStart = this->y;

        this->SetGoalTile(x, y, snapToCenter);

        a = this->xStart;
        b = this->xTarget;
        c = this->yStart;
        d = this->yTarget;

        // This is silly, but the combination of macros and the static inline function seem to prompt the compiler
        // to create the matching ASM sequence...
        ABS(a - b);
        ABS(c - d);

        sqrt = SQRT_WRAPPER(a, b, c, d);

        this->duration = IntSys_Div(sqrt, this->speed);

        if (this->duration < 4)
        {
            this->duration = 4;
        }

        if (this->duration > duration)
        {
            this->duration = duration;
        }

        this->timer = 0;

        if (this->state < 2)
        {
            this->unk_19 = this->state;
        }

        if (flag != 0)
        {
            this->state = 3;
        }
        else
        {
            this->state = 2;
        }

        this->unk_1a = 4;
    }

    return;
}

void Camera::ScrollEx(s32 x, s32 y, s32 snapToCenter, s32 duration, s32 interpolateKind, u8 flag)
{
    if (duration == -1)
    {
        this->Scroll(x, y, snapToCenter, 0x20, 0);
        this->unk_1a = interpolateKind;
        return;
    }

    if (this->NeedsScroll(x, y, snapToCenter) != 0)
    {
        this->unk_1a = interpolateKind;

        this->xStart = this->x;
        this->yStart = this->y;

        this->SetGoalTile(x, y, snapToCenter);

        this->duration = duration;
        this->timer = 0;

        if (this->state < 2)
        {
            this->unk_19 = this->state;
        }

        if (flag != 0)
        {
            this->state = 3;
        }
        else
        {
            this->state = 2;
        }
    }

    return;
}

void Camera::ScrollInstant(s32 x, s32 y, BOOL snapToCenter)
{
    this->SetGoalTile(x, y, snapToCenter);
    this->SetPos(this->xTarget, this->yTarget, 0);

    return;
}

void Camera::Clamp(void)
{
    s32 var;

    s32 xTarget = this->xTarget;
    s32 yTarget = this->yTarget;

    var = gMapStateManager->unk_24 * 0x18;

    if (xTarget < var - 0x18)
    {
        this->xTarget = var - 0x18;
    }

    var = gMapStateManager->unk_26 * 0x18;

    if (xTarget + 0x100 > var + 0x18)
    {
        this->xTarget = var - 0xe8;
    }

    var = gMapStateManager->unk_25 * 0x18;

    if (yTarget < var - 0x18)
    {
        this->yTarget = var - 0x18;
    }

    var = gMapStateManager->unk_27 * 0x18;

    if (yTarget + 0xc0 > var + 0x18)
    {
        this->yTarget = var - 0xa8;
    }

    return;
}

BOOL Camera::IsAtEdge(void)
{
    s32 val = gMapStateManager->unk_25 * 0x18;

    if (this->y > val - 0x18)
    {
        return TRUE;
    }

    return FALSE;
}

BOOL Camera::NeedsScroll(s32 x, s32 y, BOOL snapToCenter)
{
    s32 xTarget = this->xTarget;
    s32 yTarget = this->yTarget;

    this->SetGoalTile(x, y, snapToCenter);

    if (this->xTarget == xTarget && this->yTarget == yTarget)
    {
        return FALSE;
    }

    this->xTarget = xTarget;
    this->yTarget = yTarget;

    return TRUE;
}

void Camera::_021a4fb4(void)
{
    s32 x;
    s32 xclamp;
    s32 y;
    s32 yclamp;
    s32 range;

    x = this->xTarget;
    xclamp = this->x;

    range = this->speed;

    if (gMapStateManager->inputHandler->unk_24)
    {
        range *= 2;
    }

    y = this->y;
    yclamp = this->yTarget;

    if (x - xclamp > range)
    {
        x = xclamp + range;
    }
    else if (x - xclamp < -range)
    {
        x = xclamp - range;
    }
    else
    {
        // x = xclamp;
    }

    if (yclamp - y > range)
    {
        y += range;
    }
    else if (yclamp - y < -range)
    {
        y -= range;
    }
    else
    {
        y = yclamp;
    }

    this->SetPos(x, y, 0);

    return;
}

void Camera::_021a5030(BOOL boostSpeed)
{
    s32 x;
    s32 y;

    this->timer++;

    if (boostSpeed && this->timer < this->duration && func_020252fc())
    {
        this->timer++;
    }

    if (this->duration <= 4)
    {
        x = Interpolate(0, this->xStart, this->xTarget, this->timer, this->duration);
        y = Interpolate(0, this->yStart, this->yTarget, this->timer, this->duration);
    }
    else
    {
        x = Interpolate(this->unk_1a, this->xStart, this->xTarget, this->timer, this->duration);
        y = Interpolate(this->unk_1a, this->yStart, this->yTarget, this->timer, this->duration);
    }

    this->SetPos(x, y, 0);

    if (this->timer != this->duration)
    {
        return;
    }

    this->state = this->unk_19;
    this->timer = 0;
    this->duration = 0;

    return;
}

void Camera::Update(void)
{
    switch (this->state)
    {
        case 1:
            this->_021a4fb4();
            break;

        case 2:
            this->_021a5030(FALSE);
            break;

        case 3:
            this->_021a5030(TRUE);
            break;
    }

    return;
}

void Camera::StopScroll(void)
{
    if (this->state == 1)
    {
        return;
    }

    if (this->state != 2 && this->state != 3)
    {
        return;
    }

    this->SetPos(this->xTarget, this->yTarget, 0);

    this->state = this->unk_19;

    this->timer = 0;
    this->duration = 0;

    return;
}

BOOL Camera::_021a51b8(s32 x, s32 y, struct Vec3 * pos)
{
    pos->x = x * this->tileSize - this->x;
    pos->y = y * this->tileSize - this->y;

    if ((pos->x + this->tileSize <= 0) || (pos->x >= 0x100) || (pos->y + this->tileSize <= 0) || (pos->y >= 0xc0))
    {
        return FALSE;
    }

    return TRUE;
}

BOOL Camera::_021a5228(s32 x, s32 y, struct Vec3 * pos)
{
    struct Vec3 local;

    this->_021a52f8(x, y, &local);

    if (local.x < 0)
    {
        local.x -= (GetTileSize() - 1);
    }

    if (local.y < 0)
    {
        local.y -= (GetTileSize() - 1);
    }

    pos->x = IntSys_Div(local.x, GetTileSize());
    pos->y = IntSys_Div(local.y, GetTileSize());

    return 1;
}

void Camera::ResetPos(void)
{
    this->SetPos(0, 0, 0);

    return;
}

void Camera::SetPos(s32 x, s32 y, s32 z)
{
    this->x = x;
    this->y = y;
    this->z = z;

    return;
}

void Camera::AddPos(s32 x, s32 y, s32 z)
{
    this->x += x;
    this->y += y;
    this->z += z;

    return;
}

BOOL Camera::_021a52f8(s32 x, s32 y, struct Vec3 * pos)
{
    pos->x = x + this->x;
    pos->y = y + this->y;

    return TRUE;
}
