#include "global.h"

#include "unknown_data.h"
#include "unknown_funcs.h"

#include "state_manager.hpp"

static inline u8 TestFlag(u8 * arr, u32 i)
{
    return (arr[i / 8] & (1 << (i & 7)));
}

static inline u32 Align(u32 n, u32 a)
{
    return (((u32)(n) + (a) - 1) & -(a));
}

void FlagManager::func_020492a0(void)
{
    if (this->unk_04 != NULL)
    {
        func_020a5824(this->unk_04, 0, func_020114dc(data_027e1b9c, this->unk_04));
    }
    else
    {
        func_020a5824(this->unk_08, 0, func_020114dc(data_027e1b9c, this->unk_08));
    }

    return;
}

s32 FlagManager::FindIdByName(char * str)
{
    char ** it;
    s32 i;

    it = this->unk_04;

    for (i = 0; i < (s32)this->unk_0c; i++, it++)
    {
        if (*it == 0)
        {
            continue;
        }

        if (func_020b6e2c(*it, str) != 0)
        {
            continue;
        }

        return i;
    }

    return -1;
}

BOOL FlagManager::GetById(u32 flagId)
{
    if (TestFlag(this->unk_08, flagId))
    {
        return TRUE;
    }

    return FALSE;
}

BOOL FlagManager::GetByName(char * flagName)
{
    s32 id = this->FindIdByName(flagName);

    if (id != -1)
    {
        return this->GetById(id);
    }

    return FALSE;
}

void FlagManager::SetById(u32 flagId)
{
    this->unk_08[flagId / 8] |= (1 << (flagId & 7));
    return;
}

void FlagManager::SetByName(char * flagName)
{
    s32 id = this->FindIdByName(flagName);

    if (id != -1)
    {
        this->SetById(id);
    }

    return;
}

void FlagManager::ClearById(u32 flagId)
{
    this->unk_08[flagId / 8] &= (-1 ^ (1 << (flagId & 7)));
    return;
}

void FlagManager::ClearByName(char * flagName)
{
    s32 id = this->FindIdByName(flagName);

    if (id != -1)
    {
        this->ClearById(id);
    }

    return;
}

BOOL FlagManager::func_02049438(void)
{
    s32 i;

    for (i = 0; i < Align(this->unk_0c, 8) / 8; i++)
    {
        if (this->unk_08[i] != 0)
        {
            return TRUE;
        }
    }

    return FALSE;
}

void FlagManager::func_0204947c(void)
{
    func_020a5824(this->unk_08, 0xff, Align(this->unk_0c, 8) / 8);
    return;
}

void FlagManager::RegisterName(char * str, BOOL arg_1)
{
    s32 i;

    if (!arg_1)
    {
        for (i = 0; i < (s32)this->unk_0c; i++)
        {
            if (this->unk_04[i] == NULL)
            {
                this->unk_04[i] = str;
                return;
            }
        }
    }
    else
    {
        for (i = (s32)this->unk_0c - 1; i >= 0; i--)
        {
            if (this->unk_04[i] == NULL)
            {
                this->unk_04[i] = str;
                return;
            }
        }
    }

    return;
}

void FlagManager::RemoveById(u32 id)
{
    this->unk_04[id] = NULL;
    this->ClearById(id);
    return;
}

void FlagManager::RemoveAll(void)
{
    s32 i;

    for (i = this->unk_0c - 1; i >= 0; i--)
    {
        if (this->unk_04[i] == NULL)
        {
            return;
        }

        this->RemoveById(i);
    }

    return;
}

void FlagManager::func_02049564(struct UnkBuf_Func_02049564 * buf)
{
    s32 i;

    buf->WriteWord(this->unk_0c);

    for (i = 0; i < Align(this->unk_0c, 8) / 8; i++)
    {
        buf->WriteByte(this->unk_08[i]);
    }

    return;
}

void FlagManager::func_0204961c(struct UnkBuf_Func_02049564 * buf)
{
    s32 flagCount = buf->ReadWord();
    u32 byteCount;
    u8 * temp;
    s32 i;
    s32 j;

    if (flagCount == this->unk_0c)
    {
        for (i = 0; i < Align(flagCount, 8) / 8; i++)
        {
            this->unk_08[i] = buf->ReadByte();
        }

        return;
    }

    byteCount = Align(flagCount, 8) / 8;
    temp = static_cast<u8 *>(func_01ffb934(data_027e1b9c, byteCount));

    for (i = 0; i < byteCount; i++)
    {
        temp[i] = buf->ReadByte();
    }

    func_020a5824(this->unk_08, 0, byteCount);

    if (this->unk_04 != NULL)
    {
        for (j = 0; j < flagCount; j++)
        {
            if (j >= (s32)this->unk_0c)
            {
                break;
            }

            if (this->unk_04[j] == NULL)
            {
                break;
            }

            if (TestFlag(temp, j))
            {
                this->SetById(j);
            }
        }

        for (i = 0; i < flagCount - j; i++)
        {
            if (i >= (s32)this->unk_0c)
            {
                break;
            }

            if (TestFlag(temp, flagCount - i - 1))
            {
                this->SetById(this->unk_0c - i - 1);
            }
        }
    }
    else
    {
        for (i = 0; i < flagCount && i < (s32)this->unk_0c; i++)
        {
            if (i >= (s32)this->unk_0c)
            {
                break;
            }

            if (TestFlag(temp, i))
            {
                this->SetById(i);
            }
        }
    }

    func_01ffbb90(data_027e1b9c, temp);

    return;
}

void FlagManager::func_02049824(struct UnkBuf_Func_02049564 * buf, s32 arg_1)
{
    u8 * arr;
    u32 byteCount;
    s32 i;
    s32 j;

    if (arg_1 == this->unk_0c)
    {
        for (i = 0; i < Align(arg_1, 8) / 8; i++)
        {
            this->unk_08[i] = buf->ReadByte();
        }

        return;
    }

    byteCount = Align(arg_1, 8) / 8;
    arr = static_cast<u8 *>(func_01ffb934(data_027e1b9c, byteCount));

    for (i = 0; i < byteCount; i++)
    {
        arr[i] = buf->ReadByte();
    }

    func_020a5824(this->unk_08, 0, byteCount);

    if (this->unk_04 != NULL)
    {
        for (j = 0; j < arg_1; j++)
        {
            if (j >= (s32)this->unk_0c)
            {
                break;
            }

            if (this->unk_04[j] == NULL)
            {
                break;
            }

            if (TestFlag(arr, j))
            {
                this->SetById(j);
            }
        }

        for (i = 0; i < arg_1 - j; i++)
        {
            if (i >= (s32)this->unk_0c)
            {
                break;
            }

            if (TestFlag(arr, arg_1 - i - 1))
            {
                this->SetById(this->unk_0c - i - 1);
            }
        }
    }
    else
    {
        for (i = 0; i < arg_1 && i < (s32)this->unk_0c; i++)
        {
            if (i >= (s32)this->unk_0c)
            {
                break;
            }

            if (TestFlag(arr, i))
            {
                this->SetById(i);
            }
        }
    }

    func_01ffbb90(data_027e1b9c, arr);

    return;
}

s32 ValueManager::GetById(s32 valueId)
{
    u32 * values = reinterpret_cast<u32 *>(this->unk_08);
    return values[valueId];
}

s32 ValueManager::GetByName(char * valueName)
{
    s32 id = this->FindIdByName(valueName);

    if (id != -1)
    {
        return this->GetById(id);
    }

    return 0;
}

void ValueManager::SetById(s32 valueId, s32 value)
{
    u32 * values = reinterpret_cast<u32 *>(this->unk_08);
    values[valueId] = value;
    return;
}

void ValueManager::SetByName(char * valueName, s32 value)
{
    s32 id = this->FindIdByName(valueName);

    if (id != -1)
    {
        this->SetById(id, value);
    }

    return;
}

void ValueManager::ClearById(u32 valueId)
{
    u32 * values = reinterpret_cast<u32 *>(this->unk_08);
    values[valueId] = 0;
    return;
}

void ValueManager::ClearByName(char * valueName)
{
    s32 id = this->FindIdByName(valueName);

    if (id != -1)
    {
        this->ClearById(id);
    }

    return;
}

void ValueManager::func_02049a9c(struct UnkBuf_Func_02049564 * buf)
{
    u32 * arr = reinterpret_cast<u32 *>(this->unk_08);
    s32 i;

    buf->WriteWord(this->unk_0c);

    for (i = 0; i < (s32)this->unk_0c; i++)
    {
        buf->WriteWord(arr[i]);
    }

    return;
}

void ValueManager::func_02049b90(struct UnkBuf_Func_02049564 * buf)
{
    u32 * r4 = reinterpret_cast<u32 *>(this->unk_08);
    s32 count = buf->ReadWord();
    u32 * arr;
    s32 i;
    s32 j;

    if (count == this->unk_0c)
    {
        for (i = 0; i < count; i++)
        {
            r4[i] = buf->ReadWord();
        }

        return;
    }

    arr = static_cast<u32 *>(func_01ffb934(data_027e1b9c, count << 2));

    for (i = 0; i < count; i++)
    {
        arr[i] = buf->ReadWord();
    }

    func_020a5824(r4, 0, count << 2);

    if (this->unk_04 != NULL)
    {
        for (j = 0; j < count; j++)
        {
            if (j >= (s32)this->unk_0c)
            {
                break;
            }

            if (this->unk_04[j] == NULL)
            {
                break;
            }

            this->SetById(j, arr[j]);
        }

        for (i = 0; i < count - j; i++)
        {
            if (i >= (s32)this->unk_0c)
            {
                break;
            }

            this->SetById(this->unk_0c - i - 1, arr[count - i - 1]);
        }
    }
    else
    {
        for (i = 0; i < count && i < (s32)this->unk_0c; i++)
        {
            if (i >= (s32)this->unk_0c)
            {
                break;
            }

            this->SetById(i, arr[i]);
        }
    }

    func_01ffbb90(data_027e1b9c, arr);

    return;
}

void ValueManager::func_02049dc8(struct UnkBuf_Func_02049564 * buf, s32 arg_1)
{
    u32 * r4 = reinterpret_cast<u32 *>(this->unk_08);
    u32 * arr;
    s32 i;
    s32 j;

    if (arg_1 == this->unk_0c)
    {
        for (i = 0; i < arg_1; i++)
        {
            r4[i] = buf->ReadWord();
        }

        return;
    }

    arr = static_cast<u32 *>(func_01ffb934(data_027e1b9c, arg_1 << 2));

    for (i = 0; i < arg_1; i++)
    {
        arr[i] = buf->ReadWord();
    }

    func_020a5824(r4, 0, arg_1 << 2);

    if (this->unk_04 != NULL)
    {
        for (j = 0; j < arg_1; j++)
        {
            if (j >= (s32)this->unk_0c)
                break;

            if (this->unk_04[j] == NULL)
                break;

            this->SetById(j, arr[j]);
        }

        for (i = 0; i < arg_1 - j; i++)
        {
            if (i >= (s32)this->unk_0c)
                break;

            this->SetById(this->unk_0c - i - 1, arr[arg_1 - i - 1]);
        }
    }
    else
    {
        for (i = 0; i < arg_1 && i < (s32)this->unk_0c; i++)
        {
            if (i >= (s32)this->unk_0c)
                break;

            this->SetById(i, arr[i]);
        }
    }

    func_01ffbb90(data_027e1b9c, arr);

    return;
}

inline FlagManager::~FlagManager()
{
    if (this->unk_04 != NULL)
    {
        func_01ffbb90(data_027e1b9c, this->unk_04);
    }
    else
    {
        func_01ffbb90(data_027e1b9c, this->unk_08);
    }

    return;
}

ValueManager::~ValueManager()
{
    return;
}
