 
  Pevent = ^opal_event_t;
  Pevent_base = ^event_base;
  Peventop = ^eventop;
  Ptimeval = ^timeval;

  evutil_socket_t = integer;

  timeval = packed record
    tv_sec: integer;
    tv_usec: integer;    
  end;
  
  Tev_timeout_pos = packed record
    Case Byte of
	0: (ev_next_with_common_timeout: TAILQ_ENTRY(event));
	1: (min_heap_idx: integer);
  end;

  Tev_io = packed record
	ev_io_next: TAILQ_ENTRY(event);
	ev_timeout: timeval;
  end;
  
  Tev_signal = packed record
	ev_signal_next: TAILQ_ENTRY(event);
	ev_ncalls: smallint;
	ev_pncalls: ^smallint;
  end;
  
  T_ev = packed record
    Case Byte of
	0: (ev_io: Tev_io);
	1: (ev_signal: Tev_signal);
  end;
  
  opal_event_t = packed record
	ev_active_next: TAILQ_ENTRY(event);
	ev_next: TAILQ_ENTRY(event);
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

  eventop = packed record
	name: PChar;
	init = procedure(p1: Pevent_base);
	add = function(p1: Pevent_base; fd: evutil_socket_t; old: smallint; events: smallint; fdinfo: pointer): integer;
	del = function(p1: Pevent_base; fd: evutil_socket_t; old: smallint; events: smallint; fdinfo: pointer): integer;
	dispatch = function(p1: Pevent_base; p2: Ptimeval): integer;
	dealloc = procedure(p1: Pevent_base);
	need_reinit: integer;
	features: event_method_feature;
	fdinfo_len: valuint;
  end;

  event_change = packed record
	fd: evutil_socket_t;
	old_events: smallint;
	read_change: Word;
	write_change: Word;
  end;

  event_changelist = packed record
	changes: Pevent_change;
	n_changes: integer;
	changes_size: integer;
  end;
  
  Const
    _SIGSET_NWORDS = 1024 / (8 * sizeof (DWord));
  
  Type
  __sigset_t = packed record
     __val: array[0.._SIGSET_NWORDS-1] of DWord;
  end;

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
    sa_handler: __sighandler_t;
{$endif}
    sa_mask: __sigset_t;
    sa_flags: integer;
    void sa_restorer = procedure();
  end;
  
  evsig_info = packed record
	ev_signal: opal_event_t;
	ev_signal_pair: array[0..1] of evutil_socket_t;
	ev_signal_added: integer;
	ev_n_signals_added: integer;
{$ifdef _EVENT_HAVE_SIGACTION}
	sh_old: PPsigaction;
{$else}
	sh_old: PPev_sighandler_t;
{$endif}
	sh_old_max: integer;
  end;
  
  event_base = packed record
	evsel: Peventop;
	evbase: Pointer;
	changelist: event_changelist;
	evsigsel: Peventop;
	sig: evsig_info;
	virtual_event_count: integer;
	event_count: integer;
	event_count_active: integer;
	event_gotterm: integer;
	event_break: integer;
	event_continue: integer;
	event_running_priority: integer;
	running_loop: integer;
	activequeues: event_list;
	nactivequeues: integer;
	common_timeout_queues: ^^common_timeout_list;
	n_common_timeouts: integer;
	n_common_timeouts_allocated: unteger;
	defer_queue: deferred_cb_queue;
	io: event_io_map;
	sigmap: event_signal_map;
	eventqueue: event_list;
	event_tv: timeval;
	timeheap: min_heap;
	tv_cache: timeval;
{$if defined(_EVENT_HAVE_CLOCK_GETTIME) && defined(CLOCK_MONOTONIC)}
	tv_clock_diff: timeval;
	last_updated_clock_diff: time_t;
{$endif}

{$ifndef _EVENT_DISABLE_THREAD_SUPPORT}
	th_owner_id: DWord;
	th_base_lock: Pointer;
	current_event: Pevent;
	current_event_cond: Pointer;
	current_event_waiters: integer;
{$endif}

{$ifdef WIN32}
	iocp: Pevent_iocp_port;
{$endif}
	flags: event_base_config_flag;
	is_notify_pending: integer;
	th_notify_fd: array[0..1] of evutil_socket_t;
	th_notify: event;
	th_notify_fn = function(base: Pevent_base): integer;
  end;


  