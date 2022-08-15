/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prueba.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdegaude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 03:43:20 by pdegaude          #+#    #+#             */
/*   Updated: 2022/08/15 03:43:28 by pdegaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/ft_printf.h"

int main(void)
{
	// mix de nulos

	printf("NULOS CON PRINTF:     \n");
	printf("Cadena null :%s, null con precision y ancho: %10.2s , y null con precision y ancho: %12.4s,	nulo con PRECISION:%.3s, NULO CON ALINEACION:%-10.2s FIN\n", NULL,NULL,	NULL,NULL,NULL);
	
	printf("NULOS CON FT_PRINTF  :\n");
	ft_printf("Cadena null :%s, null con precision y ancho: %10.2s , y null con precision y ancho: %12.4s, 	nulo con PRECISION:%.3s, NULO CON ALINEACION:%-10.2s FIN\n", NULL,NULL,	NULL,NULL,NULL);
	
	//DECIMALES
	printf("decimales d con printf:     \n");
	printf("%d,%12.3d,%d,%10.2d,%-4.20d,%-26.15d,%14.2d,%10.0d,%.0d,%d,%10.2dFIN\n",664912823,	NULL, NULL,(int) -232322,82423, -1,-4321,0,0,0,0);
	printf("decimales d con FT_PRINTF  :\n");
	ft_printf("%d,%12.3d,%d,%10.2d,%-4.20d,%-26.15d,%14.2d,%10.0d,%.0d,%d,%10.2dFIN\n",664912823,	NULL, NULL,(int) -232322,82423, -1,-4321,0,0,0,0);
	
	
	printf("\n-----------------------------\n\n");
	printf("decimales i con printf:     \n");
	printf("%12.3i,%i,%+10.2i,%-4.20i,%-26.15i,%14.2i,%10.0i,%.0i,%i,%10.2i,% .2dFIN\n",	NULL, NULL,(int) -1256912,398143, -1,-43216,0,0,0,0,17);
	printf("decimales i con FT_PRINTF  :\n");
	ft_printf("%12.3i,%i,%+10.2i,%-4.20i,%-26.15i,%14.2i,%10.0i,%.0i,%i,%10.2i,% .2dFIN\n",	NULL, NULL,(int) -1256912,398143, -1,-43216,0,0,0,0,17);
	
	// CADENA
	printf("\n-----------------------------\n\n");
	printf("Cadenas printf:     \n");
	printf("%s,%10.2s,%12.4s,%-1s,%30s,%.16s,%.sFIN\n", "ESTA ES UNA CADENA COMmpleta",	"Cadena con precision y ancho",	"Cadena con precision y ancho","holaaaa","cadena con ancho","cadena con precision", "esta cadena no se muestra");
	printf("cadena ft_printf   :\n");
	ft_printf("%s,%10.2s,%12.4s,%-01s,%30s,%.16s,%.sFIN\n", "ESTA ES UNA CADENA COMmpleta",	"Cadena con precision y ancho",	"Cadena con precision y ancho","holaaaa","cadena con ancho","cadena con precision", "esta cadena no se muestra");

	printf("\n-----------------------------\n\n");
	printf("Cracteres printf:     \n");
	printf("%c,%10.2c,%12.4c,%-1c,%30c,%.16c,%.cFIN\n", 'E','h',	's','u','t','h','x');
	printf("Cracteres ft_printf   :\n");
	ft_printf("%c,%10.2c,%12.4c,%-1c,%30c,%.16c,%.cFIN\n", 'E','h',	's','u','t','h','x');


	// HEXADECIMAL
	printf("\n-----------------------------\n\n");
	printf("hexadecimales x  con printf:     \n");
	printf("%x,%12.3x,%x,%10.2x,%-4.20x,%-26.15x,%14.2x,%10.0x,%.0x,%x,%10.2x,%102.2xFIN\n",	5456616,NULL, NULL, -1256912,398143, -1,-43216,0,0,0,0,-110);
	printf("hexadecimales x con FT_PRINTF  :\n");
	ft_printf("%x,%12.3x,%x,%10.2x,%-4.20x,%-26.15x,%14.2x,%10.0x,%.0x,%x,%10.2x,%102.2xFIN\n",	5456616,NULL, NULL, -1256912,398143, -1,-43216,0,0,0,0,-110);
	printf("\n-----------------------------\n\n");

	printf("\n-----------------------------\n\n");
	printf("hexadecimales X con printf:     \n");
	printf("%X,%12.3X,%x,%10.2X,%-4.20X,%-26.15X,%14.2X,%10.0X,%.0X,%X,%10.2X,%111.2XFIN\n",	545999,NULL, NULL, -1256912,398143, -1,-43216,0,0,0,0,-110);
	printf("hexadecimales X con FT_PRINTF  :\n");
	ft_printf("%X,%12.3X,%x,%10.2X,%-4.20X,%-26.15X,%14.2X,%10.0X,%.0X,%X,%10.2X,%111.2XFIN\n",	545999,NULL, NULL, -1256912,398143, -1,-43216,0,0,0,0,-110);
	printf("\n-----------------------------\n\n");

    // PUNTERO

	char *a,*b,*c,*d;
	printf("\n-----------------------------\n\n");
	printf("punteros con printf:     \n");
	printf("%p,%p,%20p,%-50pFIN\n",NULL,a,b,c );
	printf("punteros  con FT_PRINTF  :\n");
	ft_printf("%p,%p,%20p,%-50pFIN\n",NULL,a, b,c);
	printf("\n-----------------------------\n\n");

	// UNSIGNED
	printf("\n-----------------------------\n\n");
	printf("Unsigned con printf:       \n");
	printf("%u,%12.3u,%u,%10.2u,%-4.20u,%-26.15u,%14.2u,%10.0u,%.0u,%u,%10.2u,%111.2uFIN\n",545999,NULL, NULL, 	-1256912,398143, -1,-43216,0,0,0,0,-110);
	printf("Unsigned con ft_printf:     \n");
	ft_printf("%u,%12.3u,%u,%10.2u,%-4.20u,%-26.15u,%14.2u,%10.0u,%.0u,%u,%10.2u,%111.2uFIN\n",545999,NULL, NULL,	 -1256912,398143, -1,-43216,0,0,0,0,-110);
	printf("\n-----------------------------\n\n");
	
	// BONUS
	printf("\n-----------------------------\n\n");
	printf("SHARP con printf:       \n");
	printf("%#x,%#12.3x,%#x,%#10.2x,%#-4.20x,%#-26.15x,%#14.2x,%#10.0x,%#.0x,%#x,%#10.2x,%#80.2x,%#x,%#5.15xFIN\n",5456616,NULL, NULL,	 -1256912,398143, -1,-43216,0,0,0,0,-110,0,202);
	printf("SHARP x con FT_PRINTF  :\n");
	ft_printf("%#x,%#12.3x,%#x,%#10.2x,%#-4.20x,%#-26.15x,%#14.2x,%#10.0x,%#.0x,%#x,%#10.2x,%#80.2x,%#x,%#5.15xFIN\n",5456616,NULL, NULL, 	-1256912,398143, -1,-43216,0,0,0,0,-110,0,202);
	printf("\n-----------------------------\n\n");

	printf("\n-----------------------------\n\n");
	printf("decimales con printf BONUS(+):     \n");
	printf("%+12.3i,%+i,%+10.2i,%+-4.20i,%+-26.15i,%+14.2i,%+i,%+10.2i,%+2.2dFIN\n",NULL, NULL,(int) 	-1256912,398143, -1,-43216,0,0,17);
	printf("decimales con ft_printf BONUS(+):  \n");
	ft_printf("%+12.3i,%+i,%+10.2i,%+-4.20i,%+-26.15i,%+14.2i,%+i,%+10.2i,%+2.2dFIN\n",NULL, NULL,(int) 	-1256912,398143, -1,-43216,0,0,17);

	printf("\n-----------------------------\n\n");
	printf("decimales con printf BONUS(space):       \n");
	printf(",% 10.2i,% -4.20i,% -26.15i,% 14.2i,% 10.0i,% i,% .2dFIN\n",(int) -1256912,398143, -1,	-43216,0,0,17);
	printf("decimales con ft_printf BONUS(space):     \n");
	ft_printf(",% 10.2i,% -4.20i,% -26.15i,% 14.2i,% 10.0i,% i,% .2dFIN\n",(int) -1256912,398143,	 -1,-43216,0,0,17);

}
