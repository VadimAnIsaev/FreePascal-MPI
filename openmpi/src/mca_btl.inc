  Pmca_btl_base_module_t = ^mca_btl_base_module_t;

  mca_btl_base_registration_handle_t = packed record
  end;

  mca_btl_base_module_flush_fn_t= function(btl: Pmca_btl_base_module_t; endpoint: Pmca_btl_base_endpoint_t): integer;
  mca_btl_base_module_add_procs_fn_t= function(btl: Pmca_btl_base_module_t; nprocs: valuint; procs: Popal_proc_t; endpoints: Pmca_btl_base_endpoint_t; reachable: Popal_bitmap_t): integer;
  mca_btl_base_module_del_procs_fn_t= function(btl: Pmca_btl_base_module_t; nprocs: valuint; procs: Popal_proc_t; peer: Pmca_btl_base_endpoint_t): integer;
  mca_btl_base_module_register_fn_t= function(btl: Pmca_btl_base_module_t; tag: mca_btl_base_tag_t; cbfunc: mca_btl_base_module_recv_cb_fn_t; cbdata: Pointer): integer;
  mca_btl_base_module_finalize_fn_t= function(btl: Pmca_btl_base_module_t): integer;
  mca_btl_base_module_alloc_fn_t= function(btl: Pmca_btl_base_module_t; endpoint: Pmca_btl_base_endpoint_t; order: Byte; size: valuint; flags: DWord): Pmca_btl_base_descriptor_t;
  mca_btl_base_module_free_fn_t= function(btl: Pmca_btl_base_module_t; descriptor: Pmca_btl_base_descriptor_t): integer;
  mca_btl_base_module_prepare_fn_t= function(btl: Pmca_btl_base_module_t; endpoint: Pmca_btl_base_endpoint_t; convertor: Popal_convertor_t; order: Byte; reserve: valuint; size: Pvaluint; flags: DWord): Pmca_btl_base_descriptor_t;
  mca_btl_base_module_send_fn_t= function(btl: Pmca_btl_base_module_t; endpoint: Pmca_btl_base_endpoint_t; descriptor: Pmca_btl_base_descriptor_t; tag: mca_btl_base_tag_t): integer;
  mca_btl_base_module_sendi_fn_t= function(btl: Pmca_btl_base_module_t; endpoint: Pmca_btl_base_endpoint_t; convertor: Popal_convertor_t; header: Pointer; header_size: valuint; payload_size: valuint; order: Byte; flags: DWord; tag: mca_btl_base_tag_t; descriptor: Pmca_btl_base_descriptor_t): integer;
  mca_btl_base_module_put_fn_t= function(btl: Pmca_btl_base_module_t; endpoint: Pmca_btl_base_endpoint_t; local_address: Pointer; remote_address: QWord; local_handle: Pmca_btl_base_registration_handle_t; remote_handle: Pmca_btl_base_registration_handle_t; size: valuint; flags: integer; order: integer; cbfunc: mca_btl_base_rdma_completion_fn_t; cbcontext: Pointer; cbdata: Pointer): integer;
  mca_btl_base_module_get_fn_t= function(btl: Pmca_btl_base_module_t; endpoint: Pmca_btl_base_endpoint_t; local_address: Pointer; remote_address: QWord; local_handle: Pmca_btl_base_registration_handle_t; remote_handle: Pmca_btl_base_registration_handle_t; size: valuint; flags: integer; order: integer; cbfunc: mca_btl_base_rdma_completion_fn_t; cbcontext: Pointer; cbdata: Pointer): integer;
  mca_btl_base_module_dump_fn_t= procedure(btl: Pmca_btl_base_module_t; endpoint: Pmca_btl_base_endpoint_t; verbose: integer);
  mca_btl_base_module_atomic_op64_fn_t= function(btl: Pmca_btl_base_module_t; endpoint: Pmca_btl_base_endpoint_t; remote_address: QWord; remote_handle: Pmca_btl_base_registration_handle_t; op: mca_btl_base_atomic_op_t; operand: QWord; flags: integer; order: integer; cbfunc: mca_btl_base_rdma_completion_fn_t; cbcontext: Pointer; cbdata: Pointer): integer;
  mca_btl_base_module_atomic_fop64_fn_t= function(btl: Pmca_btl_base_module_t; endpoint: Pmca_btl_base_endpoint_t; local_address: Pointer; remote_address: QWord; local_handle: Pmca_btl_base_registration_handle_t; remote_handle: Pmca_btl_base_registration_handle_t; op: mca_btl_base_atomic_op_t; operand: QWord; flags: integer; order: integer; cbfunc: mca_btl_base_rdma_completion_fn_t; cbcontext: Pointer; cbdata: Pointer): integer;
  mca_btl_base_module_atomic_cswap64_fn_t= function(btl: Pmca_btl_base_module_t; endpoint: Pmca_btl_base_endpoint_t; local_address: Pointer; remote_address: QWord; local_handle: Pmca_btl_base_registration_handle_t; remote_handle: Pmca_btl_base_registration_handle_t; compare: QWord; value: QWord; flags: integer; order: integer; cbfunc: mca_btl_base_rdma_completion_fn_t; cbcontext: Pointer; cbdata: Pointer): integer;
  mca_btl_base_module_register_mem_fn_t= function(btl: Pmca_btl_base_module_t; endpoint: Pmca_btl_base_endpoint_t; base: Pointer; size: valuint; flags: DWord): Pmca_btl_base_registration_handle_t;
  mca_btl_base_module_deregister_mem_fn_t= function(btl: Pmca_btl_base_module_t; handle: Pmca_btl_base_registration_handle_t): integer;
  mca_mpool_base_module_address_fn_t= procedure(mpool: Pmca_mpool_base_module_t);
  mca_mpool_base_module_alloc_fn_t= procedure(mpool: Pmca_mpool_base_module_t; size: valuint; align: valuint; flags: DWord);
  mca_mpool_base_module_realloc_fn_t= procedure(mpool: Pmca_mpool_base_module_t; addr: Pointer; size: valuint);
  mca_mpool_base_module_free_fn_t= procedure(mpool: Pmca_mpool_base_module_t; addr: Pointer);
  mca_mpool_base_module_finalize_fn_t= procedure(mpool: Pmca_mpool_base_module_t);
  mca_mpool_base_module_ft_event_fn_t= function(state: integer): integer;
  mca_btl_base_module_register_error_fn_t= function(btl: Pmca_btl_base_module_t; cbfunc: mca_btl_base_module_error_cb_fn_t): integer;
  mca_btl_base_module_ft_event_fn_t= function(state: integer): integer;
  mca_btl_base_module_flush_fn_t= function(btl: Pmca_btl_base_module_t; endpoint: Pmca_btl_base_endpoint_t): integer;

  mca_btl_base_module_t = packed record
    btl_component				: Pmca_btl_base_component_t; 
    btl_eager_limit				: valuint;      
    btl_rndv_eager_limit			: valuint;    
    btl_max_send_size				: valuint;    
    btl_rdma_pipeline_send_length		: valuint; 
    btl_rdma_pipeline_frag_size			: valuint; 
    btl_min_rdma_pipeline_size			: valuint; 
    btl_exclusivity				: DWord;      
    btl_latency					: DWord;          
    btl_bandwidth				: DWord;        
    btl_flags					: DWord;            
    btl_atomic_flags				: DWord;     
    btl_registration_handle_size		: valuint;
    btl_get_limit				: valuint;    
    btl_get_alignment				: valuint;
    btl_put_limit				: valuint;    
    btl_put_alignment				: valuint;
    btl_get_local_registration_threshold	: valuint;
    btl_put_local_registration_threshold	: valuint;
    btl_add_procs				: mca_btl_base_module_add_procs_fn_t;
    btl_del_procs				: mca_btl_base_module_del_procs_fn_t;
    btl_register				: mca_btl_base_module_register_fn_t;
    btl_finalize				: mca_btl_base_module_finalize_fn_t;
    btl_alloc					: mca_btl_base_module_alloc_fn_t;
    btl_free					: mca_btl_base_module_free_fn_t;
    btl_prepare_src				: mca_btl_base_module_prepare_fn_t;
    btl_send					: mca_btl_base_module_send_fn_t;
    btl_sendi					: mca_btl_base_module_sendi_fn_t;
    btl_put					: mca_btl_base_module_put_fn_t;
    btl_get					: mca_btl_base_module_get_fn_t;
    btl_dump					: mca_btl_base_module_dump_fn_t;
    btl_atomic_op				: mca_btl_base_module_atomic_op64_fn_t;
    btl_atomic_fop				: mca_btl_base_module_atomic_fop64_fn_t;
    btl_atomic_cswap				: mca_btl_base_module_atomic_cswap64_fn_t;
    btl_register_mem				: mca_btl_base_module_register_mem_fn_t;
    btl_deregister_mem				: mca_btl_base_module_deregister_mem_fn_t;
    btl_mpool					: Pmca_mpool_base_module_t;
    btl_register_error				: mca_btl_base_module_register_error_fn_t;
    btl_ft_event				: mca_btl_base_module_ft_event_fn_t;
{$if defined(OPAL_CUDA_GDR_SUPPORT)}
    btl_cuda_eager_limit			: valuint;
    btl_cuda_rdma_limit				: valuint;
{$endif}
{$if defined(OPAL_CUDA_SUPPORT)}
    btl_cuda_max_send_size			: valuint;
{$endif}
    btl_flush					: mca_btl_base_module_flush_fn_t;
    padding					: array[0..255] of Byte;
  end;
