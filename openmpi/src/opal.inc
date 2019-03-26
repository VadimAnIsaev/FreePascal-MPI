  Popal_class_t			= ^opal_class_t;
  Popal_object_t		= ^opal_object_t;
  Popal_hash_element_t		= ^opal_hash_element_t;
  Popal_mutex_t			= ^opal_mutex_t;
  Popal_hash_type_methods_t	= ^opal_hash_type_methods_t;
  Popal_list_item_t		= ^opal_list_item_t;
  Popal_list_t			= ^opal_list_t;
  Popal_convertor_t		= ^opal_convertor_t;
  
  opal_free_list_item_t = packed record
    super			: opal_list_item_t;
    registration		: Pmca_rcache_base_registration_t;
    ptr				: Pointer;
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

  opal_list_t = packed record
    super		: opal_object_t;
    opal_list_sentinel	: opal_list_item_t;
    opal_list_length	: valuint;
  end;

  opal_info_t = packed record
    super		: opal_list_t;
    i_lock		: Popal_mutex_t;
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
