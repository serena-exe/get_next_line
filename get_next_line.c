/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebavaro <sebavaro@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 10:50:40 by sebavaro          #+#    #+#             */
/*   Updated: 2025/12/09 22:03:22 by sebavaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*read_and_stash(int fd, char *stash) //comme c'est dit elle lit et rempli la stash until \n
{
	int		byte_read;
	char	*buffer;
	
	if (!stash)
		stash = ft_calloc(1,1); // securité au cas ou on alloue 1 meme si j'aurait pu mettre NULL ou strdup de rien ""
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char)); // ouvre mon buffer d'une certaine taille
	byte_read = 1; // je l'initialise a 1 pour rentrer dans la boucle
	while (byte_read > 0) // while byte read is grater than zero (positif genre)
	{
		byte_read = read(fd, buffer, BUFFER_SIZE); //la b read = le nbr de byte read
		if (byte_read == -1) // securite si ca fait de la D
		{
			free(buffer);
			return(NULL);
		}
		buffer[byte_read] = 0; // c comme un str[i] cest buffer de byte read
		stash = ft_strjoin(stash, buffer); //je join les deux stash and buffer ATTENTION j'ai rajouté un free dans strjoin

		if (ft_strchr (buffer, '\n')) // si ya un retour a ligne sur la partie étudié bah vasy on s'arrette
			break ;
	}
	free(buffer);
	return(stash); //on return la stash du coup 
}

char	*get_the_line(char *stash) // renvoie la line du stash
{
	char	*line;
	int		i;
	
	i = 0; //normal hein on part d'en bas pour atteindre les sommets my G
	if (!stash[i])
		return(NULL);
	while (stash[i] && stash[i] != '\n')
		i ++; // on mesure le stash
	if (stash[i] == '\n')
		i ++; //cou loucoucou loucoucou stash stash faut bien prendre le back slash n
	line = ft_calloc(i + 1, sizeof(char));
	i = 0; //mtn qu'on a la mesure bah on peut remettre a zero
	while (stash[i] && stash[i] != '\n') // du coup la on fait pareil mais on copie
	{
		line[i] = stash[i]; //copie
		i ++;
	}
	if (stash[i] == '\n') // on ajoute le \n
	{
		line[i] = stash[i];
		i++;
	}
	line[i] = '\0'; // et le \0 
	return (line);
}

char	*the_next_line(char *stash)
{
	int		i;
	int		j;
	char	*next_line; //la on veut la ligne d'apres
	
	i = 0;
	j = 0;
	while (stash[i] && stash[i] == '\n') //tant que on est ni a la fin ni a la fin de la line, on avance I
		i++;
	if (!stash[i]) //securite
	{
		free(stash);
		return (NULL);
	}
	i ++; //on avance i pour passer le \n
	next_line = ft_calloc((ft_strlen(stash) - i + 1), sizeof(char)); //on prend la taille de stash -i pour mesurer que ce qui nous reste a stash genre j'ai un stash de 5 et une longueur tot de 15 il me reste 10 byte a stash 
	while (stash[i])
	{
		next_line[j] = stash[i]; //on copie le reste de stash dans la new line du coup
		j ++;
		i ++;
	}
	next_line[j] = '\0'; //le back slash 0
	free(stash); //on libere la stash
	return(next_line); //et voila
}

char	*get_next_line (int fd)
{
	static char	*the_buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 )
		return (NULL);
	the_buffer = read_and_stash(fd, the_buffer); //ça cest pour read the file
	if (!the_buffer)
		return (NULL);
	line = get_the_line(the_buffer); // ça c'est pour avoir la ligne
	the_buffer = the_next_line(the_buffer); // la en gros mon buffer il prend la ligne d'apres
	return(line);
}

int main()
{
    int fd = open("text.txt", O_RDONLY);
    char *line;
    
    line = get_next_line(fd);
    while (line)
    {
        printf("%s", line);
        free(line);
        line = get_next_line(fd);
    }
    close(fd);
    return(0);
}
