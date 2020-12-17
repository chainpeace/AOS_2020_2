#include <linux/syscalls.h>
#include <linux/plmt.h>
#include <asm/pgtable.h>

#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/module.h>
#include <linux/fcntl.h>
#include <asm/uaccess.h>



void kwrite_file(char *data){
	char *filename = "/output.txt";
	int fd;
	loff_t pos = 0;
        struct file *file;
        mm_segment_t old_fs = get_fs ();
        set_fs (KERNEL_DS);
        fd = ksys_open (filename, O_RDWR | O_APPEND | O_CREAT, 0644);


	if (fd >= 0){
		file = fget (fd);
		if (file){
			vfs_write (file, data, strlen(data), &pos);
			fput (file);
		}
		ksys_close(fd);
	}
	set_fs (old_fs);
}

//reseve bit 51st


//native_pte_val(pte)
//pte_flags(pte)
inline pte_t pte_mkfake(pte_t pte){

    return pte_set_flags(pte, PTE_FAKE_MASK);
}
inline pte_t pte_clrfake(pte_t pte){
    return pte_clear_flags(pte, PTE_FAKE_MASK);
}
inline int is_pte_fake(pte_t pte){
    if(native_pte_val(pte) & PTE_FAKE_MASK)
        return 1;
    else 
        return 0;
}
//inline pte_t pte_mkpresent(pte_t pte){}
inline pte_t pte_clrpresent(pte_t pte){

    return pte_clear_flags(pte, _PAGE_PRESENT);
}



//system call to enable plmt
SYSCALL_DEFINE1(plmt_set_comm, const char __user *, process_name){

    long ret;
    printk("set plmt process name : %s\n", process_name);
    ret = strncpy_from_user(plmt_process_name, process_name, MAX_NAME_LEN-1);

    return ret;
}

// check this is plmt process 
int is_plmt_process(const char * process_name){
    
    if(!strncmp(process_name, plmt_process_name, MAX_NAME_LEN))
        return 1;

    return 0;
    
}
