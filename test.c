/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JP <JP@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/27 14:20:46 by JP                #+#    #+#             */
/*   Updated: 2020/04/28 11:02:27 by JP               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "/usr/local/Cellar/libsndfile/1.0.28/include/sndfile.h"
#include "/usr/local/Cellar/libao/1.2.2/include/ao/ao.h"
#include "libft/inc/libft.h"
#include <stdio.h>
#include <math.h>
#include <string.h>

#define MAX_CHANNELS 6


void audio(SNDFILE *file, ao_sample_format format, ao_device *device)
{

	int readcount;
	short *buff;
	int buff_size;


	
	buff_size = format.bits / 8 * format.channels * format.rate;
	if (!(buff = malloc(buff_size * sizeof(char))))
		ft_putendl("caca");
	int flex = 0;
	while ((readcount = sf_read_short(file, buff, 1024)))
	{
		if (ao_play(device, (char*)buff, (uint_32)(readcount * sizeof(short))) == 0)
			exit(0);
	}
	sf_seek(file, 0, SEEK_SET);
}
int main(void)
{
	SNDFILE *infile;
	SF_INFO info;
	SNDFILE *infile2;
	SF_INFO info2;
	ao_device *device;
	ao_sample_format format;
	int default_driver;

	ao_initialize();

	default_driver = ao_default_driver_id();
	bzero(&info, sizeof(info));
	bzero(&format, sizeof(format));
	

	if (!(infile = sf_open("shotgun.wav", SFM_READ, &info)))
	{
		printf("error");
		return 1;
	}
	if (!(infile2 = sf_open("bfg.wav", SFM_READ, &info2)))
	{
		printf("error");
		return 1;
	}
	if (info.channels > MAX_CHANNELS) {
		printf("Too many channels");
		return 1;
	}
	if ((info.format & SF_FORMAT_SUBMASK) == SF_FORMAT_PCM_16) {
		format.bits = 16;
	} else if ((info.format & SF_FORMAT_SUBMASK) == SF_FORMAT_PCM_24) {
		format.bits = 24;
	} else if ((info.format & SF_FORMAT_SUBMASK) == SF_FORMAT_PCM_32) {
		format.bits = 32;
	} else if ((info.format & SF_FORMAT_SUBMASK) == SF_FORMAT_PCM_S8) {
		format.bits = 8;
	} else if ((info.format & SF_FORMAT_SUBMASK) == SF_FORMAT_PCM_U8) {
		format.bits = 8;
	} else {
		format.bits = 16;
	}
	format.channels = info.channels;
	format.rate = info2.samplerate;
	device = ao_open_live(default_driver, &format, NULL);
	while (1)
	{
		getchar();
		audio(infile, format, device);
		audio(infile2, format, device);
	}
	sf_close(infile);
	ao_close(device);

	ao_shutdown();
	return 0;
}


