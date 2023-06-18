/*	$NetBSD: workqueue.h,v 1.25 2021/12/19 11:40:13 riastradh Exp $	*/

/*-
 * Copyright (c) 2013, 2018 The NetBSD Foundation, Inc.
 * All rights reserved.
 *
 * This code is derived from software contributed to The NetBSD Foundation
 * by Taylor R. Campbell.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND CONTRIBUTORS
 * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED
 * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS
 * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef _LINUX_WORKQUEUE_H_
#define _LINUX_WORKQUEUE_H_

#include <sys/queue.h>
#include <sys/stdbool.h>

#include <linux/kernel.h>	/* container_of */
#include <linux/stringify.h>

#define	INIT_DELAYED_WORK		linux_INIT_DELAYED_WORK
#define	INIT_RCU_WORK			linux_INIT_RCU_WORK
#define	INIT_WORK			linux_INIT_WORK
#define	alloc_ordered_workqueue		linux_alloc_ordered_workqueue
#define	alloc_workqueue			linux_alloc_workqueue
#define	cancel_delayed_work		linux_cancel_delayed_work
#define	cancel_delayed_work_sync	linux_cancel_delayed_work_sync
#define	cancel_work			linux_cancel_work
#define	cancel_work_sync		linux_cancel_work_sync
#define	current_work			linux_current_work
#define	delayed_work_pending		linux_delayed_work_pending
#define	destroy_workqueue		linux_destroy_workqueue
#define	drain_workqueue			linux_drain_workqueue
#define	flush_delayed_work		linux_flush_delayed_work
#define	flush_scheduled_work		linux_flush_scheduled_work
#define	flush_work			linux_flush_work
#define	flush_workqueue			linux_flush_workqueue
#define	mod_delayed_work		linux_mod_delayed_work
#define	queue_delayed_work		linux_queue_delayed_work
#define	queue_rcu_work			linux_queue_rcu_work
#define	queue_work			linux_queue_work
#define	schedule_delayed_work		linux_schedule_delayed_work
#define	schedule_work			linux_schedule_work
#define	system_highpri_wq		linux_system_highpri_wq
#define	system_long_wq			linux_system_long_wq
#define	system_power_efficient_wq	linux_system_power_efficient_wq
#define	system_unbound_wq		linux_system_unbound_wq
#define	system_wq			linux_system_wq
#define	to_delayed_work			linux_to_delayed_work
#define	work_pending			linux_work_pending

struct workqueue_struct;

struct work_struct {
	volatile uintptr_t		work_owner;
	TAILQ_ENTRY(work_struct)	work_entry;
	void	(*func)(struct work_struct *); /* Linux API name */
};

struct delayed_work {
	struct work_struct		work; /* Linux API name */
	struct callout			dw_callout;
	TAILQ_ENTRY(delayed_work)	dw_entry;
	int				dw_resched;
	enum {
		DELAYED_WORK_IDLE,
		DELAYED_WORK_SCHEDULED,
		DELAYED_WORK_RESCHEDULED,
		DELAYED_WORK_CANCELLED,
	}				dw_state;
};

struct rcu_work {
	struct work_struct		work; /* Linux API name */
	struct rcu_head			rw_rcu;
};

#define	WQ_FREEZABLE		__BIT(0)
#define	WQ_HIGHPRI		__BIT(1)
#define	WQ_MEM_RECLAIM		__BIT(2)
#define	WQ_UNBOUND		__BIT(3)

#define	WQ_UNBOUND_MAX_ACTIVE	0

static inline struct delayed_work *
to_delayed_work(struct work_struct *work)
{
	return container_of(work, struct delayed_work, work);
}

extern struct workqueue_struct	*system_highpri_wq;
extern struct workqueue_struct	*system_long_wq;
extern struct workqueue_struct	*system_power_efficient_wq;
extern struct workqueue_struct	*system_unbound_wq;
extern struct workqueue_struct	*system_wq;

int	linux_workqueue_init(void);
void	linux_workqueue_fini(void);

#define	create_singlethread_workqueue(name)				      \
	alloc_ordered_workqueue((name), 0)

struct workqueue_struct *
	alloc_workqueue(const char *, int, unsigned);
struct workqueue_struct *
	alloc_ordered_workqueue(const char *, int);
void	destroy_workqueue(struct workqueue_struct *);
void	flush_workqueue(struct workqueue_struct *);
void	drain_workqueue(struct workqueue_struct *);
void	flush_scheduled_work(void);

void	INIT_WORK(struct work_struct *, void (*)(struct work_struct *));
bool	schedule_work(struct work_struct *);
bool	queue_work(struct workqueue_struct *, struct work_struct *);
bool	cancel_work(struct work_struct *);
bool	cancel_work_sync(struct work_struct *);
bool	flush_work(struct work_struct *);
bool	work_pending(const struct work_struct *);

void	INIT_DELAYED_WORK(struct delayed_work *,
	    void (*)(struct work_struct *));
bool	schedule_delayed_work(struct delayed_work *, unsigned long);
bool	queue_delayed_work(struct workqueue_struct *, struct delayed_work *,
	    unsigned long ticks);
bool	mod_delayed_work(struct workqueue_struct *, struct delayed_work *,
	    unsigned long ticks);
bool	cancel_delayed_work(struct delayed_work *);
bool	cancel_delayed_work_sync(struct delayed_work *);
bool	flush_delayed_work(struct delayed_work *);
bool	delayed_work_pending(const struct delayed_work *);

void	INIT_RCU_WORK(struct rcu_work *, void (*fn)(struct work_struct *));
void	queue_rcu_work(struct workqueue_struct *, struct rcu_work *);

struct work_struct *
	current_work(void);

#define	INIT_WORK_ONSTACK		INIT_WORK
#define	INIT_DELAYED_WORK_ONSTACK	INIT_DELAYED_WORK
#define	destroy_delayed_work_on_stack(dw)	__nothing

static inline void
destroy_work_on_stack(struct work_struct *work)
{
}

#endif  /* _LINUX_WORKQUEUE_H_ */
