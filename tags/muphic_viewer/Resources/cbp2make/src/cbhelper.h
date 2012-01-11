/*
    cbp2make : Makefile generation tool for the Code::Blocks IDE
    Copyright (C) 2010-2011 Mirai Computing (mirai.computing@gmail.com)

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

//------------------------------------------------------------------------------
#ifndef CBHELPER_H
#define CBHELPER_H
//------------------------------------------------------------------------------
#include "stlstrings.h"
//------------------------------------------------------------------------------

void ShowStringList(const CString& Title, const CString& LinePrefix,
                    const CStringList& StringList);
CString MakefileFriendly(const CString& AString);
CString XMLFriendly(const CString& AString);
CString FlatFileName(const CString& FileName);

#endif
//------------------------------------------------------------------------------
