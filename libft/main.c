#include <stdio.h>
#include <string.h>
/*
void	*ft_memset(void *destination, int c, size_t n);
int		main(void)
{
	unsigned char src[15]="1234567890";
	ft_memset(src, '1',10);
	printf("src: %s\n", src);

	return (0);
}
void	ft_bzero(void *s, size_t n);
int		main(void)
{
	unsigned char src[18]="1234567890";
	ft_bzero(src, 10);
	printf("src: %s\n", src);

	return (0);
}
void	*ft_memcpy(void *dest, const void *src, size_t n);
int		main(void)
{
	unsigned char src[18]="239687451234";
	unsigned char dest[11]="abcdefghigk";
	ft_memcpy(dest, src, 8);
	printf("dest: %s\n", dest);
}
void	*ft_memccpy(void *destination, const void *source, int c, size_t n);
int		main(void)
{
	
	unsigned char src[18]="2539687451234";
	unsigned char dest[11]="abcdefghigk";
	ft_memccpy(dest, src, '5', 3);
	printf("dest: %s\n", dest);
}
void	*ft_memmove(void *destination, const void *source, size_t n);
int		main(void)
{
	unsigned char src[18]="2539687451234";
	unsigned char dest[11]="abcdefghigk";
	ft_memmove(&src[1], &src[6], 4);
	printf("src new: %s\n", src);

	return (0);
}
void	*ft_memchr(const void *arr, int c, size_t n);
int		main(void)
{
	unsigned char src[15] = "1235678909875";
	char *sym;

	printf("src old: %s\n", src);
	sym = ft_memchr (src, '4', 10);
	if (sym != NULL)
		sym[0] = '!';
	printf("src new: %s\n", src);

	return (0);

}
int		ft_memcmp(const void *arr1, const void *arr2, size_t n);
int		main(void)
{
	unsigned char src[18]="254";
	unsigned char dest[11]="255";
	if (ft_memcmp(src, dest, 3) == -1)
		printf("string 2 is cooler");
	else if (ft_memcmp(src, dest, 3) == 1)
		printf("string 1 is cooler");
	else
		printf("equal!");

	return (0);
}
size_t		ft_strlen(const char *str);
int		main()
{
	char str [9] = "012012012";
	printf("Lenght of %s = %zu of sings\n", str, ft_strlen(str));

	return (0);
}*/
/*size_t		ft_strlcpy(char *destination, const char *source, size_t n);

char buf[2];

int		main()
{
	char str[8] = "12345678";
	size_t sz;

	buf[0] = '\0';

	printf("the string: \"%s\" \n\n", str);
	printf("the buf before copying: \"%s\"\n", buf);

	sz = ft_strlcpy(buf, str, sizeof(buf));
	if (sz >= sizeof(buf))
		printf("the cut of the string detected from %zu to %lu sings!\n", sz, sizeof(buf) - 1);

	printf("the buf after copying: \"%s\"\n", buf);

	return (0);
}/*
size_t		ft_strlcat(char *destination, const char *source, size_t n);
int		main()
{
	char str[7] = "abcdefg";
	size_t sz;
	char str2[5] = "12345";

	printf("the string: \"%s\" \n\n", str);
	printf("the str2 before copying: \"%s\"\n", str2);

	sz = ft_strlcat(str2, str, 11);
	printf("the str2 after copying: \"%s\"\n", str2);
	printf("this is the result: %zu ", sz);

	return (0);
}
/*char	*ft_strrchr(const char *str, int ch);
int		main()
{
	char *str;
	str = "";
	int ch = 3;
	char *ach;

	ach = ft_strrchr(str, ch);

	if (ach == NULL)
		printf("Symbol not found.\n");
	else
		printf("Symbol is on the %ld\n position",ach-str+1);
	return (0);
}*/