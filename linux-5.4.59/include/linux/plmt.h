#ifndef _LINUX_PLMT_H
#define _LINUX_PLMT_H

#define MAX_NAME_LEN 32
//#define PTE_FAKE_BIT 51

/// 9th bit  _PAGE_BIT_SOFTW1
#define PTE_FAKE_MASK _PAGE_SOFTW1
//#define PTE_FAKE_MASK (_AT(pteval_t, 1) << PTE_FAKE_BIT)

char plmt_process_name[MAX_NAME_LEN];

inline pte_t pte_mkfake(pte_t pte);
inline pte_t pte_clrfake(pte_t pte);
inline int is_pte_fake(pte_t pte);

inline pte_t pte_clrpresent(pte_t pte);

long plmt_set_comm(const char __user *process_name);
int is_plmt_process(const char * process_name);

void kwrite_file(char *data);
#endif
