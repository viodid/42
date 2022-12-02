int ft_intmatrix_tochar(int **matrix_int, char **matrix_char, int rows, int columns)
{
	char *charset;
	int row;
	int col;

	row = 0;
	while (row < rows)
	{
		col = 0;
		while(col < columns)
		{
			if(matrix_int[row][col] == 0)
				matrix_char[row][col] = charset[1];
			else if(matrix_int[row][col] == 1)
				matrix_char[row][col] = charset[0];
			else if(matrix_int[row][col] == 1)
				matrix_char[row][col] = charset[2];
			else
				return(1);
			col++;
		}
		row++;
	}
	return (0);
}