/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   config.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: cwesseli <cwesseli@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/11 15:20:29 by cwesseli      #+#    #+#                 */
/*   Updated: 2023/09/18 11:38:41 by cherrewi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONFIG_H
# define CONFIG_H

//dimensions of the MLX screenthe game will play on
# define SCREEN_WIDTH 2000
# define SCREEN_HEIGHT 1200

# define WINDOW_X_POS 100
# define WINDOW_Y_POS 100

// wall hight relative to grid cell lenght and width
# define WALL_HEIGHT 1.00

//movement speed and refresh rates
# define MOVE_INCREMENT 0.2
# define TURN_INCREMENT 0.062831853071796 /* M_PI / 50 */
# define UPDATE_RATE 0.001
# define MOUSE_SENSITIVITY 0.1

// additional math constants
# define M_SQRT1_3 0.577350269189625764509148780501957456	/* 1/sqrt(3) */

#endif
