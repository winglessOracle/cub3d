/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   config.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: cwesseli <cwesseli@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/11 15:20:29 by cwesseli      #+#    #+#                 */
/*   Updated: 2023/09/11 18:32:53 by carlowessel   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONFIG_H
# define CONFIG_H

//dimensions of the MLX screenthe game will play on
# define SCREEN_WIDTH 2000
# define SCREEN_HEIGHT 1000

# define WINDOW_X_POS 200
# define WINDOW_Y_POS 100

// wall hight relative to grid cell lenght and width
# define WALL_HEIGHT 1.00

//movement speed and refresh rates
# define MOVE_INCREMENT 0.5
# define TURN_INCREMENT M_PI / 10
# define MOVEMENT_RATE 10
# define MOUSE_SENSITIVITY 0.05
# define MOUSE_SENSITIVITY 0.05

#endif
