Const
  OPEN_MPI            = 1;
  
  MPI_VERSION         = 3;
  MPI_SUBVERSION      = 1;
  
  OMPI_MAJOR_VERSION  = 4;
  OMPI_MINOR_VERSION  = 0;
  OMPI_RELEASE_VERSION= 1;
    
  MPI_COMM_NULL_F = 2;
  MPI_COMM_SELF_F = 1;
  MPI_COMM_WORLD_F= 0;

  MPI_ARGC_NULL		= PInteger(0);
  MPI_ARGV_NULL		= NIL;
  MPI_ARGVS_NULL	= NIL;
 
  
  
  MPI_ANY_SOURCE			= -1;
  MPI_PROC_NULL				= -2;                     
  MPI_ROOT				= -4;                     
  MPI_ANY_TAG				= -1;                     
  MPI_MAX_PROCESSOR_NAME		= 256;
  MPI_MAX_ERROR_STRING			= 256;  
  MPI_MAX_OBJECT_NAME			= 64;   
  MPI_MAX_LIBRARY_VERSION_STRING	= 256;
  MPI_UNDEFINED				= -32766;
  MPI_DIST_GRAPH			= 3;
  MPI_CART				= 1;
  MPI_GRAPH				= 2;
  MPI_KEYVAL_INVALID			= -1;
  MPI_UNWEIGHTED			= Pinteger(2);
  MPI_WEIGHTS_EMPTY			= Pinteger(3);
  MPI_BOTTOM				= Pointer(0);
  MPI_IN_PLACE				= Pointer(1);
  MPI_BSEND_OVERHEAD			= 128;
  MPI_MAX_INFO_KEY			= 36;
  MPI_MAX_INFO_VAL			= 256;
  MPI_ERRCODES_IGNORE			= Pinteger(0);
  MPI_MAX_PORT_NAME			= 1024;

  MPI_ORDER_C				= 0;
  MPI_ORDER_FORTRAN			= 1;

  MPI_DISTRIBUTE_BLOCK			= 0;
  MPI_DISTRIBUTE_CYCLIC			= 1;
  MPI_DISTRIBUTE_NONE			= 2;
  MPI_DISTRIBUTE_DFLT_DARG		= -1;

  MPI_MODE_CREATE			= 1;
  MPI_MODE_RDONLY			= 2;
  MPI_MODE_WRONLY			= 4;
  MPI_MODE_RDWR				= 8;
  MPI_MODE_DELETE_ON_CLOSE		= 16;
  MPI_MODE_UNIQUE_OPEN			= 32;
  MPI_MODE_EXCL				= 64;
  MPI_MODE_APPEND			= 128;
  MPI_MODE_SEQUENTIAL			= 256;

  MPI_DISPLACEMENT_CURRENT		= -54278278;

  MPI_SEEK_SET				= 600;
  MPI_SEEK_CUR				= 602;
  MPI_SEEK_END				= 604;

  MPI_MAX_DATAREP_STRING		= 128;

  MPI_MODE_NOCHECK			= 1;
  MPI_MODE_NOPRECEDE			= 2;
  MPI_MODE_NOPUT			= 4;
  MPI_MODE_NOSTORE			= 8;
  MPI_MODE_NOSUCCEED			= 16;

  MPI_LOCK_EXCLUSIVE			= 1;
  MPI_LOCK_SHARED			= 2;

  MPI_WIN_FLAVOR_CREATE			= 1;
  MPI_WIN_FLAVOR_ALLOCATE		= 2;
  MPI_WIN_FLAVOR_DYNAMIC		= 3;
  MPI_WIN_FLAVOR_SHARED			= 4;

  MPI_WIN_UNIFIED			= 0;
  MPI_WIN_SEPARATE			= 1;

  MPI_COMM_TYPE_SHARED			= 0;


// Error codes returned of functions
  MPI_SUCCESS = 0;
  MPI_ERR_BUFFER = 1;
  MPI_ERR_COUNT = 2;
  MPI_ERR_TYPE = 3;
  MPI_ERR_TAG = 4;
  MPI_ERR_COMM = 5;
  MPI_ERR_RANK = 6;
  MPI_ERR_REQUEST = 7;
  MPI_ERR_ROOT = 8;
  MPI_ERR_GROUP = 9;
  MPI_ERR_OP = 10;
  MPI_ERR_TOPOLOGY = 11;
  MPI_ERR_DIMS = 12;
  MPI_ERR_ARG = 13;
  MPI_ERR_UNKNOWN = 14;
  MPI_ERR_TRUNCATE = 15;
  MPI_ERR_OTHER = 16;
  MPI_ERR_INTERN = 17;
  MPI_ERR_IN_STATUS = 18;
  MPI_ERR_PENDING = 19;
  MPI_ERR_ACCESS = 20;
  MPI_ERR_AMODE = 21;
  MPI_ERR_ASSERT = 22;
  MPI_ERR_BAD_FILE = 23;
  MPI_ERR_BASE = 24;
  MPI_ERR_CONVERSION = 25;
  MPI_ERR_DISP = 26;
  MPI_ERR_DUP_DATAREP = 27;
  MPI_ERR_FILE_EXISTS = 28;
  MPI_ERR_FILE_IN_USE = 29;
  MPI_ERR_FILE = 30;
  MPI_ERR_INFO_KEY = 31;
  MPI_ERR_INFO_NOKEY = 32;
  MPI_ERR_INFO_VALUE = 33;
  MPI_ERR_INFO = 34;
  MPI_ERR_IO = 35;
  MPI_ERR_KEYVAL = 36;
  MPI_ERR_LOCKTYPE = 37;
  MPI_ERR_NAME = 38;
  MPI_ERR_NO_MEM = 39;
  MPI_ERR_NOT_SAME = 40;
  MPI_ERR_NO_SPACE = 41;
  MPI_ERR_NO_SUCH_FILE = 42;
  MPI_ERR_PORT = 43;
  MPI_ERR_QUOTA = 44;
  MPI_ERR_READ_ONLY = 45;
  MPI_ERR_RMA_CONFLICT = 46;
  MPI_ERR_RMA_SYNC = 47;
  MPI_ERR_SERVICE = 48;
  MPI_ERR_SIZE = 49;
  MPI_ERR_SPAWN = 50;
  MPI_ERR_UNSUPPORTED_DATAREP = 51;
  MPI_ERR_UNSUPPORTED_OPERATION = 52;
  MPI_ERR_WIN = 53;

  MPI_T_ERR_MEMORY = 54;
  MPI_T_ERR_NOT_INITIALIZED = 55;
  MPI_T_ERR_CANNOT_INIT = 56;
  MPI_T_ERR_INVALID_INDEX = 57;
  MPI_T_ERR_INVALID_ITEM = 58;
  MPI_T_ERR_INVALID_HANDLE = 59;
  MPI_T_ERR_OUT_OF_HANDLES = 60;
  MPI_T_ERR_OUT_OF_SESSIONS = 61;
  MPI_T_ERR_INVALID_SESSION = 62;
  MPI_T_ERR_CVAR_SET_NOT_NOW = 63;
  MPI_T_ERR_CVAR_SET_NEVER = 64;
  MPI_T_ERR_PVAR_NO_STARTSTOP = 65;
  MPI_T_ERR_PVAR_NO_WRITE = 66;
  MPI_T_ERR_PVAR_NO_ATOMIC = 67;

  MPI_ERR_RMA_RANGE = 68;
  MPI_ERR_RMA_ATTACH = 69;
  MPI_ERR_RMA_FLAVOR = 70;
  MPI_ERR_RMA_SHARED = 71;
  MPI_T_ERR_INVALID = 72;
  MPI_T_ERR_INVALID_NAME = 73;
  MPI_ERR_LASTCODE = 92;
  
 
  MPI_CONVERSION_FN_NULL = NIL;
  
  // Datatype
  MPI_DATATYPE_NULL_F = 0;

  // C
  MPI_CHAR_F = 34;
  MPI_BYTE_F = 1;
  MPI_SHORT_F = 37;
  MPI_INT_F = 39;
  MPI_LONG_F = 41;
  MPI_LONG_LONG_INT_F = 43;
  MPI_FLOAT_F = 45;
  MPI_DOUBLE_F = 46;

  // Fortran
  MPI_CHARACTER_F = 5;
  MPI_LOGICAL_F = 6;
  MPI_INTEGER_F = 7;
  MPI_REAL_F = 13;
  MPI_DOUBLE_PRECISION_F = 17;
  MPI_COMPLEX_F = 18;

  MPI_2COMPLEX_F = 26;
  MPI_2DOUBLE_COMPLEX_F = 27;
  MPI_2DOUBLE_PRECISION_F = 24;
  MPI_2INT_F = 52;
  MPI_2INTEGER_F = 25;
  MPI_2REAL_F = 23;
  MPI_AINT_F = 66;

  
    
  MPI_COMPLEX8_F = 19;
  MPI_COMPLEX16_F = 20;
  MPI_COMPLEX32_F = 21;
  
  MPI_CXX_BOOL_F = 54;
  MPI_CXX_COMPLEX_F = 55;
  MPI_CXX_DOUBLE_COMPLEX_F = 56;
  MPI_CXX_FLOAT_COMPLEX_F = 55;
  MPI_CXX_LONG_DOUBLE_COMPLEX_F = 57;
  MPI_C_BOOL_F = 68;
  MPI_C_COMPLEX_F = 69;
  MPI_C_DOUBLE_COMPLEX_F = 70;
  MPI_C_FLOAT_COMPLEX_F = 69;
  MPI_C_LONG_DOUBLE_COMPLEX_F = 71;
  
  MPI_DOUBLE_COMPLEX_F = 22;
  MPI_DOUBLE_INT_F = 49;
  
  
  MPI_FLOAT_INT_F = 48;
  

  MPI_INT8_T_F = 58;
  MPI_INT16_T_F = 60;
  MPI_INT32_T_F = 62;
  MPI_INT64_T_F = 64;
  MPI_UINT16_T_F = 61;
  MPI_UINT32_T_F = 63;
  MPI_UINT64_T_F = 65;
  MPI_UINT8_T_F = 59;
  
  
  MPI_INTEGER1_F = 8;
  MPI_INTEGER2_F = 9;
  MPI_INTEGER4_F = 10;
  MPI_INTEGER8_F = 11;
  MPI_INTEGER16_F = 12;
  
  MPI_LOGICAL1_F = 29;
  MPI_LOGICAL2_F = 30;
  MPI_LOGICAL4_F = 31;
  MPI_LOGICAL8_F = 32;
  
  MPI_LONG_DOUBLE_F = 47;
  MPI_LONG_DOUBLE_INT_F = 50;
  MPI_LONG_INT_F = 51;
  MPI_LONG_LONG_F = 43;
  
  
  MPI_REAL2_F = 28;
  MPI_REAL4_F = 14;
  MPI_REAL8_F = 15;
  MPI_REAL16_F = 16;
  
  MPI_SHORT_INT_F = 53;
  MPI_SIGNED_CHAR_F = 36;
  MPI_UNSIGNED_F = 40;
  MPI_UNSIGNED_CHAR_F = 35;
  MPI_UNSIGNED_LONG_F = 42;
  MPI_UNSIGNED_LONG_LONG_F = 44;
  MPI_UNSIGNED_SHORT_F = 38;
  MPI_WCHAR_F = 33;


  // Operations
  MPI_MAX_F = 1;	// maximum
  MPI_MIN_F = 2;	// minimum
  MPI_SUM_F = 3;          // sum
  MPI_PROD_F = 4;         // product
  MPI_BAND_F = 6;         // bit-wise and
  MPI_LAND_F = 5;         // logical and
  MPI_BOR_F = 8;          // bit-wise or
  MPI_LOR_F = 7;          // logical or
  MPI_BXOR_F = 10;        // bit-wise xor
  MPI_LXOR_F = 9;         // logical xor
  MPI_MAXLOC_F = 11;      // max value and his location
  MPI_MINLOC_F = 12;      // min value and his location
  MPI_REPLACE_F = 13;
  MPI_NO_OP_F = 14;

  
{
  MPI_GROUP_EMPTY_F = 1;
  MPI_GROUP_NULL_F = 0;
  MPI_INFO_ENV_F = 1;
  MPI_INFO_NULL_F = 0;


  MPI_LB_F = 4;
  MPI_ERRHANDLER_NULL_F = 0;
  MPI_COUNT_F = 72;
  
  MPI_ERRORS_ARE_FATAL_F = 1;
  MPI_ERRORS_RETURN_F = 2;
  
}

 // MPI_Init_thread constants
  MPI_THREAD_SINGLE = 0;
  MPI_THREAD_FUNNELED = 1;
  MPI_THREAD_SERIALIZED = 2;
  MPI_THREAD_MULTIPLE = 3;
