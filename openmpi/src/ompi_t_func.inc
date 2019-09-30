Type
  mca_base_pvar_handle_t = packed record
    super: opal_list_item_t;
    list2		: opal_list_item_t;
    session		: Pmca_base_pvar_session_t;
    pvar		: mca_base_pvar_session_t;
    obj_handle		: pointer;
    count		: integer;
    last_value		: pointer;
    current_value	: pointer;
    tmp_value		: pointer;
    started		: longbool;
  end;
  
  mca_base_pvar_session_t = packed record
    super		: opal_object_t;
    handles		: opal_list_t;
  end;
  
  ompi_mpit_cvar_handle_t = packed record
    var			: mca_base_var_t;
    bound_object	: pointer;
  end;

  mca_base_var_enum_t = packed record
    super		: opal_object_t;
    enum_is_static	: longbool;
    enum_name		: PChar;
    get_count		: mca_base_var_enum_get_count_fn_t;
    get_value		: mca_base_var_enum_get_value_fn_t;
    value_from_string	: mca_base_var_enum_vfs_fn_t;
    string_from_value	: mca_base_var_enum_sfv_fn_t;
    dump		: mca_base_var_enum_dump_fn_t;
    enum_value_count	: integer;
    enum_values		: Pmca_base_var_enum_value_t;
  end;  
  
  TMPI_T_cvar_handle = ompi_mpit_cvar_handle_t;
  TMPI_T_enum = mca_base_var_enum_t;
  TMPI_T_pvar_handle = mca_base_pvar_handle_t;
  TMPI_T_pvar_session = mca_base_pvar_session_t;

  PMPI_T_cvar_handle = ^TMPI_T_cvar_handle;
  PMPI_T_enum = ^TMPI_T_enum;
  PMPI_T_pvar_handle = ^TMPI_T_pvar_handle;
  PMPI_T_pvar_session = ^TMPI_T_pvar_session;

Const
  MPI_T_PVAR_ALL_HANDLES = MPI_T_pvar_handle(-1);
  MPI_T_PVAR_HANDLE_NULL = MPI_T_pvar_handle(0);
  MPI_T_PVAR_SESSION_NULL = MPI_T_pvar_session(0);
  MPI_T_CVAR_HANDLE_NULL = MPI_T_cvar_handle(0);


function MPI_T_init_thread (required: integer; provided: Pinteger): integer; cdecl; external LIBMPI name 'MPI_T_init_thread ';
function MPI_T_finalize (): integer; cdecl; external LIBMPI name 'MPI_T_finalize ';
function MPI_T_cvar_get_num (num_cvar: Pinteger): integer; cdecl; external LIBMPI name 'MPI_T_cvar_get_num ';
function MPI_T_cvar_get_info (cvar_index: integer; name: Pchar; name_len: Pinteger; verbosity: Pinteger; datatype: PMPI_Datatype; enumtype: PMPI_T_enum; desc: Pchar; desc_len: Pinteger; bind: Pinteger; scope: Pinteger): integer; cdecl; external LIBMPI name 'MPI_T_cvar_get_info ';
function MPI_T_cvar_get_index (const name: Pchar; cvar_index: Pinteger): integer; cdecl; external LIBMPI name 'MPI_T_cvar_get_index ';
function MPI_T_cvar_handle_alloc (cvar_index: integer; obj_handle: Pointer; handle: PMPI_T_cvar_handle; count: Pinteger): integer; cdecl; external LIBMPI name 'MPI_T_cvar_handle_alloc ';
function MPI_T_cvar_handle_free (handle: PMPI_T_cvar_handle): integer; cdecl; external LIBMPI name 'MPI_T_cvar_handle_free ';
function MPI_T_cvar_read (handle: TMPI_T_cvar_handle; buf: Pointer): integer; cdecl; external LIBMPI name 'MPI_T_cvar_read ';
function MPI_T_cvar_write (handle: TMPI_T_cvar_handle; const buf: Pointer): integer; cdecl; external LIBMPI name 'MPI_T_cvar_write ';
function MPI_T_category_get_num(num_cat: Pinteger): integer; cdecl; external LIBMPI name 'MPI_T_category_get_num';
function MPI_T_category_get_info(cat_index: integer; name: Pchar; name_len: Pinteger; desc: Pchar; desc_len: Pinteger; num_cvars: Pinteger; num_pvars: Pinteger; num_categories: Pinteger): integer; cdecl; external LIBMPI name 'MPI_T_category_get_info';
function MPI_T_category_get_index (const name: Pchar; category_index: Pinteger): integer; cdecl; external LIBMPI name 'MPI_T_category_get_index ';
function MPI_T_category_get_cvars(cat_index: integer; len: integer; indices: array of integer): integer; cdecl; external LIBMPI name 'MPI_T_category_get_cvars';
function MPI_T_category_get_pvars(cat_index: integer; len: integer; indices: array of integer): integer; cdecl; external LIBMPI name 'MPI_T_category_get_pvars';
function MPI_T_category_get_categories(cat_index: integer; len: integer; indices: array of integer): integer; cdecl; external LIBMPI name 'MPI_T_category_get_categories';
function MPI_T_category_changed(stamp: Pinteger): integer; cdecl; external LIBMPI name 'MPI_T_category_changed';
function MPI_T_pvar_get_num(num_pvar: Pinteger): integer; cdecl; external LIBMPI name 'MPI_T_pvar_get_num';
function MPI_T_pvar_get_info(pvar_index: integer; name: Pchar; name_len: Pinteger; verbosity: Pinteger; var_class: Pinteger; datatype: PMPI_Datatype; enumtype: PMPI_T_enum; desc: Pchar; desc_len: Pinteger; bind: Pinteger; readonly: Pinteger; continuous: Pinteger; atomic: Pinteger): integer; cdecl; external LIBMPI name 'MPI_T_pvar_get_info';
function MPI_T_pvar_get_index (const name: Pchar; var_class: integer; pvar_index: Pinteger): integer; cdecl; external LIBMPI name 'MPI_T_pvar_get_index ';
function MPI_T_pvar_session_create(session: PMPI_T_pvar_session): integer; cdecl; external LIBMPI name 'MPI_T_pvar_session_create';
function MPI_T_pvar_session_free(session: PMPI_T_pvar_session): integer; cdecl; external LIBMPI name 'MPI_T_pvar_session_free';
function MPI_T_pvar_handle_alloc(session: TMPI_T_pvar_session; pvar_index: integer; obj_handle: Pointer; handle: PMPI_T_pvar_handle; count: Pinteger): integer; cdecl; external LIBMPI name 'MPI_T_pvar_handle_alloc';
function MPI_T_pvar_handle_free(session: TMPI_T_pvar_session; handle: PMPI_T_pvar_handle): integer; cdecl; external LIBMPI name 'MPI_T_pvar_handle_free';
function MPI_T_pvar_start(session: TMPI_T_pvar_session; handle: TMPI_T_pvar_handle): integer; cdecl; external LIBMPI name 'MPI_T_pvar_start';
function MPI_T_pvar_stop(session: TMPI_T_pvar_session; handle: TMPI_T_pvar_handle): integer; cdecl; external LIBMPI name 'MPI_T_pvar_stop';
function MPI_T_pvar_read(session: TMPI_T_pvar_session; handle: TMPI_T_pvar_handle; buf: Pointer): integer; cdecl; external LIBMPI name 'MPI_T_pvar_read';
function MPI_T_pvar_write(session: TMPI_T_pvar_session; handle: TMPI_T_pvar_handle; const buf: Pointer): integer; cdecl; external LIBMPI name 'MPI_T_pvar_write';
function MPI_T_pvar_reset(session: TMPI_T_pvar_session; handle: TMPI_T_pvar_handle): integer; cdecl; external LIBMPI name 'MPI_T_pvar_reset';
function MPI_T_pvar_readreset(session: TMPI_T_pvar_session; handle: TMPI_T_pvar_handle; buf: Pointer): integer; cdecl; external LIBMPI name 'MPI_T_pvar_readreset';
function MPI_T_enum_get_info(enumtype: TMPI_T_enum; num: Pinteger; name: Pchar; name_len: Pinteger): integer; cdecl; external LIBMPI name 'MPI_T_enum_get_info';
function MPI_T_enum_get_item(enumtype: TMPI_T_enum; index: integer; value: Pinteger; name: Pchar; name_len: Pinteger): integer; cdecl; external LIBMPI name 'MPI_T_enum_get_item';
