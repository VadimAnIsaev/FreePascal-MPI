 
  Pevent = ^opal_event_t;
  PPevent = ^Pevent;
  Pevent_base = ^event_base;
  Peventop = ^eventop;
  Ptimeval = ^timeval;
  Pevent_change = ^event_change;
  Popal_event_t = ^opal_event_t;
  PPopal_event_t = ^Popal_event_t;
  Pcommon_timeout_list = ^common_timeout_list;
  PPcommon_timeout_list = ^Pcommon_timeout_list;
  Pdeferred_cb_queue = ^deferred_cb_queue;
  Pdeferred_cb = ^deferred_cb;
  PPdeferred_cb = ^Pdeferred_cb;
  Pevent_map_entry = ^event_map_entry;
{$ifdef WIN32}  
  PHANDLE = ^THANDLE;
  Pevent_iocp_port = ^event_iocp_port;
{$endif}

  evutil_socket_t = integer;

  timeval = packed record
    tv_sec: integer;
    tv_usec: integer;    
  end;
  
  TT1 = packed record
	tqe_next: Pevent;
	tqe_prev: PPevent;
  end;
  Tev_timeout_pos = packed record
    Case Byte of
	0: (ev_next_with_common_timeout: TT1);
	1: (min_heap_idx: integer);
  end;

  Tev_io = packed record
	ev_io_next: TT1;
	ev_timeout: timeval;
  end;
  
  Tev_signal = packed record
	ev_signal_next: TT1;
	ev_ncalls: smallint;
	ev_pncalls: ^smallint;
  end;
  
  T_ev = packed record
    Case Byte of
	0: (ev_io: Tev_io);
	1: (ev_signal: Tev_signal);
  end;
  
  opal_event_t = packed record
	ev_active_next: TT1;
	ev_next: TT1;
        ev_timeout_pos: Tev_timeout_pos;
	ev_fd: evutil_socket_t;
	ev_base: Pevent_base;
	_ev: T_ev;
	ev_events: smallint;
	ev_res: smallint;
	ev_flags: smallint;
	ev_pri: Byte;
	ev_closure: Byte;
	ev_timeout: timeval;
        ev_callback: procedure(p1: evutil_socket_t; p2: smallint; arg: Pointer);
	ev_arg: Pointer;
  end;

  event_method_feature = (
    EV_FEATURE_ET = $01,
    EV_FEATURE_O1 = $02,
    EV_FEATURE_FDS = $04
  );

  eventop = packed record
	name		: PChar;
	init		: procedure(p1: Pevent_base);
	add		: function(p1: Pevent_base; fd: evutil_socket_t; old: smallint; events: smallint; fdinfo: pointer): integer;
	del		: function(p1: Pevent_base; fd: evutil_socket_t; old: smallint; events: smallint; fdinfo: pointer): integer;
	dispatch	: function(p1: Pevent_base; p2: Ptimeval): integer;
	dealloc		: procedure(p1: Pevent_base);
	need_reinit	: integer;
	features	: event_method_feature;
	fdinfo_len	: valuint;
  end;

  event_change = packed record
	fd		: evutil_socket_t;
	old_events	: smallint;
	read_change	: Word;
	write_change	: Word;
  end;

  event_changelist = packed record
	changes		: Pevent_change;
	n_changes	: integer;
	changes_size	: integer;
  end;
  
  __sigset_t = packed record
     __val: array[0..3] of DWord;
  end;

  ev_sighandler_t = procedure(p1: integer);
  
  sigaction = packed record
{$ifdef __USE_POSIX199309}
    union
      {
	__sighandler_t sa_handler;
	void (*sa_sigaction) (int, siginfo_t *, void *);
      }
    __sigaction_handler;
# define sa_handler	__sigaction_handler.sa_handler
# define sa_sigaction	__sigaction_handler.sa_sigaction
{$else}
    sa_handler: ev_sighandler_t;
{$endif}
    sa_mask: __sigset_t;
    sa_flags: integer;
    sa_restorer: procedure();
  end;
  
  evsig_info = packed record
	ev_signal		: opal_event_t;
	ev_signal_pair		: array[0..1] of evutil_socket_t;
	ev_signal_added		: integer;
	ev_n_signals_added	: integer;
{$ifdef _EVENT_HAVE_SIGACTION}
	sh_old			: PPsigaction;
{$else}
	sh_old			: ev_sighandler_t;
{$endif}
	sh_old_max		: integer;
  end;

  event_list = packed record
  	tqh_first: Popal_event_t;
	tqh_last: PPopal_event_t;
  end;	

  common_timeout_list = packed record
	events		: event_list;
	duration	: timeval;
	timeout_event	: opal_event_t;
	base		: Pevent_base;
  end;

  Tcb_next = packed record
  	tqh_next: Pdeferred_cb;
	tqh_prev: PPdeferred_cb;
  end;	
  
  deferred_cb_fn = procedure(p1: Pdeferred_cb; p2: pointer);
  
  deferred_cb = packed record
	cb_next: Tcb_next;
	queued: DWord;
	cb: deferred_cb_fn;
	arg: pointer;
  end;

  
  Tdeferred_cb_list = packed record
  	tqh_first: Pdeferred_cb;
	tqh_last: PPdeferred_cb;
  end;	
  
  deferred_cb_queue = packed record
	lock: pointer;
	active_count: integer;
	notify_fn: procedure(p1: Pdeferred_cb_queue; p2: pointer);
	notify_arg: pointer;
	deferred_cb_list: Tdeferred_cb_list;
  end;

  event_signal_map = packed record
	entries: pointer;
	nentries: integer;
  end;

  Tevmap_io = packed record
	events: event_list;
	nread: Word;
	nwrite: Word;
  end;
  Tent = packed record
	evmap_io: Tevmap_io;
  end;

{$ifdef HT_CACHE_HASH_VALUES}
  Tmap_node = packed record
    hte_next: Pevent_map_entry;
    hte_hash: DWord;
  end;
{$else}
  Tmap_node = packed record
    hte_next: Pevent_map_entry; 
  end;
{$endif}

  event_map_entry = packed record
	map_node: Tmap_node;
	fd: evutil_socket_t;
	ent: Tent;
  end;

{$ifdef EVMAP_USE_HT}
  event_io_map = Tmap_node;
{$else}
  event_io_map = event_signal_map;
{$endif}


  min_heap = packed record
	p: opal_event_t;
	n: DWord;
	a: DWord;
  end;

{$ifdef WIN32}
  event_iocp_port = packed record
	port: THANDLE;
	lock: CRITICAL_SECTION;
	n_threads: smallint;
	shutdown: smallint;
	ms: integer;
	threads: PHANDLE;
	n_live_threads: smallint;
	shutdownSemaphore: PHANDLE;
  end;
{$endif}

  event_base_config_flag = (
	EVENT_BASE_FLAG_NOLOCK = $01,
	EVENT_BASE_FLAG_IGNORE_ENV = $02,
	EVENT_BASE_FLAG_STARTUP_IOCP = $04,
	EVENT_BASE_FLAG_NO_CACHE_TIME = $08,
	EVENT_BASE_FLAG_EPOLL_USE_CHANGELIST = $10
  );
  
  event_base = packed record
	evsel				: Peventop;
	evbase				: Pointer;
	changelist			: event_changelist;
	evsigsel			: Peventop;
	sig				: evsig_info;
	virtual_event_count		: integer;
	event_count			: integer;
	event_count_active		: integer;
	event_gotterm			: integer;
	event_break			: integer;
	event_continue			: integer;
	event_running_priority		: integer;
	running_loop			: integer;
	activequeues			: event_list;
	nactivequeues			: integer;
	common_timeout_queues		: PPcommon_timeout_list;
	n_common_timeouts		: integer;
	n_common_timeouts_allocated	: integer;
	defer_queue			: deferred_cb_queue;
	io				: event_io_map;
	sigmap				: event_signal_map;
	eventqueue			: event_list;
	event_tv			: timeval;
	timeheap			: min_heap;
	tv_cache			: timeval;
{$if defined(_EVENT_HAVE_CLOCK_GETTIME)} 
  {$if defined(CLOCK_MONOTONIC)}
	tv_clock_diff			: timeval;
	last_updated_clock_diff		: integer;
  {$endif}
{$endif}
{$ifndef _EVENT_DISABLE_THREAD_SUPPORT}
	th_owner_id			: DWord;
	th_base_lock			: Pointer;
	current_event			: Pevent;
	current_event_cond		: Pointer;
	current_event_waiters		: integer;
{$endif}

{$ifdef WIN32}
	iocp				: Pevent_iocp_port;
{$endif}
	flags				: event_base_config_flag;
	is_notify_pending		: integer;
	th_notify_fd			: array[0..1] of evutil_socket_t;
	th_notify			: opal_event_t;
	th_notify_fn			: function(base: Pevent_base): integer;
  end;


  