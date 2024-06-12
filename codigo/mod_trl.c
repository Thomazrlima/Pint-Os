struct thread
  {
    int64_t arcodar;
    tid_t tid;
    enum thread_status status;
    char name[16];
    uint8_t *stack;
    int priority;
    struct list_elem allelem;

    struct list_elem elem;

    #ifdef USERPROG
        uint32_t *pagedir;
    #endif

    unsigned magic;
  };

void timer_sleep (int64_t ticks) {
    if (ticks <= 0) {
        return;
    }
    int64_t cmc = timer_ticks();

    if(timer_elapsed(cmc) < ticks){
        thread_sleep(cmc + ticks);
    }
}

void
thread_init (void) 
{
  ASSERT (intr_get_level () == INTR_OFF);
  list_init (&espera);
  lock_init (&tid_lock);
  list_init (&ready_list);
  list_init (&all_list);
  initial_thread = running_thread ();
  init_thread (initial_thread, "main", PRI_DEFAULT);
  initial_thread->status = THREAD_RUNNING;
  initial_thread->tid = allocate_tid ();
}

void thread_sleep(int64_t ticks) {
    struct thread *current_thread = thread_current();

    if (current_thread == idle_thread || ticks <= 0) {
        return;
    }

    int64_t wake_up_tick = timer_ticks() + ticks;

    struct list_elem *e = list_begin(&espera);
    while (e != list_end(&espera)) {
        struct thread *t = list_entry(e, struct thread, elem);
        if (t->arcodar > wake_up_tick) {
            break;
        }
        e = list_next(e);
    }

    current_thread->arcodar = wake_up_tick;
    current_thread->status = THREAD_BLOCKED;
    list_insert(e, &current_thread->elem);

    struct intr_frame if_;
    if_.rsp = current_thread->user_rsp;
    schedule(&if_);
}