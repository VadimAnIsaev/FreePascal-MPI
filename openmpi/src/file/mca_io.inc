  mca_io_base_version_t = (
    MCA_IO_BASE_V_NONE,
    MCA_IO_BASE_V_2_0_0,
    MCA_IO_BASE_V_MAX
  );

  Pmca_io_base_module_2_0_0_t = ^mca_io_base_component_2_0_0_t;
  
  mca_io_base_component_init_query_fn_t = function(bool enable_progress_threads, bool enable_mpi_threads): integer;
  mca_io_base_component_file_query_2_0_0_fn_t = function(struct ompi_file_t *file, struct mca_io_base_file_t **private_data,
 							     int *priority): Pmca_io_base_module_2_0_0_t;
  mca_io_base_component_file_unquery_fn_t = function(struct ompi_file_t *file, struct mca_io_base_file_t *private_data): integer;
  mca_io_base_component_file_delete_query_fn_t = function(const char *filename, 
                                                        struct opal_info_t *info,
                                                        struct mca_io_base_delete_t **private_data,
                                                        bool *usable, 
                                                        int *priority): integer;
  mca_io_base_component_file_delete_select_fn_t = function(const char *filename, struct opal_info_t *info,
							     struct mca_io_base_delete_t *private_data);
  mca_io_base_component_file_delete_unselect_fn_t = function(const char *filename, struct opal_info_t *info,
							     struct mca_io_base_delete_t *private_data);
  mca_io_base_component_register_datarep_fn_t = function(
                                              const char *,
                                              MPI_Datarep_conversion_function*,
                                              MPI_Datarep_conversion_function*,
                                              MPI_Datarep_extent_function*,
                                              void*): integer;


  
  mca_io_base_component_2_0_0_t = packed record
    io_version: mca_base_component_t;
    io_data: mca_base_component_data_t;
    io_init_query: mca_io_base_component_init_query_fn_t;
    io_file_query: mca_io_base_component_file_query_2_0_0_fn_t;
    io_file_unquery: mca_io_base_component_file_unquery_fn_t;
    io_delete_query: mca_io_base_component_file_delete_query_fn_t;
    io_delete_unquery: mca_io_base_component_file_delete_unselect_fn_t;
    io_delete_select: mca_io_base_component_file_delete_select_fn_t;
    io_register_datarep: mca_io_base_component_register_datarep_fn_t;
  end;
  
  mca_io_base_components_t = packed record
    Case byte of
      0: (v2_0_0: mca_io_base_component_2_0_0_t);
  end;
