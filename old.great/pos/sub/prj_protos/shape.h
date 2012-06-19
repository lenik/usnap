/*
                                                                  * CVI DRAFT *
    POS - Practice-Oriented Structure (System)                        Version 1
    ---------------------------------------------------------------------------
                                Power Of the Software !

    License:    POS.LCL
    See Also:   X@A LaS PoX EPFS HFVC 1/bios HAS/HAD Aipos

    Ci Virtuality Integrated,
    Copyright 1997-2003, CHINA. All rights reserved.

    File:
        Module Name:    _________________________
        Description:    ___________________________________________________
                        ___________________________________________________
        Version:        0.0.1
        Author:         (ZD) ZAUJ G.DANSEI
    History:
        2003-MM-DD      ZD|started
        2003-MM-DD
    ---------------------------------------------------------------------------
                                                                  * CVI DRAFT *
*/



#ifndef __MODULE_INCLUDED__
#define __MODULE_INCLUDED__
#ifdef POS_CF_ONCE
#   pragma once
#endif

#include "config.h"



///////////////////////////////////////////////////////////////////////////////
//
// Forward Declaration, Macros and Constants
// ----------------------------------------------------------------------------
POS_BEGIN

POS_END



// Header files to use
#include "variant.h"
#include "error.h"

///////////////////////////////////////////////////////////////////////////////
//
// Prototypes
// ----------------------------------------------------------------------------
#include "config/alignment_begin.h"
POS_BEGIN




















POS_END
#include "config/alignment_end.h"



///////////////////////////////////////////////////////////////////////////////
//
// Inline implementations & Utility functions
// ----------------------------------------------------------------------------
POS_BEGIN

POS_END

#endif



///////////////////////////////////////////////////////////////////////////////
//
// The Developing Procedure
// ----------------------------------------------------------------------------
/*
        Summary:
                _____________________________________________
                _____________________________________________
        Motivation:
                ___________________________________________________________
        Objective:
                ___________________________________________
                ___________________________________________
                ___________________________________________
        Sandbox, Problems, Warnings:
                - How constraints affect each other?
                _______________________________________
                _______________________________________
                _______________________________________
        Development:
                * �ռ���ʽ���̳�geometry_t�ṹ?
                    - ����ϵ�����ռ䣻
                        . bOverflow     ������ռ�
                    - ��״���Ծ���Ϊ��
                        . ��������: ��״�Ķ���ͱ߻���ԣ�����ȼ�
                    - �ռ���Ϊ���������ı��ʴ洢����û���
                        . pContent
                        . pUser
                    - ����������һ���ռ����һ���ռ�ʩ��Ӱ��
                        . �ռ������������
                            (�Ժ������������ؼ�������������ӣ�������ͱ����ñ�������)
                        . �������������ԣ�
                            ��������ԣ������ռ��Զ���ϡ�����ճ����һ��
                            ռ���ԣ�һ���������ӸߵĿռ佫�������ǵĿռ�ʩ����״Ӱ�죬
                                (����Ϊ���豻���ռ�һ���޸��˵ĸ��ռ䣬�޸�һ����������)
                    -
                ___________________________________________________________
                ___________________________________________________________
        References:
                _________________________________________________
        Achievement:
                ________________________________________
        Outgrowth & Babies, Abbreviations:
                _____________________________
                _____________________________
                _____________________________
        Acknowledgement:
                _____________________________________________
*/