// MountPoints.h - Declaratio of CMountPoins
//
// WinDirStat - Directory Statistics
// Copyright (C) 2003-2005 Bernhard Seifert
// Copyright (C) 2004-2024 WinDirStat Team (windirstat.net)
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
//

#pragma once

#include "stdafx.h"

class COleFilterOverride final : public COleMessageFilter
{
public:

    BOOL m_DefaultHandler = TRUE;

    COleFilterOverride()
    {
        m_bEnableNotResponding = FALSE;
    }

    void RegisterFilter()
    {
        AfxOleGetMessageFilter()->Revoke();
        this->Register();
    }

    BOOL OnMessagePending(const MSG* pMsg) override
    {
        return (m_DefaultHandler) ? COleMessageFilter::OnMessagePending(pMsg) : FALSE;
    }

    void SetDefaultHandler(BOOL defaultHandler)
    {
        m_DefaultHandler = defaultHandler;
    }
};
