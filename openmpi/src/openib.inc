  Pibv_context = ^ibv_context;
  Pibv_device = ^ibv_device;
  Pibv_mw = ^ibv_mw;

  ibv_context_ops = packed record
	_compat_query_device = procedure();
	_compat_query_port = function(context: Pibv_context; port_num: Word; port_attr: P_compat_ibv_port_attr): integer;
	_compat_alloc_pd = procedure();
	_compat_dealloc_pd = procedure();
	_compat_reg_mr = procedure();
	_compat_rereg_mr = procedure();
	_compat_dereg_mr = procedure(void);
	alloc_mw = function(pd: Pibv_pd; type: enum ibv_mw_type): Pibv_mw;
	bind_mw = function(struct ibv_qp *qp, struct ibv_mw *mw,
					   struct ibv_mw_bind *mw_bind): integer;
	int			(*dealloc_mw)(struct ibv_mw *mw);
	void *(*_compat_create_cq)(void);
	int			(*poll_cq)(struct ibv_cq *cq, int num_entries, struct ibv_wc *wc);
	int			(*req_notify_cq)(struct ibv_cq *cq, int solicited_only);
	void *(*_compat_cq_event)(void);
	void *(*_compat_resize_cq)(void);
	void *(*_compat_destroy_cq)(void);
	void *(*_compat_create_srq)(void);
	void *(*_compat_modify_srq)(void);
	void *(*_compat_query_srq)(void);
	void *(*_compat_destroy_srq)(void);
	int			(*post_srq_recv)(struct ibv_srq *srq,
						 struct ibv_recv_wr *recv_wr,
						 struct ibv_recv_wr **bad_recv_wr);
	void *(*_compat_create_qp)(void);
	void *(*_compat_query_qp)(void);
	void *(*_compat_modify_qp)(void);
	void *(*_compat_destroy_qp)(void);
	int			(*post_send)(struct ibv_qp *qp, struct ibv_send_wr *wr,
					     struct ibv_send_wr **bad_wr);
	int			(*post_recv)(struct ibv_qp *qp, struct ibv_recv_wr *wr,
					     struct ibv_recv_wr **bad_wr);
	void *(*_compat_create_ah)(void);
	void *(*_compat_destroy_ah)(void);
	void *(*_compat_attach_mcast)(void);
	void *(*_compat_detach_mcast)(void);
	void *(*_compat_async_event)(void);
  end;


  ibv_context = packed record
	device: Pibv_device;
	ops: ibv_context_ops;
	cmd_fd: integer;
	async_fd: integer;
	num_comp_vectors: integer;
	mutex: pthread_mutex_t;
	abi_compat: pointer;
  end;

  ibv_srq = packed record
    context: Pibv_context;
    srq_context: pointer;
    pd: Pibv_pd;
    handle: DWord;
    mutex: pthread_mutex_t;
    cond: pthread_cond_t;
    events_completed: DWord;
  end;

  ibv_mr = packed record
	struct ibv_context     *context;
	struct ibv_pd	       *pd;
	void		       *addr;
	size_t			length;
	uint32_t		handle;
	uint32_t		lkey;
	uint32_t		rkey;
  end;

  ibv_sge = packed record
	uint64_t		addr;
	uint32_t		length;
	uint32_t		lkey;
  end;

  ibv_recv_wr = packed record
	uint64_t		wr_id;
	struct ibv_recv_wr     *next;
	struct ibv_sge	       *sg_list;
	int			num_sge;
  end;

  ibv_send_wr = packed record
	uint64_t		wr_id;
	struct ibv_send_wr     *next;
	struct ibv_sge	       *sg_list;
	int			num_sge;
	enum ibv_wr_opcode	opcode;
	unsigned int		send_flags;
	/* When opcode is *_WITH_IMM: Immediate data in network byte order.
	 * When opcode is *_INV: Stores the rkey to invalidate
	 */
	union {
		__be32			imm_data;
		uint32_t		invalidate_rkey;
	};
	union {
		struct {
			uint64_t	remote_addr;
			uint32_t	rkey;
		} rdma;
		struct {
			uint64_t	remote_addr;
			uint64_t	compare_add;
			uint64_t	swap;
			uint32_t	rkey;
		} atomic;
		struct {
			struct ibv_ah  *ah;
			uint32_t	remote_qpn;
			uint32_t	remote_qkey;
		} ud;
	} wr;
	union {
		struct {
			uint32_t    remote_srqn;
		} xrc;
	} qp_type;
	union {
		struct {
			struct ibv_mw	*mw;
			uint32_t		rkey;
			struct ibv_mw_bind_info	bind_info;
		} bind_mw;
		struct {
			void		       *hdr;
			uint16_t		hdr_sz;
			uint16_t		mss;
		} tso;
	};
  end;

  ibv_device = packed record
	struct _ibv_device_ops	_ops;
	enum ibv_node_type	node_type;
	enum ibv_transport_type	transport_type;
	/* Name of underlying kernel IB device, eg "mthca0" */
	char			name[IBV_SYSFS_NAME_MAX];
	/* Name of uverbs device, eg "uverbs0" */
	char			dev_name[IBV_SYSFS_NAME_MAX];
	/* Path to infiniband_verbs class device in sysfs */
	char			dev_path[IBV_SYSFS_PATH_MAX];
	/* Path to infiniband class device in sysfs */
	char			ibdev_path[IBV_SYSFS_PATH_MAX];
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
	struct ibv_context     *context;
	uint32_t		handle;
  end;

  ibv_cq = packed record
	struct ibv_context     *context;
	struct ibv_comp_channel *channel;
	void		       *cq_context;
	uint32_t		handle;
	int			cqe;
	pthread_mutex_t		mutex;
	pthread_cond_t		cond;
	uint32_t		comp_events_completed;
	uint32_t		async_events_completed;
  end;

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
