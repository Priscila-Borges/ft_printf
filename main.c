/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: pride-ol <pride-ol@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/05/11 21:56:13 by pride-ol      #+#    #+#                 */
/*   Updated: 2026/05/11 22:44:57 by pride-ol      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

int main(void)
{
    int mine;
    int original; 
   
    printf("1. Char (%%c):\n");
    mine = ft_printf("  Mine: [%c]\n", 'G');
    original = printf("  Orig: [%c]\n", 'G');
    printf("  Return -> Mine: %d | Orig: %d\n\n", mine, original);
   
    printf("2. String (%%s):\n");
    mine = ft_printf("  Mine: [%s]\n", "Priscila 42");
    original = printf("  Orig: [%s]\n", "Priscila 42");
    printf("  Return -> Mine: %d | Orig: %d\n\n", mine, original);

	char *s2 = NULL;
	mine = ft_printf("  Mine: [%s]\n", s2);
    original = printf("  Orig: [%s]\n", s2);
    printf("  Return -> Mine: %d | Orig: %d\n\n", mine, original);

	mine = ft_printf("  Mine: [%s]\n", "Hello world %");
    original = printf("  Orig: [%s]\n", "Hello world %");
    printf("  Return -> Mine: %d | Orig: %d\n\n", mine, original);	
   
    printf("3. Pointer (%%p):\n");
    void *ptr = &mine;
	void *nil_prt = NULL;
    mine = ft_printf("  Mine: [%p]\n", ptr);
    original = printf("  Orig: [%p]\n", ptr);
    printf("  Return -> Mine: %d | Orig: %d\n\n", mine, original);

	mine = ft_printf("  Mine: [%p]\n", nil_prt);
    original = printf("  Orig: [%p]\n", nil_prt);
    printf("  Return -> Mine: %d | Orig: %d\n\n", mine, original);
   
    printf("4. Int (%%d e %%i):\n");
    mine = ft_printf("  Mine: [%d] [%i]\n", INT_MIN, 42);
    original = printf("  Orig: [%d] [%i]\n", INT_MIN, 42);
    printf("  Return -> Mine: %d | Orig: %d\n\n", mine, original);
   
    printf("5. Unsigned (%%u):\n");
    mine = ft_printf("  Mine: [%u]\n", 4294967295U);
    original = printf("  Orig: [%u]\n", 4294967295U);
    printf("  Return -> Mine: %d | Orig: %d\n\n", mine, original);
   
    printf("6. Hexa Lower (%%x):\n");
    mine = ft_printf("  Mine: [%x]\n", 255);
    original = printf("  Orig: [%x]\n", 255);
    printf("  Return -> Mine: %d | Orig: %d\n\n", mine, original);
   
    printf("7. Hexa Upper (%%X):\n");
    mine = ft_printf("  Mine: [%X]\n", 255);
    original = printf("  Orig: [%X]\n", 255);
    printf("  Return -> Mine: %d | Orig: %d\n\n", mine, original);
  
    printf("8. Percentage (%%%%):\n");
    mine = ft_printf("  Mine: [%%]\n");
    original = printf("  Orig: [%%]\n");
    printf("  Return -> Mine: %d | Orig: %d\n\n", mine, original);

	printf("9. Mixed:\n");
    mine = ft_printf("  Mine: [%d] [%s] [%p] [%%] [%x]\n", -1, "end", NULL, 42);
    original = printf("  Orig: [%d] [%s] [%p] [%%] [%x]\n", -1, "end", NULL, 42);
    printf("  Return -> Mine: %d | Orig: %d\n\n", mine, original);
    return (0);
}
	