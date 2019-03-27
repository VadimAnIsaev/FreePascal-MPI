  mca_btl_openib_qp_t = (
    MCA_BTL_OPENIB_PP_QP,
    MCA_BTL_OPENIB_SRQ_QP,
    MCA_BTL_OPENIB_XRC_QP
  );
  
  mca_btl_base_atomic_op_t = (
    MCA_BTL_ATOMIC_ADD	= $0001,
    MCA_BTL_ATOMIC_AND	= $0011,
    MCA_BTL_ATOMIC_OR	= $0012,
    MCA_BTL_ATOMIC_XOR	= $0014,
    MCA_BTL_ATOMIC_LAND	= $0015,
    MCA_BTL_ATOMIC_LOR	= $0016,
    MCA_BTL_ATOMIC_LXOR	= $0017,
    MCA_BTL_ATOMIC_SWAP	= $001a,
    MCA_BTL_ATOMIC_MIN	= $0020,
    MCA_BTL_ATOMIC_MAX	= $0021,
    MCA_BTL_ATOMIC_LAST);
  
  mca_btl_openib_ib_addr_state_t = (
    MCA_BTL_IB_ADDR_CONNECTING = 100,
    MCA_BTL_IB_ADDR_CONNECTED,
    MCA_BTL_IB_ADDR_CLOSED
  );
  
  mca_btl_openib_frag_t = (MCA_BTL_OPENIB_FRAG_RECV, MCA_BTL_OPENIB_FRAG_RECV_USER, MCA_BTL_OPENIB_FRAG_SEND, MCA_BTL_OPENIB_FRAG_SEND_USER, MCA_BTL_OPENIB_FRAG_EAGER_RDMA, MCA_BTL_OPENIB_FRAG_CONTROL, MCA_BTL_OPENIB_FRAG_COALESCED);
  
  mca_btl_openib_com_frag_t = packed record
    super: mca_btl_openib_frag_t;
    sg_entry: ibv_sge;
    registration: Pmca_btl_openib_reg_t;
    endpoint: Pmca_btl_base_endpoint_t;
    n_wqes_inflight: integer;
  end;
  
  mca_btl_openib_out_frag_t = packed record
    super: mca_btl_openib_com_frag_t;
    sr_desc: ibv_send_wr;
  end;
  
  mca_btl_base_tag_t = Byte;

  mca_btl_openib_header_t = packed record
    tag: mca_btl_base_tag_t;
    cm_seen: Byte;
    credits: Word;
{$if defined(OPAL_OPENIB_PAD_HDR)}
    padding: array[0..3] of Byte;
{$endif}
  end;

  Tuf = packed record  
    Case Byte of    
      0: (size: DWord);
      1: (buf: array[0..3] of Byte);
  end;    
  
  mca_btl_openib_footer_t = packed record
{$if defined(OPAL_ENABLE_DEBUG)}
    seq: DWord;
{$endif}
    u: Tuf;
{$if defined(OPAL_OPENIB_PAD_HDR)}
  {$if defined(OPAL_ENABLE_DEBUG)}
    padding: array[0..11] of Byte;
  {$else}
    padding: array[0..7] of Byte;
  {$endif}
{$endif}
  end;

  mca_btl_openib_send_control_frag_t = packed record
    super: mca_btl_openib_out_frag_t;
    hdr: Pmca_btl_openib_header_t;
    chdr: Pmca_btl_openib_header_t;
    ftr: Pmca_btl_openib_footer_t;
    qp_idx: Byte;
    coalesced_length: DWord;
    coalesced_frags: opal_list_t;
  end;

  
  mca_btl_openib_endpoint_srq_qp_t = packed record
    dummy: integer;
  end;  

  mca_btl_openib_endpoint_pp_qp_t = packed record
    sd_credits: integer;
    rd_posted: integer;
    rd_credits: integer;
    cm_received: integer;
    cm_return: integer;
    cm_sent: integer;
  end;  

  Tum = packed record
    Case Byte of
      0: (srq_qp: mca_btl_openib_endpoint_srq_qp_t);
      1: (pp_qp: mca_btl_openib_endpoint_pp_qp_t);
  end;
  
  mca_btl_openib_endpoint_qp_t = packed record
    qp: Pmca_btl_openib_qp_t;
    no_credits_pending_frags: array[0..1] of opal_list_t;
    no_wqe_pending_frags: array[0..1] of opal_list_t;
    rd_credit_send_lock: integer;
    credit_frag: Pmca_btl_openib_send_control_frag_t;
    ib_inline_max: valuint;
    u: Tum;
  end;

  
  ib_address_t = packed record
    super: opal_list_item_t;
    key: pointer;           
    subnet_id: QWord;       
    lid: QWord;             
    pending_ep: opal_list_t;
    qp: Pmca_btl_openib_qp_t;
    remote_xrc_rcv_qp_num: DWord; 
    addr_lock: opal_mutex_t;         
    status: mca_btl_openib_ib_addr_state_t;
    max_wqe: integer;
  end;
  
  
  mca_btl_base_endpoint_t = packed record
    super			: opal_list_item_t;
    endpoint_btl		: Pmca_btl_openib_module_t;
    endpoint_proc		: Pmca_btl_openib_proc_t;
    endpoint_local_cpc		: Popal_btl_openib_connect_base_module_t;
    endpoint_local_cpc_data	: Pointer;
    endpoint_initiator		: longbool;
    endpoint_remote_cpc_data	: Popal_btl_openib_connect_base_module_data_t;
    endpoint_state		: mca_btl_openib_endpoint_state_t;
    endpoint_retries		: valuint;
    endpoint_tstamp		: double;
    endpoint_lock		: opal_mutex_t;
    pending_lazy_frags		: opal_list_t;
    qps				: Pmca_btl_openib_endpoint_qp_t;
{$if defined(OPAL_HAVE_CONNECTX_XRC_DOMAINS)}
    xrc_recv_qp			: Pibv_qp;
{$else}
    xrc_recv_qp_num		: DWord;
{$endif}
    xrc_recv_psn		: DWord;
    pending_get_frags		: opal_list_t;
    pending_put_frags		: opal_list_t;
    get_tokens			: integer;
    subnet_id			: QWord;
    ib_addr			: Pib_address_t;
    eager_recv_count		: integer;
    eager_rdma_remote		: mca_btl_openib_eager_rdma_remote_t;
    eager_rdma_local		: mca_btl_openib_eager_rdma_local_t;
    index			: integer;
    nbo				: longbool;
    use_eager_rdma		: longbool;
    rem_info			: mca_btl_openib_rem_info_t;
    endpoint_cts_frag		: mca_btl_openib_recv_frag_t;
    endpoint_cts_mr		: Pibv_mr;
    endpoint_posted_recvs	: longbool;
    endpoint_cts_received	: longbool;
    endpoint_cts_sent		: longbool;
  end;
  
  
  mca_btl_base_registration_handle_t = packed record
  end;

  mca_btl_base_rdma_completion_fn_t = procedure(module: Pmca_btl_base_module_t; endpoint: Pmca_btl_base_endpoint_t; local_address: Pointer; local_handle: Pmca_btl_base_registration_handle_t; context: pointer; cbdata: pointer; status: integer);
  
  mca_btl_base_module_error_cb_fn_t = procedure(btl: Pmca_btl_base_module_t; flags: integer; errproc: Popal_proc_t; btlinfo: PChar);
  mca_btl_base_module_recv_cb_fn_t = procedure(btl: Pmca_btl_base_module_t; tag: mca_btl_base_tag_t; descriptor: Pmca_btl_base_descriptor_t; cbdata: Pointer);

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
  mca_btl_base_module_register_error_fn_t= function(btl: Pmca_btl_base_module_t; cbfunc: mca_btl_base_module_error_cb_fn_t): integer;
  mca_btl_base_module_ft_event_fn_t= function(state: integer): integer;
  mca_btl_base_module_flush_fn_t= function(btl: Pmca_btl_base_module_t; endpoint: Pmca_btl_base_endpoint_t): integer;
  
  mca_btl_base_component_init_fn_t = function(num_btls: Pinteger; enable_progress_threads: longbool; enable_mpi_threads: longbool): PPmca_btl_base_module_t;
  mca_btl_base_component_progress_fn_t = function(): integer;
  
  mca_btl_base_component_t = packed record
    btl_version: mca_base_component_t;
    btl_data: mca_base_component_data_t;
    btl_init: mca_btl_base_component_init_fn_t;
    btl_progress: mca_btl_base_component_progress_fn_t;
  end;

  
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

  mca_btl_openib_device_t = packed record
    super			: opal_object_t;
    ib_dev			: Pibv_device;
{$if defined(OPAL_ENABLE_PROGRESS_THREADS)}
    ib_channel			: Pibv_comp_channel;
    thread			: opal_thread_t;               
    progress			: longbool;             
{$endif}
    device_lock			: opal_mutex_t;          
    ib_dev_context		: Pibv_context;
{$if defined(HAVE_DECL_IBV_EXP_QUERY_DEVICE)}
    ib_exp_dev_attr		: ibv_exp_device_attr;
{$endif}
    ib_dev_attr			: ibv_device_attr;
    ib_pd			: ibv_pd;
    ib_cq			: array[0..BTL_OPENIB_MAX_CQ-1] of ibv_cq;
    cq_size			: array[0..BTL_OPENIB_MAX_CQ-1] of DWord;
    mpool			: Pmca_rcache_base_module_t;
    rcache			: Pmca_rcache_base_module_t;
    mtu				: DWord;
    use_eager_rdma		: Byte;
    btls			: Byte; 
    endpoints			: Popal_pointer_array_t;
    device_btls			: Popal_pointer_array_t;
    hp_cq_polls			: Word;
    eager_rdma_polls		: Word;
    pollme			: longbool;
    got_fatal_event		: longbool;
    got_port_event		: longbool;
{$if defined(HAVE_XRC)}
  {$if defined(OPAL_HAVE_CONNECTX_XRC_DOMAINS)}
    xrcd			: Pibv_xrcd;
  {$else}
    xrc_domain			: Pibv_xrc_domain;
  {$endif}
    xrc_fd			: integer;
{$endif}
    non_eager_rdma_endpoints	: integer;
    eager_rdma_buffers_count	: integer;
    eager_rdma_buffers		: PPmca_btl_base_endpoint_t;
    send_free_control		: opal_free_list_t;
    qps				: Pmca_btl_openib_device_qp_t;
    max_inline_data		: DWord;
    mem_reg_max			: QWord;
    mem_reg_max_total		: QWord;
    mem_reg_active		: QWord;
    ready_for_use		: longbool;
    async_event			: opal_event_t;
 end;


  mca_btl_openib_module_t = packed record
    super			: mca_btl_base_module_t;
    btl_inited			: longbool;
    srqs_created		: longbool;
    port_info			: mca_btl_openib_modex_message_t;
    cpcs			: opal_btl_openib_connect_base_module_t;
    num_cpcs			: Byte;
    device			: Pmca_btl_openib_device_t;
    port_num			: Byte;                  
    pkey_index			: Word;
    ib_port_attr		: ibv_port_attr;
    lid				: Word;                      
    apm_port			: integer;                      
    src_path_bits		: Byte;             
    num_peers			: integer;
    ib_lock			: opal_mutex_t;
    eager_rdma_frag_size	: valuint;    
    eager_rdma_channels		: integer;
    error_cb			: mca_btl_base_module_error_cb_fn_t;
    qps				: Pmca_btl_openib_module_qp_t;
    local_procs			: integer;
    atomic_ops_be		: longbool;
  end;  
  
  mca_btl_openib_proc_modex_t = packed record
    pm_port_info	: mca_btl_openib_modex_message_t;
    pm_cpc_data		: Popal_btl_openib_connect_base_module_data_t;
    pm_cpc_data_count	: Byte;
  end;
  
  mca_btl_openib_proc_t = packed record
    super		: opal_list_item_t;
    proc_opal		: Popal_proc_t;
    proc_ports		: Pmca_btl_openib_proc_modex_t;
    proc_port_count	: Word;
    openib_btls		: opal_list_t;
    proc_endpoints	: PPmca_btl_base_endpoint_t;
    proc_endpoint_count	: valuint;
    proc_lock		: opal_mutex_t;
  end;

  mca_btl_base_completion_fn_t = procedure(module: Pmca_btl_base_module_t; endpoint: Pmca_btl_base_endpoint_t; descriptor: Pmca_btl_base_descriptor_t; status: integer);

  mca_btl_base_descriptor_t = packed record
    super		: opal_free_list_item_t;
    des_segments	: Pmca_btl_base_segment_t;  
    des_segment_count	: valuint;              
    des_cbfunc		: mca_btl_base_completion_fn_t;
    des_cbdata		: pointer;                       
    des_context		: pointer;                      
    des_flags		: DWord;                     
    order		: Byte;
  end;  