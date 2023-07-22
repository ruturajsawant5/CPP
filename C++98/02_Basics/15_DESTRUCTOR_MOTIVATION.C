#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <assert.h>

typedef long long ssize_t; 
typedef struct Date Date_t; 
typedef struct String String_t; 
typedef struct DebitCard DebitCard_t; 

struct Date
{
    int day; 
    int month; 
    int year; 
}; 

struct String 
{
    char* p; 
    ssize_t N; 
}; 

struct DebitCard
{
    String_t* holder_name; 
    Date_t* issue_date; 
    Date_t* valid_thru_date; 
    size_t card_number; 
    short cvv;     
}; 

Date_t* make_date(int day, int month, int year)
{
    Date_t* p = NULL; 

    p = (Date_t*)malloc(sizeof(Date_t)); 
    assert(NULL != p);
    
    p->day = day; 
    p->month = month; 
    p->year = year; 

    return (p); 
}

void release_date(Date_t** pp_date)
{
    Date_t* p_date = *pp_date; 

    free(p_date); 
    *pp_date = NULL; 
}

String_t* make_string(char* p)
{
    ssize_t str_len = strlen(p); 
    String_t* p_str = (String_t*)malloc(sizeof(String_t)); 

    assert(p_str != NULL); 

    p_str->p = (char*)calloc(1, str_len + 1); 
    assert(p_str->p != NULL); 
    p_str->N = str_len; 
    strncpy(p_str->p, p, p_str->N); 

    return (p_str); 
}

void release_string(String_t** pp_str)
{
    String_t* p_str = NULL; 

    p_str = *pp_str; 
    free(p_str->p); 
    free(p_str); 

    *pp_str = 0; 
}

DebitCard_t* make_debit_card(char* holder_name, 
                            size_t card_number, 
                            short cvv, 
                            int issue_month, 
                            int issue_year, 
                            int valid_thru_month, 
                            int valid_thru_year)
{
    DebitCard_t* p_card = NULL; 

    p_card = (DebitCard_t*)malloc(sizeof(DebitCard_t)); 
    assert(NULL != p_card); 

    p_card->card_number = card_number; 
    p_card->cvv = cvv; 

    p_card->holder_name = make_string(holder_name); 
    p_card->issue_date = make_date(1, issue_month, issue_year); 
    p_card->issue_date = make_date(28, valid_thru_month, valid_thru_year); 

    return (p_card); 
}

void release_debit_card_manual(DebitCard_t** pp_debit_card)
{
    DebitCard_t* p_card = *pp_debit_card; 

    free(p_card->holder_name->p); 
    free(p_card->holder_name); 
    free(p_card->issue_date); 
    free(p_card->valid_thru_date); 
    free(p_card); 

    *pp_debit_card = NULL; 
}

void release_debit_card(DebitCard_t** pp_debit_card)
{
    DebitCard_t* p_card = *pp_debit_card; 

    release_string(p_card->holder_name); 
    release_date(p_card->issue_date); 
    release_date(p_card->valid_thru_date); 
    free(p_card); 

    *pp_debit_card = NULL; 
}

struct T 
{
    T1* p1; 
    T2* p2; 


    Tn* pn; 

    // other non-pointer member
}; 

void test(void)
{
    struct T* pT = (struct T*)malloc(sizeof(struct T)); 

    pT->p1 = (T1*)make_T1(/*data*/); 

    pT->pn = (Tn*)make_Tn(/*data*/); 

    free(pT); 
}