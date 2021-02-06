/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkortbi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 10:00:09 by hkortbi           #+#    #+#             */
/*   Updated: 2020/10/27 12:58:37 by hkortbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int		ft_is_safe_diagonal(int board[10][10], int row, int column)
{
	int i;
	int j;

	i = row - 1;
	j = column - 1;
	while (i >= 0 && j >= 0)
	{
		if (board[i][j] == 1)
			return (0);
		i--;
		j--;
	}
	i = row - 1;
	j = column + 1;
	while (i >= 0 && j < 10)
	{
		if (board[i][j] == 1)
			return (0);
		i--;
		j++;
	}
	return (1);
}

int		ft_is_safe(int board[10][10], int row, int column)
{
	int i;

	i = 0;
	while (i < row)
	{
		if (board[i][column] == 1)
			return (0);
		i++;
	}
	if (ft_is_safe_diagonal(board, row, column) == 0)
		return (0);
	return (1);
}

void	ft_print_board(int board[10][10])
{
	int		i;
	int		j;
	char	c;
	char	new_line;

	new_line = '\n';
	i = 0;
	while (i < 10)
	{
		j = 0;
		while (j < 10)
		{
			c = '\0';
			if (board[i][j] == 1)
			{
				c = j + '0';
				write(1, &c, 1);
			}
			j++;
		}
		i++;
	}
	write(1, &new_line, 1);
}

int		ft_ten_queens(int board[10][10], int row, int *solutions)
{
	int i;

	if (row == 10)
	{
		ft_print_board(board);
		*solutions = *solutions + 1;
	}
	i = 0;
	while (i < 10)
	{
		if (ft_is_safe(board, row, i))
		{
			board[row][i] = 1;
			ft_ten_queens(board, row + 1, solutions);
			board[row][i] = 0;
		}
		i++;
	}
	return (*solutions);
}

int		ft_ten_queens_puzzle(void)
{
	int board[10][10];
	int i;
	int j;
	int solution;
	int *solutions;

	solution = 0;
	solutions = &solution;
	i = 0;
	j = 0;
	while (i < 10)
	{
		j = 0;
		while (j < 10)
		{
			board[i][j] = 0;
			j++;
		}
		i++;
	}
	return (ft_ten_queens(board, 0, solutions));
}
