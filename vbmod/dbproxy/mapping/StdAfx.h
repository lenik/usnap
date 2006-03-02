// stdafx.h : include file for standard system include files,
//      or project specific include files that are used frequently,
//      but are changed infrequently

#if !defined(AFX_STDAFX_H__5B31C49D_8019_4748_994A_B049145F8D4F__INCLUDED_)
#define AFX_STDAFX_H__5B31C49D_8019_4748_994A_B049145F8D4F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define STRICT
#ifndef _WIN32_WINNT
#define _WIN32_WINNT 0x0400
#endif
#define _ATL_APARTMENT_THREADED

#include <atlbase.h>
//You may derive a class from CComModule and use it if you want to override
//something, but do not change the name of _Module
extern CComModule _Module;
#include <atlcom.h>

#include <cpf/start/win32.h>
#undef EOF

#import "C:\Program Files\Common Files\System\ado\msado15.dll" raw_interfaces_only, raw_native_types, named_guids
using namespace ADODB;

/*
using ADODB::ADO_LONGPTR;

using ADODB::_Collection;
using ADODB::_DynaCollection;
using ADODB::_ADO;
using ADODB::Properties;
using ADODB::Property;
using ADODB::Error;
using ADODB::Errors;
using ADODB::Command15;
using ADODB::_Connection;
using ADODB::Connection15;
using ADODB::_Recordset;
using ADODB::Recordset21;
using ADODB::Recordset20;
using ADODB::Recordset15;
using ADODB::Fields;
using ADODB::Fields20;
using ADODB::Fields15;
using ADODB::Field;
using ADODB::Field20;
using ADODB::_Parameter;
using ADODB::Parameters;
using ADODB::Command25;
using ADODB::_Command;
using ADODB::ConnectionEventsVt;
using ADODB::RecordsetEventsVt;
using ADODB::ConnectionEvents;
using ADODB::RecordsetEvents;
using ADODB::ADOConnectionConstruction15;
using ADODB::ADOConnectionConstruction;
using ADODB::_Record;
using ADODB::_Stream;
using ADODB::ADORecordConstruction;
using ADODB::ADOStreamConstruction;
using ADODB::ADOCommandConstruction;
using ADODB::ADORecordsetConstruction;
using ADODB::Field15;

// Enums.
using ADODB::CursorTypeEnum;
using ADODB::CursorOptionEnum;
using ADODB::LockTypeEnum;
using ADODB::ExecuteOptionEnum;
using ADODB::ConnectOptionEnum;
using ADODB::ObjectStateEnum;
using ADODB::CursorLocationEnum;
using ADODB::DataTypeEnum;
using ADODB::FieldAttributeEnum;
using ADODB::EditModeEnum;
using ADODB::RecordStatusEnum;
using ADODB::GetRowsOptionEnum;
using ADODB::PositionEnum;
using ADODB::PositionEnum_Param;
using ADODB::BookmarkEnum;
using ADODB::MarshalOptionsEnum;
using ADODB::AffectEnum;
using ADODB::ResyncEnum;
using ADODB::CompareEnum;
using ADODB::FilterGroupEnum;
using ADODB::SearchDirectionEnum;
using ADODB::PersistFormatEnum;
using ADODB::StringFormatEnum;
using ADODB::ConnectPromptEnum;
using ADODB::ConnectModeEnum;
using ADODB::RecordCreateOptionsEnum;
using ADODB::RecordOpenOptionsEnum;
using ADODB::IsolationLevelEnum;
using ADODB::XactAttributeEnum;
using ADODB::PropertyAttributesEnum;
using ADODB::ErrorValueEnum;
using ADODB::ParameterAttributesEnum;
using ADODB::ParameterDirectionEnum;
using ADODB::CommandTypeEnum;
using ADODB::EventStatusEnum;
using ADODB::EventReasonEnum;
using ADODB::SchemaEnum;
using ADODB::FieldStatusEnum;
using ADODB::SeekEnum;
using ADODB::ADCPROP_UPDATECRITERIA_ENUM;
using ADODB::ADCPROP_ASYNCTHREADPRIORITY_ENUM;
using ADODB::ADCPROP_AUTORECALC_ENUM;
using ADODB::ADCPROP_UPDATERESYNC_ENUM;
using ADODB::MoveRecordOptionsEnum;
using ADODB::CopyRecordOptionsEnum;
using ADODB::StreamTypeEnum;
using ADODB::LineSeparatorEnum;
using ADODB::StreamOpenOptionsEnum;
using ADODB::StreamWriteEnum;
using ADODB::SaveOptionsEnum;
using ADODB::FieldEnum;
using ADODB::StreamReadEnum;
using ADODB::RecordTypeEnum;
*/

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STDAFX_H__5B31C49D_8019_4748_994A_B049145F8D4F__INCLUDED)
