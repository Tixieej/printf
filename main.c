/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: rde-vrie <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/24 09:52:14 by rde-vrie      #+#    #+#                 */
/*   Updated: 2020/01/06 15:03:20 by rde-vrie      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <limits.h>
#include <stdio.h>

int	main()
{
	char	c = 'g';
	int		i = 5;
	int		groot = 2147483647;
	char	*s = "Rixt";
/*	printf("\t#########################################\n");
	printf("\t_.-._.-._.=.= Test Integers =.=._.-._.-._ \n");
	printf("\t#########################################\n");

	printf("\n alleen 0 flag  %%0i \n");
	ft_printf("mijn: [%0i]\n", 45);
	printf("echt: [%0i]\n", 45);

	printf("\n 0 flag en width 5 %%05i \n");
	ft_printf("mijn: [%05i]\n", 45);
	printf("echt: [%05i]\n", 45);

	printf("\n 0 flag, width 5, neg int %%05i \n");
	ft_printf("mijn: [%05i]\n", -45);
	printf("echt: [%05i]\n", -45);

	printf("\n 0 flag, width 5, prcsn 6 %%05.6i \n");
	ft_printf("mijn: [%05.6i]\n", 45);
	printf("echt: [%05.6i]\n", 45);

	printf("\n 0 flag, prcsn 6  %%0.6i \n");
	ft_printf("mijn: [%0.6i]\n", 45);
	printf("echt: [%0.6i]\n", 45);

	printf("\n alleen width  %%5i \n");
	ft_printf("mijn: [%5i]\n", 45);
	printf("echt: [%5i]\n", 45);

	printf("\n alleen width, neg int  %%5i \n");
	ft_printf("mijn: [%5i]\n", -45);
	printf("echt: [%5i]\n", -45);

	printf("\n width, prcsn  %%5.6i \n");
	ft_printf("mijn: [%5.6i]\n", 45);
	printf("echt: [%5.6i]\n", 45);

	printf("\n width, prcsn, neg int  %%10.6i \n");
	ft_printf("mijn: [%10.6i]\n", -45);
	printf("echt: [%10.6i]\n", -45);

	printf("\n alleen prcsn  %%.6i \n");
	ft_printf("mijn: [%.6i]\n", 45);
	printf("echt: [%.6i]\n", 45);

	printf("\n<>-<>-<>-<> %%024.6i <>-<>-<>-<>\n");
	//vul aan met 0 tot 24 width. prec overwrite 0padding
	ft_printf("mijn: [%024.6i]\n", 123456789);	
	printf("echt: [%024.6i]\n", 123456789);

	printf("\n<>-<>-<>-<> %%026i <>-<>-<>-<>\n");
	ft_printf("mijn: [%026i]\n", 123456789);	
	printf("echt: [%026i]\n", 123456789);

	printf("\n<>-<>-<> %%000000-000006i <>-<>-<>\n");
	ft_printf("mijn: [%000000-000006i]\n", 25);
	printf("echt: [%000000-000006i]\n", 25);

	printf("\n<>-<>-<>-<> %%0*i, 8 <>-<>-<>-<>\n");
	ft_printf("mijn: [%0*i]\n", 8, 125);
	printf("echt: [%0*i]\n", 8, 125);

	printf("\n<>-<>-<>-<> %%i <>-<>-<>-<>\n");
	ft_printf("mijn: [%i]\n", INT_MIN);
	printf("echt: [%i]\n", INT_MIN);

	printf("\n<>-<>-<>-<> %%20.7i <>-<>-<>-<>\n");
	//7 is minimale width? vul op met 0
	ft_printf("mijn: [%20.7i]\n", 12345);
	printf("echt: [%20.7i]\n", 12345);

	printf("\n NU DE - FLAG \n");

	printf("\n alleen - flag  %%-i \n");
	ft_printf("mijn: [%-i]\n", 45);
	printf("echt: [%-i]\n", 45);

	printf("\n - flag en width 5 %%-5i \n");
	ft_printf("mijn: [%-5i]\n", 45);
	printf("echt: [%-5i]\n", 45);

	printf("\n - flag, width 5, neg int %%-5i \n");
	ft_printf("mijn: [%-5i]\n", -45);
	printf("echt: [%-5i]\n", -45);

	printf("\n - flag, width 5, prcsn 6 %%-5.6i \n");
	ft_printf("mijn: [%-5.6i]\n", 45);
	printf("echt: [%-5.6i]\n", 45);

	printf("\n - flag, width 5, prcsn 6, neg int %%-5.6i \n");
	ft_printf("mijn: [%-5.6i]\n", -45);
	printf("echt: [%-5.6i]\n", -45);

	printf("\n - flag, prcsn 6 %%-.6i <>-<>-<>-<>\n");
	ft_printf("mijn: [%-.6i]\n", 45);
	printf("echt: [%-.6i]\n", 45);

	printf("\n - flag, width 10, prcsn 6 %%-10.6i <>-<>-<>-<>\n");
	ft_printf("mijn: [%-10.6i]\n", 45);
	printf("echt: [%-10.6i]\n", 45);
*/

	printf("\n\t#########################################\n");
	printf("\t_.-._.-._.=.= Test Strings =.=._.-._.-._\n");
	printf("\t#########################################\n");

	printf("\n alleen 0 flag %%0s \n");
	ft_printf("mijn: [%0s]\n", "la");
	printf("echt: [%0s]\n", "la");

	printf("\n alleen - flag %%-s \n");
	ft_printf("mijn: [%-s]\n", "la");
	printf("echt: [%-s]\n", "la");

	
	printf("\n_.-._.=.=.= %%-5s =.=.=._.-._\n");
	ft_printf("mijn: [%-5s]\n", "la");
	printf("echt: [%-5s]\n", "la");

	printf("\n<>-<>-<>-<> %%-.5s <>-<>-<>-<>\n");
	ft_printf("mijn: [%-.5s]\n", "la");	
	printf("echt: [%-.5s]\n", "la");

	printf("\n-._.-._.- precision test: %%.6s -._.-._.-\n");
	ft_printf("mijn: [%.6s]\n", "dit is een heel verhaal");
	printf("echt: [%.6s]\n", "dit is een heel verhaal");

	printf("\n<>-<>-<>-<> %%.44s <>-<>-<>-<>\n");
	ft_printf("mijn: [%.44s]\n", "dit is een string in ft_printf");	
	printf("echt: [%.44s]\n", "dit is een string in printf");

	printf("\n<>-<>-<>-<> %%0-5.12s <>-<>-<>-<>\n");
	ft_printf("mijn: [%0-5.12s]\n", "falafelspinazietafel");	
	printf("echt: [%0-5.12s]\n", "falafelspinazietafel");

	printf("\n<>-<>-<>-<> %%0-12.5s <>-<>-<>-<>\n");
	ft_printf("mijn: [%0-12.5s]\n", "falafelspinazietafel");	
	printf("echt: [%0-12.5s]\n", "falafelspinazietafel");

	printf("\n<>-<>-<>-<> %%05.12s <>-<>-<>-<>\n");
	ft_printf("mijn: [%05.12s]\n", "falafelspinazietafel");	
	printf("echt: [%05.12s]\n", "falafelspinazietafel");

	printf("\n<>-<>-<>-<> %%05.12s <>-<>-<>-<>\n");
	ft_printf("mijn: [%05.12s]\n", "la");	
	printf("echt: [%05.12s]\n", "la");

	printf("\n<>-<>-<>-<> %%05.3s <>-<>-<>-<>\n");
	ft_printf("mijn: [%05.3s]\n", "falafel");	
	printf("echt: [%05.3s]\n", "falafel");

	printf("\n<>-<>-<>-<> %%015.12s <>-<>-<>-<>\n");
	ft_printf("mijn: [%015.12s]\n", "falafel");	
	printf("echt: [%015.12s]\n", "falafel");


/*	
	printf("\n\t#########################################\n");
	printf("\t_.-._.-._.=.= Test Characters =.=._.-._.-._\n");
	printf("\t#########################################\n");
*/	
}
