// -- mca-mpool --------------------------------------------------------
  mca_mpool_base_component_query_fn_t = function(const hints: PChar; priority: Pinteger; module: PPmca_mpool_base_module_t): integer;
  
  mca_mpool_base_component_t = packed record
    mpool_version	: mca_base_component_t;        
    mpool_data		: mca_base_component_data_t;
    mpool_query		: mca_mpool_base_component_query_fn_t; 
  end;

  mca_mpool_base_module_address_fn_t	= procedure(mpool: Pmca_mpool_base_module_t);
  mca_mpool_base_module_alloc_fn_t	= procedure(mpool: Pmca_mpool_base_module_t; size: valuint; align: valuint; flags: DWord);
  mca_mpool_base_module_realloc_fn_t	= procedure(mpool: Pmca_mpool_base_module_t; addr: Pointer; size: valuint);
  mca_mpool_base_module_free_fn_t	= procedure(mpool: Pmca_mpool_base_module_t; addr: Pointer);
  mca_mpool_base_module_finalize_fn_t	= procedure(mpool: Pmca_mpool_base_module_t);
  mca_mpool_base_module_ft_event_fn_t	= function(state: integer): integer;

  mca_mpool_base_module_t = packed record
    mpool_component		: Pmca_mpool_base_component_t;
    mpool_base			: mca_mpool_base_module_address_fn_t;
    mpool_alloc			: mca_mpool_base_module_alloc_fn_t; 
    mpool_realloc		: mca_mpool_base_module_realloc_fn_t;
    mpool_free			: mca_mpool_base_module_free_fn_t;      
    mpool_finalize		: mca_mpool_base_module_finalize_fn_t;
    mpool_ft_event		: mca_mpool_base_module_ft_event_fn_t;
    flags			: DWord; 
    mpool_allocation_unit	: valuint; 
    mpool_name			: PChar;
  end;
// -- mca-mpool --------------------------------------------------------  