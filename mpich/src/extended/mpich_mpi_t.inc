Type
  MPIR_T_object_kind = (
    MPIR_T_OBJECT_INVALID = 0,
    MPIR_T_ENUM_HANDLE,
    MPIR_T_CVAR_HANDLE,
    MPIR_T_PVAR_HANDLE,
    MPIR_T_PVAR_SESSION
  );

  PUT_array	= Pointer;			// ?????

  MPIR_T_enum_s = packed record
{$ifdef HAVE_ERROR_CHECKING}
    kind	: MPIR_T_object_kind;
{$endif}
    name	: PChar;
    items	: PUT_array;
  end;
  MPI_T_enum	= MPIR_T_enum_s;
  PMPI_T_enum	= ^MPIR_T_enum_s;

  MPIR_T_pvar_get_value_cb = procedure(addr: Pointer; obj_handle: Pointer; count: Integer; buf: Pointer);
  
  MPIR_T_pvar_class_t = (
    MPIX_T_PVAR_CLASS_INVALID = 0,
    MPIR_T_PVAR_CLASS_FIRST = 240,
    MPI_T_PVAR_CLASS_STATE = MPIR_T_PVAR_CLASS_FIRST,
    MPI_T_PVAR_CLASS_LEVEL,
    MPI_T_PVAR_CLASS_SIZE,
    MPI_T_PVAR_CLASS_PERCENTAGE,
    MPI_T_PVAR_CLASS_HIGHWATERMARK,
    MPI_T_PVAR_CLASS_LOWWATERMARK,
    MPI_T_PVAR_CLASS_COUNTER,
    MPI_T_PVAR_CLASS_AGGREGATE,
    MPI_T_PVAR_CLASS_TIMER,
    MPI_T_PVAR_CLASS_GENERIC,
    MPIR_T_PVAR_CLASS_LAST,
    MPIR_T_PVAR_CLASS_NUMBER = MPIR_T_PVAR_CLASS_LAST - MPIR_T_PVAR_CLASS_FIRST
  );

  watermark_value_t = packed record
   Case Byte Of
    f	: Double;
    u	: DWord;
    ul	: DWord;
    ull	: QWord;
  end;
  Twatermark_value_t = watermark_value_t;
  
  PMPIR_T_pvar_handle_s	= ^MPIR_T_pvar_handle_s;
  MPIR_T_pvar_handle_s	= packed record
{$ifdef HAVE_ERROR_CHECKING}
    kind: MPIR_T_object_kind;
{$endif}
    addr	: Pointer;
    datatype	: TMPI_Datatype;
    count	: integer;
    get_value	: PMPIR_T_pvar_get_value_cb;
    varclass	: PMPIR_T_pvar_class_t;
    bytes	: integer;
    flags	: integer;
    info	: Pvar_table_entry_t;
    session	: PMPIR_T_pvar_session_s;
    obj_handle	: Pointer;
    accum	: Pointer;
    offset	: Pointer;
    current	: Pointer;
    watermark	: watermark_value_t;
    prev	: PMPIR_T_pvar_handle_s; 
    next	: PMPIR_T_pvar_handle_s;
    prev2	: PMPIR_T_pvar_handle_s; 
    next2	: PMPIR_T_pvar_handle_s;
  end;
  MPIR_T_pvar_handle_t	= MPIR_T_pvar_handle_s;
  PMPIR_T_pvar_handle_t	= ^MPIR_T_pvar_handle_s;
  MPIR_T_pvar_handle	= MPIR_T_pvar_handle_s;
  PMPIR_T_pvar_handle	= ^MPIR_T_pvar_handle_s;

  MPI_T_pvar_session_s = packed record
{$ifdef HAVE_ERROR_CHECKING}
    kind	: MPIR_T_object_kind;
{$endif}
    hlist	: PMPIR_T_pvar_handle_t;
  end;
  MPI_T_pvar_session	= MPIR_T_pvar_session_s;
  PMPI_T_pvar_session	= ^MPIR_T_pvar_session_s;

  MPIR_T_scope_t = (
    MPIX_T_SCOPE_INVALID = 0,
    MPI_T_SCOPE_CONSTANT = 60438,
    MPI_T_SCOPE_READONLY,
    MPI_T_SCOPE_LOCAL,
    MPI_T_SCOPE_GROUP,
    MPI_T_SCOPE_GROUP_EQ,
    MPI_T_SCOPE_ALL,
    MPI_T_SCOPE_ALL_EQ
  );

  MPIR_T_cvar_handle_s = packed record
{$ifdef HAVE_ERROR_CHECKING}
    kind	: MPIR_T_object_kind;
{$endif}
    addr	: Pointer;
    count	: integer;
    datatype	: TMPI_Datatype;
    scope	: TMPIR_T_scope_t;
  end;
  MPI_T_cvar_handle	= MPIR_T_cvar_handle_s;
  PMPI_T_cvar_handle	= ^MPI_T_cvar_handle;

Const
  MPI_T_ENUM_NULL		= PMPI_T_enum(NIL);
  MPI_T_CVAR_HANDLE_NULL	= PMPI_T_cvar_handle(NIL);
  MPI_T_PVAR_HANDLE_NULL	= PMPI_T_pvar_handle(NIL);
  MPI_T_PVAR_SESSION_NULL	= PMPI_T_pvar_session(NIL);


  function MPI_T_init_thread(required: integer; provided: Pinteger): integer; cdecl; external LIBMPI name 'MPI_T_init_thread';
  function MPI_T_finalize(): integer; cdecl; external LIBMPI name 'MPI_T_finalize';
  function MPI_T_enum_get_info(enumtype: TMPI_T_enum; num: Pinteger; name: PChar; name_len: Pinteger): integer; cdecl; external LIBMPI name 'MPI_T_enum_get_info';
  function MPI_T_enum_get_item(enumtype: TMPI_T_enum; indx: integer; value: Pinteger; name: PChar; name_len: Pinteger): integer; cdecl; external LIBMPI name 'MPI_T_enum_get_item';
  function MPI_T_cvar_get_num(num_cvar: Pinteger): integer; cdecl; external LIBMPI name 'MPI_T_cvar_get_num';
  function MPI_T_cvar_get_info(cvar_index: integer; name: PChar; name_len: Pinteger; verbosity: Pinteger; datatype: PMPI_Datatype; enumtype: PMPI_T_enum; desc: PChar; desc_len: Pinteger; binding: Pinteger; scope: Pinteger): integer; cdecl; external LIBMPI name 'MPI_T_cvar_get_info';
  function MPI_T_cvar_handle_alloc(cvar_index: integer; obj_handle: Pointer; handle: PMPI_T_cvar_handle; count: Pinteger): integer; cdecl; external LIBMPI name 'MPI_T_cvar_handle_alloc';
  function MPI_T_cvar_handle_free(handle: PMPI_T_cvar_handle): integer; cdecl; external LIBMPI name 'MPI_T_cvar_handle_free';
  function MPI_T_cvar_read(handle: TMPI_T_cvar_handle; buf: Pointer): integer; cdecl; external LIBMPI name 'MPI_T_cvar_read';
  function MPI_T_cvar_write(handle: TMPI_T_cvar_handle; const buf: Pointer): integer; cdecl; external LIBMPI name 'MPI_T_cvar_write';
  function MPI_T_pvar_get_num(num_pvar: Pinteger): integer; cdecl; external LIBMPI name 'MPI_T_pvar_get_num';
  function MPI_T_pvar_get_info(pvar_index: integer; name: PChar; name_len: Pinteger; verbosity: Pinteger; var_class: Pinteger; datatype: PMPI_Datatype; enumtype: PMPI_T_enum; desc: PChar; desc_len: Pinteger; binding: Pinteger; readonly: Pinteger; continuous: Pinteger; atomic: Pinteger): integer; cdecl; external LIBMPI name 'MPI_T_pvar_get_info';
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
  function MPI_T_category_get_num(num_cat: Pinteger): integer; cdecl; external LIBMPI name 'MPI_T_category_get_num';
  function MPI_T_category_get_info(cat_index: integer; name: PChar; name_len: Pinteger; desc: PChar; desc_len: Pinteger; num_cvars: Pinteger; num_pvars: Pinteger; num_categories: Pinteger): integer; cdecl; external LIBMPI name 'MPI_T_category_get_info';
  function MPI_T_category_get_cvars(cat_index: integer; len: integer; indices: array of integer): integer; cdecl; external LIBMPI name 'MPI_T_category_get_cvars';
  function MPI_T_category_get_pvars(cat_index: integer; len: integer; indices: array of integer): integer; cdecl; external LIBMPI name 'MPI_T_category_get_pvars';
  function MPI_T_category_get_categories(cat_index: integer; len: integer; indices: array of integer): integer; cdecl; external LIBMPI name 'MPI_T_category_get_categories';
  function MPI_T_category_changed(stamp: Pinteger): integer; cdecl; external LIBMPI name 'MPI_T_category_changed';
  function MPI_T_cvar_get_index(const name: PChar; cvar_index: Pinteger): integer; cdecl; external LIBMPI name 'MPI_T_cvar_get_index';
  function MPI_T_pvar_get_index(const name: PChar; var_class: integer; pvar_index: Pinteger): integer; cdecl; external LIBMPI name 'MPI_T_pvar_get_index';
  function MPI_T_category_get_index(const name: PChar; cat_index: Pinteger): integer; cdecl; external LIBMPI name 'MPI_T_category_get_index';

  function PMPI_T_init_thread(required: integer; provided: Pinteger): integer; cdecl; external LIBMPI name 'PMPI_T_init_thread';
  function PMPI_T_finalize(): integer; cdecl; external LIBMPI name 'PMPI_T_finalize';
  function PMPI_T_enum_get_info(enumtype: TMPI_T_enum; num: Pinteger; name: PChar; name_len: Pinteger): integer; cdecl; external LIBMPI name 'PMPI_T_enum_get_info';
  function PMPI_T_enum_get_item(enumtype: TMPI_T_enum; indx: integer; value: Pinteger; name: PChar; name_len: Pinteger): integer; cdecl; external LIBMPI name 'PMPI_T_enum_get_item';
  function PMPI_T_cvar_get_num(num_cvar: Pinteger): integer; cdecl; external LIBMPI name 'PMPI_T_cvar_get_num';
  function PMPI_T_cvar_get_info(cvar_index: integer; name: PChar; name_len: Pinteger; verbosity: Pinteger; datatype: PMPI_Datatype; enumtype: PMPI_T_enum; desc: PChar; desc_len: Pinteger; binding: Pinteger; scope: Pinteger): integer; cdecl; external LIBMPI name 'PMPI_T_cvar_get_info';
  function PMPI_T_cvar_handle_alloc(cvar_index: integer; obj_handle: Pointer; handle: PMPI_T_cvar_handle; count: Pinteger): integer; cdecl; external LIBMPI name 'PMPI_T_cvar_handle_alloc';
  function PMPI_T_cvar_handle_free(handle: PMPI_T_cvar_handle): integer; cdecl; external LIBMPI name 'PMPI_T_cvar_handle_free';
  function PMPI_T_cvar_read(handle: TMPI_T_cvar_handle; buf: Pointer): integer; cdecl; external LIBMPI name 'PMPI_T_cvar_read';
  function PMPI_T_cvar_write(handle: TMPI_T_cvar_handle; const buf: Pointer): integer; cdecl; external LIBMPI name 'PMPI_T_cvar_write';
  function PMPI_T_pvar_get_num(num_pvar: Pinteger): integer; cdecl; external LIBMPI name 'PMPI_T_pvar_get_num';
  function PMPI_T_pvar_get_info(pvar_index: integer; name: PChar; name_len: Pinteger; verbosity: Pinteger; var_class: Pinteger; datatype: PMPI_Datatype; enumtype: PMPI_T_enum; desc: PChar; desc_len: Pinteger; binding: Pinteger; readonly: Pinteger; continuous: Pinteger; atomic: Pinteger): integer; cdecl; external LIBMPI name 'PMPI_T_pvar_get_info';
  function PMPI_T_pvar_session_create(session: PMPI_T_pvar_session): integer; cdecl; external LIBMPI name 'PMPI_T_pvar_session_create';
  function PMPI_T_pvar_session_free(session: PMPI_T_pvar_session): integer; cdecl; external LIBMPI name 'PMPI_T_pvar_session_free';
  function PMPI_T_pvar_handle_alloc(session: TMPI_T_pvar_session; pvar_index: integer; obj_handle: Pointer; handle: PMPI_T_pvar_handle; count: Pinteger): integer; cdecl; external LIBMPI name 'PMPI_T_pvar_handle_alloc';
  function PMPI_T_pvar_handle_free(session: TMPI_T_pvar_session; handle: PMPI_T_pvar_handle): integer; cdecl; external LIBMPI name 'PMPI_T_pvar_handle_free';
  function PMPI_T_pvar_start(session: TMPI_T_pvar_session; handle: TMPI_T_pvar_handle): integer; cdecl; external LIBMPI name 'PMPI_T_pvar_start';
  function PMPI_T_pvar_stop(session: TMPI_T_pvar_session; handle: TMPI_T_pvar_handle): integer; cdecl; external LIBMPI name 'PMPI_T_pvar_stop';
  function PMPI_T_pvar_read(session: TMPI_T_pvar_session; handle: TMPI_T_pvar_handle; buf: Pointer): integer; cdecl; external LIBMPI name 'PMPI_T_pvar_read';
  function PMPI_T_pvar_write(session: TMPI_T_pvar_session; handle: TMPI_T_pvar_handle; const buf: Pointer): integer; cdecl; external LIBMPI name 'PMPI_T_pvar_write';
  function PMPI_T_pvar_reset(session: TMPI_T_pvar_session; handle: TMPI_T_pvar_handle): integer; cdecl; external LIBMPI name 'PMPI_T_pvar_reset';
  function PMPI_T_pvar_readreset(session: TMPI_T_pvar_session; handle: TMPI_T_pvar_handle; buf: Pointer): integer; cdecl; external LIBMPI name 'PMPI_T_pvar_readreset';
  function PMPI_T_category_get_num(num_cat: Pinteger): integer; cdecl; external LIBMPI name 'PMPI_T_category_get_num';
  function PMPI_T_category_get_info(cat_index: integer; name: PChar; name_len: Pinteger; desc: PChar; desc_len: Pinteger; num_cvars: Pinteger; num_pvars: Pinteger; num_categories: Pinteger): integer; cdecl; external LIBMPI name 'PMPI_T_category_get_info';
  function PMPI_T_category_get_cvars(cat_index: integer; len: integer; indices: array of integer): integer; cdecl; external LIBMPI name 'PMPI_T_category_get_cvars';
  function PMPI_T_category_get_pvars(cat_index: integer; len: integer; indices: array of integer): integer; cdecl; external LIBMPI name 'PMPI_T_category_get_pvars';
  function PMPI_T_category_get_categories(cat_index: integer; len: integer; indices: array of integer): integer; cdecl; external LIBMPI name 'PMPI_T_category_get_categories';
  function PMPI_T_category_changed(stamp: Pinteger): integer; cdecl; external LIBMPI name 'PMPI_T_category_changed';
  function PMPI_T_cvar_get_index(const name: PChar; cvar_index: Pinteger): integer; cdecl; external LIBMPI name 'PMPI_T_cvar_get_index';
  function PMPI_T_pvar_get_index(const name: PChar; var_class: integer; pvar_index: Pinteger): integer; cdecl; external LIBMPI name 'PMPI_T_pvar_get_index';
  function PMPI_T_category_get_index(const name: PChar; cat_index: Pinteger): integer; cdecl; external LIBMPI name 'PMPI_T_category_get_index';
