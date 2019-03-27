  mca_rcache_base_module_register_fn_t		= function(rcache: Pmca_rcache_base_module_t; addr: Pointer; size: valuint; flags: DWord; access_flags: integer; reg: PPmca_rcache_base_registration_t): integer; 
  mca_rcache_base_module_deregister_fn_t	= function(rcache: Pmca_rcache_base_module_t; reg: Pmca_rcache_base_registration_t): integer;
  mca_rcache_base_module_find_fn_t		= function(rcache: Pmca_rcache_base_module_t; addr: Pointer; size: valuint; reg: PPmca_rcache_base_registration_t): integer;
  mca_rcache_base_module_invalidate_range_fn_t	= function(rcache: Pmca_rcache_base_module_t; addr: Pointer; size: valuint): integer;
  mca_rcache_base_module_finalize_fn_t		= procedure(rcache: Pmca_rcache_base_module_t);
  mca_rcache_base_module_evict_fn_t		= function(rcache: Pmca_rcache_base_module_t): longbool;

  mca_rcache_base_resources_t = packed record
    cache_name		: PChar;
    reg_data		: Pointer;
    sizeof_reg		: valuint;
    register_mem	: function(reg_data: pointer; base: pointer; size: valuint;  reg: Pmca_rcache_base_registration_t): integer;
    deregister_mem	: function(reg_data: pointer;  reg: Pmca_rcache_base_registration_t): integer;
  end;
  
  mca_rcache_base_component_init_fn_t = function(p1: mca_rcache_base_resources_t): Pmca_rcache_base_module_t;
  
  mca_rcache_base_component_t = packed record
    rcache_version	: mca_base_component_t;
    rcache_data		: mca_base_component_data_t;
    rcache_init		: mca_rcache_base_component_init_fn_t;
  end;
  
  mca_rcache_base_module_t = packed record
    rcache_component		: Pmca_rcache_base_component_t; 
    rcache_register		: mca_rcache_base_module_register_fn_t;
    rcache_deregister		: mca_rcache_base_module_deregister_fn_t;
    rcache_find			: mca_rcache_base_module_find_fn_t;
    rcache_invalidate_range	: mca_rcache_base_module_invalidate_range_fn_t;
    rcache_finalize		: mca_rcache_base_module_finalize_fn_t;
    rcache_evict		: mca_rcache_base_module_evict_fn_t;
    lock			: opal_mutex_t;
  end;
  
  mca_rcache_base_registration_t = packed record
    super		: opal_free_list_item_t;
    rcache		: Pmca_rcache_base_module_t;
    base		: PByte;
    bound		: PByte;
    alloc_base		: PByte;
    ref_count		: integer;
    flags		: DWord;
    rcache_context	: Pointer;
{$if defined(OPAL_CUDA_GDR_SUPPORT)}
    gpu_bufID		: QWord;
{$endif}
    access_flags	: integer;
    padding		: array[0..63] of Byte;
  end;
