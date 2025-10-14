#include "global.h"

#include "map.hpp"
#include "unknown_funcs.h"

// TODO: Constants for screen height, width, and tile size

void Camera::func_ov000_021a4a7c(void)
{
    this->unk_0c = 24;
    this->unk_0e = 0x100 / this->unk_0c;
    this->unk_10 = 0xC0 / this->unk_0c;
    this->unk_12 = this->unk_0c / 4;
    this->unk_14 = 0;
    this->unk_16 = 0;
    this->unk_18 = 1;
    this->unk_19 = 1;

    this->func_ov000_021a52b0();

    return;
}

void Camera::func_ov000_021a4ae0(s32 x, s32 y, BOOL snapToCenter)
{
    if (snapToCenter)
    {
        this->unk_14 = x * 0x18 - 0x74;
        this->unk_16 = y * 0x18 - 0x54;
    }
    else
    {
        this->unk_14 = this->unk_00;
        this->unk_16 = this->unk_04;

        if (this->unk_00 >= (x - 2) * 0x18 - 1)
        {
            this->unk_14 = (x - 2) * 0x18;
        }

        if (this->unk_00 + 0x100 <= (x + 3) * 0x18 + 1)
        {
            this->unk_14 = (x + 3) * 0x18 - 0x100;
        }

        if (this->unk_04 >= (y - 2) * 0x18 - 1)
        {
            this->unk_16 = (y - 2) * 0x18;
        }

        if (this->unk_04 + 0xc0 <= (y + 3) * 0x18 + 1)
        {
            this->unk_16 = (y + 3) * 0x18 - 0xc0;
        }
    }

    this->func_ov000_021a4ea8();

    return;
}

void Camera::func_ov000_021a4ba0(s32 x, s32 y, BOOL snapToCenter)
{
    if (snapToCenter)
    {
        this->unk_14 = x - 0x80;
        this->unk_16 = y - 0x60;
    }
    else
    {
        this->unk_14 = this->unk_00;
        this->unk_16 = this->unk_04;

        if (this->unk_00 >= x - 0x31)
        {
            this->unk_14 = x - 0x30;
        }

        if (this->unk_00 + 0x100 <= x + 0x49)
        {
            this->unk_14 = x - 0xb8;
        }

        if (this->unk_04 >= y - 0x31)
        {
            this->unk_16 = y - 0x30;
        }

        if (this->unk_04 + 0xc0 <= y + 0x49)
        {
            this->unk_16 = y - 0x78;
        }
    }

    this->func_ov000_021a4ea8();

    return;
}

BOOL Camera::func_ov000_021a4c30(s32 x, s32 y)
{
    s16 sVar1 = this->unk_14;
    s16 sVar2 = this->unk_16;

    if (x < 0x10)
    {
        if (x < 8)
        {
            this->unk_14 = this->unk_00 - 8;
        }
        else
        {
            this->unk_14 = this->unk_00 - 4;
        }
    }
    else if (x >= 0xf0)
    {
        if (x >= 0xf8)
        {
            this->unk_14 = this->unk_00 + 8;
        }
        else
        {
            this->unk_14 = this->unk_00 + 4;
        }
    }
    if (y < 0x10)
    {
        if (y < 8)
        {
            this->unk_16 = this->unk_04 - 8;
        }
        else
        {
            this->unk_16 = this->unk_04 - 4;
        }
    }
    else if (y >= 0xb0)
    {
        if (y >= 0xb8)
        {
            this->unk_16 = this->unk_04 + 8;
        }
        else
        {
            this->unk_16 = this->unk_04 + 4;
        }
    }

    this->func_ov000_021a4ea8();

    return sVar1 != this->unk_14 || sVar2 != this->unk_16;
}

static inline s32 SQRT_WRAPPER(s32 a, s32 b, s32 c, s32 d)
{
    s32 iVar5 = ABS(a - b);
    s32 iVar3 = ABS(c - d);

    return IntSys_Sqrt(iVar5 * iVar5 + iVar3 * iVar3);
}

void Camera::func_ov000_021a4cec(s32 x, s32 y, BOOL snapToCenter, s32 duration, u8 flag)
{
    s32 d;
    s32 c;
    s32 b;
    s32 a;
    s32 sqrt;

    if (this->func_ov000_021a4f7c(x, y, snapToCenter) != 0)
    {
        this->unk_1c = this->unk_00;
        this->unk_1e = this->unk_04;

        this->func_ov000_021a4ae0(x, y, snapToCenter);

        a = this->unk_1c;
        b = this->unk_14;
        c = this->unk_1e;
        d = this->unk_16;

        // This is silly, but the combination of macros and the static inline function seem to prompt the compiler
        // to create the matching ASM sequence...
        ABS(a - b);
        ABS(c - d);

        sqrt = SQRT_WRAPPER(a, b, c, d);

        this->unk_20 = IntSys_Div(sqrt, this->unk_12);

        if (this->unk_20 < 4)
        {
            this->unk_20 = 4;
        }

        if (this->unk_20 > duration)
        {
            this->unk_20 = duration;
        }

        this->unk_22 = 0;

        if (this->unk_18 < 2)
        {
            this->unk_19 = this->unk_18;
        }

        if (flag != 0)
        {
            this->unk_18 = 3;
        }
        else
        {
            this->unk_18 = 2;
        }

        this->unk_1a = 4;
    }

    return;
}

void Camera::func_ov000_021a4dc0(s32 x, s32 y, s32 snapToCenter, s32 duration, s32 interpolateKind, u8 flag)
{
    if (duration == -1)
    {
        this->func_ov000_021a4cec(x, y, snapToCenter, 0x20, 0);
        this->unk_1a = interpolateKind;
        return;
    }

    if (this->func_ov000_021a4f7c(x, y, snapToCenter) != 0)
    {
        this->unk_1a = interpolateKind;

        this->unk_1c = this->unk_00;
        this->unk_1e = this->unk_04;

        this->func_ov000_021a4ae0(x, y, snapToCenter);

        this->unk_20 = duration;
        this->unk_22 = 0;

        if (this->unk_18 < 2)
        {
            this->unk_19 = this->unk_18;
        }

        if (flag != 0)
        {
            this->unk_18 = 3;
        }
        else
        {
            this->unk_18 = 2;
        }
    }

    return;
}

void Camera::func_ov000_021a4e84(s32 x, s32 y, BOOL snapToCenter)
{
    this->func_ov000_021a4ae0(x, y, snapToCenter);
    this->func_ov000_021a52c8(this->unk_14, this->unk_16, 0);

    return;
}

void Camera::func_ov000_021a4ea8(void)
{
    s32 iVar3;

    s32 sVar1 = this->unk_14;
    s32 sVar2 = this->unk_16;

    iVar3 = gMapStateManager->unk_24 * 0x18;

    if (sVar1 < iVar3 - 0x18)
    {
        this->unk_14 = iVar3 - 0x18;
    }

    iVar3 = gMapStateManager->unk_26 * 0x18;

    if (sVar1 + 0x100 > iVar3 + 0x18)
    {
        this->unk_14 = iVar3 - 0xe8;
    }

    iVar3 = gMapStateManager->unk_25 * 0x18;

    if (sVar2 < iVar3 - 0x18)
    {
        this->unk_16 = iVar3 - 0x18;
    }

    iVar3 = gMapStateManager->unk_27 * 0x18;

    if (sVar2 + 0xc0 > iVar3 + 0x18)
    {
        this->unk_16 = iVar3 - 0xa8;
    }

    return;
}

BOOL Camera::func_ov000_021a4f4c(void)
{
    s32 val = gMapStateManager->unk_25 * 0x18;

    if (this->unk_04 > val - 0x18)
    {
        return TRUE;
    }

    return FALSE;
}

BOOL Camera::func_ov000_021a4f7c(s32 x, s32 y, BOOL snapToCenter)
{
    s32 sVar1 = this->unk_14;
    s32 sVar2 = this->unk_16;

    this->func_ov000_021a4ae0(x, y, snapToCenter);

    if (this->unk_14 == sVar1 && this->unk_16 == sVar2)
    {
        return FALSE;
    }

    this->unk_14 = sVar1;
    this->unk_16 = sVar2;

    return TRUE;
}

void Camera::func_ov000_021a4fb4(void)
{
    s32 x;
    s32 xclamp;
    s32 y;
    s32 yclamp;
    s32 range;

    x = this->unk_14;
    xclamp = this->unk_00;

    range = this->unk_12;

    if (gMapStateManager->unk_0c->unk_24)
    {
        range *= 2;
    }

    y = this->unk_04;
    yclamp = this->unk_16;

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

    this->func_ov000_021a52c8(x, y, 0);

    return;
}

void Camera::func_ov000_021a5030(BOOL boostSpeed)
{
    s32 x;
    s32 y;

    this->unk_22++;

    if (boostSpeed && this->unk_22 < this->unk_20 && func_020252fc())
    {
        this->unk_22++;
    }

    if (this->unk_20 <= 4)
    {
        x = Interpolate(0, this->unk_1c, this->unk_14, this->unk_22, this->unk_20);
        y = Interpolate(0, this->unk_1e, this->unk_16, this->unk_22, this->unk_20);
    }
    else
    {
        x = Interpolate(this->unk_1a, this->unk_1c, this->unk_14, this->unk_22, this->unk_20);
        y = Interpolate(this->unk_1a, this->unk_1e, this->unk_16, this->unk_22, this->unk_20);
    }

    this->func_ov000_021a52c8(x, y, 0);

    if (this->unk_22 != this->unk_20)
    {
        return;
    }

    this->unk_18 = this->unk_19;
    this->unk_22 = 0;
    this->unk_20 = 0;

    return;
}

void Camera::func_ov000_021a5128(void)
{
    switch (this->unk_18)
    {
        case 1:
            this->func_ov000_021a4fb4();
            break;

        case 2:
            this->func_ov000_021a5030(FALSE);
            break;

        case 3:
            this->func_ov000_021a5030(TRUE);
            break;
    }

    return;
}

void Camera::func_ov000_021a516c(void)
{
    if (this->unk_18 == 1)
    {
        return;
    }

    if (this->unk_18 != 2 && this->unk_18 != 3)
    {
        return;
    }

    this->func_ov000_021a52c8(this->unk_14, this->unk_16, 0);

    this->unk_18 = this->unk_19;

    this->unk_22 = 0;
    this->unk_20 = 0;

    return;
}

BOOL Camera::func_ov000_021a51b8(s32 x, s32 y, struct Vec3 * pos)
{
    pos->x = x * this->unk_0c - this->unk_00;
    pos->y = y * this->unk_0c - this->unk_04;

    if ((pos->x + this->unk_0c <= 0) || (pos->x >= 0x100) || (pos->y + this->unk_0c <= 0) || (pos->y >= 0xc0))
    {
        return FALSE;
    }

    return TRUE;
}

BOOL Camera::func_ov000_021a5228(s32 x, s32 y, struct Vec3 * pos)
{
    struct Vec3 local;

    this->func_ov000_021a52f8(x, y, &local);

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

void Camera::func_ov000_021a52b0(void)
{
    this->func_ov000_021a52c8(0, 0, 0);

    return;
}

void Camera::func_ov000_021a52c8(s32 x, s32 y, s32 z)
{
    this->unk_00 = x;
    this->unk_04 = y;
    this->unk_08 = z;

    return;
}

void Camera::func_ov000_021a52d0(s32 x, s32 y, s32 z)
{
    this->unk_00 += x;
    this->unk_04 += y;
    this->unk_08 += z;

    return;
}

BOOL Camera::func_ov000_021a52f8(s32 x, s32 y, struct Vec3 * pos)
{
    pos->x = x + this->unk_00;
    pos->y = y + this->unk_04;

    return TRUE;
}
