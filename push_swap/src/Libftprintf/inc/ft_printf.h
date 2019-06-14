/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vice-wra <vice-wra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 13:28:20 by jblue-da          #+#    #+#             */
/*   Updated: 2019/04/30 18:47:18 by vice-wra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdarg.h>

short	g_crutch;

typedef struct		s_node
{
	char			*data;
	struct s_node	*next;
	struct s_node	*prev;
}					t_node;

typedef struct		s_queue
{
	t_node			*head;
	t_node			*tail;
	size_t			size;
}					t_queue;

typedef struct		s_iterator
{
	t_node			*node;
}					t_iterator;

typedef struct		s_string
{
	char			*data;
	int				size;
	int				capacity;
}					t_string;

typedef struct		s_bignum
{
	char			sign;
	t_string		int_part;
	t_string		frac_part;
}					t_bignum;

typedef struct		s_fs {
	char			*flags;
	int				width;
	int				precision;
	char			*size;
	char			type;
}					t_fs;

typedef struct		s_fs_vector {
	t_fs			*data;
	int				size;
	int				capacity;
}					t_fs_vector;

typedef struct		s_char_vec
{
	char			*str;
	int				size;
	int				capacity;
}					t_char_vec;

union
{
	long double		d_num;
	struct			s_double
	{
		__uint128_t mantissa:64;
		__uint128_t exponent:15;
		__uint128_t sign:1;
	}				t_double;
}					t;

/*
**Main function
*/

int					ft_printf(char *format, ...);
void				decide(t_queue *q, t_string *cust_str, va_list *args);
void				get_queue(char *format, t_queue *queue);
void				arr_zero(int *arr, int size);
char				*get_flags(char **str);
void				get_fs(char **str, t_fs *form_string);
int					get_precision(char **str);
char				*get_size(char **str);
char				get_type(char **str);
int					get_width(char **str);
int					overflow_handle(char *str);
void				parse(char *format, t_fs_vector *form_strings);
void				d_handler(t_fs *form_string, long long arg, char **format);
void				i_handler(t_fs *form_string, long long arg, char **format);
void				o_handler(t_fs *form_string,
					unsigned long long arg, char **format);
void				u_handler(t_fs *form_string,
					unsigned long long arg, char **format);
void				x_handler(t_fs *form_string,
					unsigned long long arg, char **format);
void				xx_handler(t_fs *form_string, long long arg, char **format);
void				lf_handler(t_fs *form_string, long double arg,
															char **format);
void				f_handler(t_fs *form_string, double arg, char **format);
void				c_handler(t_fs *form_string, int arg, char **format);
void				s_handler(t_fs *form_string, char *arg, char **format);
void				p_handler(t_fs *form_string, long long arg, char **format);
void				pr_handler(t_fs *form_string, char **format);
void				handler(va_list *args,
					t_fs_vector *form_strings, char **format);
void				s_get_width(t_fs *form_string, char **substr);
void				s_get_precision(t_fs *form_string, char **substr);
void				prepare(t_fs_vector *form_strings);
void				prepare_item(t_fs *form_string);
char				get_sign(t_fs *form_string, long long arg);
void				width_insert(t_fs *form_string, char **substr);
void				ft_replace(char **str, char *substr);
void				precision_insert(t_fs *form_string, char **substr);
void				width_insert_left(char **new_str,
					char *substr, int width, char c);
void				width_insert_right(char **new_str,
					char *substr, int width, char c);
void				add_sign(char **str, char sign);
void				num_insert(char **substr, long long arg);
void				u_cast(t_fs *form_string,
									unsigned long long *arg);
char				*dec_to_octal(unsigned long long n);
void				handler_item(va_list *args, t_fs *form_string,
													char **format);
void				cast(t_fs *form_string, long long *arg);
t_string			cust_strsub(t_string *str, unsigned int start, size_t len);
char				f_get_sign(t_fs *form_string, long double arg);
void				do_bignum_arithm(t_bignum *num, int precision);
t_bignum			*get_the_bits(long double arg);
char				*cust_strdup(t_string *src);
char				*cust_strdup_free(t_string *src);
char				*cust_strjoin_left(t_string *s1, char *s2);
char				*cust_strjoin_right(char *s1, t_string *s2);
char				*put_bignum_strings_into_one(t_bignum *num,
											t_fs *form_string);

/*
**Char_vec function
*/

t_char_vec			ft_cvec_create(int size);
void				ft_cvec_resize(t_char_vec *v);
void				ft_cvec_push_back(t_char_vec *v, char elem);

/*
**fs_vector function
*/

t_fs_vector			fs_vector_create(int size);
void				fs_vector_resize(t_fs_vector *v, int new_size);
void				fs_vector_push_back(t_fs_vector *v, t_fs elem);
void				fs_vector_destroy(t_fs_vector *v);
int					fs_vector_length(t_fs_vector *v);
void				fs_init(t_fs *fs);
void				fs_copy(t_fs *new_form_string, t_fs *form_string);
void				fs_destroy(t_fs *form_string);

/*
**long_arifm function
*/

t_bignum			*big_num_create(void);
t_bignum			*big_num_create_by_str(char sign,
							char *int_part, char *frac_part);
t_bignum			big_num_create_by_size(char sign, int i_part, int f_part);
t_bignum			*bin_sum(t_bignum *l, t_bignum *r);
t_bignum			bin_minus(t_bignum *l, t_bignum *r);
t_bignum			*bin_mult(t_bignum *l);
t_bignum			*bin_div(t_bignum *l);
void				big_num_destroy(t_bignum **num);
t_bignum			*dec_mult(t_bignum *n);
t_bignum			*dec_div(t_bignum *n);
t_bignum			*dec_sum(t_bignum *l, t_bignum *r, int n);
void				swap_comp_str(t_string *s1, t_string *s2);
void				rround(t_bignum **num, int precision);
void				str_push_cs(t_string *l, t_string *r);
void				bin_to_dec(t_bignum *num);
void				do_frac_part(t_bignum *num);
void				do_int_part(t_bignum *num);
void				pos_pow(t_bignum **n, int power, t_bignum *(*f)(t_bignum*));

/*
**t_string function
*/

t_string			str_create_custstr(t_string *cs);
t_string			str_create_str(char *s);
t_string			str_create_size(int size);
void				str_resize(t_string *s, int new_size);
void				str_pushchar(t_string *s, char c);
void				str_pushstr(t_string *s, char *str);
int					str_len(t_string *s);
void				str_destroy(t_string *s);
void				str_print(t_string *s);
void				str_rev(t_string *s);
char				str_at(t_string *s, int idx);
t_string			str_custjoin(t_string *l, t_string *r);
t_string			str_cut(t_string *str, int start, int end);
int					str_len(t_string *s);
void				str_print(t_string *s);
void				str_push_cs(t_string *l, t_string *r);
char				*to_cstr(t_string *str);

/*
**support function
*/

void				ft_strdel(char **as);
char				*ft_strdup(const char *s1);
size_t				ft_strlen(const char *s);
void				ft_strpush(char **str1, char str2);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
char				*ft_strchr(const char *s, int c);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_ltoa(long long n);
char				*ft_strnew(size_t size);
void				ft_bzero(void *s, size_t n);
char				*ft_strcat(char *s1, const char *s2);
void				ft_sym_del(char **str, char c);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
int					ft_max(int x, int y);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_count_digits(int n);
char				*ft_rev_str(char *str);
int					ft_isalnum(int c);
void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				ft_putendl(char const *s);
char				*ft_dec_to_hex(unsigned long long n);
unsigned int		ft_dec_to_octal(unsigned int nb);
void				ft_toupper(char **str);
char				del_minus(char **str);
int					ft_pow(int n, int power);
int					ft_abs(int c);
int					find_exclusion_of_letter(char *str, char letter,
										char letter1, char letter2);
char				*ft_utoa(unsigned long long n);
int					ft_isflag(int c);
char				*ft_strjoin_free(char *s1, char *s2, int n);
void				move_char_pointer(char **s1);
char				*ft_strchr_free(char *str, int c);

/*
**parsing function
*/

void				arr_zero(int *arr, int size);
char				*get_flags(char **str);
void				get_fs(char **str, t_fs *form_string);
int					get_precision(char **str);
char				*get_size(char **str);
char				get_type(char **str);
int					get_width(char **str);
int					overflow_handle(char *str);
void				parse(char *format, t_fs_vector *form_strings);
int					find_the_flags(char **str);
void				process_fs(char **str, t_fs *form_string, va_list *args);

/*
**prepare function
*/

void				prepare(t_fs_vector *form_strings);
void				prepare_item(t_fs *form_string);
void				prepare_item_size(t_fs *form_string);
void				prepare_item_size_f(t_fs *form_string);
void				prepare_item_size_n(t_fs *form_string);
void				prepare_item_precision(t_fs *form_string);
void				prepare_item_flags(t_fs *form_string);

/*
**queue function
*/

t_iterator			first(t_queue *q);
t_iterator			last(t_queue *q);
t_iterator			next(t_iterator *i);
t_iterator			prev(t_iterator *i);
char				*fetch(const t_iterator *i);
void				store(const t_iterator *i, const char *elem);

void				queue_create(t_queue *q);
void				queue_push(t_queue *q, char *value);
char				*queue_pop(t_queue *q);
int					queue_is_empty(t_queue *q);
size_t				queue_len(t_queue *q);
void				queue_destroy(t_queue *q);

void				queue_insert(t_queue *q, t_iterator *i, char *num);
void				queue_push_back(t_queue *q, char *value);
void				queue_del(t_queue *q, t_iterator *i);
void				queue_print(t_queue *q);

#endif
