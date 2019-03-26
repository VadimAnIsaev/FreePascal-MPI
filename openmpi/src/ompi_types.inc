
Type  
  pvaluint = ^valuint;
  
  PMPI_Comm	= ^TMPI_Comm;
  Pompi_communicator_t = ^ompi_communicator_t;

  {$I mca.inc}
  
  PMPI_File	= ^TMPI_File;
  PMPI_Win	= ^TMPI_Win;
  Pompi_win_t	= ^ompi_win_t;
//----------------------------------------
  Pompi_datatype_t = pointer;//^ompi_datatype_t;
  Pompi_op_t	= pointer;
  Pompi_request_t = pointer;

//----------------------------------------
  Pompi_group_t = ^ompi_group_t;
    
  TMPI_Aint	= integer;
  PMPI_Aint	= ^TMPI_Aint;
  TMPI_Count	= int64;
  PMPI_Count	= ^TMPI_Count;
  TMPI_Offset	= int64;
  PMPI_Offset	= ^TMPI_Offset;
  TMPI_Fint	= integer;
  PMPI_Fint	= ^TMPI_Fint;

  ompi_errhandler_type_t = 
  (
    OMPI_ERRHANDLER_TYPE_PREDEFINED,
    OMPI_ERRHANDLER_TYPE_COMM,
    OMPI_ERRHANDLER_TYPE_WIN,
    OMPI_ERRHANDLER_TYPE_FILE
  );
  TMPI_Errhandler = ompi_errhandler_type_t;
  
  ompi_errhandler_lang_t = 
  (
    OMPI_ERRHANDLER_LANG_C,
    OMPI_ERRHANDLER_LANG_CXX,
    OMPI_ERRHANDLER_LANG_FORTRAN
  );

  ompi_win_accumulate_ops_t =
  (  
    OMPI_WIN_ACCUMULATE_OPS_SAME_OP_NO_OP,
    OMPI_WIN_ACCUMULATE_OPS_SAME_OP
  );

  
  ompi_group_sporadic_list_t = packed record
    rank_first	: integer;
    length	: integer;
  end;
  Pompi_group_sporadic_list_t = ^ompi_group_sporadic_list_t;

  ompi_group_sporadic_data_t = packed record
    grp_sporadic_list		: Pompi_group_sporadic_list_t;
    grp_sporadic_list_len	: integer;
  end;

  ompi_group_strided_data_t = packed record
    grp_strided_offset		: integer;         
    grp_strided_stride		: integer;         
    grp_strided_last_element	: integer;    
  end;

  ompi_group_bitmap_data_t = packed record
    grp_bitmap_array		: ^Byte;
    grp_bitmap_array_len	: integer; 
  end;
  
  Tsparse_data = packed record
    Case byte of
      0: (grp_sporadic	: ompi_group_sporadic_data_t);
      1: (grp_strided 	: ompi_group_strided_data_t);
      3: (grp_bitmap  	: ompi_group_bitmap_data_t);
  end;

  ompi_proc_t = packed record
    super		: opal_proc_t;
    proc_endpoints	: array[0..OMPI_PROC_ENDPOINT_TAG_MAX-1] of Pointer;
    padding		: array[0..OMPI_PROC_PADDING_SIZE-1] of Char;
  end;
  Pompi_proc_t = ^ompi_proc_t;

  ompi_group_t = packed record
    super		: opal_object_t;    
    grp_proc_count	: integer;     
    grp_my_rank		: integer;        
    grp_f_to_c_index	: integer;   
    grp_proc_pointers	: Pompi_proc_t;
    grp_flags		: DWord;     
    grp_parent_group_ptr: Pompi_group_t;
    sparse_data		: Tsparse_data;
  end;
  TMPI_Group = ompi_group_t;
  PMPI_Group = ^TMPI_Group;

  TMPI_File = packed record
  end;
  
  MPI_Comm_errhandler_function		= procedure(p1: PMPI_Comm; p2: Pinteger); varargs;
  ompi_file_errhandler_fn		= procedure(p1: PMPI_File; p2: Pinteger); varargs;
  MPI_Win_errhandler_function		= procedure(p1: PMPI_Win; p2: Pinteger); varargs;
  ompi_errhandler_generic_handler_fn_t	= procedure(p1: Pointer; p2: Pinteger); varargs;
  ompi_errhandler_fortran_handler_fn_t	= procedure(p1: PMPI_Fint;p2: PMPI_Fint); varargs;
  ompi_errhandler_cxx_dispatch_fn_t	= procedure(handle: Pointer; err_code: Pinteger; const message: PChar; fn: ompi_errhandler_generic_handler_fn_t);
 
  ompi_errhandler_t = packed record
    super		: opal_object_t;
    eh_name		: array[0..MPI_MAX_OBJECT_NAME-1] of char;
    eh_mpi_object_type	: ompi_errhandler_type_t;
    eh_lang		: ompi_errhandler_lang_t;
    eh_comm_fn		: MPI_Comm_errhandler_function;
    eh_file_fn		: ompi_file_errhandler_fn;
    eh_win_fn		: MPI_Win_errhandler_function;
    eh_fort_fn		: ompi_errhandler_fortran_handler_fn_t;
    eh_cxx_dispatch_fn	: ompi_errhandler_cxx_dispatch_fn_t;
    eh_f_to_c_index	: integer;
  end;

  {$I ompi_osc.inc}
  
  ompi_win_t = packed record
    super		: opal_infosubscriber_t;
    w_lock		: opal_mutex_t;
    w_name		: array[0..MPI_MAX_OBJECT_NAME-1] of Char;
    w_group		: Pompi_group_t;
    w_flags		: Word;
    w_flavor		: Word;
    w_acc_ops		: ompi_win_accumulate_ops_t;
    w_keyhash		: ^opal_hash_table_t;
    w_f_to_c_index	: integer;
    error_handler	: ompi_errhandler_t;
    errhandler_type	: ompi_errhandler_type_t;
    w_osc_module	: ^ompi_osc_base_module_t;
    w_acc_order		: longint;
  end;
  TMPI_Win = ompi_win_t;
  
  ompi_communicator_t = packed record
    super		: opal_infosubscriber_t;
    c_lock		: opal_mutex_t; 
    c_name		: array [0..MPI_MAX_OBJECT_NAME-1] of char;
    c_contextid		: DWord;
    c_my_rank		: integer;
    c_flags		: DWord; 
    c_assertions	: DWord; 
    c_id_available	: integer; 
    c_id_start_index	: integer; 
    c_local_group	: Pompi_group_t;
    c_remote_group	: Pompi_group_t;
    c_local_comm	: Pompi_communicator_t; 
    c_keyhash		: ^opal_hash_table_t;
    c_cube_dim		: integer;
    c_topo		: ^mca_topo_base_module_t;
    c_f_to_c_index	: integer;
{$ifdef OMPI_WANT_PERUSE}
    c_peruse_handles	: ^^ompi_peruse_handle_t;
{$endif}
    error_handler	: ^ompi_errhandler_t;
    errhandler_type	: ompi_errhandler_type_t;
    c_pml_comm		: ^mca_pml_comm_t;
    c_coll		: ^mca_coll_base_comm_coll_t;
  end;
  TMPI_Comm = ompi_communicator_t;
  
