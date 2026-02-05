#ifndef LINK_DIALOG_HPP
#define LINK_DIALOG_HPP

#include "proc_ex.hpp"

class LinkErrorDialog : public ProcEx
{
public:
    char * unk_38;

    LinkErrorDialog(char * str)
    {
        this->unk_38 = str;
    }

    virtual ~LinkErrorDialog()
    {
    }
};

#endif // LINK_DIALOG_HPP