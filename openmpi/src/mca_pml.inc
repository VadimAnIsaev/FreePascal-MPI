  Pmca_pml_comm_t		= ^mca_pml_comm_t;
  Pmca_pml_ob1_comm_proc_t	= ^mca_pml_ob1_comm_proc_t; 
  Pmca_pml_ob1_recv_frag_t	= ^mca_pml_ob1_recv_frag_t;
  
  mca_pml_ob1_common_hdr_t = packed record
    hdr_type		: Byte;
    hdr_flags		: Byte;
  end;

  
  mca_pml_ob1_match_hdr_t = packed record
    hdr_common: mca_pml_ob1_common_hdr_t; 
    hdr_ctx		: Word;                    
    hdr_src		: integer;                    
    hdr_tag		: integer;                    
    hdr_seq		: Word;                    
{$if defined(OPAL_ENABLE_HETEROGENEOUS_SUPPORT)}
    hdr_padding		: array[0..1] of Byte;             
{$endif}
  end;
  
  mca_pml_ob1_rendezvous_hdr_t = packed record
    hdr_match		: mca_pml_ob1_match_hdr_t;
    hdr_msg_length	: QWord;
    hdr_src_req		: opal_ptr_t;
  end;
  
  mca_pml_ob1_rget_hdr_t = packed record
    hdr_rndv		: mca_pml_ob1_rendezvous_hdr_t;
{$if defined(OPAL_ENABLE_HETEROGENEOUS_SUPPORT)}
    hdr_padding		: array[0..3] of Byte;
{$endif}
    hdr_frag		: opal_ptr_t;
    hdr_src_ptr		: QWord;
  end;
  
  mca_pml_ob1_frag_hdr_t = packed record
    hdr_common		: mca_pml_ob1_common_hdr_t; 
{$if defined(OPAL_ENABLE_HETEROGENEOUS_SUPPORT)}
    hdr_padding		: array[0..5] of Byte;
{$endif}
    hdr_frag_offset	: QWord;
    hdr_src_req		: opal_ptr_t;
    hdr_dst_req		: opal_ptr_t;
  end;
  
  mca_pml_ob1_ack_hdr_t = packed record
    hdr_common		: mca_pml_ob1_common_hdr_t;
{$if defined(OPAL_ENABLE_HETEROGENEOUS_SUPPORT)}
    hdr_padding		: array[0..5] of Byte;
{$endif}
    hdr_src_req		: opal_ptr_t;
    hdr_dst_req		: opal_ptr_t;
    hdr_send_offset	: QWord;
    hdr_send_size	: QWord;
  end;
  
  mca_pml_ob1_rdma_hdr_t = packed record
    hdr_common		: mca_pml_ob1_common_hdr_t;
{$if defined(OPAL_ENABLE_HETEROGENEOUS_SUPPORT)}
    hdr_padding		: array[0..1] of Byte;
{$endif}
    hdr_req		: opal_ptr_t;      
    hdr_frag		: opal_ptr_t;     
    hdr_recv_req	: opal_ptr_t; 
    hdr_rdma_offset	: QWord;
    hdr_dst_ptr		: QWord; 
    hdr_dst_size	: QWord;
  end;
  
  mca_pml_ob1_fin_hdr_t = packed record
    hdr_common	: mca_pml_ob1_common_hdr_t;
{$if defined(OPAL_ENABLE_HETEROGENEOUS_SUPPORT)}
    hdr_padding	: array[0..1] of Byte;
{$endif}
    hdr_size	: int64;
    hdr_frag	: opal_ptr_t;
  end;
  
  mca_pml_ob1_hdr_t = packed record
   Case byte Of 
     0: (hdr_common: mca_pml_ob1_common_hdr_t);
     1: (hdr_match: mca_pml_ob1_match_hdr_t);
     2: (hdr_rndv: mca_pml_ob1_rendezvous_hdr_t);
     3: (hdr_rget: mca_pml_ob1_rget_hdr_t);
     4: (hdr_frag: mca_pml_ob1_frag_hdr_t);
     5: (hdr_ack: mca_pml_ob1_ack_hdr_t);
     6: (hdr_rdma: mca_pml_ob1_rdma_hdr_t);
     7: (hdr_fin: mca_pml_ob1_fin_hdr_t);
  end;
   
  mca_btl_base_segment_t = packed record
    seg_addr	: opal_ptr_t;
    seg_len	: QWord;
  end;
  
  mca_pml_ob1_buffer_t = packed record
    len		: valuint;
    addr	: Pointer;
  end;

  mca_pml_ob1_recv_frag_t = packed record
    super		: opal_free_list_item_t;
    hdr			: mca_pml_ob1_hdr_t;
    num_segments	: valuint;
    range		: Pmca_pml_ob1_recv_frag_t;
    btl			: Pmca_btl_base_module_t;
    segments		: array[0..MCA_BTL_DES_MAX_SEGMENTS-1] of mca_btl_base_segment_t;
    buffers		: array[0..MCA_BTL_DES_MAX_SEGMENTS-1] of mca_pml_ob1_buffer_t;
    addr		: array[0..0] of Byte;
  end;
  
  mca_pml_ob1_comm_proc_t = packed record
    super		: opal_object_t;
    ompi_proc		: Pompi_proc_t;
    expected_sequence	: Word;
    send_sequence	: integer; 
    frags_cant_match	: Pmca_pml_ob1_recv_frag_t;  
    specific_receives	: opal_list_t; 
    unexpected_frags	: opal_list_t;  
  end;
 
  mca_pml_comm_t = packed record
    super		: opal_object_t;
    recv_sequence	: DWord;
    matching_lock	: opal_mutex_t; 
    wild_receives	: opal_list_t;  
    proc_lock		: opal_mutex_t;
    procs		: Pmca_pml_ob1_comm_proc_t;
    num_procs		: valuint;
    last_probed		: valuint;
  end;
