/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcereced <vcereced@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 14:43:41 by vcereced          #+#    #+#             */
/*   Updated: 2023/03/27 22:06:38 by vcereced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include	<fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}		t_list;
t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void*));
void	ft_lstclear(t_list **lst, void (*del)(void*));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

/**************PRINTF***************/
int		ft_printf(char const *fmt, ...);
void	ft_putstr_printf(char *s, int *length);
void	ft_putnbr_printf(long nbrl, char *base, int *len, char ptr);

/*************GET_NEXT_LINE********/
char	*get_next_line(int fd);
char	*get_joint(const char *buffer, char *bufferstatic, char *str_jointed);
size_t	get_strlen(const char *s);
char	*get_strrchr(char *s, int c);
char	*get_clean(char *bufferstatic, char *bufferstatic_cleaned, int i);
/*************EXTRA FUNCTION********/
int		ft_matrizlen(char **matriz);
char	**ft_matrizcharfree(char **array, unsigned int i);
char	**ft_matrizintfree(int **array, unsigned int i);
int		ft_atoi_base(const char *str, int str_base);

int		ft_lstsize(t_list *lst);
/**
 * @brief tests for any character for which isupper(3) or
     islower(3) is true.
 * @param c  must be representable as
     an unsigned char or the value of EOF.
 * @return int zero if the character tests false and
     returns non-zero if the character tests true.
 */
int		ft_isalpha(int c);
/**
 * @brief tests for a decimal digit character. Similar to isnumber().
 * @param c  must be representable as an unsigned char or
     the value of EOF.
 * @return int zero if the character tests
     false and return non-zero if the character tests true.
 */
int		ft_isdigit(int c);
/**
 * @brief tests for any character for which isalpha(3) or
     isdigit(3) is true.
 * @param c must be representable as
     an unsigned char or the value of EOF.
 * @return int zero if the character tests false and
     returns non-zero if the character tests true.
 */
int		ft_isalnum(int c);
/**
 * @brief tests for an ASCII character, which is any charac-
     ter between 0 and octal 0177 inclusive.
 * @param c int of ascii table character 
 * @return int zero if the character tests false and
     returns non-zero if the character tests true.
 */
int		ft_isascii(int c);
/**
 * @brief tests for any printing character, including space
     (` ').
 * @param c must be representable as an unsigned
     char or the value of EOF.
 * @return int zero if the character tests false and
     returns non-zero if the character tests true.
 */
int		ft_isprint(int c);
/**
 * @brief converts a lower-case letter to the corresponding
     upper-case letter.
 * @param c must be representable as an unsigned
     char or the value of EOF.
 * @return int If the argument is a lower-case letter, returns
     the corresponding upper-case letter, otherwise, the argu-
     ment is returned unchanged.
 */
int		ft_toupper(int c);
/**
 * @brief converts an upper-case letter to the corresponding
     lower-case letter.
 * @param c must be representable as an unsigned
     char or the value of EOF.
 * @return int If the argument is an upper-case letter returns
     the corresponding lower-case letter, otherwise, the argu-
     ment is returned unchanged.
 */
int		ft_tolower(int c);
/**
 * @brief converts the initial portion of the string pointed to
     by str to int representation.
 * @param str string pointed.
 * @return int representation of the str pointed.
 */
int		ft_atoi(const char *str);
/**
 * @brief Coverts the integer n into a character string.
 * @param n int to take the value for convert in string.
 * @return char* String pointer will be returned. When passed a 
 * non-valid argument, function will return NULL
 */
char	*ft_itoa(int n);
/**
 * @brief Locates the first occurrence of c (converted to a
     char) in the string pointed to by s. The terminating null character is
     considered to be part of the string, so the func-
     tions locate the terminating `\0'.
 * 
 * @param s pointer to be locate the character
 * @param c character to be searched
 * @return char* a pointer to the located
     character, or NULL if the character does not appear in the string.
 */
char	*ft_strchr(const char *s, int c);
/**
 * @brief identical to strchr(), except it locates
     the last occurrence of c.
 * 
 * @param s pointer to be locate the character
 * @param c character to be searched
 * @return char* char* a pointer to the located
     character, or NULL if the character does not appear in the string.
 */
char	*ft_strrchr(const char *s, int c);
/**
 * @brief locates the first occurrence of the null-terminated string 
 *  needle in the string haystack. Characters that appear 
     after a `\0' character are not searched.  
 * 
 * @param haystack string to be iterated for search needle 
 * @param needle string to be searched in haystack
 * @param len  not more than len characters will search.
 * @return char* If needle is an empty string, haystack is returned; 
 *  if needle occurs nowhere in haystack, NULL is returned; otherwise a
    pointer to the first character of the first occurrence of needle is 
	returned.
 */
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
/**
 * @brief allocates sufficient memory for a copy of the string s1, does the
 * copy
 * 
 * @param s1 string to be copied.
 * @return char* a pointer to it. If insufficient memory is available, NULL 
 * is returned
 */
char	*ft_strdup(const char *s1);
/**
 * @brief allocates sufficient memory for a copy of a part of the string s 
 * and does the copy .
 * 
 * @param s string to extract the part to be allocate an copied.
 * @param start index of the string to start to copy
 * @param len length to be copied from start
 * @return char* a pointer to allocated memory. if error NULL is returned.
 */
char	*ft_substr(char const *s, unsigned int start, size_t len);
/**
 * @brief allocates sufficient memory for copy s1 and s2, does the copy. 
 * 
 * @param s1 first string to be copied.
 * @param s2 second string to be copied at the end of s1.
 * @return char* a pointer to allocated memory. If error NULL is returned.
 */
char	*ft_strjoin(char const *s1, char const *s2);
/**
 * @brief allocates memory of string without the character of set at the 
 * begining and the end.
 * 
 * @param s1 the string on wich to iterate.
 * @param set the string with character to be trimed on s1.
 * @return char* a pointer of allocated memory. If error NULL is returned.
 */
char	*ft_strtrim(char const *s1, char const *set);
/**
 * @brief Applies the function f to each character of the
string s to create a new string, with malloc()
resulting from successive applications of f.
 * 
 * @param s The string on which to iterate.
 * @param f The function to apply to each character.
 * @return char* string created from the successive applications
of f. Returns NULL if the allocation fails.
 */
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
/**
 * @brief split the string on c character, allocating every divion on a 
 * row of matriz with last row with NULL;
 * 
 * @param s the string to be splited.
 * @param c the character on the string will be splited.
 * @return char** a matriz with the divion of the string. If error NULL 
 * is returned.
 */
char	**ft_split(char const *s, char c);
/**
 * @brief compare strings null-terminated strings s1 and s2. characters 
 * that appear after a `\0' character are not compared.
 * 
 * @param s1 string be compare to.
 * @param s2 string be compare to.
 * @param n number of characters to be compare.
 * @return int integer greater than, equal to, or less than 0, according 
 * as the string s1
     is greater than, equal to, or less than the string s2. The comparison 
	 is done using unsigned characters, so that `\200'
     is greater than `\0'.
 */
int		ft_strncmp(const char *s1, const char *s2, size_t n);
/**
 * @brief writes len bytes of value c (converted to an unsigned char) to 
 * the string b.
 * 
 * @param b string to be copied the value of c.
 * @param c value of unsigned char of c.
 * @param len length of bytes.
 * @return void* 
 */
void	*ft_memset(void *b, int c, size_t len);
/**
 * @brief writes n zeroed bytes to the string s.
 * 
 * @param s string pointed
 * @param n number of bytes
 */
void	ft_bzero(void *s, size_t n);
/**
 * @brief aply the function to every element of the string.
 * 
 * @param s string to be iterating.
 * @param f function to apply.
 */
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
/**
 * @brief output stream of stdout.
 * 
 * @param c chararcter to output.
 * @param fd file descriptor on wich to write.
 */
void	ft_putchar_fd(char c, int fd);
/**
 * @brief write the string on the file descriptor given, followed by 
 * a newline.
 * 
 * @param s The string to output.
 * @param fd File descriptor on wich to write.
 */
void	ft_putstr_fd(char *s, int fd);
/**
 * @brief Outputs the string s to the given file.
 * 
 * @param s string to be streamed
 * @param fd file descriptor to be writen.
 */
void	ft_putendl_fd(char *s, int fd);
/**
 * @brief Outputs the integer n to the given file descriptor
 * 
 * @param n The integer to output.fd
 * @param fd file descriptor to be writen.
 */
void	ft_putnbr_fd(int n, int fd);
/**
 * @brief cThe memcpy() function copies n bytes from memory area s2 to 
 * memory area s1.  If s1 and s2 overlap, behavior is undefined.
 * Applications in which s1 and s2 might overlap should use memmove(3) 
 * instead.
 * 
 * @param dst pointer of destination (converted void*).
 * @param src pointed of source (converted void*).
 * @param n number of bytes to copy.
 * @return void* a pointer to dst (converted void)
 */
void	*ft_memcpy(void *dst, const void *src, size_t n);
/**
 * @brief copies n bytes from string src to string dst.  The
**	two strings may overlap; the copy is always done in a non-destructive
**	manner.
 * @return void*  pointer to dst
 */
void	*ft_memmove(void *dst, const void *src, size_t len);
/**
 * @brief iterate the string till find a character over n bytes.
 * 
 * @param s of string
 * @param c character to find
 * @param n number of bytes to iterate 
 * @return void* if it find the character, return a pointer to the character, 
 * otherwise return NULL;
 */
void	*ft_memchr(const void *s, int c, size_t n);
/**
 * @brief allocates memory and fill it up with zeroes.
 * 
 * @param count number values to store.
 * @param size size of the type of value.
 * @return void* pointer to memory allocated.
 */
void	*ft_calloc(size_t count, size_t size);
/*
 * @brief compare 2 pointer till n bytes.
 * 
 * @param s1 pointer to compare
 * @param s2 pointer to compare
 * @param n bytes to compare
 * @return int if s1 is greater return >1, if s2 is greater return 0 or 
 * are equal 
 * return <0. 
 */
int		ft_memcmp(const void *s1, const void *s2, size_t n);
/**
 * @brief calculate the length of a string
 * 
 * @param s  string pointed by s
 * @return size_t a number of size of the string
 */
size_t	ft_strlen(const char *s);
/*
 * @brief copy a NULL terminated string into a sized buffer
 * 
 * @param dst where to copy the string to
 * @param src where to copy the string from
 * @param dstsize size of destination buffer
 * @return size_t length of src
 */
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
/*
 * @brief concatenate src then dst, but the length of the string concatenated
 * must be smaller than the size
 * 
 * @param dst the string to concatenate with src
 * @param src  string to concatenate 
 * @param dstsize the length of the string concatenated + '\0' must be 
 * smaller than 
 * dstsize
 * @return size_t length of the dstsize + src. if length of dst is greater 
 * than size return the length of dst + size if the concatenation is full 
 * complete.
 */
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);

#endif
