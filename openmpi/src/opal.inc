  opal_btl_openib_connect_base_component_register_fn_t = procedure();
  opal_btl_openib_connect_base_component_init_fn_t = function(): integer;
  opal_btl_openib_connect_base_func_component_query_t = function(btl: Pmca_btl_openib_module_t; cpc: PPopal_btl_openib_connect_base_module_t): integer;
  opal_btl_openib_connect_base_component_finalize_fn_t = function(): integer;

  opal_btl_openib_connect_base_component_t = packed record
    cbc_name: array[0..BCF_MAX_NAME-1] of shortint;
    cbc_register: opal_btl_openib_connect_base_component_register_fn_t;
    cbc_init: opal_btl_openib_connect_base_component_init_fn_t;
    cbc_query: opal_btl_openib_connect_base_func_component_query_t;
    cbc_finalize: opal_btl_openib_connect_base_component_finalize_fn_t;
  end;
  
  opal_btl_openib_connect_base_module_data_t = packed record
    cbm_component		: Popal_btl_openib_connect_base_component_t;
    cbm_priority		: Byte;
    cbm_modex_message		: pointer;
    cbm_modex_message_len	: Byte;
  end;
  
  opal_btl_openib_connect_base_module_endpoint_init_fn_t = function(endpoint: Pmca_btl_base_endpoint_t): integer;
  opal_btl_openib_connect_base_module_start_connect_fn_t = function(cpc: Popal_btl_openib_connect_base_module_t; endpoint: Pmca_btl_base_endpoint_t): integer;
  opal_btl_openib_connect_base_module_endpoint_finalize_fn_t = function(endpoint: Pmca_btl_base_endpoint_t): integer;
  opal_btl_openib_connect_base_module_finalize_fn_t = function(btl: Pmca_btl_openib_module_t; cpc: Popal_btl_openib_connect_base_module_t): integer;

  opal_btl_openib_connect_base_module_t = packed record
    data			: opal_btl_openib_connect_base_module_data_t;
    cbm_endpoint_init		: opal_btl_openib_connect_base_module_endpoint_init_fn_t;
    cbm_start_connect		: opal_btl_openib_connect_base_module_start_connect_fn_t;
    cbm_endpoint_finalize	: opal_btl_openib_connect_base_module_endpoint_finalize_fn_t;
    cbm_finalize		: opal_btl_openib_connect_base_module_finalize_fn_t;
    cbm_uses_cts		: longbool;
  end;

  
  Tsval = packed record
    uval: integer;
    lval: integer;
  end;

  opal_ptr_t = packed record
    lval: QWord;
    ival: DWord;
    pval: Pointer;
    sval: Tsval; 
  end;
  
  opal_object_t = packed record
{$if defined(OPAL_ENABLE_DEBUG)}
    obj_magic_id	: QWord;
{$endif}
    obj_class		: Popal_class_t;            
    obj_reference_count	: integer;   
{$if defined(OPAL_ENABLE_DEBUG)}
    cls_init_file_name	: PChar;        
    cls_init_lineno	: integer;           
{$endif}
  end;

  opal_construct_t = procedure(p1: Popal_object_t);
  opal_destruct_t = procedure (p1: Popal_object_t);

  opal_class_t = packed record
    cls_name		: PChar;           
    cls_parent		: Popal_class_t;       
    cls_construct	: opal_construct_t; 
    cls_destruct	: opal_destruct_t;   
    cls_initialized	: integer;            
    cls_depth		: integer;                  
    cls_construct_array	: array of opal_construct_t;
    cls_destruct_array	: array of opal_destruct_t;
    cls_sizeof		: valuint;              
  end;

  opal_bitmap_t = packed record
    super: opal_object_t;      
    bitmap: ^QWord;     
    array_size: integer; 
    max_size: integer;   
  end;

  
  Tu = packed record
   case byte of
     0: (lock		: integer);
     1: (sparc_lock	: Byte);
     2: (padding	: array[0..sizeof(integer)-1] of shortint);
  end;

  opal_atomic_lock_t = packed record
    u: Tu;
  end;

  _pthread_descr = pointer;
  _pthread_fastlock = record
    __status : longint;
    __spinlock : longint;
  end;


  pthread_mutex_t = record
    __m_reserved	: longint;
    __m_count		: longint;
    __m_owner		: _pthread_descr;
    __m_kind		: longint;
    __m_lock		: _pthread_fastlock;
  end;
  
  opal_mutex_t = packed record
    super		: opal_object_t;
    m_lock_pthread	: pthread_mutex_t;
{$if defined(OPAL_ENABLE_DEBUG)}
    m_lock_debug	: integer;
    m_lock_file		: PChar;
    m_lock_line		: integer;
{$endif}
    m_lock_atomic	: opal_atomic_lock_t;
  end;
  
  opal_pointer_array_t = packed record
    super: opal_object_t;
    lock: opal_mutex_t;
    lowest_free: integer;
    number_free: integer;
    size: integer;
    max_size: integer;
    block_size: integer;
    free_bits: ^QWord;
    addr: pointer;
  end;
  
  Tptr = packed record
    key		: Pointer;
    key_size	: valuint;
  end;
  
  Tkey = packed record
    case byte of                     
      0: (u32		: DWord);
      1: (u64		: QWord);
      3: (ptr		: Tptr);
  end;
 
  opal_hash_element_t = packed record
    valid		: integer;          
    key			: Tkey;
    value		: Pointer;
  end;
 

  opal_hash_type_methods_t = packed record
    elt_destructor	: procedure(elt: Popal_hash_element_t);
    hash_elt		: function(elt: Popal_hash_element_t): valuint;
  end;
  
  opal_hash_table_t = packed record
    super		: opal_object_t;
    ht_table		: Popal_hash_element_t; 
    ht_capacity		: valuint;
    ht_size		: valuint;    
    ht_growth_trigger	: valuint;
    ht_density_numer	: integer;
    ht_density_denom	: integer;
    ht_growth_numer	: integer;
    ht_growth_denom	: integer;  
    ht_type_methods	: Popal_hash_type_methods_t;
  end;

  opal_list_item_t = packed record
    super			: opal_object_t;
    opal_list_next		: Popal_list_item_t;
    opal_list_prev		: Popal_list_item_t;
    item_free			: integer;
{$if defined(OPAL_ENABLE_DEBUG)}
    opal_list_item_refcount	: integer;
    opal_list_item_belong_to	: Popal_list_t;
{$endif}
  end;

  opal_free_list_item_t = packed record
    super			: opal_list_item_t;
    registration		: Pmca_rcache_base_registration_t;
    ptr				: Pointer;
  end;  
  
  opal_list_t = packed record
    super		: opal_object_t;
    opal_list_sentinel	: opal_list_item_t;
    opal_list_length	: valuint;
  end;

  opal_info_t = packed record
    super		: opal_list_t;
    i_lock		: Popal_mutex_t;
  end;

  opal_free_list_item_init_fn_t = function(item: Popal_free_list_item_t; ctx: pointer): integer;

  Topaldata = packed record
     counter: QWord;
     item: Popal_list_item_t;
  end;

  opal_int128_t = int128rec;
{    a: int64;
    b: int64;
  end;}
  
  opal_counted_pointer_t = packed record
    Case Byte of
      0: (data: TopalData);
{$if defined(OPAL_HAVE_ATOMIC_COMPARE_EXCHANGE_128 && HAVE_OPAL_INT128_T)}
      1: (value: opal_int128_t);
{$endif}
  end;

  
  opal_lifo_t = packed record
    super: opal_object_t;
    opal_lifo_head: opal_counted_pointer_t;
    opal_lifo_ghost: opal_list_item_t;
  end;

  opal_condition_t = packed record
    super: opal_object_t;
    c_waiting: integer;
    c_signaled: integer;
  end;
  
  opal_free_list_t = packed record
    super: opal_lifo_t ;
    fl_max_to_alloc: valuint;
    fl_num_allocated: valuint;
    fl_num_per_alloc: valuint;
    fl_num_waiting: valuint;
    fl_frag_size: valuint;
    fl_frag_alignment: valuint;
    fl_payload_buffer_size: valuint;
    fl_payload_buffer_alignment: valuint;
    fl_frag_class: Popal_class_t;
    fl_mpool: Pmca_mpool_base_module_t;
    fl_rcache: Pmca_rcache_base_module_t;
    fl_lock: opal_mutex_t;
    fl_condition: opal_condition_t;
    fl_allocations: opal_list_t;
    fl_rcache_reg_flags: integer;
    item_init: opal_free_list_item_init_fn_t;
    ctx: Pointer;
  end;  
  
  opal_jobid_t = DWord;
  opal_vpid_t = DWord;
   
  opal_process_name_t = packed record
     jobid	: opal_jobid_t;
     vpid	: opal_vpid_t;
  end;

  opal_hwloc_locality_t = Word;

  conversion_fct_t = function(pConvertor: Popal_convertor_t; 
			count: DWord;
		const from: Pointer; 
			from_len: valuint; 
			from_extent: integer;
                        too: Pointer; 
                        to_length: valuint; 
                        to_extent: integer;
                        advance: Pinteger): integer;
  
  opal_convertor_t = packed record
    next		: Popal_convertor_t;
    remote_arch		: DWord;
    flags		: DWord;
    hetero_mask		: DWord;
    remote_sizes	: array[0..OPAL_DATATYPE_MAX_PREDEFINED-1] of valuint;
    pFunctions		: conversion_fct_t;   
  end;
 
  opal_proc_t = packed record
    super		: opal_list_item_t;
    proc_name		: opal_process_name_t;
    proc_arch		: DWord;
    proc_flags		: opal_hwloc_locality_t;
    proc_convertor	: ^opal_convertor_t;
    proc_hostname	: PChar;
  end;
  
  opal_infosubscriber_t = packed record
    s_base		: opal_object_t;
    s_subscriber_table	: opal_hash_table_t;
    s_info		: ^opal_info_t;
  end;
