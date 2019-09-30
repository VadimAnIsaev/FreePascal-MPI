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
	uint64_t		wr_id;
	ibv_send_wr     *next;
	ibv_sge	       *sg_list;
	int			num_sge;
	enum ibv_wr_opcode	opcode;
	unsigned int		send_flags;
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
	char			fw_ver[64];
	__be64			node_guid;
	__be64			sys_image_guid;
	uint64_t		max_mr_size;
	uint64_t		page_size_cap;
	uint32_t		vendor_id;
	uint32_t		vendor_part_id;
	uint32_t		hw_ver;
	int			max_qp;
	int			max_qp_wr;
	unsigned int		device_cap_flags;
	int			max_sge;
	int			max_sge_rd;
	int			max_cq;
	int			max_cqe;
	int			max_mr;
	int			max_pd;
	int			max_qp_rd_atom;
	int			max_ee_rd_atom;
	int			max_res_rd_atom;
	int			max_qp_init_rd_atom;
	int			max_ee_init_rd_atom;
	enum ibv_atomic_cap	atomic_cap;
	int			max_ee;
	int			max_rdd;
	int			max_mw;
	int			max_raw_ipv6_qp;
	int			max_raw_ethy_qp;
	int			max_mcast_grp;
	int			max_mcast_qp_attach;
	int			max_total_mcast_qp_attach;
	int			max_ah;
	int			max_fmr;
	int			max_map_per_fmr;
	int			max_srq;
	int			max_srq_wr;
	int			max_srq_sge;
	uint16_t		max_pkeys;
	uint8_t			local_ca_ack_delay;
	uint8_t			phys_port_cnt;
  end;

  ibv_pd = packed record
	context: Pibv_context;
	handle: integer;
  end;

  ibv_cq = packed record
	ibv_context     *context;
	ibv_comp_channel *channel;
	void		       *cq_context;
	uint32_t		handle;
	int			cqe;
	pthread_mutex_t		mutex;
	pthread_cond_t		cond;
	uint32_t		comp_events_completed;
	uint32_t		async_events_completed;
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
	enum ibv_port_state	state;
	enum ibv_mtu		max_mtu;
	enum ibv_mtu		active_mtu;
	int			gid_tbl_len;
	uint32_t		port_cap_flags;
	uint32_t		max_msg_sz;
	uint32_t		bad_pkey_cntr;
	uint32_t		qkey_viol_cntr;
	uint16_t		pkey_tbl_len;
	uint16_t		lid;
	uint16_t		sm_lid;
	uint8_t			lmc;
	uint8_t			max_vl_num;
	uint8_t			sm_sl;
	uint8_t			subnet_timeout;
	uint8_t			init_type_reply;
	uint8_t			active_width;
	uint8_t			active_speed;
	uint8_t			phys_state;
	uint8_t			link_layer;
	uint8_t			flags;
	uint16_t		port_cap_flags2;
  end;
