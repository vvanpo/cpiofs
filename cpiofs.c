
#include <linux/module.h>
#include <linux/fs.h>
#include <linux/decompress/generic.h>

struct dentry *cpiofs_mount(struct file_system_type *fs_type, int flags,
							const char *dev_name, void *data)
{

}

static struct file_system_type cpiofs_fs_type = {
	.name		= "cpiofs",
	.fs_flags	= 0,
	.mount		= cpiofs_mount,
	.kill_sb	= kill_block_super,
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

