#ifndef _LINUX_PLMT_H
#define _LINUX_PLMT_H

#define MAX_NAME_LEN 32

char plmt_process_name[MAX_NAME_LEN];

void kwrite_file(char *data);

long plmt_set_comm(const char __user *process_name);
int is_plmt_process(const char * process_name);

#endif
