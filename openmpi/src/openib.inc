Const
  IBV_SYSFS_NAME_MAX = 64;
  IBV_SYSFS_PATH_MAX = 256;
  
Type  
  Pibv_context = ^ibv_context;
  Pibv_device = ^ibv_device;
  Pibv_srq = ^ibv_srq;
  Pibv_mw = ^ibv_mw;
  Pibv_pd = ^ibv_pd;
  Pibv_cq = ^ibv_cq;
  Pibv_wc = ^ibv_wc;
  Pibv_recv_wr = ^ibv_recv_wr;
  PPibv_recv_wr = ^Pibv_recv_wr;

  ibv_mw_type = (
	IBV_MW_TYPE_1 = 1,
	IBV_MW_TYPE_2 = 2
  );
  
  Pibv_context = ^ibv_context;
  
  ibv_context_ops = packed record
	_compat_query_device = procedure();
	_compat_query_port = function(context: Pibv_context; port_num: Word; port_attr: P_compat_ibv_port_attr): integer;
	_compat_alloc_pd = procedure();
	_compat_dealloc_pd = procedure();
	_compat_reg_mr = procedure();
	_compat_rereg_mr = procedure();
	_compat_dereg_mr = procedure(void);
	alloc_mw = function(pd: Pibv_pd; type: ibv_mw_type): Pibv_mw;
	bind_mw = function(qp: Pibv_qp; mw: Pibv_mw; mw_bind: Pibv_mw_bind): integer;
	dealloc_mw = function(mw: Pibv_mw): integer;
	_compat_create_cq = procedure();
	poll_cq = function(cq: Pibv_cq; num_entries: integer; wc: Pibv_wc): integer;
	req_notify_cq = function(cq: Pibv_cq; solicited_only: integer): integer;
	_compat_cq_event = procedure();
	_compat_resize_cq = procedure();
	_compat_destroy_cq = procedure();
	_compat_create_srq = procedure();
	_compat_modify_srq = procedure();
	_compat_query_srq = procedure();
	_compat_destroy_srq = procedure();
	post_srq_recv = function(srq: Pibv_srq; recv_wr: Pibv_recv_wr; bad_recv_wr: PPibv_recv_wr): integer;
	_compat_create_qp = procedure();
	_compat_query_qp = procedure();
	_compat_modify_qp = procedure();
	_compat_destroy_qp = procedure();
	post_send = function(qp: Pibv_qp; wr: Pibv_send_wr; bad_wr: PPibv_send_wr): integer;
	post_recv = function(qp: Pibv_qp; wr: Pibv_recv_wr; bad_wr: PPibv_recv_wr): integer;
	_compat_create_ah = procedure();
	_compat_destroy_ah = procedure();
	_compat_attach_mcast = procedure();
	_compat_detach_mcast = procedure();
	_compat_async_event = procedure();
  end;

  ibv_context = packed record
	device			: Pibv_device;
	ops			: ibv_context_ops;
	cmd_fd			: integer;
	async_fd		: integer;
	num_comp_vectors	: integer;
	mutex			: pthread_mutex_t;
	abi_compat		: pointer;
  end;

  ibv_srq = packed record
    context		: Pibv_context;
    srq_context		: pointer;
    pd			: Pibv_pd;
    handle		: DWord;
    mutex		: pthread_mutex_t;
    cond		: pthread_cond_t;
    events_completed	: DWord;
  end;

  ibv_mr = packed record
	context: Pibv_context;
	pd: Pibv_pd;
	addr: pointer;
	length: valuint;
	handle: integer;
	lkey: integer;
	rkey: integer;
  end;

  ibv_sge = packed record
	addr: QWord;
	length: DWord;
	lkey: DWord;
  end;

  ibv_recv_wr = packed record
	wr_id: QWord;
	next: Pibv_recv_wr;
	sg_list: Pibv_sge;
	num_sge: integer;
  end;

  ibv_send_wr = packed record
	wr_id: QWord;
	next: ^ibv_send_wr;
	sg_list: ^ibv_sge;
	num_sge: integer;
	opcode: ibv_wr_opcode;
	send_flags: DWord;
	union {
		__be32			imm_data;
		uint32_t		invalidate_rkey;
	};
	union {
		{
			uint64_t	remote_addr;
			uint32_t	rkey;
		} rdma;
		{
			uint64_t	remote_addr;
			uint64_t	compare_add;
			uint64_t	swap;
			uint32_t	rkey;
		} atomic;
		{
			ibv_ah  *ah;
			uint32_t	remote_qpn;
			uint32_t	remote_qkey;
		} ud;
	} wr;
	union {
		{
			uint32_t    remote_srqn;
		} xrc;
	} qp_type;
	union {
		{
			ibv_mw	*mw;
			uint32_t		rkey;
			ibv_mw_bind_info	bind_info;
		} bind_mw;
		{
			void		       *hdr;
			uint16_t		hdr_sz;
			uint16_t		mss;
		} tso;
	};
  end;

  ibv_device = packed record
	_ops: _ibv_device_ops;
	node_type: ibv_node_type;
	transport_type: ibv_transport_type;
	name: array[0..IBV_SYSFS_NAME_MAX-1] of char;
	dev_name: array[0..IBV_SYSFS_NAME_MAX-1] of char;
	dev_path: array[0..IBV_SYSFS_PATH_MAX-1] if char;
	ibdev_path: array[0..IBV_SYSFS_PATH_MAX-1] of char;
  end;

  ibv_device_attr = packed record
	fw_ver: array[0..63] of Char;
	node_guid: __be64;
	sys_image_guid: __be64;
	max_mr_size: QWord;
	page_size_cap: QWord;
	vendor_id: DWord;
	vendor_part_id: DWord;
	hw_ver: DWord;
	max_qp: integer;
	max_qp_wr: integer;
	device_cap_flags: DWord;
	max_sge: integer;
	max_sge_rd: integer;
	max_cq: integer;
	max_cqe: integer;
	max_mr: integer;
	max_pd: integer;
	max_qp_rd_atom: integer;
	max_ee_rd_atom: integer;
	max_res_rd_atom: integer;
	max_qp_init_rd_atom: integer;
	max_ee_init_rd_atom: integer;
	atomic_cap: enum ibv_atomic_cap;
	max_ee: integer;
	max_rdd: integer;
	max_mw: integer;
	max_raw_ipv6_qp: integer;
	max_raw_ethy_qp: integer;
	max_mcast_grp: integer;
	max_mcast_qp_attach: integer;
	max_total_mcast_qp_attach: integer;
	max_ah: integer;
	max_fmr: integer;
	max_map_per_fmr: integer;
	max_srq: integer;
	max_srq_wr: integer;
	max_srq_sge: integer;
	max_pkeys: Word;
	local_ca_ack_delay: Byte;
	phys_port_cnt: Byte;
  end;

  ibv_pd = packed record
	context: Pibv_context;
	handle: integer;
  end;

  ibv_cq = packed record
	context: ^ibv_context;
	channel: ^ibv_comp_channel;
	cq_context: Pointer;
	handle: DWord;
	cqe: integer;
	mutex: pthread_mutex_t;
	cond: pthread_cond_t;
	comp_events_completed: DWord;
	async_events_completed: DWord;
  end;

  ibv_port_state = (
	IBV_PORT_NOP		= 0,
	IBV_PORT_DOWN		= 1,
	IBV_PORT_INIT		= 2,
	IBV_PORT_ARMED		= 3,
	IBV_PORT_ACTIVE		= 4,
	IBV_PORT_ACTIVE_DEFER	= 5
  );
  
  ibv_mtu = (
	IBV_MTU_256  = 1,
	IBV_MTU_512  = 2,
	IBV_MTU_1024 = 3,
	IBV_MTU_2048 = 4,
	IBV_MTU_4096 = 5
  );
  
  ibv_port_attr = packed record
	state: ibv_port_state;
	max_mtu: enum ibv_mtu;
	active_mtu: enum ibv_mtu;
	gid_tbl_len: integer;
	port_cap_flags: DWord;
	max_msg_sz: DWord;
	bad_pkey_cntr: DWord;
	qkey_viol_cntr: DWord;
	pkey_tbl_len: Word;
	lid: Word;
	sm_lid: Word;
	lmc: Byte;
	max_vl_num: Byte;
	sm_sl: Byte;
	subnet_timeout: Byte;
	init_type_reply: Byte;
	active_width: Byte;
	active_speed: Byte;
	phys_state: Byte;
	link_layer: Byte;
	flags: Byte;
	port_cap_flags2: Word;
  end;
