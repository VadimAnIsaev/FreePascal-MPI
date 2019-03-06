Type 
  
  TMPI_Aint       = longint;
  PMPI_Aint       = ^TMPI_Aint;
  TMPI_Comm       = integer;
  PMPI_Comm       = ^TMPI_Comm;
  TMPI_Count      = int64;
  PMPI_Count      = ^TMPI_Count;
  TMPI_Datatype   = integer;
  PMPI_Datatype   = ^TMPI_Datatype;
  TMPI_Errhandler = integer;
  PMPI_Errhandler = ^TMPI_Errhandler;
  TMPI_Group      = integer;
  PMPI_Group      = ^TMPI_Group;
  TMPI_Fint       = integer;
  PMPI_Fint       = ^TMPI_Fint;
  TMPI_Info       = integer;
  PMPI_Info       = ^TMPI_Info;
  TMPI_Message    = integer;
  PMPI_Message    = ^TMPI_Message;
  TMPI_Offset     = int64;
  PMPI_Offset     = ^TMPI_Offset;
  TMPI_Op         = integer;
  PMPI_Op         = ^TMPI_Op;
  TMPI_Request    = integer;
  PMPI_Request    = ^TMPI_Request; 
  TMPI_Win        = integer;
  PMPI_Win        = ^TMPI_Win;
  
  MPI_Status = packed record
    count_lo              : integer;
    count_hi_and_cancelled: integer;
    MPI_SOURCE            : integer;
    MPI_TAG               : integer;
    MPI_ERROR             : integer;
  end;
  TMPI_Status = MPI_Status;
  PMPI_Status = ^TMPI_Status;
 
  MPI_F08_Status = packed record
    count_lo              : TMPI_Fint;
    count_hi_and_cancelled: TMPI_Fint;
    MPI_SOURCE            : TMPI_Fint;
    MPI_TAG               : TMPI_Fint;
    MPI_ERROR             : TMPI_Fint;
  end;
  TMPI_F08_Status = MPI_F08_Status;
  PMPI_F08_Status = ^MPI_F08_Status;

  TArrInteger = array of Integer;
  TArr2Integer = array of array of Integer;
  TArrMPI_Aint = array of TMPI_Aint;
  TArrMPI_Datatype = array of TMPI_Datatype;
  TArrMPI_Info = array of TMPI_Info;
  TArrMPI_Request = array of TMPI_Request;
  TArrMPI_Status = array of TMPI_Status;

  
  MPIR_Win_flavor = (MPI_WIN_FLAVOR_CREATE	= 1,
                     MPI_WIN_FLAVOR_ALLOCATE	= 2,
                     MPI_WIN_FLAVOR_DYNAMIC	= 3,
                     MPI_WIN_FLAVOR_SHARED	= 4);
  MPIR_Win_flavor_t = MPIR_Win_flavor;
  TMPIR_Win_flavor  = MPIR_Win_flavor;
  TMPIR_Win_flavor_t = MPIR_Win_flavor;
  
 
  MPIR_Win_model = (MPI_WIN_SEPARATE = 1,
                    MPI_WIN_UNIFIED  = 2);
  TMPIR_Win_model= MPIR_Win_model;
  MPIR_Win_model_t = TMPIR_Win_model;
  TMPIR_Win_model_t = TMPIR_Win_model;
 
  MPIR_Topo_type = ( MPI_GRAPH      = 1, 
                     MPI_CART       = 2, 
                     MPI_DIST_GRAPH = 3);  
  TMPIR_Topo_type = MPIR_Topo_type;

  ADIO_Offset	= valsint;
  TADIO_Offset	= ADIO_Offset;
  PADIO_Offset	= ^ADIO_Offset;
  
  ADIOI_FileD = packed record
  
  end;
  MPI_File  = ^ADIOI_FileD;
  TMPI_File = MPI_File;
  PMPI_File = MPI_File;
  
  MPI_Handler_function		= procedure( p1: Pinteger; p2: Pinteger; args: array of const );
  PMPI_Handler_function		= MPI_Handler_function;
  MPI_Comm_errhandler_function	= procedure( p1: Pinteger; p2: Pinteger; args: array of const );
  PMPI_Comm_errhandler_function	= MPI_Comm_errhandler_function;
  MPI_File_errhandler_function	= procedure( p1: PMPI_File; p2: Pinteger; args: array of const );
  PMPI_File_errhandler_function	= MPI_File_errhandler_function;
  MPI_Win_errhandler_function	= procedure( p1: Pinteger; p2: Pinteger; args: array of const);
  PMPI_Win_errhandler_function	= MPI_Win_errhandler_function;
  MPI_User_function		= procedure( p1: Pointer; p2: Pointer; p3: Pinteger; p4: Pinteger ); 
  PMPI_User_function		= MPI_User_function;
  
  MPI_Comm_copy_attr_function		= function(p1: integer; p2: integer; p3: Pointer; p4: Pointer; p5: Pointer; p6: Pinteger): integer;
  PMPI_Comm_copy_attr_function		= MPI_Comm_copy_attr_function;
  MPI_Comm_delete_attr_function		= function(p1: integer; p2: integer; p3: Pointer; p4: Pointer): integer;
  PMPI_Comm_delete_attr_function	= MPI_Comm_delete_attr_function;
  MPI_Type_copy_attr_function		= function(p1: integer; p2: integer; p3: Pointer; p4: Pointer; p5: Pointer; p6: Pinteger): integer;
  PMPI_Type_copy_attr_function		= MPI_Type_copy_attr_function;
  MPI_Type_delete_attr_function		= function(p1: integer; p2: integer; p3: Pointer; p4: Pointer): integer;
  PMPI_Type_delete_attr_function	= MPI_Type_delete_attr_function;
  MPI_Win_copy_attr_function		= function(p1: integer; p2: integer; p3: Pointer; p4: Pointer; p5: Pointer; p6: Pinteger): integer;
  PMPI_Win_copy_attr_function		= MPI_Win_copy_attr_function;
  MPI_Win_delete_attr_function		= function(p1: integer; p2: integer; p3: Pointer; p4: Pointer): integer;
  PMPI_Win_delete_attr_function		= MPI_Win_delete_attr_function;
  MPI_Copy_function			= function(p1: integer; p2: integer; p3: Pointer; p4: Pointer; p5: Pointer; p6: Pinteger ): integer;
  PMPI_Copy_function			= MPI_Copy_function;
  MPI_Delete_function			= function(p1: integer; p2: integer; p3: Pointer; p4: Pointer ): integer;
  PMPI_Delete_function			= MPI_Delete_function;
  MPI_Grequest_cancel_function		= function(p1: Pointer; p2: integer ): integer; 
  PMPI_Grequest_cancel_function		= MPI_Grequest_cancel_function;
  MPI_Grequest_free_function		= function(p: Pointer): integer; 
  PMPI_Grequest_free_function		= MPI_Grequest_free_function;
  MPI_Grequest_query_function		= function(p1: Pointer; p2: PMPI_Status): integer; 
  PMPI_Grequest_query_function		= MPI_Grequest_query_function;
  MPI_Datarep_conversion_function	= function(p1: Pointer; p2: integer; p3: integer; p4: Pointer; p5: int64; p6: Pointer): integer;
  PMPI_Datarep_conversion_function	= MPI_Datarep_conversion_function;
  MPI_Datarep_extent_function		= function(p1: integer; p2: Pinteger; p3: Pointer): integer;
  PMPI_Datarep_extent_function		= MPI_Datarep_extent_function;

  MPI_Comm_errhandler_fn	= MPI_Comm_errhandler_function;
  TMPI_Comm_errhandler_fn	= MPI_Comm_errhandler_fn;
  MPI_File_errhandler_fn	= MPI_File_errhandler_function;
  TMPI_File_errhandler_fn	= MPI_File_errhandler_fn;
  MPI_Win_errhandler_fn		= MPI_Win_errhandler_function;
  TMPI_Win_errhandler_fn	= MPI_Win_errhandler_fn;

{
 ADIOI_Fns_struct = packed record
    void (*ADIOI_xxx_Open) (ADIO_File fd, int *error_code);
    void (*ADIOI_xxx_OpenColl) (ADIO_File fd, int rank, int access_mode, int *error_code);
    void (*ADIOI_xxx_ReadContig) (ADIO_File fd, void *buf, int count, MPI_Datatype datatype, int file_ptr_type, ADIO_Offset offset, ADIO_Status *status, int *error_code);
    void (*ADIOI_xxx_WriteContig) (ADIO_File fd, const void *buf, int count, MPI_Datatype datatype, int file_ptr_type, ADIO_Offset offset, ADIO_Status *status, int *error_code);  
    void (*ADIOI_xxx_ReadStridedColl) (ADIO_File fd, void *buf, int count, MPI_Datatype datatype, int file_ptr_type, ADIO_Offset offset, ADIO_Status *status, int *error_code);
    void (*ADIOI_xxx_WriteStridedColl) (ADIO_File fd, const void *buf, int count, MPI_Datatype datatype, int file_ptr_type, ADIO_Offset offset, ADIO_Status *status, int *error_code);
    ADIO_Offset (*ADIOI_xxx_SeekIndividual) (ADIO_File fd, ADIO_Offset offset, int whence, int *error_code);
    void (*ADIOI_xxx_Fcntl) (ADIO_File fd, int flag, ADIO_Fcntl_t *fcntl_struct, int *error_code); 
    void (*ADIOI_xxx_SetInfo) (ADIO_File fd, MPI_Info users_info, int *error_code);
    void (*ADIOI_xxx_ReadStrided) (ADIO_File fd, void *buf, int count, MPI_Datatype datatype, int file_ptr_type, ADIO_Offset offset, ADIO_Status *status, int *error_code);
    void (*ADIOI_xxx_WriteStrided) (ADIO_File fd, const void *buf, int count, MPI_Datatype datatype, int file_ptr_type, ADIO_Offset offset, ADIO_Status *status, int *error_code);
    void (*ADIOI_xxx_Close) (ADIO_File fd, int *error_code);
    void (*ADIOI_xxx_IreadContig) (ADIO_File fd, void *buf, int count, MPI_Datatype datatype, int file_ptr_type, ADIO_Offset offset, ADIO_Request *request, int *error_code);
    void (*ADIOI_xxx_IwriteContig) (ADIO_File fd, const void *buf, int count, MPI_Datatype datatype, int file_ptr_type, ADIO_Offset offset, ADIO_Request *request, int *error_code);
    int (*ADIOI_xxx_ReadDone) (ADIO_Request *request, ADIO_Status *status, int *error_code); 
    int (*ADIOI_xxx_WriteDone) (ADIO_Request *request, ADIO_Status *status, int *error_code);
    void (*ADIOI_xxx_ReadComplete) (ADIO_Request *request, ADIO_Status *status, int *error_code); 
    void (*ADIOI_xxx_WriteComplete) (ADIO_Request *request, ADIO_Status *status, int *error_code); 
    void (*ADIOI_xxx_IreadStrided) (ADIO_File fd, void *buf, int count, MPI_Datatype datatype, int file_ptr_type, ADIO_Offset offset, ADIO_Request *request, int *error_code);
    void (*ADIOI_xxx_IwriteStrided) (ADIO_File fd, const void *buf, int count, MPI_Datatype datatype, int file_ptr_type, ADIO_Offset offset, ADIO_Request *request, int *error_code);
    void (*ADIOI_xxx_Flush) (ADIO_File fd, int *error_code); 
    void (*ADIOI_xxx_Resize) (ADIO_File fd, ADIO_Offset size, int *error_code);
    void (*ADIOI_xxx_Delete) (const char *filename, int *error_code);
    int  (*ADIOI_xxx_Feature) (ADIO_File fd, int flag);
    const char *fsname;
    void (*ADIOI_xxx_IreadStridedColl) (ADIO_File fd, void *buf, int count, MPI_Datatype datatype, int file_ptr_type, ADIO_Offset offset, ADIO_Request *request, int *error_code);
    void (*ADIOI_xxx_IwriteStridedColl) (ADIO_File fd, const void *buf, int count, MPI_Datatype datatype, int file_ptr_type, ADIO_Offset offset, ADIO_Request *request, int *error_code);
 end;
 ADIOI_Fns = ADIOI_Fns_struct;
 PADIOI_Fns = ^ADIOI_Fns;
}

(*
 ADIOI_Hints_struct = packed record
    initialized    : integer;
    striping_factor: integer;
    striping_unit  : integer;
    cb_read        : integer;
    cb_write       : integer;
    cb_nodes       : integer;
    cb_buffer_size : integer;
    cb_pfr         : integer;
    cb_fr_type     : integer;
    cb_fr_alignment: integer;
    cb_ds_threshold: integer;
    cb_alltoall    : integer;
    ds_read        : integer;
    ds_write       : integer;
    no_indep_rw    : integer;
    ind_rd_buffer_size: integer;
    ind_wr_buffer_size: integer;
    deferred_open   : integer;
    min_fdomain_size: integer;
    cb_config_list  : PChar;
    ranklist        : Pinteger;
    case fs_hints of
	    pvfs = packed record
		listio_read : integer;
		listio_write: integer;
	    end ;
	    pvfs2 = packed record
		debugmask   : integer;
		posix_read  : integer;
		posix_write : integer;
		listio_read : integer;
		listio_write: integer;
		dtype_read  : integer;
		dtype_write : integer;
	    end ;
            lustre = packed record
                start_iodevice: integer;
                co_ratio      : integer;
                coll_threshold: integer;
                ds_in_coll    : integer;
            end ;
	    xfs = packed record
		read_chunk_sz : longword; { chunk size for direct reads }
		write_chunk_sz: longword; { chunk size for direct writes }
	    end ;
	    bg = packed record
	      bridgelist   : Pinteger; { list of all bride ranks }
	      bridgelistnum: Pinteger; { each entry here is the number of aggregators
				   associated with the bridge rank of the same
				   index in bridgelist }
	      numbridges   : integer; { total number of bridges }
	    end;
    end;

 end;
 ADIOI_Hints = ADIOI_Hints_struct;
 PADIOI_Hints = ^ADIOI_Hints;
*)
(* ADIOI_FileD = packed record
    cookie                   : integer;     { for error checking }
    fd_sys                   : integer;     { system file descriptor }
    null_fd                  : integer;     { the null-device file descriptor: debug only (obviously)}
    fd_direct                : integer;     { On XFS, this is used for direct I/O; 
                                                fd_sys is used for buffered I/O }
    direct_read              : integer;     { flag; 1 means use direct read }
    direct_write             : integer;     { flag; 1 means use direct write  }
    { direct I/O attributes }
    d_mem                    : dword;       { data buffer memory alignment }
    d_miniosz                : dword;       { min xfer size, xfer size multiple,
                                             and file seek offset alignment }
    blksize                  : longint;     { some optimizations benefit from knowing
				                 underlying block size }
    fp_ind                   : ADIO_Offset; { individual file pointer in MPI-IO (in bytes)}
    fp_sys_posn              : ADIO_Offset; { current location of the system file-pointer
                                              in bytes }
    fns                      : PADIOI_Fns;  { struct of I/O functions to use }
    comm                     : integer;     { communicator indicating who called open }
    is_open                  : integer;	    { deferred open: 0: not open yet 1: is open }
    is_agg                   : integer;     { bool: if I am an aggregator }
    filename                 : PChar;          
    file_system              : integer;     { type of file system }
    access_mode              : integer;     { Access mode (sequential, append, etc.),
				              possibly modified to deal with
				              data sieving or deferred open}
    orig_access_mode         : integer;     { Access mode provided by user: unmodified }
    disp                     : ADIO_Offset; { reqd. for MPI-IO }
    etype                    : integer;     { reqd. for MPI-IO }
    filetype                 : integer;     { reqd. for MPI-IO }
    etype_size               : int64;       { in bytes }
    hints                    : PADIOI_Hints;{ structure containing fs-indep. info values }
    info                     : integer;

    { The following support the split collective operations }
    split_coll_count         : integer;     { count of outstanding split coll. ops. }
    split_status             : MPI_Status;  { status used for split collectives }
    split_datatype           : integer;     { datatype used for split collectives }

    { The following support the shared file operations }
    shared_fp_fname          : PChar;       { name of file containing shared file pointer }
    shared_fp_fd             : ^ADIOI_FileD;{ file handle of file 
                                              containing shared fp }
    async_count              : integer;     { count of outstanding nonblocking operations }
    perm                     : integer;
    atomicity                : integer;     { true=atomic, false=nonatomic }
    fortran_handle           : integer;     { handle for Fortran interface if needed }
    err_handler              : integer;
    fs_ptr                   : Pointer;     { file-system specific information }

    { Two phase collective I/O support }
    file_realm_st_offs       : PADIO_Offset;{ file realm starting offsets }
    file_realm_types         : Pinteger;    { file realm datatypes }
    my_cb_nodes_index        : integer;     { my index into cb_config_list. -1 if N/A }
    io_buf                   : PChar;       { two-phase buffer allocated out of i/o path }
    io_buf_window            : integer;     { Window over the io_buf to support one-sided aggregation }
    io_buf_put_amounts       : Pinteger;    { array tracking the amount of data mpi_put into the io_buf
                                              during the same round of one-sided write aggregation }
    io_buf_put_amounts_window: integer;     { Window over the io_buf_put_amounts }
    { External32 }
    is_external32            : integer;     { bool:  0 means native view }
 end;
 MPI_File  = ^ADIOI_FileD;
*)
