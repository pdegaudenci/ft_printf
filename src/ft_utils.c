
#include "../include/ft_printf.h"

static char	*ft_strcpy(char *cadena1, const char *cadena2)
{
	int	cont;

	cont = 0;
	while (cadena2[cont] != 0)
	{
		cadena1[cont] = cadena2[cont];
		cont++;
	}
	cadena1[cont] = '\0' ;
	return (cadena1);
}

char	*ft_strdup(const char *src)
{
	char	*dst;

	dst = malloc(ft_strlen (src) + 1);
	if (dst == NULL)
		return (NULL);
	ft_strcpy(dst, src);
	return (dst);
}

size_t	ft_strlen(const char *s)
{
	size_t	cont;

	cont = 0;
	while (s[cont] != 0)
		cont++;
	return (cont);
}

int	ft_isformat(char c)
{
	if (c == 'c' || c == 's')
		return(0);
	if (c == 'p')
		return(0);
	if (c == 'd' || c == 'i' || c == 'u')
		return(0);
	if (c == 'x' || c == 'X')
		return(0);
	if (c == '%')
		return(0);
	return (1);
}
