
#include <linux/decompress/generic.h>
#include "cpiofs.h"

#include "inode.c"

static const struct super_operations cpiofs_s_ops = {
	.alloc_inode	= cpiofs_alloc_inode,
/*	.destroy_inode	= cpiofs_destroy_inode,

	.dirty_inode	= cpiofs_dirty_inode,
	.write_inode	= cpiofs_write_inode,
	.drop_inode		= cpiofs_drop_inode,
	.evict_inode	= cpiofs_evict_inode,
	.put_super		= cpiofs_put_super,
	.sync_fs		= cpiofs_sync_fs,
	.freeze_fs		= cpiofs_freeze_fs,
	.unfreeze_fs	= cpiofs_unfreeze_fs,
	.statfs			= cpiofs_statfs,
	.remount_fs		= cpiofs_remount_fs,
	.umount_begin	= cpiofs_umount_begin,

	.show_options	= cpiofs_show_options,*/
};

static int cpiofs_fill_super(struct super_block *sb, void *data, int silent)
{
	sb->s_op = &cpiofs_s_ops;
	int error;
	return error;
}

static struct dentry *cpiofs_mount(struct file_system_type *fs_type,
						int flags, const char *dev_name, void *data)
{
	/*
	 *	mount_nodev instantiates an anonymous superblock by setting s->s_dev
	 *	using get_anon_bdev(dev_t *).  cpiofs_fill_super is hence left to
	 *	fill in the fields other than those that sget sets for you:
	 *		s_list, s_instances, s_id, s_shrink
	 */
	return mount_nodev(fs_type, flags, data, cpiofs_fill_super);
}

static struct file_system_type cpiofs_fs_type = {
	.name		= "cpiofs",
	.fs_flags	= 0,
	.mount		= cpiofs_mount,
	.kill_sb	= kill_anon_super,
	.owner		= THIS_MODULE,
	.next		= NULL,
};
MODULE_ALIAS_FS("cpiofs");

static int __init init_cpiofs_fs(void)
{
	return register_filesystem(&cpiofs_fs_type);
}

static void __exit exit_cpiofs_fs(void)
{
	unregister_filesystem(&cpiofs_fs_type);
}

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Victor van Poppelen <vvanpo@gmail.com>");

module_init(init_cpiofs_fs)
module_exit(exit_cpiofs_fs)

