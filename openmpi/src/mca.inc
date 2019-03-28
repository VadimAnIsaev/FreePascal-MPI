{$I ptrs.inc}  
{$I opal.inc}  

  mca_base_component_data_2_0_0_t = packed record
    param_field	: DWord;
    reserved	: array[0..31] of Char;
  end;
  mca_base_component_data_t = mca_base_component_data_2_0_0_t;

  mca_base_open_component_1_0_0_fn_t = function(): integer;
  mca_base_close_component_1_0_0_fn_t = function(): integer;
  mca_base_query_component_2_0_0_fn_t = function(module: Pmca_base_module_2_0_0_t; priority: Pinteger): integer;
  mca_base_register_component_params_2_0_0_fn_t = function(): integer;

  mca_base_component_2_1_0_t = packed record
    mca_major_version			: integer;
    mca_minor_version			: integer;
    mca_release_version			: integer;
    mca_project_name			: array[0..MCA_BASE_MAX_PROJECT_NAME_LEN] of Char;
    mca_project_major_version		: integer;
    mca_project_minor_version		: integer;
    mca_project_release_version		: integer;
    mca_type_name			: array[0..MCA_BASE_MAX_TYPE_NAME_LEN] of Char;
    mca_type_major_version		: integer;
    mca_type_minor_version		: integer;
    mca_type_release_version		: integer;
    mca_component_name			: array[0..MCA_BASE_MAX_COMPONENT_NAME_LEN] of Char;
    mca_component_major_version		: integer;
    mca_component_minor_version		: integer;
    mca_component_release_version	: integer;
    mca_open_component			: mca_base_open_component_1_0_0_fn_t;
    mca_close_component			: mca_base_close_component_1_0_0_fn_t;
    mca_query_component			: mca_base_query_component_2_0_0_fn_t;
    mca_register_component_params	: mca_base_register_component_params_2_0_0_fn_t;
    mca_component_flags			: integer;
    reserved				: array[0..27] of Char;
  end;
  mca_base_component_t = mca_base_component_2_1_0_t;

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
  
{$I mca_coll.inc}
{$I mca_rcache.inc}
{$I mca_btl.inc}
{$I mca_pml.inc}
    
  mca_base_module_2_0_0_t = packed record
    dummy_value: integer;
  end;
  
  mca_topo_base_component_init_query_2_2_0_fn_t = function(enable_progress_threads: longbool; enable_mpi_threads: longbool): integer;
  mca_topo_base_component_comm_query_2_2_0_fn_t = function(const comm: Pompi_communicator_t; priority: Pinteger; ttype: DWord): Pmca_topo_base_module_t;
  
  mca_topo_base_component_t = packed record
    topoc_version	: mca_base_component_t;
    topoc_data		: mca_base_component_data_t;
    topoc_init_query	: mca_topo_base_component_init_query_2_2_0_fn_t;
    topoc_comm_query	: mca_topo_base_component_comm_query_2_2_0_fn_t;
  end; 

  mca_topo_base_comm_cart_2_2_0_t = packed record
    super	: opal_object_t;
    ndims	: integer;
    dims	: Pinteger;
    periods	: Pinteger;
    coords	: Pinteger;
  end;

  mca_topo_base_comm_graph_2_2_0_t = packed record
    super	: opal_object_t;
    nnodes	: integer;
    index	: Pinteger;
    edges	: Pinteger;
  end;
  mca_topo_base_comm_graph_t = mca_topo_base_comm_graph_2_2_0_t;

  mca_topo_base_comm_dist_graph_2_2_0_t = packed record
    super	: opal_object_t;
    iin		: Pinteger;
    inw		: Pinteger;
    oout	: Pinteger;
    outw	: Pinteger;
    indegree	: integer;
    outdegree	: integer;
    weighted	: longbool;
  end;
  
  mca_topo_base_comm_cgd_union_t = packed record
    graph	: Pmca_topo_base_comm_graph_2_2_0_t;
    cart	: Pmca_topo_base_comm_cart_2_2_0_t;
    dist_graph	: Pmca_topo_base_comm_dist_graph_2_2_0_t;
  end;

  mca_topo_base_module_cart_coords_fn_t = function(comm: Pompi_communicator_t; rank: integer; maxdims: integer; coords: Pinteger): integer;
  mca_topo_base_module_cart_create_fn_t = function(topo_module: Pmca_topo_base_module_t; old_comm: Pompi_communicator_t; ndims: integer; const dims: Pinteger; const periods: Pinteger; reorder: longbool; comm_topo: Pompi_communicator_t): integer;		 
  mca_topo_base_module_cart_get_fn_t = function(comm: Pompi_communicator_t; maxdims: integer; dims: Pinteger; periods: Pinteger; coords: Pinteger): integer;
  mca_topo_base_module_cartdim_get_fn_t = function(comm: Pompi_communicator_t; ndims: Pinteger): integer;
  mca_topo_base_module_cart_map_fn_t = function(comm: Pompi_communicator_t; ndims: integer; const dims: Pinteger; const periods: Pinteger; newrank: Pinteger): integer;
  mca_topo_base_module_cart_rank_fn_t = function(comm: Pompi_communicator_t; const coords: pinteger; rank: Pinteger): integer;
  mca_topo_base_module_cart_shift_fn_t = function(comm: Pompi_communicator_t; direction: integer; disp: integer; rank_source: Pinteger; rank_dest: Pinteger): integer;
  mca_topo_base_module_cart_sub_fn_t = function(comm: Pompi_communicator_t; const remain_dims: Pinteger; new_comm: Pompi_communicator_t): integer;
 
  mca_topo_base_cart_module_2_2_0_t = packed record
    cart_coords	: mca_topo_base_module_cart_coords_fn_t;
    cart_create	: mca_topo_base_module_cart_create_fn_t;
    cart_get	: mca_topo_base_module_cart_get_fn_t;
    cartdim_get	: mca_topo_base_module_cartdim_get_fn_t;
    cart_map	: mca_topo_base_module_cart_map_fn_t;
    cart_rank	: mca_topo_base_module_cart_rank_fn_t;
    cart_shift	: mca_topo_base_module_cart_shift_fn_t;
    cart_sub	: mca_topo_base_module_cart_sub_fn_t;
  end;
  
  mca_topo_base_module_graph_create_fn_t = function(topo_module: Pmca_topo_base_module_t; old_comm: Pompi_communicator_t; nnodes: integer; const index: Pinteger; const edges: Pinteger; reorder:longbool; new_comm: PPompi_communicator_t): integer;
  mca_topo_base_module_graph_get_fn_t = function(comm: Pompi_communicator_t; maxindex: integer;maxedges: integer; index: Pinteger; edges: Pinteger): integer;
  mca_topo_base_module_graph_map_fn_t = function(comm: Pompi_communicator_t; nnodes: integer; const index: Pinteger; const edges: Pinteger; newrank: Pinteger): integer;
  mca_topo_base_module_graphdims_get_fn_t = function(comm: Pompi_communicator_t; nnodes: Pinteger; nnedges: Pinteger): integer;
  mca_topo_base_module_graph_neighbors_fn_t = function(comm: Pompi_communicator_t; rank: integer; maxneighbors: integer; neighbors: Pinteger): integer;
  mca_topo_base_module_graph_neighbors_count_fn_t = function(comm: Pompi_communicator_t; rank: integer; nneighbors: Pinteger): integer;
  
  mca_topo_base_graph_module_2_2_0_t = packed record
    graph_create: mca_topo_base_module_graph_create_fn_t;
    graph_get: mca_topo_base_module_graph_get_fn_t;
    graph_map: mca_topo_base_module_graph_map_fn_t;
    graphdims_get: mca_topo_base_module_graphdims_get_fn_t;
    graph_neighbors: mca_topo_base_module_graph_neighbors_fn_t;
    graph_neighbors_count: mca_topo_base_module_graph_neighbors_count_fn_t;
  end;

 mca_topo_base_module_dist_graph_create_fn_t = function(module: Pmca_topo_base_module_t; old_comm: Pompi_communicator_t; n: integer; const nodes: array of integer; const degrees: array of integer; const targets: array of integer; const weights: array of integer; info: Popal_info_t; reorder: integer; new_comm: PPompi_communicator_t): integer;
 mca_topo_base_module_dist_graph_create_adjacent_fn_t = function(module: Pmca_topo_base_module_t; comm_old: Pompi_communicator_t; indegree: integer; const sources: array of integer; const sourceweights: array of integer; outdegree: integer; const destinations: array of integer; const destweights: array of integer; info: Popal_info_t; reorder: integer; comm_dist_graph: PPompi_communicator_t): integer;
 mca_topo_base_module_dist_graph_neighbors_fn_t = function(comm: Pompi_communicator_t; maxindegree: integer; sources: array of integer; sourceweights: array of integer; maxoutdegree: integer; destinations: array of integer; destweights: array of integer): integer; 
 mca_topo_base_module_dist_graph_neighbors_count_fn_t = function(comm: Pompi_communicator_t; inneighbors: PInteger; outneighbors: Pinteger; weighted: Pinteger): integer;
 
 mca_topo_base_dist_graph_module_2_2_0_t = packed record
    dist_graph_create		: mca_topo_base_module_dist_graph_create_fn_t;
    dist_graph_create_adjacent	: mca_topo_base_module_dist_graph_create_adjacent_fn_t;
    dist_graph_neighbors	: mca_topo_base_module_dist_graph_neighbors_fn_t;
    dist_graph_neighbors_count	: mca_topo_base_module_dist_graph_neighbors_count_fn_t;
 end;
  
  
  Ttopo = packed record
    Case byte Of
      0: (cart		: mca_topo_base_cart_module_2_2_0_t);
      1: (graph		: mca_topo_base_graph_module_2_2_0_t);
      2: (dist_graph	: mca_topo_base_dist_graph_module_2_2_0_t);
  end;
  
  mca_topo_base_module_t = packed record
    super		: opal_object_t;
    ttype		: DWord;
    reorder		: longbool;
    topo_component	: Pmca_topo_base_component_t;
    topo		: Ttopo;
    mtc			: mca_topo_base_comm_cgd_union_t;
  end;
