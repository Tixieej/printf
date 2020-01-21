/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: rde-vrie <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/24 09:52:14 by rde-vrie      #+#    #+#                 */
/*   Updated: 2020/01/21 11:27:32 by rde-vrie      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <limits.h>
#include <stdio.h>
#include <unistd.h>

int	main()
{
	char	c = 'g';
	int		i = 5;
	int		groot = 2147483647;
	char	*s = "Rixt";
/*	printf("\t#########################################\n");
	printf("\t_.-._.-._.=.= Test Integers =.=._.-._.-._ \n");
	printf("\t#########################################\n");

	printf("\n EERST GEEN FLAG wel width en prcsn\n");

	printf("\n width>prcsn>len %%10.6i \n");
	printf("[%i]\n", ft_printf("mijn: [%10.6i]", 45));
	printf("[%i]\n", printf("echt: [%10.6i]", 45));

	printf("\n width>len>prcsn %%6.3i \n");
	printf("[%i]\n", ft_printf("mijn: [%6.3i]", 1245));
	printf("[%i]\n", printf("echt: [%6.3i]", 1245));

	printf("\n prcsn>width>len %%4.6i \n");
	printf("[%i]\n", ft_printf("mijn: [%4.6i]", 45));
	printf("[%i]\n", printf("echt: [%4.6i]", 45));

	printf("\n prcsn>len>width %%2.6i \n");
	printf("[%i]\n", ft_printf("mijn: [%2.6i]", 1245));
	printf("[%i]\n", printf("echt: [%2.6i]", 1245));

	printf("\n len>width>prcsn> %%4.3i \n");
	printf("[%i]\n", ft_printf("mijn: [%4.3i]", 123456));
	printf("[%i]\n", printf("echt: [%4.3i]", 123456));

	printf("\n len>prcsn>width %%3.4i \n");
	printf("[%i]\n", ft_printf("mijn: [%3.4i]", 123456));
	printf("[%i]\n", printf("echt: [%3.4i]", 123456));

	printf("\n=== 0 en 0 precision ===\n");

	printf("\n len>prcsn>width %%.0i \n");
	printf("[%i]\n", ft_printf("mijn: [%.0i]", 0));
	printf("[%i]\n", printf("echt: [%.0i]", 0));

	printf("\n len>prcsn>width %%.0i \n");
	printf("[%i]\n", ft_printf("mijn: [%.0i]", 000));
	printf("[%i]\n", printf("echt: [%.0i]", 000));
	
	printf("\n len>prcsn=width %%.0i \n");
	printf("[%i]\n", ft_printf("mijn: [%.0i]", 0));
	printf("[%i]\n", printf("echt: [%.0i]", 0));

	printf("\n len>prcsn=width %%0.0i \n");
	printf("[%i]\n", ft_printf("mijn: [%0.0i]", 0));
	printf("[%i]\n", printf("echt: [%0.0i]", 0));

	printf("\n len>prcsn=width %%-.0i \n");
	printf("[%i]\n", ft_printf("mijn: [%-.0i]", 0));
	printf("[%i]\n", printf("echt: [%-.0i]", 0));

	printf("\n width>len>prcsn %%5.0i \n");
	printf("[%i]\n", ft_printf("mijn: [%5.0i]", 0));
	printf("[%i]\n", printf("echt: [%5.0i]", 0));

	printf("\n len>prcsn=width %%.0i \n");
	printf("[%i]\n", ft_printf("mijn: [%.0i]", 5));
	printf("[%i]\n", printf("echt: [%.0i]", 5));

	printf("\n=== 0 FLAG  ===\n");

	printf("\n alleen 0 flag  %%0i \n");
	printf("[%i]\n", ft_printf("mijn: [%0i]", 45));
	printf("[%i]\n", printf("echt: [%0i]", 45));

	printf("\n 0 flag en width 5 %%05i \n");
	printf("[%i]\n", ft_printf("mijn: [%05i]", 45));
	printf("[%i]\n", printf("echt: [%05i]", 45));

	printf("\n 0 flag en width 4 %%04i \n");
	printf("[%i]\n", ft_printf("mijn: [%04i]", -4825));
	printf("[%i]\n", printf("echt: [%04i]", -4825));

	printf("\n 0 flag, width 5, neg int %%05i \n");
	printf("[%i]\n", ft_printf("mijn: [%05i]", -45));
	printf("[%i]\n", printf("echt: [%05i]", -45));

	printf("\n 0 flag, width 5, prcsn 6 %%05.6i \n");
	printf("[%i]\n", ft_printf("mijn: [%05.6i]", 45));
	printf("[%i]\n", printf("echt: [%05.6i]", 45));

	printf("\n 0 flag, width 10, prcsn 6, lang getal %%010.6i \n");
	printf("[%i]\n", ft_printf("mijn: [%010.6i]", 4512369));
	printf("[%i]\n", printf("echt: [%010.6i]", 4512369));

	printf("\n 0 flag, width>prcsn>len %%010.6i \n");
	printf("[%i]\n", ft_printf("mijn: [%010.6i]", 45));
	printf("[%i]\n", printf("echt: [%010.6i]", 45));

	printf("\n GEEN flag, width>prcsn>len %%10.6i \n");
	printf("[%i]\n", ft_printf("mijn: [%10.6i]", 45));
	printf("[%i]\n", printf("echt: [%10.6i]", 45));

	printf("\n 0 flag, prcsn 6  %%0.6i \n");
	printf("[%i]\n", ft_printf("mijn: [%0.6i]", 45));
	printf("[%i]\n", printf("echt: [%0.6i]", 45));

	printf("\n alleen width  %%5i \n");
	printf("[%i]\n", ft_printf("mijn: [%5i]", 45));
	printf("[%i]\n", printf("echt: [%5i]", 45));

	printf("\n alleen width, neg int  %%5i \n");
	printf("[%i]\n", ft_printf("mijn: [%5i]", -45));
	printf("[%i]\n", printf("echt: [%5i]", -45));

	printf("\n width, prcsn  %%5.6i \n");
	printf("[%i]\n", ft_printf("mijn: [%5.6i]", 45));
	printf("[%i]\n", printf("echt: [%5.6i]", 45));

	printf("\n width, prcsn, neg int  %%10.6i \n");
	printf("[%i]\n", ft_printf("mijn: [%10.6i]", -45));
	printf("[%i]\n", printf("echt: [%10.6i]", -45));

	printf("\n alleen prcsn  %%.6i \n");
	printf("[%i]\n", ft_printf("mijn: [%.6i]", 45));
	printf("[%i]\n", printf("echt: [%.6i]", 45));

	printf("\n<>-<>-<>-<> %%024.6i <>-<>-<>-<>\n");
	//vul aan met 0 tot 24 width. prec overwrite 0padding
	printf("[%i]\n", ft_printf("mijn: [%024.6i]", 123456789));	
	printf("[%i]\n", printf("echt: [%024.6i]", 123456789));

	printf("\n<>-<>-<>-<> %%026i <>-<>-<>-<>\n");
	printf("[%i]\n", ft_printf("mijn: [%026i]", 123456789));	
	printf("[%i]\n", printf("echt: [%026i]", 123456789));

	printf("\n<>-<>-<> %%000000-000006i <>-<>-<>\n");
	printf("[%i]\n", ft_printf("mijn: [%000000-000006i]", 25));
	printf("[%i]\n", printf("echt: [%000000-000006i]", 25));

	printf("\n<>-<>-<>-<> %%0*i, 8 <>-<>-<>-<>\n");
	printf("[%i]\n", ft_printf("mijn: [%0*i]", 8, 125));
	printf("[%i]\n", printf("echt: [%0*i]", 8, 125));

	printf("\n<>-<>-<>-<> %%i <>-<>-<>-<>\n");
	printf("[%i]\n", ft_printf("mijn: [%i]", INT_MIN));
	printf("[%i]\n", printf("echt: [%i]", INT_MIN));

	printf("\n<>-<>-<>-<> %%20.7i <>-<>-<>-<>\n");
	//7 is minimale width? vul op met 0
	printf("[%i]\n", ft_printf("mijn: [%20.7i]", 12345));
	printf("[%i]\n", printf("echt: [%20.7i]", 12345));

	printf("\n NU DE - FLAG \n");

	printf("\n alleen - flag  %%-i \n");
	printf("[%i]\n", ft_printf("mijn: [%-i]", 45));
	printf("[%i]\n", printf("echt: [%-i]", 45));

	printf("\n - flag en width 5 %%-5i \n");
	printf("[%i]\n", ft_printf("mijn: [%-5i]", 45));
	printf("[%i]\n", printf("echt: [%-5i]", 45));

	printf("\n - flag, width 5, neg int %%-5i \n");
	printf("[%i]\n", ft_printf("mijn: [%-5i]", -45));
	printf("[%i]\n", printf("echt: [%-5i]", -45));

	printf("\n - flag, width 5, prcsn 6 %%-5.6i \n");
	printf("[%i]\n", ft_printf("mijn: [%-5.6i]", 45));
	printf("[%i]\n", printf("echt: [%-5.6i]", 45));

	printf("\n - flag, width 5, prcsn 6, neg int %%-5.6i \n");
	printf("[%i]\n", ft_printf("mijn: [%-5.6i]", -45));
	printf("[%i]\n", printf("echt: [%-5.6i]", -45));

	printf("\n - flag, prcsn 6 %%-.6i <>-<>-<>-<>\n");
	printf("[%i]\n", ft_printf("mijn: [%-.6i]", 45));
	printf("[%i]\n", printf("echt: [%-.6i]", 45));

	printf("\n - flag, width 10, prcsn 6 %%-10.6i <>-<>-<>-<>\n");
	printf("[%i]\n", ft_printf("mijn: [%-10.6i]", 45));
	printf("[%i]\n", printf("echt: [%-10.6i]", 45));

	printf("\t=== INT MIN ===");

	printf("\n alleen int min %%i\n");
	printf("[%i]\n", ft_printf("mijn: [%i]", INT_MIN));
	printf("[%i]\n", printf("echt: [%i]", INT_MIN));

	printf("\n 0 flag en width %%015i\n");
	printf("[%i]\n", ft_printf("mijn: [%015i]", INT_MIN));
	printf("[%i]\n", printf("echt: [%015i]", INT_MIN));

	printf("\n width en prcsn  %%15.13i\n");
	printf("[%i]\n", ft_printf("mijn: [%15.13i]", INT_MIN));
	printf("[%i]\n", printf("echt: [%15.13i]", INT_MIN));

	printf("\n - flag %%-i\n");
	printf("[%i]\n", ft_printf("mijn: [%-i]", INT_MIN));
	printf("[%i]\n", printf("echt: [%-i]", INT_MIN));*/



/*	printf("\n\t#########################################\n");
	printf("\t_.-._.-._.=.= Test Strings =.=._.-._.-._\n");
	printf("\t#########################################\n");

	printf("\n GEEN FLAG \n");

	// NIET SCCHRIKKEN, DEZE SEGFAULT
	printf("\n NULL string: %%s \n");
	printf("[%i]\n", ft_printf("mijn: [%s]\n", NULL));
	printf("[%i]\n", printf("echt: [%s]\n", NULL));

	printf("\n width, short string: %%6s \n");
	printf("[%i]\n", ft_printf("mijn: [%6s]\n", "la"));
	printf("[%i]\n", printf("echt: [%6s]\n", "la"));

	printf("\n width, long string: %%6s \n");
	printf("[%i]\n", ft_printf("mijn: [%6s]\n", "dit is een heel verhaal"));
	printf("[%i]\n", printf("echt: [%6s]\n", "dit is een heel verhaal"));

	printf("\n precision, short string: %%.6s \n");
	printf("[%i]\n", ft_printf("mijn: [%.6s]\n", "la"));
	printf("[%i]\n", printf("echt: [%.6s]\n", "la"));

	printf("\n precision, long string: %%.6s \n");
	printf("[%i]\n", ft_printf("mijn: [%.6s]\n", "dit is een heel verhaal"));
	printf("[%i]\n", printf("echt: [%.6s]\n", "dit is een heel verhaal"));

	printf("\n long width, precision, short string: %%10.6s \n");
	printf("[%i]\n", ft_printf("mijn: [%10.6s]\n", "la"));
	printf("[%i]\n", printf("echt: [%10.6s]\n", "la"));

	printf("\n long width, precision, long string: %%10.6s \n");
	printf("[%i]\n", ft_printf("mijn: [%10.6s]\n", "dit is een heel verhaal");
	printf("[%i]\n", printf("echt: [%10.6s]\n", "dit is een heel verhaal");

	printf("\n short width, precision, short string: %%4.6s \n");
	printf("[%i]\n", ft_printf("mijn: [%4.6s]\n", "la");
	printf("[%i]\n", printf("echt: [%4.6s]\n", "la");

	printf("\n short width, precision, long string: %%4.6s \n");
	printf("[%i]\n", ft_printf("mijn: [%4.6s]\n", "dit is een heel verhaal");
	printf("[%i]\n", printf("echt: [%4.6s]\n", "dit is een heel verhaal");

	printf("\n<>-<>-<>-<> %%.44s <>-<>-<>-<>\n");
	printf("[%i]\n", ft_printf("mijn: [%.44s]\n", "dit is een string in ft_printf");	
	printf("[%i]\n", printf("echt: [%.44s]\n", "dit is een string in printf");

	printf("\n ALLEEN 0 FLAG \n");

	printf("\n alleen 0 flag %%0s \n");
	printf("[%i]\n", ft_printf("mijn: [%0s]\n", "la");
	printf("[%i]\n", printf("echt: [%0s]\n", "la");

	printf("\n zero, width, short string: %%06s \n");
	printf("[%i]\n", ft_printf("mijn: [%06s]\n", "la");
	printf("[%i]\n", printf("echt: [%06s]\n", "la");

	printf("\n zero, width, long string: %%06s \n");
	printf("[%i]\n", ft_printf("mijn: [%06s]\n", "dit is een heel verhaal");
	printf("[%i]\n", printf("echt: [%06s]\n", "dit is een heel verhaal");

	printf("\n zero, precision, short string: %%0.6s \n");
	printf("[%i]\n", ft_printf("mijn: [%0.6s]\n", "la");
	printf("[%i]\n", printf("echt: [%0.6s]\n", "la");

	printf("\n zero, precision, long string: %%0.6s \n");
	printf("[%i]\n", ft_printf("mijn: [%0.6s]\n", "dit is een heel verhaal");
	printf("[%i]\n", printf("echt: [%0.6s]\n", "dit is een heel verhaal");

	printf("\n zero, long width, precision, short string: %%010.6s \n");
	printf("[%i]\n", ft_printf("mijn: [%010.6s]\n", "la");
	printf("[%i]\n", printf("echt: [%010.6s]\n", "la");

	printf("\n long width, precision, long string: %%010.6s \n");
	printf("[%i]\n", ft_printf("mijn: [%010.6s]\n", "dit is een heel verhaal");
	printf("[%i]\n", printf("echt: [%010.6s]\n", "dit is een heel verhaal");

	printf("\n short width, precision, short string: %%04.6s \n");
	printf("[%i]\n", ft_printf("mijn: [%04.6s]\n", "la");
	printf("[%i]\n", printf("echt: [%04.6s]\n", "la");

	printf("\n short width, precision, long string: %%04.6s \n");
	printf("[%i]\n", ft_printf("mijn: [%04.6s]\n", "dit is een heel verhaal");
	printf("[%i]\n", printf("echt: [%04.6s]\n", "dit is een heel verhaal");*/

	/*printf("\n<>-<>-<>-<> %%05.12s <>-<>-<>-<>\n");
	printf("[%i]\n", ft_printf("mijn: [%05.12s]\n", "falafelspinazietafel");	
	printf("[%i]\n", printf("echt: [%05.12s]\n", "falafelspinazietafel");

	printf("\n<>-<>-<>-<> %%05.12s <>-<>-<>-<>\n");
	printf("[%i]\n", ft_printf("mijn: [%05.12s]\n", "la");	
	printf("[%i]\n", printf("echt: [%05.12s]\n", "la");

	printf("\n<>-<>-<>-<> %%05.3s <>-<>-<>-<>\n");
	printf("[%i]\n", ft_printf("mijn: [%05.3s]\n", "falafel");	
	printf("[%i]\n", printf("echt: [%05.3s]\n", "falafel");

	printf("\n<>-<>-<>-<> %%015.12s <>-<>-<>-<>\n");
	printf("[%i]\n", ft_printf("mijn: [%015.12s]\n", "falafelspinazie");	
	printf("[%i]\n", printf("echt: [%015.12s]\n", "falafelspinazie");*/

/*	printf("\n NU DE - FLAG \n");

	printf("\n alleen - flag %%-s \n");
	printf("[%i]\n", ft_printf("mijn: [%-s]\n", "la");
	printf("[%i]\n", printf("echt: [%-s]\n", "la");

	printf("\n - flag, width, short string: %%-6s \n");
	printf("[%i]\n", ft_printf("mijn: [%-6s]\n", "la");
	printf("[%i]\n", printf("echt: [%-6s]\n", "la");

	printf("\n width, long string: %%-6s \n");
	printf("[%i]\n", ft_printf("mijn: [%-6s]\n", "dit is een heel verhaal");
	printf("[%i]\n", printf("echt: [%-6s]\n", "dit is een heel verhaal");

	printf("\n precision, short string: %%-.6s \n");
	printf("[%i]\n", ft_printf("mijn: [%-.6s]\n", "la");
	printf("[%i]\n", printf("echt: [%-.6s]\n", "la");

	printf("\n precision, long string: %%-.6s \n");
	printf("[%i]\n", ft_printf("mijn: [%-.6s]\n", "dit is een heel verhaal");
	printf("[%i]\n", printf("echt: [%-.6s]\n", "dit is een heel verhaal");

	printf("\n long width, precision, short string: %%-10.6s \n");
	printf("[%i]\n", ft_printf("mijn: [%-10.6s]\n", "la");
	printf("[%i]\n", printf("echt: [%-10.6s]\n", "la");

	printf("\n long width, precision, long string: %%-10.6s \n");
	printf("[%i]\n", ft_printf("mijn: [%-10.6s]\n", "dit is een heel verhaal");
	printf("[%i]\n", printf("echt: [%-10.6s]\n", "dit is een heel verhaal");

	printf("\n short width, precision, short string: %%-4.6s \n");
	printf("[%i]\n", ft_printf("mijn: [%-4.6s]\n", "la");
	printf("[%i]\n", printf("echt: [%-4.6s]\n", "la");

	printf("\n short width, precision, long string: %%-4.6s \n");
	printf("[%i]\n", ft_printf("mijn: [%-4.6s]\n", "dit is een heel verhaal");
	printf("[%i]\n", printf("echt: [%-4.6s]\n", "dit is een heel verhaal");

	printf("\n<>-<>-<>-<> %%0-12.5s <>-<>-<>-<>\n");
	printf("[%i]\n", ft_printf("mijn: [%0-12.5s]\n", "falafelspinazietafel");	
	printf("[%i]\n", printf("echt: [%0-12.5s]\n", "falafelspinazietafel");

	printf("\n<>-<>-<>-<> %%0-5.12s <>-<>-<>-<>\n");
	printf("[%i]\n", ft_printf("mijn: [%0-5.12s]\n", "falafelspinazietafel");	
	printf("[%i]\n", printf("echt: [%0-5.12s]\n", "falafelspinazietafel");

	printf("\n<>-<>-<>-<> %%-.5s <>-<>-<>-<>\n");
	printf("[%i]\n", ft_printf("mijn: [%-.5s]\n", "la");	
	printf("[%i]\n", printf("echt: [%-.5s]\n", "la");*/

	
/*	printf("\n\t#########################################\n");
	printf("\t_.-._.-._.=.= Test Characters =.=._.-._.-._\n");
	printf("\t#########################################\n");

	printf("\n GEEN FLAG \n");

	printf("\n width: %%6c \n");
	printf("[%i]\n", ft_printf("mijn: [%6c]\n", 'a');
	printf("[%i]\n", printf("echt: [%6c]\n", 'a');

	printf("\n precision: %%.6c \n");
	printf("[%i]\n", ft_printf("mijn: [%.6c]\n", 'a');
	printf("[%i]\n", printf("echt: [%.6c]\n", 'a');

	printf("\n long width, precision: %%10.6c \n");
	printf("[%i]\n", ft_printf("mijn: [%10.6c]\n", 'a');
	printf("[%i]\n", printf("echt: [%10.6c]\n", 'a');

	printf("\n short width, precision: %%4.6c \n");
	printf("[%i]\n", ft_printf("mijn: [%4.6c]\n", 'a');
	printf("[%i]\n", printf("echt: [%4.6c]\n", 'a');

	printf("\n ALLEEN 0 FLAG \n");

	printf("\n alleen 0 flag %%0c \n");
	printf("[%i]\n", ft_printf("mijn: [%0c]\n", 'a');
	printf("[%i]\n", printf("echt: [%0c]\n", 'a');

	printf("\n zero, width: %%06c \n");
	printf("[%i]\n", ft_printf("mijn: [%06c]\n", 'a');
	printf("[%i]\n", printf("echt: [%06c]\n", 'a');

	printf("\n zero, precision: %%0.6s \n");
	printf("[%i]\n", ft_printf("mijn: [%0.6c]\n", 'a');
	printf("[%i]\n", printf("echt: [%0.6c]\n", 'a');

	printf("\n zero, long width, precision: %%010.6c \n");
	printf("[%i]\n", ft_printf("mijn: [%010.6c]\n", 'a');
	printf("[%i]\n", printf("echt: [%010.6c]\n", 'a');
	
	printf("\n short width, precision: %%04.6c \n");
	printf("[%i]\n", ft_printf("mijn: [%04.6c]\n", 'a');
	printf("[%i]\n", printf("echt: [%04.6c]\n", 'a');

	printf("\n NU DE - FLAG \n");

	printf("\n alleen - flag %%-c \n");
	printf("[%i]\n", ft_printf("mijn: [%-c]\n", 'a');
	printf("[%i]\n", printf("echt: [%-c]\n", 'a');

	printf("\n - flag, width: %%-6c \n");
	printf("[%i]\n", ft_printf("mijn: [%-6c]\n", 'a');
	printf("[%i]\n", printf("echt: [%-6c]\n", 'a');

	printf("\n precision: %%-.6c \n");
	printf("[%i]\n", ft_printf("mijn: [%-.6c]\n", 'a');
	printf("[%i]\n", printf("echt: [%-.6c]\n", 'a');

	printf("\n long width, precision: %%-10.6c \n");
	printf("[%i]\n", ft_printf("mijn: [%-10.6c]\n", 'a');
	printf("[%i]\n", printf("echt: [%-10.6c]\n", 'a');

	printf("\n short width, precision: %%-4.6c \n");
	printf("[%i]\n", ft_printf("mijn: [%-4.6c]\n", 'a');
	printf("[%i]\n", printf("echt: [%-4.6c]\n", 'a');

	printf("\n slash nul char: %%-6c \n");
	printf("[%i]\n", ft_printf("mijn: [%-6c]\n", '\0');
	printf("[%i]\n", printf("echt: [%-6c]\n", '\0');*/
	
	printf("\n\t#########################################\n");
	printf("\t_.-._.-._.=.= Test Pointers =.=._.-._.-._\n");
	printf("\t#########################################\n");
	
	int test = 0;
	printf("\n === GEEN FLAG === \n");

	printf("\n Gewoon Pointer: %%p \n");
	printf("[%i]\n", ft_printf("mijn: [%p]", &test));
	printf("[%i]\n", printf("echt: [%p]", &test));

	printf("\n Null Pointer: %%p \n");
	printf("[%i]\n", ft_printf("mijn: [%p]", NULL));
	printf("[%i]\n", printf("echt: [%p]", NULL));

	printf("\n kleine width: %%4p \n");
	printf("[%i]\n", ft_printf("mijn: [%4p]", &test));
	printf("[%i]\n", printf("echt: [%4p]", &test));

	printf("\n grote width: %%16p \n");
	printf("[%i]\n", ft_printf("mijn: [%16p]", &test));
	printf("[%i]\n", printf("echt: [%16p]", &test));

	printf("\n grote width, NULL: %%16p \n");
	printf("[%i]\n", ft_printf("mijn: [%16p]", NULL));
	printf("[%i]\n", printf("echt: [%16p]", NULL));

	printf("\n kleine prcsn: %%.3p \n");
	printf("[%i]\n", ft_printf("mijn: [%.3p]", &test));
	printf("[%i]\n", printf("echt: [%.3p]", &test));

	printf("\n grote prcsn: %%.16p \n");
	printf("[%i]\n", ft_printf("mijn: [%.16p]", &test));
	printf("[%i]\n", printf("echt: [%.16p]", &test));

	printf("\n grote prcsn, NULL: %%.16p \n");
	printf("[%i]\n", ft_printf("mijn: [%.16p]", NULL));
	printf("[%i]\n", printf("echt: [%.16p]", NULL));

	printf("\n width > prcsn: %%16.15p \n");
	printf("[%i]\n", ft_printf("mijn: [%16.15p]", &test));
	printf("[%i]\n", printf("echt: [%16.15p]", &test));

	printf("\n prcsn > width: %%15.16p \n");
	printf("[%i]\n", ft_printf("mijn: [%15.16p]", &test));
	printf("[%i]\n", printf("echt: [%15.16p]", &test));

	printf("\n lege prcsn: %%.p \n");
	printf("[%i]\n", ft_printf("mijn: [%.p]", &test));
	printf("[%i]\n", printf("echt: [%.p]", &test));

	printf("\n === 0 FLAG === \n");

	printf("\n Alleen 0: %%0p \n");
	printf("[%i]\n", ft_printf("mijn: [%0p]", &test));
	printf("[%i]\n", printf("echt: [%0p]", &test));

	printf("\n Null Pointer: %%0p \n");
	printf("[%i]\n", ft_printf("mijn: [%0p]", NULL));
	printf("[%i]\n", printf("echt: [%0p]", NULL));

	printf("\n kleine width: %%01p \n");
	printf("[%i]\n", ft_printf("mijn: [%01p]", &test));
	printf("[%i]\n", printf("echt: [%01p]", &test));

	printf("\n grote width: %%016p \n");
	printf("[%i]\n", ft_printf("mijn: [%016p]", &test));
	printf("[%i]\n", printf("echt: [%016p]", &test));

	printf("\n kleine prcsn: %%0.2p \n");
	printf("[%i]\n", ft_printf("mijn: [%0.2p]", &test));
	printf("[%i]\n", printf("echt: [%0.2p]", &test));

	printf("\n grote prcsn: %%0.19p \n");
	printf("[%i]\n", ft_printf("mijn: [%0.19p]", &test));
	printf("[%i]\n", printf("echt: [%0.19p]", &test));

	printf("\n width > prcsn: %%015.10p \n");
	printf("[%i]\n", ft_printf("mijn: [%015.10p]", &test));
	printf("[%i]\n", printf("echt: [%015.10p]", &test));

	printf("\n width > prcsn: %%019.15p \n");
	printf("[%i]\n", ft_printf("mijn: [%019.15p]", &test));
	printf("[%i]\n", printf("echt: [%019.15p]", &test));

	printf("\n prcsn > width: %%010.19p \n");
	printf("[%i]\n", ft_printf("mijn: [%010.19p]", &test));
	printf("[%i]\n", printf("echt: [%010.19p]", &test));

	printf("\n prcsn > width: %%015.19p \n");
	printf("[%i]\n", ft_printf("mijn: [%015.19p]", &test));
	printf("[%i]\n", printf("echt: [%015.19p]", &test));

	printf("\n === - FLAG === \n");

	printf("\n Null Pointer: %%-p \n");
	printf("[%i]\n", ft_printf("mijn: [%-p]", NULL));
	printf("[%i]\n", printf("echt: [%-p]", NULL));

	int a01 = 55;
	int a02 = 4;
	int a03 = 99944;
	int a04 = 2;
	int a05 = 0;
	printf("\n veel Pointers: %%-20p-20p.. \n");
	printf("[%i]\n", ft_printf("mijn: [%-20p%-20p%-20p%-20p%-20p]", &a01, &a02, &a03, &a04, &a05));
	printf("[%i]\n", printf("echt: [%-20p%-20p%-20p%-20p%-20p]", &a01, &a02, &a03, &a04, &a05));


	/*printf("\n\t#########################################\n");
	printf("\t-._.-._.=.= Test Hexadecimaal =.=._.-._.-\n");
	printf("\t#########################################\n");

	printf("\n === GEEN FLAG === \n");

	printf("\n geen flags: %%x \n");
	printf("[%i]\n", ft_printf("mijn: [%x]", 3549));
	printf("[%i]\n", printf("echt: [%x]", 3549));

	printf("\n geen flags, max int: %%x \n");
	printf("[%i]\n", ft_printf("mijn: [%x]", INT_MAX));
	printf("[%i]\n", printf("echt: [%x]", INT_MAX));

	printf("\n geen flags, min int: %%x \n");
	printf("[%i]\n", ft_printf("mijn: [%x]", INT_MIN));
	printf("[%i]\n", printf("echt: [%x]", INT_MIN));
	
	printf("\n geen flags, width: %%10x \n");
	printf("[%i]\n", ft_printf("mijn: [%10x]", 4746));
	printf("[%i]\n", printf("echt: [%10x]", 4746));

	printf("\n geen flags, len>width: %%4x \n");
	printf("[%i]\n", ft_printf("mijn: [%10x]", 47461235));
	printf("[%i]\n", printf("echt: [%10x]", 47461235));

	printf("\n geen flags, prcsn: %%.8x \n");
	printf("[%i]\n", ft_printf("mijn: [%.8x]", 4746));
	printf("[%i]\n", printf("echt: [%.8x]", 4746));

	printf("\n geen flags, len>prcsn: %%.4x \n");
	printf("[%i]\n", ft_printf("mijn: [%.8x]", 47461235));
	printf("[%i]\n", printf("echt: [%.8x]", 47461235));

	printf("\n geen flags, width > prcsn > len: %%10.8x \n");
	printf("[%i]\n", ft_printf("mijn: [%10.8x]", 4746));
	printf("[%i]\n", printf("echt: [%10.8x]", 4746));

	printf("\n geen flags, width > len > prcsn: %%10.3x \n");
	printf("[%i]\n", ft_printf("mijn: [%10.3x]", 4746123));
	printf("[%i]\n", printf("echt: [%10.3x]", 4746123));

	printf("\n geen flags, prcsn>widtdh>len: %%6.8x \n");
	printf("[%i]\n", ft_printf("mijn: [%6.8x]", 4746));
	printf("[%i]\n", printf("echt: [%6.8x]", 4746));

	printf("\n geen flags, prcsn>len>width: %%3.8x \n");
	printf("[%i]\n", ft_printf("mijn: [%3.8x]", 124746));
	printf("[%i]\n", printf("echt: [%3.8x]", 124746));

	printf("\n geen flags, len > width > prcsn: %%5.3x \n");
	printf("[%i]\n", ft_printf("mijn: [%5.3x]", 474618569));
	printf("[%i]\n", printf("echt: [%5.3x]", 474618569));

	printf("\n geen flags, len > prcsn > width: %%3.5x \n");
	printf("[%i]\n", ft_printf("mijn: [%3.5x]", 987147426));
	printf("[%i]\n", printf("echt: [%3.5x]", 987147426));

	printf("\n len>prcsn=width %%.0x \n");
	printf("[%i]\n", ft_printf("mijn: [%.0x]", 0));
	printf("[%i]\n", printf("echt: [%.0x]", 0));

	printf("\n len>prcsn=width %%0.0x \n");
	printf("[%i]\n", ft_printf("mijn: [%0.0x]", 0));
	printf("[%i]\n", printf("echt: [%0.0x]", 0));

	printf("\n len>prcsn=width %%-.0x \n");
	printf("[%i]\n", ft_printf("mijn: [%-.0x]", 0));
	printf("[%i]\n", printf("echt: [%-.0x]", 0));

	printf("\n width>len>prcsn %%5.0x \n");
	printf("[%i]\n", ft_printf("mijn: [%5.0x]", 0));
	printf("[%i]\n", printf("echt: [%5.0x]", 0));

	printf("\n len>prcsn=width %%.0x \n");
	printf("[%i]\n", ft_printf("mijn: [%.0x]", 5));
	printf("[%i]\n", printf("echt: [%.0x]", 5));

	printf("\n === ALLES MET  0 FLAG === \n");

	printf("\n Alleen 0 flag: %%0x\n");
	printf("[%i]\n", ft_printf("mijn: [%0x]", 6783));
	printf("[%i]\n", printf("echt: [%0x]", 6783));

	printf("\n 0 flag, width: %%020x \n");
	printf("[%i]\n", ft_printf("mijn: [%020x]", 3586240));
	printf("[%i]\n", printf("echt: [%020x]", 3586240));

	printf("\n 0 flag, prcsn: %%0.4x \n");
	printf("[%i]\n", ft_printf("mijn: [%0.4x]", 6178329));
	printf("[%i]\n", printf("echt: [%0.4x]", 6178329));

	printf("\n 0 flag, width en prcsn: %%07.4x \n");
	printf("[%i]\n", ft_printf("mijn: [%07.4x]", 6178329));
	printf("[%i]\n", printf("echt: [%07.4x]", 6178329));
	
	printf("\n == 0 FLAG, INT MAX == \n");

	printf("\n 0 flag, INT MAX: %%0x \n");
	printf("[%i]\n", ft_printf("mijn: [%0x]", INT_MAX));
	printf("[%i]\n", printf("echt: [%0x]", INT_MAX));

	printf("\n 0 flag, width, INT_MAX: %%020x \n");
	printf("[%i]\n", ft_printf("mijn: [%020x]", INT_MAX));
	printf("[%i]\n", printf("echt: [%020x]", INT_MAX));

	printf("\n 0 flag, prcsn, INT_MAX: %%0.4x \n");
	printf("[%i]\n", ft_printf("mijn: [%0.4x]", INT_MAX));
	printf("[%i]\n", printf("echt: [%0.4x]", INT_MAX));

	printf("\n 0 flag, width en prcsn, INT_MAX: %%07.4x \n");
	printf("[%i]\n", ft_printf("mijn: [%07.4x]", INT_MAX));
	printf("[%i]\n", printf("echt: [%07.4x]", INT_MAX));

	printf("\n NU DE - FLAG \n");

	printf("\n - flags, width: %%-20x \n");
	printf("[%i]\n", ft_printf("mijn: [%-20x]", 3586240));
	printf("[%i]\n", printf("echt: [%-20x]", 3586240));

	printf("\n alleen - flag  %%-x \n");
	printf("[%i]\n", ft_printf("mijn: [%-x]", 45));
	printf("[%i]\n", printf("echt: [%-x]", 45));

	printf("\n - flag en width 5 %%-5x \n");
	printf("[%i]\n", ft_printf("mijn: [%-5x]", 45));
	printf("[%i]\n", printf("echt: [%-5x]", 45));

	printf("\n - flag, width 5, neg int %%-5x \n");
	printf("[%i]\n", ft_printf("mijn: [%-5x]", -45));
	printf("[%i]\n", printf("echt: [%-5x]", -45));

	printf("\n - flag, width 5, prcsn 6 %%-5.6x \n");
	printf("[%i]\n", ft_printf("mijn: [%-5.6x]", 45));
	printf("[%i]\n", printf("echt: [%-5.6x]", 45));

	printf("\n - flag, width 5, prcsn 6, neg int %%-5.6x \n");
	printf("[%i]\n", ft_printf("mijn: [%-5.6x]", -45));
	printf("[%i]\n", printf("echt: [%-5.6x]", -45));

	printf("\n - flag, prcsn 6 %%-.6x \n");
	printf("[%i]\n", ft_printf("mijn: [%-.6x]", 45));
	printf("[%i]\n", printf("echt: [%-.6x]", 45));

	printf("\n - flag, width 10, prcsn 6 %%-10.6x \n");
	printf("[%i]\n", ft_printf("mijn: [%-10.6x]", 45));
	printf("[%i]\n", printf("echt: [%-10.6x]", 45));*/


	printf("\n\t#########################################\n");
	printf("\t-._.-._.=.= Test Unsigned int =.=._.-._.-\n");
	printf("\t#########################################\n");

	printf("\n === GEEN FLAG === \n");

	printf("\n niks: %%u \n");
	printf("[%i]\n", ft_printf("mijn: [%u]", 2147483647));
	printf("[%i]\n", printf("echt: [%u]", 2147483647));

	printf("\n nul: %%u \n");
	printf("[%i]\n", ft_printf("mijn: [%u]", 0));
	printf("[%i]\n", printf("echt: [%u]", 0));

	printf("\n tiental: %%u \n");
	printf("[%i]\n", ft_printf("mijn: [%u]", 45454500));
	printf("[%i]\n", printf("echt: [%u]", 45454500));

	printf("\n width: %%5u \n");
	printf("[%i]\n", ft_printf("mijn: [%5u]", 79142));
	printf("[%i]\n", printf("echt: [%5u]", 79142));

	printf("\n prcsn: %%.5u \n");
	printf("[%i]\n", ft_printf("mijn: [%.5u]", 3337));
	printf("[%i]\n", printf("echt: [%.5u]", 3337));

	printf("\n 0 prcsn, u = 0: %%.0u \n");
	printf("[%i]\n", ft_printf("mijn: [%.0u]", 0));
	printf("[%i]\n", printf("echt: [%.0u]", 0));

	printf("\n width en prcsn: %%10.7u \n");
	printf("[%i]\n", ft_printf("mijn: [%10.7u]", 46475));
	printf("[%i]\n", printf("echt: [%10.7u]", 46475));

	printf("\n === 0 FLAG === \n");

	printf("\n alleen 0: %%0u \n");
	printf("[%i]\n", ft_printf("mijn: [%0u]", 2441));
	printf("[%i]\n", printf("echt: [%0u]", 2441));

	printf("\n width: %%08u \n");
	printf("[%i]\n", ft_printf("mijn: [%08u]", 1786));
	printf("[%i]\n", printf("echt: [%08u]", 1786));

	printf("\n prcsn: %%0.7u \n");
	printf("[%i]\n", ft_printf("mijn: [%0.7u]", 92734));
	printf("[%i]\n", printf("echt: [%0.7u]", 92734));

	printf("\n width > prcsn: %%08.6u \n");
	printf("[%i]\n", ft_printf("mijn: [%08.6u]", 3646));
	printf("[%i]\n", printf("echt: [%08.6u]", 3646));

	printf("\n prcsn > width: %%06.8u \n");
	printf("[%i]\n", ft_printf("mijn: [%06.8u]", 909));
	printf("[%i]\n", printf("echt: [%06.8u]", 909));

	printf("\n === - FLAG === \n");

	printf("\n onzichtbare prcsn, u = 0: %%-5.u \n");
	printf("[%i]\n", ft_printf("mijn: [%-5.u]", 0));
	printf("[%i]\n", printf("echt: [%-5.u]", 0));


	printf("\n\t#########################################\n");
	printf("\t-._.-._.-._.=.= Test MIX =.=._.-._.-._.-\n");
	printf("\t#########################################\n");

	int		getal = 85;
	char	*zin = "het adres van";

	printf("\n %%i %%p %%s \n");
	printf("[%i]\n", ft_printf("mijn: %s %i is %p", zin, getal, &getal));
	printf("[%i]\n", printf("echt: %s %i is %p", zin, getal, &getal));


}
