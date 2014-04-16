
#include <linux/fs.h>
#include <linux/decompress/generic.h>

static struct file_system_type cpiofs_fs_type = {
	.name		= "cpiofs",
	.fs_flags	= 0,
	.mount		= cpiofs_mount,
	.kill_sb	= kill_block_super,
	.owner		= THIS_MODULE,
	.next		= NULL,
};

static int __init init_cpiofs_fs(void)
{
	return register_filesystem(&cpiofs_fs_type);
}

static void __exit exit_cpiofs_fs(void)
{
	unregister_filesystem(&cpiofs_fs_type);
}

MODULE_LICENSE("GPL");

module_init(init_cpiofs_fs)
module_exit(exit_cpiofs_fs)

