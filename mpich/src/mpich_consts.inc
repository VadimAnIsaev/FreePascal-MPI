{*********************************************
 Headers of MPI (library MPICH) for FreePascal.
 Constants module.
  
 Copyright (C) 2019 by Vadim Isaev.

 This program is free software; you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation; either version 2 of the License, or
 (at your option) any later version.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

 *********************************************}

Const

   NO_TAGS_WITH_MODIFIERS = 1;

{ Results of the compare operations. }
   MPI_IDENT           = 0;
   MPI_CONGRUENT       = 1;
   MPI_SIMILAR         = 2;
   MPI_UNEQUAL         = 3;


{ Define some null objects }
   MPI_COMM_NULL       = TMPI_Comm($04000000);
   MPI_OP_NULL         = TMPI_Op($18000000);
   MPI_GROUP_NULL      = TMPI_Group($08000000);
   MPI_DATATYPE_NULL   = TMPI_Datatype($0c000000);
   MPI_REQUEST_NULL    = TMPI_Request($2c000000);
   MPI_ERRHANDLER_NULL = TMPI_Errhandler($14000000);
   MPI_MESSAGE_NULL    = TMPI_Message($2c000000);
   MPI_MESSAGE_NO_PROC = TMPI_Message($6c000000);

{Datatypes}
   MPI_CHAR               = TMPI_Datatype($4c000101);
   MPI_SIGNED_CHAR        = TMPI_Datatype($4c000118);
   MPI_UNSIGNED_CHAR      = TMPI_Datatype($4c000102);
   MPI_BYTE               = TMPI_Datatype($4c00010d);
   MPI_WCHAR              = TMPI_Datatype($4c00040e);
   MPI_SHORT              = TMPI_Datatype($4c000203);
   MPI_UNSIGNED_SHORT     = TMPI_Datatype($4c000204);
   MPI_INT                = TMPI_Datatype($4c000405);
   MPI_UNSIGNED           = TMPI_Datatype($4c000406);
   MPI_LONG               = TMPI_Datatype($4c000807);
   MPI_UNSIGNED_LONG      = TMPI_Datatype($4c000808);
   MPI_FLOAT              = TMPI_Datatype($4c00040a);
   MPI_DOUBLE             = TMPI_Datatype($4c00080b);
   MPI_LONG_DOUBLE        = TMPI_Datatype($4c00100c);
   MPI_LONG_LONG_INT      = TMPI_Datatype($4c000809);
   MPI_UNSIGNED_LONG_LONG = TMPI_Datatype($4c000819);
   MPI_LONG_LONG          = MPI_LONG_LONG_INT;

   MPI_PACKED             = TMPI_Datatype($4c00010f);
   MPI_LB                 = TMPI_Datatype($4c000010);
   MPI_UB                 = TMPI_Datatype($4c000011);
 
   MPI_FLOAT_INT         = TMPI_Datatype($8c000000);
   MPI_DOUBLE_INT        = TMPI_Datatype($8c000001);
   MPI_LONG_INT          = TMPI_Datatype($8c000002);
   MPI_SHORT_INT         = TMPI_Datatype($8c000003);
   MPI_2INT              = TMPI_Datatype($4c000816);
   MPI_LONG_DOUBLE_INT   = TMPI_Datatype($8c000004);

{ Fortran types }
   MPI_COMPLEX           = TMPI_Datatype(1275070494);
   MPI_DOUBLE_COMPLEX    = TMPI_Datatype(1275072546);
   MPI_LOGICAL           = TMPI_Datatype(1275069469);
   MPI_REAL              = TMPI_Datatype(1275069468);
   MPI_DOUBLE_PRECISION  = TMPI_Datatype(1275070495);
   MPI_INTEGER           = TMPI_Datatype(1275069467);
   MPI_2INTEGER          = TMPI_Datatype(1275070496);

   MPI_2COMPLEX          = TMPI_Datatype(1275072548);
   MPI_2DOUBLE_COMPLEX   = TMPI_Datatype(1275076645);
   MPI_2REAL             = TMPI_Datatype(1275070497);
   MPI_2DOUBLE_PRECISION = TMPI_Datatype(1275072547);
   MPI_CHARACTER         = TMPI_Datatype(1275068698);

{ Size-specific types (see MPI-2, 10.2.5) }
   MPI_REAL4             = TMPI_Datatype($4c000427);
   MPI_REAL8             = TMPI_Datatype($4c000829);
   MPI_REAL16            = TMPI_Datatype($4c00102b);
   MPI_COMPLEX8          = TMPI_Datatype($4c000828);
   MPI_COMPLEX16         = TMPI_Datatype($4c00102a);
   MPI_COMPLEX32         = TMPI_Datatype($4c00202c);
   MPI_INTEGER1          = TMPI_Datatype($4c00012d);
   MPI_INTEGER2          = TMPI_Datatype($4c00022f);
   MPI_INTEGER4          = TMPI_Datatype($4c000430);
   MPI_INTEGER8          = TMPI_Datatype($4c000831);
   MPI_INTEGER16         = MPI_DATATYPE_NULL;

{ C99 fixed-width datatypes }
   MPI_INT8_T            = TMPI_Datatype($4c000137);
   MPI_INT16_T           = TMPI_Datatype($4c000238);
   MPI_INT32_T           = TMPI_Datatype($4c000439);
   MPI_INT64_T           = TMPI_Datatype($4c00083a);
   MPI_UINT8_T           = TMPI_Datatype($4c00013b);
   MPI_UINT16_T          = TMPI_Datatype($4c00023c);
   MPI_UINT32_T          = TMPI_Datatype($4c00043d);
   MPI_UINT64_T          = TMPI_Datatype($4c00083e);

{ other C99 types }
   MPI_C_BOOL                 = TMPI_Datatype($4c00013f);
   MPI_C_FLOAT_COMPLEX        = TMPI_Datatype($4c000840);
   MPI_C_COMPLEX              = MPI_C_FLOAT_COMPLEX;
   MPI_C_DOUBLE_COMPLEX       = TMPI_Datatype($4c001041);
   MPI_C_LONG_DOUBLE_COMPLEX  = TMPI_Datatype($4c002042);

{ address/offset types }
   MPI_AINT                   = TMPI_Datatype($4c000843);
   MPI_OFFSET                 = TMPI_Datatype($4c000844);
   MPI_COUNT                  = TMPI_Datatype($4c000845);

{ MPI-3 C++ types }
   MPI_CXX_BOOL                = TMPI_Datatype($4c000133);
   MPI_CXX_FLOAT_COMPLEX       = TMPI_Datatype($4c000834);
   MPI_CXX_DOUBLE_COMPLEX      = TMPI_Datatype($4c001035);
   MPI_CXX_LONG_DOUBLE_COMPLEX = TMPI_Datatype($4c002036);

{ typeclasses }
   MPI_TYPECLASS_REAL          = 1;
   MPI_TYPECLASS_INTEGER       = 2;
   MPI_TYPECLASS_COMPLEX       = 3;

{ Communicators }
   MPI_COMM_WORLD = TMPI_Comm($44000000);
   MPI_COMM_SELF  = TMPI_Comm($44000001);

{ Groups }
   MPI_GROUP_EMPTY = TMPI_Group($48000000);

{ RMA and Windows }
   MPI_WIN_NULL    = TMPI_Win($20000000);

{ Collective operations }
   MPI_MAX       = TMPI_Op($58000001);
   MPI_MIN       = TMPI_Op($58000002);
   MPI_SUM       = TMPI_Op($58000003);
   MPI_PROD      = TMPI_Op($58000004);
   MPI_LAND      = TMPI_Op($58000005);
   MPI_BAND      = TMPI_Op($58000006);
   MPI_LOR       = TMPI_Op($58000007);
   MPI_BOR       = TMPI_Op($58000008);
   MPI_LXOR      = TMPI_Op($58000009);
   MPI_BXOR      = TMPI_Op($5800000a);
   MPI_MINLOC    = TMPI_Op($5800000b);
   MPI_MAXLOC    = TMPI_Op($5800000c);
   MPI_REPLACE   = TMPI_Op($5800000d);
   MPI_NO_OP     = TMPI_Op($5800000e);

{ Permanent key values }
   MPI_TAG_UB           = $64400001;
   MPI_HOST             = $64400003;
   MPI_IO               = $64400005;
   MPI_WTIME_IS_GLOBAL  = $64400007;
   MPI_UNIVERSE_SIZE    = $64400009;
   MPI_LASTUSEDCODE     = $6440000b;
   MPI_APPNUM           = $6440000d;

{ In addition, there are 5 predefined window attributes that are
defined for every window }
   MPI_WIN_BASE          = $66000001;
   MPI_WIN_SIZE          = $66000003;
   MPI_WIN_DISP_UNIT     = $66000005;
   MPI_WIN_CREATE_FLAVOR = $66000007;
   MPI_WIN_MODEL         = $66000009;

{ These are only guesses; make sure you change them in mpif.h as well }
   MPI_MAX_PROCESSOR_NAME         = 128;
   MPI_MAX_LIBRARY_VERSION_STRING = 8192;
   MPI_MAX_ERROR_STRING           = 512;
   MPI_MAX_PORT_NAME              = 256;
   MPI_MAX_OBJECT_NAME            = 128;

{ Pre-defined constants }
   MPI_UNDEFINED                  = -32766;
   MPI_KEYVAL_INVALID             = $24000000;

{ MPI-3 window flavors }
{ MPI-3 window consistency models }
{ Upper bound on the overhead in bsend for each message buffer }
   MPI_BSEND_OVERHEAD             = 96;

{ Topology types }
   MPI_BOTTOM          = NIL;
   MPI_PROC_NULL       = -1;
   MPI_ANY_SOURCE      = -2;
   MPI_ROOT            = -3;
   MPI_ANY_TAG         = -1;
   MPI_LOCK_EXCLUSIVE  = 234;
   MPI_LOCK_SHARED     = 235;

   MPI_ERRORS_ARE_FATAL = TMPI_Errhandler($54000000);
   MPI_ERRORS_RETURN    = TMPI_Errhandler($54000001);

{ MPIR_ERRORS_THROW_EXCEPTIONS is not part of the MPI standard, it is here to
   facilitate the c++ binding which has MPI::ERRORS_THROW_EXCEPTIONS. 
   Using the MPIR prefix preserved the MPI_ names for objects defined by
   the standard. }
   MPIR_ERRORS_THROW_EXCEPTIONS = TMPI_Errhandler($54000002);

{ Make the C names for the dup function mixed case.}
{ MPI 1 names }
   MPI_NULL_COPY_FN        = NIL;
   MPI_NULL_DELETE_FN      = NIL;

{ MPI 2 names }
   MPI_COMM_NULL_COPY_FN   = NIL;
   MPI_COMM_NULL_DELETE_FN = NIL;
   
   MPI_WIN_NULL_COPY_FN    = NIL;
   MPI_WIN_NULL_DELETE_FN  = NIL;
   MPI_TYPE_NULL_COPY_FN   = NIL;
   MPI_TYPE_NULL_DELETE_FN = NIL;
   
//   MPI_COMM_DUP_FN         = TMPI_Comm_copy_attr_function(MPI_DUP_FN);
//   MPI_WIN_DUP_FN          = TMPI_Win_copy_attr_function(MPI_DUP_FN);
//   MPI_TYPE_DUP_FN         = TPMPI_Type_copy_attr_function(MPI_DUP_FN);

   MPI_VERSION    = 3;
   MPI_SUBVERSION = 1;
   MPICH_NAME     = 3;
//   MPICH          = 1;
   MPICH_HAS_C2F  = 1;

{ MPICH_VERSION is the version string. MPICH_NUMVERSION is the
   MPICH_VERSION "3.3"
   MPICH_NUMVERSION 30201300
   MPICH_RELEASE_TYPE_ALPHA  0
   MPICH_RELEASE_TYPE_BETA   1
   MPICH_RELEASE_TYPE_RC     2
   MPICH_RELEASE_TYPE_PATCH  3
   MPICH_CALC_VERSION(MAJOR, MINOR, REVISION, TYPE, PATCH) \
   (((MAJOR) * 10000000) + ((MINOR) * 100000) + ((REVISION) * 1000) + ((TYPE) * 100) + (PATCH))
}
   
{ for the datatype decoders }
{ for info }
   MPI_INFO_NULL            = TMPI_Info($1c000000);
   MPI_INFO_ENV             = TMPI_Info($5c000001);
   MPI_MAX_INFO_KEY         = 255;
   MPI_MAX_INFO_VAL         = 1024;

{ for subarray and darray constructors }
   MPI_ORDER_C              = 56;
   MPI_ORDER_FORTRAN        = 57;
   MPI_DISTRIBUTE_BLOCK     = 121;
   MPI_DISTRIBUTE_CYCLIC    = 122;
   MPI_DISTRIBUTE_NONE      = 123;
   MPI_DISTRIBUTE_DFLT_DARG = -49767;
   MPI_IN_PLACE             = Pointer(-1);

{ asserts for one-sided communication }
   MPI_MODE_NOCHECK         = 1024;
   MPI_MODE_NOSTORE         = 2048;
   MPI_MODE_NOPUT           = 4096;
   MPI_MODE_NOPRECEDE       = 8192;
   MPI_MODE_NOSUCCEED       = 16384;

{ predefined types for MPI_Comm_split_type }
   MPI_COMM_TYPE_SHARED     = 1;

   MPI_STATUS_IGNORE    = PMPI_Status(1);
   MPI_STATUSES_IGNORE  = PMPI_Status(1);
   MPI_ERRCODES_IGNORE  = NIL;

{ The MPI standard requires that the ARGV_NULL values be the same as
   NULL (see 5.3.2) }
   MPI_ARGV_NULL   = NIL;
   MPI_ARGVS_NULL  = NIL;

{  For supported thread levels }
   MPI_THREAD_SINGLE     = 0;
   MPI_THREAD_FUNNELED   = 1;
   MPI_THREAD_SERIALIZED = 2;
   MPI_THREAD_MULTIPLE   = 3;

{ MPI's error classes }
   MPI_SUCCESS          = 0;      { Successful return code }
{ Communication argument parameters }
   MPI_ERR_BUFFER       = 1;      { Invalid buffer pointer }
   MPI_ERR_COUNT        = 2;      { Invalid count argument }
   MPI_ERR_TYPE         = 3;      { Invalid datatype argument }
   MPI_ERR_TAG          = 4;      { Invalid tag argument }
   MPI_ERR_COMM         = 5;       { Invalid communicator }
   MPI_ERR_RANK         = 6;      { Invalid rank }
   MPI_ERR_ROOT         = 7;      { Invalid root }
   MPI_ERR_TRUNCATE     = 14;      { Message truncated on receive }
{ MPI Objects (other than COMM) }
   MPI_ERR_GROUP        = 8;      { Invalid group }
   MPI_ERR_OP           = 9;      { Invalid operation }
   MPI_ERR_REQUEST      = 19;      { Invalid mpi_request handle }
{ Special topology argument parameters }
   MPI_ERR_TOPOLOGY     = 10;      { Invalid topology }
   MPI_ERR_DIMS         = 11;      { Invalid dimension argument }
{ All other arguments.  This is a class with many kinds }
   MPI_ERR_ARG          = 12;      { Invalid argument }
{ Other errors that are not simply an invalid argument }
   MPI_ERR_OTHER        = 15;      { Other error; use Error_string }
   MPI_ERR_UNKNOWN      = 13;      { Unknown error }
   MPI_ERR_INTERN       = 16;      { Internal error code    }
{ Multiple completion has three special error classes }
   MPI_ERR_IN_STATUS    = 17;      { Look in status for error value }
   MPI_ERR_PENDING      = 18;      { Pending request }
{ New MPI-2 Error classes }
   MPI_ERR_ACCESS       = 20;      { }
   MPI_ERR_AMODE        = 21;      { }
   MPI_ERR_BAD_FILE     = 22;      { }
   MPI_ERR_CONVERSION   = 23;      { }
   MPI_ERR_DUP_DATAREP  = 24;      { }
   MPI_ERR_FILE_EXISTS  = 25;      { }
   MPI_ERR_FILE_IN_USE  = 26;      { }
   MPI_ERR_FILE         = 27;      { }
   MPI_ERR_IO           = 32;      { }
   MPI_ERR_NO_SPACE     = 36;      { }
   MPI_ERR_NO_SUCH_FILE = 37;     { }
   MPI_ERR_READ_ONLY    = 40;      { }
   MPI_ERR_UNSUPPORTED_DATAREP = 43;  { }
{ MPI_ERR_INFO is NOT defined in the MPI-2 standard.  I believe that
 this is an oversight }
   MPI_ERR_INFO         = 28;      { }
   MPI_ERR_INFO_KEY     = 29;      { }
   MPI_ERR_INFO_VALUE   = 30;      { }
   MPI_ERR_INFO_NOKEY   = 31;      { }
   MPI_ERR_NAME         = 33;      { }
   MPI_ERR_NO_MEM       = 34;      { Alloc_mem could not allocate memory }
   MPI_ERR_NOT_SAME     = 35;      { }
   MPI_ERR_PORT         = 38;      { }
   MPI_ERR_QUOTA        = 39;      { }
   MPI_ERR_SERVICE      = 41;      { }
   MPI_ERR_SPAWN        = 42;     { }
   MPI_ERR_UNSUPPORTED_OPERATION = 44; { }
   MPI_ERR_WIN          = 45;      { }
   MPI_ERR_BASE         = 46;      { }
   MPI_ERR_LOCKTYPE     = 47;      { }
   MPI_ERR_KEYVAL       = 48;      { Erroneous attribute key }
   MPI_ERR_RMA_CONFLICT = 49;     { }
   MPI_ERR_RMA_SYNC     = 50;      { } 
   MPI_ERR_SIZE         = 51;      { }
   MPI_ERR_DISP         = 52;      { }
   MPI_ERR_ASSERT       = 53;      { }
   MPI_ERR_RMA_RANGE    = 55;       { }
   MPI_ERR_RMA_ATTACH   = 56;       { }
   MPI_ERR_RMA_SHARED   = 57;       { }
   MPI_ERR_RMA_FLAVOR   = 58;       { }
   MPI_ERR_LASTCODE     = $3fffffff;  { Last valid error code for a 
						predefined error class }
						
   MPICH_ERR_LAST_CLASS = 74;     { It is also helpful to know the
				    last valid class }

{ feature advertisement }
   MPIIMPL_ADVERTISES_FEATURES         = 1;
   MPIIMPL_HAVE_MPI_INFO               = 1;                                                 
   MPIIMPL_HAVE_MPI_COMBINER_DARRAY    = 1;                                      
   MPIIMPL_HAVE_MPI_TYPE_CREATE_DARRAY = 1;
   MPIIMPL_HAVE_MPI_COMBINER_SUBARRAY  = 1;                                    
   MPIIMPL_HAVE_MPI_COMBINER_DUP       = 1;                                         
   MPIIMPL_HAVE_MPI_GREQUEST           = 1;      
   MPIIMPL_HAVE_STATUS_SET_BYTES       = 1;
   MPIIMPL_HAVE_STATUS_SET_INFO        = 1;
