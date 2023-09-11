/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   config.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: cwesseli <cwesseli@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/11 15:20:29 by cwesseli      #+#    #+#                 */
/*   Updated: 2023/09/13 00:53:48 by carlowessel   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONFIG_H
# define CONFIG_H

//dimensions of the MLX screenthe game will play on
# define SCREEN_WIDTH 2000
# define SCREEN_HEIGHT 1200

# define WINDOW_X_POS 100
# define WINDOW_Y_POS 1200

// wall hight relative to grid cell lenght and width
# define WALL_HEIGHT 1.00

//movement speed and refresh rates
# define MOVE_INCREMENT 0.2
# define TURN_INCREMENT M_PI / 20
# define MOVEMENT_RATE 20
# define MOUSE_SENSITIVITY 0.05
# define MOUSE_SENSITIVITY 0.05

#endif

