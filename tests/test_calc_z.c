# include <cub3d.h>
# include <assert.h>

void test_calc_z_height(void)
{
	double dist;
	double z_angle;
	double z1;
	double z2;

	puts("testing calc_z_height() ...");
	dist = 1;
	
	// look horizonal (angle 0)
	assert(fabs(calc_z_height(dist, 0) - (WALL_HEIGHT / 2)) < 0.001);

	// compare valid look ups, with look downs
	z_angle = 0.1;
	while (z_angle < M_PI_2 - 0.1)
	{
		z1 = calc_z_height(dist, z_angle);
		z2 = calc_z_height(dist, 2 * M_PI - z_angle);
		assert(z1 != NAN);
		assert(z2 != NAN);
		assert(fabs((z1 - WALL_HEIGHT) - (-1 * z2)) < 0.001);
		z_angle += M_PI / 10;
	}

	// NAN checks
	assert(isnan(calc_z_height(dist, M_PI_2)));
	assert(isnan(calc_z_height(dist, M_PI_2 + M_PI_4)));
	assert(isnan(calc_z_height(dist, M_PI)));
	assert(isnan(calc_z_height(dist, M_PI + M_PI_4)));
	assert(isnan(calc_z_height(dist, M_PI + M_PI_2)));
	puts("OK");
}

void test_calc_z_angle(t_data *data)
{
	puts("testing calc_z_angle() ...");
	
	double z_angle;
	double z_angle_1;
	double z_angle_2;

	// top pixel
	z_angle = calc_z_angle(0, data);

	assert(fabs(z_angle - M_PI / 12) < 0.001);

	// mid pixel
	if (data->screen_height % 2 == 1)
	{
		z_angle = calc_z_angle((data->screen_height / 2), data);
		assert(fabs(z_angle) < 0.001);
	}
	else
	{
		// even nr of pixels, so calc the average of the 2 in the middle
		z_angle_1 = calc_z_angle((data->screen_height / 2) - 1, data);
		z_angle_2 = calc_z_angle((data->screen_height / 2), data);
		assert(fabs(fmod(z_angle_1 + z_angle_2, 2 * M_PI)) < 0.001);
	}

	// bottom pixel
	z_angle = calc_z_angle(data->screen_height - 1, data);
	assert(fabs(z_angle - (M_PI * (1 + (double)11/12))) < 0.001);
	
	puts("OK");
}
