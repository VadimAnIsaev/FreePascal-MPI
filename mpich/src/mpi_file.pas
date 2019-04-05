{*********************************************
 Headers of MPI (library MPICH) for FreePascal.
 Types, constants and functions for file operations.
  
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
{$mode objfpc}{$h+}
{$packrecords c}
Unit mpi_file;

interface

Uses mpi;

Type
  PMPI_File  = ^ADIOI_FileD;

Const
  MPI_MODE_RDONLY		= 2;  // ADIO_RDONLY
  MPI_MODE_RDWR			= 8;  // ADIO_RDWR  
  MPI_MODE_WRONLY		= 4;  // ADIO_WRONLY
  MPI_MODE_CREATE		= 1;  // ADIO_CREATE 
  MPI_MODE_EXCL			= 64;  // ADIO_EXCL 
  MPI_MODE_DELETE_ON_CLOSE	= 16;  // ADIO_DELETE_ON_CLOSE
  MPI_MODE_UNIQUE_OPEN		= 32;  // ADIO_UNIQUE_OPEN 
  MPI_MODE_APPEND		= 128;  // ADIO_APPEND 
  MPI_MODE_SEQUENTIAL		= 256;  // ADIO_SEQUENTIAL 

  MPI_DISPLACEMENT_CURRENT	= -54278278;
  
  MPI_FILE_NULL			= PMPI_File(0);

Type
  ADIO_Offset = valsint;
  TADIO_Offset = ADIO_Offset;
  PADIO_Offset = ^ADIO_Offset;

  PADIOI_Fns = ^ADIOI_Fns_struct;
  PADIO_File = ^ADIOI_FileD;

  ADIO_Status = TMPI_Status;
  PADIO_Status = ^TMPI_Status;
  ADIO_Request = TMPI_Request;
  PADIO_Request = ^TMPI_Request;
 
  ADIOI_RequestD = TMPI_Request;		// ????
  PMPIO_Request = ^ADIOI_RequestD;

  ADIO_Fcntl_t = packed record
    disp	: TADIO_Offset;
    etype	: TMPI_Datatype;
    filetype	: TMPI_Datatype;
    info	: TMPI_Info;
    atomicity	: integer;
    fsize	: TADIO_Offset;       
    diskspace	: TADIO_Offset;   
  end;              
  TADIO_Fcntl_t = ADIO_Fcntl_t;
  PADIO_Fcntl_t = ^TADIO_Fcntl_t;
 
  ADIOI_Fns_struct = packed record
    ADIOI_xxx_Open:  procedure(fd: PADIO_File; error_code: Pinteger);
    ADIOI_xxx_OpenColl: procedure(fd: PADIO_File; rank: integer; access_mode: integer; error_code: Pinteger);
    ADIOI_xxx_ReadContig: procedure(fd: PADIO_File; buf: Pointer; count: integer; datatype: TMPI_Datatype; file_ptr_type: integer; offset: TADIO_Offset; status: PADIO_Status; error_code: Pinteger);
    ADIOI_xxx_WriteContig: procedure(fd: PADIO_File; const buf: Pointer; count: integer; datatype: TMPI_Datatype; file_ptr_type: integer; offset: TADIO_Offset; status: PADIO_Status; error_code: Pinteger);
    ADIOI_xxx_ReadStridedColl: procedure( fd: PADIO_File; buf: Pointer; count: integer; datatype: TMPI_Datatype; file_ptr_type: integer; offset: TADIO_Offset; status: PADIO_Status; error_code: Pinteger);
    ADIOI_xxx_WriteStridedColl: procedure(fd: PADIO_File; const buf: Pointer; count: integer; datatype: TMPI_Datatype; file_ptr_type: integer; offset: TADIO_Offset; status: PADIO_Status; error_code: Pinteger);
    ADIOI_xxx_SeekIndividual: function(fd: PADIO_File; offset: ADIO_Offset; whence: integer; error_code: Pinteger): ADIO_Offset;
    ADIOI_xxx_Fcntl: procedure(fd: PADIO_File; flag: integer; fcntl_struct: PADIO_Fcntl_t; error_code: Pinteger); 
    ADIOI_xxx_SetInfo: procedure(fd: PADIO_File; users_info: TMPI_Info; error_code: Pinteger);
    ADIOI_xxx_ReadStrided: procedure(fd: PADIO_File; buf: Pointer; count: integer; datatype: TMPI_Datatype; file_ptr_type: integer; offset: ADIO_Offset; status: PADIO_Status; error_code: Pinteger);
    ADIOI_xxx_WriteStrided: procedure(fd: PADIO_File; const buf: Pointer; count: integer; datatype: TMPI_Datatype; file_ptr_type: integer; offset: ADIO_Offset; status: ADIO_Status; error_code: Pinteger);
    ADIOI_xxx_Close: procedure(fd: PADIO_File; error_code: Pinteger);
    ADIOI_xxx_IreadContig: procedure(fd: PADIO_File; buf: Pointer; count: integer; datatype: TMPI_Datatype; file_ptr_type: integer; offset: TADIO_Offset; request: PADIO_Request; error_code: Pinteger);
    ADIOI_xxx_IwriteContig: procedure(fd: PADIO_File; const buf: Pointer; count: integer; datatype: TMPI_Datatype; file_ptr_type: integer; offset: TADIO_Offset; request: PADIO_Request; error_code: Pinteger);
    ADIOI_xxx_ReadComplete: procedure(request: PADIO_Request; status: PADIO_Status; error_code: Pinteger);
    ADIOI_xxx_WriteComplete: procedure(request: PADIO_Request; status: PADIO_Status; error_code: Pinteger);
    ADIOI_xxx_ReadDone: function(request: PADIO_Request; status: PADIO_Status; error_code: Pinteger): integer;
    ADIOI_xxx_WriteDone: function(request: PADIO_Request; status: PADIO_Status; error_code: Pinteger): integer;
    ADIOI_xxx_IreadStrided: procedure(fd: PADIO_File; buf: Pointer; count: integer; datatype: TMPI_Datatype; file_ptr_type: integer; offset: TADIO_Offset; request: PADIO_Request; error_code: Pinteger);
    ADIOI_xxx_IwriteStrided: procedure(fd: PADIO_File; const buf: Pointer; count: integer; datatype: TMPI_Datatype; file_ptr_type: integer; offset: TADIO_Offset; request: PADIO_Request; error_code: Pinteger);
    ADIOI_xxx_Flush: procedure(fd: PADIO_File; error_code: Pinteger);
    ADIOI_xxx_Resize: procedure(fd: PADIO_File; size: TADIO_Offset; error_code: Pinteger);
    ADIOI_xxx_Delete: procedure(const filename: PChar; error_code: Pinteger);
    ADIOI_xxx_Feature: function(fd: PADIO_File; flag: integer): integer;
    fsname: PChar;
    ADIOI_xxx_IreadStridedColl: procedure(fd: PADIO_File; buf: Pointer; count: integer; datatype: TMPI_Datatype; file_ptr_type: integer; offset: TADIO_Offset; request: PADIO_Request; error_code: Pinteger);
    ADIOI_xxx_IwriteStridedColl: procedure(fd: PADIO_File; const buf: Pointer; count: integer; datatype: TMPI_Datatype; file_ptr_type: integer; offset: TADIO_Offset; request: PADIO_Request; error_code: Pinteger);
  end;
  ADIOI_Fns = ADIOI_Fns_struct;
  TADIOI_Fns = ADIOI_Fns_struct;

  Tpvfs = packed record
	listio_read : integer;
	listio_write: integer;
  end ;

  Tpvfs2 = packed record
	debugmask   : integer;
	posix_read  : integer;
	posix_write : integer;
	listio_read : integer;
	listio_write: integer;
	dtype_read  : integer;
	dtype_write : integer;
  end ;

  Tlustre = packed record
        start_iodevice: integer;
        co_ratio      : integer;
        coll_threshold: integer;
        ds_in_coll    : integer;
  end ;

  Txfs = packed record
	read_chunk_sz : longword; 
	write_chunk_sz: longword; 
  end ;

  Tbg = packed record
      bridgelist   : Pinteger; 
      bridgelistnum: Pinteger; 
      numbridges   : integer; 
  end;

  Tfs_hints = packed record
    Case Byte Of
     0: (pvfs: Tpvfs);
     1: (pvfs2: Tpvfs2);
     2: (lustre: Tlustre);
     3: (xfs: Txfs);
     4: (bg: Tbg);
  end;

  ADIOI_Hints_struct = packed record
    initialized		: integer;
    striping_factor	: integer;
    striping_unit	: integer;
    cb_read		: integer;
    cb_write		: integer;
    cb_nodes		: integer;
    cb_buffer_size	: integer;
    cb_pfr		: integer;
    cb_fr_type		: integer;
    cb_fr_alignment	: integer;
    cb_ds_threshold	: integer;
    cb_alltoall		: integer;
    ds_read		: integer;
    ds_write		: integer;
    no_indep_rw		: integer;
    ind_rd_buffer_size	: integer;
    ind_wr_buffer_size	: integer;
    deferred_open	: integer;
    min_fdomain_size	: integer;
    cb_config_list	: PChar;
    ranklist		: Pinteger;
    fs_hints		: Tfs_hints;
  end;
  ADIOI_Hints = ADIOI_Hints_struct;
  PADIOI_Hints = ^ADIOI_Hints;

  PADIOI_FileD = ADIOI_FileD;
  ADIOI_FileD = packed record
    cookie                   : integer;     
    fd_sys                   : integer;     
    null_fd                  : integer;     
    fd_direct                : integer;      
    direct_read              : integer;     
    direct_write             : integer;     
    d_mem                    : dword;       
    d_miniosz                : dword;       
    blksize                  : longint;     
    fp_ind                   : TADIO_Offset; 
    fp_sys_posn              : TADIO_Offset; 
    fns                      : PADIOI_Fns;  
    comm                     : integer;     
    is_open                  : integer;	    
    is_agg                   : integer;     
    filename                 : PChar;          
    file_system              : integer;     
    access_mode              : integer;     
    orig_access_mode         : integer;     
    disp                     : TADIO_Offset; 
    etype                    : integer;     
    filetype                 : integer;     
    etype_size               : int64;       
    hints                    : PADIOI_Hints;
    info                     : integer;
    split_coll_count         : integer;     
    split_status             : TMPI_Status;  
    split_datatype           : integer;     
    shared_fp_fname          : PChar;       
    shared_fp_fd             : PADIOI_FileD;
    async_count              : integer;     
    perm                     : integer;
    atomicity                : integer;     
    fortran_handle           : integer;     
    err_handler              : integer;
    fs_ptr                   : Pointer;     
    file_realm_st_offs       : PADIO_Offset;
    file_realm_types         : Pinteger;    
    my_cb_nodes_index        : integer;     
    io_buf                   : PChar;       
    io_buf_window            : integer;     
    io_buf_put_amounts       : Pinteger;    
    io_buf_put_amounts_window: integer;     
    is_external32            : integer;     
  end;

  MPI_File_errhandler_function	= procedure( p1: PMPI_File; p2: Pinteger; args: array of const );
  PMPI_File_errhandler_function	= MPI_File_errhandler_function;
  MPI_File_errhandler_fn	= MPI_File_errhandler_function;
  PMPI_File_errhandler_fn	= MPI_File_errhandler_fn;  

  
  function MPI_File_call_errhandler(fh: PMPI_File; errorcode: integer): integer; cdecl; external LIBMPI name 'MPI_File_call_errhandler';
  function MPI_File_close(fh: PMPI_File): integer; cdecl; external LIBMPI name 'MPI_File_close';
  function MPI_File_create_errhandler(file_errhandler_fn: PMPI_File_errhandler_function; errhandler: PMPI_Errhandler): integer; cdecl; external LIBMPI name 'MPI_File_create_errhandler';
  function MPI_File_delete(const filename: PChar; info: TMPI_Info): integer; cdecl; external LIBMPI name 'MPI_File_delete';
  function MPI_File_get_amode(fh: PMPI_File; amode: Pinteger): integer; cdecl; external LIBMPI name 'MPI_File_get_amode';
  function MPI_File_get_atomicity(fh: PMPI_File; flag: Pinteger): integer; cdecl; external LIBMPI name 'MPI_File_get_atomicity';
  function MPI_File_get_byte_offset(fh: PMPI_File; offset: TMPI_Offset; disp: PMPI_Offset): integer; cdecl; external LIBMPI name 'MPI_File_get_byte_offset';
  function MPI_File_get_errhandler(fh: PMPI_File; errhandler: PMPI_Errhandler): integer; cdecl; external LIBMPI name 'MPI_File_get_errhandler';
  function MPI_File_get_group(fh: PMPI_File; group: PMPI_Group): integer; cdecl; external LIBMPI name 'MPI_File_get_group';
  function MPI_File_get_info(fh: PMPI_File; info_used: PMPI_Info): integer; cdecl; external LIBMPI name 'MPI_File_get_info';
  function MPI_File_get_position(fh: PMPI_File; offset: PMPI_Offset): integer; cdecl; external LIBMPI name 'MPI_File_get_position';
  function MPI_File_get_position_shared(fh: PMPI_File; offset: PMPI_Offset): integer; cdecl; external LIBMPI name 'MPI_File_get_position_shared';
  function MPI_File_get_size(fh: PMPI_File; size: PMPI_Offset): integer; cdecl; external LIBMPI name 'MPI_File_get_size';
  function MPI_File_get_type_extent(fh: PMPI_File; datatype: TMPI_Datatype; extent: PMPI_Aint): integer; cdecl; external LIBMPI name 'MPI_File_get_type_extent';
  function MPI_File_get_view(fh: PMPI_File; disp: PMPI_Offset; etype: PMPI_Datatype; filetype: PMPI_Datatype; datarep: PChar): integer; cdecl; external LIBMPI name 'MPI_File_get_view';
  function MPI_File_iread(fh: PMPI_File; buf: Pointer; count: integer; datatype: TMPI_Datatype; request: PMPIO_Request): integer; cdecl; external LIBMPI name 'MPI_File_iread';
  function MPI_File_iread_all(fh: PMPI_File; buf: Pointer; count: integer; datatype: TMPI_Datatype; request: PMPI_Request): integer; cdecl; external LIBMPI name 'MPI_File_iread_all';
  function MPI_File_iread_at(fh: PMPI_File; offset: TMPI_Offset; buf: Pointer; count: integer; datatype: TMPI_Datatype; request: PMPIO_Request): integer; cdecl; external LIBMPI name 'MPI_File_iread_at';
  function MPI_File_iread_at_all(fh: PMPI_File; offset: TMPI_Offset; buf: Pointer; count: integer; datatype: TMPI_Datatype; request: PMPI_Request): integer; cdecl; external LIBMPI name 'MPI_File_iread_at_all';
  function MPI_File_iread_shared(fh: PMPI_File; buf: Pointer; count: integer; datatype: TMPI_Datatype; request: PMPIO_Request): integer; cdecl; external LIBMPI name 'MPI_File_iread_shared';
  function MPI_File_iwrite(fh: PMPI_File; const buf: Pointer; count: integer; datatype: TMPI_Datatype; request: PMPIO_Request): integer; cdecl; external LIBMPI name 'MPI_File_iwrite';
  function MPI_File_iwrite_all(fh: PMPI_File; const buf: Pointer; count: integer; datatype: TMPI_Datatype; request: PMPI_Request): integer; cdecl; external LIBMPI name 'MPI_File_iwrite_all';
  function MPI_File_iwrite_at(fh: PMPI_File; offset: TMPI_Offset; const buf: Pointer; count: integer; datatype: TMPI_Datatype; request: PMPIO_Request): integer; cdecl; external LIBMPI name 'MPI_File_iwrite_at';
  function MPI_File_iwrite_at_all(fh: PMPI_File; offset: TMPI_Offset; const buf: Pointer; count: integer; datatype: TMPI_Datatype; request: PMPI_Request): integer; cdecl; external LIBMPI name 'MPI_File_iwrite_at_all';
  function MPI_File_iwrite_shared(fh: PMPI_File; const buf: Pointer; count: integer; datatype: TMPI_Datatype; request: PMPIO_Request): integer; cdecl; external LIBMPI name 'MPI_File_iwrite_shared';
  function MPI_File_open(comm: TMPI_Comm; const filename: PChar; amode: integer; info: TMPI_Info; fh: PMPI_File): integer; cdecl; external LIBMPI name 'MPI_File_open';
  function MPI_File_preallocate(fh: PMPI_File; size: TMPI_Offset): integer; cdecl; external LIBMPI name 'MPI_File_preallocate';
  function MPI_File_read(fh: PMPI_File; buf: Pointer; count: integer; datatype: TMPI_Datatype; status: PMPI_Status): integer; cdecl; external LIBMPI name 'MPI_File_read';
  function MPI_File_read_all(fh: PMPI_File; buf: Pointer; count: integer; datatype: TMPI_Datatype; status: PMPI_Status): integer; cdecl; external LIBMPI name 'MPI_File_read_all';
  function MPI_File_read_all_begin(fh: PMPI_File; buf: Pointer; count: integer; datatype: TMPI_Datatype): integer; cdecl; external LIBMPI name 'MPI_File_read_all_begin';
  function MPI_File_read_all_end(fh: PMPI_File; buf: Pointer; status: PMPI_Status): integer; cdecl; external LIBMPI name 'MPI_File_read_all_end';
  function MPI_File_read_at(fh: PMPI_File; offset: TMPI_Offset; buf: Pointer; count: integer; datatype: TMPI_Datatype; status: PMPI_Status): integer; cdecl; external LIBMPI name 'MPI_File_read_at';
  function MPI_File_read_at_all(fh: PMPI_File; offset: TMPI_Offset; buf: Pointer; count: integer; datatype: TMPI_Datatype; status: PMPI_Status): integer; cdecl; external LIBMPI name 'MPI_File_read_at_all';
  function MPI_File_read_at_all_begin(fh: PMPI_File; offset: TMPI_Offset; buf: Pointer; count: integer; datatype: TMPI_Datatype): integer; cdecl; external LIBMPI name 'MPI_File_read_at_all_begin';
  function MPI_File_read_at_all_end(fh: PMPI_File; buf: Pointer; status: PMPI_Status): integer; cdecl; external LIBMPI name 'MPI_File_read_at_all_end';
  function MPI_File_read_ordered(fh: PMPI_File; buf: Pointer; count: integer; datatype: TMPI_Datatype; status: PMPI_Status): integer; cdecl; external LIBMPI name 'MPI_File_read_ordered';
  function MPI_File_read_ordered_begin(fh: PMPI_File; buf: Pointer; count: integer; datatype: TMPI_Datatype): integer; cdecl; external LIBMPI name 'MPI_File_read_ordered_begin';
  function MPI_File_read_ordered_end(fh: PMPI_File; buf: Pointer; status: PMPI_Status): integer; cdecl; external LIBMPI name 'MPI_File_read_ordered_end';
  function MPI_File_read_shared(fh: PMPI_File; buf: Pointer; count: integer; datatype: TMPI_Datatype; status: PMPI_Status): integer; cdecl; external LIBMPI name 'MPI_File_read_shared';
  function MPI_File_seek(fh: PMPI_File; offset: TMPI_Offset; whence: integer): integer; cdecl; external LIBMPI name 'MPI_File_seek';
  function MPI_File_seek_shared(fh: PMPI_File; offset: TMPI_Offset; whence: integer): integer; cdecl; external LIBMPI name 'MPI_File_seek_shared';
  function MPI_File_set_atomicity(fh: PMPI_File; flag: integer): integer; cdecl; external LIBMPI name 'MPI_File_set_atomicity';
  function MPI_File_set_errhandler(fh: PMPI_File; errhandler: TMPI_Errhandler): integer; cdecl; external LIBMPI name 'MPI_File_set_errhandler';
  function MPI_File_set_info(fh: PMPI_File; info: TMPI_Info): integer; cdecl; external LIBMPI name 'MPI_File_set_info';
  function MPI_File_set_size(fh: PMPI_File; size: TMPI_Offset): integer; cdecl; external LIBMPI name 'MPI_File_set_size';
  function MPI_File_set_view(fh: PMPI_File; disp: TMPI_Offset; etype: TMPI_Datatype; filetype: TMPI_Datatype; const datarep: PChar; info: TMPI_Info): integer; cdecl; external LIBMPI name 'MPI_File_set_view';
  function MPI_File_sync(fh: PMPI_File): integer; cdecl; external LIBMPI name 'MPI_File_sync';
  function MPI_File_write(fh: PMPI_File; const buf: Pointer; count: integer; datatype: TMPI_Datatype; status: PMPI_Status): integer; cdecl; external LIBMPI name 'MPI_File_write';
  function MPI_File_write_all(fh: PMPI_File; const buf: Pointer; count: integer; datatype: TMPI_Datatype; status: PMPI_Status): integer; cdecl; external LIBMPI name 'MPI_File_write_all';
  function MPI_File_write_all_begin(fh: PMPI_File; const buf: Pointer; count: integer; datatype: TMPI_Datatype): integer; cdecl; external LIBMPI name 'MPI_File_write_all_begin';
  function MPI_File_write_all_end(fh: PMPI_File; const buf: Pointer; status: PMPI_Status): integer; cdecl; external LIBMPI name 'MPI_File_write_all_end';
  function MPI_File_write_at(fh: PMPI_File; offset: TMPI_Offset; const buf: Pointer; count: integer; datatype: TMPI_Datatype; status: PMPI_Status): integer; cdecl; external LIBMPI name 'MPI_File_write_at';
  function MPI_File_write_at_all(fh: PMPI_File; offset: TMPI_Offset; const buf: Pointer; count: integer; datatype: TMPI_Datatype; status: PMPI_Status): integer; cdecl; external LIBMPI name 'MPI_File_write_at_all';
  function MPI_File_write_at_all_begin(fh: PMPI_File; offset: TMPI_Offset; const buf: Pointer; count: integer; datatype: TMPI_Datatype): integer; cdecl; external LIBMPI name 'MPI_File_write_at_all_begin';
  function MPI_File_write_at_all_end(fh: PMPI_File; const buf: Pointer; status: PMPI_Status): integer; cdecl; external LIBMPI name 'MPI_File_write_at_all_end';
  function MPI_File_write_ordered(fh: PMPI_File; const buf: Pointer; count: integer; datatype: TMPI_Datatype; status: PMPI_Status): integer; cdecl; external LIBMPI name 'MPI_File_write_ordered';
  function MPI_File_write_ordered_begin(fh: PMPI_File; const buf: Pointer; count: integer; datatype: TMPI_Datatype): integer; cdecl; external LIBMPI name 'MPI_File_write_ordered_begin';
  function MPI_File_write_ordered_end(fh: PMPI_File; const buf: Pointer; status: PMPI_Status): integer; cdecl; external LIBMPI name 'MPI_File_write_ordered_end';
  function MPI_File_write_shared(fh: PMPI_File; const buf: Pointer; count: integer; datatype: TMPI_Datatype; status: PMPI_Status): integer; cdecl; external LIBMPI name 'MPI_File_write_shared';
  function MPI_Register_datarep(const datarep: PChar; read_conversion_fn: PMPI_Datarep_conversion_function; write_conversion_fn: PMPI_Datarep_conversion_function; dtype_file_extent_fn: PMPI_Datarep_extent_function; extra_state: Pointer): integer; cdecl; external LIBMPI name 'MPI_Register_datarep';
  function MPI_File_f2c(fh: TMPI_Fint): PMPI_File; cdecl; external LIBMPI name 'MPI_File_f2c';
  function MPI_File_c2f(fh: PMPI_File): TMPI_Fint; cdecl; external LIBMPI name 'MPI_File_c2f';

implementation

end.
