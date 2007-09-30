Attribute VB_Name = "modErrors"
' -----------------------------------------
' Win32 API error code definitions
' -----------------------------------------
' This section contains the error code definitions for the Win32 API functions.

' NO_ERROR
Public Const NO_ERROR = 0 '  dderror

' The configuration registry database operation completed successfully.
Public Const ERROR_SUCCESS = 0&

'   Incorrect function.
Public Const ERROR_INVALID_FUNCTION = 1 '  dderror

'   The system cannot find the file specified.
Public Const ERROR_FILE_NOT_FOUND = 2&

'   The system cannot find the path specified.
Public Const ERROR_PATH_NOT_FOUND = 3&

'   The system cannot open the file.
Public Const ERROR_TOO_MANY_OPEN_FILES = 4&

'   Access is denied.
Public Const ERROR_ACCESS_DENIED = 5&

'   The handle is invalid.
Public Const ERROR_INVALID_HANDLE = 6&

'   The storage control blocks were destroyed.
Public Const ERROR_ARENA_TRASHED = 7&

'   Not enough storage is available to process this command.
Public Const ERROR_NOT_ENOUGH_MEMORY = 8 '  dderror

'   The storage control block address is invalid.
Public Const ERROR_INVALID_BLOCK = 9&

'   The environment is incorrect.
Public Const ERROR_BAD_ENVIRONMENT = 10&

'   An attempt was made to load a program with an
'   incorrect format.
Public Const ERROR_BAD_FORMAT = 11&

'   The access code is invalid.
Public Const ERROR_INVALID_ACCESS = 12&

'   The data is invalid.
Public Const ERROR_INVALID_DATA = 13&

'   Not enough storage is available to complete this operation.
Public Const ERROR_OUTOFMEMORY = 14&

'   The system cannot find the drive specified.
Public Const ERROR_INVALID_DRIVE = 15&

'   The directory cannot be removed.
Public Const ERROR_CURRENT_DIRECTORY = 16&

'   The system cannot move the file
'   to a different disk drive.
Public Const ERROR_NOT_SAME_DEVICE = 17&

'   There are no more files.
Public Const ERROR_NO_MORE_FILES = 18&

'   The media is write protected.
Public Const ERROR_WRITE_PROTECT = 19&

'   The system cannot find the device specified.
Public Const ERROR_BAD_UNIT = 20&

'   The device is not ready.
Public Const ERROR_NOT_READY = 21&

'   The device does not recognize the command.
Public Const ERROR_BAD_COMMAND = 22&

'   Data error (cyclic redundancy check)
Public Const ERROR_CRC = 23&

'   The program issued a command but the
'   command length is incorrect.
Public Const ERROR_BAD_LENGTH = 24&

'   The drive cannot locate a specific
'   area or track on the disk.
Public Const ERROR_SEEK = 25&

'   The specified disk or diskette cannot be accessed.
Public Const ERROR_NOT_DOS_DISK = 26&

'   The drive cannot find the sector requested.
Public Const ERROR_SECTOR_NOT_FOUND = 27&

'   The printer is out of paper.
Public Const ERROR_OUT_OF_PAPER = 28&

'   The system cannot write to the specified device.
Public Const ERROR_WRITE_FAULT = 29&

'   The system cannot read from the specified device.
Public Const ERROR_READ_FAULT = 30&

'   A device attached to the system is not functioning.
Public Const ERROR_GEN_FAILURE = 31&

'   The process cannot access the file because
'   it is being used by another process.
Public Const ERROR_SHARING_VIOLATION = 32&

'   The process cannot access the file because
'   another process has locked a portion of the file.
Public Const ERROR_LOCK_VIOLATION = 33&

'   The wrong diskette is in the drive.
'   Insert %2 (Volume Serial Number: %3)
'   into drive %1.
Public Const ERROR_WRONG_DISK = 34&

'   Too many files opened for sharing.
Public Const ERROR_SHARING_BUFFER_EXCEEDED = 36&

'   Reached end of file.
Public Const ERROR_HANDLE_EOF = 38&

'   The disk is full.
Public Const ERROR_HANDLE_DISK_FULL = 39&

'   The network request is not supported.
Public Const ERROR_NOT_SUPPORTED = 50&

'   The remote computer is not available.
Public Const ERROR_REM_NOT_LIST = 51&

'   A duplicate name exists on the network.
Public Const ERROR_DUP_NAME = 52&

'   The network path was not found.
Public Const ERROR_BAD_NETPATH = 53&

'   The network is busy.
Public Const ERROR_NETWORK_BUSY = 54&

'   The specified network resource or device is no longer
'   available.
Public Const ERROR_DEV_NOT_EXIST = 55 '  dderror

'   The network BIOS command limit has been reached.
Public Const ERROR_TOO_MANY_CMDS = 56&

'   A network adapter hardware error occurred.
Public Const ERROR_ADAP_HDW_ERR = 57&

'   The specified server cannot perform the requested
'   operation.
Public Const ERROR_BAD_NET_RESP = 58&

'   An unexpected network error occurred.
Public Const ERROR_UNEXP_NET_ERR = 59&

'   The remote adapter is not compatible.
Public Const ERROR_BAD_REM_ADAP = 60&

'   The printer queue is full.
Public Const ERROR_PRINTQ_FULL = 61&

'   Space to store the file waiting to be printed is
'   not available on the server.
Public Const ERROR_NO_SPOOL_SPACE = 62&

'   Your file waiting to be printed was deleted.
Public Const ERROR_PRINT_CANCELLED = 63&

'   The specified network name is no longer available.
Public Const ERROR_NETNAME_DELETED = 64&

'   Network access is denied.
Public Const ERROR_NETWORK_ACCESS_DENIED = 65&

'   The network resource type is not correct.
Public Const ERROR_BAD_DEV_TYPE = 66&

'   The network name cannot be found.
Public Const ERROR_BAD_NET_NAME = 67&

'   The name limit for the local computer network
'   adapter card was exceeded.
Public Const ERROR_TOO_MANY_NAMES = 68&

'   The network BIOS session limit was exceeded.
Public Const ERROR_TOO_MANY_SESS = 69&

'   The remote server has been paused or is in the
'   process of being started.
Public Const ERROR_SHARING_PAUSED = 70&

'   The network request was not accepted.
Public Const ERROR_REQ_NOT_ACCEP = 71&

'   The specified printer or disk device has been paused.
Public Const ERROR_REDIR_PAUSED = 72&

'   The file exists.
Public Const ERROR_FILE_EXISTS = 80&

'   The directory or file cannot be created.
Public Const ERROR_CANNOT_MAKE = 82&

'   Fail on INT 24
Public Const ERROR_FAIL_I24 = 83&

'   Storage to process this request is not available.
Public Const ERROR_OUT_OF_STRUCTURES = 84&

'   The local device name is already in use.
Public Const ERROR_ALREADY_ASSIGNED = 85&

'   The specified network password is not correct.
Public Const ERROR_INVALID_PASSWORD = 86&

'   The parameter is incorrect.
Public Const ERROR_INVALID_PARAMETER = 87 '  dderror

'   A write fault occurred on the network.
Public Const ERROR_NET_WRITE_FAULT = 88&

'   The system cannot start another process at
'   this time.
Public Const ERROR_NO_PROC_SLOTS = 89&

'   Cannot create another system semaphore.
Public Const ERROR_TOO_MANY_SEMAPHORES = 100&

'   The exclusive semaphore is owned by another process.
Public Const ERROR_EXCL_SEM_ALREADY_OWNED = 101&

'   The semaphore is set and cannot be closed.
Public Const ERROR_SEM_IS_SET = 102&

'   The semaphore cannot be set again.
Public Const ERROR_TOO_MANY_SEM_REQUESTS = 103&

'   Cannot request exclusive semaphores at interrupt time.
Public Const ERROR_INVALID_AT_INTERRUPT_TIME = 104&

'   The previous ownership of this semaphore has ended.
Public Const ERROR_SEM_OWNER_DIED = 105&

'   Insert the diskette for drive %1.
Public Const ERROR_SEM_USER_LIMIT = 106&

'   Program stopped because alternate diskette was not inserted.
Public Const ERROR_DISK_CHANGE = 107&

'   The disk is in use or locked by
'   another process.
Public Const ERROR_DRIVE_LOCKED = 108&

'   The pipe has been ended.
Public Const ERROR_BROKEN_PIPE = 109&

'   The system cannot open the
'   device or file specified.
Public Const ERROR_OPEN_FAILED = 110&

'   The file name is too long.
Public Const ERROR_BUFFER_OVERFLOW = 111&

'   There is not enough space on the disk.
Public Const ERROR_DISK_FULL = 112&

'   No more internal file identifiers available.
Public Const ERROR_NO_MORE_SEARCH_HANDLES = 113&

'   The target internal file identifier is incorrect.
Public Const ERROR_INVALID_TARGET_HANDLE = 114&

'   The IOCTL call made by the application program is
'   not correct.
Public Const ERROR_INVALID_CATEGORY = 117&

'   The verify-on-write switch parameter value is not
'   correct.
Public Const ERROR_INVALID_VERIFY_SWITCH = 118&

'   The system does not support the command requested.
Public Const ERROR_BAD_DRIVER_LEVEL = 119&

'   This function is only valid in Windows NT mode.
Public Const ERROR_CALL_NOT_IMPLEMENTED = 120&

'   The semaphore timeout period has expired.
Public Const ERROR_SEM_TIMEOUT = 121&

'   The data area passed to a system call is too
'   small.
Public Const ERROR_INSUFFICIENT_BUFFER = 122 '  dderror

'   The filename, directory name, or volume label syntax is incorrect.
Public Const ERROR_INVALID_NAME = 123&

'   The system call level is not correct.
Public Const ERROR_INVALID_LEVEL = 124&

'   The disk has no volume label.
Public Const ERROR_NO_VOLUME_LABEL = 125&

'   The specified module could not be found.
Public Const ERROR_MOD_NOT_FOUND = 126&

'   The specified procedure could not be found.
Public Const ERROR_PROC_NOT_FOUND = 127&

'   There are no child processes to wait for.
Public Const ERROR_WAIT_NO_CHILDREN = 128&

'   The %1 application cannot be run in Windows NT mode.
Public Const ERROR_CHILD_NOT_COMPLETE = 129&

'   Attempt to use a file handle to an open disk partition for an
'   operation other than raw disk I/O.
Public Const ERROR_DIRECT_ACCESS_HANDLE = 130&

'   An attempt was made to move the file pointer before the beginning of the file.
Public Const ERROR_NEGATIVE_SEEK = 131&

'   The file pointer cannot be set on the specified device or file.
Public Const ERROR_SEEK_ON_DEVICE = 132&

'   A JOIN or SUBST command
'   cannot be used for a drive that
'   contains previously joined drives.
Public Const ERROR_IS_JOIN_TARGET = 133&

'   An attempt was made to use a
'   JOIN or SUBST command on a drive that has
'   already been joined.
Public Const ERROR_IS_JOINED = 134&

'   An attempt was made to use a
'   JOIN or SUBST command on a drive that has
'   already been substituted.
Public Const ERROR_IS_SUBSTED = 135&

'   The system tried to delete
'   the JOIN of a drive that is not joined.
Public Const ERROR_NOT_JOINED = 136&

'   The system tried to delete the
'   substitution of a drive that is not substituted.
Public Const ERROR_NOT_SUBSTED = 137&

'   The system tried to join a drive
'   to a directory on a joined drive.
Public Const ERROR_JOIN_TO_JOIN = 138&

'   The system tried to substitute a
'   drive to a directory on a substituted drive.
Public Const ERROR_SUBST_TO_SUBST = 139&

'   The system tried to join a drive to
'   a directory on a substituted drive.
Public Const ERROR_JOIN_TO_SUBST = 140&

'   The system tried to SUBST a drive
'   to a directory on a joined drive.
Public Const ERROR_SUBST_TO_JOIN = 141&

'   The system cannot perform a JOIN or SUBST at this time.
Public Const ERROR_BUSY_DRIVE = 142&

'   The system cannot join or substitute a
'   drive to or for a directory on the same drive.
Public Const ERROR_SAME_DRIVE = 143&

'   The directory is not a subdirectory of the root directory.
Public Const ERROR_DIR_NOT_ROOT = 144&

'   The directory is not empty.
Public Const ERROR_DIR_NOT_EMPTY = 145&

'   The path specified is being used in
'   a substitute.
Public Const ERROR_IS_SUBST_PATH = 146&

'   Not enough resources are available to
'   process this command.
Public Const ERROR_IS_JOIN_PATH = 147&

'   The path specified cannot be used at this time.
Public Const ERROR_PATH_BUSY = 148&

'   An attempt was made to join
'   or substitute a drive for which a directory
'   on the drive is the target of a previous
'   substitute.
Public Const ERROR_IS_SUBST_TARGET = 149&

'   System trace information was not specified in your
'   CONFIG.SYS file, or tracing is disallowed.
Public Const ERROR_SYSTEM_TRACE = 150&

'   The number of specified semaphore events for
'   DosMuxSemWait is not correct.
Public Const ERROR_INVALID_EVENT_COUNT = 151&

'   DosMuxSemWait did not execute; too many semaphores
'   are already set.
Public Const ERROR_TOO_MANY_MUXWAITERS = 152&

'   The DosMuxSemWait list is not correct.
Public Const ERROR_INVALID_LIST_FORMAT = 153&

'   The volume label you entered exceeds the
'   11 character limit.  The first 11 characters were written
'   to disk.  Any characters that exceeded the 11 character limit
'   were automatically deleted.
Public Const ERROR_LABEL_TOO_LONG = 154&

'   Cannot create another thread.
Public Const ERROR_TOO_MANY_TCBS = 155&

'   The recipient process has refused the signal.
Public Const ERROR_SIGNAL_REFUSED = 156&

'   The segment is already discarded and cannot be locked.
Public Const ERROR_DISCARDED = 157&

'   The segment is already unlocked.
Public Const ERROR_NOT_LOCKED = 158&

'   The address for the thread ID is not correct.
Public Const ERROR_BAD_THREADID_ADDR = 159&

'   The argument string passed to DosExecPgm is not correct.
Public Const ERROR_BAD_ARGUMENTS = 160&

'   The specified path is invalid.
Public Const ERROR_BAD_PATHNAME = 161&

'   A signal is already pending.
Public Const ERROR_SIGNAL_PENDING = 162&

'   No more threads can be created in the system.
Public Const ERROR_MAX_THRDS_REACHED = 164&

'   Unable to lock a region of a file.
Public Const ERROR_LOCK_FAILED = 167&

'   The requested resource is in use.
Public Const ERROR_BUSY = 170&

'   A lock request was not outstanding for the supplied cancel region.
Public Const ERROR_CANCEL_VIOLATION = 173&

'   The file system does not support atomic changes to the lock type.
Public Const ERROR_ATOMIC_LOCKS_NOT_SUPPORTED = 174&

'   The system detected a segment number that was not correct.
Public Const ERROR_INVALID_SEGMENT_NUMBER = 180&

'   The operating system cannot run %1.
Public Const ERROR_INVALID_ORDINAL = 182&

'   Cannot create a file when that file already exists.
Public Const ERROR_ALREADY_EXISTS = 183&

'   The flag passed is not correct.
Public Const ERROR_INVALID_FLAG_NUMBER = 186&

'   The specified system semaphore name was not found.
Public Const ERROR_SEM_NOT_FOUND = 187&

'   The operating system cannot run %1.
Public Const ERROR_INVALID_STARTING_CODESEG = 188&

'   The operating system cannot run %1.
Public Const ERROR_INVALID_STACKSEG = 189&

'   The operating system cannot run %1.
Public Const ERROR_INVALID_MODULETYPE = 190&

'   Cannot run %1 in Windows NT mode.
Public Const ERROR_INVALID_EXE_SIGNATURE = 191&

'   The operating system cannot run %1.
Public Const ERROR_EXE_MARKED_INVALID = 192&

'   %1 is not a valid Windows NT application.
Public Const ERROR_BAD_EXE_FORMAT = 193&

'   The operating system cannot run %1.
Public Const ERROR_ITERATED_DATA_EXCEEDS_64k = 194&

'   The operating system cannot run %1.
Public Const ERROR_INVALID_MINALLOCSIZE = 195&

'   The operating system cannot run this
'   application program.
Public Const ERROR_DYNLINK_FROM_INVALID_RING = 196&

'   The operating system is not presently
'   configured to run this application.
Public Const ERROR_IOPL_NOT_ENABLED = 197&

'   The operating system cannot run %1.
Public Const ERROR_INVALID_SEGDPL = 198&

'   The operating system cannot run this
'   application program.
Public Const ERROR_AUTODATASEG_EXCEEDS_64k = 199&

'   The code segment cannot be greater than or equal to 64KB.
Public Const ERROR_RING2SEG_MUST_BE_MOVABLE = 200&

'   The operating system cannot run %1.
Public Const ERROR_RELOC_CHAIN_XEEDS_SEGLIM = 201&

'   The operating system cannot run %1.
Public Const ERROR_INFLOOP_IN_RELOC_CHAIN = 202&

'   The system could not find the environment
'   option that was entered.
Public Const ERROR_ENVVAR_NOT_FOUND = 203&

'   No process in the command subtree has a
'   signal handler.
Public Const ERROR_NO_SIGNAL_SENT = 205&

'   The filename or extension is too long.
Public Const ERROR_FILENAME_EXCED_RANGE = 206&

'   The ring 2 stack is in use.
Public Const ERROR_RING2_STACK_IN_USE = 207&

'   The Global filename characters,  or ?, are entered
'   incorrectly or too many Global filename characters are specified.
Public Const ERROR_META_EXPANSION_TOO_LONG = 208&

'   The signal being posted is not correct.
Public Const ERROR_INVALID_SIGNAL_NUMBER = 209&

'   The signal handler cannot be set.
Public Const ERROR_THREAD_1_INACTIVE = 210&

'   The segment is locked and cannot be reallocated.
Public Const ERROR_LOCKED = 212&

'   Too many dynamic link modules are attached to this
'   program or dynamic link module.
Public Const ERROR_TOO_MANY_MODULES = 214&

'   Can't nest calls to LoadModule.
Public Const ERROR_NESTING_NOT_ALLOWED = 215&

'   The pipe state is invalid.
Public Const ERROR_BAD_PIPE = 230&

'   All pipe instances are busy.
Public Const ERROR_PIPE_BUSY = 231&

'   The pipe is being closed.
Public Const ERROR_NO_DATA = 232&

'   No process is on the other end of the pipe.
Public Const ERROR_PIPE_NOT_CONNECTED = 233&

'   More data is available.
Public Const ERROR_MORE_DATA = 234 '  dderror

'   The session was cancelled.
Public Const ERROR_VC_DISCONNECTED = 240&

'   The specified extended attribute name was invalid.
Public Const ERROR_INVALID_EA_NAME = 254&

'   The extended attributes are inconsistent.
Public Const ERROR_EA_LIST_INCONSISTENT = 255&

'   No more data is available.
Public Const ERROR_NO_MORE_ITEMS = 259&

'   The Copy API cannot be used.
Public Const ERROR_CANNOT_COPY = 266&

'   The directory name is invalid.
Public Const ERROR_DIRECTORY = 267&

'   The extended attributes did not fit in the buffer.
Public Const ERROR_EAS_DIDNT_FIT = 275&

'   The extended attribute file on the mounted file system is corrupt.
Public Const ERROR_EA_FILE_CORRUPT = 276&

'   The extended attribute table file is full.
Public Const ERROR_EA_TABLE_FULL = 277&

'   The specified extended attribute handle is invalid.
Public Const ERROR_INVALID_EA_HANDLE = 278&

'   The mounted file system does not support extended attributes.
Public Const ERROR_EAS_NOT_SUPPORTED = 282&

'   Attempt to release mutex not owned by caller.
Public Const ERROR_NOT_OWNER = 288&

'   Too many posts were made to a semaphore.
Public Const ERROR_TOO_MANY_POSTS = 298&

'   The system cannot find message for message number 0x%1
'   in message file for %2.
Public Const ERROR_MR_MID_NOT_FOUND = 317&

'   Attempt to access invalid address.
Public Const ERROR_INVALID_ADDRESS = 487&

'   Arithmetic result exceeded 32 bits.
Public Const ERROR_ARITHMETIC_OVERFLOW = 534&

'   There is a process on other end of the pipe.
Public Const ERROR_PIPE_CONNECTED = 535&

'   Waiting for a process to open the other end of the pipe.
Public Const ERROR_PIPE_LISTENING = 536&

'   Access to the extended attribute was denied.
Public Const ERROR_EA_ACCESS_DENIED = 994&

'   The I/O operation has been aborted because of either a thread exit
'   or an application request.
Public Const ERROR_OPERATION_ABORTED = 995&

'   Overlapped I/O event is not in a signalled state.
Public Const ERROR_IO_INCOMPLETE = 996&

'   Overlapped I/O operation is in progress.
Public Const ERROR_IO_PENDING = 997 '  dderror

'   Invalid access to memory location.
Public Const ERROR_NOACCESS = 998&

'   Error performing inpage operation.
Public Const ERROR_SWAPERROR = 999&

'   Recursion too deep, stack overflowed.
Public Const ERROR_STACK_OVERFLOW = 1001&

'   The window cannot act on the sent message.
Public Const ERROR_INVALID_MESSAGE = 1002&

'   Cannot complete this function.
Public Const ERROR_CAN_NOT_COMPLETE = 1003&

'   Invalid flags.
Public Const ERROR_INVALID_FLAGS = 1004&

'   The volume does not contain a recognized file system.
'   Please make sure that all required file system drivers are loaded and that the
'   volume is not corrupt.
Public Const ERROR_UNRECOGNIZED_VOLUME = 1005&

'   The volume for a file has been externally altered such that the
'   opened file is no longer valid.
Public Const ERROR_FILE_INVALID = 1006&

'   The requested operation cannot be performed in full-screen mode.
Public Const ERROR_FULLSCREEN_MODE = 1007&

'   An attempt was made to reference a token that does not exist.
Public Const ERROR_NO_TOKEN = 1008&

'   The configuration registry database is corrupt.
Public Const ERROR_BADDB = 1009&

'   The configuration registry key is invalid.
Public Const ERROR_BADKEY = 1010&

'   The configuration registry key could not be opened.
Public Const ERROR_CANTOPEN = 1011&

'   The configuration registry key could not be read.
Public Const ERROR_CANTREAD = 1012&

'   The configuration registry key could not be written.
Public Const ERROR_CANTWRITE = 1013&

'   One of the files in the Registry database had to be recovered
'   by use of a log or alternate copy.  The recovery was successful.
Public Const ERROR_REGISTRY_RECOVERED = 1014&

'   The Registry is corrupt. The structure of one of the files that contains
'   Registry data is corrupt, or the system's image of the file in memory
'   is corrupt, or the file could not be recovered because the alternate
'   copy or log was absent or corrupt.
Public Const ERROR_REGISTRY_CORRUPT = 1015&

'   An I/O operation initiated by the Registry failed unrecoverably.
'   The Registry could not read in, or write out, or flush, one of the files
'   that contain the system's image of the Registry.
Public Const ERROR_REGISTRY_IO_FAILED = 1016&

'   The system has attempted to load or restore a file into the Registry, but the
'   specified file is not in a Registry file format.
Public Const ERROR_NOT_REGISTRY_FILE = 1017&

'   Illegal operation attempted on a Registry key which has been marked for deletion.
Public Const ERROR_KEY_DELETED = 1018&

'   System could not allocate the required space in a Registry log.
Public Const ERROR_NO_LOG_SPACE = 1019&

'   Cannot create a symbolic link in a Registry key that already
'   has subkeys or values.
Public Const ERROR_KEY_HAS_CHILDREN = 1020&

'   Cannot create a stable subkey under a volatile parent key.
Public Const ERROR_CHILD_MUST_BE_VOLATILE = 1021&

'   A notify change request is being completed and the information
'   is not being returned in the caller's buffer. The caller now
'   needs to enumerate the files to find the changes.
Public Const ERROR_NOTIFY_ENUM_DIR = 1022&

'   A stop control has been sent to a service which other running services
'   are dependent on.
Public Const ERROR_DEPENDENT_SERVICES_RUNNING = 1051&

'   The requested control is not valid for this service
Public Const ERROR_INVALID_SERVICE_CONTROL = 1052&

'   The service did not respond to the start or control request in a timely
'   fashion.
Public Const ERROR_SERVICE_REQUEST_TIMEOUT = 1053&

'   A thread could not be created for the service.
Public Const ERROR_SERVICE_NO_THREAD = 1054&

'   The service database is locked.
Public Const ERROR_SERVICE_DATABASE_LOCKED = 1055&

'   An instance of the service is already running.
Public Const ERROR_SERVICE_ALREADY_RUNNING = 1056&

'   The account name is invalid or does not exist.
Public Const ERROR_INVALID_SERVICE_ACCOUNT = 1057&

'   The specified service is disabled and cannot be started.
Public Const ERROR_SERVICE_DISABLED = 1058&

'   Circular service dependency was specified.
Public Const ERROR_CIRCULAR_DEPENDENCY = 1059&

'   The specified service does not exist as an installed service.
Public Const ERROR_SERVICE_DOES_NOT_EXIST = 1060&

'   The service cannot accept control messages at this time.
Public Const ERROR_SERVICE_CANNOT_ACCEPT_CTRL = 1061&

'   The service has not been started.
Public Const ERROR_SERVICE_NOT_ACTIVE = 1062&

'   The service process could not connect to the service controller.
Public Const ERROR_FAILED_SERVICE_CONTROLLER_CONNECT = 1063&

'   An exception occurred in the service when handling the control request.
Public Const ERROR_EXCEPTION_IN_SERVICE = 1064&

'   The database specified does not exist.
Public Const ERROR_DATABASE_DOES_NOT_EXIST = 1065&

'   The service has returned a service-specific error code.
Public Const ERROR_SERVICE_SPECIFIC_ERROR = 1066&

'   The process terminated unexpectedly.
Public Const ERROR_PROCESS_ABORTED = 1067&

'   The dependency service or group failed to start.
Public Const ERROR_SERVICE_DEPENDENCY_FAIL = 1068&

'   The service did not start due to a logon failure.
Public Const ERROR_SERVICE_LOGON_FAILED = 1069&

'   After starting, the service hung in a start-pending state.
Public Const ERROR_SERVICE_START_HANG = 1070&

'   The specified service database lock is invalid.
Public Const ERROR_INVALID_SERVICE_LOCK = 1071&

'   The specified service has been marked for deletion.
Public Const ERROR_SERVICE_MARKED_FOR_DELETE = 1072&

'   The specified service already exists.
Public Const ERROR_SERVICE_EXISTS = 1073&

'   The system is currently running with the last-known-good configuration.
Public Const ERROR_ALREADY_RUNNING_LKG = 1074&

'   The dependency service does not exist or has been marked for
'   deletion.
Public Const ERROR_SERVICE_DEPENDENCY_DELETED = 1075&

'   The current boot has already been accepted for use as the
'   last-known-good control set.
Public Const ERROR_BOOT_ALREADY_ACCEPTED = 1076&

'   No attempts to start the service have been made since the last boot.
Public Const ERROR_SERVICE_NEVER_STARTED = 1077&

'   The name is already in use as either a service name or a service display
'   name.
Public Const ERROR_DUPLICATE_SERVICE_NAME = 1078&

'   The physical end of the tape has been reached.
Public Const ERROR_END_OF_MEDIA = 1100&

'   A tape access reached a filemark.
Public Const ERROR_FILEMARK_DETECTED = 1101&

'   Beginning of tape or partition was encountered.
Public Const ERROR_BEGINNING_OF_MEDIA = 1102&

'   A tape access reached the end of a set of files.
Public Const ERROR_SETMARK_DETECTED = 1103&

'   No more data is on the tape.
Public Const ERROR_NO_DATA_DETECTED = 1104&

'   Tape could not be partitioned.
Public Const ERROR_PARTITION_FAILURE = 1105&

'   When accessing a new tape of a multivolume partition, the current
'   blocksize is incorrect.
Public Const ERROR_INVALID_BLOCK_LENGTH = 1106&

'   Tape partition information could not be found when loading a tape.
Public Const ERROR_DEVICE_NOT_PARTITIONED = 1107&

'   Unable to lock the media eject mechanism.
Public Const ERROR_UNABLE_TO_LOCK_MEDIA = 1108&

'   Unable to unload the media.
Public Const ERROR_UNABLE_TO_UNLOAD_MEDIA = 1109&

'   Media in drive may have changed.
Public Const ERROR_MEDIA_CHANGED = 1110&

'   The I/O bus was reset.
Public Const ERROR_BUS_RESET = 1111&

'   No media in drive.
Public Const ERROR_NO_MEDIA_IN_DRIVE = 1112&

'   No mapping for the Unicode character exists in the target multi-byte code page.
Public Const ERROR_NO_UNICODE_TRANSLATION = 1113&

'   A dynamic link library (DLL) initialization routine failed.
Public Const ERROR_DLL_INIT_FAILED = 1114&

'   A system shutdown is in progress.
Public Const ERROR_SHUTDOWN_IN_PROGRESS = 1115&

'   Unable to abort the system shutdown because no shutdown was in progress.
Public Const ERROR_NO_SHUTDOWN_IN_PROGRESS = 1116&

'   The request could not be performed because of an I/O device error.
Public Const ERROR_IO_DEVICE = 1117&

'   No serial device was successfully initialized.  The serial driver will unload.
Public Const ERROR_SERIAL_NO_DEVICE = 1118&

'   Unable to open a device that was sharing an interrupt request (IRQ)
'   with other devices. At least one other device that uses that IRQ
'   was already opened.
Public Const ERROR_IRQ_BUSY = 1119&

'   A serial I/O operation was completed by another write to the serial port.
'   (The IOCTL_SERIAL_XOFF_COUNTER reached zero.)
Public Const ERROR_MORE_WRITES = 1120&

'   A serial I/O operation completed because the time-out period expired.
'   (The IOCTL_SERIAL_XOFF_COUNTER did not reach zero.)
Public Const ERROR_COUNTER_TIMEOUT = 1121&

'   No ID address mark was found on the floppy disk.
Public Const ERROR_FLOPPY_ID_MARK_NOT_FOUND = 1122&

'   Mismatch between the floppy disk sector ID field and the floppy disk
'   controller track address.
Public Const ERROR_FLOPPY_WRONG_CYLINDER = 1123&

'   The floppy disk controller reported an error that is not recognized
'   by the floppy disk driver.
Public Const ERROR_FLOPPY_UNKNOWN_ERROR = 1124&

'   The floppy disk controller returned inconsistent results in its registers.
Public Const ERROR_FLOPPY_BAD_REGISTERS = 1125&

'   While accessing the hard disk, a recalibrate operation failed, even after retries.
Public Const ERROR_DISK_RECALIBRATE_FAILED = 1126&

'   While accessing the hard disk, a disk operation failed even after retries.
Public Const ERROR_DISK_OPERATION_FAILED = 1127&

'   While accessing the hard disk, a disk controller reset was needed, but
'   even that failed.
Public Const ERROR_DISK_RESET_FAILED = 1128&

'   Physical end of tape encountered.
Public Const ERROR_EOM_OVERFLOW = 1129&

'   Not enough server storage is available to process this command.
Public Const ERROR_NOT_ENOUGH_SERVER_MEMORY = 1130&

'   A potential deadlock condition has been detected.
Public Const ERROR_POSSIBLE_DEADLOCK = 1131&

'   The base address or the file offset specified does not have the proper
'   alignment.
Public Const ERROR_MAPPED_ALIGNMENT = 1132&

' NEW for Win32
Public Const ERROR_INVALID_PIXEL_FORMAT = 2000
Public Const ERROR_BAD_DRIVER = 2001
Public Const ERROR_INVALID_WINDOW_STYLE = 2002
Public Const ERROR_METAFILE_NOT_SUPPORTED = 2003
Public Const ERROR_TRANSFORM_NOT_SUPPORTED = 2004
Public Const ERROR_CLIPPING_NOT_SUPPORTED = 2005
Public Const ERROR_UNKNOWN_PRINT_MONITOR = 3000
Public Const ERROR_PRINTER_DRIVER_IN_USE = 3001
Public Const ERROR_SPOOL_FILE_NOT_FOUND = 3002
Public Const ERROR_SPL_NO_STARTDOC = 3003
Public Const ERROR_SPL_NO_ADDJOB = 3004
Public Const ERROR_PRINT_PROCESSOR_ALREADY_INSTALLED = 3005
Public Const ERROR_PRINT_MONITOR_ALREADY_INSTALLED = 3006
Public Const ERROR_WINS_INTERNAL = 4000
Public Const ERROR_CAN_NOT_DEL_LOCAL_WINS = 4001
Public Const ERROR_STATIC_INIT = 4002
Public Const ERROR_INC_BACKUP = 4003
Public Const ERROR_FULL_BACKUP = 4004
Public Const ERROR_REC_NON_EXISTENT = 4005
Public Const ERROR_RPL_NOT_ALLOWED = 4006
Public Const SEVERITY_SUCCESS = 0
Public Const SEVERITY_ERROR = 1
Public Const FACILITY_NT_BIT = &H10000000
Public Const NOERROR = 0
Public Const E_UNEXPECTED = &H8000FFFF
Public Const E_NOTIMPL = &H80004001
Public Const E_OUTOFMEMORY = &H8007000E
Public Const E_INVALIDARG = &H80070057
Public Const E_NOINTERFACE = &H80004002
Public Const E_POINTER = &H80004003
Public Const E_HANDLE = &H80070006
Public Const E_ABORT = &H80004004
Public Const E_FAIL = &H80004005
Public Const E_ACCESSDENIED = &H80070005
Public Const CO_E_INIT_TLS = &H80004006
Public Const CO_E_INIT_SHARED_ALLOCATOR = &H80004007
Public Const CO_E_INIT_MEMORY_ALLOCATOR = &H80004008
Public Const CO_E_INIT_CLASS_CACHE = &H80004009
Public Const CO_E_INIT_RPC_CHANNEL = &H8000400A
Public Const CO_E_INIT_TLS_SET_CHANNEL_CONTROL = &H8000400B
Public Const CO_E_INIT_TLS_CHANNEL_CONTROL = &H8000400C
Public Const CO_E_INIT_UNACCEPTED_USER_ALLOCATOR = &H8000400D
Public Const CO_E_INIT_SCM_MUTEX_EXISTS = &H8000400E
Public Const CO_E_INIT_SCM_FILE_MAPPING_EXISTS = &H8000400F
Public Const CO_E_INIT_SCM_MAP_VIEW_OF_FILE = &H80004010
Public Const CO_E_INIT_SCM_EXEC_FAILURE = &H80004011
Public Const CO_E_INIT_ONLY_SINGLE_THREADED = &H80004012
Public Const S_OK = &H0
Public Const S_FALSE = &H1
Public Const OLE_E_FIRST = &H80040000
Public Const OLE_E_LAST = &H800400FF
Public Const OLE_S_FIRST = &H40000
Public Const OLE_S_LAST = &H400FF
Public Const OLE_E_OLEVERB = &H80040000
Public Const OLE_E_ADVF = &H80040001
Public Const OLE_E_ENUM_NOMORE = &H80040002
Public Const OLE_E_ADVISENOTSUPPORTED = &H80040003
Public Const OLE_E_NOCONNECTION = &H80040004
Public Const OLE_E_NOTRUNNING = &H80040005
Public Const OLE_E_NOCACHE = &H80040006
Public Const OLE_E_BLANK = &H80040007
Public Const OLE_E_CLASSDIFF = &H80040008
Public Const OLE_E_CANT_GETMONIKER = &H80040009
Public Const OLE_E_CANT_BINDTOSOURCE = &H8004000A
Public Const OLE_E_STATIC = &H8004000B
Public Const OLE_E_PROMPTSAVECANCELLED = &H8004000C
Public Const OLE_E_INVALIDRECT = &H8004000D
Public Const OLE_E_WRONGCOMPOBJ = &H8004000E
Public Const OLE_E_INVALIDHWND = &H8004000F
Public Const OLE_E_NOT_INPLACEACTIVE = &H80040010
Public Const OLE_E_CANTCONVERT = &H80040011
Public Const OLE_E_NOSTORAGE = &H80040012
Public Const DV_E_FORMATETC = &H80040064
Public Const DV_E_DVTARGETDEVICE = &H80040065
Public Const DV_E_STGMEDIUM = &H80040066
Public Const DV_E_STATDATA = &H80040067
Public Const DV_E_LINDEX = &H80040068
Public Const DV_E_TYMED = &H80040069
Public Const DV_E_CLIPFORMAT = &H8004006A
Public Const DV_E_DVASPECT = &H8004006B
Public Const DV_E_DVTARGETDEVICE_SIZE = &H8004006C
Public Const DV_E_NOIVIEWOBJECT = &H8004006D
Public Const DRAGDROP_E_FIRST = &H80040100
Public Const DRAGDROP_E_LAST = &H8004010F
Public Const DRAGDROP_S_FIRST = &H40100
Public Const DRAGDROP_S_LAST = &H4010F
Public Const DRAGDROP_E_NOTREGISTERED = &H80040100
Public Const DRAGDROP_E_ALREADYREGISTERED = &H80040101
Public Const DRAGDROP_E_INVALIDHWND = &H80040102
Public Const CLASSFACTORY_E_FIRST = &H80040110
Public Const CLASSFACTORY_E_LAST = &H8004011F
Public Const CLASSFACTORY_S_FIRST = &H40110
Public Const CLASSFACTORY_S_LAST = &H4011F
Public Const CLASS_E_NOAGGREGATION = &H80040110
Public Const CLASS_E_CLASSNOTAVAILABLE = &H80040111
Public Const MARSHAL_E_FIRST = &H80040120
Public Const MARSHAL_E_LAST = &H8004012F
Public Const MARSHAL_S_FIRST = &H40120
Public Const MARSHAL_S_LAST = &H4012F
Public Const DATA_E_FIRST = &H80040130
Public Const DATA_E_LAST = &H8004013F
Public Const DATA_S_FIRST = &H40130
Public Const DATA_S_LAST = &H4013F
Public Const VIEW_E_FIRST = &H80040140
Public Const VIEW_E_LAST = &H8004014F
Public Const VIEW_S_FIRST = &H40140
Public Const VIEW_S_LAST = &H4014F
Public Const VIEW_E_DRAW = &H80040140
Public Const REGDB_E_FIRST = &H80040150
Public Const REGDB_E_LAST = &H8004015F
Public Const REGDB_S_FIRST = &H40150
Public Const REGDB_S_LAST = &H4015F
Public Const REGDB_E_READREGDB = &H80040150
Public Const REGDB_E_WRITEREGDB = &H80040151
Public Const REGDB_E_KEYMISSING = &H80040152
Public Const REGDB_E_INVALIDVALUE = &H80040153
Public Const REGDB_E_CLASSNOTREG = &H80040154
Public Const REGDB_E_IIDNOTREG = &H80040155
Public Const CACHE_E_FIRST = &H80040170
Public Const CACHE_E_LAST = &H8004017F
Public Const CACHE_S_FIRST = &H40170
Public Const CACHE_S_LAST = &H4017F
Public Const CACHE_E_NOCACHE_UPDATED = &H80040170
Public Const OLEOBJ_E_FIRST = &H80040180
Public Const OLEOBJ_E_LAST = &H8004018F
Public Const OLEOBJ_S_FIRST = &H40180
Public Const OLEOBJ_S_LAST = &H4018F
Public Const OLEOBJ_E_NOVERBS = &H80040180
Public Const OLEOBJ_E_INVALIDVERB = &H80040181
Public Const CLIENTSITE_E_FIRST = &H80040190
Public Const CLIENTSITE_E_LAST = &H8004019F
Public Const CLIENTSITE_S_FIRST = &H40190
Public Const CLIENTSITE_S_LAST = &H4019F
Public Const INPLACE_E_NOTUNDOABLE = &H800401A0
Public Const INPLACE_E_NOTOOLSPACE = &H800401A1
Public Const INPLACE_E_FIRST = &H800401A0
Public Const INPLACE_E_LAST = &H800401AF
Public Const INPLACE_S_FIRST = &H401A0
Public Const INPLACE_S_LAST = &H401AF
Public Const ENUM_E_FIRST = &H800401B0
Public Const ENUM_E_LAST = &H800401BF
Public Const ENUM_S_FIRST = &H401B0
Public Const ENUM_S_LAST = &H401BF
Public Const CONVERT10_E_FIRST = &H800401C0
Public Const CONVERT10_E_LAST = &H800401CF
Public Const CONVERT10_S_FIRST = &H401C0
Public Const CONVERT10_S_LAST = &H401CF
Public Const CONVERT10_E_OLESTREAM_GET = &H800401C0
Public Const CONVERT10_E_OLESTREAM_PUT = &H800401C1
Public Const CONVERT10_E_OLESTREAM_FMT = &H800401C2
Public Const CONVERT10_E_OLESTREAM_BITMAP_TO_DIB = &H800401C3
Public Const CONVERT10_E_STG_FMT = &H800401C4
Public Const CONVERT10_E_STG_NO_STD_STREAM = &H800401C5
Public Const CONVERT10_E_STG_DIB_TO_BITMAP = &H800401C6
Public Const CLIPBRD_E_FIRST = &H800401D0
Public Const CLIPBRD_E_LAST = &H800401DF
Public Const CLIPBRD_S_FIRST = &H401D0
Public Const CLIPBRD_S_LAST = &H401DF
Public Const CLIPBRD_E_CANT_OPEN = &H800401D0
Public Const CLIPBRD_E_CANT_EMPTY = &H800401D1
Public Const CLIPBRD_E_CANT_SET = &H800401D2
Public Const CLIPBRD_E_BAD_DATA = &H800401D3
Public Const CLIPBRD_E_CANT_CLOSE = &H800401D4
Public Const MK_E_FIRST = &H800401E0
Public Const MK_E_LAST = &H800401EF
Public Const MK_S_FIRST = &H401E0
Public Const MK_S_LAST = &H401EF
Public Const MK_E_CONNECTMANUALLY = &H800401E0
Public Const MK_E_EXCEEDEDDEADLINE = &H800401E1
Public Const MK_E_NEEDGENERIC = &H800401E2
Public Const MK_E_UNAVAILABLE = &H800401E3
Public Const MK_E_SYNTAX = &H800401E4
Public Const MK_E_NOOBJECT = &H800401E5
Public Const MK_E_INVALIDEXTENSION = &H800401E6
Public Const MK_E_INTERMEDIATEINTERFACENOTSUPPORTED = &H800401E7
Public Const MK_E_NOTBINDABLE = &H800401E8
Public Const MK_E_NOTBOUND = &H800401E9
Public Const MK_E_CANTOPENFILE = &H800401EA
Public Const MK_E_MUSTBOTHERUSER = &H800401EB
Public Const MK_E_NOINVERSE = &H800401EC
Public Const MK_E_NOSTORAGE = &H800401ED
Public Const MK_E_NOPREFIX = &H800401EE
Public Const MK_E_ENUMERATION_FAILED = &H800401EF
Public Const CO_E_FIRST = &H800401F0
Public Const CO_E_LAST = &H800401FF
Public Const CO_S_FIRST = &H401F0
Public Const CO_S_LAST = &H401FF
Public Const CO_E_NOTINITIALIZED = &H800401F0
Public Const CO_E_ALREADYINITIALIZED = &H800401F1
Public Const CO_E_CANTDETERMINECLASS = &H800401F2
Public Const CO_E_CLASSSTRING = &H800401F3
Public Const CO_E_IIDSTRING = &H800401F4
Public Const CO_E_APPNOTFOUND = &H800401F5
Public Const CO_E_APPSINGLEUSE = &H800401F6
Public Const CO_E_ERRORINAPP = &H800401F7
Public Const CO_E_DLLNOTFOUND = &H800401F8
Public Const CO_E_ERRORINDLL = &H800401F9
Public Const CO_E_WRONGOSFORAPP = &H800401FA
Public Const CO_E_OBJNOTREG = &H800401FB
Public Const CO_E_OBJISREG = &H800401FC
Public Const CO_E_OBJNOTCONNECTED = &H800401FD
Public Const CO_E_APPDIDNTREG = &H800401FE
Public Const CO_E_RELEASED = &H800401FF
Public Const OLE_S_USEREG = &H40000
Public Const OLE_S_STATIC = &H40001
Public Const OLE_S_MAC_CLIPFORMAT = &H40002
Public Const DRAGDROP_S_DROP = &H40100
Public Const DRAGDROP_S_CANCEL = &H40101
Public Const DRAGDROP_S_USEDEFAULTCURSORS = &H40102
Public Const DATA_S_SAMEFORMATETC = &H40130
Public Const VIEW_S_ALREADY_FROZEN = &H40140
Public Const CACHE_S_FORMATETC_NOTSUPPORTED = &H40170
Public Const CACHE_S_SAMECACHE = &H40171
Public Const CACHE_S_SOMECACHES_NOTUPDATED = &H40172
Public Const OLEOBJ_S_INVALIDVERB = &H40180
Public Const OLEOBJ_S_CANNOT_DOVERB_NOW = &H40181
Public Const OLEOBJ_S_INVALIDHWND = &H40182
Public Const INPLACE_S_TRUNCATED = &H401A0
Public Const CONVERT10_S_NO_PRESENTATION = &H401C0
Public Const MK_S_REDUCED_TO_SELF = &H401E2
Public Const MK_S_ME = &H401E4
Public Const MK_S_HIM = &H401E5
Public Const MK_S_US = &H401E6
Public Const MK_S_MONIKERALREADYREGISTERED = &H401E7
Public Const CO_E_CLASS_CREATE_FAILED = &H80080001
Public Const CO_E_SCM_ERROR = &H80080002
Public Const CO_E_SCM_RPC_FAILURE = &H80080003
Public Const CO_E_BAD_PATH = &H80080004
Public Const CO_E_SERVER_EXEC_FAILURE = &H80080005
Public Const CO_E_OBJSRV_RPC_FAILURE = &H80080006
Public Const MK_E_NO_NORMALIZED = &H80080007
Public Const CO_E_SERVER_STOPPING = &H80080008
Public Const MEM_E_INVALID_ROOT = &H80080009
Public Const MEM_E_INVALID_LINK = &H80080010
Public Const MEM_E_INVALID_SIZE = &H80080011
Public Const DISP_E_UNKNOWNINTERFACE = &H80020001
Public Const DISP_E_MEMBERNOTFOUND = &H80020003
Public Const DISP_E_PARAMNOTFOUND = &H80020004
Public Const DISP_E_TYPEMISMATCH = &H80020005
Public Const DISP_E_UNKNOWNNAME = &H80020006
Public Const DISP_E_NONAMEDARGS = &H80020007
Public Const DISP_E_BADVARTYPE = &H80020008
Public Const DISP_E_EXCEPTION = &H80020009
Public Const DISP_E_OVERFLOW = &H8002000A
Public Const DISP_E_BADINDEX = &H8002000B
Public Const DISP_E_UNKNOWNLCID = &H8002000C
Public Const DISP_E_ARRAYISLOCKED = &H8002000D
Public Const DISP_E_BADPARAMCOUNT = &H8002000E
Public Const DISP_E_PARAMNOTOPTIONAL = &H8002000F
Public Const DISP_E_BADCALLEE = &H80020010
Public Const DISP_E_NOTACOLLECTION = &H80020011
Public Const TYPE_E_BUFFERTOOSMALL = &H80028016
Public Const TYPE_E_INVDATAREAD = &H80028018
Public Const TYPE_E_UNSUPFORMAT = &H80028019
Public Const TYPE_E_REGISTRYACCESS = &H8002801C
Public Const TYPE_E_LIBNOTREGISTERED = &H8002801D
Public Const TYPE_E_UNDEFINEDTYPE = &H80028027
Public Const TYPE_E_QUALIFIEDNAMEDISALLOWED = &H80028028
Public Const TYPE_E_INVALIDSTATE = &H80028029
Public Const TYPE_E_WRONGTYPEKIND = &H8002802A
Public Const TYPE_E_ELEMENTNOTFOUND = &H8002802B
Public Const TYPE_E_AMBIGUOUSNAME = &H8002802C
Public Const TYPE_E_NAMECONFLICT = &H8002802D
Public Const TYPE_E_UNKNOWNLCID = &H8002802E
Public Const TYPE_E_DLLFUNCTIONNOTFOUND = &H8002802F
Public Const TYPE_E_BADMODULEKIND = &H800288BD
Public Const TYPE_E_SIZETOOBIG = &H800288C5
Public Const TYPE_E_DUPLICATEID = &H800288C6
Public Const TYPE_E_INVALIDID = &H800288CF
Public Const TYPE_E_TYPEMISMATCH = &H80028CA0
Public Const TYPE_E_OUTOFBOUNDS = &H80028CA1
Public Const TYPE_E_IOERROR = &H80028CA2
Public Const TYPE_E_CANTCREATETMPFILE = &H80028CA3
Public Const TYPE_E_CANTLOADLIBRARY = &H80029C4A
Public Const TYPE_E_INCONSISTENTPROPFUNCS = &H80029C83
Public Const TYPE_E_CIRCULARTYPE = &H80029C84
Public Const STG_E_INVALIDFUNCTION = &H80030001
Public Const STG_E_FILENOTFOUND = &H80030002
Public Const STG_E_PATHNOTFOUND = &H80030003
Public Const STG_E_TOOMANYOPENFILES = &H80030004
Public Const STG_E_ACCESSDENIED = &H80030005
Public Const STG_E_INVALIDHANDLE = &H80030006
Public Const STG_E_INSUFFICIENTMEMORY = &H80030008
Public Const STG_E_INVALIDPOINTER = &H80030009
Public Const STG_E_NOMOREFILES = &H80030012
Public Const STG_E_DISKISWRITEPROTECTED = &H80030013
Public Const STG_E_SEEKERROR = &H80030019
Public Const STG_E_WRITEFAULT = &H8003001D
Public Const STG_E_READFAULT = &H8003001E
Public Const STG_E_SHAREVIOLATION = &H80030020
Public Const STG_E_LOCKVIOLATION = &H80030021
Public Const STG_E_FILEALREADYEXISTS = &H80030050
Public Const STG_E_INVALIDPARAMETER = &H80030057
Public Const STG_E_MEDIUMFULL = &H80030070
Public Const STG_E_ABNORMALAPIEXIT = &H800300FA
Public Const STG_E_INVALIDHEADER = &H800300FB
Public Const STG_E_INVALIDNAME = &H800300FC
Public Const STG_E_UNKNOWN = &H800300FD
Public Const STG_E_UNIMPLEMENTEDFUNCTION = &H800300FE
Public Const STG_E_INVALIDFLAG = &H800300FF
Public Const STG_E_INUSE = &H80030100
Public Const STG_E_NOTCURRENT = &H80030101
Public Const STG_E_REVERTED = &H80030102
Public Const STG_E_CANTSAVE = &H80030103
Public Const STG_E_OLDFORMAT = &H80030104
Public Const STG_E_OLDDLL = &H80030105
Public Const STG_E_SHAREREQUIRED = &H80030106
Public Const STG_E_NOTFILEBASEDSTORAGE = &H80030107
Public Const STG_E_EXTANTMARSHALLINGS = &H80030108
Public Const STG_S_CONVERTED = &H30200
Public Const RPC_E_CALL_REJECTED = &H80010001
Public Const RPC_E_CALL_CANCELED = &H80010002
Public Const RPC_E_CANTPOST_INSENDCALL = &H80010003
Public Const RPC_E_CANTCALLOUT_INASYNCCALL = &H80010004
Public Const RPC_E_CANTCALLOUT_INEXTERNALCALL = &H80010005
Public Const RPC_E_CONNECTION_TERMINATED = &H80010006
Public Const RPC_E_SERVER_DIED = &H80010007
Public Const RPC_E_CLIENT_DIED = &H80010008
Public Const RPC_E_INVALID_DATAPACKET = &H80010009
Public Const RPC_E_CANTTRANSMIT_CALL = &H8001000A
Public Const RPC_E_CLIENT_CANTMARSHAL_DATA = &H8001000B
Public Const RPC_E_CLIENT_CANTUNMARSHAL_DATA = &H8001000C
Public Const RPC_E_SERVER_CANTMARSHAL_DATA = &H8001000D
Public Const RPC_E_SERVER_CANTUNMARSHAL_DATA = &H8001000E
Public Const RPC_E_INVALID_DATA = &H8001000F
Public Const RPC_E_INVALID_PARAMETER = &H80010010
Public Const RPC_E_CANTCALLOUT_AGAIN = &H80010011
Public Const RPC_E_SERVER_DIED_DNE = &H80010012
Public Const RPC_E_SYS_CALL_FAILED = &H80010100
Public Const RPC_E_OUT_OF_RESOURCES = &H80010101
Public Const RPC_E_ATTEMPTED_MULTITHREAD = &H80010102
Public Const RPC_E_NOT_REGISTERED = &H80010103
Public Const RPC_E_FAULT = &H80010104
Public Const RPC_E_SERVERFAULT = &H80010105
Public Const RPC_E_CHANGED_MODE = &H80010106
Public Const RPC_E_INVALIDMETHOD = &H80010107
Public Const RPC_E_DISCONNECTED = &H80010108
Public Const RPC_E_RETRY = &H80010109
Public Const RPC_E_SERVERCALL_RETRYLATER = &H8001010A
Public Const RPC_E_SERVERCALL_REJECTED = &H8001010B
Public Const RPC_E_INVALID_CALLDATA = &H8001010C
Public Const RPC_E_CANTCALLOUT_ININPUTSYNCCALL = &H8001010D
Public Const RPC_E_WRONG_THREAD = &H8001010E
Public Const RPC_E_THREAD_NOT_INIT = &H8001010F
Public Const RPC_E_UNEXPECTED = &H8001FFFF


' /////////////////////////
'                        //
'  Winnet32 Status Codes //
'                        //
' /////////////////////////

'   The specified username is invalid.
Public Const ERROR_BAD_USERNAME = 2202&

'   This network connection does not exist.
Public Const ERROR_NOT_CONNECTED = 2250&

'   This network connection has files open or requests pending.
Public Const ERROR_OPEN_FILES = 2401&

'   The device is in use by an active process and cannot be disconnected.
Public Const ERROR_DEVICE_IN_USE = 2404&

'   The specified device name is invalid.
Public Const ERROR_BAD_DEVICE = 1200&

'   The device is not currently connected but it is a remembered connection.
Public Const ERROR_CONNECTION_UNAVAIL = 1201&

'   An attempt was made to remember a device that had previously been remembered.
Public Const ERROR_DEVICE_ALREADY_REMEMBERED = 1202&

'   No network provider accepted the given network path.
Public Const ERROR_NO_NET_OR_BAD_PATH = 1203&

'   The specified network provider name is invalid.
Public Const ERROR_BAD_PROVIDER = 1204&

'   Unable to open the network connection profile.
Public Const ERROR_CANNOT_OPEN_PROFILE = 1205&

'   The network connection profile is corrupt.
Public Const ERROR_BAD_PROFILE = 1206&

'   Cannot enumerate a non-container.
Public Const ERROR_NOT_CONTAINER = 1207&

'   An extended error has occurred.
Public Const ERROR_EXTENDED_ERROR = 1208&

'   The format of the specified group name is invalid.
Public Const ERROR_INVALID_GROUPNAME = 1209&

'   The format of the specified computer name is invalid.
Public Const ERROR_INVALID_COMPUTERNAME = 1210&

'   The format of the specified event name is invalid.
Public Const ERROR_INVALID_EVENTNAME = 1211&

'   The format of the specified domain name is invalid.
Public Const ERROR_INVALID_DOMAINNAME = 1212&

'   The format of the specified service name is invalid.
Public Const ERROR_INVALID_SERVICENAME = 1213&

'   The format of the specified network name is invalid.
Public Const ERROR_INVALID_NETNAME = 1214&

'   The format of the specified share name is invalid.
Public Const ERROR_INVALID_SHARENAME = 1215&

'   The format of the specified password is invalid.
Public Const ERROR_INVALID_PASSWORDNAME = 1216&

'   The format of the specified message name is invalid.
Public Const ERROR_INVALID_MESSAGENAME = 1217&

'   The format of the specified message destination is invalid.
Public Const ERROR_INVALID_MESSAGEDEST = 1218&

'   The credentials supplied conflict with an existing set of credentials.
Public Const ERROR_SESSION_CREDENTIAL_CONFLICT = 1219&

'   An attempt was made to establish a session to a Lan Manager server, but there
'   are already too many sessions established to that server.
Public Const ERROR_REMOTE_SESSION_LIMIT_EXCEEDED = 1220&

'   The workgroup or domain name is already in use by another computer on the
'   network.
Public Const ERROR_DUP_DOMAINNAME = 1221&

'   The network is not present or not started.
Public Const ERROR_NO_NETWORK = 1222&


' /////////////////////////
'                        //
'  Security Status Codes //
'                        //
' /////////////////////////

'   Not all privileges referenced are assigned to the caller.
Public Const ERROR_NOT_ALL_ASSIGNED = 1300&

'   Some mapping between account names and security IDs was not done.
Public Const ERROR_SOME_NOT_MAPPED = 1301&

'   No system quota limits are specifically set for this account.
Public Const ERROR_NO_QUOTAS_FOR_ACCOUNT = 1302&

'   No encryption key is available.  A well-known encryption key was returned.
Public Const ERROR_LOCAL_USER_SESSION_KEY = 1303&

'   The NT password is too complex to be converted to a LAN Manager
'   password.  The LAN Manager password returned is a NULL string.
Public Const ERROR_NULL_LM_PASSWORD = 1304&

'   The revision level is unknown.
Public Const ERROR_UNKNOWN_REVISION = 1305&

'   Indicates two revision levels are incompatible.
Public Const ERROR_REVISION_MISMATCH = 1306&

'   This security ID may not be assigned as the owner of this object.
Public Const ERROR_INVALID_OWNER = 1307&

'   This security ID may not be assigned as the primary group of an object.
Public Const ERROR_INVALID_PRIMARY_GROUP = 1308&

'   An attempt has been made to operate on an impersonation token
'   by a thread that is not currently impersonating a client.
Public Const ERROR_NO_IMPERSONATION_TOKEN = 1309&

'   The group may not be disabled.
Public Const ERROR_CANT_DISABLE_MANDATORY = 1310&

'   There are currently no logon servers available to service the logon
'   request.
Public Const ERROR_NO_LOGON_SERVERS = 1311&

'    A specified logon session does not exist.  It may already have
'    been terminated.
Public Const ERROR_NO_SUCH_LOGON_SESSION = 1312&

'    A specified privilege does not exist.
Public Const ERROR_NO_SUCH_PRIVILEGE = 1313&

'    A required privilege is not held by the client.
Public Const ERROR_PRIVILEGE_NOT_HELD = 1314&

'   The name provided is not a properly formed account name.
Public Const ERROR_INVALID_ACCOUNT_NAME = 1315&

'   The specified user already exists.
Public Const ERROR_USER_EXISTS = 1316&

'   The specified user does not exist.
Public Const ERROR_NO_SUCH_USER = 1317&

'   The specified group already exists.
Public Const ERROR_GROUP_EXISTS = 1318&

'   The specified group does not exist.
Public Const ERROR_NO_SUCH_GROUP = 1319&

'   Either the specified user account is already a member of the specified
'   group, or the specified group cannot be deleted because it contains
'   a member.
Public Const ERROR_MEMBER_IN_GROUP = 1320&

'   The specified user account is not a member of the specified group account.
Public Const ERROR_MEMBER_NOT_IN_GROUP = 1321&

'   The last remaining administration account cannot be disabled
'   or deleted.
Public Const ERROR_LAST_ADMIN = 1322&

'   Unable to update the password.  The value provided as the current
'   password is incorrect.
Public Const ERROR_WRONG_PASSWORD = 1323&

'   Unable to update the password.  The value provided for the new password
'   contains values that are not allowed in passwords.
Public Const ERROR_ILL_FORMED_PASSWORD = 1324&

'   Unable to update the password because a password update rule has been
'   violated.
Public Const ERROR_PASSWORD_RESTRICTION = 1325&

'   Logon failure: unknown user name or bad password.
Public Const ERROR_LOGON_FAILURE = 1326&

'   Logon failure: user account restriction.
Public Const ERROR_ACCOUNT_RESTRICTION = 1327&

'   Logon failure: account logon time restriction violation.
Public Const ERROR_INVALID_LOGON_HOURS = 1328&

'   Logon failure: user not allowed to log on to this computer.
Public Const ERROR_INVALID_WORKSTATION = 1329&

'   Logon failure: the specified account password has expired.
Public Const ERROR_PASSWORD_EXPIRED = 1330&

'   Logon failure: account currently disabled.
Public Const ERROR_ACCOUNT_DISABLED = 1331&

'   No mapping between account names and security IDs was done.
Public Const ERROR_NONE_MAPPED = 1332&

'   Too many local user identifiers (LUIDs) were requested at one time.
Public Const ERROR_TOO_MANY_LUIDS_REQUESTED = 1333&

'   No more local user identifiers (LUIDs) are available.
Public Const ERROR_LUIDS_EXHAUSTED = 1334&

'   The subauthority part of a security ID is invalid for this particular use.
Public Const ERROR_INVALID_SUB_AUTHORITY = 1335&

'   The access control list (ACL) structure is invalid.
Public Const ERROR_INVALID_ACL = 1336&

'   The security ID structure is invalid.
Public Const ERROR_INVALID_SID = 1337&

'   The security descriptor structure is invalid.
Public Const ERROR_INVALID_SECURITY_DESCR = 1338&

'   The inherited access control list (ACL) or access control entry (ACE)
'   could not be built.
Public Const ERROR_BAD_INHERITANCE_ACL = 1340&

'   The server is currently disabled.
Public Const ERROR_SERVER_DISABLED = 1341&

'   The server is currently enabled.
Public Const ERROR_SERVER_NOT_DISABLED = 1342&

'   The value provided was an invalid value for an identifier authority.
Public Const ERROR_INVALID_ID_AUTHORITY = 1343&

'   No more memory is available for security information updates.
Public Const ERROR_ALLOTTED_SPACE_EXCEEDED = 1344&

'   The specified attributes are invalid, or incompatible with the
'   attributes for the group as a whole.
Public Const ERROR_INVALID_GROUP_ATTRIBUTES = 1345&

'   Either a required impersonation level was not provided, or the
'   provided impersonation level is invalid.
Public Const ERROR_BAD_IMPERSONATION_LEVEL = 1346&

'   Cannot open an anonymous level security token.
Public Const ERROR_CANT_OPEN_ANONYMOUS = 1347&

'   The validation information class requested was invalid.
Public Const ERROR_BAD_VALIDATION_CLASS = 1348&

'   The type of the token is inappropriate for its attempted use.
Public Const ERROR_BAD_TOKEN_TYPE = 1349&

'   Unable to perform a security operation on an object
'   which has no associated security.
Public Const ERROR_NO_SECURITY_ON_OBJECT = 1350&

'   Indicates a Windows NT Advanced Server could not be contacted or that
'   objects within the domain are protected such that necessary
'   information could not be retrieved.
Public Const ERROR_CANT_ACCESS_DOMAIN_INFO = 1351&

'   The security account manager (SAM) or local security
'   authority (LSA) server was in the wrong state to perform
'   the security operation.
Public Const ERROR_INVALID_SERVER_STATE = 1352&

'   The domain was in the wrong state to perform the security operation.
Public Const ERROR_INVALID_DOMAIN_STATE = 1353&

'   This operation is only allowed for the Primary Domain Controller of the domain.
Public Const ERROR_INVALID_DOMAIN_ROLE = 1354&

'   The specified domain did not exist.
Public Const ERROR_NO_SUCH_DOMAIN = 1355&

'   The specified domain already exists.
Public Const ERROR_DOMAIN_EXISTS = 1356&

'   An attempt was made to exceed the limit on the number of domains per server.
Public Const ERROR_DOMAIN_LIMIT_EXCEEDED = 1357&

'   Unable to complete the requested operation because of either a
'   catastrophic media failure or a data structure corruption on the disk.
Public Const ERROR_INTERNAL_DB_CORRUPTION = 1358&

'   The security account database contains an internal inconsistency.
Public Const ERROR_INTERNAL_ERROR = 1359&

'   Generic access types were contained in an access mask which should
'   already be mapped to non-generic types.
Public Const ERROR_GENERIC_NOT_MAPPED = 1360&

'   A security descriptor is not in the right format (absolute or self-relative).
Public Const ERROR_BAD_DESCRIPTOR_FORMAT = 1361&

'   The requested action is restricted for use by logon processes
'   only.  The calling process has not registered as a logon process.
Public Const ERROR_NOT_LOGON_PROCESS = 1362&

'   Cannot start a new logon session with an ID that is already in use.
Public Const ERROR_LOGON_SESSION_EXISTS = 1363&

'   A specified authentication package is unknown.
Public Const ERROR_NO_SUCH_PACKAGE = 1364&

'   The logon session is not in a state that is consistent with the
'   requested operation.
Public Const ERROR_BAD_LOGON_SESSION_STATE = 1365&

'   The logon session ID is already in use.
Public Const ERROR_LOGON_SESSION_COLLISION = 1366&

'   A logon request contained an invalid logon type value.
Public Const ERROR_INVALID_LOGON_TYPE = 1367&

'   Unable to impersonate via a named pipe until data has been read
'   from that pipe.
Public Const ERROR_CANNOT_IMPERSONATE = 1368&

'   The transaction state of a Registry subtree is incompatible with the
'   requested operation.
Public Const ERROR_RXACT_INVALID_STATE = 1369&

'   An internal security database corruption has been encountered.
Public Const ERROR_RXACT_COMMIT_FAILURE = 1370&

'   Cannot perform this operation on built-in accounts.
Public Const ERROR_SPECIAL_ACCOUNT = 1371&

'   Cannot perform this operation on this built-in special group.
Public Const ERROR_SPECIAL_GROUP = 1372&

'   Cannot perform this operation on this built-in special user.
Public Const ERROR_SPECIAL_USER = 1373&

'   The user cannot be removed from a group because the group
'   is currently the user's primary group.
Public Const ERROR_MEMBERS_PRIMARY_GROUP = 1374&

'   The token is already in use as a primary token.
Public Const ERROR_TOKEN_ALREADY_IN_USE = 1375&

'   The specified local group does not exist.
Public Const ERROR_NO_SUCH_ALIAS = 1376&

'   The specified account name is not a member of the local group.
Public Const ERROR_MEMBER_NOT_IN_ALIAS = 1377&

'   The specified account name is already a member of the local group.
Public Const ERROR_MEMBER_IN_ALIAS = 1378&

'   The specified local group already exists.
Public Const ERROR_ALIAS_EXISTS = 1379&

'   Logon failure: the user has not been granted the requested
'   logon type at this computer.
Public Const ERROR_LOGON_NOT_GRANTED = 1380&

'   The maximum number of secrets that may be stored in a single system has been
'   exceeded.
Public Const ERROR_TOO_MANY_SECRETS = 1381&

'   The length of a secret exceeds the maximum length allowed.
Public Const ERROR_SECRET_TOO_LONG = 1382&

'   The local security authority database contains an internal inconsistency.
Public Const ERROR_INTERNAL_DB_ERROR = 1383&

'   During a logon attempt, the user's security context accumulated too many
'   security IDs.
Public Const ERROR_TOO_MANY_CONTEXT_IDS = 1384&

'   Logon failure: the user has not been granted the requested logon type
'   at this computer.
Public Const ERROR_LOGON_TYPE_NOT_GRANTED = 1385&

'   A cross-encrypted password is necessary to change a user password.
Public Const ERROR_NT_CROSS_ENCRYPTION_REQUIRED = 1386&

'   A new member could not be added to a local group because the member does
'   not exist.
Public Const ERROR_NO_SUCH_MEMBER = 1387&

'   A new member could not be added to a local group because the member has the
'   wrong account type.
Public Const ERROR_INVALID_MEMBER = 1388&

'   Too many security IDs have been specified.
Public Const ERROR_TOO_MANY_SIDS = 1389&

'   A cross-encrypted password is necessary to change this user password.
Public Const ERROR_LM_CROSS_ENCRYPTION_REQUIRED = 1390&

'   Indicates an ACL contains no inheritable components
Public Const ERROR_NO_INHERITANCE = 1391&

'   The file or directory is corrupt and non-readable.
Public Const ERROR_FILE_CORRUPT = 1392&

'   The disk structure is corrupt and non-readable.
Public Const ERROR_DISK_CORRUPT = 1393&

'   There is no user session key for the specified logon session.
Public Const ERROR_NO_USER_SESSION_KEY = 1394&

'  End of security error codes


' /////////////////////////
'                        //
'  WinUser Error Codes   //
'                        //
' /////////////////////////

'   Invalid window handle.
Public Const ERROR_INVALID_WINDOW_HANDLE = 1400&

'   Invalid menu handle.
Public Const ERROR_INVALID_MENU_HANDLE = 1401&

'   Invalid cursor handle.
Public Const ERROR_INVALID_CURSOR_HANDLE = 1402&

'   Invalid accelerator table handle.
Public Const ERROR_INVALID_ACCEL_HANDLE = 1403&

'   Invalid hook handle.
Public Const ERROR_INVALID_HOOK_HANDLE = 1404&

'   Invalid handle to a multiple-window position structure.
Public Const ERROR_INVALID_DWP_HANDLE = 1405&

'   Cannot create a top-level child window.
Public Const ERROR_TLW_WITH_WSCHILD = 1406&

'   Cannot find window class.
Public Const ERROR_CANNOT_FIND_WND_CLASS = 1407&

'   Invalid window, belongs to other thread.
Public Const ERROR_WINDOW_OF_OTHER_THREAD = 1408&

'   Hot key is already registered.
Public Const ERROR_HOTKEY_ALREADY_REGISTERED = 1409&

'   Class already exists.
Public Const ERROR_CLASS_ALREADY_EXISTS = 1410&

'   Class does not exist.
Public Const ERROR_CLASS_DOES_NOT_EXIST = 1411&

'   Class still has open windows.
Public Const ERROR_CLASS_HAS_WINDOWS = 1412&

'   Invalid index.
Public Const ERROR_INVALID_INDEX = 1413&

'   Invalid icon handle.
Public Const ERROR_INVALID_ICON_HANDLE = 1414&

'   Using private DIALOG window words.
Public Const ERROR_PRIVATE_DIALOG_INDEX = 1415&

'   The listbox identifier was not found.
Public Const ERROR_LISTBOX_ID_NOT_FOUND = 1416&

'   No wildcards were found.
Public Const ERROR_NO_WILDCARD_CHARACTERS = 1417&

'   Thread does not have a clipboard open.
Public Const ERROR_CLIPBOARD_NOT_OPEN = 1418&

'   Hot key is not registered.
Public Const ERROR_HOTKEY_NOT_REGISTERED = 1419&

'   The window is not a valid dialog window.
Public Const ERROR_WINDOW_NOT_DIALOG = 1420&

'   Control ID not found.
Public Const ERROR_CONTROL_ID_NOT_FOUND = 1421&

'   Invalid message for a combo box because it does not have an edit control.
Public Const ERROR_INVALID_COMBOBOX_MESSAGE = 1422&

'   The window is not a combo box.
Public Const ERROR_WINDOW_NOT_COMBOBOX = 1423&

'   Height must be less than 256.
Public Const ERROR_INVALID_EDIT_HEIGHT = 1424&

'   Invalid device context (DC) handle.
Public Const ERROR_DC_NOT_FOUND = 1425&

'   Invalid hook procedure type.
Public Const ERROR_INVALID_HOOK_FILTER = 1426&

'   Invalid hook procedure.
Public Const ERROR_INVALID_FILTER_PROC = 1427&

'   Cannot set non-local hook without a module handle.
Public Const ERROR_HOOK_NEEDS_HMOD = 1428&

'   This hook procedure can only be set Globally.
'
Public Const ERROR_PUBLIC_ONLY_HOOK = 1429&

'   The journal hook procedure is already installed.
Public Const ERROR_JOURNAL_HOOK_SET = 1430&

'   The hook procedure is not installed.
Public Const ERROR_HOOK_NOT_INSTALLED = 1431&

'   Invalid message for single-selection listbox.
Public Const ERROR_INVALID_LB_MESSAGE = 1432&

'   LB_SETCOUNT sent to non-lazy listbox.
Public Const ERROR_SETCOUNT_ON_BAD_LB = 1433&

'   This list box does not support tab stops.
Public Const ERROR_LB_WITHOUT_TABSTOPS = 1434&

'   Cannot destroy object created by another thread.
Public Const ERROR_DESTROY_OBJECT_OF_OTHER_THREAD = 1435&

'   Child windows cannot have menus.
Public Const ERROR_CHILD_WINDOW_MENU = 1436&

'   The window does not have a system menu.
Public Const ERROR_NO_SYSTEM_MENU = 1437&

'   Invalid message box style.
Public Const ERROR_INVALID_MSGBOX_STYLE = 1438&

'   Invalid system-wide (SPI_) parameter.
Public Const ERROR_INVALID_SPI_VALUE = 1439&

'   Screen already locked.
Public Const ERROR_SCREEN_ALREADY_LOCKED = 1440&

'   All handles to windows in a multiple-window position structure must
'   have the same parent.
Public Const ERROR_HWNDS_HAVE_DIFF_PARENT = 1441&

'   The window is not a child window.
Public Const ERROR_NOT_CHILD_WINDOW = 1442&

'   Invalid GW_ command.
Public Const ERROR_INVALID_GW_COMMAND = 1443&

'   Invalid thread identifier.
Public Const ERROR_INVALID_THREAD_ID = 1444&

'   Cannot process a message from a window that is not a multiple document
'   interface (MDI) window.
Public Const ERROR_NON_MDICHILD_WINDOW = 1445&

'   Popup menu already active.
Public Const ERROR_POPUP_ALREADY_ACTIVE = 1446&

'   The window does not have scroll bars.
Public Const ERROR_NO_SCROLLBARS = 1447&

'   Scroll bar range cannot be greater than 0x7FFF.
Public Const ERROR_INVALID_SCROLLBAR_RANGE = 1448&

'   Cannot show or remove the window in the way specified.
Public Const ERROR_INVALID_SHOWWIN_COMMAND = 1449&

'  End of WinUser error codes


' /////////////////////////
'                        //
'  Eventlog Status Codes //
'                        //
' /////////////////////////

'   The event log file is corrupt.
Public Const ERROR_EVENTLOG_FILE_CORRUPT = 1500&

'   No event log file could be opened, so the event logging service did not start.
Public Const ERROR_EVENTLOG_CANT_START = 1501&

'   The event log file is full.
Public Const ERROR_LOG_FILE_FULL = 1502&

'   The event log file has changed between reads.
Public Const ERROR_EVENTLOG_FILE_CHANGED = 1503&

'  End of eventlog error codes


' /////////////////////////
'                        //
'    RPC Status Codes    //
'                        //
' /////////////////////////

'   The string binding is invalid.
Public Const RPC_S_INVALID_STRING_BINDING = 1700&

'   The binding handle is not the correct type.
Public Const RPC_S_WRONG_KIND_OF_BINDING = 1701&

'   The binding handle is invalid.
Public Const RPC_S_INVALID_BINDING = 1702&

'   The RPC protocol sequence is not supported.
Public Const RPC_S_PROTSEQ_NOT_SUPPORTED = 1703&

'   The RPC protocol sequence is invalid.
Public Const RPC_S_INVALID_RPC_PROTSEQ = 1704&

'   The string universal unique identifier (UUID) is invalid.
Public Const RPC_S_INVALID_STRING_UUID = 1705&

'   The endpoint format is invalid.
Public Const RPC_S_INVALID_ENDPOINT_FORMAT = 1706&

'   The network address is invalid.
Public Const RPC_S_INVALID_NET_ADDR = 1707&

'   No endpoint was found.
Public Const RPC_S_NO_ENDPOINT_FOUND = 1708&

'   The timeout value is invalid.
Public Const RPC_S_INVALID_TIMEOUT = 1709&

'   The object universal unique identifier (UUID) was not found.
Public Const RPC_S_OBJECT_NOT_FOUND = 1710&

'   The object universal unique identifier (UUID) has already been registered.
Public Const RPC_S_ALREADY_REGISTERED = 1711&

'   The type universal unique identifier (UUID) has already been registered.
Public Const RPC_S_TYPE_ALREADY_REGISTERED = 1712&

'   The RPC server is already listening.
Public Const RPC_S_ALREADY_LISTENING = 1713&

'   No protocol sequences have been registered.
Public Const RPC_S_NO_PROTSEQS_REGISTERED = 1714&

'   The RPC server is not listening.
Public Const RPC_S_NOT_LISTENING = 1715&

'   The manager type is unknown.
Public Const RPC_S_UNKNOWN_MGR_TYPE = 1716&

'   The interface is unknown.
Public Const RPC_S_UNKNOWN_IF = 1717&

'   There are no bindings.
Public Const RPC_S_NO_BINDINGS = 1718&

'   There are no protocol sequences.
Public Const RPC_S_NO_PROTSEQS = 1719&

'   The endpoint cannot be created.
Public Const RPC_S_CANT_CREATE_ENDPOINT = 1720&

'   Not enough resources are available to complete this operation.
Public Const RPC_S_OUT_OF_RESOURCES = 1721&

'   The RPC server is unavailable.
Public Const RPC_S_SERVER_UNAVAILABLE = 1722&

'   The RPC server is too busy to complete this operation.
Public Const RPC_S_SERVER_TOO_BUSY = 1723&

'   The network options are invalid.
Public Const RPC_S_INVALID_NETWORK_OPTIONS = 1724&

'   There is not a remote procedure call active in this thread.
Public Const RPC_S_NO_CALL_ACTIVE = 1725&

'   The remote procedure call failed.
Public Const RPC_S_CALL_FAILED = 1726&

'   The remote procedure call failed and did not execute.
Public Const RPC_S_CALL_FAILED_DNE = 1727&

'   A remote procedure call (RPC) protocol error occurred.
Public Const RPC_S_PROTOCOL_ERROR = 1728&

'   The transfer syntax is not supported by the RPC server.
Public Const RPC_S_UNSUPPORTED_TRANS_SYN = 1730&

'   The universal unique identifier (UUID) type is not supported.
Public Const RPC_S_UNSUPPORTED_TYPE = 1732&

'   The tag is invalid.
Public Const RPC_S_INVALID_TAG = 1733&

'   The array bounds are invalid.
Public Const RPC_S_INVALID_BOUND = 1734&

'   The binding does not contain an entry name.
Public Const RPC_S_NO_ENTRY_NAME = 1735&

'   The name syntax is invalid.
Public Const RPC_S_INVALID_NAME_SYNTAX = 1736&

'   The name syntax is not supported.
Public Const RPC_S_UNSUPPORTED_NAME_SYNTAX = 1737&

'   No network address is available to use to construct a universal
'   unique identifier (UUID).
Public Const RPC_S_UUID_NO_ADDRESS = 1739&

'   The endpoint is a duplicate.
Public Const RPC_S_DUPLICATE_ENDPOINT = 1740&

'   The authentication type is unknown.
Public Const RPC_S_UNKNOWN_AUTHN_TYPE = 1741&

'   The maximum number of calls is too small.
Public Const RPC_S_MAX_CALLS_TOO_SMALL = 1742&

'   The string is too long.
Public Const RPC_S_STRING_TOO_LONG = 1743&

'   The RPC protocol sequence was not found.
Public Const RPC_S_PROTSEQ_NOT_FOUND = 1744&

'   The procedure number is out of range.
Public Const RPC_S_PROCNUM_OUT_OF_RANGE = 1745&

'   The binding does not contain any authentication information.
Public Const RPC_S_BINDING_HAS_NO_AUTH = 1746&

'   The authentication service is unknown.
Public Const RPC_S_UNKNOWN_AUTHN_SERVICE = 1747&

'   The authentication level is unknown.
Public Const RPC_S_UNKNOWN_AUTHN_LEVEL = 1748&

'   The security context is invalid.
Public Const RPC_S_INVALID_AUTH_IDENTITY = 1749&

'   The authorization service is unknown.
Public Const RPC_S_UNKNOWN_AUTHZ_SERVICE = 1750&

'   The entry is invalid.
Public Const EPT_S_INVALID_ENTRY = 1751&

'   The server endpoint cannot perform the operation.
Public Const EPT_S_CANT_PERFORM_OP = 1752&

'   There are no more endpoints available from the endpoint mapper.
Public Const EPT_S_NOT_REGISTERED = 1753&

'   No interfaces have been exported.
Public Const RPC_S_NOTHING_TO_EXPORT = 1754&

'   The entry name is incomplete.
Public Const RPC_S_INCOMPLETE_NAME = 1755&

'   The version option is invalid.
Public Const RPC_S_INVALID_VERS_OPTION = 1756&

'   There are no more members.
Public Const RPC_S_NO_MORE_MEMBERS = 1757&

'   There is nothing to unexport.
Public Const RPC_S_NOT_ALL_OBJS_UNEXPORTED = 1758&

'   The interface was not found.
Public Const RPC_S_INTERFACE_NOT_FOUND = 1759&

'   The entry already exists.
Public Const RPC_S_ENTRY_ALREADY_EXISTS = 1760&

'   The entry is not found.
Public Const RPC_S_ENTRY_NOT_FOUND = 1761&

'   The name service is unavailable.
Public Const RPC_S_NAME_SERVICE_UNAVAILABLE = 1762&

'   The network address family is invalid.
Public Const RPC_S_INVALID_NAF_ID = 1763&

'   The requested operation is not supported.
Public Const RPC_S_CANNOT_SUPPORT = 1764&

'   No security context is available to allow impersonation.
Public Const RPC_S_NO_CONTEXT_AVAILABLE = 1765&

'   An internal error occurred in a remote procedure call (RPC).
Public Const RPC_S_INTERNAL_ERROR = 1766&

'   The RPC server attempted an integer division by zero.'
Public Const RPC_S_ZERO_DIVIDE = 1767&

'   An addressing error occurred in the RPC server.
Public Const RPC_S_ADDRESS_ERROR = 1768&

'   A floating-point operation at the RPC server caused a division by zero.
Public Const RPC_S_FP_DIV_ZERO = 1769&

'   A floating-point underflow occurred at the RPC server.
Public Const RPC_S_FP_UNDERFLOW = 1770&

'   A floating-point overflow occurred at the RPC server.
Public Const RPC_S_FP_OVERFLOW = 1771&

'   The list of RPC servers available for the binding of auto handles
'   has been exhausted.
Public Const RPC_X_NO_MORE_ENTRIES = 1772&

'   Unable to open the character translation table file.
Public Const RPC_X_SS_CHAR_TRANS_OPEN_FAIL = 1773&

'   The file containing the character translation table has fewer than
'   512 bytes.
Public Const RPC_X_SS_CHAR_TRANS_SHORT_FILE = 1774&

'   A null context handle was passed from the client to the host during
'   a remote procedure call.
Public Const RPC_X_SS_IN_NULL_CONTEXT = 1775&

'   The context handle changed during a remote procedure call.
Public Const RPC_X_SS_CONTEXT_DAMAGED = 1777&

'   The binding handles passed to a remote procedure call do not match.
Public Const RPC_X_SS_HANDLES_MISMATCH = 1778&

'   The stub is unable to get the remote procedure call handle.
Public Const RPC_X_SS_CANNOT_GET_CALL_HANDLE = 1779&

'   A null reference pointer was passed to the stub.
Public Const RPC_X_NULL_REF_POINTER = 1780&

'   The enumeration value is out of range.
Public Const RPC_X_ENUM_VALUE_OUT_OF_RANGE = 1781&

'   The byte count is too small.
Public Const RPC_X_BYTE_COUNT_TOO_SMALL = 1782&

'   The stub received bad data.
Public Const RPC_X_BAD_STUB_DATA = 1783&

'   The supplied user buffer is not valid for the requested operation.
Public Const ERROR_INVALID_USER_BUFFER = 1784&

'   The disk media is not recognized.  It may not be formatted.
Public Const ERROR_UNRECOGNIZED_MEDIA = 1785&

'   The workstation does not have a trust secret.
Public Const ERROR_NO_TRUST_LSA_SECRET = 1786&

'   The SAM database on the Windows NT Advanced Server does not have a computer
'   account for this workstation trust relationship.
Public Const ERROR_NO_TRUST_SAM_ACCOUNT = 1787&

'   The trust relationship between the primary domain and the trusted
'   domain failed.
Public Const ERROR_TRUSTED_DOMAIN_FAILURE = 1788&

'   The trust relationship between this workstation and the primary
'   domain failed.
Public Const ERROR_TRUSTED_RELATIONSHIP_FAILURE = 1789&

'   The network logon failed.
Public Const ERROR_TRUST_FAILURE = 1790&

'   A remote procedure call is already in progress for this thread.
Public Const RPC_S_CALL_IN_PROGRESS = 1791&

'   An attempt was made to logon, but the network logon service was not started.
Public Const ERROR_NETLOGON_NOT_STARTED = 1792&

'   The user's account has expired.
Public Const ERROR_ACCOUNT_EXPIRED = 1793&

'   The redirector is in use and cannot be unloaded.
Public Const ERROR_REDIRECTOR_HAS_OPEN_HANDLES = 1794&

'   The specified printer driver is already installed.
Public Const ERROR_PRINTER_DRIVER_ALREADY_INSTALLED = 1795&

'   The specified port is unknown.
Public Const ERROR_UNKNOWN_PORT = 1796&

'   The printer driver is unknown.
Public Const ERROR_UNKNOWN_PRINTER_DRIVER = 1797&

'   The print processor is unknown.
'
Public Const ERROR_UNKNOWN_PRINTPROCESSOR = 1798&

'   The specified separator file is invalid.
Public Const ERROR_INVALID_SEPARATOR_FILE = 1799&

'   The specified priority is invalid.
Public Const ERROR_INVALID_PRIORITY = 1800&

'   The printer name is invalid.
Public Const ERROR_INVALID_PRINTER_NAME = 1801&

'   The printer already exists.
Public Const ERROR_PRINTER_ALREADY_EXISTS = 1802&

'   The printer command is invalid.
Public Const ERROR_INVALID_PRINTER_COMMAND = 1803&

'   The specified datatype is invalid.
Public Const ERROR_INVALID_DATATYPE = 1804&

'   The Environment specified is invalid.
Public Const ERROR_INVALID_ENVIRONMENT = 1805&

'   There are no more bindings.
Public Const RPC_S_NO_MORE_BINDINGS = 1806&

'   The account used is an interdomain trust account.  Use your Global user account or local user account to access this server.
Public Const ERROR_NOLOGON_INTERDOMAIN_TRUST_ACCOUNT = 1807&

'   The account used is a Computer Account.  Use your Global user account or local user account to access this server.
Public Const ERROR_NOLOGON_WORKSTATION_TRUST_ACCOUNT = 1808&

'   The account used is an server trust account.  Use your Global user account or local user account to access this server.
Public Const ERROR_NOLOGON_SERVER_TRUST_ACCOUNT = 1809&

'   The name or security ID (SID) of the domain specified is inconsistent
'   with the trust information for that domain.
Public Const ERROR_DOMAIN_TRUST_INCONSISTENT = 1810&

'   The server is in use and cannot be unloaded.
Public Const ERROR_SERVER_HAS_OPEN_HANDLES = 1811&

'   The specified image file did not contain a resource section.
Public Const ERROR_RESOURCE_DATA_NOT_FOUND = 1812&

'   The specified resource type can not be found in the image file.
Public Const ERROR_RESOURCE_TYPE_NOT_FOUND = 1813&

'   The specified resource name can not be found in the image file.
Public Const ERROR_RESOURCE_NAME_NOT_FOUND = 1814&

'   The specified resource language ID cannot be found in the image file.
Public Const ERROR_RESOURCE_LANG_NOT_FOUND = 1815&

'   Not enough quota is available to process this command.
Public Const ERROR_NOT_ENOUGH_QUOTA = 1816&

'   The group member was not found.
Public Const RPC_S_GROUP_MEMBER_NOT_FOUND = 1898&

'   The endpoint mapper database could not be created.
Public Const EPT_S_CANT_CREATE = 1899&

'   The object universal unique identifier (UUID) is the nil UUID.
Public Const RPC_S_INVALID_OBJECT = 1900&

'   The specified time is invalid.
Public Const ERROR_INVALID_TIME = 1901&

'   The specified Form name is invalid.
Public Const ERROR_INVALID_FORM_NAME = 1902&

'   The specified Form size is invalid
Public Const ERROR_INVALID_FORM_SIZE = 1903&

'   The specified Printer handle is already being waited on
Public Const ERROR_ALREADY_WAITING = 1904&

'   The specified Printer has been deleted
Public Const ERROR_PRINTER_DELETED = 1905&

'   The state of the Printer is invalid
Public Const ERROR_INVALID_PRINTER_STATE = 1906&

'   The list of servers for this workgroup is not currently available
Public Const ERROR_NO_BROWSER_SERVERS_FOUND = 6118&
