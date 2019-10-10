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


  mca_io_base_module_file_open_fn_t = function(struct ompi_communicator_t *comm, const char *filename, int amode,
     struct opal_info_t *info, struct ompi_file_t *fh): integer;
  mca_io_base_module_file_close_fn_t = function(struct ompi_file_t *fh): integer;

  mca_io_base_module_file_set_size_fn_t = function(struct ompi_file_t *fh, MPI_Offset size): integer;
  mca_io_base_module_file_preallocate_fn_t = fucntion(struct ompi_file_t *fh, MPI_Offset size): integer;
  mca_io_base_module_file_get_size_fn_t = function(struct ompi_file_t *fh, MPI_Offset *size): integer;
  mca_io_base_module_file_get_amode_fn_t = function(struct ompi_file_t *fh, int *amode): integer;

  mca_io_base_module_file_set_view_fn_t = function(struct ompi_file_t *fh, MPI_Offset disp, struct ompi_datatype_t *etype,
     struct ompi_datatype_t *filetype, const char *datarep,
     struct opal_info_t *info): integer;
  mca_io_base_module_file_get_view_fn_t = function(struct ompi_file_t *fh, MPI_Offset *disp,
     struct ompi_datatype_t **etype, struct ompi_datatype_t **filetype,
     char *datarep): integer;

  mca_io_base_module_file_read_at_fn_t = function(struct ompi_file_t *fh, MPI_Offset offset, void *buf,
     int count, struct ompi_datatype_t *datatype,
     struct ompi_status_public_t *status): integer;
  mca_io_base_module_file_read_at_all_fn_t = function(struct ompi_file_t *fh, MPI_Offset offset, void *buf,
     int count, struct ompi_datatype_t *datatype,
     struct ompi_status_public_t *status): integer;
  mca_io_base_module_file_write_at_fn_t = function(struct ompi_file_t *fh, MPI_Offset offset, const void *buf,
     int count, struct ompi_datatype_t *datatype,
     struct ompi_status_public_t *status): integer;
  mca_io_base_module_file_write_at_all_fn_t = function(struct ompi_file_t *fh, MPI_Offset offset, const void *buf,
     int count, struct ompi_datatype_t *datatype,
     struct ompi_status_public_t *status): integer;

  mca_io_base_module_file_iread_at_fn_t = function(struct ompi_file_t *fh, MPI_Offset offset, void *buf,
     int count, struct ompi_datatype_t *datatype,
     struct ompi_request_t **request): integer;
  mca_io_base_module_file_iwrite_at_fn_t = function(struct ompi_file_t *fh, MPI_Offset offset, const void *buf,
     int count, struct ompi_datatype_t *datatype,
     struct ompi_request_t **request): integer;

  mca_io_base_module_file_iread_at_all_fn_t = function(struct ompi_file_t *fh, MPI_Offset offset, void *buf,
     int count, struct ompi_datatype_t *datatype,
     struct ompi_request_t **request): integer;
  mca_io_base_module_file_iwrite_at_all_fn_t = function(struct ompi_file_t *fh, MPI_Offset offset, const void *buf,
     int count, struct ompi_datatype_t *datatype,
     struct ompi_request_t **request): integer;

  mca_io_base_module_file_read_fn_t = function(struct ompi_file_t *fh, void *buf, int count, struct ompi_datatype_t *
     datatype, struct ompi_status_public_t *status): integer;
  mca_io_base_module_file_read_all_fn_t = function(struct ompi_file_t *fh, void *buf, int count, struct ompi_datatype_t *
     datatype, struct ompi_status_public_t *status): integer;
  mca_io_base_module_file_write_fn_t = function(struct ompi_file_t *fh, const void *buf, int count, struct ompi_datatype_t *
     datatype, struct ompi_status_public_t *status): integer;
  mca_io_base_module_file_write_all_fn_t = function(struct ompi_file_t *fh, const void *buf, int count, struct ompi_datatype_t *
     datatype, struct ompi_status_public_t *status): integer;

  mca_io_base_module_file_iread_fn_t = function(struct ompi_file_t *fh, void *buf, int count,
     struct ompi_datatype_t *datatype, struct ompi_request_t **request): integer;
  mca_io_base_module_file_iwrite_fn_t = function(struct ompi_file_t *fh, const void *buf, int count,
     struct ompi_datatype_t *datatype, struct ompi_request_t **request): integer;

typedef int (*mca_io_base_module_file_iread_all_fn_t)
    (struct ompi_file_t *fh, void *buf, int count,
     struct ompi_datatype_t *datatype, struct ompi_request_t **request);
typedef int (*mca_io_base_module_file_iwrite_all_fn_t)
    (struct ompi_file_t *fh, const void *buf, int count,
     struct ompi_datatype_t *datatype, struct ompi_request_t **request);

typedef int (*mca_io_base_module_file_seek_fn_t)
    (struct ompi_file_t *fh, MPI_Offset offset, int whence);
typedef int (*mca_io_base_module_file_get_position_fn_t)
    (struct ompi_file_t *fh, MPI_Offset *offset);
typedef int (*mca_io_base_module_file_get_byte_offset_fn_t)
    (struct ompi_file_t *fh, MPI_Offset offset, MPI_Offset *disp);

typedef int (*mca_io_base_module_file_read_shared_fn_t)
    (struct ompi_file_t *fh, void *buf, int count,
     struct ompi_datatype_t *datatype, struct ompi_status_public_t *status);
typedef int (*mca_io_base_module_file_write_shared_fn_t)
    (struct ompi_file_t *fh, const void *buf, int count,
     struct ompi_datatype_t *datatype, struct ompi_status_public_t *status);
typedef int (*mca_io_base_module_file_iread_shared_fn_t)
    (struct ompi_file_t *fh, void *buf, int count,
     struct ompi_datatype_t *datatype, struct ompi_request_t **request);
typedef int (*mca_io_base_module_file_iwrite_shared_fn_t)
    (struct ompi_file_t *fh, const void *buf, int count,
     struct ompi_datatype_t *datatype, struct ompi_request_t **request);
typedef int (*mca_io_base_module_file_read_ordered_fn_t)
    (struct ompi_file_t *fh, void *buf, int count,
     struct ompi_datatype_t *datatype, struct ompi_status_public_t *status);
typedef int (*mca_io_base_module_file_write_ordered_fn_t)
    (struct ompi_file_t *fh, const void *buf, int count,
     struct ompi_datatype_t *datatype, struct ompi_status_public_t *status);
typedef int (*mca_io_base_module_file_seek_shared_fn_t)
    (struct ompi_file_t *fh, MPI_Offset offset, int whence);
typedef int (*mca_io_base_module_file_get_position_shared_fn_t)
    (struct ompi_file_t *fh, MPI_Offset *offset);

typedef int (*mca_io_base_module_file_read_at_all_begin_fn_t)
    (struct ompi_file_t *fh, MPI_Offset offset, void *buf,
     int count, struct ompi_datatype_t *datatype);
typedef int (*mca_io_base_module_file_read_at_all_end_fn_t)
    (struct ompi_file_t *fh, void *buf, struct ompi_status_public_t *status);
typedef int (*mca_io_base_module_file_write_at_all_begin_fn_t)
    (struct ompi_file_t *fh, MPI_Offset offset, const void *buf,
     int count, struct ompi_datatype_t *datatype);
typedef int (*mca_io_base_module_file_write_at_all_end_fn_t)
    (struct ompi_file_t *fh, const void *buf, struct ompi_status_public_t *status);
typedef int (*mca_io_base_module_file_read_all_begin_fn_t)
    (struct ompi_file_t *fh, void *buf, int count,
     struct ompi_datatype_t *datatype);
typedef int (*mca_io_base_module_file_read_all_end_fn_t)
    (struct ompi_file_t *fh, void *buf, struct ompi_status_public_t *status);
typedef int (*mca_io_base_module_file_write_all_begin_fn_t)
    (struct ompi_file_t *fh, const void *buf, int count,
     struct ompi_datatype_t *datatype);
typedef int (*mca_io_base_module_file_write_all_end_fn_t)
    (struct ompi_file_t *fh, const void *buf, struct ompi_status_public_t *status);
typedef int (*mca_io_base_module_file_read_ordered_begin_fn_t)
    (struct ompi_file_t *fh, void *buf, int count,
     struct ompi_datatype_t *datatype);
typedef int (*mca_io_base_module_file_read_ordered_end_fn_t)
    (struct ompi_file_t *fh, void *buf, struct ompi_status_public_t *status);
typedef int (*mca_io_base_module_file_write_ordered_begin_fn_t)
    (struct ompi_file_t *fh, const void *buf, int count,
     struct ompi_datatype_t *datatype);
typedef int (*mca_io_base_module_file_write_ordered_end_fn_t)
    (struct ompi_file_t *fh, const void *buf, struct ompi_status_public_t *status);

typedef int (*mca_io_base_module_file_get_type_extent_fn_t)
    (struct ompi_file_t *fh, struct ompi_datatype_t *datatype,
     MPI_Aint *extent);

typedef int (*mca_io_base_module_file_set_atomicity_fn_t)
    (struct ompi_file_t *fh, int flag);
typedef int (*mca_io_base_module_file_get_atomicity_fn_t)
    (struct ompi_file_t *fh, int *flag);
typedef int (*mca_io_base_module_file_sync_fn_t)(struct ompi_file_t *fh);
  
  
  
  mca_io_base_module_2_0_0_t = packed record

    { Back-ends to MPI API calls (pretty much a 1-to-1 mapping) }

    io_module_file_open: mca_io_base_module_file_open_fn_t;
    io_module_file_close: mca_io_base_module_file_close_fn_t;

    io_module_file_set_size: mca_io_base_module_file_set_size_fn_t;
    io_module_file_preallocate: mca_io_base_module_file_preallocate_fn_t;
    io_module_file_get_size: mca_io_base_module_file_get_size_fn_t;
    io_module_file_get_amode: mca_io_base_module_file_get_amode_fn_t;

    io_module_file_set_view: mca_io_base_module_file_set_view_fn_t;
    io_module_file_get_view: mca_io_base_module_file_get_view_fn_t;

    io_module_file_read_at: mca_io_base_module_file_read_at_fn_t;
    io_module_file_read_at_all: mca_io_base_module_file_read_at_all_fn_t;
    io_module_file_write_at: mca_io_base_module_file_write_at_fn_t;
    io_module_file_write_at_all: mca_io_base_module_file_write_at_all_fn_t;

    io_module_file_iread_at: mca_io_base_module_file_iread_at_fn_t;
    io_module_file_iwrite_at: mca_io_base_module_file_iwrite_at_fn_t;
    io_module_file_iread_at_all: mca_io_base_module_file_iread_at_all_fn_t;
    io_module_file_iwrite_at_all: mca_io_base_module_file_iwrite_at_all_fn_t;

    io_module_file_read: mca_io_base_module_file_read_fn_t;
    io_module_file_read_all: mca_io_base_module_file_read_all_fn_t;
    io_module_file_write: mca_io_base_module_file_write_fn_t;
    io_module_file_write_all: mca_io_base_module_file_write_all_fn_t;

    io_module_file_iread: mca_io_base_module_file_iread_fn_t;
    io_module_file_iwrite: mca_io_base_module_file_iwrite_fn_t;
    io_module_file_iread_all: mca_io_base_module_file_iread_all_fn_t;
    io_module_file_iwrite_all: mca_io_base_module_file_iwrite_all_fn_t;

    io_module_file_seek: mca_io_base_module_file_seek_fn_t;
    io_module_file_get_position: mca_io_base_module_file_get_position_fn_t;
    io_module_file_get_byte_offset: mca_io_base_module_file_get_byte_offset_fn_t;

    io_module_file_read_shared: mca_io_base_module_file_read_shared_fn_t;
    io_module_file_write_shared: mca_io_base_module_file_write_shared_fn_t;
    io_module_file_iread_shared: mca_io_base_module_file_iread_shared_fn_t;
    io_module_file_iwrite_shared: mca_io_base_module_file_iwrite_shared_fn_t;
    io_module_file_read_ordered: mca_io_base_module_file_read_ordered_fn_t;
    io_module_file_write_ordered: mca_io_base_module_file_write_ordered_fn_t;
    io_module_file_seek_shared: mca_io_base_module_file_seek_shared_fn_t;
    io_module_file_get_position_shared: mca_io_base_module_file_get_position_shared_fn_t;

    io_module_file_read_at_all_begin: mca_io_base_module_file_read_at_all_begin_fn_t;
    io_module_file_read_at_all_end: mca_io_base_module_file_read_at_all_end_fn_t;
    io_module_file_write_at_all_begin: mca_io_base_module_file_write_at_all_begin_fn_t;
    io_module_file_write_at_all_end: mca_io_base_module_file_write_at_all_end_fn_t;
    io_module_file_read_all_begin: mca_io_base_module_file_read_all_begin_fn_t;
    io_module_file_read_all_end: mca_io_base_module_file_read_all_end_fn_t;
    io_module_file_write_all_begin: mca_io_base_module_file_write_all_begin_fn_t;
    io_module_file_write_all_end: mca_io_base_module_file_write_all_end_fn_t;
    io_module_file_read_ordered_begin: mca_io_base_module_file_read_ordered_begin_fn_t;
    io_module_file_read_ordered_end: mca_io_base_module_file_read_ordered_end_fn_t;
    io_module_file_write_ordered_begin: mca_io_base_module_file_write_ordered_begin_fn_t;
    io_module_file_write_ordered_end: mca_io_base_module_file_write_ordered_end_fn_t;

    io_module_file_get_type_extent: mca_io_base_module_file_get_type_extent_fn_t;

    io_module_file_set_atomicity: mca_io_base_module_file_set_atomicity_fn_t;
    io_module_file_get_atomicity: mca_io_base_module_file_get_atomicity_fn_t;
    io_module_file_sync: mca_io_base_module_file_sync_fn_t;
  end;

  
  mca_io_base_modules_t = packed record
    case byte of
      0: (v2_0_0: mca_io_base_module_2_0_0_t);
  end;
