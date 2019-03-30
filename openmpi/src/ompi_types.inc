
Type  
  pvaluint = ^valuint;
  
  TMPI_Aint	= integer;
  PMPI_Aint	= ^TMPI_Aint;
  TMPI_Count	= int64;
  PMPI_Count	= ^TMPI_Count;
  TMPI_Offset	= int64;
  PMPI_Offset	= ^TMPI_Offset;
  TMPI_Fint	= integer;
  PMPI_Fint	= ^TMPI_Fint;
  
  PMPI_Comm	= ^TMPI_Comm;
  PMPI_Op	= ^TMPI_Op;
  PMPI_File	= ^TMPI_File;
  PMPI_Win 	= ^TMPI_Win;
  PMPI_Group	= ^TMPI_Group;  
  PMPI_Info	= ^TMPI_Info;  
  PMPI_Datatype	= ^TMPI_Datatype;

  Pompi_communicator_t = ^ompi_communicator_t;
  PPompi_communicator_t = ^Pompi_communicator_t;
  Pompi_win_t = ^ompi_win_t;
  Pompi_proc_t = ^ompi_proc_t;
  Pompi_op_t = ^ompi_op_t;
  Pompi_info_t = ^ompi_info_t;
  Pompi_group_t = ^ompi_group_t;
  Pompi_errhandler_t = ^ompi_errhandler_t;
  Pompi_coll_tree_t = ^ompi_coll_tree_t;
  Pompi_request_t = ^ompi_request_t;
  PPompi_request_t = ^Pompi_request_t;
  Pompi_file_t = ^ompi_file_t;
  Pompi_datatype_t = ^ompi_datatype_t;
  PPompi_datatype_t = ^Pompi_datatype_t;

  Pompi_op_base_module_1_0_0_t = ^ompi_op_base_module_1_0_0_t;
  Pompi_op_base_module_t = ^ompi_op_base_module_1_0_0_t;

  {$I mca.inc}
  
  ompi_datatype_t = packed record
    super: opal_datatype_t;
    id: integer;
    d_f_to_c_index: integer;
    d_keyhash: Popal_hash_table_t;
    args: pointer;
    packed_description: pointer;
    pml_data: QWord;
    name: array[0..MPI_MAX_OBJECT_NAME-1] of char;
  end;  
  TMPI_Datatype = ompi_datatype_t;
  
  ompi_status_public_t = packed record
    MPI_SOURCE	: integer;
    MPI_TAG	: integer;
    MPI_ERROR	: integer;
    _cancelled	: integer;
    _ucount	: valuint;
  end;
  TMPI_Status = ompi_status_public_t;
  
  ompi_request_type_t = (
    OMPI_REQUEST_PML,
    OMPI_REQUEST_IO, 
    OMPI_REQUEST_GEN,
    OMPI_REQUEST_WIN,
    OMPI_REQUEST_COLL,
    OMPI_REQUEST_NULL,
    OMPI_REQUEST_NOOP,
    OMPI_REQUEST_COMM,
    OMPI_REQUEST_MAX  
  );
  
  ompi_request_state_t = (
    OMPI_REQUEST_INVALID,
    OMPI_REQUEST_INACTIVE,
    OMPI_REQUEST_ACTIVE,
    OMPI_REQUEST_CANCELLED
  );

  ompi_request_start_fn_t = function(count: valuint; requests: PPompi_request_t): integer;
  ompi_request_free_fn_t = function(rptr: PPompi_request_t): integer;
  ompi_request_cancel_fn_t = function(request: Pompi_request_t; flag: integer): integer;
  ompi_request_complete_fn_t = function(request: Pompi_request_t): integer;

  ompi_mpi_object_t = packed record
    Case Byte of
      0: (comm: Pompi_communicator_t);
      1: (fil: Pompi_file_t);
      2: (win: Pompi_win_t);
  end;
  
  ompi_request_t = packed record
    super: opal_free_list_item_t;
    req_type: ompi_request_type_t;
    req_status: ompi_status_public_t;
    req_complete: pointer;    
    req_state: ompi_request_state_t;
    req_persistent: longbool;                    
    req_f_to_c_index: integer;                   
    req_start: ompi_request_start_fn_t;      
    req_free: ompi_request_free_fn_t;        
    req_cancel: ompi_request_cancel_fn_t;    
    req_complete_cb: ompi_request_complete_fn_t;
    req_complete_cb_data: pointer;
    req_mpi_object: ompi_mpi_object_t;          
  end;
  TMPI_Request = ompi_request_t;
  
  ompi_coll_tree_t = packed record
    tree_root: integer;
    tree_fanout: integer;
    tree_bmtree: integer;
    tree_prev: integer;
    tree_nextsize: integer;
    tree_next: array of integer;
  end;


  ompi_info_t = packed record
    super		: opal_info_t;
    i_f_to_c_index	: integer;
    i_freed		: longbool;
  end;
  TMPI_Info = ompi_info_t;
  
  ompi_win_accumulate_ops_t =
  (  
    OMPI_WIN_ACCUMULATE_OPS_SAME_OP_NO_OP,
    OMPI_WIN_ACCUMULATE_OPS_SAME_OP
  );

  ompi_errhandler_type_t = 
  (
    OMPI_ERRHANDLER_TYPE_PREDEFINED,
    OMPI_ERRHANDLER_TYPE_COMM,
    OMPI_ERRHANDLER_TYPE_WIN,
    OMPI_ERRHANDLER_TYPE_FILE
  );
  
  ompi_errhandler_lang_t = 
  (
    OMPI_ERRHANDLER_LANG_C,
    OMPI_ERRHANDLER_LANG_CXX,
    OMPI_ERRHANDLER_LANG_FORTRAN
  );
  
  ompi_errhandler_generic_handler_fn_t = procedure(p1: pointer; p2: Pinteger; args: array of const);
  MPI_Comm_errhandler_function = procedure(p1: PMPI_Comm; p2: Pinteger; args: array of const); 
  ompi_file_errhandler_fn = procedure(p1: PMPI_File; p2: Pinteger; args: array of const);
  MPI_Win_errhandler_function = procedure(p1: PMPI_Win; p2: Pinteger; args: array of const);
  ompi_errhandler_fortran_handler_fn_t = procedure(p1: PMPI_Fint; p2: PMPI_Fint; args: array of const);
  ompi_errhandler_cxx_dispatch_fn_t = procedure(handle: pointer; err_code: Pinteger; const message: PChar; fn: ompi_errhandler_generic_handler_fn_t);

  ompi_errhandler_t = packed record
    super		: opal_object_t;
    eh_name		: array[0..MPI_MAX_OBJECT_NAME-1] of Char;
    eh_mpi_object_type	: ompi_errhandler_type_t;
    eh_lang		: ompi_errhandler_lang_t;
    eh_comm_fn		: MPI_Comm_errhandler_function;
    eh_file_fn		: ompi_file_errhandler_fn;
    eh_win_fn		: MPI_Win_errhandler_function;
    eh_fort_fn		: ompi_errhandler_fortran_handler_fn_t;
    eh_cxx_dispatch_fn	: ompi_errhandler_cxx_dispatch_fn_t;
    eh_f_to_c_index	: integer;
  end;
  TMPI_Errhandler = ompi_errhandler_t;
  
  ompi_op_type = (
    OMPI_OP_NULL,
    OMPI_OP_MAX,
    OMPI_OP_MIN,
    OMPI_OP_SUM,
    OMPI_OP_PROD,
    OMPI_OP_LAND,
    OMPI_OP_BAND,
    OMPI_OP_LOR,
    OMPI_OP_BOR,
    OMPI_OP_LXOR,
    OMPI_OP_BXOR,
    OMPI_OP_MAXLOC,
    OMPI_OP_MINLOC,
    OMPI_OP_REPLACE,
    OMPI_OP_NUM_OF_TYPES
  );

  MPI_User_function = procedure(p1: pointer; p2: pointer; p3: Pinteger; p4: PMPI_Datatype);
  
  ompi_op_base_handler_fn_1_0_0_t = procedure(p1: pointer; p2: pointer; p3: Pinteger; p4: PPompi_datatype_t; p5: Pompi_op_base_module_1_0_0_t);
  
  ompi_op_base_op_fns_1_0_0_t = packed record
    fns: array [0..OMPI_OP_BASE_TYPE_MAX-1] of ompi_op_base_handler_fn_1_0_0_t;
    modules: array[0..OMPI_OP_BASE_TYPE_MAX-1] of Pompi_op_base_module_t;
  end;
  ompi_op_base_op_fns_t = ompi_op_base_op_fns_1_0_0_t;  
  
  ompi_op_c_handler_fn_t = procedure(p1: pointer; p2: pointer; p3: Pinteger; p4: PPompi_datatype_t);
  ompi_op_cxx_handler_fn_t = procedure(p1: pointer; p2: pointer; p3: Pinteger; p4: PPompi_datatype_t; op: MPI_User_function);

  Tcxx_data = packed record
    user_fn		: ompi_op_c_handler_fn_t;
    intercept_fn	: ompi_op_cxx_handler_fn_t;
  end;

  ompi_op_java_handler_fn_t = procedure(p1: pointer; p2: pointer; p3: Pinteger; p4: PPompi_datatype_t; baseType: integer; jnienv: pointer; obj: pointer);
  
  Tjava_data = packed record
    intercept_fn	: ompi_op_java_handler_fn_t;
    jnienv		: pointer;
    obj			: pointer;
    baseType		: integer;
  end;
  
  ompi_op_fortran_handler_fn_t = procedure(p1: pointer; p2: pointer; p3: PMPI_Fint; p4: PMPI_Fint);

  To_func = packed record
    intrinsic	: ompi_op_base_op_fns_t;
    c_fn	: ompi_op_c_handler_fn_t;
    fort_fn	: ompi_op_fortran_handler_fn_t;
    cxx_data	: Tcxx_data;
    java_data	: Tjava_data;
  end;
    
  ompi_op_base_3buff_handler_fn_1_0_0_t = procedure(p1: pointer; p2: pointer; p3: pointer; p4: Pinteger; p5: PPompi_datatype_t; p6: Pompi_op_base_module_1_0_0_t);
  ompi_op_base_module_enable_1_0_0_fn_t = function(module: Pompi_op_base_module_1_0_0_t; op: Pompi_op_t): integer;
  
  ompi_op_base_module_1_0_0_t = packed record
    super: opal_object_t;
    opm_enable		: ompi_op_base_module_enable_1_0_0_fn_t;
    opm_op		: Pompi_op_t;
    opm_fns		: array[0..OMPI_OP_BASE_TYPE_MAX-1] of ompi_op_base_handler_fn_1_0_0_t;
    opm_3buff_fns	: array[0..OMPI_OP_BASE_TYPE_MAX-1] of ompi_op_base_3buff_handler_fn_1_0_0_t;
  end;

  ompi_op_base_op_3buff_fns_t = packed record
    fns		: array[0..OMPI_OP_BASE_TYPE_MAX-1] of ompi_op_base_3buff_handler_fn_1_0_0_t;
    modules	: array[0..OMPI_OP_BASE_TYPE_MAX-1] of Pompi_op_base_module_t;
  end;

  ompi_op_t = packed record
    super		: opal_object_t;
    o_name		: array[0..MPI_MAX_OBJECT_NAME-1] of Char;
    op_type		: ompi_op_type;
    o_flags		: integer;
    o_f_to_c_index	: integer;
    o_func		: To_func;
    o_3buff_intrinsic	: ompi_op_base_op_3buff_fns_t;
  end;
  TMPI_Op = ompi_op_t;

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
  
  ompi_file_t = packed record
  end;
  TMPI_File = ompi_file_t;
  
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
    w_osc_module	: Pompi_osc_base_module_t;
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
    c_peruse_handles	: PPompi_peruse_handle_t;
{$endif}
    error_handler	: Pompi_errhandler_t;
    errhandler_type	: ompi_errhandler_type_t;
    c_pml_comm		: Pmca_pml_comm_t;
    c_coll		: Pmca_coll_base_comm_coll_t;
  end;
  TMPI_Comm = ompi_communicator_t;
  
