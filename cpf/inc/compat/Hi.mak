
#
# MAKETYPE can be follows:
#	- NTDDK
#	- 2000DDK
#	- 98DDK
#	- 95DDK
#	- WDM

!IF "$(MAKETYPE)" == "NTDDK"
MT_MAJOR	= DDK
MT_MINOR	= NT

!ELSEIF "$(MAKETYPE)" == "2000DDK"
MT_MAJOR	= DDK
MT_MINOR	= 2000

!ELSEIF "$(MAKETYPE)" == "98DDK"
MT_MAJOR	= DDK
MT_MINOR	= 98

!ELSEIF "$(MAKETYPE)" == "95DDK"
MT_MAJOR	= DDK
MT_MINOR	= 95

!ELSEIF "$(MAKETYPE)" == "WDM"
MT_MAJOR	= DDK
MT_MINOR	= NT

!ELSEIF "$(MAKETYPE)" == ""
	# use MT_MAJOR/MT_MINOR settings.

!ELSE
!	ERROR Himak: Unknown MAKETYPE command ($(MAKETYPE)).
!ENDIF


#

!IF "$(MT_MAJOR)" == "DDK"
!	IF "$(MT_MINOR)" == "NT" || "$(MT_MINOR)" == "2000"
!		MESSAGE Himak: NTDDK mode settings...
!		INCLUDE <Hi.ntddk.mak>
!	ELSEIF "$(MT_MINOR)" == "98"
!		ERROR Himak: 98DDK isn't support, yet.
!	ELSEIF "$(MT_MINOR)" == "95"
!		ERROR Himak: 95DDK isn't support, yet.
!	ELSE
!		ERROR Himak: Unknown MT_MINOR command ($(MAKETYPE)) in DDK major type.
!	ENDIF
!ELSE
!	ERROR Himak: Unknown MT_MAJOR command.
!ENDIF
