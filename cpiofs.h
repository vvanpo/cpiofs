
#include <linux/module.h>
#include <linux/fs.h>

extern struct dentry *cpiofs_mount(struct file_system_type *fs_type, int flags,
							const char *dev_name, void *data);
