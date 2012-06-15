/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 5.01.0164 */
/* at Thu Mar 02 15:06:15 2006
 */
/* Compiler settings for C:\.lokaj\zbmis\module\dbproxy\mapping\adoenum.idl:
    Os (OptLev=s), W1, Zp8, env=Win32, ms_ext, c_ext
    error checks: allocation ref bounds_check enum stub_data
*/
//@@MIDL_FILE_HEADING(  )


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 440
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __adoenum_h__
#define __adoenum_h__

#ifdef __cplusplus
extern "C"{
#endif

/* Forward Declarations */

void __RPC_FAR * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void __RPC_FAR * );

/* interface __MIDL_itf_adoenum_0000 */
/* [local] */

#if 0
typedef /* [public][uuid] */ long ADO_LONGPTR;

typedef /* [public][helpcontext][uuid] */
enum __MIDL___MIDL_itf_adoenum_0000_0001
    {	adOpenUnspecified	= -1,
	adOpenForwardOnly	= 0,
	adOpenKeyset	= 1,
	adOpenDynamic	= 2,
	adOpenStatic	= 3
    }	CursorTypeEnum;

typedef /* [public][helpcontext][uuid] */
enum __MIDL___MIDL_itf_adoenum_0000_0002
    {	adHoldRecords	= 256,
	adMovePrevious	= 512,
	adAddNew	= 16778240,
	adDelete	= 16779264,
	adUpdate	= 16809984,
	adBookmark	= 8192,
	adApproxPosition	= 16384,
	adUpdateBatch	= 65536,
	adResync	= 131072,
	adNotify	= 262144,
	adFind	= 524288,
	adSeek	= 4194304,
	adIndex	= 8388608
    }	CursorOptionEnum;

typedef /* [public][helpcontext][uuid] */
enum __MIDL___MIDL_itf_adoenum_0000_0003
    {	adLockUnspecified	= -1,
	adLockReadOnly	= 1,
	adLockPessimistic	= 2,
	adLockOptimistic	= 3,
	adLockBatchOptimistic	= 4
    }	LockTypeEnum;

typedef /* [public][helpcontext][uuid] */
enum __MIDL___MIDL_itf_adoenum_0000_0004
    {	adOptionUnspecified	= -1,
	adAsyncExecute	= 16,
	adAsyncFetch	= 32,
	adAsyncFetchNonBlocking	= 64,
	adExecuteNoRecords	= 128,
	adExecuteStream	= 1024,
	adExecuteRecord	= 2048
    }	ExecuteOptionEnum;

typedef /* [public][helpcontext][uuid] */
enum __MIDL___MIDL_itf_adoenum_0000_0005
    {	adConnectUnspecified	= -1,
	adAsyncConnect	= 16
    }	ConnectOptionEnum;

typedef /* [public][helpcontext][uuid] */
enum __MIDL___MIDL_itf_adoenum_0000_0006
    {	adStateClosed	= 0,
	adStateOpen	= 1,
	adStateConnecting	= 2,
	adStateExecuting	= 4,
	adStateFetching	= 8
    }	ObjectStateEnum;

typedef /* [public][helpcontext][uuid] */
enum __MIDL___MIDL_itf_adoenum_0000_0007
    {	adUseNone	= 1,
	adUseServer	= 2,
	adUseClient	= 3,
	adUseClientBatch	= 3
    }	CursorLocationEnum;

typedef /* [public][helpcontext][uuid] */
enum __MIDL___MIDL_itf_adoenum_0000_0008
    {	adEmpty	= 0,
	adTinyInt	= 16,
	adSmallInt	= 2,
	adInteger	= 3,
	adBigInt	= 20,
	adUnsignedTinyInt	= 17,
	adUnsignedSmallInt	= 18,
	adUnsignedInt	= 19,
	adUnsignedBigInt	= 21,
	adSingle	= 4,
	adDouble	= 5,
	adCurrency	= 6,
	adDecimal	= 14,
	adNumeric	= 131,
	adBoolean	= 11,
	adError	= 10,
	adUserDefined	= 132,
	adVariant	= 12,
	adIDispatch	= 9,
	adIUnknown	= 13,
	adGUID	= 72,
	adDate	= 7,
	adDBDate	= 133,
	adDBTime	= 134,
	adDBTimeStamp	= 135,
	adBSTR	= 8,
	adChar	= 129,
	adVarChar	= 200,
	adLongVarChar	= 201,
	adWChar	= 130,
	adVarWChar	= 202,
	adLongVarWChar	= 203,
	adBinary	= 128,
	adVarBinary	= 204,
	adLongVarBinary	= 205,
	adChapter	= 136,
	adFileTime	= 64,
	adPropVariant	= 138,
	adVarNumeric	= 139,
	adArray	= 8192
    }	DataTypeEnum;

typedef /* [public][helpcontext][uuid] */
enum __MIDL___MIDL_itf_adoenum_0000_0009
    {	adFldUnspecified	= -1,
	adFldMayDefer	= 2,
	adFldUpdatable	= 4,
	adFldUnknownUpdatable	= 8,
	adFldFixed	= 16,
	adFldIsNullable	= 32,
	adFldMayBeNull	= 64,
	adFldLong	= 128,
	adFldRowID	= 256,
	adFldRowVersion	= 512,
	adFldCacheDeferred	= 4096,
	adFldIsChapter	= 8192,
	adFldNegativeScale	= 16384,
	adFldKeyColumn	= 32768,
	adFldIsRowURL	= 65536,
	adFldIsDefaultStream	= 131072,
	adFldIsCollection	= 262144
    }	FieldAttributeEnum;

typedef /* [public][helpcontext][uuid] */
enum __MIDL___MIDL_itf_adoenum_0000_0010
    {	adEditNone	= 0,
	adEditInProgress	= 1,
	adEditAdd	= 2,
	adEditDelete	= 4
    }	EditModeEnum;

typedef /* [public][helpcontext][uuid] */
enum __MIDL___MIDL_itf_adoenum_0000_0011
    {	adRecOK	= 0,
	adRecNew	= 1,
	adRecModified	= 2,
	adRecDeleted	= 4,
	adRecUnmodified	= 8,
	adRecInvalid	= 16,
	adRecMultipleChanges	= 64,
	adRecPendingChanges	= 128,
	adRecCanceled	= 256,
	adRecCantRelease	= 1024,
	adRecConcurrencyViolation	= 2048,
	adRecIntegrityViolation	= 4096,
	adRecMaxChangesExceeded	= 8192,
	adRecObjectOpen	= 16384,
	adRecOutOfMemory	= 32768,
	adRecPermissionDenied	= 65536,
	adRecSchemaViolation	= 131072,
	adRecDBDeleted	= 262144
    }	RecordStatusEnum;

typedef /* [public][helpcontext][uuid] */
enum __MIDL___MIDL_itf_adoenum_0000_0012
    {	adGetRowsRest	= -1
    }	GetRowsOptionEnum;

typedef /* [public][public][helpcontext][uuid] */
enum __MIDL___MIDL_itf_adoenum_0000_0013
    {	adPosUnknown	= -1,
	adPosBOF	= -2,
	adPosEOF	= -3
    }	PositionEnum;

typedef /* [public][uuid] */ PositionEnum PositionEnum_Param;

typedef /* [public][helpcontext] */
enum __MIDL___MIDL_itf_adoenum_0000_0014
    {	adBookmarkCurrent	= 0,
	adBookmarkFirst	= 1,
	adBookmarkLast	= 2
    }	BookmarkEnum;

typedef /* [public][helpcontext][uuid] */
enum __MIDL___MIDL_itf_adoenum_0000_0015
    {	adMarshalAll	= 0,
	adMarshalModifiedOnly	= 1
    }	MarshalOptionsEnum;

typedef /* [public][helpcontext][uuid] */
enum __MIDL___MIDL_itf_adoenum_0000_0016
    {	adAffectCurrent	= 1,
	adAffectGroup	= 2,
	adAffectAll	= 3,
	adAffectAllChapters	= 4
    }	AffectEnum;

typedef /* [public][helpcontext][uuid] */
enum __MIDL___MIDL_itf_adoenum_0000_0017
    {	adResyncUnderlyingValues	= 1,
	adResyncAllValues	= 2
    }	ResyncEnum;

typedef /* [public][helpcontext][uuid] */
enum __MIDL___MIDL_itf_adoenum_0000_0018
    {	adCompareLessThan	= 0,
	adCompareEqual	= 1,
	adCompareGreaterThan	= 2,
	adCompareNotEqual	= 3,
	adCompareNotComparable	= 4
    }	CompareEnum;

typedef /* [public][helpcontext][uuid] */
enum __MIDL___MIDL_itf_adoenum_0000_0019
    {	adFilterNone	= 0,
	adFilterPendingRecords	= 1,
	adFilterAffectedRecords	= 2,
	adFilterFetchedRecords	= 3,
	adFilterPredicate	= 4,
	adFilterConflictingRecords	= 5
    }	FilterGroupEnum;

typedef /* [public][public][helpcontext][uuid] */
enum __MIDL___MIDL_itf_adoenum_0000_0020
    {	adSearchForward	= 1,
	adSearchBackward	= -1
    }	SearchDirectionEnum;

typedef /* [public] */ SearchDirectionEnum SearchDirection;

typedef /* [public][helpcontext][uuid] */
enum __MIDL___MIDL_itf_adoenum_0000_0021
    {	adPersistADTG	= 0,
	adPersistXML	= 1
    }	PersistFormatEnum;

typedef /* [public][helpcontext][uuid] */
enum __MIDL___MIDL_itf_adoenum_0000_0022
    {	adClipString	= 2
    }	StringFormatEnum;

typedef /* [public][helpcontext][uuid] */
enum __MIDL___MIDL_itf_adoenum_0000_0023
    {	adPromptAlways	= 1,
	adPromptComplete	= 2,
	adPromptCompleteRequired	= 3,
	adPromptNever	= 4
    }	ConnectPromptEnum;

typedef /* [public][helpcontext][uuid] */
enum __MIDL___MIDL_itf_adoenum_0000_0024
    {	adModeUnknown	= 0,
	adModeRead	= 1,
	adModeWrite	= 2,
	adModeReadWrite	= 3,
	adModeShareDenyRead	= 4,
	adModeShareDenyWrite	= 8,
	adModeShareExclusive	= 12,
	adModeShareDenyNone	= 16,
	adModeRecursive	= 4194304
    }	ConnectModeEnum;

typedef /* [public][helpcontext][uuid] */
enum __MIDL___MIDL_itf_adoenum_0000_0025
    {	adCreateCollection	= 8192,
	adCreateStructDoc	= 0x80000000,
	adCreateNonCollection	= 0,
	adOpenIfExists	= 33554432,
	adCreateOverwrite	= 67108864,
	adFailIfNotExists	= -1
    }	RecordCreateOptionsEnum;

typedef /* [public][helpcontext][uuid] */
enum __MIDL___MIDL_itf_adoenum_0000_0026
    {	adOpenRecordUnspecified	= -1,
	adOpenSource	= 8388608,
	adOpenOutput	= 8388608,
	adOpenAsync	= 4096,
	adDelayFetchStream	= 16384,
	adDelayFetchFields	= 32768,
	adOpenExecuteCommand	= 65536
    }	RecordOpenOptionsEnum;

typedef /* [public][helpcontext][uuid] */
enum __MIDL___MIDL_itf_adoenum_0000_0027
    {	adXactUnspecified	= -1,
	adXactChaos	= 16,
	adXactReadUncommitted	= 256,
	adXactBrowse	= 256,
	adXactCursorStability	= 4096,
	adXactReadCommitted	= 4096,
	adXactRepeatableRead	= 65536,
	adXactSerializable	= 1048576,
	adXactIsolated	= 1048576
    }	IsolationLevelEnum;

typedef /* [public][helpcontext][uuid] */
enum __MIDL___MIDL_itf_adoenum_0000_0028
    {	adXactCommitRetaining	= 131072,
	adXactAbortRetaining	= 262144,
	adXactAsyncPhaseOne	= 524288,
	adXactSyncPhaseOne	= 1048576
    }	XactAttributeEnum;

typedef /* [public][helpcontext][uuid] */
enum __MIDL___MIDL_itf_adoenum_0000_0029
    {	adPropNotSupported	= 0,
	adPropRequired	= 1,
	adPropOptional	= 2,
	adPropRead	= 512,
	adPropWrite	= 1024
    }	PropertyAttributesEnum;

typedef /* [public][helpcontext][uuid] */
enum __MIDL___MIDL_itf_adoenum_0000_0030
    {	adErrProviderFailed	= 3000,
	adErrInvalidArgument	= 3001,
	adErrOpeningFile	= 3002,
	adErrReadFile	= 3003,
	adErrWriteFile	= 3004,
	adErrNoCurrentRecord	= 3021,
	adErrIllegalOperation	= 3219,
	adErrCantChangeProvider	= 3220,
	adErrInTransaction	= 3246,
	adErrFeatureNotAvailable	= 3251,
	adErrItemNotFound	= 3265,
	adErrObjectInCollection	= 3367,
	adErrObjectNotSet	= 3420,
	adErrDataConversion	= 3421,
	adErrObjectClosed	= 3704,
	adErrObjectOpen	= 3705,
	adErrProviderNotFound	= 3706,
	adErrBoundToCommand	= 3707,
	adErrInvalidParamInfo	= 3708,
	adErrInvalidConnection	= 3709,
	adErrNotReentrant	= 3710,
	adErrStillExecuting	= 3711,
	adErrOperationCancelled	= 3712,
	adErrStillConnecting	= 3713,
	adErrInvalidTransaction	= 3714,
	adErrNotExecuting	= 3715,
	adErrUnsafeOperation	= 3716,
	adwrnSecurityDialog	= 3717,
	adwrnSecurityDialogHeader	= 3718,
	adErrIntegrityViolation	= 3719,
	adErrPermissionDenied	= 3720,
	adErrDataOverflow	= 3721,
	adErrSchemaViolation	= 3722,
	adErrSignMismatch	= 3723,
	adErrCantConvertvalue	= 3724,
	adErrCantCreate	= 3725,
	adErrColumnNotOnThisRow	= 3726,
	adErrURLDoesNotExist	= 3727,
	adErrTreePermissionDenied	= 3728,
	adErrInvalidURL	= 3729,
	adErrResourceLocked	= 3730,
	adErrResourceExists	= 3731,
	adErrCannotComplete	= 3732,
	adErrVolumeNotFound	= 3733,
	adErrOutOfSpace	= 3734,
	adErrResourceOutOfScope	= 3735,
	adErrUnavailable	= 3736,
	adErrURLNamedRowDoesNotExist	= 3737,
	adErrDelResOutOfScope	= 3738,
	adErrPropInvalidColumn	= 3739,
	adErrPropInvalidOption	= 3740,
	adErrPropInvalidValue	= 3741,
	adErrPropConflicting	= 3742,
	adErrPropNotAllSettable	= 3743,
	adErrPropNotSet	= 3744,
	adErrPropNotSettable	= 3745,
	adErrPropNotSupported	= 3746,
	adErrCatalogNotSet	= 3747,
	adErrCantChangeConnection	= 3748,
	adErrFieldsUpdateFailed	= 3749,
	adErrDenyNotSupported	= 3750,
	adErrDenyTypeNotSupported	= 3751,
	adErrProviderNotSpecified	= 3753,
	adErrConnectionStringTooLong	= 3754
    }	ErrorValueEnum;

typedef /* [public][helpcontext][uuid] */
enum __MIDL___MIDL_itf_adoenum_0000_0031
    {	adParamSigned	= 16,
	adParamNullable	= 64,
	adParamLong	= 128
    }	ParameterAttributesEnum;

typedef /* [public][helpcontext][uuid] */
enum __MIDL___MIDL_itf_adoenum_0000_0032
    {	adParamUnknown	= 0,
	adParamInput	= 1,
	adParamOutput	= 2,
	adParamInputOutput	= 3,
	adParamReturnValue	= 4
    }	ParameterDirectionEnum;

typedef /* [public][helpcontext][uuid] */
enum __MIDL___MIDL_itf_adoenum_0000_0033
    {	adCmdUnspecified	= -1,
	adCmdUnknown	= 8,
	adCmdText	= 1,
	adCmdTable	= 2,
	adCmdStoredProc	= 4,
	adCmdFile	= 256,
	adCmdTableDirect	= 512
    }	CommandTypeEnum;

typedef /* [public][helpcontext][uuid] */
enum __MIDL___MIDL_itf_adoenum_0000_0034
    {	adStatusOK	= 1,
	adStatusErrorsOccurred	= 2,
	adStatusCantDeny	= 3,
	adStatusCancel	= 4,
	adStatusUnwantedEvent	= 5
    }	EventStatusEnum;

typedef /* [public][helpcontext][uuid] */
enum __MIDL___MIDL_itf_adoenum_0000_0035
    {	adRsnAddNew	= 1,
	adRsnDelete	= 2,
	adRsnUpdate	= 3,
	adRsnUndoUpdate	= 4,
	adRsnUndoAddNew	= 5,
	adRsnUndoDelete	= 6,
	adRsnRequery	= 7,
	adRsnResynch	= 8,
	adRsnClose	= 9,
	adRsnMove	= 10,
	adRsnFirstChange	= 11,
	adRsnMoveFirst	= 12,
	adRsnMoveNext	= 13,
	adRsnMovePrevious	= 14,
	adRsnMoveLast	= 15
    }	EventReasonEnum;

typedef /* [public][helpcontext][uuid] */
enum __MIDL___MIDL_itf_adoenum_0000_0036
    {	adSchemaProviderSpecific	= -1,
	adSchemaAsserts	= 0,
	adSchemaCatalogs	= 1,
	adSchemaCharacterSets	= 2,
	adSchemaCollations	= 3,
	adSchemaColumns	= 4,
	adSchemaCheckConstraints	= 5,
	adSchemaConstraintColumnUsage	= 6,
	adSchemaConstraintTableUsage	= 7,
	adSchemaKeyColumnUsage	= 8,
	adSchemaReferentialContraints	= 9,
	adSchemaReferentialConstraints	= 9,
	adSchemaTableConstraints	= 10,
	adSchemaColumnsDomainUsage	= 11,
	adSchemaIndexes	= 12,
	adSchemaColumnPrivileges	= 13,
	adSchemaTablePrivileges	= 14,
	adSchemaUsagePrivileges	= 15,
	adSchemaProcedures	= 16,
	adSchemaSchemata	= 17,
	adSchemaSQLLanguages	= 18,
	adSchemaStatistics	= 19,
	adSchemaTables	= 20,
	adSchemaTranslations	= 21,
	adSchemaProviderTypes	= 22,
	adSchemaViews	= 23,
	adSchemaViewColumnUsage	= 24,
	adSchemaViewTableUsage	= 25,
	adSchemaProcedureParameters	= 26,
	adSchemaForeignKeys	= 27,
	adSchemaPrimaryKeys	= 28,
	adSchemaProcedureColumns	= 29,
	adSchemaDBInfoKeywords	= 30,
	adSchemaDBInfoLiterals	= 31,
	adSchemaCubes	= 32,
	adSchemaDimensions	= 33,
	adSchemaHierarchies	= 34,
	adSchemaLevels	= 35,
	adSchemaMeasures	= 36,
	adSchemaProperties	= 37,
	adSchemaMembers	= 38,
	adSchemaTrustees	= 39,
	adSchemaFunctions	= 40,
	adSchemaActions	= 41,
	adSchemaCommands	= 42,
	adSchemaSets	= 43
    }	SchemaEnum;

typedef /* [public][helpcontext][uuid] */
enum __MIDL___MIDL_itf_adoenum_0000_0037
    {	adFieldOK	= 0,
	adFieldCantConvertValue	= 2,
	adFieldIsNull	= 3,
	adFieldTruncated	= 4,
	adFieldSignMismatch	= 5,
	adFieldDataOverflow	= 6,
	adFieldCantCreate	= 7,
	adFieldUnavailable	= 8,
	adFieldPermissionDenied	= 9,
	adFieldIntegrityViolation	= 10,
	adFieldSchemaViolation	= 11,
	adFieldBadStatus	= 12,
	adFieldDefault	= 13,
	adFieldIgnore	= 15,
	adFieldDoesNotExist	= 16,
	adFieldInvalidURL	= 17,
	adFieldResourceLocked	= 18,
	adFieldResourceExists	= 19,
	adFieldCannotComplete	= 20,
	adFieldVolumeNotFound	= 21,
	adFieldOutOfSpace	= 22,
	adFieldCannotDeleteSource	= 23,
	adFieldReadOnly	= 24,
	adFieldResourceOutOfScope	= 25,
	adFieldAlreadyExists	= 26,
	adFieldPendingInsert	= 65536,
	adFieldPendingDelete	= 131072,
	adFieldPendingChange	= 262144,
	adFieldPendingUnknown	= 524288,
	adFieldPendingUnknownDelete	= 1048576
    }	FieldStatusEnum;

typedef /* [public][helpcontext][uuid] */
enum __MIDL___MIDL_itf_adoenum_0000_0038
    {	adSeekFirstEQ	= 1,
	adSeekLastEQ	= 2,
	adSeekAfterEQ	= 4,
	adSeekAfter	= 8,
	adSeekBeforeEQ	= 16,
	adSeekBefore	= 32
    }	SeekEnum;

typedef /* [public][helpcontext][uuid] */
enum __MIDL___MIDL_itf_adoenum_0000_0039
    {	adCriteriaKey	= 0,
	adCriteriaAllCols	= 1,
	adCriteriaUpdCols	= 2,
	adCriteriaTimeStamp	= 3
    }	ADCPROP_UPDATECRITERIA_ENUM;

typedef /* [public][helpcontext][uuid] */
enum __MIDL___MIDL_itf_adoenum_0000_0040
    {	adPriorityLowest	= 1,
	adPriorityBelowNormal	= 2,
	adPriorityNormal	= 3,
	adPriorityAboveNormal	= 4,
	adPriorityHighest	= 5
    }	ADCPROP_ASYNCTHREADPRIORITY_ENUM;

typedef /* [public][helpcontext][uuid] */
enum __MIDL___MIDL_itf_adoenum_0000_0041
    {	adRecalcUpFront	= 0,
	adRecalcAlways	= 1
    }	ADCPROP_AUTORECALC_ENUM;

typedef /* [public][helpcontext][uuid] */
enum __MIDL___MIDL_itf_adoenum_0000_0042
    {	adResyncNone	= 0,
	adResyncAutoIncrement	= 1,
	adResyncConflicts	= 2,
	adResyncUpdates	= 4,
	adResyncInserts	= 8,
	adResyncAll	= 15
    }	ADCPROP_UPDATERESYNC_ENUM;

typedef /* [public][helpcontext][uuid] */
enum __MIDL___MIDL_itf_adoenum_0000_0043
    {	adMoveUnspecified	= -1,
	adMoveOverWrite	= 1,
	adMoveDontUpdateLinks	= 2,
	adMoveAllowEmulation	= 4
    }	MoveRecordOptionsEnum;

typedef /* [public][helpcontext][uuid] */
enum __MIDL___MIDL_itf_adoenum_0000_0044
    {	adCopyUnspecified	= -1,
	adCopyOverWrite	= 1,
	adCopyAllowEmulation	= 4,
	adCopyNonRecursive	= 2
    }	CopyRecordOptionsEnum;

typedef /* [public][helpcontext][uuid] */
enum __MIDL___MIDL_itf_adoenum_0000_0045
    {	adTypeBinary	= 1,
	adTypeText	= 2
    }	StreamTypeEnum;

typedef /* [public][helpcontext][uuid] */
enum __MIDL___MIDL_itf_adoenum_0000_0046
    {	adLF	= 10,
	adCR	= 13,
	adCRLF	= -1
    }	LineSeparatorEnum;

typedef /* [public][helpcontext][uuid] */
enum __MIDL___MIDL_itf_adoenum_0000_0047
    {	adOpenStreamUnspecified	= -1,
	adOpenStreamAsync	= 1,
	adOpenStreamFromRecord	= 4
    }	StreamOpenOptionsEnum;

typedef /* [public][helpcontext][uuid] */
enum __MIDL___MIDL_itf_adoenum_0000_0048
    {	adWriteChar	= 0,
	adWriteLine	= 1,
	stWriteChar	= 0,
	stWriteLine	= 1
    }	StreamWriteEnum;

typedef /* [public][helpcontext][uuid] */
enum __MIDL___MIDL_itf_adoenum_0000_0049
    {	adSaveCreateNotExist	= 1,
	adSaveCreateOverWrite	= 2
    }	SaveOptionsEnum;

typedef /* [public][helpcontext] */
enum __MIDL___MIDL_itf_adoenum_0000_0050
    {	adDefaultStream	= -1,
	adRecordURL	= -2
    }	FieldEnum;

typedef /* [public][helpcontext] */
enum __MIDL___MIDL_itf_adoenum_0000_0051
    {	adReadAll	= -1,
	adReadLine	= -2
    }	StreamReadEnum;

typedef /* [public][helpcontext][uuid] */
enum __MIDL___MIDL_itf_adoenum_0000_0052
    {	adSimpleRecord	= 0,
	adCollectionRecord	= 1,
	adStructDoc	= 2
    }	RecordTypeEnum;

#endif


extern RPC_IF_HANDLE __MIDL_itf_adoenum_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_adoenum_0000_v0_0_s_ifspec;

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif
